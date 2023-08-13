#include "Action.h"

CAction::CAction()
{
	m_pic = 0;
}

CAction::~CAction()
{
}

void CAction::SetTag(CObject* tag)
{
}

void CAction::Act_Begin()
{
}

void CAction::Act_Play()
{
}

void CAction::Act_Pause()
{
}

void CAction::Act_Stop()
{
}

void CAction::Init()
{
	m_pic = m_Am.GetCurPic();
}

void CAction::Run()
{
}

void CAction::End()
{
}

CRect* CAction::GetAttackRect()
{
	return m_pic->AttackRect;
}

int CAction::GetAttackRectLen()
{
	return m_pic->Attacklen;
}

CRect* CAction::GetDefenseRect()
{
	return  m_pic->DefenseRect;
}

int CAction::GetDefenseRectLen()
{
	return m_pic->DefenseLen;
}

int CAction::GetPicLen()
{
	return m_Am.GetSize();
}
