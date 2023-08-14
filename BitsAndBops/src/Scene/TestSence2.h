#pragma once
#include "Core/Scene.h"
#include "Math/Rect.h"
#include "Animation/Animation.h"

class CTestScene2 :public CScene
{
	//全部动画
	Animation* m_Am;
	//有几个动画-动画组的数量
	int m_Amlen;
	//当前动画是哪个 
	Animation* m_curAm;
	//当前动画是第几组
	int m_AmIndex;
	//需要调整的图片下标
	int m_pic1;
	//参照图片下标
	int m_pic2;
	//动画是否在演示
	bool m_IsMove;


	int x;
	int y;
	int speed;
public:
	void Init();
	void Run();
	void End();
};




//镜像-加载图片时候就做镜像
//两个DC  (注意结合素材)
//整合素材-中心点可以直接镜像 pw(整图宽度) - x(镜像前的x) ////左上角 pw(整图宽度) - x(镜像前的x)   -w(小图片大小) +1
//先计算中心点-锚点与中心点计算（偏移量x取反）


 


//行为-类