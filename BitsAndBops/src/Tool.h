#pragma once
#include "Math/vector.h"
class CHero;
class CTool
{
protected:
	Vector m_pos;          //(�ӵ�������)-��Ҫ(�տ�ʼ������-�ӵ������ĵ�λ����) �տ�ʼ������-����������ı�
	Vector m_direction;     //�����ƶ��ĵ�λ����
	bool m_alive;          //�����
	const char* m_key;     //���ߵ�ͼƬ
public:
	CTool();
	virtual ~CTool();
	void SetAct(bool b);       //����Ģ���Ƿ����
	bool GetAct();       //����Ģ���Ƿ����
	void SetPos(Vector v);
	void SetDirection(Vector v);
	Vector GetPos();
	virtual void Init();
	virtual void Run();
	virtual void End();
	virtual void ColliderFun(CHero* hero, int dir);   //ÿ���������Լ�����ײ����
};
