#include "MobileStation.h"
#include "OutputAndInput/GameOutput.h"
#include "Math/Matrix.h"

void MobileStation::Init()
{

}

void MobileStation::UpDate(float dt)
{
	//�����ƶ�̨��λ��
	//m_x = m_x * m_Speed;
	//dt ����һ֡��ʱ��
	
	//һ�� 100 �����ص�
	//dt �� �� 100/dt �����ص�
	//m_speed = 100/dt * dt 
	//dt * m_Speed /dt * dt = 

	m_x = m_x + m_Speed * dt;

	CGameOutput* output = CGameOutput::GetGameOutput();

	SetMatrix();
	left_m = left_sm * left_tm;
	middle_m = middle_sm * middle_tm;
	right_m = right_sm * right_tm;

	output->DrawPic("wood_left", &left_m);
	output->DrawPic("wood_centre", &middle_m);
	output->DrawPic("wood_right", &right_m);

}

void MobileStation::End()
{
}

void MobileStation::SetSpeed(float speed)
{
	m_Speed = speed;
}

void MobileStation::SetStationLen(int lenid)
{
	//�м�x������ y�㶨0.3
	float zoomx = 0;
	//�����ƶ��� x y  -ֻ��������ƶ����
	float off_right_x = 0;

	if (lenid == STATION_SHORT)
	{
		zoomx = 0.3f;
		off_right_x = 200;
	}
	else if (lenid == STATION_MIDDLE)
	{
		zoomx = 0.4f;
		off_right_x = 215;
	}
	else if (lenid == STATION_LONG)
	{
		zoomx = 0.5f;
		off_right_x = 230;
	}
	//SetMatrix();

	m_zoomx = zoomx;
	m_offx = off_right_x;

}

void MobileStation::SetMatrix()
{
	left_tm.Translate(m_x, m_y);
	left_sm.Scale(1, 0.3f);
	middle_tm.Translate(m_x + 15, m_y);
	middle_sm.Scale(m_zoomx, 0.3f);
	right_tm.Translate(m_x + m_offx, m_y);
	right_sm.Scale(1, 0.3f);

}
