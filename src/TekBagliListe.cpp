/**
* TekBagliListe.cpp
* TekBagliListe sınıfının kaynak dosyası
* 1/A grubu
* 1. ödev
* 25/07/2023
* Zehra Bak - zehra.bak@ogr.sakarya.edu.tr
*/
#include "TekBagliListe.hpp"
#include <iostream>

TekBagliListe::TekBagliListe() : bas(nullptr), satirSayisi(0) {}

TekBagliListe::TekBagliListe(int satirSayisi) : bas(nullptr) {
}

void TekBagliListe::Ekle(int veri) {
    Dugum* yeniDugum = new Dugum(veri);
    yeniDugum->sonraki = bas;
    bas = yeniDugum;
}
void TekBagliListe::DugumEkleTersten(Dugum* yeniDugum) {
    if (bas == nullptr) {
        bas = yeniDugum;
    } else {
        Dugum* sonDugum = bas;
        while (sonDugum->sonraki != nullptr) {
            sonDugum = sonDugum->sonraki;
        }
        sonDugum->sonraki = yeniDugum;
    }
    }
void TekBagliListe::YerDegistir(TekBagliListe& digerListe) {
    Dugum* temp = bas;
    bas = digerListe.bas;
    digerListe.bas = temp;
}

void TekBagliListe::Yazdir() const {
    Dugum* aktif = bas;
    while (aktif != nullptr) {
        std::cout << aktif->deger << " ";
        aktif = aktif->sonraki;
    }
    std::cout << std::endl;
}
Dugum* TekBagliListe::BasDugum() {
    return bas;
}


void TekBagliListe::TumDugumleriSil() {
    Dugum* aktif = bas;
    while (aktif != nullptr) {
        Dugum* temp = aktif;
        aktif = aktif->sonraki;
        delete temp;
    }
    bas = nullptr; // Liste boşaltıldığında bas nullptr yapıldı.
}

TekBagliListe::~TekBagliListe() {

}




