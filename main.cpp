#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "te.h"
#include <fstream>//ifstream���ļ���ofstreamд�ļ���fstream��д�ļ�
#include <sstream>
#include <string>//�ı����󣬴����ȡ������
#include <iostream>//��Ļ���cout
#include <cstdlib>//����system("pause");
#include <windows.h>//���ں���SetConsoleOutputCP(65001);����cmd����Ϊutf8
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <vector>
using namespace std;


typedef struct Node 
{ //���嵥���������� ID������ �洢�Ľṹ�� 
	char name[20];
	char ISBN[20];
	char price[20];
	char p_name[20];
	char s_name[20];
	char t_name[20];
	char m_name[20];


}Node;
typedef struct Book 
{ //�������� 
	Node date;
	struct Book* next;
}book;

string UTF8ToGB(const char* str)//����Ϊʲô��Ҫ��������أ���Ϊ���Ǵ��ı��ļ��ж�ȡʱ��������ASCII�����GB2312���ܲ������
                               //���Ƕ�ȡ����UTF8ʱ���ͺ�����������룬��������ÿ�ζ�ȡʱ����ý���ȡ��������ת��GB2312��
{
	string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//�����ʱ�����Ĵ�С
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//�����ʱ�����Ĵ�С
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}

book* Read_file()
{             //ʵ��������Ϣ¼���ı�
	cout << "��Ϣ���ڶ�ȡ" << endl;//�õ����ҵ������� ID������ 
	ifstream infile("1.txt");
	string data;
	book* h, * tail, * p;  //���ñ���  
	h = tail = (book*)malloc(sizeof(book)); //������� �����������ָ�� 
	h->next = NULL;      //������һ����Ϣ 
	try
	{
		// ��������
		while (getline(infile, data)) {
			//cout << "read from file:" << data << endl;
			std::istringstream is(data);//�����Ǵ�string����data�ж�ȡ�ַ�
			string n1;
			p = (book*)malloc(sizeof(book));  //�õ������� ID������ 
			string vstr[7];
			int cn = 0;
			while (is >> n1)
			{

				/*			n1=  UTF8ToGB(n1.c_str());*/
				vstr[cn] = n1;
				cn++;
			}
			//pstm
			strcpy(p->date.name, vstr[0].c_str());//�ǽ�һ���ַ������Ƶ���һ��ռ��ַ�� �ĺ�������\0����ֹͣ��������ֹ������ͬʱҲ�Ὣ '\0' Ҳ���Ƶ�Ŀ��ռ䡣
			strcpy(p->date.ISBN, vstr[1].c_str());
			strcpy(p->date.price, vstr[2].c_str());
			strcpy(p->date.p_name, vstr[3].c_str());
			strcpy(p->date.s_name, vstr[4].c_str());
			strcpy(p->date.t_name, vstr[5].c_str());
			strcpy(p->date.m_name, vstr[6].c_str());
			cout << p->date.name << "\t" << p->date.ISBN << "\t" << p->date.price << "\t" << p->date.p_name << "\t"
				<< p->date.s_name << "\t" << p->date.t_name << "\t" << p->date.m_name << endl;
			/*	while(is >>n1)
				{
				cout << n1 << endl ;
				p->date.name = n1;

				}*/
			p->next = NULL;
			tail->next = p;         //������������Ϣ����ȫ���Ĵ洢 
			tail = p;               //�õ���ǰ������ 	
		}
	}
	catch (exception)
	{
		// catch ��

		return h;

	}

	return h;
}



