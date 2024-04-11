#include"WorkerManager.h"


WorkerManager::WorkerManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		//初始化人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化标志 文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		cout << "文件为空" << endl;
		//初始化属性
		//初始化人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化标志 文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在 并且记录了数据
	int num = this->get_EmpNum();
	cout << "职工人数为" << num << endl;
	this->m_EmpNum = num;
	this->m_FileIsEmpty = false;
	//开辟空间，
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据，存到数组中
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工编号：" << this->m_EmpArray[i]->m_ID
	//		<< "\t职工姓名：" << this->m_EmpArray[i]->m_name
	//		<< "\t职工职位：" << this->m_EmpArray[i]->m_DeptID << endl;
	//}

}

//展示菜单
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//退出程序
void WorkerManager::ExitSystem() 
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序

}

//添加职工
void WorkerManager::add_Emp()
{
	cout << "请输入添加员工的数量" << endl;
	int add_Num;
	cin >> add_Num;
	bool IsLastAdd = true;
	if (add_Num == 1) {
		IsLastAdd = true;
	}
	else
	{
		IsLastAdd = false;
	}
	if (add_Num > 0)
	{

		//添加
		//计算添加新空间的大小
		int new_Size = this->m_EmpNum + add_Num;

		//开辟新空间
		Worker** new_Space = new Worker * [new_Size];

		//将原来空间下的数据放在新空间中
		if (this->m_EmpNum != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				new_Space[i] = this->m_EmpArray[i];

			}

		}
		//批量添加数据
		for (int i = 0; i < add_Num; i++)
		{
			if (add_Num == add_Num - 1) {
				IsLastAdd = true;
			}
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择

			cout << "请输入第" << i + 1 << "个职工的编号" << endl;
			cin >> id;
			if (this->IsExist(id) != -1) {
				cout << "您输入的职工编号已经存在，请重新输入" << endl;
				i -= 1;
				continue;
			}
			cout << "请输入第" << i + 1 << "个职工的姓名" << endl;
			cin >> name;

			cout << "请选择该员工的职位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			//判断职位选择是否正确
			while (true)
			{
				if (dSelect == 1 || dSelect == 2 || dSelect == 3)
				{
					break;
				}
				cout << "您输入的职位有误，请重新输入" << endl;
				cout << "请选择该员工的职位" << endl;
				cout << "1、普通职工" << endl;
				cout << "2、经理" << endl;
				cout << "3、老板" << endl;
				cin >> dSelect;
			}

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//创建新职工指针，保存在数组中
			new_Space[this->m_EmpNum] = worker;

			//如果是最后一个添加进来的则释放原有空间
			if (IsLastAdd) {
				delete[] this->m_EmpArray;
			}
			//更新指针指向
			this->m_EmpArray = new_Space;

			//更新职工人数
			this->m_EmpNum++;

			//更新职工不为空的标志
			this->m_FileIsEmpty = false;

			//保存数据到文件中
			this->save();

			//提示添加成功
			cout << "成功添加姓名为为" << this->m_EmpArray[m_EmpNum-1]->m_name << "的职工为新员工" << endl;
		}


		//提示添加成功
		cout << "成功添加" << add_Num << "名职工" << endl;


		//按任意键后，清屏返回上级目录
		system("pause");
		system("cls");

	}
	else
	{
		cout<<"输入数据有误"<<endl;
	}

}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件 --写文件
	//将每个人的数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " " 
			<< this->m_EmpArray[i]->m_name << " "
			<< m_EmpArray[i]->m_DeptID << endl;
	}

	//关闭文件
	ofs.close();

}

//统计文件中职工人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件 读

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//统计人数变量
		num++;
	}
	return num;
}

//初始化职工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if(dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	//关闭文件
	ifs.close();
}

//显示所有职工
void WorkerManager::Show_Emp()
{
	//判断文件是否有数据
	if (this->m_EmpNum == 0)
	{
		cout << "数据为空！！！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->ShowInfo();

		}

	}

	//按任意键清屏
	system("pause");
	system("cls");

}

//按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			index = i;

			break;
		}
	}
	return index;
}

