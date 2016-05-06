#include "short_seq.h"
#include<iostream>//读写测试用
using namespace std;//测试用


short_seq::short_seq()
{
}


short_seq::~short_seq()
{
}

unsigned char short_seq::diction(char* byte)
{
	unsigned char c=0;
	//cout << "ss>sizeof byte is" << sizeof(byte) << endl;//测试指针传递完整性
	for (int i =  0; i < 4; i++)
		if (byte[i] == 'T')
			c += 1 << i * 2;
		else
			if (byte[i] == 'G')
				c += 2 << i * 2;
			else
				if (byte[i] == 'C')
					c += 3 << i * 2;
	return c;
}

unsigned int short_seq::diction(char* byte, int k)
{
	unsigned int c = 0;
	for (int i = 0; i < k; i++)
	{
		c = c << 2;
		if (*(byte + i) == 'T')
			c += 1;
		else
			if (*(byte + i) == 'G')
				c += 2;
			else
				if (*(byte + i) == 'C')
					c += 3;
	}
	//cout << "索引压缩测试>" << c << endl;//用于测试输出数值
	//cout << "索引压缩测试>" << k << endl;//用于测试输入字符串地址
	//cin.get();//用于打断输出
	return c;
}

unsigned int short_seq::next(char*mark, int k, unsigned int *c)
{
	//cout << "索引压缩测试>" << temp<< endl;//用于测试输出数值
	*c=((*c) << 2) & ((1 << (k * 2)) - 1);
	if (*(mark) == 'T')
		*c += 1;
	else
		if (*(mark) == 'G')
			*c += 2;
		else
			if (*(mark) == 'C')
				*c += 3;
	//cout << "索引压缩测试>" << *c << endl;//用于测试输出数值
	//cin.get();
	return *c;
}


