#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "te.h"
#include <fstream>//ifstream读文件，ofstream写文件，fstream读写文件
#include <sstream>
#include <string>//文本对象，储存读取的内容
#include <iostream>//屏幕输出cout
#include <cstdlib>//调用system("pause");
#include <windows.h>//用于函数SetConsoleOutputCP(65001);更改cmd编码为utf8
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <vector>
using namespace std;


typedef struct Node 
{ //定义单个的所属类 ID具体类 存储的结构体 
	char name[20];
	char ISBN[20];
	char price[20];
	char p_name[20];
	char s_name[20];
	char t_name[20];
	char m_name[20];


}Node;
typedef struct Book 
{ //定义链表 
	Node date;
	struct Book* next;
}book;

string UTF8ToGB(const char* str)//我们为什么需要这个函数呢，因为我们从文本文件中读取时，编码是ASCII码或者GB2312可能不会出错，
                               //但是读取的是UTF8时，就很容易造成乱码，所以我们每次读取时都最好将读取到的内容转成GB2312。
{
	string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//获得临时变量的大小
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//获得临时变量的大小
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}

book* Read_file()
{             //实现链表信息录入文本
	cout << "信息正在读取" << endl;//得到查找的所属类 ID具体类 
	ifstream infile("1.txt");
	string data;
	book* h, * tail, * p;  //设置变量  
	h = tail = (book*)malloc(sizeof(book)); //定义变量 ，设置链表的指向 
	h->next = NULL;      //创建第一个信息 
	try
	{
		// 保护代码
		while (getline(infile, data)) {
			//cout << "read from file:" << data << endl;
			std::istringstream is(data);//作用是从string对象data中读取字符
			string n1;
			p = (book*)malloc(sizeof(book));  //得到所属类 ID具体类 
			string vstr[7];
			int cn = 0;
			while (is >> n1)
			{

				/*			n1=  UTF8ToGB(n1.c_str());*/
				vstr[cn] = n1;
				cn++;
			}
			//pstm
			strcpy(p->date.name, vstr[0].c_str());//是将一个字符串复制到另一块空间地址中 的函数，‘\0’是停止拷贝的终止条件，同时也会将 '\0' 也复制到目标空间。
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
			tail->next = p;         //对于上述的信息进行全部的存储 
			tail = p;               //得到当前的链表 	
		}
	}
	catch (exception)
	{
		// catch 块

		return h;

	}

	return h;
}



book* GreatLink()  //定义所属类 ID具体类 的录入函数 
{
	book* h, * tail, * p;  //设置变量 
	try
	{
		h = Read_file();
		tail = Read_file();
		h = h->next;
		tail = tail->next;
	}
	catch (exception)
	{
		h = tail = (book*)malloc(sizeof(book)); //定义变量 ，设置链表的指向 
	}
	//cout << h->date.name << h->date.ISBN << h->date.price << endl;
	//h->next = NULL;      //创建第一个信息 
	int n = 0;           //定义变量记录所属类 ID具体类 数量 

	cout << "输入要录入的人数：";

	scanf("%d", &n);     //得到所属类 ID具体类 数量 
	for (int i = 0; i < n; i++)   //开始循环存储 
	{
		p = (book*)malloc(sizeof(book));  //得到所属类 ID具体类 
		cout << "所属类：";
		scanf("%s", &p->date.name);    //存储所属类 ID具体类 
		string s;
		s = p->date.name;

		if (s == "会员")
		{
			cout << "ID:";              //得到所属类 ID具体类 
			scanf("%s", &p->date.ISBN);   //存储I所属类 ID具体类 
			cout << "具体类：";            //得到所属类 ID具体类 
			scanf("%s", &p->date.price); //存储所属类 ID具体类    
			cout << "姓名：";
			scanf("%s", &p->date.p_name);    //存储所属类 ID具体类 
			cout << "性别:";              //得到所属类 ID具体类 
			scanf("%s", &p->date.s_name);   //存储I所属类 ID具体类 
			cout << "办卡时间：";            //得到所属类 ID具体类 
			scanf("%s", &p->date.t_name); //存储所属类 ID具体类  
			cout << "充值金额：";            //得到所属类 ID具体类 
			scanf("%s", &p->date.m_name); //存储所属类 ID具体类  
		}
		if (s == "员工")
		{
			cout << "ID:";              //得到所属类 ID具体类 
			scanf("%s", &p->date.ISBN);   //存储I所属类 ID具体类 
			cout << "具体类：";            //得到所属类 ID具体类 
			scanf("%s", &p->date.price); //存储所属类 ID具体类    
			cout << "姓名：";
			scanf("%s", &p->date.p_name);    //存储所属类 ID具体类 
			cout << "性别:";              //得到所属类 ID具体类 
			scanf("%s", &p->date.s_name);   //存储I所属类 ID具体类 
			cout << "入职时间：";            //得到所属类 ID具体类 
			scanf("%s", &p->date.t_name); //存储所属类 ID具体类  
			cout << "工资：";            //得到所属类 ID具体类 
			scanf("%s", &p->date.m_name); //存储所属类 ID具体类  
		}
		p->next = tail->next;//对于上述的信息进行全部的存储 
		tail->next = p;//将信息放入到链表中
		//tail = p;               //得到当前的链表 
	}
	h->next = tail;
	return h;             //返回总的链表 
}

