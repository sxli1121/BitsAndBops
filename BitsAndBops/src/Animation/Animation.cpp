#include "Animation.h"

#include <cassert>

void Animation::AddAnmiationPic(const char* BmpKey, int off_x, int off_y, int PresisitenceFre)
{
	//此处不做任何检测 如果传进来的图片为空的话 这一帧就不画
	PIC_InAnimation pic;
	pic.bmp_key = BmpKey;
	pic.off_x = off_x;
	pic.off_y = off_y;
	pic.PresistenceFra = PresisitenceFre;

	m_PicList.push_back(pic);
	m_size += 1;
}

int Animation::GetAnimationState()
{
	return m_state;
}

PIC_InAnimation* Animation::GetCurPic()
{
	return &m_PicList[m_CurPic];
}

PIC_InAnimation* Animation::GetPic(int index)
{
	if (index <0 || index >=m_size)
		return nullptr;

	return  &m_PicList[index];
}

void Animation::SetMatrix(Matrix33* m)
{
	m_Matrix = *m;
}

void Animation::Animation_Playing()
{
	//播放-在哪里就从哪里开始
	m_state = AM_PLAYING;
}

void Animation::Animation_Stop()
{
	//stop之后 回到第一张图片-持续的帧数也变成0 （从头开始）
	m_state = AM_STOP;
	m_CurPresistenceFra = 0;
	m_CurPic = 0;
}

void Animation::Animation_Pause()
{
	//停在当前的图片
	m_state = AM_PAUSE;
}

void Animation::Animation_RePlay()
{
	//从开头开始播放
	m_state = AM_PLAYING;
	m_CurPresistenceFra = 0;
	m_CurPic = 0;
}

void Animation::SetCurPic(int picindex)
{
	if (picindex < 0 || picindex >= m_size)
		picindex = 0;
	//设置当前的播放图片
	m_CurPic = picindex;
	//播放的帧数归0
	m_CurPresistenceFra = 0;
}

int Animation::GetSize()
{
	return m_size;
}

int Animation::GetCurIndex()
{
	return m_CurPic;
}

void Animation::Init()
{
	//初始从头开始
	m_CurPic = 0;
	m_CurPresistenceFra = 0;
	m_state = AM_STOP;
	m_size = 0;
}

void Animation::Run()
{
	//停止状态不绘制
	if (m_state == AM_STOP)
		return;
	//CGameOutput* gameoutput = CGameOutput::GetGameOutput();
	PIC_InAnimation* pic = &m_PicList[m_CurPic];
	//gameoutput->DrawPic(pic->bmp_key, &m_Matrix);
	//不是暂停状态运行-暂停状态只绘制不播放
	if (m_state != AM_PAUSE)
	{
		m_CurPresistenceFra += 1;
		if (m_CurPresistenceFra >= pic->PresistenceFra)
		{
			m_CurPresistenceFra = 0;
			m_CurPic += 1;
			if (m_CurPic >= m_size)
			{
				m_state = AM_STOP;
			}
		}
	}

	
}

void Animation::End()
{

}

PIC_InAnimation::PIC_InAnimation()
{
	bmp_key = 0;
	off_x = 0;
	off_y = 0;
	PresistenceFra = 0;
	//AttackRect = 0;
	//Attacklen = 0;
	//DefenseRect = 0;
	//DefenseLen = 0;
}

PIC_InAnimation::~PIC_InAnimation()
{
	//if (AttackRect)
	//{
	//	if (Attacklen > 1)
	//		delete[] AttackRect;
	//	else
	//		delete AttackRect;
	//}

	//if (DefenseRect)
	//{
	//	if (DefenseLen > 1)
	//		delete[] DefenseRect;
	//	else
	//		delete DefenseRect;
	//}
}
