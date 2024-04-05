#include<iostream>
using namespace std;
#include"WorkerManager.h"


#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"

int main()
{
	////测试代码
	//Worker* worker = NULL;
	//worker = new Employee(1, "张三", 1);
	//worker->ShowInfo();
	//delete worker;


	//worker = new Manager(2, "李四", 2);
	//worker->ShowInfo();
	//delete worker;


	//worker = new Boss(3, "赵武", 3);
	//worker->ShowInfo();
	//delete worker;
	


	
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
			wm.add_Emp();
			break;
		case 2: //显示职工
			wm.Show_Emp();
			break;			
		case 3: //删除职工
			wm.Del_Emp();
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