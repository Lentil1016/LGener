#pragma once
class short_seq//����ΪATGC����ת��
{
public:
	short_seq();
	~short_seq();
	unsigned char diction(char*);//�ֵ�ѹ��
	unsigned int diction(char*, int);//�����ֵ�ѹ��
	unsigned int next(char*, int, unsigned int*);
};

