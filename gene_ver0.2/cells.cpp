#include "cells.h"
#include "short_seq.h"
#include<iostream>//测试用
//#include <iomanip>//测试用
using namespace std;//测试用


cells::cells() 
{
}


cells::~cells()
{
}

unsigned char* cells::take_rna()
{
	return rna;
}


bool cells::match(char* buf,unsigned char n1, unsigned char n2,unsigned char pos)
{
	short_seq prs;
	char s[4];
	int i,j=0;
	for (i = n1; i < n2; i++)
	{
		s[j] = buf[i];
		//cout << "s="<<s[j]<<endl;//测试29号错误用
		j++;
		if (j == 4)
		{
			j = 0;
			if (prs.diction(s) != rna[(pos+i) / 4])
				return 0;
		}
	}
	//cout << (int)(prs.diction(s) & ((1 << j * 2) - 1)) << "," << (int)rna[(pos+n2) / 4]<<"," << (int)(rna[(pos+n2) / 4 ] & ((1 << j * 2) - 1)) << endl;//测试用
	if (j != 0)
		if ((prs.diction(s) & ((1 << j * 2) - 1) )!= (rna[(pos+n2) / 4] & ((1 << j * 2) - 1)))
			return 0;
	//cout << "索引成功" << endl;
	return 1;
}

/*void cells::test()
{
	for (int i = 0; i < 25; i++)//测试用输出
		cout << setw(4) << (short)rna[24-i];//24-i使得序列彻底颠倒，在二进制层面具有原相邻关系，但有异于实际存储方式
	cout << endl;//测试用输出
	cin.get();//测试用，每个序列添加输入打断
}*/
