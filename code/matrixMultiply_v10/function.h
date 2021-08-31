/****************************
[file name]--------------
function.h
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
v8: add inner_product_size_detection
		idcount_increase
		print_define_setting
v10:add inner_product(Matrix_class A, Matrix_class B)
****************************/

#ifndef FUNCTION_H
#define FUNCTION_H

#include "define.h"
using namespace std;

void print_define_setting(bool ToF)
{
	if(ToF) //true for print the setting in "define.h"
	{
		cout << "*************MODE*************\n"; // 13+4+13 =30
		#if DEBUG_MODE == 1
		printf("%-23s%7s\n","DEBUG_MODE","ON");
		#else
		printf("%-23s%7s\n","DEBUG_MODE","OFF");
		#endif
		
		#if SIZE_IN_AUTO == 1
		printf("%-23s%7s\n","SIZE_IN_AUTO","ON");
		#else
		printf("%-23s%7s\n","SIZE_IN_AUTO","OFF");
		#endif
		
		#if MATRIX_IN_AUTO == 1
		printf("%-23s%7s\n","MATRIX_IN_AUTO","ON");
		#else
		printf("%-23s%7s\n","MATRIX_IN_AUTO","OFF");
		#endif
		
		#if CREAT_RANDOM_MATRIX == 1
		printf("%-23s%7s\n","CREAT_RANDOM_MATRIX","ON");
		#else
		printf("%-23s%7s\n","CREAT_RANDOM_MATRIX","OFF");
		#endif
		
		cout << "******************************\n\n\n\n";
	}
}
void multiplication_size_detection(int matrix_a_col, int matrix_b_row)
{
	if(matrix_a_col != matrix_b_row) // number of column of A and number of row of B aren't match
	{
		printf("\n\n\n  %d != %d multiplication_size_error!!", matrix_a_col, matrix_b_row);
		exit(1);
	}
}
void inner_product_size_detection(int matrix_a_row, int matrix_a_col, int matrix_b_row, int matrix_b_col)
{
	if(matrix_a_row != matrix_b_row) // number of row isn't match
	{
		printf("\n\n\n inner_product_size_error!!");
		exit(1);
	}
	if(matrix_a_col != matrix_b_col) // number of column isn't match
	{
		printf("\n\n\n inner_product_size_error!!");
		exit(1);
	}
}
#if DEBUG_MODE == 1
void idcount_increase()
{
	idcount++;	
}		
#endif

#endif
