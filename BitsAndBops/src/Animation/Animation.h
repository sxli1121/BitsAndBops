#pragma once

#include "Math/Matrix.h"
#include <vector>
 
#define AM_STOP     0
#define AM_PLAYING  1
#define AM_PAUSE    2

struct PIC_InAnimation
{
	//key
	const char* bmp_key;
	//ê��
	int off_x;
	int off_y;
	//������֡��
	int PresistenceFra;

	//����
	PIC_InAnimation();
	~PIC_InAnimation();
};

class Animation
{
	std::vector<PIC_InAnimation> m_PicList;    	//���е�ͼƬ����
	int m_CurPic;                               //��ǰ��ͼƬ
	int m_CurPresistenceFra;                    //�ڲ��Ŷ����ĵ�ǰ����֡������¼���Ŵ�����
	int m_state;                                //��ǰ�Ĳ��ŵĶ�����״̬
	Matrix33 m_Matrix;                          //��ǰͼƬ��Ҫ�ľ���
	int m_size;                                 //ÿ�鶯����ͼƬ����
public:
	//��Ӷ���ͼƬ
	void AddAnmiationPic(const char* BmpKey, int off_x, int off_y, int PresisitenceFre);
	int GetAnimationState();
	PIC_InAnimation* GetCurPic();
	PIC_InAnimation* GetPic(int index);         	//��ȡָ��ͼƬ

	//����
	void SetMatrix(Matrix33* m);
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

