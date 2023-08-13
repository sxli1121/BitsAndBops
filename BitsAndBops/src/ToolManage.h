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
	//单例
	static ToolManage* GetToolManage();
	~ToolManage();
	bool AddTool(CTool* tool);               //添加道具
	bool T_ManageCollider(CHero* hero, int dir);       //碰撞
	void Reset_it();                             //拿到道具的第一个
	CTool* GetToolData();                         //拿到每一个道具的数据
	void Run();                                  //用来遍历每个道具
	int GetToolsize();                            //道具的个数
};

