#pragma once
#include "Math/Rect.h"
#include "Math/Matrix.h"
#include <vector>
 
#define AM_STOP     0
#define AM_PLAYING  1
#define AM_PAUSE    2

//�����е�ͼƬ
struct PIC_InAnimation
{
	//key
	const char* bmp_key;
	//ê��
	int off_x;
	int off_y;
	//������֡��
	int PresistenceFra;
	//���� ��������-����θ���
	CRect* AttackRect;
	int Attacklen;
	CRect* DefenseRect;
	int DefenseLen;

	//����
	PIC_InAnimation();
	~PIC_InAnimation();

};
class Animation
{
	std::vector<PIC_InAnimation> m_PicList;
	//��ǰ��ͼƬ
	int m_CurPic;
	//�ڲ��Ŷ����ĵ�ǰ����֡������¼���Ŵ�����
	int m_CurPresistenceFra;
	//��ǰ�Ĳ��ŵĶ�����״̬
	int m_state;
	//��ǰͼƬ��Ҫ�ľ���
	CMatrix33 m_m;
	//ÿ�鶯����ͼƬ����
	int m_size;
public:
	//��Ӷ���ͼƬ
	void AddAnmiationPic(const char* BmpKey, int off_x, int off_y, int PresisitenceFre);
	//��ӹ�������-�����ڵڼ���
	void AddAttackRect(CRect* Rect,int len, int Picindex);
	//��������
	void AddDefenseRect(CRect* Rect, int Len, int Picindex);
	//
	int GetAnimationState();
	//��ȡ��ǰͼƬ
	PIC_InAnimation* GetCurPic();
	//��ȡָ��ͼƬ
	PIC_InAnimation* GetPic(int index);

	//����
	void SetMatrix(CMatrix33* m);
	//�ı䶯�����ŵ�״̬
	void Animation_Playing();
	void Animation_Stop();
	void Animation_Pause();
	void Animation_RePlay();

	//���ô���һ��ͼƬ��ʼ����
	void SetCurPic(int picindex);

	//��ȡ��ǰ������ͼƬ����
	int GetSize();
	//��ȡ�ǵڼ���ͼƬ
	int GetCurIndex();



	void Init();
	void Run();
	void End();

};

