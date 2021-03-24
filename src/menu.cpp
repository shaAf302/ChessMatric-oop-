//Author Shafaqat Iqbal
//neptun pmr75l, Assignment no. 1.1
//Chess Matrix, Group 1;
#include <iostream>
#include "menu.h"
#include "../read.hpp"
#include <string>
#define menuCount 4 ///number of menu items

using namespace std;

///Check if the given menuitem number exists
bool check(int a){return a>=0 && a<=menuCount;}

void Menu::Run()
{
    int v;
   matrix C("1.txt");
    M = C;
    do{
        v=MenuPrint();
        switch(v)
        {
            case 1:
                print();
                break;
            case 2:
                add();
                if(!addition){
                        print();
                }
                M = C;
                addition = false;
                break;
            case 3:
                getElem();
               //print();
                break;
            case 4:
                multiply();
              if(!multiplication){
                        print();
                }
                M = C;
                multiplication = false;
                break;
            default:
                cout<<"\nGoodbye!\n";
                break;

        }
    }while(v!=0);
}

int Menu::MenuPrint()
{
    int choice;
    cout<<"\n****************************************\n";
    cout<<"0. Exit\n";
    cout<<"1. Print\n";
    cout<<"2. Add\n";
    cout<<"3. Get elements\n";
    cout<<"4. multiply\n";
    cout<<"****************************************\n";
    ///felxible error msg
    string input = "choose a number between 0 and 4: ";
    ///read with read.hpp
    choice=read<int>("Choose a menu item: ",input,check);

    return choice;
}

void Menu::print(){
    //CLEARSCREEN();
    cout << M;
}

void Menu::add(){
    //CLEARSCREEN();

    cout << "Enter the filename for 2nd matrix" << endl;
    string s;
    cin >> s;

    //matrix C("1.tx
    try{
        matrix B(s);
        M = M.add(M,B);
    }catch(matrix::errors e ){
        addition = true;
        if(e == matrix::errors::corrupt_file){
            cout << "the file is corrupt!";
        }else if( e ==  matrix::errors::inequal_size){
            cout <<  "Matrix sizes are not equal!" << endl;
        }
        else if(e == matrix::errors::incorrect_size){
            cout << "GIven matrix is not a chess type matrix.";
        }
        else{
            cout << "Uknown Error!" <<endl;
        }
    }
}

void Menu::multiply(){
    //CLEARSCREEN();
      cout << "Enter the filename for 2nd matrix" << endl;
    string s;
    cin >> s;

     try{
         matrix B(s);
        M = M.multiply(M,B);
    }catch(matrix::errors e ){
        multiplication = true;
        if(e == matrix::errors::corrupt_file){
            cout << "the file is corrupt!";
        }
        if( e ==   matrix::errors::inequal_size){
            cout <<  "Matrix sizes are not equal!" << endl;
        }
        else if(e == matrix::errors::incorrect_size){
            cout << "GIven matrix is not a chess type matrix.";
        }
        else
            cout << "Uknown Error!" <<endl;
    }


}

void Menu::getElem(){
    //CLEARSCREEN();
    //cout << M;
    cout << "Enter the indexes for the element you want"<<endl;
    int i,j;
    cin >> i >> j;
     try{
        elem = M.element_at(i,j);

    cout << "This is your element " << elem << endl;
    }catch(matrix::errors e ){
        if( e == matrix::errors::index_out_of_bound)
            cout <<  "index out of bound!" << endl;
        else
            cout << "Uknown Error!" <<endl;
    }
}
