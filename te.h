#pragma once
#include<iostream>
using namespace std;
template<class T>//����ģ��
T Hello(string x)
{
	string s;
	s = x;
	return s;
}//��ͷ�ļ�����������

class Box
{
	string width;
public:
	friend void printWidth(Box box);//��Ԫ����
	void setWidth(string wid);
};