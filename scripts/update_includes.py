#!/usr/bin/env python3
import sys,os,glob,re
root = os.path.dirname(os.path.dirname(__file__))
os.chdir(root)
files = glob.glob("examples/**/*.c", recursive=True) + glob.glob("src/**/*.c", recursive=True)
files = sorted(files)
for f in files:
    try:
        with open(f, 'r', encoding='utf-8') as fh:
            s = fh.read()
    except Exception as e:
        print(f"SKIP (read error): {f} -> {e}")
        continue
    if '#include "creg.h"' in s or '#include "types.h"' in s:
        continue
    prefix = ''
    if '/examples/' in f:
        if '#include <stdio.h>' in s:
            prefix = '#include "creg.h"\n\n'
        else:
            prefix = '#include <stdio.h>\n#include "creg.h"\n\n'
    elif '/src/models/' in f:
        m = re.search(r'/src/models/([^/]+)/', f)
        model = m.group(1) if m else 'unknown'
        prefix = f'#include "models/{model}.h"\n#include "optimizers/optimizer.h"\n#include "utils/matrix.h"\n#include "loss/loss.h"\n#include "types.h"\n\n'
    elif '/src/optimizers/' in f:
        prefix = '#include "optimizers/optimizer.h"\n#include "utils/math.h"\n#include "utils/matrix.h"\n#include "types.h"\n\n'
    elif '/src/analytic/' in f:
        m = re.search(r'/src/analytic/([^/]+)/', f)
        ana = m.group(1) if m else 'unknown'
        prefix = f'#include "analytic/{ana}.h"\n#include "utils/matrix.h"\n#include "types.h"\n\n'
    elif '/src/loss/' in f:
        prefix = '#include "loss/loss.h"\n#include "types.h"\n\n'
    elif '/src/metrics/' in f:
        prefix = '#include "metrics/metrics.h"\n#include "types.h"\n\n'
    elif '/src/utils/' in f:
        m = re.search(r'/src/utils/([^/]+)/', f)
        util = m.group(1) if m else 'unknown'
        prefix = f'#include "utils/{util}.h"\n#include "types.h"\n\n'
    else:
        prefix = '#include "types.h"\n\n'
    try:
        with open(f, 'w', encoding='utf-8') as fh:
            fh.write(prefix + s)
        print('Updated:', f)
    except Exception as e:
        print(f"SKIP (write error): {f} -> {e}")
print('Done')