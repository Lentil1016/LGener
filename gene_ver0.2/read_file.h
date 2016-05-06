#pragma once
#include <fstream>
#include<iostream>
using namespace std;

class read_file
{
public:
	read_file();
	~read_file();
	void openit(string s);//打开文件
	void one_seq(unsigned char*);//输入一个RNA头，读入序列
	void closeit();//关闭文件
private:
	ifstream f1;//创建文件类
};

