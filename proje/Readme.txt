Projeyi çalıştırmak için makefile bulunan klasörde terminalden
" bin/proje dat/giris.dat dat/cikis.dat " komutu girilmelidir.

dat klasörü : Giris ve Cikis dosyaları bulunmaktadir.
doc klasörü : Örnek ekran çıktılarına ait pdf dökümanı bulunur.
bin klasörü : çalışır program burda bulunur.
src klasörü : Proje kaynak kodu burda bulunur.


Amaç

Bu projede , veri dosyasından okunan komutlara göre çıkış dosyası
oluşturan bir programı C dilinde gerçeklemek.

İçerik

Libfdr dosyasında libfdr kütüphanesinden yararlanılmaktadır.
b221210350_b201210554 dosyasında proje kaynak kodları giriş-çıkış
dosyaları bulunmaktadır.Verilen giriş dosyasına göre çıkış üretilmiştir. 

Derleme

Gerekli kütüphaneler projeye eklendi. libfdr dan fields.h kütüphanesinden
IS türünde nesne oluşturuldu ve giris.dat dosyası ile ilişkilendirildi.
Ilk başta hata kontrolleri yapılarak projenin çökmesi engellendi. "yaz:" 
komutu strcmp fonksiyonu ile giris.dat dosyasında aratıldı.Bulunan sayılar
ve harfler statik diziye kaydedili."sil:" komutu için de aynı şekilde işlemler
uygulandı."yaz:" ve "sil:" dizileri karşılaştırılarak gerekli silme işlemleri
yapıldı.En son "cikis.dat" dosyasına dizi yazdırıldı.

Çalıştırma

Projeyi çalıştırmak için makefile bulunan klasörde terminalden
" bin/proje dat/giris.dat dat/cikis.dat " komutu girilmelidir.
Eksik hatalı girişler için hatalar engellenmiştir.
proje çalıştıktan sonra komut satırında "dur: Program sonlanmıştır!"
yazmaktadır.

