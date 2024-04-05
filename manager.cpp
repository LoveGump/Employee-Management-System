#include"Manager.h"


//构造函数
Manager::Manager(int id, string name, int deptid)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_DeptID = deptid;
}
//显示个人信息
void Manager::ShowInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_name
		<< "\t职工岗位："<< this->getDepthName()
		<< "\t岗位职责：完成Boss安排的工作，并下发任务给普通员工" << endl;

}
//获取岗位名称
string Manager::getDepthName()
{
	return string("Manager");
}
