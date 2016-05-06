#include "rff.h"
#include"short_seq.h"
#include<string>


rff::rff() :buf(new char[80000000]),temp (new unsigned int)
{
}


rff::~rff()
{
}

void rff::extract(string s)
{
	errno_t err;
	if ((err=fopen_s(&f1, s.c_str(), "rb"))!=0)//文件打开成功测试
	{
		cout << "没有找到"<<s<<"，请将序列库文件与该EXE文件放置于同一目录下！！！\n请按回车退出该程序" << endl;
		cin.get();
		cin.get();
		exit(0);
	}
	else
		cout << s << "读取完毕\n开始建立索引······"<< "\n[====================]\n[";
	m = fread(buf, 1, 80000000, f1);//提取数据到内存
	buf[m] = '\0';
	n = 0;//maker回到数据头部
	/*//测试用
	int i, j;
	for (i = 0; i < m / 1000; i++)
	{
		for (j = 0; j < 1000; j++)
			cout << buf[n++];
		cin.get();
	}
	//测试用*/
	fclose(f1);
}	

void rff::indexing(unsigned char* rna_head,int k,index* p_ind,int rank)
{
	int i, j;
	char s[4];//存储short_seq;
	short_seq prs;
	//char c=1;//测试用变量，请与测试一起删除
	//cout << "c=" << c<< endl;//工作状态测试
	if (buf[n] == '>')
		//cout << ">checked";//测试18号rff错误用
	while (buf[n] != '\n')
		n ++;//跳过一行
	m = ++n;
	for (i = 0; i < 25; i++)//25字节
	{
		for (j = 0; j < 4; j++)//每字节4位
		{
			//cout << buf[n];//测试18号rff错误用
			s[j] = buf[n++];
		}
		*(rna_head + i) = prs.diction(s); //完成字典压缩并存入RNA
	}
	//此刻m为序列头，n-1为序列尾
	//cout << buf[n]<<endl;//测试位置
	//cin.get();//测试位置
	p_ind->setup(*temp = prs.diction((char*)(buf + m), k), rank, 0);
	//cout << "RFF测试" << *temp<< endl;//工作状态测试
	m = m + k;
	for (i = m; i < n; i++)//将当前序列载入到k_max宽的字典压缩索引，n-1为尾部，m为头部
		p_ind->setup(prs.next((char*)(buf + i), k, temp), rank, i-m+1);//diction输入字符长度和返回序列转义数值，i-m为该序列段在原序列上距离起点的偏移量，即pos
	n++;//读入序列尾回车，删除测试时请将c改为s.byte[0]
	//cout << "endl c=" << c<< endl;//工作状态测试
}
