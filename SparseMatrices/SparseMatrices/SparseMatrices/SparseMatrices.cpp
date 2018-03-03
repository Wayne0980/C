// SparseMatrices.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#define MAX_TERMS	10
struct Term{
	int row;
	int col;
	int value;
};
struct sMatrix{

	int rows;
	int cols;
	int numofTerms;
	struct Term arr[MAX_TERMS];
};

typedef struct sMatrix Matrix;
Matrix m;
void createMatrix(int r, int c, int *arr);
void printMatrix();

void createMatrix(int r, int c, int *arr)
{
	int i,j,count;
	m.rows = r;
	m.cols = c;
	count = 0;

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(arr[i*c+j] != 0)
			{
				m.arr[count].row = i;
				m.arr[count].col = j;
				m.arr[count].value = arr[i*c+j];
				count++;
			}
		}
	}
	m.numofTerms = count;

}
void printMatrix()
{
	int i;
	printf("size:%d X %d\t",m.rows,m.cols);
	printf("items:%d \r\n",m.numofTerms);
	printf("row \t col\t value\n");

	for(i=0;i<m.numofTerms;i++)
	{
		printf("%d\t%d\t",m.arr[i].row,m.arr[i].col);
		printf("%d\n",m.arr[i].value);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{

	int sparse[5][10] = {
		0,0,0,0,1,0,1,2,3,5,
		0,5,9,0,0,4,0,5,6,8,
		1,8,0,9,0,0,0,4,0,8,
		9,5,0,5,5,0,5,5,7,7,
		0,2,9,0,0,8,0,8,0,7
	};
	int *fp = &sparse[0][0];
	createMatrix(5,10,fp);
	printMatrix();
	system("pause");
	return 0;
}

