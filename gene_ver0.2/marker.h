#pragma once
class marker
{
public:
	marker();
	~marker();
	marker* next();//�ͷ�ʱ��ʹ��
	marker* print();//���ʱ��ʹ��
	marker* next(marker*);//����ʱ��ʹ��
	void mark(int, int);
	unsigned char consult(int*);
private:
	int rank;
	unsigned char pos;
	marker* p_next;
};

