#include "index.h"
#include<iostream>
using namespace std;


index::index()
{
}


index::~index()
{
}

void index::initial(int k1)//done ����seek��nail��ָ������
{
	m = k1;
	seek = new marker*[k1];
	nail = new marker*[k1];
	for (int i = 0; i < k1; i++)//�����ֵ��ʼ��,����ָ�����
	{
		seek[i]=nail[i] = 0;
		//cout << "initial���19�մ���>" << nail[i] << ",i=" << i << endl;//���19�մ���
	}
}

void index::release()//done �ͷ�����
{
	marker* p,*q;
	//cout << seek[6] << endl;
	for (int i =0; i < m; i++)//����ָ������
	{
		if (seek[i] != 0)
		{
			p = seek[i];
			if (i % 1000 == 0)
				//cout << i / 1000;
			while (p != 0)//����ͷ�markerԪ��ɾ������
			{
				q = p->next();
				//cout << q<<","<<i<<endl;//release������
				delete p;
				p = q;
			}
		}
	}
	//====ѭ��ɾ����ǩ======/
}

void index::setup(unsigned int n, int rank, int pos)//������ǩ������ṹ��nailӦ���ڽ�����ɺ��ͷ�
{
	marker**head, **q;//Ϊ�Ż�����Ч��������ʱָ��
	head = &seek[n];
	q = &nail[n];
	//cout <<"index������>"<< n<<endl;//����19��������
	//cout << "index������>" << (*q) << endl;//����19��������
	if (nail[n] == 0)
	{
		*q = new marker;//��������ĵ�һ��marker����ʹseek��nail��ָ���marker
		*head =*q;
	}
	else
	{
		*q=(*q)->next(new marker);//��ǰָ����marker���ƶ�βָ������marker
	}
	(*q)->next(0);//�����β
	(*q)->mark(rank, pos);
	//cin.get();
	//cout <<"index����>n="<<n<< "��rank="<<rank <<"��pos=" <<pos << endl;
}

void index::release_nail()
{
	delete [] nail;//�ͷ�βָ������
}

int index::match(unsigned int a)
{
	//cout << a;//������
	int i=0;
	marker*p = seek[a];
	while (p != 0)
	{
		p=p->print();
		i++;
	}
	return i;
}

marker* index::listed(unsigned int state)
{
	return seek[state];
}