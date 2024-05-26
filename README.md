# Carduino
Arduino Tabanlı 4WD Akıllı Araç
Bu proje, Arduino ve ESP kartlarını kullanarak internet üzerinden haberleşebilen, kamerası olan, 4 motorlu ve 4 tekerlekli bir araç geliştirmeyi amaçlamaktadır.

İçindekiler
Gereksinimler
Kurulum
Donanım Kurulumu
Yazılım Kurulumu
Kullanım
Dosya Açıklamaları
Gereksinimler
Arduino Uno
ESP8266 Wi-Fi modülü
4WD robotik araç kiti
Motor sürücü (L298N)
Bağlantı kabloları ve breadboard
Güç kaynağı (piller veya batarya)
Kurulum
Donanım Kurulumu
Motor Sürücü Bağlantısı:

L298N motor sürücüsünü Arduino Uno'ya bağlayın ve motorları sürücüye bağlayın.

ESP8266 Modülü:

ESP8266'yı Arduino Uno'ya bağlayın.

Yazılım Kurulumu
Arduino IDE'yi indirin ve kurun.
WiFiEspAT kütüphanesini indirin.
WiFiEspAT kütüphanesini Arduino IDE'ye ekleyin: Sketch -> Include Library -> Add zip library -> WiFiEspAT.
Bu repo'yu klonlayın veya indirin: git clone https://github.com/devran0.
Kullanım
Donanım Kurulumu
Bağlantı şemasını şu şekilde yapın:

Motor Sürücü:

IN1, IN2, IN3, IN4 pinlerini Arduino dijital pinlerine bağlayın.
Motorları motor sürücünün çıkış pinlerine bağlayın.
ESP8266:

VCC ve GND pinlerini güç kaynağına, RX ve TX pinlerini uygun Arduino pinlerine bağlayın.
Kullanım Talimatları
Web tarayıcınızdan dashboard.php dosyasına erişin.
Kontrol panelinden aracınızı ileri, geri, sağa, sola veya durdurma komutları ile kontrol edin.
Dosya Açıklamaları
dashboard.php: Bu dosya, aracın web tabanlı kontrol panelini içerir. HTML ve PHP kullanarak kontrol butonları oluşturur ve tıklanan butona göre komutları index.txt dosyasına yazar.
carduino.ino: Bu dosya, Arduino üzerinde çalışacak olan yazılımı içerir. ESP8266 üzerinden gelen komutları alır ve motor sürücüsüne ileterek aracı kontrol eder.
