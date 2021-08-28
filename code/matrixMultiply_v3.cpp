/****************************
[file name]--------------
matrixMultiply_v3.cpp
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
****************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>  
using namespace std;  
int main()  
{  
	//printf("¢z¢{¢x¢y¢|¢}    _\n");
	printf("¢z    ¢{\n");
	printf("¢x    ¢x\n");
	printf("¢|    ¢}\n");
	printf("hello, world!\n");
    int r,c,i,j,k;    
    cout<<"enter the number of row=";    
    cin>>r;    
    cout<<"enter the number of column=";    
    cin>>c;    
    int a[r][c],b[r][c],mul[r][c];
    cout<<"enter the first matrix element=\n";    
    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {    
            cin>>a[i][j];  
        }    
    }    
    cout<<"enter the second matrix element=\n";    
    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {    
            cin>>b[i][j];    
        }    
    }    
    cout<<"computing...\n";    
    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {    
            mul[i][j]=0;    
            for(k=0;k<c;k++)    
            {    
                mul[i][j]+=a[i][k]*b[k][j];    
            }    
        }    
    }    
    //for printing matrix a  
	cout<<"matrix A:\n";   
	printf("¢z");
	for(i = 0;i < c;i++)
	{
		printf("%5c",' ');
	}
	printf("¢{\n");
    for(i=0;i<r;i++)    
    {    
    	printf("¢x");
        for(j=0;j<c;j++)    
        {   
        	printf("%5d",a[i][j]);
        }    
        printf("¢x");
        cout<<"\n";    
    }  
	printf("¢|");
	for(i = 0;i < c;i++)
	{
		printf("%5c",' ');
	}
	printf("¢}\n");
    //for printing matrix b    
    cout<<"matrix B:\n"; 
    printf("¢z");
	for(i = 0;i < c;i++)
	{
		printf("%5c",' ');
	}
	printf("¢{\n");
    for(i=0;i<r;i++)    
    {    
    	printf("¢x");
        for(j=0;j<c;j++)    
        {   
        	printf("%5d",b[i][j]);
        }    
        printf("¢x");
        cout<<"\n";    
    }  
	printf("¢|");
	for(i = 0;i < c;i++)
	{
		printf("%5c",' ');
	}
	printf("¢}\n");
    //for printing result   
	cout<<"output matrix AB=\n"; 
	printf("¢z");
	for(i = 0;i < c;i++)
	{
		printf("%5c",' ');
	}
	printf("¢{\n");
    for(i=0;i<r;i++)    
    {    
    	printf("¢x");
        for(j=0;j<c;j++)    
        {   
        	printf("%5d",mul[i][j]);
            //cout<<mul[i][j]<<" "; 
        }    
        printf("¢x");
        cout<<"\n";    
    }  
	printf("¢|");
	for(i = 0;i < c;i++)
	{
		printf("%5c",' ');
	}
	printf("¢}\n"); 
    return 0;  
}
