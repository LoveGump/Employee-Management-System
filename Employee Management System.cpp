#include<iostream>
using namespace std;
#include"WorkerManager.h"


int main()
{

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
			break;
		case 2: //��ʾְ��
			break;
		case 3: //ɾ��ְ��
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