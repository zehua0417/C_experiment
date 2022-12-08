/*
 * file name: easyx_heart_demo1.cpp
 * author: lihuax
 * version: 1.0
 * discriptiion: use easyx drawing a heart! 
 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<windows.h>
#define PIE 3.1415926
#define WIDTH 4608       //�������
#define HEIGHT 3072       //�����߶�

void heart(double mul, int R, int G, int B);
void diffusion(double mul, int R, int G, int B);				//������ɢ
void outer_diffusion(double mul, int R, int G, int B);	    	//������ɢ
double random(double a, double b);		//����a~b���漴��(b<10)

int main(void)
{
	//��ʼ��
	initgraph(WIDTH, HEIGHT);
	setbkcolor(WHITE);
	cleardevice();

	//��ͼ
	double mul = 20;
	heart(mul, 234, 54, 128);
	diffusion(mul, 234, 54, 128);
	diffusion(mul, 234, 63, 247);
	outer_diffusion(mul, 234, 63, 247);

	//�����ð�����������
	while (1 == 1)
	{
		for (mul = 20;mul > 19.2;mul -= 0.15)
		{
			setbkcolor(WHITE);
			cleardevice();
			heart(mul,234,54,128);
			diffusion(mul,234,54,128);
			diffusion(mul,234,63,247);
			outer_diffusion(mul,234,63,247);
			Sleep(150);
		}
	
		for (mul = 19.2;mul > 20;mul += 0.15)
		{
			setbkcolor(WHITE);
			cleardevice();
			heart(mul, 234, 54, 128);
			diffusion(mul, 234, 54, 128);
			diffusion(mul, 234, 63, 247);
			outer_diffusion(mul, 234, 63, 247);
			Sleep(150);
		}
	}

	//�ر�
	closegraph();
	return 0;
}

void heart(double mul,int R,int G,int B)
{
	double x, y;
	for (double t = 0;t <= 2 * PIE;t += 0.01)

	{
		//������ɫ
		setfillcolor(RGB(R,G,B));
		//��������
		x = 16 * pow(sin(t), 3);
		y = (-1) * ((13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)));
		//�Ŵ�
		x *= mul;
		y *= mul;
		//�ƶ�
		x += (3.0 / 16) * WIDTH;
		y += 0.125 * HEIGHT;
		//��ͼ
		fillcircle(x, y, 2);
	}
}

void diffusion(double mul,int R,int G,int B)
{
	double ctrl = 9.99 / 10, x, y;
	for (mul;mul > 1;mul -= 0.2)
	{
		for (int i = 0;i < ((2 * PIE) / 0.01) * ctrl;i++)
		{
			double t = random(0, 2 * PIE);
			//������ɫ
			setfillcolor(RGB(R,G,B));
			//��������
			x = 16 * pow(sin(t), 3);
			y = (-1) * ((13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)));
			//�Ŵ�
			x *= mul;
			y *= mul;
			//�ƶ�
			x += (3.0 / 16) * WIDTH;
			y += 0.125 * HEIGHT;
			//��ͼ
			fillcircle(x, y, 2);
			ctrl -= 0.00019;
		}
	}
}

void outer_diffusion(double mul,int R,int G,int B)
{
	double ctrl = 4.9 / 10, x, y, temp = mul;
	for (mul;mul < temp +1.9;mul += 0.2)
	{
		for (int i = 0;i < ((2 * PIE) / 0.01) * ctrl;i++)
		{
			double t = random(0, 2 * PIE);
			//������ɫ
			setfillcolor(RGB(R,G,B));
			//��������
			x = 16 * pow(sin(t), 3);
			y = (-1) * ((13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)));
			//�Ŵ�
			x *= mul;
			y *= mul;
			//�ƶ�
			x += (3.0 / 16) * WIDTH;
			y += 0.125 * HEIGHT;
			//��ͼ
			fillcircle(x, y, 2);
			ctrl -= 0.00019;
		}
	}
}

double random(double a, double b)
{
	while (1 == 1)
	{
		double result = 0;
		for (double i = 0.01; i <= 1;i *= 10)
		{
			int temp = rand() % 10;
			result += temp * i;
		}
			if (result >= a && result <= b)
			return result;
	}
}
