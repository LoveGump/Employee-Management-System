#include"Employee.h"
using namespace std;





//���캯��
Employee:: Employee (int id, string name, int deptid)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_DeptID = deptid;
}
//��ʾ������Ϣ
void Employee::  ShowInfo() {
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_name
		<< "\tְ����λ��" << this->getDepthName()
		<< "\t��λְ����ɾ����ŵĹ���" << endl;
}
//��ȡ��λ����
string Employee::getDepthName() 
{

	return string("Ա��");
}
