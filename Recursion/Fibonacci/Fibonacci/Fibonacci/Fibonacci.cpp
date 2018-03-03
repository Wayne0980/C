// Fibonacci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
HANDLE h;
int counter = 0;
int old_n = 0;
int fibonacci_function(int n)
{
	counter++;
	
	if(old_n-1==n||old_n==n)
	{
		//設定新的顏色 
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY ); 
	}
	else
	{
		//設定新的顏色 
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY ); 
	}
	
	old_n = n;
	if(n<2)
	{
		SetConsoleTextAttribute ( h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE  ); 
		printf("execute:%d,n=%d\r\n",counter,n);
		return n;
	}else
	{
		printf("execute:%d,n=%d\r\n",counter,n);
		return (fibonacci_function(n-1)+fibonacci_function(n-2));
	}
}
HANDLE set_color_of_text()
{
	HANDLE h;
	h = GetStdHandle ( STD_OUTPUT_HANDLE ); 
	WORD wOldColorAttrs;  
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;  
	GetConsoleScreenBufferInfo(h, &csbiInfo); 
	wOldColorAttrs = csbiInfo.wAttributes; 
	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY ); 

	return h;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n = 6;
	old_n = n;
 
	
	h = set_color_of_text();
	printf("your number:%d",n,fibonacci_function(n));
	system("pause");
	return 0;
}

