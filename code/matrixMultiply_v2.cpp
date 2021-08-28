/****************************
[file name]--------------
matrixMultiply_v2.cpp
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
****************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>  
using namespace std;  
int main()  
{  
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
    cout<<"multiply of the matrix=\n";    
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
    //for printing result    
    for(i=0;i<r;i++)    
    {    
        for(j=0;j<c;j++)    
        {    
            cout<<mul[i][j]<<" ";    
        }    
        cout<<"\n";    
    }    
    return 0;  
}
