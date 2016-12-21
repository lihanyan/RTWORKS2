#pragma once

#include <opencv2\opencv.hpp>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/nman.h>

#include <native/task.h>
#include <native/timer.h>


class CBall
{
public:
	float x;
	float y;//球的位置坐标
	float vx;
	float vy;//球的速度大小

	void Init();
	void getBallState();
	void Collision();
	void Display();

private:
	Scalar color;//球的颜色
	int diameter;//球的直径
	float m;//球的质量
};


void CBall::Init()
{
	//球的初始化函数，给参数赋初值
	x = 0; y = 0; vx = 0; vy = 0;
	color = (0, 0, 255);
	diameter = 10;
	m = 5;
}

void CBall::getBallState()
{
	//获取球的当前状态，包括位置和速度
}

void CBall::Collision()
{
	//根据球和击球器的位置速度，得到球碰撞后的状态
}

void CBall::Display()
{
	//根据球的位置坐标、颜色、直径，实时显示冰球
}