/****************************
[file name]--------------
main.cpp
[project name]----------
matrixMultiply_v13
[despription]------
2D matrix operation
can creat random matrix 
can do convolution computing conv(A,B)
can do O = A + B
can do O = A¡DB 
can do O = AB with two method
	1. typing in cosole window
	2. from text file (matrix_a.txt)(matrix_b.txt)
can use differend method to do O = AB
	1. O = A * B
	2. O->matrix_multiplication(A,B)

and output on console window and output file (matrix_o#.txt)

3D matrix convolution (channel, row, column)
3D matrix convolution (channel, row, column, stride, zero-padding)
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-09-02
[last modify]----
2021-09-03 
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
v10: can do Hadamard product
	 can O = A + B 
v11: can do convolution computing of matrix_a and matrix_b
v12: create "class3D.h"
	 can do 3D matrix convolution
v13: can set stride and zero-padding for 2D/3D matrix convolution
****************************/

#include "include.h"
#include "class.h"
#include "class3D.h"
#include "define.h"
#include "function.h"

using namespace std;  
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv)
{
	srand(time(NULL));
	
	// print setting argument in "define.h"
	print_define_setting(true); //true for print the setting in "define.h"
	
	// class declaration
    Matrix_3D_class *Matrix_A = new Matrix_3D_class;
    Matrix_3D_class *Matrix_B = new Matrix_3D_class;
	Matrix_3D_class *Matrix_O = new Matrix_3D_class;
	
	// decide the size of matrix A and B
	int CNL_A = 2;
	int ROW_A = 7;
	int COL_A = 7;
	int CNL_B = 2;
	int ROW_B = 3;
	int COL_B = 3;
	
	#if SIZE_IN_AUTO == 1
	cout<<"enter the number of channel of A = " << CNL_A << " (auto)\n";    
    Matrix_A->set_numberOfChannel(CNL_A); 
    cout<<"enter the number of row of A = " << ROW_A << " (auto)\n";    
    Matrix_A->set_numberOfRow(ROW_A); 
    cout<<"enter the number of column of A = " << COL_A << " (auto)\n";    
    Matrix_A->set_numberOfColumn(COL_A); 
    cout<<"enter the number of channel of B = " << CNL_B << " (auto)\n";    
    Matrix_B->set_numberOfChannel(CNL_B);
	cout<<"enter the number of row of B = " << ROW_B << " (auto)\n";    
    Matrix_B->set_numberOfRow(ROW_B); 
    cout<<"enter the number of column of B = " << COL_B << " (auto)\n";    
    Matrix_B->set_numberOfColumn(COL_B); 
    #else 
    cout<<"enter the number of channel of A = ";    
    Matrix_A->set_numberOfChannel(); 
    cout<<"enter the number of row of A = ";    
    Matrix_A->set_numberOfRow(); 
    cout<<"enter the number of column of A = ";    
    Matrix_A->set_numberOfColumn(); 
    cout<<"enter the number of channel of B = ";    
    Matrix_B->set_numberOfChannel(); 
	cout<<"enter the number of row of B = ";    
    Matrix_B->set_numberOfRow(); 
    cout<<"enter the number of column of B = ";    
    Matrix_B->set_numberOfColumn(); 
    #endif
    
    /**** Matrix size allocation ****/
    Matrix_A->matrix_allocation();
    Matrix_B->matrix_allocation();
    
    /**** Creat randon int matrix ****/
    #if CREAT_RANDOM_MATRIX == 1
    cout << "\n>> creat random matrix \"matrix_a.txt\", \"matrix_b.txt\" \n";
    Matrix_A->creat_random_int_matrix("matrix_a.txt",  0, 3);
    Matrix_B->creat_random_int_matrix("matrix_b.txt",  0, 3);
    //can also use creat_random_int_matrix("matrix_b.txt", ROW_B, COL_B, 0, 5); it will auto allocate
    #endif
    
    /**** Matrix content set****/
    #if MATRIX_IN_AUTO == 1
    cout << "\n enter the first matrix (A) element = (auto)\n";
    Matrix_A->set_content_from_txt("matrix_a.txt");
    cout << "\n enter the second matrix (B) element = (auto)\n";
    Matrix_B->set_content_from_txt("matrix_b.txt");
    #else
    cout << "\n enter the first matrix (A) element =\n";
//	Matrix_A->set_content();  
	cout << "\n enter the second matrix (B) element =\n";    
//    Matrix_B->set_content(); 
    #endif
	
    /**** for printing matrix A ****/  
	cout << "\n matrix A:\n";   
	Matrix_A->print_content();

	/**** for printing matrix B ****/
	cout << "\n matrix B:\n";   
	Matrix_B->print_content();
	
	/**** computing O = conv(A,B)****/
	Matrix_O->matrix_convolution(*Matrix_A, *Matrix_B, 3, 2);
	/**** for printing result ****/ 
	cout << "\n output matrix O = \n"; 
	Matrix_O->print_content();
	Matrix_O->write_content_to_txt("matrix_o.txt");
	
	delete Matrix_A;
	delete Matrix_B;
	delete Matrix_O;
	
	system("pause");
    return 0;  
}
