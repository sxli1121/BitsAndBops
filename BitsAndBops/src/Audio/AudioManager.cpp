#include "AudioManager.h"
#include <iostream>

#pragma comment(lib, "fmodvc.lib")

CAudioManager::CAudioManager(int LoopVolume, int OnceVolume, int MaxChannel)
:
m_MaxChannel(MaxChannel),
m_OnceVolume(OnceVolume),
m_LoopVolume(LoopVolume)
{
	//FMOD��ʼ��
	FSOUND_Init(44100, MaxChannel, 0);
}

CAudioManager::~CAudioManager()
{
	//ͨ�������� ѭ���ͷ���Ƶ
	std::map<std::string, _LOOPAUDIO>::iterator i;
	for(i = m_LoopAudio.begin(); i != m_LoopAudio.end(); ++i)
	{
		FSOUND_Stream_Close(i->second._s);
	}
	std::map<std::string, FSOUND_SAMPLE*>::iterator j;
	for(j = m_OnceAudio.begin(); j != m_OnceAudio.end(); ++j)
	{
		FSOUND_Sample_Free(j->second);
	}

	//FMOD�ر�
	FSOUND_Close();
}

//��������
bool CAudioManager::PushLoopAudio(const char* key,		//����ID
					const char* AudioPath)	//����·��
{
	//����ҵ���key �����ʧ�� 
	std::string s = key;
	if(m_LoopAudio.find(key) != m_LoopAudio.end())
	{
		return 0;
	}
	//���û���ҵ� ���������
	_LOOPAUDIO la;
	la._s = FSOUND_Stream_Open(AudioPath, FSOUND_LOOP_NORMAL, 0, 0);

	//����ӳ����
	if(la._s)
	{
		m_LoopAudio[s] = la;
		return 1;
	}
	return 0;
}

//������Ч
bool CAudioManager::PushOnceAudio(const char* key,		//����ID
					const char* AudioPath)	//����·��
{
	std::string s = key;
	//�ж�key �Ƿ���� ����� ���ؼ�
	if(m_OnceAudio.find(key) != m_OnceAudio.end())
		return 0;

	//������Ƶ
	FSOUND_SAMPLE* fs = FSOUND_Sample_Load(FSOUND_FREE, AudioPath, FSOUND_LOOP_OFF, 0, 0);
	if(fs)
	{
		
		m_OnceAudio[s] = fs;
		return 1;
	}
	return 0;
}

//�ͷ�����
bool CAudioManager::ReleaseLoopAudio(const char* key)
{
	std::string s = key;
	//���û���ҵ� ����ʧ��
	std::map<std::string, _LOOPAUDIO>::iterator i = m_LoopAudio.find(s);
	if(i == m_LoopAudio.end())
		return 0;
	//�ҵ����ͷ�
	FSOUND_Stream_Close(i->second._s);
	m_LoopAudio.erase(i);
	return 1;
}
//�ͷ���Ч
bool CAudioManager::ReleaseOnceAudio(const char* key)
{
	std::string s = key;
	//���û���ҵ� ����ʧ��
	std::map<std::string, FSOUND_SAMPLE*>::iterator i = m_OnceAudio.find(s);
	if(i == m_OnceAudio.end())
		return 0;
	//�ҵ����ͷ�
	FSOUND_Sample_Free(i->second);
	m_OnceAudio.erase(i);
	return 1;
}


bool CAudioManager::PlayLoopAudio(const char* key)
{
	//�����ǰ��ѭ����Ƶ�ڲ��� �˴�ʧ��
	if(m_PlayingLoopAudio != std::string(""))
		return 0;
	
	//����޷��ҵ�key Ҳ����ʧ��
	std::string s = key;
	std::map<std::string, _LOOPAUDIO>::iterator i = m_LoopAudio.find(s);
	if(i == m_LoopAudio.end())
		return 0;

	//���õ�ǰ���ڲ��ŵ�����
	m_PlayingLoopAudio = s;
	//������Ƶ ���õ�����
	i->second._c = FSOUND_Stream_Play(FSOUND_FREE, i->second._s);
	
	//��������
	FSOUND_SetVolume( i->second._c, m_LoopVolume);
	return 1;
}

bool CAudioManager::StopLoopAudio(const char* key)
{
	std::string s = key;

	//������ǵ�ǰ���ڲ��ŵ����� ����ʧ��
	if(m_PlayingLoopAudio != s)
		return 0;
	//����޷��ҵ�key ����ʧ��
	std::map<std::string, _LOOPAUDIO>::iterator i = m_LoopAudio.find(s);
	if(i == m_LoopAudio.end())
		return 0;

	//����ֹͣ����
	m_PlayingLoopAudio = "";
	//ֹͣ��Ƶ����
	FSOUND_Stream_Stop(i->second._s);
	//��������
	i->second._c = -1;
	return 1;
}

bool CAudioManager::PlayOnceAudio(const char* key)
{
	//����޷��ҵ�key ����ʧ��
	std::string s = key;
	std::map<std::string, FSOUND_SAMPLE*>::iterator i = m_OnceAudio.find(s);
	if(i == m_OnceAudio.end())
		return 0;

	//������Ƶ����������

	FSOUND_SetVolume(FSOUND_PlaySound(FSOUND_FREE, i->second), m_OnceVolume);
	return 1;
}

int CAudioManager::GetLoopVolume()
{
	//���ر������ֵ�����
	return m_LoopVolume;
}

void CAudioManager::SetLoopVolume(int Volume)
{
	//�ж�������Χ
	if(Volume < 0)
		Volume = 0;
	else if(Volume > 255)
		Volume = 255;

	m_LoopVolume = Volume;

	if(m_PlayingLoopAudio != std::string(""))
	{
		//���ø���Ƶ����
		FSOUND_SetVolume(m_LoopAudio.find(m_PlayingLoopAudio)->second._c, m_LoopVolume);
	}
}

int CAudioManager::GetOnceVolume()
{
	//���ر������ֵ�����
	return m_OnceVolume;
}

void CAudioManager::SetOnceVolume(int Volume)
{
	//�ж�������Χ
	if(Volume < 0)
		Volume = 0;
	else if(Volume > 255)
		Volume = 255;

	//�õ�����
	m_OnceVolume = Volume;
}


