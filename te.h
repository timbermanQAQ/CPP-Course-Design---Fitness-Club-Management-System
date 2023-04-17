#pragma once
#include<iostream>
using namespace std;
template<class T>//函数模板
T Hello(string x)
{
	string s;
	s = x;
	return s;
}//在头文件中声明函数

class Box
{
	string width;
public:
	friend void printWidth(Box box);//友元函数
	void setWidth(string wid);
};