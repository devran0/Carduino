# Carduino

# Arduino Tabanlı 4WD Akıllı Araç

Bu proje, Arduino ve ESP kartlarını kullanarak internet üzerinden haberleşebilen, kamerası olan, 4 motorlu ve 4 tekerlekli bir araç geliştirmeyi amaçlamaktadır.

## İçindekiler 

- [Gereksinimler](#gereksinimler)
- [Kurulum](#kurulum)
  - [Donanım Kurulumu](#donanım-kurulumu)
  - [Yazılım Kurulumu](#yazılım-kurulumu)
- [Kullanım](#kullanım)
- [Notlar](#notlar)
- [Dosya Açıklamaları](#dosya-açıklamaları)

## Gereksinimler

- Arduino Uno
- ESP8266 Wi-Fi modülü
- 4WD robotik araç kiti
- Motor sürücü (L298N)
- Bağlantı kabloları ve breadboard
- Güç kaynağı (piller veya batarya)

## Kurulum

### Donanım Kurulumu

**Motor Sürücü Bağlantısı:**

L298N motor sürücüsünü Arduino Uno'ya bağlayın ve motorları sürücüye bağlayın.

**ESP8266 Modülü:**

ESP8266'yı Arduino Uno'ya bağlayın.

### Yazılım Kurulumu

1. Arduino IDE'yi indirin ve kurun.
2. [WiFiEspAT kütüphanesini indirin.](https://github.com/JAndrassy/WiFiEspAT)
3. WifiEspAt kütüphanesini Arduino IDE'ye ekleyin: `Sketch -> Include Library -> Add zip library -> WiFiEspAT` yi yükleyin.
4. Bu repo'yu klonlayın veya indirin: `git clone https://github.com/devran0`

## Kullanım

1. Web sayfanıza `index.txt` ve `dashboard.php` dosyalarını atın.
2. Web tarayıcınızdan `dashboard.php` dosyasına erişin.
3. Kontrol panelinden aracınızı ileri, geri, sağa, sola veya durdurma komutları ile kontrol edin.
4. Bu kod sitede bulunan `index.txt` dosyasından veri alır: `client.println("GET /index.txt HTTP/1.1")`.
   
**Notlar:**
- Siteniz HTTP desteklemek zorundadır ve 80. portu açık olmalıdır.

## Dosya Açıklamaları

- **dashboard.php:** Bu dosya, aracın web tabanlı kontrol panelini içerir. HTML ve PHP kullanarak kontrol butonları oluşturur ve tıklanan butona göre komutları `index.txt` dosyasına yazar.
- **carduino.ino:** Bu dosya, Arduino üzerinde çalışacak olan yazılımı içerir. ESP8266 üzerinden gelen komutları alır ve motor sürücüsüne ileterek aracı kontrol eder.
