#pragma once
//#include"big_seq.h"细胞核类
class cells
{
public:
	cells();
	~cells();
	unsigned char* take_rna();//提取RNA头
	bool match(char*, unsigned char, unsigned char, unsigned char);
	//void test();//早期rna转录dna，现为测试函数
private:
	//big_seq seq;//细胞核，早期用来备份rna为dna...优化后dna成为冗余内存，已删除
	unsigned char rna[25];//RNA
};

