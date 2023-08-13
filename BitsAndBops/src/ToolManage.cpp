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
	if (tool == nullptr)   //��ָ��
		return false;
	m_toolList.push_back(tool);   //main����������ڴ� Ȼ����߹������list��
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
	if (it == m_toolList.end())      //���ж�itָ���λ�� ��ֵ
		it = m_toolList.begin();
	CTool* tool = *it;           //ÿ�����ߵ����ݣ������е����ݣ� ����
	it++;
	return tool;
}

void ToolManage::Run()
{
	std::list<CTool*>::iterator it; //������ 

	for (it = m_toolList.begin(); it != m_toolList.end(); )
	{
		if ((*it)->GetAct())
		{
			(*it)->Run();   //run ÿһ������
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
