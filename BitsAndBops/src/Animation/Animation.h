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
	//锚点
	int off_x;
	int off_y;
	//持续的帧数
	int PresistenceFra;

	//构造
	PIC_InAnimation();
	~PIC_InAnimation();
};

class Animation
{
	std::vector<PIC_InAnimation> m_PicList;    	//所有的图片都在
	int m_CurPic;                               //当前的图片
	int m_CurPresistenceFra;                    //在播放动画的当前播放帧数（记录播放次数）
	int m_state;                                //当前的播放的动画的状态
	Matrix33 m_Matrix;                          //当前图片需要的矩阵
	int m_size;                                 //每组动画的图片数量
public:
	//添加动画图片
	void AddAnmiationPic(const char* BmpKey, int off_x, int off_y, int PresisitenceFre);
	int GetAnimationState();
	PIC_InAnimation* GetCurPic();
	PIC_InAnimation* GetPic(int index);         	//获取指定图片

	//矩阵
	void SetMatrix(Matrix33* m);
	//改变动画播放的状态
	void Animation_Playing();
	void Animation_Stop();
	void Animation_Pause();
	void Animation_RePlay();

	//设置从哪一张图片开始播放
	void SetCurPic(int picindex);

	//获取当前动画的图片数量
	int GetSize();
	//获取是第几张图片
	int GetCurIndex();

	void Init();
	void Run();
	void End();
};

