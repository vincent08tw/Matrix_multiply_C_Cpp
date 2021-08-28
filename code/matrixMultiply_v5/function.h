/****************************
[file name]--------------
function.h
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

#ifndef FUNCTION_H
#define FUNCTION_H


void multiplication_size_detection(int matrix_a_col, int matrix_b_row)
{
	if(matrix_a_col != matrix_b_row)
	{
		printf("\n\n\n multiplication_size_error!!");
		exit(1);
	}

}
#endif
