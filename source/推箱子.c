#include <stdio.h>
#include <graphics.h>
#include <conio.h>
int i, j;//循环变量
int temp;
int m;
int mode = 1;
int arr[16][16];
int arr2[16][16];
IMAGE background, box,redBox, wall, ground, figure, aim;
void createMap();
int main();
void direction(int x);//控制方向
void locateFigure();
void contralGame();
void judge();//判断获胜
void redraw(int x);
void redraw(int x)
{
	if (x == 1)
	{
		for (i = 0; i <16; i++)
		{
			for (j = 0; j < 16; j++)
			{
				if (arr[i][j] == 0)
					putimage(40 * j, 40 * i, &background);
				if (arr[i][j] == 1)
					putimage(40 * j, 40 * i, &wall);
				if (arr[i][j] == 2)
					putimage(40 * j, 40 * i, &ground);
				if (arr[i][j] == 3)
					putimage(40 * j, 40 * i, &aim);
				if (arr[i][j] == 4)
					putimage(40 * j, 40 * i, &box);
				if (arr[i][j] == 5)
					putimage(40 * j, 40 * i, &figure);
				if (arr[i][j] == 6)
					putimage(40 * j, 40 * i, &redBox);
			}
		}
	}
	if (x == 2)
	{
		for (i = 0; i <16; i++)
		{
			for (j = 0; j < 16; j++)
			{
				
				if ((arr2[i][j] == 3|| arr2[i][j] == 6) && arr[i][j] != 6 && arr[i][j] != 5)
				{
					arr[i][j]= 3;
					putimage(40 * j, 40 * i, &aim);
				}
			}
		}
	}
	if (x == 3)
	{
		for (i = 0; i <16; i++)
		{
			for (j = 0; j < 16; j++)
			{
				if (arr[i][j] == 4)
					putimage(40 * j, 40 * i, &box);
				if (arr[i][j] == 5)
					putimage(40 * j, 40 * i, &figure);
				if (arr[i][j] == 6)
					putimage(40 * j, 40 * i, &redBox);
			}
		}
	}
}
void createMap()
{
	setbkcolor(RGB(233, 233, 233));
	cleardevice();
	if (mode == 1)
	{
		m = 5;
		int arr1[16][16] =
		{ { 0 },{ 0 },{ 0 },{ 0 },
		{ 0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0 },
		{ 0,0,0,0,1,1,1,2,2,2,2,1,0,0,0,0 },
		{ 0,0,0,1,1,3,2,4,1,1,2,1,1,0,0,0 },
		{ 0,0,0,1,3,3,4,2,4,2,2,5,1,0,0,0 },
		{ 0,0,0,1,3,3,2,4,2,4,2,1,1,0,0,0 },
		{ 0,0,0,1,1,1,1,1,1,2,2,1,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0 },
		{ 0 },{ 0 },{ 0 },{ 0 },{ 0 } };
		for (i = 0; i < 16; i++)
			for (j = 0; j < 16; j++)
			{
				arr[i][j] = arr1[i][j];
				arr2[i][j] = arr1[i][j];
			}
	}
	if (mode == 2)
	{
		m = 3;
		int arr1[16][16] =
		{ {0},{0},
		{ 0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0 },
		{ 0,0,0,1,2,2,2,1,0,0,0,0,0,0,0,0 },
		{ 0,0,0,1,2,4,2,1,0,1,1,1,0,0,0,0 },
		{ 0,0,0,1,2,4,5,1,0,1,3,1,0,0,0,0 },
		{ 0,0,0,1,1,1,4,1,1,1,3,1,0,0,0,0 },
		{ 0,0,0,0,1,1,2,2,2,2,3,1,0,0,0,0 },
		{ 0,0,0,0,1,2,2,2,1,2,2,1,0,0,0,0 },
		{ 0,0,0,0,1,2,2,2,1,1,1,1,0,0,0,0 },
		{ 0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0 },
		{0},{0},{0},{0},{0} };
		for (i = 0; i < 16; i++)
			for (j = 0; j < 16; j++)
			{
				arr[i][j] = arr1[i][j];
				arr2[i][j] = arr1[i][j];
			}
	}
	if (mode == 3)
	{
		m = 4;
		int arr1[16][16] =
		{ { 0 },{ 0 },{ 0 },
		{ 0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0 },
		{ 0,0,0,0,1,2,2,2,2,2,1,1,1,0,0,0 },
		{ 0,0,0,1,1,4,1,1,1,2,2,2,1,0,0,0 },
		{ 0,0,0,1,2,5,2,4,2,2,4,2,1,0,0,0 },
		{ 0,0,0,1,2,3,3,1,2,4,2,1,1,0,0,0 },
		{ 0,0,0,1,1,3,3,1,2,2,2,1,0,0,0,0 },
		{ 0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0 },
		{ 0 },{ 0 },{ 0 },{ 0 },{ 0 },{ 0 } };
		for (i = 0; i < 16; i++)
			for (j = 0; j < 16; j++)
			{
				arr[i][j] = arr1[i][j];
				arr2[i][j] = arr1[i][j];
			}
	}
	if (mode == 4)
	{
		m = 5;
		int arr1[16][16] =
		{ { 0 },{ 0 },{ 0 },
		{ 0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,1,2,2,1,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,5,4,2,1,0,0,0,0,0,0 },
		{ 0,0,0,0,0,1,1,4,2,1,1,0,0,0,0,0 },
		{ 0,0,0,0,0,1,1,2,4,2,1,0,0,0,0,0 },
		{ 0,0,0,0,0,1,3,4,2,2,1,0,0,0,0,0 },
		{ 0,0,0,0,0,1,3,3,6,3,1,0,0,0,0,0 },
		{ 0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0 },
		{ 0 },{ 0 },{ 0 },{ 0 },{ 0 } };
		for (i = 0; i < 16; i++)
			for (j = 0; j < 16; j++)
			{
				arr[i][j] = arr1[i][j];
				arr2[i][j] = arr1[i][j];
			}
	}
	
	loadimage(&background, _T("pic\\0.jpg"), 40, 40);
	loadimage(&wall, _T("pic\\1.jpg"), 40, 40);
	loadimage(&ground, _T("pic\\2.jpg"), 40, 40);
	loadimage(&aim, _T("pic\\3.jpg"), 40, 40);
	loadimage(&box, _T("pic\\4.jpg"), 40, 40);
	loadimage(&figure, _T("pic\\5.jpg"), 40, 40);
	loadimage(&redBox, _T("pic\\6.jpg"), 40, 40);
	redraw(1);
}
void direction(int x)
{
	if (x == 1)
	{
		locateFigure();
		if ((arr[i - 1][j] == 2 || arr[i - 1][j] == 3))
		{
			arr[i][j] = 2;
			arr[i - 1][j] = 5;
		}
		if (arr[i - 1][j] == 4 && arr[i - 2][j] == 2)
		{
			arr[i][j] = 2;
			arr[i - 1][j] = 5;
			arr[i - 2][j] = 4;
		}
		if (arr[i - 1][j] == 4 && arr[i - 2][j] == 3)
		{
			arr[i][j] = 2;
			arr[i - 1][j] = 5;
			arr[i - 2][j] = 6;
		}
		if (arr[i - 1][j] == 6 && arr[i - 2][j] == 3)
		{
			arr[i][j] = 2;
			arr[i - 1][j] = 5;
			arr[i - 2][j] = 6;
		}
		redraw(1);
		redraw(2);
		redraw(3);
	}
	if (x == 2)
	{
		locateFigure();
		if ((arr[i + 1][j] == 2 || arr[i + 1][j] == 3))
		{
			arr[i][j] = 2;
			arr[i + 1][j] = 5;
		}
		if (arr[i + 1][j] == 4 && arr[i + 2][j] == 2)
		{
			arr[i][j] = 2;
			arr[i + 1][j] = 5;
			arr[i + 2][j] = 4;
		}
		if (arr[i + 1][j] == 4 && arr[i + 2][j] == 3)
		{
			arr[i][j] = 2;
			arr[i + 1][j] = 5;
			arr[i + 2][j] = 6;
		}
		if (arr[i + 1][j] == 6 && arr[i + 2][j] == 3)
		{
			arr[i][j] = 2;
			arr[i + 1][j] = 5;
			arr[i + 2][j] = 6;
		}
		redraw(1);
		redraw(2);
		redraw(3);
	}
	if (x == 3)
	{
		locateFigure();//1墙2地3目标4箱子5人6红箱子
		if ((arr[i][j - 1] == 2 || arr[i][j - 1] == 3))
		{
			arr[i][j] = 2;
			arr[i][j - 1] = 5;
		}
		if (arr[i][j - 1] == 4 && arr[i][j - 2] == 2)
		{
			arr[i][j] = 2;
			arr[i][j - 1] = 5;
			arr[i][j - 2] = 4;
		}
		if (arr[i][j - 1] == 4 && arr[i][j - 2] == 3)
		{
			arr[i][j] = 2;
			arr[i][j - 1] = 5;
			arr[i][j - 2] = 6;
		}
		if (arr[i][j - 1] == 6 && arr[i][j - 2] == 3)
		{
			arr[i][j] = 2;
			arr[i][j - 1] = 5;
			arr[i][j - 2] = 6;
		}
		redraw(1);
		redraw(2);
		redraw(3);
	}
	if (x == 4)
	{
		locateFigure();
		if ((arr[i][j + 1] == 2 || arr[i][j + 1] == 3))
		{
			arr[i][j] = 2;
			arr[i][j + 1] = 5;
		}
		if (arr[i][j + 1] == 4 && arr[i][j + 2] == 2)
		{
			arr[i][j] = 2;
			arr[i][j + 1] = 5;
			arr[i][j + 2] = 4;
		}
		if (arr[i][j + 1] == 4 && arr[i][j + 2] == 3)
		{
			arr[i][j] = 2;
			arr[i][j + 1] = 5;
			arr[i][j + 2] = 6;
		}
		if (arr[i][j + 1] == 6 && arr[i][j + 2] == 3)
		{
			arr[i][j] = 2;
			arr[i][j + 1] = 5;
			arr[i][j + 2] = 6;
		}
		redraw(1);
		redraw(2);
		redraw(3);
	}
}
void contralGame()
{
	char c = 0;
	while (1)
	{
		if (kbhit)
			c = getch();
		switch (c)
		{
		case 'w':
			direction(1);
			judge();
			break;
		case 's':
			direction(2);
			judge();
			break;
		case 'a':
			direction(3);
			judge();
			break;
		case 'd':
			direction(4);
			judge();
			break;
		}
	}
}
void locateFigure()//找到小人的位置
{
	int flag = 0;
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			if (arr[i][j] == 5)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}	
}
void judge()
{
	int s = 0;
	for (i = 0; i <16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			if (arr[i][j] == 6)
				s++;
		}
	}
	if (s == m)
	{
		mode++;
		main();
	}
}
int main()
{
	initgraph(640, 640,SHOWCONSOLE);
	createMap();
	contralGame();
	getch();
	closegraph();
}