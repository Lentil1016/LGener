#include "read_file.h"
#include"short_seq.h"
#include<string>

read_file::read_file()
{
}


read_file::~read_file()
{
}

void read_file::openit(string s)
{
	f1.open(s); //测试完成后改成相对目录
	if (!f1.is_open())//文件打开成功测试
	{
		cout << "文件打开失败" << endl;
		exit(0);
	}
	else
		cout << "开始读取文件"<<s<<"\n[====================]\n[";
}

void read_file::one_seq(unsigned char* rna_head)
{
	short_seq prs;
	std::ios::sync_with_stdio(false);
	//char c=1;//测试用变量，请与测试一起删除
	int i,j;
	//cout << "c=" << c<< endl;//工作状态测试
	char temp[101],s[4];
	f1.getline(temp, 100);//跳过一行
	if (f1.eof())
		cout << "遭遇文件尾" << endl;//读文件结束状态检查。用于调整
	for (i = 0; i < 25; i++)//25字节
	{
		for (j = 0; j < 4; j++)//每字节4位
			f1 >> s[j];
		*(rna_head + i) =prs.diction(s); //完成字典压缩并存入RNA
	}
	f1 >> s[0];//读入序列尾回车，删除测试时请将c改为s.byte[0]
	//cout << "endl c=" << c<< endl;//工作状态测试
}

void read_file::closeit()
{
	f1.close();
	if (!f1.is_open())
		cout << "]\n文件读取完成\n" << endl;//变量生存期检查
}
