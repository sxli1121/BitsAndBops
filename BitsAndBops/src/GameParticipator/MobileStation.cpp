#include "MobileStation.h"
#include "OutputAndInput/GameOutput.h"
#include "Math/Matrix.h"

void MobileStation::Init()
{

}

void MobileStation::UpDate(float dt)
{
	//更新移动台的位置
	//m_x = m_x * m_Speed;
	//dt 运行一帧的时间
	
	//一秒 100 个像素点
	//dt 秒 是 100/dt 个像素点
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
	//中间x的缩放 y恒定0.3
	float zoomx = 0;
	//左右移动的 x y  -只有右面的移动会变
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
