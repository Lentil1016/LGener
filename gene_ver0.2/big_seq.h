#pragma once
class big_seq
{
public:
	big_seq();
	~big_seq();
	void trans(unsigned char*);//转录RNA用，RNA头指针传参
	void gnrt(unsigned char*);//建立DNA用，同上
private:
	unsigned char dna[25];//DNA
};

