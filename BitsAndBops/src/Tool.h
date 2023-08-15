#pragma once
#include "Math/vector.h"
class CHero;
class CTool
{
protected:
	Vector m_pos;          //(子弹的向量)-需要(刚开始的向量-子弹与鼠标的单位向量) 刚开始的坐标-后续会持续改变
	Vector m_direction;     //后续移动的单位向量
	bool m_alive;          //存活标记
	const char* m_key;     //道具的图片
public:
	CTool();
	virtual ~CTool();
	void SetAct(bool b);       //设置蘑菇是否存在
	bool GetAct();       //设置蘑菇是否存在
	void SetPos(Vector v);
	void SetDirection(Vector v);
	Vector GetPos();
	virtual void Init();
	virtual void Run();
	virtual void End();
	virtual void ColliderFun(CHero* hero, int dir);   //每个子类有自己的碰撞方案
};
