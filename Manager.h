#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

//������
class Manager :public Worker
{
public:
	//���캯��
	Manager(int id, string name, int deptid);
	//��ʾ������Ϣ
	virtual	void ShowInfo();
	//��ȡ��λ����
	virtual string getDepthName();

};
