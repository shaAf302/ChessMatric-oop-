//Author Shafaqat Iqbal
//neptun pmr75l, Assignment no. 1.1
//Chess Matrix, Group 1;

#include "matrix.h"

#include <cmath>
#include <fstream>

matrix::matrix(){
    _size = 0;
}


matrix::matrix(const vector<int> &vec){
    //size check chess matrix
    int length = vec.size();
    if(! isChessMatrix(length)){
        throw errors::incorrect_size;
    }
    //size fix
    _size = calcSize(length);
    //vector copy
    _vec = vec;
}


unsigned int matrix::calcSize(unsigned int length)const{
    return 2 * sqrt(length / 2 );
}

bool matrix::isChessMatrix(unsigned int length) const{
    // length = 2 * n * n
    double N = sqrt(length / 2);
    if(N == (int) N){
        return true;
    }
    return false;
}


matrix::matrix(const std::string &filename){

    //file reading
    std::fstream file(filename);
    if(file.fail()){
        throw errors::corrupt_file;
    }
    int num;
    while(file >> num ){
        //vector copy
        _vec.push_back(num);
    }

    //is chess matrix check
    if(! isChessMatrix(_vec.size())){
       throw errors::incorrect_size;
       _vec.clear();
       _size = 0;
    }

    //calculate size
    _size = calcSize(_vec.size());

}


int matrix::index(int i, int j)const{
    return _size/2 * i + floor(j /2);
}

int matrix::element_at(unsigned int i, unsigned int j)const{
    if(i < 0 || j < 0 || i >= _size || j >= _size){
        throw errors::index_out_of_bound;
    }

    ///if non-zero elements
    if((i + j) % 2 == 0){
        return _vec[index(i, j)];
    }

    return 0;

}


matrix matrix::add(const matrix &A,const matrix &B){
    //size check
    if(A._size != B._size ){
        throw errors::inequal_size;
    }
    vector<int> ret_vec;
    for(int i = 0; i<A._vec.size(); i++){
        ret_vec.push_back(A._vec[i] + B._vec[i]);
    }
    matrix m(ret_vec);
    return m;
}


matrix matrix::multiply(const matrix &A,const matrix &B){
    if(A._size != B._size ){
        throw errors::inequal_size;
    }
    vector<int> ret_vec;
    for(unsigned int i = 0; i<A._size; i++){
        for(unsigned int j = 0; j<A._size; j++){
            if((i + j) % 2 == 0){
                int sum = 0;
                for(int k  = 0; k < A._size; k++){
                    sum += A.element_at(i, k) * B.element_at(k, j);
                }
                ret_vec.push_back(sum);
            }
        }
    }
    matrix m(ret_vec);
    return m;
}


std::ostream& operator<<(std::ostream& Stream,const matrix& m)
{
    Stream << "    " << m._size <<"x"<< m._size << ": "<<std::endl;
    for (unsigned int i=0;i<m._size;i++)
    {
        for (unsigned int j=0;j<m._size;j++)
        {
            Stream << "    "  << m.element_at(i,j);
        }
        Stream << "\n\n";
    }
    return Stream;
}

