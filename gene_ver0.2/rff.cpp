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
	if ((err=fopen_s(&f1, s.c_str(), "rb"))!=0)//�ļ��򿪳ɹ�����
	{
		cout << "û���ҵ�"<<s<<"���뽫���п��ļ����EXE�ļ�������ͬһĿ¼�£�����\n�밴�س��˳��ó���" << endl;
		cin.get();
		cin.get();
		exit(0);
	}
	else
		cout << s << "��ȡ���\n��ʼ��������������������"<< "\n[====================]\n[";
	m = fread(buf, 1, 80000000, f1);//��ȡ���ݵ��ڴ�
	buf[m] = '\0';
	n = 0;//maker�ص�����ͷ��
	/*//������
	int i, j;
	for (i = 0; i < m / 1000; i++)
	{
		for (j = 0; j < 1000; j++)
			cout << buf[n++];
		cin.get();
	}
	//������*/
	fclose(f1);
}	

void rff::indexing(unsigned char* rna_head,int k,index* p_ind,int rank)
{
	int i, j;
	char s[4];//�洢short_seq;
	short_seq prs;
	//char c=1;//�����ñ������������һ��ɾ��
	//cout << "c=" << c<< endl;//����״̬����
	if (buf[n] == '>')
		//cout << ">checked";//����18��rff������
	while (buf[n] != '\n')
		n ++;//����һ��
	m = ++n;
	for (i = 0; i < 25; i++)//25�ֽ�
	{
		for (j = 0; j < 4; j++)//ÿ�ֽ�4λ
		{
			//cout << buf[n];//����18��rff������
			s[j] = buf[n++];
		}
		*(rna_head + i) = prs.diction(s); //����ֵ�ѹ��������RNA
	}
	//�˿�mΪ����ͷ��n-1Ϊ����β
	//cout << buf[n]<<endl;//����λ��
	//cin.get();//����λ��
	p_ind->setup(*temp = prs.diction((char*)(buf + m), k), rank, 0);
	//cout << "RFF����" << *temp<< endl;//����״̬����
	m = m + k;
	for (i = m; i < n; i++)//����ǰ�������뵽k_max����ֵ�ѹ��������n-1Ϊβ����mΪͷ��
		p_ind->setup(prs.next((char*)(buf + i), k, temp), rank, i-m+1);//diction�����ַ����Ⱥͷ�������ת����ֵ��i-mΪ�����ж���ԭ�����Ͼ�������ƫ��������pos
	n++;//��������β�س���ɾ������ʱ�뽫c��Ϊs.byte[0]
	//cout << "endl c=" << c<< endl;//����״̬����
}
