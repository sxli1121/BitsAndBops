#include "ta.h"
#include "TestSence2.h"
#include "OutputAndInput/GameOutput.h"
#include "OutputAndInput/GameInput.h"
#include "Math/Matrix.h"
#include "OutputAndInput/Camera.h"
//#include "GameObject/Hero.h"
#include <iostream>

#include "Time.h"
void CTestScene3::Init()
{
	//eye = Vector3D(0, 0, -1000); 
	////at = eye;
	//atDir.z= 1;

	CGameOutput* go = CGameOutput::GetGameOutput();

	go->AddImg("1", "Assets/Textures/1.png");
	go->AddPic("c", "1", 0, 0, 1920, 1080);
	//rp.SetViewMatrix(1000, 800);
	//rp.SetCameraMatrix(Vector3D(0,0,-200),eye+ atDir,Vector3D(0,1,0));

}

void CTestScene3::Run()
{
	CGameOutput* go = CGameOutput::GetGameOutput();
	Camera m_camera;
	m_camera.SetAngle(45);
	go->SetCamera(&m_camera);
	
	//m_camera.CameraMove();
	Matrix33 tm = Matrix33::MakeTranslate(0, 0);
	go->DrawPic("c",&tm);

	//rp.SetCameraMatrix(eye, eye+ atDir, up);
	 
}

void CTestScene3::End()
{

}
