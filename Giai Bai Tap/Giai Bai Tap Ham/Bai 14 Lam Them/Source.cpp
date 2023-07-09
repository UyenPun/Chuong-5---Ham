/* Bài 14: Vẽ hình chữ nhật đặc kích thước m×n bằng các dấu *.

vd: Nhập chieurong = 4, chieudai = 5
* * * * *
* * * * *
* * * * *
* * * * *

for(int i = 1; i <= chieurong; i++)
{
	for(int j = 1; j <= chieudai; j++)
	{
		printf("*");
	}
	printf("\n");
}

*/

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <iomanip>
using namespace std;

void VeHCN(int chieudai, int chieurong)
{
	for(int i = 1; i <= chieurong; i++)
	{
		for(int j = 1; j <= chieudai; j++)
		{
			Sleep(500);
			printf("*");
		}
		printf("\n");
	}
}

/* 

Bài 15: Vẽ hình chữ nhật rỗng kích thước m×n.

vd: Nhập chieudai = 5, chieurong = 4

* * * * *
*       *
*       *
* * * * *

*/

void VeHCNRong(int chieudai, int chieurong)
{
	for(int i = 1; i <= chieurong; i++)
	{
		if(i == 1 || i == chieurong)
		{
			for(int j = 1; j <= chieudai; j++)
			{
				Sleep(500);
				printf("*");
			}
		}
		else
		{
			for(int j = 1; j <= chieudai; j++)
			{
				if(j == 1 || j == chieudai)
				{
					Sleep(500);
					printf("*");
				}
				else
				{
					Sleep(500);
					printf(" ");
				}
			}
		}
		
		printf("\n");
	}
}

/* 

Bài 16: Vẽ tam giác vuông cân đặc có độ dài của cạnh là a.

vd: Nhập độ dài của cạnh: 4

*
* *
* * *
* * * *


*/

void VeTamGiacDac(int canh)
{
	for(int i = 1; i <= canh; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			Sleep(500);
			printf("*");
		}
		printf("\n");
	}
}

/* 

Bài 17: Vẽ tam giác cân có chiều cao h.

vd: Nhập chiều cao tam giác: 4

*
* * *
* * * * *
* * * * * * *

*/

void VeTamGiacCan(int canh)
{
	for(int i = 1; i <= canh; i++)
	{
		for(int j = 1; j <= 2 * i - 1; j++)
		{
			//Sleep(500);
			printf("*");
		}
		printf("\n");
	}
}

/* 

Bài 18: Vẽ tam giác cân rỗng có chiều cao h.

vd: Nhập chiều cao tam giác: 4
		
		*
	  *   *
     *     *
	*********
*/

void VeTamGiacRong(int canh)
{
	int x = 20;
	int khoangcachbandau = x - 2;
	for(int i = 1; i <= canh; i++)
	{
		Sleep(500);
		int khoangcach = x - i * 2;
		cout << setw(khoangcach) << "*";

		if(i != 1 && i != canh)
		{
			Sleep(500);
			khoangcachbandau += 2;
			cout << setw(khoangcachbandau - khoangcach) << "*";
		}

		if(i == canh)
		{
			khoangcachbandau += 2;
		
			for(int j = 1; j <= (khoangcachbandau - khoangcach); j++)
			{
				Sleep(500);
				cout << "*";
			}
		}
		cout << endl;
	}
}

int main()
{
	int chieudai = 10, chieurong = 6;

	//VeHCN(chieudai, chieurong);

	//VeHCNRong(chieudai, chieurong);

	int canh = 5;

	//VeTamGiacDac(canh);

	//VeTamGiacCan(canh);
	
	VeTamGiacRong(canh);

	getch();
	return 0;
}