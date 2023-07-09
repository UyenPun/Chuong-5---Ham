/* 
Bài 13: Nhập vào 2 số nguyên dương x & y với điều kiện x >= 2 và y > x. 
In ra bảng cửu chương từ x đến y theo cách trình bày sau:

vd: x = 5 & y = 9

 5 x  1 =  5 |  6 x  1 =  6 |  7 x  1 =  7 |  8 x  1 =  8 |  9 x  1 =  9 |
 5 x  2 = 10 |  6 x  2 = 12 |  7 x  2 = 14 |  8 x  2 = 16 |  9 x  2 = 18 |
 5 x  3 = 15 |  6 x  3 = 18 |  7 x  3 = 21 |  8 x  3 = 24 |  9 x  3 = 27 |
 5 x  4 = 20 |  6 x  4 = 24 |  7 x  4 = 28 |  8 x  4 = 32 |  9 x  4 = 36 |
 5 x  5 = 25 |  6 x  5 = 30 |  7 x  5 = 35 |  8 x  5 = 40 |  9 x  5 = 45 |
 5 x  6 = 30 |  6 x  6 = 36 |  7 x  6 = 42 |  8 x  6 = 48 |  9 x  6 = 54 |
 5 x  7 = 35 |  6 x  7 = 42 |  7 x  7 = 49 |  8 x  7 = 56 |  9 x  7 = 63 |
 5 x  8 = 40 |  6 x  8 = 48 |  7 x  8 = 56 |  8 x  8 = 64 |  9 x  8 = 72 |
 5 x  9 = 45 |  6 x  9 = 54 |  7 x  9 = 63 |  8 x  9 = 72 |  9 x  9 = 81 |


 for(int i = 1; i <= 9; i++)
 {
	for(int j = x; j <= y; j++)
	{
		printf
	}
 }

*/

#include <stdio.h>
#include <conio.h>

void LietKe(int x, int y)
{
	 for(int i = 1; i <= 9; i++)
	 {
		for(int j = x; j <= y; j++)
		{
			printf("%d * %d = %2d |", j, i, j * i);
		}
		printf("\n");
	 }
}

int main()
{
	int x = 3, y = 7;

	LietKe(x, y);
	
	getch();
	return 0;
}