//#include "TestSence.h"
//#include "GameOutput.h"
//#include "GameInput.h"
//#include "Matrix.h"
//#include <iostream>
//void CTestScene::Init()
//{
//	CGameOutput* go = CGameOutput::GetGameOutput();
//	//3组动画-英雄类中
//	m_Am = new Animation[3];
//	m_Amlen = 3;
//	m_AmIndex = 0;
//	//设置字体大小
//	go->SetFont(30, 50);
//
//	//当前动画（初始开始）-不演示
//	m_curAm = 0;
//	m_IsMove = false;
//	m_pic1 = 1;
//	m_pic2 = 0;
//
//
//	x = 500;
//	y = 700;
//	speed = 1;
//
//	char key[128];
//	char fn[128];
//	//idle
//	for (int i = 0; i < 12; i++)
//	{
//		//%02d  表示- 替换之后固定是2位   不够前面添0
//		//将8+i 替换到 pic\\00%d.bmp中 赋值到fn中-最长128
//		sprintf_s(fn,128,"pic\\站立\\00%d.bmp",8+i);
//		sprintf_s(key, 128, "idle%d", i);
//		go->AddImg(key, fn);
//	}
//
//	go->AddBmp("idle0", "idle0",0,0,241,286,0);
//	go->AddBmp("idle1", "idle1",0,0,241,286,0);
//	go->AddBmp("idle2", "idle2",0,0,240,287,0);
//	go->AddBmp("idle3", "idle3",0,0,239,288,0);
//	go->AddBmp("idle4", "idle4",0,0,240,289,0);
//	go->AddBmp("idle5", "idle5",0,0,241,290,0);
//	go->AddBmp("idle6", "idle6",0,0,241,290,0);
//	go->AddBmp("idle7", "idle7",0,0,241,290,0);
//	go->AddBmp("idle8", "idle8",0,0,243,289,0); 
//	go->AddBmp("idle9", "idle9",0,0,243,288,0);
//	go->AddBmp("idle10","idle10",0,0,243,287,0);
//	go->AddBmp("idle11","idle11",0,0,241,286,0);
//	m_Am[0].Init();
//	m_Am[0].AddAnmiationPic("idle0", 0, 0, 3);
//	m_Am[0].AddAnmiationPic("idle1", 0, 0, 3);
//	m_Am[0].AddAnmiationPic("idle2", 0, 0, 3);
//	m_Am[0].AddAnmiationPic("idle3", 0, 0, 3);
//	m_Am[0].AddAnmiationPic("idle4", 0, 0, 3);
//	m_Am[0].AddAnmiationPic("idle5", 0, 0, 3);
//	m_Am[0].AddAnmiationPic("idle6", 0, 0, 3);
//	m_Am[0].AddAnmiationPic("idle7", 0, 0, 3);
//	m_Am[0].AddAnmiationPic("idle8", 0, 0, 3);
//	m_Am[0].AddAnmiationPic("idle9", 0, 0, 3);
//	m_Am[0].AddAnmiationPic("idle10", 0, 0, 3);
//	m_Am[0].AddAnmiationPic("idle11", 0, 0, 3);
//
//	//move
//	for (int i = 0; i < 12; ++i)
//	{
//		sprintf_s(fn, 128, "pic\\走\\00%d.bmp", 24 + i);
//		sprintf_s(key, 128, "move%d", i);
//		go->AddImg(key, fn);
//	}
//
//	go->AddBmp("move0", "move0", 0, 0, 247, 289, 0);
//	go->AddBmp("move1", "move1", 0, 0, 241, 293, 0);
//	go->AddBmp("move2", "move2", 0, 0, 238, 296, 0);
//	go->AddBmp("move3", "move3", 0, 0, 234, 297, 0);
//	go->AddBmp("move4", "move4", 0, 0, 238, 296, 0);
//	go->AddBmp("move5", "move5", 0, 0, 259, 293, 0);
//	go->AddBmp("move6", "move6", 0, 0, 254, 289, 0);
//	go->AddBmp("move7", "move7", 0, 0, 241, 293, 0);
//	go->AddBmp("move8", "move8", 0, 0, 238, 296, 0);
//	go->AddBmp("move9", "move9", 0, 0, 234, 297, 0);
//	go->AddBmp("move10", "move10", 0, 0, 238, 296, 0);
//	go->AddBmp("move11", "move11", 0, 0, 254, 231, 0);
//	m_Am[1].Init();
//	//参照标准
//	m_Am[0].AddAnmiationPic("idle0", 0, 0, 3);
//	m_Am[1].AddAnmiationPic("move0", 0, 0, 3);
//	m_Am[1].AddAnmiationPic("move1", 0, 0, 3);
//	m_Am[1].AddAnmiationPic("move2", 0, 0, 3);
//	m_Am[1].AddAnmiationPic("move3", 0, 0, 3);
//	m_Am[1].AddAnmiationPic("move4", 0, 0, 3);
//	m_Am[1].AddAnmiationPic("move5", 0, 0, 3);
//	m_Am[1].AddAnmiationPic("move6", 0, 0, 3);
//	m_Am[1].AddAnmiationPic("move7", 0, 0, 3);
//	m_Am[1].AddAnmiationPic("move8", 0, 0, 3);
//	m_Am[1].AddAnmiationPic("move9", 0, 0, 3);
//	m_Am[1].AddAnmiationPic("move10", 0, 0, 3);
//	m_Am[1].AddAnmiationPic("move11", 0, 0, 3);
//
//	//attack
//	for (int i = 0; i < 9; ++i) 
//	{
//		sprintf_s(fn, 128, "pic\\踢\\02%d.bmp", 25 + i);
//		sprintf_s(key, 128, "attack%d", i);
//		go->AddImg(key, fn);
//	}
//	go->AddBmp("attack0", "attack0", 0, 0, 241, 274, 0);
//	go->AddBmp("attack1", "attack1", 0, 0, 241, 270, 0);
//	go->AddBmp("attack2", "attack2", 0, 0, 247, 263, 0);
//	go->AddBmp("attack3", "attack3", 0, 0, 336, 265, 0);
//	go->AddBmp("attack4", "attack4", 0, 0, 244, 268, 0);
//	go->AddBmp("attack5", "attack5", 0, 0, 243, 278, 0);
//	go->AddBmp("attack6", "attack6", 0, 0, 241, 268, 0);
//	go->AddBmp("attack7", "attack7", 0, 0, 241, 268, 0);
//	go->AddBmp("attack8", "attack8", 0, 0, 240, 287, 0);
//	m_Am[2].Init();
//	m_Am[0].AddAnmiationPic("idle0", 0, 0, 3);
//	m_Am[2].AddAnmiationPic("attack0", 0, 0, 3);
//	m_Am[2].AddAnmiationPic("attack1", 0, 0, 3);
//	m_Am[2].AddAnmiationPic("attack2", 0, 0, 3);
//	m_Am[2].AddAnmiationPic("attack3", 0, 0, 3);
//	m_Am[2].AddAnmiationPic("attack4", 0, 0, 3);
//	m_Am[2].AddAnmiationPic("attack5", 0, 0, 3);
//	m_Am[2].AddAnmiationPic("attack6", 0, 0, 3);
//	m_Am[2].AddAnmiationPic("attack7", 0, 0, 3);
//	m_Am[2].AddAnmiationPic("attack8", 0, 0, 3);
//
//}
//
//void CTestScene::Run()
//{
//	//绘制地面
//	CGameOutput* go = CGameOutput::GetGameOutput();
//	CGameInput* gi = CGameInput::GetGameInput();
//	PIC_InAnimation* pic1 = m_Am[m_AmIndex].GetPic(m_pic1);
//	if (m_IsMove == false)
//	{
//		PIC_InAnimation* pic2 = m_Am[m_AmIndex].GetPic(m_pic2);
//
//		CMatrix33 m;
//		m.Translate(x + pic2->off_x, y + pic2->off_y);
//		go->DrawBmp(pic2->bmp_key, &m);
//		m.Translate(x + pic1->off_x, y + pic1->off_y);
//		go->DrawBmp(pic1->bmp_key, &m);
//		//速度比较慢的时候-精细检测
//		if (speed == 1)
//		{
//			if (gi->GetState(_GI_K_W) == _KS_DC)
//				pic1->off_y -= speed;
//			else if (gi->GetState(_GI_K_S) == _KS_DC)
//				pic1->off_y += speed;
//			if (gi->GetState(_GI_K_A) == _KS_DC)
//				pic1->off_x -= speed;
//			else if (gi->GetState(_GI_K_D) == _KS_DC)
//				pic1->off_x += speed;
//		}
//		//速度较大的时候-只要按下就操作
//		else
//		{
//			if (gi->GetKeyDown(_GI_K_W))
//				pic1->off_y -= speed;
//			else if (gi->GetKeyDown(_GI_K_S))
//				pic1->off_y += speed;
//			if (gi->GetKeyDown(_GI_K_A))
//				pic1->off_x -= speed;
//			else if (gi->GetKeyDown(_GI_K_D))
//				pic1->off_x += speed;
//		}
//		if (gi->GetState(_GI_K_SPACE) == _KS_DC)
//			speed = 10;
//		//放开的时候速度减慢
//		else if (gi->GetState(_GI_K_SPACE) == _KS_UC)
//			speed = 1;
//
//
//		//切换图片-
//		if (gi->GetState(_GI_K_LEFT) == _KS_DC)		{
//			m_pic1 -= 1;
//			//p1越界
//			if (m_pic1 < 0)
//				m_pic1 = m_Am[m_AmIndex].GetSize() - 1;
//			m_pic2 = m_pic1 - 1;
//			//p2越界-p1是第一个
//			if (m_pic2 < 0)
//				m_pic2 = m_Am[m_AmIndex].GetSize() - 1;
//		}
//		else if (gi->GetState(_GI_K_RIGHT) == _KS_DC)
//		{
//			m_pic1 += 1;
//			//p1越界
//			if (m_pic1 > m_Am[m_AmIndex].GetSize() - 1)
//				m_pic1 = 0;
//			m_pic2 = m_pic1 - 1;
//			//p2越界-p1是第一个
//			if (m_pic2 < 0)
//				m_pic2 = m_Am[m_AmIndex].GetSize() - 1;
//		}
//
//		//切换动画组
//		if (gi->GetState(_GI_K_UP) == _KS_DC)
//		{
//			m_AmIndex += 1;
//			if (m_AmIndex >= m_Amlen)
//				m_Amlen = 0;
//			//如果每组动画的图片数量不同-从第一张开始播放
//			m_pic1 = 0;
//			m_pic2 = m_Am[m_AmIndex].GetSize() - 1;
//		}
//		else if (gi->GetState(_GI_K_DOWN) == _KS_DC)
//		{
//			m_AmIndex -= 1;
//			if (m_AmIndex < 0)
//				m_Amlen = m_Amlen - 1;
//			//如果每组动画的图片数量不同-从第一张开始播放
//			m_pic1 = 0;
//			m_pic2 = m_Am[m_AmIndex].GetSize() - 1;
//		}
//	}
//	else
//	{
//		//动画播放状态为true
//		CMatrix33 m;
//		m.Translate(x, y);
//		m_Am[m_AmIndex].SetMatrix(&m);
//
//		m_Am[m_AmIndex].Run();
//		if (m_Am[m_AmIndex].GetAnimationState() == AM_STOP)
//		{
//			m_Am[m_AmIndex].Animation_RePlay();
//		}
//
//	}
//	//m按下的时候-动画的运行状态改变
//	if (gi->GetState(_GI_K_M) == _KS_DC)
//	{
//		m_IsMove = !m_IsMove;
//		//设置从哪里开始播放-播放状态
//		if (m_IsMove)
//		{
//			m_Am[m_AmIndex].SetCurPic(m_pic1);
//			m_Am[m_AmIndex].Animation_Playing();
//		}
//		else
//		{
//			//设置显示为当前的播放图片-暂停
//			m_pic1 = m_Am[m_AmIndex].GetCurIndex();
//			m_pic2 = m_pic1 - 1;
//			if (m_pic2 < 0)
//				m_pic2 = m_Am[m_AmIndex].GetSize() - 1;
//			m_Am[m_AmIndex].Animation_Stop();
//		}
//
//	}
//
//	char buf[64];
//	sprintf_s(buf, 64, "i=%d, x=%d, y=%d", m_pic1, pic1->off_x, pic1->off_y);
//	go->DrawTxt(10, 20, buf, RGB(200, 80, 200), 64);
//	go->DrawRect(x, y, 3, 3, 3, RGB(255, 0, 0));
//	go->DrawLine(0, y, 1000, y, 1, RGB(83, 139, 154));
//
//
//}
//
//void CTestScene::End()
//{
//}
