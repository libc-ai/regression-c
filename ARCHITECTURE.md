### Proje Mimari Kılavuzu: Neyi Nereye Include Edeceğiz?

Bu proje, **Model**, **Optimizer** ve **Kullanıcı** katmanlarını kesin bir şekilde ayırır. Bir dosyayı kodlarken, o dosyanın hangi katmanda olduğunu bilmek, neyi `#include` edeceğini belirler. Aşağıdaki yönergeleri doğrudan geliştiricilere/Co-pilot benzeri araçlara gönderin.

---

#### 1. Kural: `examples/` Katmanı (KULLANICI KODU)

- Dosya Türü: `examples/Linear_Regression/Iterative/adam.c`
- Amacı: Kütüphanenin bir **son kullanıcısını** simüle eder. `main()` fonksiyonu içerir.
- NE İÇERİR (`#include`)?
  - **SADECE** ana kütüphane başlığını: `#include "creg.h"`
  - Gerekiyorsa standart C kütüphaneleri: `<stdio.h>`, `<stdlib.h>`
- NE İÇERMEZ (`#include` ETMEZ)?
  - `src/` altından `.c` dosyalarını ASLA `#include` etmez (ör. `#include "src/models/linear_regression/linear_regression.c"` gibi).
  - `include/` altından tek tek alt başlıkları `#include` etmesine gerek yoktur; `creg.h` tüm public başlıkları toplayıp sağlamalıdır.
- Ne Yapar?
  - `linear_regression_fit()`, `optimizer_config_create()`, `r2_score()` gibi **public API** fonksiyonlarını çağırır.

---

#### 2. Kural: `src/models/` Katmanı (MODEL "BEYNİ")

- Dosya Türü: `src/models/linear_regression/linear_regression.c`
- Amacı: Modeli tanımlar. `fit`, `predict` ve modele özel `_gradient` (veya `_hessian`) fonksiyonlarını implemente eder. Optimizer'ları **kullanan** katmandır.
- NE İÇERİR (`#include`)?
  - Kendi public başlığı: `#include "models/linear_regression.h"`
  - Optimizer API'si (çağırmak için): `#include "optimizers/optimizer.h"`
  - Yardımcı fonksiyonlar: `#include "utils/matrix.h"`, `#include "loss/loss.h"`
  - Tipler: `#include "types.h"`
- Ne Yapar?
  - `linear_regression_fit()` fonksiyonu, `src/optimizers/` içindeki **genel** `run_optimizer()` (veya benzeri) fonksiyonunu çağırır.
  - Bu çağrıyı yaparken, kendisine ait `_linear_regression_gradient` fonksiyonunu bir **fonksiyon göstericisi (function pointer)** olarak parametre geçirir.

---

#### 3. Kural: `src/optimizers/` Katmanı (JENERİK ALGORİTMA)

- Dosya Türü: `src/optimizers/FirstOrder/adam/adam.c`
- Amacı: Sadece optimizasyon algoritmasının matematiğini uygular. Hangi modeli (Lineer, Lojistik vb.) optimize ettiğini **BİLMEZ**.
- NE İÇERİR (`#include`)?
  - Kendi public başlığı: `#include "optimizers/first_order.h"` veya `#include "optimizers/optimizer.h"`
  - Yardımcı fonksiyonlar: `#include "utils/math.h"`, `#include "utils/matrix.h"`
  - Sistem kütüphaneleri: `<math.h>` vb.
- Ne Yapar?
  - Parametre olarak aldığı **fonksiyon göstericisini** (gradyan fonksiyonu) döngü içinde çağırır.
  - Gelen gradyanı kullanarak ağırlıkları (weights) günceller.

---

#### 4. Kural: `src/utils/`, `src/loss/`, `src/metrics/` Katmanı (ARAÇLAR)

- Dosya Türü: `src/utils/matrix/matrix.c` veya `src/loss/mse/mse.c`
- Amacı: Bağımsız, tek bir işi yapan (matris çarpımı, MSE hesaplama vb.) fonksiyonları içerir.
- NE İÇERİR (`#include`)?
  - Kendi public başlığı: `#include "utils/matrix.h"` veya `#include "loss/loss.h"`
  - Gerekiyorsa diğer araçlar: Örneğin `loss/mse.c`, hesaplama için `utils/matrix.h`'ı `#include` edebilir.
  - Sistem kütüphaneleri: `<stdlib.h>`, `<stdio.h>` vb.
- Ne Yapmaz?
  - `src/loss/mse.c` dosyası, `models/linear_regression.h` hakkında **hiçbir şey bilmemelidir**.

---

#### 5. Kural: `include/` Katmanı (GENEL "SÖZLEŞMELER")

- Dosya Türü: `include/models/linear_regression.h`
- Amacı: Dış dünyanın (`examples/` veya `src/models/`) kullanacağı public fonksiyon prototiplerini ve struct'ları tanımlar.
- NE İÇERİR (`#include`)?
  - Tüm temel tiplerin (Struct `Matrix`, `Vector`, `Model` vb.) tanımlandığı ana tip başlığı: `#include "types.h"`
  - Parametre olarak alacağı diğer struct tanımları: Örneğin `linear_regression.h`, `OptimizerConfig*` parametresi alacağı için `#include "optimizers/optimizer.h"` dosyasını içerebilir.
- `creg.h`'nin Özel Rolü:
  - `creg.h` dosyası, `examples/` kullanıcısının hayatını kolaylaştırmak için **diğer tüm public `.h` dosyalarını** (`include/models/linear_regression.h`, `include/optimizers/optimizer.h` vb.) `#include` eden tek bir "ana" başlık dosyası olmalıdır.

---

Ek Notlar / Tavsiyeler
- .c dosyaları arası bağımlılıkları header'lar üzerinden sağlayın; `.c` dosyalarını başka `.c` dosyasında `#include` etmeyin.
- Public API'leri `include/*.h` içinde tutun; internal (private) fonksiyonlar için ayrı internal header konvansiyonu (örn. `internal.h`) kullanılabilir.
- Fonksiyon pointer tabanlı API (ör. optimizer -> gradient callback) katmanlar arası gevşek bağlama sağlar ve test/CI için önemlidir.

Bu dosyayı repository köküne koydum; geliştiricilere direkt gönderilebilir bir rehberdir.
