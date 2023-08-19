#pragma once
#include "GameParticipator/Participator.h"

#include <vector>

enum Nailstate
{
	NAIL_NOT_EXIST,
	NAIL_COMPLETELY_OYT,
	NAIL_MISS_LEFT,
	NAIL_MISS_RIGHT,
	NAIL_HIT_PREFECT,
};

class Nail : public Participator
{
public:
	Nail();
	void AddNail(int x,int y,int stste);
	void SetNailPos(int index, int x, int y);
	void SetNailState(int index, int State);
	int GetNailState(int index);
	void EreaseNail();

private:
	void Clear();

private:
	struct sNail
	{
		float X;
		float Y;
		int PrecenceState;       //´æÔÚ×´Ì¬
		sNail() 
		{
			PrecenceState = NAIL_NOT_EXIST;
		}
	};
	std::vector <sNail> m_nailList;
	int m_Size;

	friend class HammerTeaching;
};

