#include "ToolManage.h"
#include "Tool.h"

ToolManage* ToolManage::p = nullptr;

ToolManage* ToolManage::GetToolManage()
{
	if (p == nullptr)
		p = new ToolManage;
	return p;
}

ToolManage::ToolManage()
{

}

ToolManage::~ToolManage()
{
	for (it = m_toolList.begin(); it != m_toolList.end(); ++it)
	{
		delete* it;
	}
}

bool ToolManage::AddTool(CTool* tool)
{
	if (tool == nullptr)   //空指针
		return false;
	m_toolList.push_back(tool);   //main函数申请堆内存 然后道具管理放入list中
	return 1;
}

bool ToolManage::T_ManageCollider(CHero* hero, int dir)
{
	return 1;
}

void ToolManage::Reset_it()
{
	it = m_toolList.begin();
}

CTool* ToolManage::GetToolData()
{
	if (it == m_toolList.end())      //先判断it指向的位置 后赋值
		it = m_toolList.begin();
	CTool* tool = *it;           //每个道具的数据（父类中的数据） 返回
	it++;
	return tool;
}

void ToolManage::Run()
{
	std::list<CTool*>::iterator it; //迭代器 

	for (it = m_toolList.begin(); it != m_toolList.end(); )
	{
		if ((*it)->GetAct())
		{
			(*it)->Run();   //run 每一个道具
			++it;
		}
		else
		{
			delete* it;
			it = m_toolList.erase(it);
		}
	}
}

int ToolManage::GetToolsize()
{
	return m_toolList.size();
}
