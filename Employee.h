//普通职工文件
#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

class Employee :public Worker
{
public:
	//构造函数
	Employee(int id,string name,int deptid);
	//显示个人信息
	virtual	void ShowInfo();
	//获取岗位名称
	virtual string getDepthName();



};