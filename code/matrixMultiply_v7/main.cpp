/****************************
[file name]--------------
main.cpp
[project name]----------
matrixMultiply_v7
[despription]------
matrix multiply
can do O = AB with two method
	1. typing in cosole window
	2. from text file 
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
v6 : can get data from text file instead of typing on console window, and it can output result to text file 
v7 : very big change! our class declaration use "new" instead, so every Matrix.some() become Matrix->some() and finally delete Matrix;
****************************/

#ifndef CLASS_H
#include "class.h"
#endif

#ifndef DEFINE_H
#include "define.h"
#endif

#ifndef FUNCTION_H
#include "function.h"
#endif

using namespace std;  
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv)
{
	// class declaration
    Matrix_class *Matrix_A = new Matrix_class;
    Matrix_class *Matrix_B = new Matrix_class;
    Matrix_class *Matrix_O = new Matrix_class;
    
	int i,j,k; //temp variable for loop
	
	// decide the size of matrix A and B
    cout<<"enter the number of row of A =";    
    Matrix_A->set_numberOfRow(); 
    cout<<"enter the number of column of A=";    
    Matrix_A->set_numberOfColumn(); 
	cout<<"enter the number of row of B =";    
    Matrix_B->set_numberOfRow(); 
    cout<<"enter the number of column of B=";    
    Matrix_B->set_numberOfColumn(); 
     
    /**** Matrix size allocation ****/
    Matrix_A->matrix_allocation();
    Matrix_B->matrix_allocation();
    
    cout<<"\n enter the first matrix (A) element=\n";
	//Matrix_A->set_content();   
	Matrix_A->set_content_from_txt("matrix_a.txt");

    cout<<"\n enter the second matrix (B) element=\n";    
    //Matrix_B->set_content(); 
	Matrix_B->set_content_from_txt("matrix_b.txt");
	
    /**** for printing matrix A ****/  
	cout<< "\n matrix A:\n";   
	Matrix_A->print_content();

	/**** for printing matrix B ****/
	cout<< "\n matrix B:\n";   
	Matrix_B->print_content();
	
	/**** computing O = AB****/
	cout << "\n computing O = AB ...\n\n";
	*Matrix_O = (*Matrix_A) * (*Matrix_B);
	/**** Output matrix size depend on matrix A and B ****/
    // example A: 3*5 | B: 5*2 
	//      -> O: 3     *    2
	Matrix_O->set_matrix_size_2D(Matrix_A->get_numberOfRow(), Matrix_B->get_numberOfColumn() );
	
    /**** for printing result ****/ 
    cout << "\n output matrix O = \n"; 
	Matrix_O->print_content();
	
	/**** write output to txt****/
	Matrix_O->write_content_to_txt("matrix_o.txt");
	
	delete Matrix_A;
	delete Matrix_B;
	delete Matrix_O;
	
    return 0;  
}
