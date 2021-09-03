/****************************
[file name]--------------
class3D.h
[project name]----------
matrixMultiply_v12
[despription]------
matrix multiply
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-09-01 
[last modify]----
2021-09-01 
[additional explain]----

****************************/

#ifndef CLASS3D_H
#define CLASS3D_H
#endif

#ifndef CLASS_H
#include "class.h"
#endif

#ifndef INCLUDE_H
#include "include.h"
#endif

#ifndef DEFINE_H
#include "define.h"
#endif

#ifndef FUNCTION_H
#include "function.h"
#endif

using namespace std;

class Matrix_3D_class
{
	private:
		// Private section
		int numberOfChannel; // number of channel of matrix
		int numberOfRow, numberOfColumn; // number of row and column of matrix
	public:
		// Public Declarations
		
		int ID; // ID for class
		Matrix_3D_class() //constroctor
		{
			#if DEBUG_MODE == 1
			ID = idcount;
			cout << "Matrix_3D_class ID: " << ID << " is created \n";
			idcount_increase(); //idcount++
			#endif
			//initialize matrix size and space
			this->numberOfChannel = 0;
			this->numberOfRow = 0;
			this->numberOfColumn = 0;
			this->matrix_allocation();
			
		}
		
		//content of matrix
		int*** matrix_content; 
		//creat random integer number matrix and give row column directly
		void creat_random_int_matrix(string filename, int channel, int row, int col, int min, int max);
		//creat random integer number matrix 
		void creat_random_int_matrix(string filename, int min, int max);
		//allocate space of matrix depend on numberOfRow and numberOfColumn
		void matrix_allocation();
		//set content of matrix from txt file
		void set_content_from_txt(string filename);
		//save matrix to txt file
		void write_content_to_txt(string filename);
		//print content of matrix
		void print_content();
		//set number of channel of matrix by hand
		void set_numberOfChannel();
		//set number of channel of matrix by input argument of function call
		void set_numberOfChannel(int number_int);
		//set number of row of matrix by hand
		void set_numberOfRow();
		//set number of row of matrix by input argument of function call
		void set_numberOfRow(int number_int);
		//set number of row and column of matrix by input argument of function call
		void set_matrix_size_3D(int channel, int row, int col);
		//set number of column of matrix by hand
		void set_numberOfColumn();
		//set number of column of matrix by input argument of function call
		void set_numberOfColumn(int number_int);
		//return number of row of matrix
		int get_numberOfRow();
		//return number of column of matrix
		int get_numberOfColumn();
		//return number of channel of matrix
		int get_numberOfChannel();
		
		void matrix_convolution(Matrix_3D_class, Matrix_3D_class);
		int inner_product(Matrix_3D_class, Matrix_3D_class);
		
		#if DEBUG_MODE == 1
		~Matrix_3D_class() //deconstroctor
		{
			cout << "delete Matrix_class ID: " << ID << "\n";
		}
		#endif
		
	protected:
		// Protected Declarations
};

