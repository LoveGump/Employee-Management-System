#include<iostream>
using namespace std;
#include"WorkerManager.h"


#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"

int main()
{
	////���Դ���
	//Worker* worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->ShowInfo();
	//delete worker;


	//worker = new Manager(2, "����", 2);
	//worker->ShowInfo();
	//delete worker;


	//worker = new Boss(3, "����", 3);
	//worker->ShowInfo();
	//delete worker;
	


	
	//ʵ���������߶���

	WorkerManager wm;
	
	int choice = 0;//�洢ѡ��
	while (true)
	{
		wm.Show_Menu();
		cout << "��ѡ�����ǰ������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1: //���ְ��
			wm.add_Emp();
			break;
		case 2: //��ʾְ��
			wm.Show_Emp();
			break;			
		case 3: //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4: //�޸�ְ��
			break;
		case 5: //����ְ��
			break;
		case 6: //����ְ��
			break;
		case 7: //����ļ�
			break;
		default:
			system("cls");
			break;
		}

	}

	return 0;
}