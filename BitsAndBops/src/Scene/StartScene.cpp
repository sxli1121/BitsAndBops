#include "StartScene.h"
#include "OutputAndInput/GameOutput.h"
#include "OutputAndInput/GameInput.h"
#include "Core/FrameWork.h"
#include "Math/vector.h"
#include "Math/Matrix.h"
void CStartScene::Init()
{
	CGameOutput* output = CGameOutput::GetGameOutput();
	//背景
	output->AddImg("cover_bg", "Assets/Textures/StartScreen/Opening/cover_bg.png");
	output->AddPic("cover_bg", "cover_bg", 0, 0, 2048, 1152);
	//图标
	output->AddImg("cover_bg_logo_only_transparent", "Assets/Textures/StartScreen/Opening/cover_bg_logo_only_transparent.png");
	output->AddPic("cover_bg_logo_only_transparent", "cover_bg_logo_only_transparent", 0, 0, 772, 489);
	//动漫人物
	output->AddImg("cover_birbs", "Assets/Textures/StartScreen/Opening/cover_birbs.png");
	output->AddPic("cover_birbs", "cover_birbs", 0, 0, 217, 146);
	output->AddImg("cover_boybear", "Assets/Textures/StartScreen/Opening/cover_boybear.png");
	output->AddPic("cover_boybear", "cover_boybear", 0, 0, 450, 573);
	output->AddImg("cover_catto", "Assets/Textures/StartScreen/Opening/cover_catto.png");
	output->AddPic("cover_catto", "cover_catto", 0, 0, 541, 781);
	output->AddImg("cover_dancer", "Assets/Textures/StartScreen/Opening/cover_dancer.png");
	output->AddPic("cover_dancer", "cover_dancer", 0, 0, 699, 1043);
	output->AddImg("cover_girlbear", "Assets/Textures/StartScreen/Opening/cover_girlbear.png");
	output->AddPic("cover_girlbear", "cover_girlbear", 0, 0, 587, 707);
	output->AddImg("cover_mascots", "Assets/Textures/StartScreen/Opening/cover_mascots.png");
	output->AddPic("cover_mascots", "cover_mascots", 0, 0, 626, 519);
	output->AddImg("cover_moleleft", "Assets/Textures/StartScreen/Opening/cover_moleleft.png");
	output->AddPic("cover_moleleft", "cover_moleleft", 0, 0, 529, 261);
	output->AddImg("cover_moleright", "Assets/Textures/StartScreen/Opening/cover_moleright.png");
	output->AddPic("cover_moleright", "cover_moleright", 0, 0, 328, 334);
	output->AddImg("cover_monke", "Assets/Textures/StartScreen/Opening/cover_monke.png");
	output->AddPic("cover_monke", "cover_monke", 0, 0, 263, 271);
	output->AddImg("cover_robot", "Assets/Textures/StartScreen/Opening/cover_robot.png");
	output->AddPic("cover_robot", "cover_robot", 0, 0, 413, 682);
	output->AddImg("cover_snakecharmer", "Assets/Textures/StartScreen/Opening/cover_snakecharmer.png");
	output->AddPic("cover_snakecharmer", "cover_snakecharmer", 0, 0, 379, 472);

	off = 0.4f;
	dtnum = 0;
}

void CStartScene::Update(float dt)
{
	CGameOutput* output = CGameOutput::GetGameOutput();
	//Matrix33  rm, sm;
	Matrix33 m = Matrix33::S(0.5f, 0.5f) * Matrix33::T(0, 0);
	output->DrawPic("cover_bg",&m);
	m = Matrix33::S(off, off) * Matrix33::T(287,10);
	output->DrawPic("cover_bg_logo_only_transparent", &m);
	m = Matrix33::S(off, off) * Matrix33::T(700, 10);
	output->DrawPic("cover_birbs", &m);
	m = Matrix33::S(0.5f, 0.5f) * Matrix33::T(750, 100);
	output->DrawPic("cover_boybear", &m);
	

	//m = Matrix33::S(0.5f, 0.5f) * Matrix33::T(750, 100);
	//output->DrawPic("cover_girlbear", &m);
	//m = Matrix33::S(0.5f, 0.5f) * Matrix33::T(750, 100);
	//output->DrawPic("cover_catto", &m);
	//m = Matrix33::S(0.5f, 0.5f) * Matrix33::T(750, 100);
	//output->DrawPic("cover_catto", &m);
	//m = Matrix33::S(0.5f, 0.5f) * Matrix33::T(750, 100);
	//output->DrawPic("cover_catto", &m);
	//m = Matrix33::S(0.5f, 0.5f) * Matrix33::T(750, 100);
	//output->DrawPic("cover_catto", &m);

	m = Matrix33::S(0.5f, 0.5f) * Matrix33::T(0, 20);
	output->DrawPic("cover_dancer", &m);


	m = Matrix33::S(0.5f, 0.5f) * Matrix33::T(700, 150);
	output->DrawPic("cover_catto", &m);
}

void CStartScene::End()
{
	
}
