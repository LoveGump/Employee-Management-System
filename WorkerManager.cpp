#include"WorkerManager.h"


WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ����־ �ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ����־ �ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.�ļ����� ���Ҽ�¼������
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ" << num << endl;
	this->m_EmpNum = num;
	this->m_FileIsEmpty = false;
	//���ٿռ䣬
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݣ��浽������
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_ID
	//		<< "\tְ��������" << this->m_EmpArray[i]->m_name
	//		<< "\tְ��ְλ��" << this->m_EmpArray[i]->m_DeptID << endl;
	//}

}
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//�˳�����
void WorkerManager::ExitSystem() 
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����

}

//���ְ��
void WorkerManager::add_Emp()
{
	cout << "���������Ա��������" << endl;
	int add_Num;
	cin >> add_Num;
	if (add_Num > 0)
	{
		//���
		//��������¿ռ�Ĵ�С
		int new_Size = this->m_EmpNum + add_Num;

		//�����¿ռ�
		Worker** new_Space = new Worker * [new_Size];

		//��ԭ���ռ��µ����ݷ����¿ռ���
		if (this->m_EmpNum != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				new_Space[i] = this->m_EmpArray[i];

			}

		}
		//�����������
		for (int i = 0; i < add_Num; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��

			cout << "�������" << i + 1 << "��ְ���ı��" << endl;
			cin >> id;
			if (this->IsExist(id) != -1) {
				cout << "�������ְ������Ѿ����ڣ�����������" << endl;
				i -= 1;
				break;
			}
			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���Ա����ְλ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

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
				cout << " " << endl;
				break;
			}

			//������ְ��ָ�룬������������
			new_Space[this->m_EmpNum + i] = worker;

		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//����ָ��ָ��
		this->m_EmpArray = new_Space;

		//����ְ������
		this->m_EmpNum = new_Size;

		//����ְ����Ϊ�յı�־
		this->m_FileIsEmpty = false;
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << add_Num << "��ְ��" << endl;

		//�������ݵ��ļ���
		this->save();

		//������������������ϼ�Ŀ¼
		system("pause");
		system("cls");

	}
	else
	{
		cout<<"������������"<<endl;
	}

}

//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ� --д�ļ�
	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " " 
			<< this->m_EmpArray[i]->m_name << " "
			<< m_EmpArray[i]->m_DeptID << endl;
	}

	//�ر��ļ�
	ofs.close();

}

//ͳ���ļ���ְ������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ� ��

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//ͳ����������
		num++;
	}
	return num;
}

//��ʼ��ְ��
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
	//�ر��ļ�
	ifs.close();
}

//��ʾְ��
void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ�������
	if (this->m_EmpNum == 0)
	{
		cout << "����Ϊ�գ�����" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->ShowInfo();

		}

	}

	//�����������
	system("pause");
	system("cls");

}

//����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) 
	{
		index = i;
	}
	return index;
}

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "����������ɾ��ְ���ı��" << endl;
		int  id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			//����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				delete[] this->m_EmpArray[i];

				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//���������м�¼����Ա����
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL) {
		delete this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
