#pragma once
#include "Core/Scene.h"
#include "Math/Rect.h"
#include "Animation/Animation.h"

class CTestScene2 :public CScene
{
	//ȫ������
	Animation* m_Am;
	//�м�������-�����������
	int m_Amlen;
	//��ǰ�������ĸ� 
	Animation* m_curAm;
	//��ǰ�����ǵڼ���
	int m_AmIndex;
	//��Ҫ������ͼƬ�±�
	int m_pic1;
	//����ͼƬ�±�
	int m_pic2;
	//�����Ƿ�����ʾ
	bool m_IsMove;


	int x;
	int y;
	int speed;
public:
	void Init();
	void Run();
	void End();
};




//����-����ͼƬʱ���������
//����DC  (ע�����ز�)
//�����ز�-���ĵ����ֱ�Ӿ��� pw(��ͼ���) - x(����ǰ��x) ////���Ͻ� pw(��ͼ���) - x(����ǰ��x)   -w(СͼƬ��С) +1
//�ȼ������ĵ�-ê�������ĵ���㣨ƫ����xȡ����


 


//��Ϊ-��