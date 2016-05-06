#pragma once
class marker
{
public:
	marker();
	~marker();
	marker* next();//释放时被使用
	marker* print();//输出时被使用
	marker* next(marker*);//创建时被使用
	void mark(int, int);
	unsigned char consult(int*);
private:
	int rank;
	unsigned char pos;
	marker* p_next;
};

