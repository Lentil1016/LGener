#pragma once
//#include"big_seq.h"ϸ������
class cells
{
public:
	cells();
	~cells();
	unsigned char* take_rna();//��ȡRNAͷ
	bool match(char*, unsigned char, unsigned char, unsigned char);
	//void test();//����rnaת¼dna����Ϊ���Ժ���
private:
	//big_seq seq;//ϸ���ˣ�������������rnaΪdna...�Ż���dna��Ϊ�����ڴ棬��ɾ��
	unsigned char rna[25];//RNA
};