void write_file(book* h)
{             //实现链表信息录入文本
	FILE* fp;
	cout << "信息正在录入";//得到查找所属类 ID具体类 
	fp = fopen("1.txt", "w");
	if (NULL == fp)
	{
		cout << "该文件打开失败！";
	}
	book* p;//定义变量 
	//cout << "所属类\tID\t具体类\n";//输出
	for (p = h->next; p != NULL; p = p->next)//循环遍历 
	{
		string s;
		s = p->date.name;
		if (s == "会员")
		{
			cout << "所属类\tID\t具体类\t姓名\t性别\t办卡时间\t充值金额\t\n";//输出
		}
		if (s == "员工")
		{
			cout << "所属类\tID\t具体类\t姓名\t性别\t入职时间\t工资\t\n";//输出
		}
		cout << p->date.name << "\t";//输出所属类 ID具体类 
		cout << p->date.ISBN << "\t";//输出ID
		cout << p->date.price << "\t";//输出具体类 
		cout << p->date.p_name << "\t";//姓名
		cout << p->date.s_name << "\t";//性别
		cout << p->date.t_name << "\t";//
		cout << p->date.m_name << "\t";//
		cout << "\n";//换行 
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n", p->date.name, p->date.ISBN, p->date.price, p->date.p_name, p->date.s_name, p->date.t_name, p->date.m_name);//打印输出到文件
	}
	fclose(fp);//关闭当前文件流
	cout << "（信息已录入，并保存于1.txt当中！！！）\n\n";
}





void Insert(book* h)//插入(头插法)
{
	book* p;                     //创建一个新的结构体 
	p = (book*)malloc(sizeof(book)); //得到所属类 ID具体类  
	cout << "所属类：";//存储类名 
	scanf("%s", &p->date.name);//得到类名
	string s;
	s = p->date.name;
	if (s == "会员")
	{
		cout << "ID:";              //得到所属类 ID具体类 
		scanf("%s", &p->date.ISBN);   //存储I所属类 ID具体类 
		cout << "具体类：";            //得到所属类 ID具体类 
		scanf("%s", &p->date.price); //存储所属类 ID具体类    
		cout << "姓名：";
		scanf("%s", &p->date.p_name);    //存储所属类 ID具体类 
		cout << "性别:";              //得到所属类 ID具体类 
		scanf("%s", &p->date.s_name);   //存储I所属类 ID具体类 
		cout << "办卡时间：";            //得到所属类 ID具体类 
		scanf("%s", &p->date.t_name); //存储所属类 ID具体类  
		cout << "充值金额：";            //得到所属类 ID具体类 
		scanf("%s", &p->date.m_name); //存储所属类 ID具体类  

	}
	if (s == "员工")
	{
		cout << "ID:";              //得到所属类 ID具体类 
		scanf("%s", &p->date.ISBN);   //存储I所属类 ID具体类 
		cout << "具体类：";            //得到所属类 ID具体类 
		scanf("%s", &p->date.price); //存储所属类 ID具体类    
		cout << "姓名：";
		scanf("%s", &p->date.p_name);    //存储所属类 ID具体类 
		cout << "性别:";              //得到所属类 ID具体类 
		scanf("%s", &p->date.s_name);   //存储I所属类 ID具体类 
		cout << "入职时间：";            //得到所属类 ID具体类 
		scanf("%s", &p->date.t_name); //存储所属类 ID具体类  
		cout << "工资：";            //得到所属类 ID具体类 
		scanf("%s", &p->date.m_name); //存储所属类 ID具体类  
	}
	p->next = h->next;//对于上述的信息进行全部的存储 
	h->next = p;//将信息放入到链表中 
}




