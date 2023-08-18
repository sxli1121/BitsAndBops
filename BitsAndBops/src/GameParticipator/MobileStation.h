#pragma once
#include "GameParticipator/Participator.h"
#include "Math/Matrix.h"

enum  MobileStationLen
{
	STATION_SHORT,
	STATION_MIDDLE,
	STATION_LONG,
};

class MobileStation : public Participator
{
public:
	void Init() override;
	void UpDate(float dt) override;
	void End() override;

	void SetSpeed(float speed);
	void SetStationLen(int lenid);   //�ƶ�̨�ĳ���  �����������ž���
private:
	void SetMatrix();
private:
	//����Ϊ��λ
	float m_Speed;
	float m_zoomx;
	float m_offx;

	Matrix33 left_tm, left_sm, left_m;
	Matrix33 middle_tm, middle_sm, middle_m;
	Matrix33 right_tm, right_sm, right_m;
};

