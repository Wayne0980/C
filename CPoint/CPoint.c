#include <stdio.h>
int* allocateArrary(int size,int value);
void allocateArrary2(int **arr,int size,int value);
typedef int (*fptrOperation)(int,int);
int add(int num1,int num2);
int red(int num1,int num2);
int compute(fptrOperation foperation,int num1,int num2);
int evaluate(char opcode,int num1,int num2);
int main (void)
{
	int size = 10;
	int value = 55;
	int i = 0;
	int *pvtest = (int*)malloc(5*sizeof(int));
	

	/*2015 11/13 interview */
	int a[8] = {1,2,4,8,16,32,64,128};
	int *p=a;
	int *q=a;
	int *t=a;
	printf("2015.11.13 interview test:\r\n");
	for(i=0;i<5;i++)
		printf("print *(p++)  = %d\r\n",*(p++));

	for(i=0;i<5;i++)
		printf("print *(++p) = %d\r\n",*(q++));

	*(t++) += 123;
	for(i=0;i<5;i++)
		printf("print *t=%d\r\n",t[i]);
	*(++t) += 234;

	for(i = 0;i<5;i++)
		printf("print *t=%d\r\n",t[i]);

	printf("\r\n");
	printf("This is wayne`s cpoint test\r\n");
	printf("****************************\r\n");
	for(i=0;i<5;i++)
		*(pvtest+i) = i;
	printf("print int *pvtest ; pvtest[i] = i *(pvtest+i)\r\n");
	for(i=0;i<5;i++)
		printf(" %d",pvtest[i]);
	printf("\r\n");
	printf("Initial Arrary and give value:\r\n");
	int* arr = allocateArrary(size,value);
	printf("arr = \r\n");
	
	for(i=0;i<size;i++)
	{
		printf(" %d,",arr[i]);
	}	
	printf("\r\n");

	printf("Initial Arrary and give value 2 :\r\n");
	allocateArrary2(&arr,size/2,value-10);
	printf("arr = \r\n");
	for(i=0;i<size;i++)
	{
		printf(" %d,",arr[i]);
	}
	printf("\r\n");
	printf("Using compute(add(5,6))%d\r\n",compute(add,5,6));
	printf("Using compute(red(7,2))%d\r\n",compute(red,7,2));

	printf("evaluate('+',5,6) = %d\r\n",evaluate('+',5,6));
	printf("evaluate('-',7,2) = %d\r\n",evaluate('-',7,2));
	free(arr);

	return 0;
}


/***************************************************
*     to declare variable arrary and given value   *
***************************************************/
int* allocateArrary(int size,int value)
{
	int* arr = (int*)malloc(size * sizeof(int));
	int i = 0;
	for(i=0;i<size;i++)
	{
		arr[i] = value;
	}
	return arr;
}


/****************************************************
*   using int **arr
****************************************************/

void allocateArrary2(int **arr,int size,int value)
{
	*arr = (int*)malloc(size * sizeof(int));
	int i = 0;
	for(i=0;i<size;i++)
	{
		*(*arr+i) = value;
	}	
}


int add (int num1,int num2)
{
	return num1+num2;
}
int red (int num1,int num2)
{
	if(num1>num2)
		return num1-num2;
	return 0;
}

int compute(fptrOperation foperation,int num1,int num2)
{
	return foperation(num1,num2);
	
}


fptrOperation select(char opcode)
{
	switch(opcode){
	case '+':
		return add;
	case '-':
		return red;
	}
	return 0;

}

int evaluate(char opcode,int num1,int num2)
{
	fptrOperation foperation = select(opcode);
	return  foperation(num1,num2);

}
