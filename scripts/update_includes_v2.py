#!/usr/bin/env python3
import sys, os, glob, re
root = os.path.dirname(os.path.dirname(__file__))
os.chdir(root)
files = glob.glob("examples/**/*.c", recursive=True) + glob.glob("src/**/*.c", recursive=True)
files = sorted(files)

def ensure_includes(path, content):
    """Return new content with required includes inserted if missing. Also cleans extras in examples (removes types.h)."""
    rel = path.replace('\\', '/')
    original_lines = content.splitlines()
    lines = list(original_lines)
    # Clean up examples: they should not include types.h directly
    removed_example_types = False
    if 'examples/' in rel:
        cleaned = [l for l in lines if '"types.h"' not in l]
        if cleaned != lines:
            removed_example_types = True
            lines = cleaned
    has_creg = any('creg.h' in l for l in lines)
    has_types = any('types.h' in l for l in lines)
    # Build required include list based on path
    incs = []
    if 'examples/' in rel:
        if not any('<stdio.h>' in l or '#include <stdio.h>' in l for l in lines):
            incs.append('#include <stdio.h>')
        if not has_creg:
            incs.append('#include "creg.h"')
    elif 'src/models/' in rel:
        m = re.search(r'src/models/([^/]+)/', rel)
        model = m.group(1) if m else 'unknown'
        if not any(f'models/{model}.h' in l for l in lines):
            incs.append(f'#include "models/{model}.h"')
        if not any('optimizers/optimizer.h' in l for l in lines):
            incs.append('#include "optimizers/optimizer.h"')
        if not any('utils/matrix.h' in l for l in lines):
            incs.append('#include "utils/matrix.h"')
        if not any('loss/loss.h' in l for l in lines):
            incs.append('#include "loss/loss.h"')
        if not has_types:
            incs.append('#include "types.h"')
    elif 'src/optimizers/' in rel:
        # figure out order but ensure optimizer.h present
        if not any('optimizers/optimizer.h' in l for l in lines):
            incs.append('#include "optimizers/optimizer.h"')
        if not any('utils/math.h' in l for l in lines):
            incs.append('#include "utils/math.h"')
        if not any('utils/matrix.h' in l for l in lines):
            incs.append('#include "utils/matrix.h"')
        if not has_types:
            incs.append('#include "types.h"')
    elif 'src/analytic/' in rel:
        m = re.search(r'src/analytic/([^/]+)/', rel)
        ana = m.group(1) if m else 'unknown'
        if not any(f'analytic/{ana}.h' in l for l in lines):
            incs.append(f'#include "analytic/{ana}.h"')
        if not any('utils/matrix.h' in l for l in lines):
            incs.append('#include "utils/matrix.h"')
        if not has_types:
            incs.append('#include "types.h"')
    elif 'src/loss/' in rel:
        if not any('loss/loss.h' in l for l in lines):
            incs.append('#include "loss/loss.h"')
        if not has_types:
            incs.append('#include "types.h"')
    elif 'src/metrics/' in rel:
        if not any('metrics/metrics.h' in l for l in lines):
            incs.append('#include "metrics/metrics.h"')
        if not has_types:
            incs.append('#include "types.h"')
    elif 'src/utils/' in rel:
        m = re.search(r'src/utils/([^/]+)/', rel)
        util = m.group(1) if m else 'unknown'
        if not any(f'utils/{util}.h' in l for l in lines):
            incs.append(f'#include "utils/{util}.h"')
        if not has_types:
            incs.append('#include "types.h"')
    else:
        if not has_types:
            incs.append('#include "types.h"')

    if not incs:
        # If we only cleaned up example includes, still write changes
        if removed_example_types:
            return '\n'.join(lines) + ('\n' if content.endswith('\n') else ''), True
        return content, False

    inc_block = '\n'.join(incs) + '\n\n'
    # If file already has includes at top, insert after the first existing include block
    insert_idx = 0
    for i, line in enumerate(lines[:10]):
        if line.strip().startswith('#include'):
            insert_idx = i
            # move to end of initial include cluster
            while insert_idx+1 < len(lines) and lines[insert_idx+1].strip().startswith('#include'):
                insert_idx += 1
            insert_idx += 1
            break

    # Rebuild content with inserted includes at insert_idx
    new_lines = lines[:insert_idx] + [inc_block] + lines[insert_idx:]
    return '\n'.join(new_lines) + ('\n' if content.endswith('\n') else ''), True

updated = []
for f in files:
    if '.git' in f:
        continue
    try:
        with open(f, 'r', encoding='utf-8') as fh:
            s = fh.read()
    except Exception as e:
        print(f"SKIP (read error): {f} -> {e}")
        continue
    new_s, changed = ensure_includes(f, s)
    if changed:
        try:
            # backup
            with open(f + '.bak', 'w', encoding='utf-8') as bh:
                bh.write(s)
            with open(f, 'w', encoding='utf-8') as fh:
                fh.write(new_s)
            print('Updated:', f)
            updated.append(f)
        except Exception as e:
            print(f"SKIP (write error): {f} -> {e}")
print('Done. Updated %d files.' % len(updated))
