#include "index.h"
#include<iostream>
using namespace std;


index::index()
{
}


index::~index()
{
}

void index::initial(int k1)//done 创建seek和nail两指针数组
{
	m = k1;
	seek = new marker*[k1];
	nail = new marker*[k1];
	for (int i = 0; i < k1; i++)//索引字典初始化,所有指针空置
	{
		seek[i]=nail[i] = 0;
		//cout << "initial检测19日错误>" << nail[i] << ",i=" << i << endl;//检测19日错误
	}
}

void index::release()//done 释放链表
{
	marker* p,*q;
	//cout << seek[6] << endl;
	for (int i =0; i < m; i++)//遍历指针数组
	{
		if (seek[i] != 0)
		{
			p = seek[i];
			if (i % 1000 == 0)
				//cout << i / 1000;
			while (p != 0)//逐个释放marker元素删除链表
			{
				q = p->next();
				//cout << q<<","<<i<<endl;//release测试用
				delete p;
				p = q;
			}
		}
	}
	//====循环删除书签======/
}

void index::setup(unsigned int n, int rank, int pos)//建立书签单链表结构，nail应该在建立完成后被释放
{
	marker**head, **q;//为优化索引效率设置临时指针
	head = &seek[n];
	q = &nail[n];
	//cout <<"index问题检测>"<< n<<endl;//测试19日问题用
	//cout << "index问题检测>" << (*q) << endl;//测试19日问题用
	if (nail[n] == 0)
	{
		*q = new marker;//插入链表的第一个marker，并使seek和nail都指向该marker
		*head =*q;
	}
	else
	{
		*q=(*q)->next(new marker);//当前指向新marker并移动尾指针至新marker
	}
	(*q)->next(0);//链表封尾
	(*q)->mark(rank, pos);
	//cin.get();
	//cout <<"index测试>n="<<n<< "，rank="<<rank <<"，pos=" <<pos << endl;
}

void index::release_nail()
{
	delete [] nail;//释放尾指针数组
}

int index::match(unsigned int a)
{
	//cout << a;//测试用
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