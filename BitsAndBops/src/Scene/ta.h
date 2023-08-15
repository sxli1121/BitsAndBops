#pragma once
#include "Core/Scene.h"
//#include "GameObject/Hero.h"
#include "Tools/Timer.h"
//#include "OutputAndInput/RenderingPipline.h"
#include "OutputAndInput/Camera.h"

class CTestScene3:public CScene
{
	/*CHero a;
	TimerClock itep;

	RenderingPipline rp;
	Vector3D pos;
	float angle;

	Vector3D eye;
	Vector3D atDir;
	Vector3D up;*/

	Camera m_camera;
	
public:
	void Init();
	void Run();
	void End();
};

