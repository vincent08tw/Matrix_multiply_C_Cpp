/****************************
[file name]--------------
define.h
[project name]----------
matrixMultiply_v9
[despription]------
matrix multiply
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-08-31 
[last modify]----
2021-08-31 
[additional explain]----
v6 : add DEBUG_MODE
v8 : add idcount
	 add SIZE_IN_AUTO
	 add MATRIX_IN_AUTO
v9 : add CREAT_RANDOM_MATRIX
****************************/ 
#ifndef DEFINE_H
#define DEFINE_H

#define DEBUG_MODE 1			// 1: print out more detail; 0: just print out important information; 
#define SIZE_IN_AUTO 1			// 1: decide size of input matrix automatically; 0: decide by user
#define MATRIX_IN_AUTO 1		// 1: decide content of matrix from .txt file; 0: decide by user
#define CREAT_RANDOM_MATRIX 1   // 1: creat random value matrix; 0: use original txt or by hand

#if DEBUG_MODE == 1
int idcount = 0; //global variable for recording matrix ID from 0
#endif

#endif



