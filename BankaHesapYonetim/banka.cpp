#include "banka.h"

Banka::Banka(string _kullaniciAdi, int _hesapNumarasi, int _bakiye) {
	kullanciAdi = _kullaniciAdi;
	hesapNumarasi = _hesapNumarasi;
	bakiye = _bakiye;
}
void Banka::setKullaniciAdi(string _kullaniciAdi) {
	kullanciAdi = _kullaniciAdi;
}
void Banka::setHesapNumarasi(int _hesapNumarasi) {
	hesapNumarasi = _hesapNumarasi;
}
void Banka::setBakiye(int _bakiye) {
	bakiye = _bakiye;
}
string Banka::getKullaniciAdi() {
	return kullanciAdi;
}
int Banka::getHesapNumarasi() {
	return hesapNumarasi;
}
int Banka::getBakiye() {
	return bakiye;
}
void Banka::hesapBilgileriniYazdir() {
	cout << "Kullanici Adi: " << kullanciAdi << " - Hesap Numarasi : " << hesapNumarasi << " - Bakiye: " << bakiye << endl;
}