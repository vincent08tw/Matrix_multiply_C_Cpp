/****************************
[file name]--------------
matrixMultiply_v4.cpp
[project name]----------

[despription]------
matrix multiply
[create date]---
2021-08-27
[last modify]----
2021-08-27
[additional explain]----
v1 : original and 10*10 max size  
v2 : flexible array size (compare to v1)
v3 : better visible effect print out
v4 : can do non-square matrix multiply 
****************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>  
using namespace std;  
int main()  
{  
//	printf("¢z¢{¢x¢y¢|¢}    _\n");
//	printf("¢z    ¢{\n");
//	printf("¢x    ¢x\n");
//	printf("¢|    ¢}\n");
//	printf("hello, world!\n");
    int row_a, col_a; // # of row of matrix A, # of column of matrix A,
    int row_b, col_b; // # of row of matrix B, # of column of matrix B,
    int row_o, col_o; // # of row of matrix output, # of column of matrix output,
	int i,j,k; //temp variable for loop
    cout<<"enter the number of row of A =";    
    cin>>row_a;    
    cout<<"enter the number of column of A=";    
    cin>>col_a;
	cout<<"enter the number of row of B =";    
    cin>>row_b;
    cout<<"enter the number of column of B=";    
    cin>>col_b;
    if(col_a != row_b) // detect matrix size 
	{
		printf("matrix size error!!");
		exit(1);	
	}
	// A: 3*5 B:5*2 O:3*2
    row_o = row_a;
    col_o = col_b;
    //matrix size allocation
    int a[row_a][col_a],b[row_b][col_b],mul[row_o][col_o];
    
    cout<<"enter the first matrix element=\n";    
    for(i = 0;i < row_a;i++)    
    {    
        for(j = 0;j < col_a;j++)    
        {    
            cin>>a[i][j];  
        }    
    }    
    cout<<"enter the second matrix element=\n";    
    for(i = 0;i < row_b;i++)    
    {    
        for(j = 0;j < col_b;j++)    
        {    
            cin>>b[i][j];    
        }    
    }    
    cout<<"computing...\n";    
    for(i = 0;i < row_a;i++)    
    {    
        for(j = 0;j < col_b;j++)    
        {    
            mul[i][j]=0;    
            for(k = 0;k < col_a;k++)    
            {    
                mul[i][j]+=a[i][k]*b[k][j];    
            }    
        }    
    }    
    //for printing matrix a  
	cout<<"matrix A:\n";   
	printf("¢z");
	for(i = 0;i < col_a;i++)
	{
		printf("%5c",' ');
	}
	printf("¢{\n");
    for(i = 0;i < row_a;i++)    
    {    
    	printf("¢x");
        for(j = 0;j < col_a;j++)    
        {   
        	printf("%5d",a[i][j]);
        }    
        printf("¢x");
        cout<<"\n";    
    }  
	printf("¢|");
	for(i = 0;i < col_a;i++)
	{
		printf("%5c",' ');
	}
	printf("¢}\n");
    //for printing matrix b    
    cout<<"matrix B:\n"; 
    printf("¢z");
	for(i = 0;i < col_b;i++)
	{
		printf("%5c",' ');
	}
	printf("¢{\n");
    for(i = 0;i < row_b;i++)    
    {    
    	printf("¢x");
        for(j = 0;j < col_b;j++)    
        {   
        	printf("%5d",b[i][j]);
        }    
        printf("¢x");
        cout<<"\n";    
    }  
	printf("¢|");
	for(i = 0;i < col_b;i++)
	{
		printf("%5c",' ');
	}
	printf("¢}\n");
    //for printing result   
	cout<<"output matrix AB=\n"; 
	printf("¢z");
	for(i = 0;i < col_o;i++)
	{
		printf("%5c",' ');
	}
	printf("¢{\n");
    for(i = 0;i < row_o;i++)    
    {    
    	printf("¢x");
        for(j=0;j<col_o;j++)    
        {   
        	printf("%5d",mul[i][j]);
            //cout<<mul[i][j]<<" "; 
        }    
        printf("¢x");
        cout<<"\n";    
    }  
	printf("¢|");
	for(i = 0;i < col_o;i++)
	{
		printf("%5c",' ');
	}
	printf("¢}\n"); 
    return 0;  
}
