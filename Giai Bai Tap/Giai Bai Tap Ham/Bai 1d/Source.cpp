/* 
tìm số nhỏ nhất của 4 số a, b, c, d

gán đại min là 1 số bất kỳ rồi lần
lượt lấy các số còn lại so sánh với min, 
nếu nó mà còn nhỏ hơn cả min hiện tại
thì cập nhật min hiện tại là chính số đó.
*/

#include <stdio.h>
#include <conio.h>

void NhapDuLieu(int &x)
{
	printf("\nNhap so nguyen: ");
	scanf("%d", &x);
}

void TimMin_2(int a, int b, int &Min)
{
	Min = a < b ? a : b;
}

int TimMin(int a, int b)
{
	/*
	int Min = a;
	if(b < Min)
	{
		Min = b;
	}
	return Min;
	*/

	return a < b ? a : b; // toán tử 3 ngôi
}

int main()
{
	int a, b, c, d;
	NhapDuLieu(a);
	NhapDuLieu(b);
	NhapDuLieu(c);
	NhapDuLieu(d);

	int Min = TimMin(a, b);
	Min = TimMin(Min, c);
	Min = TimMin(Min, d);

	printf("\nMin = %d", Min);

	getch();
	return 0;
}