void Matrix_3D_class::matrix_convolution(Matrix_3D_class input, Matrix_3D_class kernel)
{
	int i, j, k, a, b, c; // for loop
	
	int CNL_input = input.get_numberOfChannel();
	int ROW_input = input.get_numberOfRow();
	int ROW_kernel = kernel.get_numberOfRow();
	int CNL_kernel = kernel.get_numberOfChannel();
	int COL_input = input.get_numberOfColumn();
	int COL_kernel = kernel.get_numberOfColumn();
	
	int col_bias = 0;
	int row_bias = 0;
	//input and kernel need be square matrix and input size must bigger than kernel
	convolution_size_detection(CNL_input ,ROW_input, COL_input, CNL_kernel, ROW_kernel, COL_kernel); 
	
	//compute output matrix size
	int output_matrix_channel_size = 1;
	int output_matrix_size = ROW_input - ROW_kernel + 1;
	
	this->set_matrix_size_3D(output_matrix_channel_size, output_matrix_size, output_matrix_size);
	
	Matrix_3D_class input_slice;
	input_slice.set_matrix_size_3D(CNL_kernel, ROW_kernel, COL_kernel);
	for(c = 0; c < output_matrix_channel_size;c++)
	{
		row_bias = 0;
		for(a = 0; a < output_matrix_size;a++)
		{
			col_bias = 0;
			for(b = 0;b < output_matrix_size;b++)
			{
				for(k = 0;k < CNL_kernel;k++)
				{
					for(i = 0;i < ROW_kernel;i++)
					{
						for(j = 0;j < COL_kernel;j++)
						{
							input_slice.matrix_content[k][i][j] = input.matrix_content[k][i+row_bias][j+col_bias];
						}
					}	
				}
				
				this->matrix_content[c][a][b] = inner_product(input_slice, kernel);
				col_bias++;
			}
			row_bias++;
		}
	}
	
}
int Matrix_3D_class::inner_product(Matrix_3D_class A, Matrix_3D_class B)
{
	size_t k;
	size_t i;
	size_t j;
	int temp = 0;
	
	int cnl_A = A.get_numberOfChannel();
	int row_A = A.get_numberOfRow();
	int col_A = A.get_numberOfColumn();
	int cnl_B = B.get_numberOfChannel();
	int col_B = B.get_numberOfColumn();
	int row_B = B.get_numberOfRow();
	
	
	/* detect matrix size*/
	inner_product_size_detection(cnl_A,row_A, col_A, cnl_B, row_B, col_B);
	for(k = 0;k < cnl_A;k++)
	{
		for(i = 0;i < row_A;i++)
		{
			for(j = 0;j < col_A;j++)
			{
				temp += A.matrix_content[k][i][j] * B.matrix_content[k][i][j];
			}
		}	
	}
	
	return temp;
}
void Matrix_3D_class::print_content()
{
	size_t channel;
	size_t row;
	size_t column;
	#if DEBUG_MODE == 1
	printf("\nchannel = %d, row = %d, column = %d\n",this->numberOfChannel,this->numberOfRow,this->numberOfColumn);
	#endif
	for(channel = 0;channel < this->numberOfChannel;channel++)
	{
		printf("channel %d: \n",channel+1);
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
	        	printf("%5d",this->matrix_content[channel][row][column]);
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
}
void Matrix_3D_class::write_content_to_txt(string filename)
{
	size_t channel;
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
		for(channel = 0;channel < this->numberOfChannel;channel++)
		{
			for(row = 0;row < this->numberOfRow;row++)    
		    {   
		        for(column = 0;column < this->numberOfColumn;column++)    
		        {   
		        	fout.flags(ios::right|ios::fixed);
		        	fout.fill(' ');
		        	fout.width(5);
		        	fout << this->matrix_content[channel][row][column] << ' ';
		        }
				fout << "\n";  
		    }
		    fout << "\n";
		}
		
		fout.close();   // close file  
		#if DEBUG_MODE == 1
		cout << "write finish !! \n\n" << endl;
		#endif
	}
}
void Matrix_3D_class::set_content_from_txt(string filename)
{
	size_t channel;
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
		for(channel = 0;channel < this->numberOfChannel;channel++)
		{
			for(row = 0;row < this->numberOfRow;row++)    
		    {    
		        for(column = 0;column < this->numberOfColumn;column++)    
		        {   
		        	fin >> element;
		            this->matrix_content[channel][row][column] = element;  
		        }    
		    }
		}
		fin.close();   // close file 
	}
	   
}
void Matrix_3D_class::set_numberOfChannel(int number_int)
{
	this->numberOfChannel = number_int;
}
void Matrix_3D_class::set_numberOfChannel()
{
	cin >> this->numberOfChannel;
}
void Matrix_3D_class::set_numberOfRow(int number_int)
{
	this->numberOfRow = number_int;
}
void Matrix_3D_class::set_numberOfRow()
{
	cin >> this->numberOfRow;
}
void Matrix_3D_class::set_numberOfColumn()
{
	cin >> this->numberOfColumn;
}
void Matrix_3D_class::set_numberOfColumn(int number_int)
{
	this->numberOfColumn = number_int;
}
int Matrix_3D_class::get_numberOfRow()
{
	return this->numberOfRow;
}
int Matrix_3D_class::get_numberOfColumn()
{
	return this->numberOfColumn;
}
int Matrix_3D_class::get_numberOfChannel()
{
	return this->numberOfChannel;
}
void Matrix_3D_class::set_matrix_size_3D(int channel, int row, int col)
{
	this->numberOfChannel = channel;
	this->numberOfRow = row;
	this->numberOfColumn = col;
	
	this->matrix_allocation();
}
void Matrix_3D_class::creat_random_int_matrix(string filename, int min, int max)
{
	int i,j,k;
	
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
		for(k = 0;k < this->get_numberOfChannel();k++)
		{
			for(i = 0;i < this->get_numberOfRow();i++)    
		    {   
		        for(j = 0;j < this->get_numberOfColumn();j++)    
		        {   
		        	fout.flags(ios::right|ios::fixed);
		        	fout.fill(' ');
		        	fout.width(5);
					this->matrix_content[k][i][j] = rand() % (max - min + 1) + min;
		        	fout << this->matrix_content[k][i][j] << ' ';
		        }
				fout << "\n";  
		    }	
		    fout << "\n"; 
		}
		  
		fout.close();   // close file  
		#if DEBUG_MODE == 1
		cout << "write finish !! \n\n" << endl;
		#endif
	}
}
void Matrix_3D_class::creat_random_int_matrix(string filename, int channel, int row, int col, int min, int max)
{
	int i,j,k;
	
	this->numberOfChannel = channel;
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
		for(k = 0;k < channel;k++)
		{
			for(i = 0;i < row;i++)    
		    {   
		        for(j = 0;j < col;j++)    
		        {   
					this->matrix_content[k][i][j] = rand() % (max - min + 1) + min;
					
		        	fout << this->matrix_content[k][i][j] << ' ';
		        }
				fout << "\n";  
		    }
		    fout << "\n";
		}
		
		fout.close();   // close file  
		#if DEBUG_MODE == 1
		cout << "write finish !! \n\n" << endl;
		#endif
	}
}
void Matrix_3D_class::matrix_allocation()
{
	size_t channel;
	size_t row;
	size_t column;
	this->matrix_content = new int** [this->numberOfChannel];
	for(channel = 0;channel < this->numberOfChannel;channel++)
	{
		this->matrix_content[channel] = new int* [this->numberOfRow];
		for(row = 0;row < this->numberOfRow;row++)
		{
			this->matrix_content[channel][row] = new int[this->numberOfColumn];
		}
	}
	
	#if DEBUG_MODE == 1
	cout << "Matrix ID : " << ID << " space allocation complete! \n";
	#endif
}
