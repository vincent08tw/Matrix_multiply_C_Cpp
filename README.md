# Matrix_multiply_C/C++ - vincent08tw

## Environment
OS: windows 10  
IDE: Dev-C++ 5.11  

## Project Description
This project is for me to practice C/C++ language and prepare to model Convolution Neural Network in the future.  
This project is created from 2021/08/27.  

## Version Description
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