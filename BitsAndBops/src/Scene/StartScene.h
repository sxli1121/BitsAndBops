#pragma once
#include "Core/Scene.h"
#include "Math/vector.h"
class CStartScene : public CScene
{
	float tka;		//̹�˽Ƕ�
	Vector tkpos;	//̹������
	float speed; 
	Vector pgoffPos; //�ڹ�ê�� ƫ����
	Vector Dir;

	float pga;		//�ڹܽǶ�
	Vector pgoff;	//�ڹ�ê��
	Vector pgpos;   //�ڹܵ�����
	Vector pgDir;      //�ڹܵ�����
public:
	void Init();
	void Run();
	void End();
};