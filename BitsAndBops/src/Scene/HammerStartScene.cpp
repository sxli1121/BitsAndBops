#include "HammerStartScene.h"
#include "OutputAndInput/GameOutput.h"
#include "Audio/AudioManager.h"
#include "Math/Matrix.h"

void CHammerStart::Init()
{
	CGameOutput* gameoutput = CGameOutput::GetGameOutput();
	//����
	gameoutput->AddImg("hammer_title_screen", "Assets / Textures/FristRound /Pic/hammer_time_title_screen.png");
	gameoutput->AddPic("hammer_title", "hammer_title_screen", 0, 0, 1920, 1080);
	//CAudioManager audio;
	//����
	audio.PushOnceAudio("JingleDraft", "Assets/Audios/FristRound/JingleDraft.wav");
	//�ȴ��Ի���ʱ������
	audio.PushOnceAudio("construction_ambience", "Assets/Audios/FristRound/construction_ambience.wav");
	//�Ի���ȷ��
	audio.PushLoopAudio("CatTurn", "Assets/Audios/FristRound/SFX_FS_CatTurn.wav");
	//�̳�
	audio.PushOnceAudio("Bits And Bops TUTORIAL 110", "Assets/Audios/FristRound/Bits And Bops TUTORIAL 110.wav");
	//����Ч����Ч-����
	audio.PushOnceAudio("SFX_HT_NailHammerHit", "Assets/Audios/FristRound/SFX_HT_NailHammerHit.wav");
	//�����б
	audio.PushOnceAudio("SFX_HT_NailMissTilt", "Assets/Audios/FristRound/SFX_HT_NailMissTilt.wav");
	//��΢ƫ��
	audio.PushOnceAudio("SFX_HT_NailPlace", "Assets/Audios/FristRound/SFX_HT_NailPlace.wav");
}

void CHammerStart::Run()
{
	CGameOutput* gameoutput = CGameOutput::GetGameOutput();
	if (m_State == HAMMER_OPEN)
	{
		//����
		//ͼƬ
		Matrix33 m;
		m.Translate(0, 0);
		gameoutput->DrawPic("hammer_title", &m);
		//����
		audio.PlayOnceAudio("JingleDraft");

		//��ȡʱ��- ʱ��ȷ�� ״̬�л�
	}
	else if (m_State == HAMMER_CONFIRM)
	{
		//ȷ��
		//����--��һ���ı�����Ի���-����ͬ�����֣�

		//gameoutput->DrawTxt();
		//����
		audio.PlayLoopAudio("CatTurn");
		
	}
	else if (m_State == HAMMER_TEACH)
	{
		//��ѧ����--���Լ�������


	}


}

void CHammerStart::End()
{

}
