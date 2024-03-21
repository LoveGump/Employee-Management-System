#pragma once
#include<iostream>
#include<string>
using namespace std;

//职工抽象基类
class Worker
{
public:
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