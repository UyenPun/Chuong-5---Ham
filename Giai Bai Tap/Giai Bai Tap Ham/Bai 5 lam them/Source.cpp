#include <stdio.h>
#include <conio.h>
#include <math.h>

int KiemTraNguyenTo(int n)
{
	if(n < 2)
	{
		return 0; // sai
	}
	else if(n > 2)
	{
		if(n % 2 == 0)
		{
			return 0; // sai
		}
		for(int i = 3; i <= (int)sqrt((double)n); i += 2)
		{
			if(n % i == 0)
			{
				return 0; // sai
			}
		}
	}
	return 1; // đúng
}

void XuLy(int n)
{
	printf("\nCac so nguyen to nho hon %d la: ", n);
	for(int i = 2; i < n; i++)
	{
		if(KiemTraNguyenTo(i) == 1)
		{
			printf("%4d", i);
		}
	}
}

int main()
{
	int n = 11;

	XuLy(n);

	getch();
	return 0;
}