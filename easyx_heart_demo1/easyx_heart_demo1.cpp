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
#define WIDTH 4608       //画布宽度
#define HEIGHT 3072       //画布高度

void heart(double mul, int R, int G, int B);
void diffusion(double mul, int R, int G, int B);				//向内扩散
void outer_diffusion(double mul, int R, int G, int B);	    	//向外扩散
double random(double a, double b);		//生成a~b的随即数(b<10)

int main(void)
{
	//初始化
	initgraph(WIDTH, HEIGHT);
	setbkcolor(WHITE);
	cleardevice();

	//画图
	double mul = 20;
	heart(mul, 234, 54, 128);
	diffusion(mul, 234, 54, 128);
	diffusion(mul, 234, 63, 247);
	outer_diffusion(mul, 234, 63, 247);

	//尝试让爱心跳动起来
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

	//关闭
	closegraph();
	return 0;
}

void heart(double mul,int R,int G,int B)
{
	double x, y;
	for (double t = 0;t <= 2 * PIE;t += 0.01)

	{
		//设置颜色
		setfillcolor(RGB(R,G,B));
		//基础函数
		x = 16 * pow(sin(t), 3);
		y = (-1) * ((13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)));
		//放大
		x *= mul;
		y *= mul;
		//移动
		x += (3.0 / 16) * WIDTH;
		y += 0.125 * HEIGHT;
		//画图
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
			//设置颜色
			setfillcolor(RGB(R,G,B));
			//基础函数
			x = 16 * pow(sin(t), 3);
			y = (-1) * ((13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)));
			//放大
			x *= mul;
			y *= mul;
			//移动
			x += (3.0 / 16) * WIDTH;
			y += 0.125 * HEIGHT;
			//画图
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
			//设置颜色
			setfillcolor(RGB(R,G,B));
			//基础函数
			x = 16 * pow(sin(t), 3);
			y = (-1) * ((13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)));
			//放大
			x *= mul;
			y *= mul;
			//移动
			x += (3.0 / 16) * WIDTH;
			y += 0.125 * HEIGHT;
			//画图
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
