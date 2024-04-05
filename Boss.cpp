#include"Boss.h"
using namespace std;

//构造函数
Boss::Boss(int id, string name, int deptid)
{
	this->m_ID = id;
	this->m_name = name;
	this->m_DeptID = deptid;
}
//显示个人信息
void Boss::ShowInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名：" << this->m_name
		<< "\t职工岗位：" << this->getDepthName()
		<< "\t岗位职责：管理公司，潇洒" << endl;

}
//获取岗位名称
string Boss::getDepthName()
{
	return string("Boss");
}
