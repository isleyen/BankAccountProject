#include <iostream>
#include "banka.h"
#include <list>


using namespace std;

void menuyuGoster() {
	cout << "* * * * * * * * * *" << endl;
	cout << "*                 *" << endl;
	cout << "*       MENU      *" << endl;
	cout << "*                 *" << endl;
	cout << "* * * * * * * * * *" << endl;
	cout << "1.Hesap Ekle " << endl;
	cout << "2.Hesap Bilgilerini Goster " << endl;
	cout << "3.Para Yatirma " << endl;
	cout << "4.Para Cekme " << endl;
	cout << "5.Hesap Silme " << endl;
	cout << "6.Tum Hesaplari Goster " << endl;
	cout << "7.Cikis " << endl;
}
void hesapEkle(list <Banka>* lst) {
	string ad, soyad, isim;
	int hesapNumarasi;
	int bakiye = 0; // başlangıc degeri icin sıfır atadım.
	cout << "Ad Soyad Giriniz: "; cin >> ad >> soyad;
	cout << "Hesap Numarasini Giriniz: "; cin >> hesapNumarasi;
	isim = ad + " " + soyad;
	Banka bank(isim, hesapNumarasi, bakiye); // nesne oluşturuyorum.
	lst->push_back(bank); // Bank nesnesine pushladım
}
void bilgileriGoster(list <Banka>* lst) {
	int hesapNumarasi;
	cout << "Lutfen bulmak istediginiz banka hesabının hesap numarasini giriniz: "; cin >> hesapNumarasi;
	list <Banka>::iterator itr;

	for (itr = lst->begin(); itr != lst->end(); itr++) {
		if (itr->getHesapNumarasi() == hesapNumarasi) {
			break;
		}
	}
	if (lst->end() == itr) {
		cout << "Belirtilen hesap numarasina ait banka hesabi bulunamamistir." << endl;
	}
	else {
		cout << "Aradiginiz Hesap Bilgileri: " << endl;
		itr->hesapBilgileriniYazdir();
		cout << endl;
	}
}
void paraYatir(list <Banka>* lst) {
	int hesapNumarasi;
	double miktar;
	list<Banka>::iterator itr;

	cout << "Para yatirmak istediginiz hesap numarasini giriniz: "; cin >> hesapNumarasi;
	while (true) {
		for (itr = lst->begin(); itr != lst->end(); itr++) { // benim burada tanımladıgın end aslında listenin sondaki nesne değil.

			if (itr->getHesapNumarasi() == hesapNumarasi) {
				break;
			}
		}
		if (itr == lst->end()) {
			cout << "Girilen hesap numarasina ait hesap bulunamamistir. Tekrar deneyiniz: "; cin >> hesapNumarasi;

		}
		else {
			break;
		}
	}
	cout << "Yatirmak istediginiz miktarı giriniz: "; cin >> miktar;
	int yeniBakiye = itr->getBakiye() + miktar;
	itr->setBakiye(yeniBakiye);
	cout << "Para yatirma islemi basarili. Guncel Bakiye: " << itr->getBakiye() << endl;

	
	
}

void paraCek(list <Banka>* lst) {
	int hesapNumarasi;
	double miktar;
	list<Banka>::iterator itr;
	cout << "Para cekmek istediginiz hesap numarasini giriniz: "; cin >> hesapNumarasi;

	while (true) {
		for (itr = lst->begin(); itr != lst->end(); itr++) {
			if (itr->getHesapNumarasi() == hesapNumarasi) {
				break;
			}
		}
		if (itr == lst->end()) {
			cout << "Girdiginiz hesap numarasina ait hesap bulunamadi. Lutfen tekrar deneyiniz: "; cin >> hesapNumarasi;
		}
		else {
			break;
		}
	}
	cout << "Cekmek istediginiz miktarı giriniz: "; cin >> miktar;

	while (miktar > itr->getBakiye()) {
		cout << "Yetersiz Bakiye. Mevcut Bakiyeniz: " << itr->getBakiye() << " Tekrar Deneyiniz: "; cin >> miktar;
	}
	int yeniBakiye = itr->getBakiye() - miktar;
	itr->setBakiye(yeniBakiye);
	cout << "Guncel Bakiyeniz: " << itr->getBakiye();

}
void hesapSil(list <Banka>* lst) {
	list<Banka>::iterator itr;
	int hesapNumarasi;
	cout << "Lutfen silmek istediginiz hesabın hesap numarasini giriniz: "; cin >> hesapNumarasi;
	for (itr = lst->begin(); itr != lst->end(); itr++) {
		if (itr->getHesapNumarasi() == hesapNumarasi) {
			break;
		}
	}
	if (lst->end() == itr) {
		cout << "Lutfen gecerli bir hesap numarasi giriniz.";
	}
	else {
		lst->erase(itr);
	}
}
void hesapGoster(list <Banka>* lst) {
	cout << endl;
	cout << "------------TUM HESAPLAR------------\n";
	list<Banka>::iterator itr;

	for (itr = lst->begin(); itr != lst->end(); itr++) {
		itr->hesapBilgileriniYazdir();
	}
	cout << endl;
}



int main() {

	list <Banka>* bankaList = new list <Banka>(); // Liste olusturuldu. Şimdi Bu liste içine bilgiler kaydedilecek.
	
	int secim;
	do {
		menuyuGoster();
		cout << "Seciminizi Giriniz: "; cin >> secim;
		if (secim == 1) {
			hesapEkle(bankaList);
		}
		else if (secim == 2) {
			bilgileriGoster(bankaList);
		}
		else if (secim == 3) {
			paraYatir(bankaList);
		}
		else if (secim == 4) {
			paraCek(bankaList);
		}
		else if (secim == 5) {
			hesapSil(bankaList);
		}
		else if (secim == 6) {
			hesapGoster(bankaList);
		}
		else if (secim == 7) {
			break;
		}
		else {
			cout << "Lutfen gecerli bir deger giriniz!" << endl;
		}

	} while (secim != 5);

	return 0;
}
