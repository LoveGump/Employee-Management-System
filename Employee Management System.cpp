#include<iostream>
using namespace std;
#include"WorkerManager.h"


int main()
{

	//实例化管理者对象

	WorkerManager wm;
	
	int choice = 0;//存储选项
	while (true)
	{
		wm.Show_Menu();
		cout << "请选择操作前面的序号" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //退出系统
			wm.ExitSystem();
			break;
		case 1: //添加职工
			break;
		case 2: //显示职工
			break;
		case 3: //删除职工
			break;
		case 4: //修改职工
			break;
		case 5: //查找职工
			break;
		case 6: //排序职工
			break;
		case 7: //清空文件
			break;
		default:
			system("cls");
			break;
		}

	}

	return 0;
}