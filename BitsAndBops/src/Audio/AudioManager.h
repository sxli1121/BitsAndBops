#ifndef _AUDIO_MANAGER_H_
#define _AUDIO_MANAGER_H_

#include <string>
#include <map>
#include "fmod.h"

/*
LoopAudio  ѭ�����ŵ�����  һ��ָ��������
OnceAudio  ֻ����һ�ε����� һ��ָ��Ч
*/

class CAudioManager
{
	//ѭ����Ƶ�ṹ��
	struct _LOOPAUDIO
	{
		//������
		FSOUND_STREAM* _s;	//��Ƶ��
		//����
		int _c;
		_LOOPAUDIO()
			:
		_s(0),
		_c(-1)
		{}
	};
	//���ڲ��ŵı�������
	std::string m_PlayingLoopAudio;
	//��������n 32 16
	int m_MaxChannel;
	//������������(0~255)
	int m_LoopVolume;
	//��Ч����(0~255)
	int m_OnceVolume;
	//�������ִ洢
	std::map<std::string, _LOOPAUDIO> m_LoopAudio;
	//��Ч�洢
	std::map<std::string, FSOUND_SAMPLE*> m_OnceAudio;

public:
	CAudioManager(int LoopVolume = 127,	//������������
				int OnceVolume = 127,	//��Ч����
				int MaxChannel = 32);	//��������
	
	virtual ~CAudioManager();

	//��������
	bool PushLoopAudio(const char* key,		//����ID
					const char* AudioPath);	//����·��

	//������Ч
	bool PushOnceAudio(const char* key,		//����ID
					const char* AudioPath);	//����·��

	//�ͷ�����
	bool ReleaseLoopAudio(const char* key);
	//�ͷ���Ч
	bool ReleaseOnceAudio(const char* key);
	//��������
	bool PlayLoopAudio(const char* key);
	//ֹͣ����
	bool StopLoopAudio(const char* key);
	//������Ч
	bool PlayOnceAudio(const char* key);

	//��ȡ �� ���� ����
	int GetLoopVolume();
	void SetLoopVolume(int Volume);
	int GetOnceVolume();
	void SetOnceVolume(int Volume);
};
#endif