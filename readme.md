# regression-c

C ile yazılmış, modüler ve hafif bir regresyon kütüphanesi. Lineer/Logistik/Poisson/Ridge/Lasso/Elastic Net/Robust/SVR modelleri; analitik çözücüler (Normal Denklem, QR, SVD) ve zengin optimizasyon algoritmaları (GD, SGD, Momentum, Nesterov, Adagrad, Adadelta, RMSProp, Adam, AdamW, Adamax, Nadam, Newton, Quasi-Newton, L-BFGS, Koordinat İnişi) ile.

## Özellikler

- Modeller: Linear, Logistic, Poisson, Ridge, Lasso, Elastic Net, Robust Regression, SVR
- Optimizasyon: İlk-derem (GD, SGD, Momentum, Nesterov, Adagrad, Adadelta, RMSProp, Adam, AdamW, Adamax, Nadam), İkinci-derecem (Newton, Quasi-Newton, L-BFGS), Koordinat inişi
- Analitik çözücüler: Normal denklem, QR ayrışımı, SVD
- Kayıplar: MSE, MAE, LogLoss, Huber
- Metrikler: Accuracy, R², MAPE
- Bağımlılık yok, C99, kolay derlenir (GCC/Clang)

## Mimari (kısa özet)

- Public başlıklar `include/` altında; örnekler yalnızca `creg.h` üzerinden tüm API’ye erişir.
- `src/` tarafında her modül kendi public başlığını include eder ve gerektiğinde `types.h`, `utils/*` başlıklarını kullanır.
- Ayrıntılar için `ARCHITECTURE.md` dosyasına bakın.

## Dizin Yapısı

- `include/`: Public API (modeller, optimizers, analytic, loss, metrics, utils, `types.h`, `creg.h`)
- `src/`: Modül implementasyonları (modeller, optimizers, analytic, loss, metrics, utils)
- `examples/`: Derlenebilir, minimal örnek programlar (yalnızca `<stdio.h>` + `creg.h` içerir)
- `Makefile`: Örnekleri derlemek için üst seviye make kuralları
- `ARCHITECTURE.md`: Mimari kurallar ve include sözleşmeleri

## Kurulum ve Derleme

Önkoşullar: GCC ya da Clang (C99), make.

Örnekleri derlemek için proje kökünde:

```sh
make
```

Temizlemek için:

```sh
make clean
```

`make` tüm `examples/` altındaki `.c` dosyalarını derleyip aynı dizinlerde çalıştırılabilirler üretir (repoda .gitignore ile takip dışıdır).

## Kullanım Deseni

- Örnekler: Yalnızca `#include "creg.h"` (ve gerekiyorsa `<stdio.h>`). Başka internal başlık include edilmez.
- src implementasyonları: Kendi public başlığını ve ihtiyaca göre `types.h`, `utils/matrix.h`, `utils/math.h`, `loss/loss.h` vb. include eder.

## Katkı

PR’lar ve issue’lar memnuniyetle karşılanır. Yeni bir modül eklerken:
- Public başlığı `include/<kategori>/<isim>.h` altında oluşturun.
- Implementasyonu `src/<kategori>/<isim>/<isim>.c` altında konumlandırın.
- Örnek gerekiyorsa `examples/` altında minimal bir `.c` dosyası ekleyin ve yalnızca `creg.h` kullanın.

## Yol Haritası (öneri)

- Temel veri yapıları ve API’lerin doldurulması (şu an bir kısmı placeholder)
- Test altyapısı ve CI (GitHub Actions ile `make` doğrulaması)
- Dokümantasyon ve basit benchmark örnekleri

## Lisans

Bu proje MIT lisansı ile lisanslanmıştır. Ayrıntılar için `LICENSE` dosyasına bakın.

---

## English Summary

Lightweight, modular regression library in C. Models: Linear/Logistic/Poisson/Ridge/Lasso/Elastic Net/Robust/SVR; Analytic solvers (Normal Equation, QR, SVD); Optimizers (GD, SGD, Momentum, Nesterov, Adagrad, Adadelta, RMSProp, Adam, AdamW, Adamax, Nadam, Newton, Quasi-Newton, L-BFGS, Coordinate Descent). No external deps, C99, easy to build.

Quick build

```sh
make
make clean
```

Architecture highlights
- Public headers live under `include/` and examples only include `creg.h` (+ `<stdio.h>`)
- Implementations under `src/` include their own public headers and `types.h`/`utils/*` as needed