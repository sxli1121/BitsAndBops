#pragma once
#include "Core/Scene.h"
#include "Math/vector.h"
class CStartScene : public CScene
{
	float tka;		//坦克角度
	Vector tkpos;	//坦克坐标
	float speed; 
	Vector pgoffPos; //炮管锚点 偏移量
	Vector Dir;

	float pga;		//炮管角度
	Vector pgoff;	//炮管锚点
	Vector pgpos;   //炮管的坐标
	Vector pgDir;      //炮管的向量
public:
	void Init();
	void Run();
	void End();
};