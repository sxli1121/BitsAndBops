#pragma once
#pragma once
#include <list>

class CTool;

class CHero;

class ToolManage
{
	std::list<CTool*> m_toolList;
	std::list<CTool*>::iterator it;

	static ToolManage* p;
	ToolManage();
	ToolManage(const ToolManage& that);

public:
	//����
	static ToolManage* GetToolManage();
	~ToolManage();
	bool AddTool(CTool* tool);               //��ӵ���
	bool T_ManageCollider(CHero* hero, int dir);       //��ײ
	void Reset_it();                             //�õ����ߵĵ�һ��
	CTool* GetToolData();                         //�õ�ÿһ�����ߵ�����
	void Run();                                  //��������ÿ������
	int GetToolsize();                            //���ߵĸ���
};

