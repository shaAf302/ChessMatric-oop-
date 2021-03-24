//Author Shafaqat Iqbal
//neptun pmr75l, Assignment no. 1.1
//Chess Matrix, Group 1;
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "matrix.h"

class Menu
{
    public:
        Menu(){};
        void Run();
    private:
        int MenuPrint();
        void add();
        void print();
        void multiply();
        void getElem();
        matrix M;
        int elem;
        bool addition = false;
        bool multiplication = false;
        bool getelem = false;

};

#endif // MENU_H_INCLUDED
