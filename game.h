<<<<<<< HEAD
#pragma once

#include <opencv2\opencv.hpp>
#include <list>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/nman.h>

#include <native/task.h>
#include <native/timer.h>


//球类
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


//机械手类
class CRobotic
{
public:
	float x;
	float y;
	float vx;
	float vy;
	list CommandList;
	
	void Init();
	void readCommand();
	void Trajectory_Generator();
	void Display();

private:
	Scalar color;
	float m;
	int diameter;
};

void CRobotic::Init()
{
	//初始化参数
}

void CRobotic::readCommand()
{
	//接受并解析命令，得到目标击球点和目标击球速度
}

void CRobotic::Trajectory_Generator()
{
	//根据目标击球点和目标击球速度，生成平滑轨迹。轨迹插补可用在这里
}

void CRobotic::Display()
{
	//根据击球器的位置、大小、颜色，实时显示画面
=======
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