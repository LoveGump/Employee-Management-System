#pragma once //防止头文件重复
#include<iostream>
using namespace std;

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//显示菜单
	void Show_Menu();

	//推出系统
	void ExitSystem();

	//析构函数
	~WorkerManager();

};