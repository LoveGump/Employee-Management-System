//��ְͨ���ļ�
#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

class Employee :public Worker
{
public:
	//���캯��
	Employee(int id,string name,int deptid);
	//��ʾ������Ϣ
	virtual	void ShowInfo() = 0;
	//��ȡ��λ����
	virtual string getDepthName() = 0;

	//ְ�����
	int m_ID;

	//ְ������
	string m_name;
	//���ű��
	int m_DeptID;

};