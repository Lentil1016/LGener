#pragma once
class short_seq//用来为ATGC序列转义
{
public:
	short_seq();
	~short_seq();
	unsigned char diction(char*);//字典压缩
	unsigned int diction(char*, int);//索引字典压缩
	unsigned int next(char*, int, unsigned int*);
};