book* GreatLink()  //���������� ID������ ��¼�뺯�� 
{
	book* h, * tail, * p;  //���ñ��� 
	try
	{
		h = Read_file();
		tail = Read_file();
		h = h->next;
		tail = tail->next;
	}
	catch (exception)
	{
		h = tail = (book*)malloc(sizeof(book)); //������� �����������ָ�� 
	}
	//cout << h->date.name << h->date.ISBN << h->date.price << endl;
	//h->next = NULL;      //������һ����Ϣ 
	int n = 0;           //���������¼������ ID������ ���� 

	cout << "����Ҫ¼���������";

	scanf("%d", &n);     //�õ������� ID������ ���� 
	for (int i = 0; i < n; i++)   //��ʼѭ���洢 
	{
		p = (book*)malloc(sizeof(book));  //�õ������� ID������ 
		cout << "�����ࣺ";
		scanf("%s", &p->date.name);    //�洢������ ID������ 
		string s;
		s = p->date.name;

		if (s == "��Ա")
		{
			cout << "ID:";              //�õ������� ID������ 
			scanf("%s", &p->date.ISBN);   //�洢I������ ID������ 
			cout << "�����ࣺ";            //�õ������� ID������ 
			scanf("%s", &p->date.price); //�洢������ ID������    
			cout << "������";
			scanf("%s", &p->date.p_name);    //�洢������ ID������ 
			cout << "�Ա�:";              //�õ������� ID������ 
			scanf("%s", &p->date.s_name);   //�洢I������ ID������ 
			cout << "�쿨ʱ�䣺";            //�õ������� ID������ 
			scanf("%s", &p->date.t_name); //�洢������ ID������  
			cout << "��ֵ��";            //�õ������� ID������ 
			scanf("%s", &p->date.m_name); //�洢������ ID������  
		}
		if (s == "Ա��")
		{
			cout << "ID:";              //�õ������� ID������ 
			scanf("%s", &p->date.ISBN);   //�洢I������ ID������ 
			cout << "�����ࣺ";            //�õ������� ID������ 
			scanf("%s", &p->date.price); //�洢������ ID������    
			cout << "������";
			scanf("%s", &p->date.p_name);    //�洢������ ID������ 
			cout << "�Ա�:";              //�õ������� ID������ 
			scanf("%s", &p->date.s_name);   //�洢I������ ID������ 
			cout << "��ְʱ�䣺";            //�õ������� ID������ 
			scanf("%s", &p->date.t_name); //�洢������ ID������  
			cout << "���ʣ�";            //�õ������� ID������ 
			scanf("%s", &p->date.m_name); //�洢������ ID������  
		}
		p->next = tail->next;//������������Ϣ����ȫ���Ĵ洢 
		tail->next = p;//����Ϣ���뵽������
		//tail = p;               //�õ���ǰ������ 
	}
	h->next = tail;
	return h;             //�����ܵ����� 
}

void write_file(book* h)
{             //ʵ��������Ϣ¼���ı�
	FILE* fp;
	cout << "��Ϣ����¼��";//�õ����������� ID������ 
	fp = fopen("1.txt", "w");
	if (NULL == fp)
	{
		cout << "���ļ���ʧ�ܣ�";
	}
	book* p;//������� 
	//cout << "������\tID\t������\n";//���
	for (p = h->next; p != NULL; p = p->next)//ѭ������ 
	{
		string s;
		s = p->date.name;
		if (s == "��Ա")
		{
			cout << "������\tID\t������\t����\t�Ա�\t�쿨ʱ��\t��ֵ���\t\n";//���
		}
		if (s == "Ա��")
		{
			cout << "������\tID\t������\t����\t�Ա�\t��ְʱ��\t����\t\n";//���
		}
		cout << p->date.name << "\t";//��������� ID������ 
		cout << p->date.ISBN << "\t";//���ID
		cout << p->date.price << "\t";//��������� 
		cout << p->date.p_name << "\t";//����
		cout << p->date.s_name << "\t";//�Ա�
		cout << p->date.t_name << "\t";//
		cout << p->date.m_name << "\t";//
		cout << "\n";//���� 
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n", p->date.name, p->date.ISBN, p->date.price, p->date.p_name, p->date.s_name, p->date.t_name, p->date.m_name);//��ӡ������ļ�
	}
	fclose(fp);//�رյ�ǰ�ļ���
	cout << "����Ϣ��¼�룬��������1.txt���У�������\n\n";
}





void Insert(book* h)//����(ͷ�巨)
{
	book* p;                     //����һ���µĽṹ�� 
	p = (book*)malloc(sizeof(book)); //�õ������� ID������  
	cout << "�����ࣺ";//�洢���� 
	scanf("%s", &p->date.name);//�õ�����
	string s;
	s = p->date.name;
	if (s == "��Ա")
	{
		cout << "ID:";              //�õ������� ID������ 
		scanf("%s", &p->date.ISBN);   //�洢I������ ID������ 
		cout << "�����ࣺ";            //�õ������� ID������ 
		scanf("%s", &p->date.price); //�洢������ ID������    
		cout << "������";
		scanf("%s", &p->date.p_name);    //�洢������ ID������ 
		cout << "�Ա�:";              //�õ������� ID������ 
		scanf("%s", &p->date.s_name);   //�洢I������ ID������ 
		cout << "�쿨ʱ�䣺";            //�õ������� ID������ 
		scanf("%s", &p->date.t_name); //�洢������ ID������  
		cout << "��ֵ��";            //�õ������� ID������ 
		scanf("%s", &p->date.m_name); //�洢������ ID������  

	}
	if (s == "Ա��")
	{
		cout << "ID:";              //�õ������� ID������ 
		scanf("%s", &p->date.ISBN);   //�洢I������ ID������ 
		cout << "�����ࣺ";            //�õ������� ID������ 
		scanf("%s", &p->date.price); //�洢������ ID������    
		cout << "������";
		scanf("%s", &p->date.p_name);    //�洢������ ID������ 
		cout << "�Ա�:";              //�õ������� ID������ 
		scanf("%s", &p->date.s_name);   //�洢I������ ID������ 
		cout << "��ְʱ�䣺";            //�õ������� ID������ 
		scanf("%s", &p->date.t_name); //�洢������ ID������  
		cout << "���ʣ�";            //�õ������� ID������ 
		scanf("%s", &p->date.m_name); //�洢������ ID������  
	}
	p->next = h->next;//������������Ϣ����ȫ���Ĵ洢 
	h->next = p;//����Ϣ���뵽������ 
}