void Search(book* h)//查找
{
	char name[20];
	book* p = h->next;  //指向链表 
	cout << "输入要查找的所属类：";//输出
	scanf("%s", &name);//得到查找的所属类 ID具体类  
	while (p != NULL)//判断是否为空 
	{
		if (strcmp(p->date.name, name) != 0) //判断是否找到 
		{
			p = p->next;     //没找到继续指向下一个 
		}
		else    //找到输出 
		{
			string s;
			s = p->date.name;
			if (s == "会员")
			{
				cout << "所属类\tID\t具体类\t姓名\t性别\t办卡时间\t充值金额\t\n";//输出
			}
			if (s == "员工")
			{
				cout << "所属类\tID\t具体类\t姓名\t性别\t入职时间\t工资\t\n";//输出
			}

			cout << p->date.name << "\t" << p->date.ISBN << "\t" << p->date.price << "\t" << p->date.p_name << "\t" << p->date.s_name << "\t" << p->date.t_name << "\t" << p->date.m_name << "\n";
			return;
		}
	}
	if (p == NULL) //找到底或者为空，则没有找到 
	{
		cout << "没有查询到！\n";//输出
	}
}
void Search1(book* h)//ID查找
{
	char ISBN[20];
	book* p = h->next;//指向链表 
	cout << "输入要查找的ID：";//得到查找的所属类 ID具体类 
	scanf("%s", &ISBN);
	while (p != NULL)//判断是否为空
	{
		if (strcmp(p->date.ISBN, ISBN) != 0)//判断是否找到  比较两个字符串的大小，一个字符一个字符比较，按ASCLL码比较
		{
			p = p->next;//没找到继续指向下一个 
		}
		else//找到输出 
		{
			string s;
			s = p->date.name;
			if (s == "会员")
			{
				cout << "所属类\tID\t具体类\t姓名\t性别\t办卡时间\t充值金额\t\n";//输出
			}
			if (s == "员工")
			{
				cout << "所属类\tID\t具体类\t姓名\t性别\t入职时间\t工资\t\n";//输出
			}

			cout << p->date.name << "\t" << p->date.ISBN << "\t" << p->date.price << "\t" << p->date.p_name << "\t" << p->date.s_name << "\t" << p->date.t_name << "\t" << p->date.m_name << "\n";
			return;
		}

	}
	if (p == NULL)//找到底或者为空，则没有找到 
	{
		cout << "没有查询到！\n";//输出
	}
}

void PrintLink(book* h)//输出所有信息 
{
	book* p;//定义变量 

	for (p = h->next; p != NULL; p = p->next)//循环遍历 
	{
		string s;
		s = p->date.name;
		if (s == "会员")
		{
			cout << "所属类\tID\t具体类\t姓名\t性别\t办卡时间\t充值金额\t\n";//输出
		}
		if (s == "员工")
		{
			cout << "所属类\tID\t具体类\t姓名\t性别\t入职时间\t工资\t\n";//输出
		}

		cout << p->date.name << "\t" << p->date.ISBN << "\t" << p->date.price << "\t" << p->date.p_name << "\t" << p->date.s_name << "\t" << p->date.t_name << "\t" << p->date.m_name << "\n";
	}

}
void delete1(book* h) //删除 
{
	char ISBN[20];//按ISBN删除，因为ID是唯一的
	book* p = h->next;//定义变量 
	book* tail = h; //定义变量 
	cout << "输入要删除的ID：";//得到 ISBN
	scanf("%s", &ISBN);//得到 ISBN
	while (p != NULL)//判断是否为空
	{
		if (strcmp(p->date.ISBN, ISBN) != 0)//判断是否找到 
		{
			p = p->next;//没找到继续指向下一个 
			tail = tail->next;//没找到继续指向下一个 
		}
		else
		{
			tail->next = p->next;//找到该位置 
			free(p);//删除 
			return;//结束 
		}
	}
}



