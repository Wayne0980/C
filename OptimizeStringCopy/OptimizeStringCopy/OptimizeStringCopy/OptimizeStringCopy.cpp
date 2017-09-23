// OptimizeStringCopy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;
ULONG	Start;
ULONG	End;
#define REMOVE_STR		"This is the world we want copy"
#define COUNTER			1000000

void remove_ctrl_Optimize_6(char* destp,char const* srcp,size_t size)
{
	for(size_t i=0;i<size;++i)
	{
		if(srcp[i]>=0x20)
		{
			*destp++=srcp[i];
		}
	}
	*destp = 0;
}

void remove_ctrl_Optimize_5(std::string result,std::string const& s)
{
	result.clear();
	result.reserve(s.length());
	for(auto it=s.begin(),end=s.end();it!=end;++it)
	{
		if(*it>=0x20)
		{
			result +=*it;
		}
	}
}

std::string remove_ctrl_Optimize_4(std::string const& s)
{
	std::string result;
	result.reserve(s.length());
	for(auto it=s.begin(),end=s.end();it!=end;++it)
	{
		if(*it>=0x20)
		{
			result +=*it;
		}
	}
	return result;
}

std::string remove_ctrl_Optimize_3(std::string const& s)
{
	std::string result;
	result.reserve(s.length());
	for(int i=0;i<s.length();++i)
	{
		if(s[i]>=0x20)
		{
			result +=s[i];
		}
	}
	return result;
}

std::string remove_ctrl_Optimize_2(std::string s)
{
	std::string result;
	result.reserve(s.length());
	for(int i=0;i<s.length();++i)
	{
		if(s[i]>=0x20)
		{
			result +=s[i];
		}
	}
	return result;
}


std::string remove_ctrl_Optimize_1(std::string s)
{
	std::string result;
	for(int i=0;i<s.length();++i)
	{
		if(s[i]>=0x20)
		{
			result +=s[i];
		}
	}
	return result;
}

std::string remove_ctrl(std::string s)
{
	std::string result;
	for(int i=0;i<s.length();++i)
	{
		if(s[i]>=0x20)
		{
			result = result+s[i];
		}
	}
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
	char temp[100];
	Start = GetTickCount();// direct time 3.8ns with 15us tolerance	
	for(int i=0;i<COUNTER;i++)
		remove_ctrl(REMOVE_STR);
	End = GetTickCount();
	printf("remove_ctrl execute time:%d ms(%d times)\r\n",End-Start,COUNTER);

	Start = GetTickCount();// direct time 3.8ns with 15us tolerance	
	for(int i=0;i<COUNTER;i++)
		remove_ctrl_Optimize_1(REMOVE_STR);
	End = GetTickCount();

	printf("remove_ctrl_Optimize_1 execute time:%d ms(%d times)\r\n",End-Start,COUNTER);

	Start = GetTickCount();// direct time 3.8ns with 15us tolerance	
	for(int i=0;i<COUNTER;i++)
		remove_ctrl_Optimize_2(REMOVE_STR);
	End = GetTickCount();
	printf("remove_ctrl_Optimize_2 execute time:%d ms(%d times)\r\n",End-Start,COUNTER);

	Start = GetTickCount();// direct time 3.8ns with 15us tolerance	
	for(int i=0;i<COUNTER;i++)
		remove_ctrl_Optimize_3(REMOVE_STR);
	End = GetTickCount();
	printf("remove_ctrl_Optimize_3 execute time:%d ms(%d times)\r\n",End-Start,COUNTER);

	Start = GetTickCount();// direct time 3.8ns with 15us tolerance	
	for(int i=0;i<COUNTER;i++)
		remove_ctrl_Optimize_4(REMOVE_STR);
	End = GetTickCount();
	printf("remove_ctrl_Optimize_4 execute time:%d ms(%d times)\r\n",End-Start,COUNTER);

	Start = GetTickCount();// direct time 3.8ns with 15us tolerance	
	for(int i=0;i<COUNTER;i++)
		remove_ctrl_Optimize_5(temp,REMOVE_STR);
	End = GetTickCount();
	printf("remove_ctrl_Optimize_5 execute time:%d ms(%d times)\r\n",End-Start,COUNTER);

	Start = GetTickCount();// direct time 3.8ns with 15us tolerance	
	for(int i=0;i<COUNTER;i++)
		remove_ctrl_Optimize_6(temp,REMOVE_STR,sizeof(REMOVE_STR));
	End = GetTickCount();
	printf("remove_ctrl_Optimize_6 execute time:%d ms(%d times)\r\n",End-Start,COUNTER);

	system("pause");
	return 0;
}