//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入您想删除职工的编号" << endl;
		int  id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
		
			//数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//更新数组中记录的人员个数
			this->m_EmpNum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::Mod_Emp() 
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newID = 0;
			string newName = " ";
			int dSelect = 0;
			cout << "查到：" << id << "号职工，请输入新的职工号" << endl;
			cin >> newID;

			cout << "请输入新的名字" << endl;
			cin >> newName;

			cout << "请输入新的职位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			//判断职位选择是否正确
			while (true)
			{
				if (dSelect == 1 || dSelect == 2 || dSelect == 3)
				{
					break;
				}
				cout << "您输入的职位有误，请重新输入" << endl;
				cout << "请选择该员工的职位" << endl;
				cout << "1、普通职工" << endl;
				cout << "2、经理" << endl;
				cout << "3、老板" << endl;
				cin >> dSelect;
			}

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newID, newName, 1);
				break;
			case 2:
				worker = new Manager(newID, newName, 2);
				break;
			case 3:
				worker = new Boss(newID, newName, 3);
				break;
			default:
				cout << " " << endl;
				break;
			}

			//更新数据到数组中
			this->m_EmpArray[ret] = worker;

			cout << "修改成功" << endl;

			//保存到文件中
			this->save();

		}
		else
		{
			cout << "修改失败，未找到此人" << endl;
		}
	}
	system("pause");
	system("cls");

}

//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;

	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按照职工编号查找" << endl;
		cout << "2、按照姓名的方式查找" << endl;
	}

	int slect = 0;
	cin >> slect;

	//判断选择是否有误
	while (true)
	{
		if (slect == 1 || slect == 2) {
			break;
		}
		cout << "您输入的查找方式有误，请重新输入：" << endl;
		cout << "1、按照职工编号查找" << endl;
		cout << "2、按照姓名的方式查找" << endl;

	}

	if (slect == 1)
	{
		//按照职工编号查找
		int id;
		cout << "请输入您想查找的编号" << endl;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//找到职工
			cout << "查找成功！该职工的信息如下：" << endl;
			this->m_EmpArray[ret]->ShowInfo();
		}
		else
		{
			//未找到职工
			cout << "查找失败，查无此人" << endl;
		}

	}
	else
	{
		//按照姓名查找

		string name;
		cout << "请输入查找的姓名：" << endl;
		cin >> name;
		
		//查找成功的次数
		int count = 0;

		for (int i = 0; i < m_EmpNum; i++)
		{
			if (this->m_EmpArray[i]->m_name == name)
			{
				count++;
				cout << "查找成功，找到的编号为" << m_EmpArray[i]->m_ID << "的姓名为" << name << "的职工的信息如下：" << endl;

				//调用信息接口
				this->m_EmpArray[i]->ShowInfo();
			}
		}
		cout << "共计找到" << count << "位名为" << name << "的员工" << endl;
		if (count == 0)
		{
			//未找到职工
			cout << "查找失败，查无此人" << endl;
		}
	}

	//清屏
	system("pause");
	system("cls");
}

//按照编号排序
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;

		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序方式" << endl;
		cout << "1、按照职工号升序排序" << endl;
		cout << "2、按照职工号升序排序" << endl;

		int select = 0;
		cin >> select;

		while (true)
		{
			if (select == 1 || select == 2)
			{
				break;
			}
			
		cout << "您的选择不符合题意，请重新选择排序方式" << endl;
		cout << "1、按照职工号升序排序" << endl;
		cout << "1、按照职工号降序排序" << endl;
		cin >> select;
		}

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;//声明最小或者最大值
			for (int j = i + 1; j < m_EmpNum; j++)
			{


				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
				else//降序
				{
					if (this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
			}			
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}

		cout << "排序成功！排序后的结果为：" << endl;
		//将排序后的结果保存到文件中
		this->save();
		//展示所有的职工
		this->Show_Emp();
	}
}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "确定清空？" << endl;
	cout << "1、确定" << endl;
	cout << "输入其他都默认否定" << endl;

	int select;
	cin >> select;

	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
			
					delete this->m_EmpArray[i];		
				//	this->m_EmpArray[i] = nullptr;
				}
			}
			//删除堆区数组
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}

		cout << "清空成功" << endl;
	}

	//清屏
	system("pause");
	system("cls");

}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL) {
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete[] this->m_EmpArray[i];
			}
		}
		delete this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
