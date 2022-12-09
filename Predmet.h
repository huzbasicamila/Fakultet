//
// Created by aidah on 12/7/2022.
//

#ifndef UNTITLED_PREDMET_H
#define UNTITLED_PREDMET_H

#include <istream>

class Predmet {
private:
    Predmet(const char *n, int o);

    char naziv[50];
    int ocjena;

public:
    Predmet();

    void setNaziv();
    void setOcjena();
    char* getNaziv();
    int getOcjena();
    friend std::istream& operator>>(std::istream& stream, Predmet& p);
    friend std::ostream& operator<<(std::ostream& stream, Predmet& p);
    ~Predmet()=default;
};


#endif //UNTITLED_PREDMET_H
