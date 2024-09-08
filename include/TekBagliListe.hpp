/**
* TekBagliListe.hpp
* TekBagliListe sınıfının başlık dosyası
* 1/A grubu
* 1. ödev
* 25/07/2023
* Zehra Bak - zehra.bak@ogr.sakarya.edu.tr
*/

#ifndef TEKBAGLILISTE_HPP
#define TEKBAGLILISTE_HPP
#include <Dugum.hpp>
class TekBagliListe {
private:
    Dugum* bas;
    int satirSayisi;
public:
    TekBagliListe(); // Varsayılan yapıcı
    TekBagliListe(int satirSayisi);
    void Ekle(int veri);
    void DugumEkleTersten(Dugum* yeniDugum);
    void YerDegistir(TekBagliListe& digerListe);
    void Yazdir() const;
    Dugum* BasDugum();
    void TumDugumleriSil();
    ~TekBagliListe();
};

#endif