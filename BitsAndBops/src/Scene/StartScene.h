#pragma once
#include "Scene.h"
#include "Math/vector.h"
class CStartScene : public CScene
{
	float tka;		//̹�˽Ƕ�
	CVector tkpos;	//̹������
	float speed; 
	CVector pgoffPos; //�ڹ�ê�� ƫ����
	CVector Dir;

	float pga;		//�ڹܽǶ�
	CVector pgoff;	//�ڹ�ê��
	CVector pgpos;   //�ڹܵ�����
	CVector pgDir;      //�ڹܵ�����
public:
	void Init();
	void Run();
	void End();
};