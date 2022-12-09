//
// Created by aidah on 12/7/2022.
//
#include <string.h>
#include "Predmet.h"
#include <iostream>


Predmet::Predmet() {

}

Predmet::Predmet(const char *n, int o) {
    strcpy(this->naziv, reinterpret_cast<const char *>(50));
    this->ocjena=o;
}
void Predmet::setNaziv() {
    std::cout<<"Unesite naziv predmeta: ";
    std::cin.getline(this->naziv, 50);
}
void Predmet::setOcjena() {
    std::cout<<"Unesi ocjenu: ";
    std::cin>> this->ocjena;
    std::cin.ignore();
}
char *Predmet::getNaziv() {
    return this->naziv;
}
int Predmet::getOcjena() {
    return this->ocjena;
}
std::istream &operator>>(std::istream &stream, Predmet &p) {
    p.setOcjena();
    p.setOcjena();
    return stream;
}
std::ostream &operator<<(std::ostream &stream, Predmet &p) {
    stream<<p.getNaziv() << " - (" << p.getOcjena() << ") ";
    return stream;
}
/*Predmet::Predmet(const Predmet &p) noexcept {
    strcpy(this->naziv, p.naziv);
    this->ocjena=p.ocjena;
} */