void Search(book* h)//����
{
	char name[20];
	book* p = h->next;  //ָ������ 
	cout << "����Ҫ���ҵ������ࣺ";//���
	scanf("%s", &name);//�õ����ҵ������� ID������  
	while (p != NULL)//�ж��Ƿ�Ϊ�� 
	{
		if (strcmp(p->date.name, name) != 0) //�ж��Ƿ��ҵ� 
		{
			p = p->next;     //û�ҵ�����ָ����һ�� 
		}
		else    //�ҵ���� 
		{
			string s;
			s = p->date.name;
			if (s == "��Ա")
			{
				cout << "������\tID\t������\t����\t�Ա�\t�쿨ʱ��\t��ֵ���\t\n";//���
			}
			if (s == "Ա��")
			{
				cout << "������\tID\t������\t����\t�Ա�\t��ְʱ��\t����\t\n";//���
			}

			cout << p->date.name << "\t" << p->date.ISBN << "\t" << p->date.price << "\t" << p->date.p_name << "\t" << p->date.s_name << "\t" << p->date.t_name << "\t" << p->date.m_name << "\n";
			return;
		}
	}
	if (p == NULL) //�ҵ��׻���Ϊ�գ���û���ҵ� 
	{
		cout << "û�в�ѯ����\n";//���
	}
}
void Search1(book* h)//ID����
{
	char ISBN[20];
	book* p = h->next;//ָ������ 
	cout << "����Ҫ���ҵ�ID��";//�õ����ҵ������� ID������ 
	scanf("%s", &ISBN);
	while (p != NULL)//�ж��Ƿ�Ϊ��
	{
		if (strcmp(p->date.ISBN, ISBN) != 0)//�ж��Ƿ��ҵ�  �Ƚ������ַ����Ĵ�С��һ���ַ�һ���ַ��Ƚϣ���ASCLL��Ƚ�
		{
			p = p->next;//û�ҵ�����ָ����һ�� 
		}
		else//�ҵ���� 
		{
			string s;
			s = p->date.name;
			if (s == "��Ա")
			{
				cout << "������\tID\t������\t����\t�Ա�\t�쿨ʱ��\t��ֵ���\t\n";//���
			}
			if (s == "Ա��")
			{
				cout << "������\tID\t������\t����\t�Ա�\t��ְʱ��\t����\t\n";//���
			}

			cout << p->date.name << "\t" << p->date.ISBN << "\t" << p->date.price << "\t" << p->date.p_name << "\t" << p->date.s_name << "\t" << p->date.t_name << "\t" << p->date.m_name << "\n";
			return;
		}

	}
	if (p == NULL)//�ҵ��׻���Ϊ�գ���û���ҵ� 
	{
		cout << "û�в�ѯ����\n";//���
	}
}

void PrintLink(book* h)//���������Ϣ 
{
	book* p;//������� 

	for (p = h->next; p != NULL; p = p->next)//ѭ������ 
	{
		string s;
		s = p->date.name;
		if (s == "��Ա")
		{
			cout << "������\tID\t������\t����\t�Ա�\t�쿨ʱ��\t��ֵ���\t\n";//���
		}
		if (s == "Ա��")
		{
			cout << "������\tID\t������\t����\t�Ա�\t��ְʱ��\t����\t\n";//���
		}

		cout << p->date.name << "\t" << p->date.ISBN << "\t" << p->date.price << "\t" << p->date.p_name << "\t" << p->date.s_name << "\t" << p->date.t_name << "\t" << p->date.m_name << "\n";
	}

}
void delete1(book* h) //ɾ�� 
{
	char ISBN[20];//��ISBNɾ������ΪID��Ψһ��
	book* p = h->next;//������� 
	book* tail = h; //������� 
	cout << "����Ҫɾ����ID��";//�õ� ISBN
	scanf("%s", &ISBN);//�õ� ISBN
	while (p != NULL)//�ж��Ƿ�Ϊ��
	{
		if (strcmp(p->date.ISBN, ISBN) != 0)//�ж��Ƿ��ҵ� 
		{
			p = p->next;//û�ҵ�����ָ����һ�� 
			tail = tail->next;//û�ҵ�����ָ����һ�� 
		}
		else
		{
			tail->next = p->next;//�ҵ���λ�� 
			free(p);//ɾ�� 
			return;//���� 
		}
	}
}



