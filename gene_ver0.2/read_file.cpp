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
	f1.open(s); //������ɺ�ĳ����Ŀ¼
	if (!f1.is_open())//�ļ��򿪳ɹ�����
	{
		cout << "�ļ���ʧ��" << endl;
		exit(0);
	}
	else
		cout << "��ʼ��ȡ�ļ�"<<s<<"\n[====================]\n[";
}

void read_file::one_seq(unsigned char* rna_head)
{
	short_seq prs;
	std::ios::sync_with_stdio(false);
	//char c=1;//�����ñ������������һ��ɾ��
	int i,j;
	//cout << "c=" << c<< endl;//����״̬����
	char temp[101],s[4];
	f1.getline(temp, 100);//����һ��
	if (f1.eof())
		cout << "�����ļ�β" << endl;//���ļ�����״̬��顣���ڵ���
	for (i = 0; i < 25; i++)//25�ֽ�
	{
		for (j = 0; j < 4; j++)//ÿ�ֽ�4λ
			f1 >> s[j];
		*(rna_head + i) =prs.diction(s); //����ֵ�ѹ��������RNA
	}
	f1 >> s[0];//��������β�س���ɾ������ʱ�뽫c��Ϊs.byte[0]
	//cout << "endl c=" << c<< endl;//����״̬����
}

void read_file::closeit()
{
	f1.close();
	if (!f1.is_open())
		cout << "]\n�ļ���ȡ���\n" << endl;//���������ڼ��
}
