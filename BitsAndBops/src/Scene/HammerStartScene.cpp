#include "HammerStartScene.h"
#include "OutputAndInput/GameOutput.h"
#include "Audio/AudioManager.h"
#include "Math/Matrix.h"

void CHammerStart::Init()
{
	CGameOutput* gameoutput = CGameOutput::GetGameOutput();
	//进场
	gameoutput->AddImg("hammer_title_screen", "Assets / Textures/FristRound /Pic/hammer_time_title_screen.png");
	gameoutput->AddPic("hammer_title", "hammer_title_screen", 0, 0, 1920, 1080);
	//CAudioManager audio;
	//进场
	audio.PushOnceAudio("JingleDraft", "Assets/Audios/FristRound/JingleDraft.wav");
	//等待对话框时背景音
	audio.PushOnceAudio("construction_ambience", "Assets/Audios/FristRound/construction_ambience.wav");
	//对话框确认
	audio.PushLoopAudio("CatTurn", "Assets/Audios/FristRound/SFX_FS_CatTurn.wav");
	//教程
	audio.PushOnceAudio("Bits And Bops TUTORIAL 110", "Assets/Audios/FristRound/Bits And Bops TUTORIAL 110.wav");
	//钉子效果音效-击中
	audio.PushOnceAudio("SFX_HT_NailHammerHit", "Assets/Audios/FristRound/SFX_HT_NailHammerHit.wav");
	//错过倾斜
	audio.PushOnceAudio("SFX_HT_NailMissTilt", "Assets/Audios/FristRound/SFX_HT_NailMissTilt.wav");
	//稍微偏差
	audio.PushOnceAudio("SFX_HT_NailPlace", "Assets/Audios/FristRound/SFX_HT_NailPlace.wav");
}

void CHammerStart::Run()
{
	CGameOutput* gameoutput = CGameOutput::GetGameOutput();
	if (m_State == HAMMER_OPEN)
	{
		//开场
		//图片
		Matrix33 m;
		m.Translate(0, 0);
		gameoutput->DrawPic("hammer_title", &m);
		//音乐
		audio.PlayOnceAudio("JingleDraft");

		//获取时间- 时间确认 状态切换
	}
	else if (m_State == HAMMER_CONFIRM)
	{
		//确认
		//画面--（一样的背景与对话框）-（不同的文字）

		//gameoutput->DrawTxt();
		//音乐
		audio.PlayLoopAudio("CatTurn");
		
	}
	else if (m_State == HAMMER_TEACH)
	{
		//教学环节--有自己的数组


	}


}

void CHammerStart::End()
{

}
