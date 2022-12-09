#include <iostream>
#include <iomanip>
#include "Student.h"

int main() {
    Student s;
    std::cin>>s;
    std::cout<<s;
    system("cls");
    std::cout<<"\nProsjek: " << std::setprecision(2) << std::fixed << !s << "\n";
    int x;
    std::cout<<"Unesite redni broj predemta koji zelite obrisati: ";
    std::cin>>x;
    std::cin.ignore();
    s^x;
    std::cout<<s;
    system("pause");
    return 0;

}
