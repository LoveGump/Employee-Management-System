#include"Manager.h"


//���캯��
Manager::Manager(int id, string name, int deptid)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_DeptID = deptid;
}
//��ʾ������Ϣ
void Manager::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_name
		<< "\tְ����λ��"<< this->getDepthName()
		<< "\t��λְ�����Boss���ŵĹ��������·��������ͨԱ��" << endl;

}
//��ȡ��λ����
string Manager::getDepthName()
{
	return string("Manager");
}
