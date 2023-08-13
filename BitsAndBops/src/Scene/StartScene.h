#pragma once
#include "Scene.h"
#include "Math/vector.h"
class CStartScene : public CScene
{
	float tka;		//坦克角度
	CVector tkpos;	//坦克坐标
	float speed; 
	CVector pgoffPos; //炮管锚点 偏移量
	CVector Dir;

	float pga;		//炮管角度
	CVector pgoff;	//炮管锚点
	CVector pgpos;   //炮管的坐标
	CVector pgDir;      //炮管的向量
public:
	void Init();
	void Run();
	void End();
};