//box��λ��#include "te.h"

// ��Ա��������
void Box::setWidth(string wid)//����ģ��
{
	width = wid;
}

// ��ע�⣺printWidth() �����κ���ĳ�Ա����
void printWidth(Box box)
{
	/* ��Ϊ printWidth() �� Box ����Ԫ��������ֱ�ӷ��ʸ�����κγ�Ա */
	cout << "*************" << box.width << "*************" << endl;
}



// ����
class Shape
{
public:
	void setWidth(string w)
	{
		width = w;
	}
	void setHeight(string  h)
	{
		height = h;
	}
protected:
	string width;
	string height;
};



class A
{
public:
	virtual void fool()//�麯��
	{
		cout << "��ʼִ��" << endl;
	}
};
class B :public A
{
public:
	void fool()
	{
		cout << "��ʼִ��" << endl;
	}
};

class printData//����
{
public:
	void print(string a, string b) {
		cout << "ִ��: " << a + b << endl;
	}

	void print(string a) {
		cout << "��ʼ: " << a << endl;
	}

};


void menu()//��ʾ�˵�  
{
	//����
	printData pd;

	// �������
	pd.print("������ֲ�", "����ϵͳ");//Ĭ�ϲ���
	pd.print("����");

	//�麯��
	A* a = new B();
	a->fool();   // �����a��Ȼ��ָ��A��ָ�룬���Ǳ����õĺ���(fool)ȴ��B��!
	// ������ //��̳�
	extern class Rectangle : public Shape
	{
	public:
		string getArea()
		{
			return width + height;
		}
	};
	Rectangle Re;
	Re.setWidth("��ʼ");
	Re.setHeight("ʹ��");
	// �������
	cout << "�����ɹ���" << Re.getArea() << endl;
	cout << Hello<string>("��ӭʹ��") << endl;//���ļ�//����ģ��
	Box box;
	// ʹ�ó�Ա��������
	box.setWidth("��ӭʹ�ý�����ֲ�����ϵͳ");
	// ʹ����Ԫ�������
	printWidth(box);
	cout << "************1.��ӹ���************\n";
	cout << "************2.�༭����************\n";
	cout << "************3.���������ѯ����******\n";
	cout << "***********4.��ID��ѯ����*******\n";
	cout << "************5.ɾ������************\n";
	cout << "************6.��ʾ����************\n";
	cout << "************7.���湦��************\n";
	cout << "************8.��ȡ����************\n";
	cout << "ע��ֻ¼��һ�Σ�����Ḳ��\n";
}

void choose(book* h)//�û��Ĺ���ѡ���ж�  
{
	int i;
	int a = 1;
	bool flag = FALSE;
	while (a > 0)
	{

		menu(); //��ʾ�˵� 
		cout << "��ѡ��";
		scanf("%d", &i); //�õ�ѡ��Ĺ������ 
		switch (i) //��������ҵ���Ӧ�Ĺ��� 
		{
		case 1:
			h = GreatLink(); //¼�� 
			flag = TRUE;
			break;
		case 2:
			if (not flag)
			{
				h = Read_file();
				flag = TRUE;
			}
			Insert(h);//���� 
			break;
		case 3:
			if (not flag)
			{
				h = Read_file();
			}
			Search(h); //���������ѯ
			break;
		case 4:
			if (not flag)
			{
				h = Read_file();
			}
			Search1(h);//��ID��ѯ
			break;
		case 5:
			if (not flag)
			{
				h = Read_file();
				flag = TRUE;
			}
			delete1(h);//ɾ����Ա��Ϣ 
			break;
		case 6:
			if (not flag)
			{
				h = Read_file();
			}
			PrintLink(h);//������л�Ա��Ϣ 
			break;
		case 7:
			if (not flag)
			{
				h = Read_file();
			}
			write_file(h);//�����Ա��Ϣ 
			break;
		case 8:
			if (not flag)
			{
				h = Read_file();
			}
			Read_file();//��ȡ��Ա��Ϣ
			break;

		default:
			cout << "��Ч�����\n";
			a = -1;//����ѭ������ 
			break;
		}
	}
}

int main() //������ 
{
	book* head = NULL; //���ñ��� 
	choose(head); //��ʼִ�� 
	return 0; //���� 
}
