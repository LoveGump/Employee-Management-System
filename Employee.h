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
	virtual	void ShowInfo() = 0;
	//获取岗位名称
	virtual string getDepthName() = 0;

	//职工编号
	int m_ID;

	//职工姓名
	string m_name;
	//部门编号
	int m_DeptID;

};