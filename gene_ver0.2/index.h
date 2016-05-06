#pragma once
#include"marker.h"
class index
{
public:
	index();
	~index();
	void initial(int);//建立字典
	void release();//释放字典及书签内存
	void setup(unsigned int, int, int);//参数1是转义数字，参数2是rank，参数3是pos
	void release_nail();
	int match(unsigned int);
	marker* listed(unsigned int);
private:
	marker** seek,**nail;//seek为索引用指针数组，生存期应与程序保持一致
	//nail为创建链表用指针数组，生存期应结束于读文件，即在rff析构时结束
	int m,k;
};

