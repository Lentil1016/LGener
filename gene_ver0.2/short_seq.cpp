#include "short_seq.h"
#include<iostream>//��д������
using namespace std;//������


short_seq::short_seq()
{
}


short_seq::~short_seq()
{
}

unsigned char short_seq::diction(char* byte)
{
	unsigned char c=0;
	//cout << "ss>sizeof byte is" << sizeof(byte) << endl;//����ָ�봫��������
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
	//cout << "����ѹ������>" << c << endl;//���ڲ��������ֵ
	//cout << "����ѹ������>" << k << endl;//���ڲ��������ַ�����ַ
	//cin.get();//���ڴ�����
	return c;
}

unsigned int short_seq::next(char*mark, int k, unsigned int *c)
{
	//cout << "����ѹ������>" << temp<< endl;//���ڲ��������ֵ
	*c=((*c) << 2) & ((1 << (k * 2)) - 1);
	if (*(mark) == 'T')
		*c += 1;
	else
		if (*(mark) == 'G')
			*c += 2;
		else
			if (*(mark) == 'C')
				*c += 3;
	//cout << "����ѹ������>" << *c << endl;//���ڲ��������ֵ
	//cin.get();
	return *c;
}


