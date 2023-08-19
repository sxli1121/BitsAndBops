#include "HammerConfirming.h"

#include "OutPutAndInput/GameOutput.h"

void HammerConfirming::OnEnter()
{

}

void HammerConfirming::OnUpdate(float dt)
{
	//�������������봸��
	
	//���ƶԻ��� 
	CGameOutput* output = CGameOutput::GetGameOutput();
	const char str[] = "Let's build something��";

	output->SetFont(15, 15);
	output->DrawTxt(100, 100, str, 255);
	//sprintf_s(buf, 64, "i=%d, x=%d, y=%d", m_pic1, pic1->off_x, pic1->off_y);
	//sprintf_s(buf, 64, "i=%d, x=%d, y=%d", m_pic1, pic1->off_x, pic1->off_y);
}

void HammerConfirming::OnExit()
{
}
