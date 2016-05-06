#include "cells.h"
#include "short_seq.h"
#include<iostream>//������
//#include <iomanip>//������
using namespace std;//������


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
		//cout << "s="<<s[j]<<endl;//����29�Ŵ�����
		j++;
		if (j == 4)
		{
			j = 0;
			if (prs.diction(s) != rna[(pos+i) / 4])
				return 0;
		}
	}
	//cout << (int)(prs.diction(s) & ((1 << j * 2) - 1)) << "," << (int)rna[(pos+n2) / 4]<<"," << (int)(rna[(pos+n2) / 4 ] & ((1 << j * 2) - 1)) << endl;//������
	if (j != 0)
		if ((prs.diction(s) & ((1 << j * 2) - 1) )!= (rna[(pos+n2) / 4] & ((1 << j * 2) - 1)))
			return 0;
	//cout << "�����ɹ�" << endl;
	return 1;
}

/*void cells::test()
{
	for (int i = 0; i < 25; i++)//���������
		cout << setw(4) << (short)rna[24-i];//24-iʹ�����г��׵ߵ����ڶ����Ʋ������ԭ���ڹ�ϵ����������ʵ�ʴ洢��ʽ
	cout << endl;//���������
	cin.get();//�����ã�ÿ���������������
}*/
