#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

//������
class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int deptid);

	//��ʾ������Ϣ
	virtual	void ShowInfo() ;

	//��ȡ��λ����
	virtual string getDepthName();

};
