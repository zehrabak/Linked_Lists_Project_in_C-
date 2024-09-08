/**
* Main.cpp
* Main 
* 1/A grubu
* 1. ödev
* 25/07/2023
* Zehra Bak - zehra.bak@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "TekBagliListe.hpp"
using namespace std;
int main() {
try{
    ifstream dosya("Sayilar.txt");
    if (!dosya.is_open()) {
        cerr << "Dosya acilamadi." << endl;
        return 1;
    }

    int satirSayisi = 0;
    int maxDugumSayisi = 0;
    string satir;

    while (getline(dosya, satir)) {
        if (!satir.empty()) {
            istringstream iss(satir);
            int sayi;
            int adet = 0; // Satırdaki 2 basamaklı sayı adedi
            while (iss >> sayi) {
                if (sayi >= 10 && sayi <= 99) {
                    adet++;
                }
            }
            maxDugumSayisi = max(maxDugumSayisi, adet);
            satirSayisi++;
        }
    }
    dosya.clear();
    dosya.seekg(0, ios::beg);

    int* dugumSayisi = new int[maxDugumSayisi];
    double* parcaToplam = new double[maxDugumSayisi];
    for (int i = 0; i < maxDugumSayisi; i++) {
        dugumSayisi[i] = 0;
        parcaToplam[i] = 0.0;
    }

    TekBagliListe liste=TekBagliListe(satirSayisi);
    TekBagliListe* birlerBasamagiDizisi = new TekBagliListe[satirSayisi];
    TekBagliListe* onlarBasamagiDizisi = new TekBagliListe[satirSayisi];

    // Dosyadan okuyarak listeleri olusturulur
    int sayi;
    for (int i = 0; i < satirSayisi; i++) {
        string satir;
        getline(dosya, satir);
        istringstream iss(satir);
        while (iss >> sayi) {
            int onlarBasamagi = sayi / 10;
            onlarBasamagiDizisi[i].DugumEkleTersten(new Dugum(onlarBasamagi));
            int birlerBasamagi = sayi % 10;
            birlerBasamagiDizisi[i].DugumEkleTersten(new Dugum(birlerBasamagi));
        }
    }

    dosya.close();

    
    int konumA, konumB;
    cout << "Konum A: ";
    cin >> konumA;
    cout << "Konum B: ";
    cin >> konumB;
    if (konumA < 0 || konumA >= satirSayisi || konumB < 0 || konumB >= satirSayisi) {
    throw std::runtime_error("Gecersiz konum!");
    }
    // Yer degistirme islemi gerceklestirilir
    birlerBasamagiDizisi[konumB].YerDegistir(onlarBasamagiDizisi[konumA]);

   
for (int i = 0; i < satirSayisi; i++) {
    TekBagliListe& hedefListe = onlarBasamagiDizisi[i];
    Dugum* aktif = hedefListe.BasDugum();
    int index = 0; // dizilerin indisini belirlemek için
    while (aktif != nullptr) {
        parcaToplam[index] += aktif->deger;
        dugumSayisi[index]++;
        aktif = aktif->sonraki;
        index++;
    }
}
double UstOrtalama=0.0;
// Ust Ortalamalar hesaplanır ve yazdırılır
for (int i = 0; i < maxDugumSayisi; i++) {
    if (dugumSayisi[i] > 0) {
        double ortalama = parcaToplam[i] / dugumSayisi[i];
    
        UstOrtalama += ortalama;    
    } else {
        cout << " Dugum yok " << endl;
    }
} 
cout << "Ust: "<< UstOrtalama << endl;


UstOrtalama=0.0;
for(int i = 0; i < maxDugumSayisi; i++){
    parcaToplam[i] = 0.0;
    dugumSayisi[i]=0;
} 


for (int i = 0; i < satirSayisi; i++) {
    TekBagliListe& hedefListe = birlerBasamagiDizisi[i];
    Dugum* aktif = hedefListe.BasDugum();
    int index = 0; // dizilerin indisini belirlemek için
    while (aktif != nullptr) {
        parcaToplam[index] += aktif->deger;
        dugumSayisi[index]++;
        aktif = aktif->sonraki;
        index++;
    }
}
double AltOrtalama=0.0;

// Alt Ortalamalar hesaplanır ve yazdırılır
for (int i = 0; i < maxDugumSayisi; i++) {
    if (dugumSayisi[i] > 0) {
        double ortalama = parcaToplam[i] / dugumSayisi[i];
        
        AltOrtalama += ortalama;    
    } else {
        cout <<" Dugum yok " << endl;
    }
} 
cout << "Alt: " << AltOrtalama << endl;



// Daha sonra dinamik diziler kaldırılır 
delete[] dugumSayisi;
delete[] parcaToplam;

for (int i = 0; i < satirSayisi; i++) {
        birlerBasamagiDizisi[i].TumDugumleriSil();
        onlarBasamagiDizisi[i].TumDugumleriSil();
    }

delete[] birlerBasamagiDizisi;
delete[] onlarBasamagiDizisi;

}  catch (const std::runtime_error& e) {
        std::cerr << "Hata: " << e.what() << std::endl;
    }
    return 0;
}





