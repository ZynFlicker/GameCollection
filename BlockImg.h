#pragma once
#include<graphics.h>

//图像资源类
//考虑到图形库的图像资源加载要求挺多的，抽象此类
class BlockImg
{
public:
	virtual PIMAGE getBlockImg(int) = 0;
};
