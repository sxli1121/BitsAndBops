#include "FightScene.h"
#include "OutputAndInput/GameOutput.h"
#include<Windows.h>
void CFightScene::Init()
{
	CGameOutput* go = CGameOutput::GetGameOutput();
	go->AddImg("JK", "pic\\1.bmp");
	go->AddPic("รรืำ", "JK", 0, 0, 258, 297);
	x = 200;
	y = 300;
}

void CFightScene::Run()
{
	CGameOutput* go = CGameOutput::GetGameOutput();
	XFORM xm;
	xm.eM11 = 1;
	xm.eM22 = 1;
	//go->DrawPic("รรืำ",&xm);
}

void CFightScene::End()
{
}
