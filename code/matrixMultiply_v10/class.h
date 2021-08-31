/****************************
[file name]--------------
class.h
[project name]----------
matrixMultiply_v10
[despription]------
matrix multiply
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-08-31 
[last modify]----
2021-08-31 
[additional explain]----
v6 : add function of Matrix_class
	 void set_content_from_txt(char filename[]);
	 void write_content_to_txt(char filename[]);
v9 : void matrix_Hadamard_product(Matrix_class,Matrix_class);
	 void creat_random_int_matrix(string filename, int row, int col, int min, int max);
v10: int inner_product(Matrix_class, Matrix_class);
	 matrix addition
****************************/


#ifndef CLASS_H
#define CLASS_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>  
#include <fstream>
#include <iomanip>
#include <time.h>

#ifndef DEFINE_H
#include "define.h"
#endif

#ifndef FUNCTION_H
#include "function.h"
#endif

using namespace std;

class Matrix_class
{
	private:
		// Private section
		int numberOfRow, numberOfColumn; //row number of row and column of matrix
	public:
		// Public Declarations
		
		#if DEBUG_MODE == 1
		int ID; // ID for class
		Matrix_class() //constroctor
		{
			ID = idcount;
			cout << "Matrix_class ID: " << ID << " is created \n";
			idcount_increase(); //idcount++
		}
		#endif
		//content of matrix
		int** matrix_content; 
		//creat random integer number matrix and give row column directly
		void creat_random_int_matrix(string filename, int row, int col, int min, int max);  
		//creat random integer number matrix 
		void creat_random_int_matrix(string filename, int min, int max);
		//allocate space of matrix depend on numberOfRow and numberOfColumn
		void matrix_allocation();
		//set content of matrix
		void set_content();
		//set content of matrix from txt file
		void set_content_from_txt(string filename);
		//save matrix to txt file
		void write_content_to_txt(string filename);
		//print content of matrix
		void print_content();
		//set number of row of matrix by hand
		void set_numberOfRow();
		//set number of row of matrix by input argument of function call
		void set_numberOfRow(int number_int);
		//set number of row and column of matrix by input argument of function call
		void set_matrix_size_2D(int row, int col);
		//set number of column of matrix by hand
		void set_numberOfColumn();
		//set number of column of matrix by input argument of function call
		void set_numberOfColumn(int number_int);
		//return number of row of matrix
		int get_numberOfRow();
		//return number of column of matrix
		int get_numberOfColumn();
		
		void matrix_multiplication(Matrix_class, Matrix_class);
		void matrix_Hadamard_product(Matrix_class, Matrix_class);
		void matrix_addition(Matrix_class, Matrix_class);
		int inner_product(Matrix_class, Matrix_class);
		
		friend int** operator*(Matrix_class,Matrix_class);
		friend int** operator+(Matrix_class,Matrix_class);
		
		Matrix_class& operator=(int** content)
		{
			matrix_content = content;
		}
		
		friend ostream& operator<<(ostream&, Matrix_class&);
		#if DEBUG_MODE == 1
		~Matrix_class() //deconstroctor
		{
			cout << "delete Matrix_class ID: " << ID << "\n";
		}
		#endif
		
