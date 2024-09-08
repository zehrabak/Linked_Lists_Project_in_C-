/**
* Dugum.hpp
* Dugum sınıfının başlık dosyası
* 1/A grubu
* 1. ödev
* 25/07/2023
* Zehra Bak - zehra.bak@ogr.sakarya.edu.tr
*/

#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>
using namespace std;

class Dugum {
public:
    int deger;
    Dugum* sonraki;
    
    Dugum(const int deger=0, Dugum* sonraki=nullptr);
    ~Dugum();// Yıkıcı
};

#endif