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
	void extract(string);//打开文件
	void indexing(unsigned char*,int,index*,int);//输入一个RNA头，读入序列
private:
	FILE* f1;//创建文件类
	char* buf;
	int m, n;
	unsigned int*temp;
};

