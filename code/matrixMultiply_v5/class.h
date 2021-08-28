/****************************
[file name]--------------
class.h
[project name]----------
matrixMultiply_v5
[despription]------
matrix multiply
[create date]---
2021-08-27
[last modify]----
2021-08-27
[additional explain]----

****************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>  
using namespace std;

#ifndef CLASS_H
#define CLASS_H

class Matrix_class
{
	private:
		// Private section
		int numberOfRow, numberOfColumn;
	public:
		// Public Declarations
		int** matrix_content;
		void matrix_allocation();
		void set_content();
		void print_content();
		void set_numberOfRow();
		void set_numberOfRow(int number_int);
		void set_numberOfColumn();
		void set_numberOfColumn(int number_int);
		int get_numberOfRow();
		int get_numberOfColumn();
		
		friend int** operator*(Matrix_class,Matrix_class);
		
		Matrix_class& operator=(int** content)
		{
			matrix_content = content;
		}
		
		friend ostream& operator<<(ostream&, Matrix_class&);
	protected:
		// Protected Declarations
};
int** operator*(Matrix_class A, Matrix_class B)
{
	size_t i;
	size_t j;
	size_t k;
	
	int row_A = A.get_numberOfRow();
	int col_B = B.get_numberOfColumn();
	int col_A = A.get_numberOfColumn();
	/* allocation a space for output matrix */
	int** mul;
	mul = new int* [row_A];
	for(i = 0;i < row_A;i++)
	{
		mul[i] = new int[col_B];
	}
	for(i = 0;i < row_A;i++)    
    {    
        for(j = 0;j < col_B;j++)    
        {    
            mul[i][j]=0;    
            for(k = 0;k < col_A;k++)    
            {    
                mul[i][j]+=A.matrix_content[i][k]*B.matrix_content[k][j];    
            }    
        }    
    }
    return mul;
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
void Matrix_class::print_content()
{
	size_t row;
	size_t column;
	printf("�z");
	for(column = 0;column < this->numberOfColumn;column++)
	{
		printf("%5c",' ');
	}
	printf("�{\n");
    for(row = 0;row < this->numberOfRow;row++)    
    {    
    	printf("�x");
        for(column = 0;column < this->numberOfColumn;column++)    
        {   
        	printf("%5d",this->matrix_content[row][column]);
        }    
        printf("�x");
        cout << "\n";    
    }  
	printf("�|");
	for(column = 0;column < this->numberOfColumn;column++)
	{
		printf("%5c",' ');
	}
	printf("�}\n");
}
#endif
