#include"Boss.h"
using namespace std;

//���캯��
Boss::Boss(int id, string name, int deptid)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_DeptID = deptid;
}
//��ʾ������Ϣ
void Boss::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ��������" << this->m_name
		<< "\tְ����λ��" << this->getDepthName()
		<< "\t��λְ�𣺹���˾������" << endl;

}
//��ȡ��λ����
string Boss::getDepthName()
{
	return string("Boss");
}
