#include "ta.h"
#include "TestSence2.h"
#include "GameOutput.h"
#include "GameInput.h"
#include "Math/Matrix.h"
#include "GameObject/Hero.h"
#include <iostream>

#include "Time.h"
void CTestScene3::Init()
{
	CGO* go = CGO::GetGO();

	//char key[128];
	//char fn[128];
	//a.Init();
	//a.SetX(100);
	//a.SetY(600);
	////idle
	//for (int i = 0; i < 12; i++)
	//{
	//	//%02d  表示- 替换之后固定是2位   不够前面添0
	//	//将8+i 替换到 pic\\00%d.bmp中 赋值到fn中-最长128
	//	sprintf_s(fn, 128, "pic\\站立\\00%d.bmp", 8 + i);
	//	sprintf_s(key, 128, "idle%d", i);
	//	go->AddImg(key, fn);
	//}

	//go->AddBmp("idle0", "idle0", 0, 0, 241, 286, 0);
	//go->AddBmp("idle1", "idle1", 0, 0, 241, 286, 0);
	//go->AddBmp("idle2", "idle2", 0, 0, 240, 287, 0);
	//go->AddBmp("idle3", "idle3", 0, 0, 239, 288, 0);
	//go->AddBmp("idle4", "idle4", 0, 0, 240, 289, 0);
	//go->AddBmp("idle5", "idle5", 0, 0, 241, 290, 0);
	//go->AddBmp("idle6", "idle6", 0, 0, 241, 290, 0);
	//go->AddBmp("idle7", "idle7", 0, 0, 241, 290, 0);
	//go->AddBmp("idle8", "idle8", 0, 0, 243, 289, 0);
	//go->AddBmp("idle9", "idle9", 0, 0, 243, 288, 0);
	//go->AddBmp("idle10", "idle10", 0, 0, 243, 287, 0);
	//go->AddBmp("idle11", "idle11", 0, 0, 241, 286, 0);
	////move
	//for (int i = 0; i < 12; ++i)
	//{
	//	sprintf_s(fn, 128, "pic\\走\\00%d.bmp", 24 + i);
	//	sprintf_s(key, 128, "move%d", i);
	//	go->AddImg(key, fn);
	//}

	//go->AddBmp("move0", "move0", 0, 0, 247, 289, 0);
	//go->AddBmp("move1", "move1", 0, 0, 241, 293, 0);
	//go->AddBmp("move2", "move2", 0, 0, 238, 296, 0);
	//go->AddBmp("move3", "move3", 0, 0, 234, 297, 0);
	//go->AddBmp("move4", "move4", 0, 0, 238, 296, 0);
	//go->AddBmp("move5", "move5", 0, 0, 259, 293, 0);
	//go->AddBmp("move6", "move6", 0, 0, 254, 289, 0);
	//go->AddBmp("move7", "move7", 0, 0, 241, 293, 0);
	//go->AddBmp("move8", "move8", 0, 0, 238, 296, 0);
	//go->AddBmp("move9", "move9", 0, 0, 234, 297, 0);
	//go->AddBmp("move10", "move10", 0, 0, 238, 296, 0);
	//go->AddBmp("move11", "move11", 0, 0, 254, 231, 0);


	////attack
	//for (int i = 0; i < 9; ++i)
	//{
	//	sprintf_s(fn, 128, "pic\\踢\\02%d.bmp", 25 + i);
	//	sprintf_s(key, 128, "attack%d", i);
	//	go->AddImg(key, fn);
	//}
	//go->AddBmp("attack0", "attack0", 0, 0, 241, 274, 0);
	//go->AddBmp("attack1", "attack1", 0, 0, 241, 270, 0);
	//go->AddBmp("attack2", "attack2", 0, 0, 247, 263, 0);
	//go->AddBmp("attack3", "attack3", 0, 0, 336, 265, 0);
	//go->AddBmp("attack4", "attack4", 0, 0, 244, 268, 0);
	//go->AddBmp("attack5", "attack5", 0, 0, 243, 278, 0);
	//go->AddBmp("attack6", "attack6", 0, 0, 241, 268, 0);
	//go->AddBmp("attack7", "attack7", 0, 0, 241, 268, 0);
	//go->AddBmp("attack8", "attack8", 0, 0, 240, 287, 0);

	//go->AddImg("b1", "pic\\1.bmp");
	//go->AddBmp("b1", "b1", 0, 0, 2037, 281, 0);
	//go->AddImg("b2", "pic\\2.bmp");
	//go->AddBmp("b2", "b2", 0, 0, 2043, 153, 0);
	//go->AddImg("b3", "pic\\3.bmp");
	//go->AddBmp("b3", "b3", 0, 0, 2037, 205, 0);
	//go->AddImg("bg", "pic\\b.bmp");
	//go->AddBmp("bg", "bg", 0, 0, 2017, 751, 0);

	go->AddImg("1", "assets/1.png");
	go->AddPic("c", "1", 0, 0, 1920, 1080);

}

void CTestScene3::Run()
{
	CGO* go = CGO::GetGO();
	//CMatrix33 m ,sm;
	//m.Translate(0, 0);
	//sm.Scale(0.5,0.5);
	//m = sm * m;
	go->DrawFront("c",0,0,2);
	go->End();

	////场景的大小-（继承）
	//int w = 4000;
	//int h = 800;
	//CGO* go = CGO::GetGO();
	//a.Run();
	////英雄的位置
	//int x = a.GetX();
	//int y = a.GetY();
	////窗口的位置
	//x = x - 500;
	//y = y - 400;
	////设置窗口
	//if (x < 0)
	//	x = 0;
	//else if (x > w - 1000)
	//	x = w - 1000;
	//if (y < 0)
	//	y = 0;
	//else if (y > h - 800)
	//	y = h - 800;
	//
	//go->SetCXCy(x,y);
	//
	//go->DrawDistantView("b1", 0, 350, DISTANT_VIEW2, 0.6f);
	//go->DrawDistantView("b2", 0, 500, DISTANT_VIEW2, 0.8f);
	//go->DrawDistantView("b3", 0, 600, DISTANT_VIEW2, 1.0f);
	//go->DrawDistantView("bg", 0, 0, DISTANT_VIEW1, 0.3f);

}

void CTestScene3::End()
{

}
