#pragma once
#include <stdio.h>
#include<iostream>
#include"marker.h"
#include"index.h"
using namespace std;


class rff
{
public:
	rff();
	~rff();
	void extract(string);//���ļ�
	void indexing(unsigned char*,int,index*,int);//����һ��RNAͷ����������
private:
	FILE* f1;//�����ļ���
	char* buf;
	int m, n;
	unsigned int*temp;
};