	protected:
		// Protected Declarations
};
void Matrix_class::creat_random_int_matrix(string filename, int row, int col, int min, int max)
{
	int i,j;
	
	this->numberOfRow = row;
	this->numberOfColumn = col;
	this->matrix_allocation();
	
	ofstream fout(filename.c_str());
	
	if(!fout) // detect if fail to open file
	{    
		cout << "fail to open " << filename << " !!" << endl;
	}
	else
	{
		
		#if DEBUG_MODE == 1
		cout << ">>> write data to " << "\"" << filename << "\"..." << endl;
		#endif
		for(i = 0;i < row;i++)    
	    {   
	        for(j = 0;j < col;j++)    
	        {   
				this->matrix_content[i][j] = rand() % (max - min + 1) + min;
				
	        	fout << this->matrix_content[i][j] << ' ';
	        }
			fout << "\n";  
	    }  
		fout.close();   // close file  
		#if DEBUG_MODE == 1
		cout << "write finish !! \n\n" << endl;
		#endif
	}
}
void Matrix_class::creat_random_int_matrix(string filename, int min, int max)
{
	int i,j;
	
	
	
	ofstream fout(filename.c_str());
	
	if(!fout) // detect if fail to open file
	{    
		cout << "fail to open " << filename << " !!" << endl;
	}
	else
	{
		#if DEBUG_MODE == 1
		cout << ">>> write data to " << "\"" << filename << "\"..." << endl;
		#endif
		for(i = 0;i < this->get_numberOfRow();i++)    
	    {   
	        for(j = 0;j < this->get_numberOfColumn();j++)    
	        {   
				this->matrix_content[i][j] = rand() % (max - min + 1) + min;
	        	fout << this->matrix_content[i][j] << ' ';
	        }
			fout << "\n";  
	    }  
		fout.close();   // close file  
		#if DEBUG_MODE == 1
		cout << "write finish !! \n\n" << endl;
		#endif
	}
}
void Matrix_class::matrix_multiplication(Matrix_class A, Matrix_class B)
{
	size_t i;
	size_t j;
	size_t k;
	
	int row_A = A.get_numberOfRow();
	int col_B = B.get_numberOfColumn();
	int row_B = B.get_numberOfRow();
	int col_A = A.get_numberOfColumn();
	
	/* detect matrix size*/
	multiplication_size_detection(col_A, row_B);

	for(i = 0;i < row_A;i++)    
    {    
        for(j = 0;j < col_B;j++)    
        {    
            this->matrix_content[i][j] = 0;    
            for(k = 0;k < col_A;k++)    
            {    
                this->matrix_content[i][j] += A.matrix_content[i][k] * B.matrix_content[k][j];    
            }    
        }    
    }
}
void Matrix_class::matrix_addition(Matrix_class A, Matrix_class B)
{
	size_t i;
	size_t j;
	
	int row_A = A.get_numberOfRow();
	int col_B = B.get_numberOfColumn();
	int row_B = B.get_numberOfRow();
	int col_A = A.get_numberOfColumn();
	
	/* detect matrix size*/
	inner_product_size_detection(col_A, col_A, row_B, col_B);
	
	/* allocation a space for output matrix */
	
	for(i = 0;i < row_A;i++)
	{
		for(j = 0;j < col_A;j++)
		{
			this->matrix_content[i][j] = A.matrix_content[i][j] + B.matrix_content[i][j];
		}
	}
}
int Matrix_class::inner_product(Matrix_class A, Matrix_class B)
{
	size_t i;
	size_t j;
	int temp = 0;
	
	int row_A = A.get_numberOfRow();
	int col_B = B.get_numberOfColumn();
	int row_B = B.get_numberOfRow();
	int col_A = A.get_numberOfColumn();
	
	/* detect matrix size*/
	inner_product_size_detection(col_A, col_A, row_B, col_B);
	
	for(i = 0;i < row_A;i++)
	{
		for(j = 0;j < col_A;j++)
		{
			temp += A.matrix_content[i][j] * B.matrix_content[i][j];
		}
	}
	return temp;
}
void Matrix_class::matrix_Hadamard_product(Matrix_class A, Matrix_class B)
{
	size_t i;
	size_t j;
	size_t k;
	
	int row_A = A.get_numberOfRow();
	int col_B = B.get_numberOfColumn();
	int row_B = B.get_numberOfRow();
	int col_A = A.get_numberOfColumn();
	
	/* detect matrix size*/
	inner_product_size_detection(col_A, col_A, row_B, col_B);
	
	for(i = 0;i < row_A;i++)
	{
		for(j = 0;j < col_A;j++)
		{
			this->matrix_content[i][j] = A.matrix_content[i][j] * B.matrix_content[i][j];
		}
	}
}
int** operator*(Matrix_class A, Matrix_class B)
{
	size_t i;
	size_t j;
	size_t k;
	
	int row_A = A.get_numberOfRow();
	int col_B = B.get_numberOfColumn();
	int row_B = B.get_numberOfRow();
	int col_A = A.get_numberOfColumn();
	
	/* detect matrix size*/
	multiplication_size_detection(col_A, row_B);

	/* allocation a space for output matrix */
	int** temp_mul;
	temp_mul = new int* [row_A];
	for(i = 0;i < row_A;i++)
	{
		temp_mul[i] = new int[col_B];
	}
	for(i = 0;i < row_A;i++)    
    {    
        for(j = 0;j < col_B;j++)    
        {    
            temp_mul[i][j] = 0;    
            for(k = 0;k < col_A;k++)    
            {    
                temp_mul[i][j] += A.matrix_content[i][k] * B.matrix_content[k][j];    
            }    
        }    
    }
    return temp_mul;
}
int** operator+(Matrix_class A, Matrix_class B)
{
	size_t i;
	size_t j;
	
	int row_A = A.get_numberOfRow();
	int col_B = B.get_numberOfColumn();
	int row_B = B.get_numberOfRow();
	int col_A = A.get_numberOfColumn();
	
	/* detect matrix size*/
	inner_product_size_detection(col_A, col_A, row_B, col_B);
	
	/* allocation a space for output matrix */
	int** temp_plus;
	temp_plus = new int* [row_A];
	for(i = 0;i < row_A;i++)
	{
		temp_plus[i] = new int[col_B];
	}
	
	for(i = 0;i < row_A;i++)
	{
		for(j = 0;j < col_A;j++)
		{
			temp_plus[i][j] = A.matrix_content[i][j] + B.matrix_content[i][j];
		}
	}
    return temp_plus;
}
void Matrix_class::set_matrix_size_2D(int row, int col)
{
	this->numberOfRow = row;
	this->numberOfColumn = col;
	
	this->matrix_allocation();
}
void Matrix_class::set_numberOfRow()
{
	cin >> this->numberOfRow;
}
void Matrix_class::set_numberOfRow(int number_int)
{
	this->numberOfRow = number_int;
}
void Matrix_class::set_numberOfColumn()
{
	cin >> this->numberOfColumn;
}
void Matrix_class::set_numberOfColumn(int number_int)
{
	this->numberOfColumn = number_int;
}
int Matrix_class::get_numberOfRow()
{
	return this->numberOfRow;
}
int Matrix_class::get_numberOfColumn()
{
	return this->numberOfColumn;
}
void Matrix_class::matrix_allocation()
{
	size_t row;
	size_t column;
	this->matrix_content = new int* [this->numberOfRow];
	for(row = 0;row < this->numberOfRow;row++)
	{
		this->matrix_content[row] = new int[this->numberOfColumn];
	}
	#if DEBUG_MODE == 1
	cout << "Matrix ID : " << ID << " space allocation complete! \n";
	#endif
}
void Matrix_class::set_content()
{
	size_t row;
	size_t column;
	for(row = 0;row < this->numberOfRow;row++)    
    {    
        for(column = 0;column < this->numberOfColumn;column++)    
        {    
            cin >> this->matrix_content[row][column];  
        }    
    }    
}
void Matrix_class::set_content_from_txt(string filename)
{
	size_t row;
	size_t column;
	
	ifstream fin(filename.c_str());

	if(!fin) // detect if fail to open file
	{    
		cout << "fail to open " << filename << " !!" << endl;
	}
	else
	{
		//#if DEBUG_MODE == 1
		cout << ">>> read data from " << "\"" << filename << "\"..." << endl;
		//#endif
		
		int element;
		
		for(row = 0;row < this->numberOfRow;row++)    
	    {    
	        for(column = 0;column < this->numberOfColumn;column++)    
	        {   
	        	fin >> element;
	            this->matrix_content[row][column] = element;  
	        }    
	    }
		fin.close();   // close file 
	}
	   
}
void Matrix_class::write_content_to_txt(string filename)
{
	size_t row;
	size_t column;
	
	ofstream fout(filename.c_str());

	if(!fout) // detect if fail to open file
	{    
		cout << "fail to open " << filename << " !!" << endl;
	}
	else
	{
		#if DEBUG_MODE == 1
		cout << ">>> write data to " << "\"" << filename << "\"..." << endl;
		#endif
		for(row = 0;row < this->numberOfRow;row++)    
	    {   
	        for(column = 0;column < this->numberOfColumn;column++)    
	        {   
	        	fout << this->matrix_content[row][column] << ' ';
	        }
			fout << "\n";  
	    }  
		fout.close();   // close file  
		#if DEBUG_MODE == 1
		cout << "write finish !! \n\n" << endl;
		#endif
	}
}
void Matrix_class::print_content()
{
	size_t row;
	size_t column;
	printf("¢z");
	for(column = 0;column < this->numberOfColumn;column++)
	{
		printf("%5c",' ');
	}
	printf("¢{\n");
    for(row = 0;row < this->numberOfRow;row++)    
    {    
    	printf("¢x");
        for(column = 0;column < this->numberOfColumn;column++)    
        {   
        	printf("%5d",this->matrix_content[row][column]);
        }    
        printf("¢x");
        cout << "\n";    
    }  
	printf("¢|");
	for(column = 0;column < this->numberOfColumn;column++)
	{
		printf("%5c",' ');
	}
	printf("¢}\n");
}

int inner_product(Matrix_class A, Matrix_class B)
{
	size_t i;
	size_t j;
	int temp = 0;
	
	int row_A = A.get_numberOfRow();
	int col_B = B.get_numberOfColumn();
	int row_B = B.get_numberOfRow();
	int col_A = A.get_numberOfColumn();
	
	/* detect matrix size*/
	inner_product_size_detection(col_A, col_A, row_B, col_B);
	
	for(i = 0;i < row_A;i++)
	{
		for(j = 0;j < col_A;j++)
		{
			temp += A.matrix_content[i][j] * B.matrix_content[i][j];
		}
	}
	return temp;
}
#endif
