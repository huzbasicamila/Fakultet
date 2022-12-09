//
// Created by aidah on 12/7/2022.
//

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <iostream>
#include <vector>
#include "Predmet.h"
enum Godina {prva=1, druga, treca, cetvrta, peta};

class Student {
private:
    char ime[20], prezime[50];
    int brIndeksa;
    std::vector<Predmet> predemti;
    Godina godina;

public:
    Student();
    Student(const char* i, const char* p, int b, Godina g);
    Student(const Student& s);
    void setIme();
    void setPrezime();
    void setGodina();
    void setBrIndeksa();
    void setPredemet();
    char* getIme();
    char* getPrezime();
    int getBrIndeksa();
    Godina getGodina();
    std::vector<Predmet>& getPredemti();
    friend std::istream& operator>>(std::istream& stream, Student& s);
    friend std::ostream& operator<<(std::ostream& stream, Student& s);
    void operator++();
    void operator++(int);
    friend float operator!(Student& s);
    void operator^(int n);
    static std::string getGodinaString(Godina x) {
        switch(x) {
            case prva:
                return "Prva. \n";
            case druga:
                return "Druga \n";
            case treca:
                return "Treca. \n";
            case cetvrta:
                return "Cetvrta. \n";
            case peta:
                return "Peta. \n";
            default:
                return "Diplomirao. \n";
        }
    }
    ~Student()=default;
};


#endif //UNTITLED_STUDENT_H
