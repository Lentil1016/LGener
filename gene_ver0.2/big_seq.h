#pragma once
class big_seq
{
public:
	big_seq();
	~big_seq();
	void trans(unsigned char*);//ת¼RNA�ã�RNAͷָ�봫��
	void gnrt(unsigned char*);//����DNA�ã�ͬ��
private:
	unsigned char dna[25];//DNA
};

