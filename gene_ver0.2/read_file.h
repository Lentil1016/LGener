#pragma once
#include <fstream>
#include<iostream>
using namespace std;

class read_file
{
public:
	read_file();
	~read_file();
	void openit(string s);//���ļ�
	void one_seq(unsigned char*);//����һ��RNAͷ����������
	void closeit();//�ر��ļ�
private:
	ifstream f1;//�����ļ���
};