//box类位于#include "te.h"

// 成员函数定义
void Box::setWidth(string wid)//函数模板
{
	width = wid;
}

// 请注意：printWidth() 不是任何类的成员函数
void printWidth(Box box)
{
	/* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
	cout << "*************" << box.width << "*************" << endl;
}



// 基类
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
	virtual void fool()//虚函数
	{
		cout << "开始执行" << endl;
	}
};
class B :public A
{
public:
	void fool()
	{
		cout << "开始执行" << endl;
	}
};

class printData//重载
{
public:
	void print(string a, string b) {
		cout << "执行: " << a + b << endl;
	}

	void print(string a) {
		cout << "开始: " << a << endl;
	}

};


void menu()//显示菜单  
{
	//重载
	printData pd;

	// 输出整数
	pd.print("健身俱乐部", "管理系统");//默认参数
	pd.print("运行");

	//虚函数
	A* a = new B();
	a->fool();   // 在这里，a虽然是指向A的指针，但是被调用的函数(fool)却是B的!
	// 派生类 //多继承
	extern class Rectangle : public Shape
	{
	public:
		string getArea()
		{
			return width + height;
		}
	};
	Rectangle Re;
	Re.setWidth("开始");
	Re.setHeight("使用");
	// 输出对象
	cout << "启动成功：" << Re.getArea() << endl;
	cout << Hello<string>("欢迎使用") << endl;//多文件//函数模板
	Box box;
	// 使用成员函数设置
	box.setWidth("欢迎使用健身俱乐部管理系统");
	// 使用友元函数输出
	printWidth(box);
	cout << "************1.添加功能************\n";
	cout << "************2.编辑功能************\n";
	cout << "************3.按所属类查询功能******\n";
	cout << "***********4.按ID查询功能*******\n";
	cout << "************5.删除功能************\n";
	cout << "************6.显示功能************\n";
	cout << "************7.保存功能************\n";
	cout << "************8.读取功能************\n";
	cout << "注：只录入一次，否则会覆盖\n";
}

void choose(book* h)//用户的功能选择判断  
{
	int i;
	int a = 1;
	bool flag = FALSE;
	while (a > 0)
	{

		menu(); //显示菜单 
		cout << "请选择：";
		scanf("%d", &i); //得到选择的功能序号 
		switch (i) //根据序号找到对应的功能 
		{
		case 1:
			h = GreatLink(); //录入 
			flag = TRUE;
			break;
		case 2:
			if (not flag)
			{
				h = Read_file();
				flag = TRUE;
			}
			Insert(h);//插入 
			break;
		case 3:
			if (not flag)
			{
				h = Read_file();
			}
			Search(h); //按所属类查询
			break;
		case 4:
			if (not flag)
			{
				h = Read_file();
			}
			Search1(h);//按ID查询
			break;
		case 5:
			if (not flag)
			{
				h = Read_file();
				flag = TRUE;
			}
			delete1(h);//删除会员信息 
			break;
		case 6:
			if (not flag)
			{
				h = Read_file();
			}
			PrintLink(h);//输出所有会员信息 
			break;
		case 7:
			if (not flag)
			{
				h = Read_file();
			}
			write_file(h);//保存会员信息 
			break;
		case 8:
			if (not flag)
			{
				h = Read_file();
			}
			Read_file();//读取会员信息
			break;

		default:
			cout << "无效的命令！\n";
			a = -1;//跳出循环条件 
			break;
		}
	}
}

int main() //主函数 
{
	book* head = NULL; //设置变量 
	choose(head); //开始执行 
	return 0; //结束 
}
