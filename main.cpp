//Author Shafaqat Iqbal
//neptun pmr75l, Assignment no. 1.1
//Chess Matrix, Group 1;
#include "matrix.h"
#include "menu.h"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{

        Menu a;
        a.Run();



    return 0;
}


#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("File constructor", "wrong input data in file"){
    CHECK_THROWS(matrix m1("WRONGINPUT.txt")); //must throw an exception
}


TEST_CASE("indexes out of bound", "value at row i column j in a file"){
    int row = 1;
    int column = 10;
        matrix m1("1.txt");
    CHECK_THROWS(m1.element_at(row, column));
}

TEST_CASE("vector constructor", "wrong input data in vector"){
    std::vector<int> wrong_vector = {332,11,22,33,44,33,44,55,4,33,22,33,44,33,22,33,44,33,22,33,44,33,22}; // the vector size is not a chess type matrix
    CHECK_THROWS(matrix m1(wrong_vector));
}



TEST_CASE("negative indexes", "value at row i column j in a file"){
    int row = -1;
    int column = -1;
    matrix m1("1.txt");
    CHECK_THROWS(m1.element_at(row, column));
}



TEST_CASE("correct indexes", "values of j and i in file"){
    int row = 2, column = 2, value = 6; // have check this manually
    matrix m1("1.txt");
    CHECK(value == m1.element_at(row, column));
}
TEST_CASE("Checking value", "value on given row and colomn") {

    matrix m1("1.txt");
    CHECK(m1.element_at(0,0) == 1);
    CHECK(m1.element_at(2,3) == 0);
    CHECK(m1.element_at(3,3) == 8);
    CHECK(m1.element_at(2,1) == m1.element_at(1,2));
}

TEST_CASE("addition", "Adding two matrices simply") {

    matrix m1("1.txt");
    matrix m2("1.txt");
    m1 = m1.add(m1,m2);
    CHECK(m1.element_at(0,0) ==2);
    CHECK(m1.element_at(0,2) ==4);
    CHECK(m1.element_at(1,1) ==6);
    CHECK(m1.element_at(1,3) ==8);
    CHECK(m1.element_at(2,0) ==10);
    CHECK(m1.element_at(2,2) ==12);
    CHECK(m1.element_at(3,1) ==14);
    CHECK(m1.element_at(3,3) ==16);

}
TEST_CASE("multiplication", "multiplying two matrices simply") {

    matrix m1("1.txt");
    matrix m2("1.txt");
    m1 = m1.multiply(m1,m2);
    CHECK(m1.element_at(0,0) ==11);
    CHECK(m1.element_at(0,2) ==14);
    CHECK(m1.element_at(1,1) ==37);
    CHECK(m1.element_at(1,3) ==44);
    CHECK(m1.element_at(2,0) ==35);
    CHECK(m1.element_at(2,2) ==46);
    CHECK(m1.element_at(3,1) ==77);
    CHECK(m1.element_at(3,3) ==92);


}




#endif
