
//18日错误：rff类indexing函数的变量n自增次数错误，导致读取失败
//19日错误：index类initial传参k没有乘2，导致指针初始化不完全
#include<iostream>
#include"cells.h"
#include"rff.h"
#include <ctime>
#include"index.h"
#include"marker.h"
#include <cmath>
#include"short_seq.h"
using namespace std;
const string file1 = "solexa_100_170_1.fa",file2="solexa_100_170_2.fa";//此处填写数据库文件名

int main()
{
//-------------------测试专用--------------------//
	//19日为测试X64的sizeof创建
	//cout << sizeof(marker) << "=marker,short=" << sizeof(short);
	//cin.get();
//--------------------初始化变量-----------------//
	cout <<"\n" " /-------------------------------------------\n" << " |                  ver 0.2                 |\n" << " |               4_17 launched              |\n" << " -------------------------------------------/\n";
	int i, k, k1, k_max, n, n1;//k_max表示索引字典的最大长度
	clock_t a, b; 
	index ind;
	cout<<"\n请输入k值以建立索引：k=" ;
	cin >> k;
	k_max = k;
	if (k < 12) k1 = (int)pow(2, k*2);
	else
	{
		k1 = 16777216;
		k_max = 12;
	}
	//cout << "main检测19日错误>" << k1 << endl;//检测19日错误
	ind.initial(k1);//初始化字典，设置大小为k<24或24位
	a = clock();//开始读入计时
	cout << "\n正在初始化······\n" << endl;//给定k值
	cells *celllist = new cells[1000000]; //创建细胞单链表表头
	n = 1000000;//n个细胞
	n1 = n / 2;


//---------------选择读文件模式---------------//
	//read_file dbase1;//早期读文件类，已经淘汰
	rff  dbase1;
//读文件模式：Read_File(read_file类)/Read_File_Fast(rff类)


//---------------读文件1----------------------//
	dbase1.extract(file1);//打开数据文件,若失败则结束
	for (i =0; i <n1 ; i++)
	{
		dbase1.indexing((&celllist[i])->take_rna(), k_max, &ind, i);//读取当前RNA，索引初始化完成
		//p->test();//早期用来将当前RNA存入细胞核，已删除
		if (i%25000==0)
			cout <<"I" ;//读文件进程监控
	}
	cout << "]\n索引建立完成\n" << endl;


//---------------读文件2----------------------//
	dbase1.extract(file2);//打开数据文件,若失败则结束
	for (; i < n; i++)
	{
		dbase1.indexing((&celllist[i])->take_rna(), k_max, &ind, i);//读取当前RNA，索引初始化完成
		//p->test();//早期用来将当前RNA存入细胞核，已删除
		if (i % 25000 == 0)
			cout << "I";//读文件进程监控
	}
	cout << "]\n索引建立完成\n" << endl;
	dbase1.~rff();//关闭读文件类
	ind.release_nail();//释放建立索引时临时创建的尾指针数组
	b = clock();//计时读文件结束
	double duration = (double)(b - a) / CLOCKS_PER_SEC;
	cout << "建立索引共用时" << duration << "s。\n初始化完成\n" << endl;

//-----------------读入DNA完毕----------------//

//-----------------搜索序列-----------------------//

	char* k_mer = new char[k];//新建临时字符串存储输入k_mer
	short_seq prs;
	if (k < 13)//24两种情况index两种函数
	{
		while (1)
		{
			cout << "\n结束请输入Q\n搜索请输入接下来需要搜索的k_mer：";
			cin >> k_mer[0];
			if (k_mer[0] == 'Q') break;
			a = clock();
			for (i = 1; i < k; i++)
				cin >> k_mer[i];
			/*cout <<"k="<<k<<"k[3]="<< *(k_mer+3) << ",";//测试用
			unsigned int temp=prs.diction(k_mer, k);//测试用
			cout << temp;//测试用
			cin.get();//测试用：用于测试19日第一次结果输出错误*/
			cout<<"\n\n共索引到"<<(ind.match(prs.diction(k_mer, k)))<<"个结果";
			b = clock(); 
			double duration = (double)(b - a) / CLOCKS_PER_SEC;
			cout << "，索引共用时" << duration<< "s。\n\n" << endl;
		}
	}
	else
	{
		//k>12的情况
		int* rank = &n1;//用来存储当前位置信息
		marker* list;//用来存储单链表头
		unsigned char pos,c_k=k,c_k_max=k_max;
		int adder;
		while (1)
		{
			cout << "\n结束请输入Q\n搜索请输入接下来需要搜索的k_mer：";
			adder = 0;
			cin >> k_mer[0];
			if (k_mer[0] == 'Q') break;
			a = clock();
			for (i = 1; i < k; i++)
				cin >> k_mer[i];//输入k_mer完毕
			//cout << "读取完毕"  << endl;//测试用输出
			//cout << prs.diction(k_mer, 12) << endl;//测试12位编码结果
			list = ind.listed(prs.diction(k_mer, 12));
			while (list != 0)
			{
				//cin.get();//测试用
				pos = list->consult(rank);//初始化pos和rank
				//cout << "\n一次循环" << endl;//测试用
				if (pos + k < 101)
				{
					//cout << "\n判断完成" << endl;//测试用
					//cout <<"\nmain下pos运行测试"<< (int)pos << endl;//测试pos测试结尾;
					unsigned char low = c_k_max-(pos)%4;//floor to 4的倍数
					//cout<< "low=" <<(int) low << endl;//测试用
					if (celllist[*rank].match(k_mer, low, c_k,pos))//此处搜索pos，如果真，输出rank和pos
					{
						list->print();
						adder++;
					}
				}
				list = list->next();
				//cout << list << endl;//测试用
			}
			cout << "\n共索引到" << adder << "个结果";
			b = clock();
			double duration = (double)(b - a) / CLOCKS_PER_SEC;
			cout << "，索引共用时" << duration << "s。\n\n" << endl;
		}
	}
//--------------------关闭序列-------------------//checked
	ind.release();//释放索引内存
	cout << "索引堆栈释放完毕" << endl;
	cout << "索引内存释放完毕" << endl;
	delete [] celllist;
	cout << "\n堆栈内存释放成功，输入任意键后回车退出：" << endl;//释放结束
	char c;
	cin>>c;//读回车
	return 0;
}