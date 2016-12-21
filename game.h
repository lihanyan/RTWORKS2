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
	float y;//���λ������
	float vx;
	float vy;//����ٶȴ�С

	void Init();
	void getBallState();
	void Collision();
	void Display();

private:
	Scalar color;//�����ɫ
	int diameter;//���ֱ��
	float m;//�������
};


void CBall::Init()
{
	//��ĳ�ʼ������������������ֵ
	x = 0; y = 0; vx = 0; vy = 0;
	color = (0, 0, 255);
	diameter = 10;
	m = 5;
}

void CBall::getBallState()
{
	//��ȡ��ĵ�ǰ״̬������λ�ú��ٶ�
}

void CBall::Collision()
{
	//������ͻ�������λ���ٶȣ��õ�����ײ���״̬
}

void CBall::Display()
{
	//�������λ�����ꡢ��ɫ��ֱ����ʵʱ��ʾ����
}