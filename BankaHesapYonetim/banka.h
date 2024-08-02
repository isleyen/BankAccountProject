#pragma once
#include <iostream>

using namespace std;

class Banka {
private:
	string kullanciAdi;
	int hesapNumarasi;
	int bakiye;
public:
	Banka(string _kullaniciAdi, int _hesapNumarasi, int _bakiye);
	void setKullaniciAdi(string _kullaniciAdi);
	void setHesapNumarasi(int _hesapNumarasi);
	void setBakiye(int _bakiye);
	string getKullaniciAdi();
	int getHesapNumarasi();
	int getBakiye();
	void hesapBilgileriniYazdir();
};