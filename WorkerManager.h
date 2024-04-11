#pragma once //��ֹͷ�ļ��ظ�
#include<iostream>
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"

#include<fstream>
#define FILENAME "empFile.txt"

using namespace std;


class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//��ʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ���ĺ���
	void add_Emp();

	//�����ļ��õĺ���
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ���ְ������
	int get_EmpNum();

	//��ʼ��ְ��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//���ձ������
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//��������
	~WorkerManager();

};