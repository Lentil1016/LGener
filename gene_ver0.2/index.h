#pragma once
#include"marker.h"
class index
{
public:
	index();
	~index();
	void initial(int);//�����ֵ�
	void release();//�ͷ��ֵ估��ǩ�ڴ�
	void setup(unsigned int, int, int);//����1��ת�����֣�����2��rank������3��pos
	void release_nail();
	int match(unsigned int);
	marker* listed(unsigned int);
private:
	marker** seek,**nail;//seekΪ������ָ�����飬������Ӧ����򱣳�һ��
	//nailΪ����������ָ�����飬������Ӧ�����ڶ��ļ�������rff����ʱ����
	int m,k;
};

