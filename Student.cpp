//
// Created by aidah on 12/7/2022.
//

#include "Student.h"
#include <string.h>
#include <memory>

Student::Student() {
    strcpy(this->ime, "Novi");
    strcpy(this->prezime, "Student");
    this->brIndeksa=0;
    this->godina=prva;
}
Student::Student(const char *i, const char *p, int b, Godina g) {
    strcpy(this->ime, i);
    strcpy(this->prezime, p);
    this->brIndeksa=b;
    this->godina=g;
}
Student::Student(const Student &s) {
    strcpy(this->ime, s.ime);
    strcpy(this->prezime, s.prezime);
    this->brIndeksa=s.brIndeksa;
    this->godina=s.godina;
}
void Student::setIme() {
    std::cout<<"Unesite ime: ";
    std::cin.getline(this->ime, 20);
}
void Student::setPrezime() {
    std::cout<<"Unesite prezime: ";
    std::cin.getline(this->prezime, 50);
}
void Student::setBrIndeksa() {
    std::cout<<"Unesite broj indeksa: ";
    std::cin>>this->brIndeksa;
    std::cin.ignore();
}
void Student::setGodina() {
    std::shared_ptr<int> x=std::make_shared<int>();
    do {
        std::cout<<"Unesite godinu studija: ";
        std::cin>>*x;
    } while(*x<1 || *x>5);
    std::cin.ignore();
    this->godina=static_cast<Godina>(*x);
}
void Student::setPredemet() {
    Predmet temp;
    std::cin>>temp;
    this->predemti.push_back(temp);
}
char *Student::getIme() {
    return this->ime;
}
char *Student::getPrezime() {
    return this->prezime;
}
int Student::getBrIndeksa() {
    return this->brIndeksa;
}
Godina Student::getGodina() {
    return this->godina;
}
std::vector<Predmet> &Student::getPredemti() {
    return this->predemti;
}
void Student::operator++(int) {
    this->brIndeksa++;
}
void Student::operator^(int n) {
    this->getPredemti().erase(this->getPredemti().begin() + n-1);
    std::cout<<"\nPredmet je uspjesno obrisan! \n";
}
std::istream &operator>>(std::istream &stream, Student &s) {
    s.setIme();
    s.setPrezime();
    s.setBrIndeksa();
    s.setGodina();
    int x;
    do {
        std::cout<<"\n Unesite 0 za kraj, bilo koji drugi broj za unos novog predmeta";
        std::cin>>x;
        std::cin.ignore();
        if(x!=0) s.setPredemet();
    } while (x!=0);
    return stream;
}
std::ostream &operator<<(std::ostream &stream, Student &s) {
    system("cls");
    stream<<"Student: " << s.getIme() << " " << s.getPrezime() << " - " <<s.getBrIndeksa() << "\n";
    stream<< "Godina studija: " << Student::getGodinaString(s.getGodina());
    stream << "R. br. \t Predmet i ocjena\n";
    stream<<"--------------------------------------------\n";
    for (int i=0; i<s.getPredemti().size(); i++) {
        stream<<i+1 << "\t" << s.getPredemti()[i] << "\n";
    }
    return stream;
}
float operator!(Student &s) {
    float rez=0;
    for (int i=0;  i<s.getPredemti().size(); i++) {
        rez+=s.getPredemti()[i].getOcjena();
    }
    rez/=static_cast<float>(s.getPredemti().size());
    return rez;
}