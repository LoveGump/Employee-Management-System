#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ���������
class Worker
{
public:
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