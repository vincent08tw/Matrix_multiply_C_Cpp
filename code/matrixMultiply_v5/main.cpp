/****************************
[file name]--------------
main.cpp
[project name]----------
matrixMultiply_v5
[despription]------
matrix multiply
[create date]---
2021-08-27
[last modify]----
2021-08-27
[additional explain]----
v1 : original and 10*10 max size  
v2 : flexible array size (compare to v1)
v3 : better visible effect print out
v4 : can do non-square matrix multiply 
v5 : use class and operator overloading to create operator for matrix O = AB 
****************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>  
#include "class.h"
#include "function.h"
#include "define.h" 
using namespace std;  
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv)
{
	// class declaration
    Matrix_class Matrix_A;
    Matrix_class Matrix_B;
    Matrix_class Matrix_O;
    
	int i,j,k; //temp variable for loop
	
	// decide the size of matrix A and B
    cout<<"enter the number of row of A =";    
    Matrix_A.set_numberOfRow(); 
    cout<<"enter the number of column of A=";    
    Matrix_A.set_numberOfColumn(); 
	cout<<"enter the number of row of B =";    
    Matrix_B.set_numberOfRow(); 
    cout<<"enter the number of column of B=";    
    Matrix_B.set_numberOfColumn(); 
    
    multiplication_size_detection(Matrix_A.get_numberOfColumn(), Matrix_B.get_numberOfRow() ); //detect if col_A = row_B
    
    /**** Output matrix size depend on matrix A and B ****/
    // example A: 3*5 | B: 5*2 
	//      -> O: 3     *    2
    Matrix_O.set_numberOfRow(Matrix_A.get_numberOfRow() );
	Matrix_O.set_numberOfColumn(Matrix_B.get_numberOfColumn() );    
    
    /**** Matrix size allocation ****/
    Matrix_A.matrix_allocation();
    Matrix_B.matrix_allocation();
    //Matrix_O.matrix_allocation();
    
    cout<<"enter the first matrix (A) element=\n";
	Matrix_A.set_content();   

    cout<<"enter the second matrix (B) element=\n";    
    Matrix_B.set_content(); 

    /**** for printing matrix A ****/  
	cout<<"matrix A:\n";   
	Matrix_A.print_content();

	/**** for printing matrix B ****/
	cout<<"matrix B:\n";   
	Matrix_B.print_content();
	
	/**** computing O = AB****/
	cout <<"computing O = AB ...\n\n";
	Matrix_O = Matrix_A * Matrix_B;
	
    /**** for printing result ****/ 
    cout<<"output matrix O = \n"; 
	Matrix_O.print_content();  
	
    return 0;  
}
