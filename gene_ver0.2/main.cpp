
//18�մ���rff��indexing�����ı���n�����������󣬵��¶�ȡʧ��
//19�մ���index��initial����kû�г�2������ָ���ʼ������ȫ
#include<iostream>
#include"cells.h"
#include"rff.h"
#include <ctime>
#include"index.h"
#include"marker.h"
#include <cmath>
#include"short_seq.h"
using namespace std;
const string file1 = "solexa_100_170_1.fa",file2="solexa_100_170_2.fa";//�˴���д���ݿ��ļ���

int main()
{
//-------------------����ר��--------------------//
	//19��Ϊ����X64��sizeof����
	//cout << sizeof(marker) << "=marker,short=" << sizeof(short);
	//cin.get();
//--------------------��ʼ������-----------------//
	cout <<"\n" " /-------------------------------------------\n" << " |                  ver 0.2                 |\n" << " |               4_17 launched              |\n" << " -------------------------------------------/\n";
	int i, k, k1, k_max, n, n1;//k_max��ʾ�����ֵ����󳤶�
	clock_t a, b; 
	index ind;
	cout<<"\n������kֵ�Խ���������k=" ;
	cin >> k;
	k_max = k;
	if (k < 12) k1 = (int)pow(2, k*2);
	else
	{
		k1 = 16777216;
		k_max = 12;
	}
	//cout << "main���19�մ���>" << k1 << endl;//���19�մ���
	ind.initial(k1);//��ʼ���ֵ䣬���ô�СΪk<24��24λ
	a = clock();//��ʼ�����ʱ
	cout << "\n���ڳ�ʼ��������������\n" << endl;//����kֵ
	cells *celllist = new cells[1000000]; //����ϸ���������ͷ
	n = 1000000;//n��ϸ��
	n1 = n / 2;


//---------------ѡ����ļ�ģʽ---------------//
	//read_file dbase1;//���ڶ��ļ��࣬�Ѿ���̭
	rff  dbase1;
//���ļ�ģʽ��Read_File(read_file��)/Read_File_Fast(rff��)


//---------------���ļ�1----------------------//
	dbase1.extract(file1);//�������ļ�,��ʧ�������
	for (i =0; i <n1 ; i++)
	{
		dbase1.indexing((&celllist[i])->take_rna(), k_max, &ind, i);//��ȡ��ǰRNA��������ʼ�����
		//p->test();//������������ǰRNA����ϸ���ˣ���ɾ��
		if (i%25000==0)
			cout <<"I" ;//���ļ����̼��
	}
	cout << "]\n�����������\n" << endl;


//---------------���ļ�2----------------------//
	dbase1.extract(file2);//�������ļ�,��ʧ�������
	for (; i < n; i++)
	{
		dbase1.indexing((&celllist[i])->take_rna(), k_max, &ind, i);//��ȡ��ǰRNA��������ʼ�����
		//p->test();//������������ǰRNA����ϸ���ˣ���ɾ��
		if (i % 25000 == 0)
			cout << "I";//���ļ����̼��
	}
	cout << "]\n�����������\n" << endl;
	dbase1.~rff();//�رն��ļ���
	ind.release_nail();//�ͷŽ�������ʱ��ʱ������βָ������
	b = clock();//��ʱ���ļ�����
	double duration = (double)(b - a) / CLOCKS_PER_SEC;
	cout << "������������ʱ" << duration << "s��\n��ʼ�����\n" << endl;

//-----------------����DNA���----------------//

//-----------------��������-----------------------//

	char* k_mer = new char[k];//�½���ʱ�ַ����洢����k_mer
	short_seq prs;
	if (k < 13)//24�������index���ֺ���
	{
		while (1)
		{
			cout << "\n����������Q\n�����������������Ҫ������k_mer��";
			cin >> k_mer[0];
			if (k_mer[0] == 'Q') break;
			a = clock();
			for (i = 1; i < k; i++)
				cin >> k_mer[i];
			/*cout <<"k="<<k<<"k[3]="<< *(k_mer+3) << ",";//������
			unsigned int temp=prs.diction(k_mer, k);//������
			cout << temp;//������
			cin.get();//�����ã����ڲ���19�յ�һ�ν���������*/
			cout<<"\n\n��������"<<(ind.match(prs.diction(k_mer, k)))<<"�����";
			b = clock(); 
			double duration = (double)(b - a) / CLOCKS_PER_SEC;
			cout << "����������ʱ" << duration<< "s��\n\n" << endl;
		}
	}
	else
	{
		//k>12�����
		int* rank = &n1;//�����洢��ǰλ����Ϣ
		marker* list;//�����洢������ͷ
		unsigned char pos,c_k=k,c_k_max=k_max;
		int adder;
		while (1)
		{
			cout << "\n����������Q\n�����������������Ҫ������k_mer��";
			adder = 0;
			cin >> k_mer[0];
			if (k_mer[0] == 'Q') break;
			a = clock();
			for (i = 1; i < k; i++)
				cin >> k_mer[i];//����k_mer���
			//cout << "��ȡ���"  << endl;//���������
			//cout << prs.diction(k_mer, 12) << endl;//����12λ������
			list = ind.listed(prs.diction(k_mer, 12));
			while (list != 0)
			{
				//cin.get();//������
				pos = list->consult(rank);//��ʼ��pos��rank
				//cout << "\nһ��ѭ��" << endl;//������
				if (pos + k < 101)
				{
					//cout << "\n�ж����" << endl;//������
					//cout <<"\nmain��pos���в���"<< (int)pos << endl;//����pos���Խ�β;
					unsigned char low = c_k_max-(pos)%4;//floor to 4�ı���
					//cout<< "low=" <<(int) low << endl;//������
					if (celllist[*rank].match(k_mer, low, c_k,pos))//�˴�����pos������棬���rank��pos
					{
						list->print();
						adder++;
					}
				}
				list = list->next();
				//cout << list << endl;//������
			}
			cout << "\n��������" << adder << "�����";
			b = clock();
			double duration = (double)(b - a) / CLOCKS_PER_SEC;
			cout << "����������ʱ" << duration << "s��\n\n" << endl;
		}
	}
//--------------------�ر�����-------------------//checked
	ind.release();//�ͷ������ڴ�
	cout << "������ջ�ͷ����" << endl;
	cout << "�����ڴ��ͷ����" << endl;
	delete [] celllist;
	cout << "\n��ջ�ڴ��ͷųɹ��������������س��˳���" << endl;//�ͷŽ���
	char c;
	cin>>c;//���س�
	return 0;
}