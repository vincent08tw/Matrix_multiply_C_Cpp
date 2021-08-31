/****************************
[file name]--------------
main.cpp
[project name]----------
matrixMultiply_v9 
[despription]------
matrix multiply
can do O = AB with two method
	1. typing in cosole window
	2. from text file (matrix_a.txt)(matrix_b.txt)
can use differend method to do O = AB
	1. O = A * B
	2. O->matrix_multiplication(A,B)

and output on console window and output file (matrix_o#.txt)
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-08-31 
[last modify]----
2021-08-31 
[additional explain]----
v1 : original and 10*10 max size  
v2 : flexible array size (compare to v1)
v3 : better visible effect print out
v4 : can do non-square matrix multiply 
v5 : use class and operator overloading to create operator for matrix O = AB 
v6 : can get data from text file instead of typing on console window, and it can output result to text file 
v7 : very big change! our class declaration use "new" instead, so every Matrix.some() become Matrix->some() and finally delete Matrix
v8 : add matrix ID to see how constroctor and deconstroctor work
	 add second method to do O = AB (by use void function matrix_multiplication)
	 allocate matrix space to Matrix_O# before doing computation 
v9 : can creat random matrix
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
	srand(time(NULL));
	// print setting argument in "define.h"
	print_define_setting(true); //true for print the setting in "define.h"
	
	// class declaration
    Matrix_class *Matrix_A = new Matrix_class;
    Matrix_class *Matrix_B = new Matrix_class;
    Matrix_class *Matrix_O1 = new Matrix_class;
//    Matrix_class *Matrix_O2 = new Matrix_class;
	
	// decide the size of matrix A and B
	int ROW_A = 3;
	int COL_A = 5;
	int ROW_B = 5;
	int COL_B = 9;
	
	#if SIZE_IN_AUTO == 1
    cout<<"enter the number of row of A = " << ROW_A << " (auto)\n";    
    Matrix_A->set_numberOfRow(ROW_A); 
    cout<<"enter the number of column of A= " << COL_A << " (auto)\n";    
    Matrix_A->set_numberOfColumn(COL_A); 
	cout<<"enter the number of row of B = " << ROW_B << " (auto)\n";    
    Matrix_B->set_numberOfRow(ROW_B); 
    cout<<"enter the number of column of B= " << COL_B << " (auto)\n";    
    Matrix_B->set_numberOfColumn(COL_B); 
    #else 
    cout<<"enter the number of row of A = ";    
    Matrix_A->set_numberOfRow(); 
    cout<<"enter the number of column of A = ";    
    Matrix_A->set_numberOfColumn(); 
	cout<<"enter the number of row of B = ";    
    Matrix_B->set_numberOfRow(); 
    cout<<"enter the number of column of B= ";    
    Matrix_B->set_numberOfColumn(); 
    #endif
    
    /**** Matrix size allocation ****/
    Matrix_A->matrix_allocation();
    Matrix_B->matrix_allocation();
    
    /**** Creat randon int matrix ****/
    #if CREAT_RANDOM_MATRIX == 1
    Matrix_A->creat_random_int_matrix("matrix_a.txt",  0, 5);
    Matrix_B->creat_random_int_matrix("matrix_b.txt",  0, 5);
    //can also use creat_random_int_matrix("matrix_b.txt", ROW_B, COL_B, 0, 5); it will auto allocate
    #endif
    
    /**** Matrix content set****/
    #if MATRIX_IN_AUTO == 1
    cout<<"\n enter the first matrix (A) element = (auto)\n";
    Matrix_A->set_content_from_txt("matrix_a.txt");
    cout<<"\n enter the second matrix (B) element = (auto)\n";
    Matrix_B->set_content_from_txt("matrix_b.txt");
    #else
    cout<<"\n enter the first matrix (A) element =\n";
	Matrix_A->set_content();  
	cout<<"\n enter the second matrix (B) element =\n";    
    Matrix_B->set_content(); 
    #endif
	
    /**** for printing matrix A ****/  
	cout<< "\n matrix A:\n";   
	Matrix_A->print_content();

	/**** for printing matrix B ****/
	cout<< "\n matrix B:\n";   
	Matrix_B->print_content();
	
	/**** Output matrix size depend on matrix A and B ****/
	/**** Output matrix space allocation****/
    // example A: 3*5 | B: 5*2 
	//      -> O: 3     *    2
	Matrix_O1->set_matrix_size_2D(Matrix_A->get_numberOfRow(), Matrix_B->get_numberOfColumn() );
//	Matrix_O2->set_matrix_size_2D(Matrix_A->get_numberOfRow(), Matrix_B->get_numberOfColumn() );
	
	/**** computing O = AB****/
	cout << "\n computing O1 = AB ...\n\n";
	*Matrix_O1 = (*Matrix_A) * (*Matrix_B);
	/**** computing O = BA****/
//	cout << "\n computing O2 = BA ...\n\n";
//	Matrix_O2->matrix_multiplication(*Matrix_B, *Matrix_A);
	
    /**** for printing result ****/ 
    cout << "\n output matrix O1 = \n"; 
	Matrix_O1->print_content();
//	cout << "\n output matrix O2 = \n"; 
//	Matrix_O2->print_content();
	
	/**** write output to txt****/
	Matrix_O1->write_content_to_txt("matrix_o1.txt");
//	Matrix_O2->write_content_to_txt("matrix_o2.txt");
	
	delete Matrix_A;
	delete Matrix_B;
	delete Matrix_O1;
//	delete Matrix_O2;
	
	system("pause");
    return 0;  
}
