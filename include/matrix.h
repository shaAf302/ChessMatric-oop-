//Author Shafaqat Iqbal
//neptun pmr75l, Assignment no. 1.1
//Chess Matrix, Group 1;
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <string>
#include <ostream>

using std::cout;
using std::cin;
using std::string;
using std::vector;
class matrix
{
    public:
        enum errors{incorrect_size, corrupt_file, index_out_of_bound, inequal_size};
        ///constructors
        matrix(); //doesn't do anything
        matrix(const std::vector<int> &vec);
        matrix(const std::string &filename);


        ///methods

        int element_at(unsigned int i, unsigned int j) const;
        unsigned int getSize()const{return _size;}
        static matrix add(const matrix &A, const matrix &B);
        static matrix multiply(const matrix &A, const matrix &B);



        ///operator overloading cout << matrix
        friend std::ostream& operator<<(std::ostream &stream, const matrix &matrix);

    private:
        unsigned int _size;
        std::vector <int> _vec;

        bool isChessMatrix(unsigned int length_of_vector) const;
        unsigned int calcSize(unsigned int length_of_vector) const;
        int index(int i,int j) const;
};

#endif // MATRIX_H



