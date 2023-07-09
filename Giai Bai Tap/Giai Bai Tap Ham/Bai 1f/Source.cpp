/* 
sắp xếp 4 số nguyên tăng dần

INTERCHANGE SORT
so sánh từng cặp số:
a - b
a - c
a - d
b - c
b - d
c - d

a --> b --> c --> d

*/

#include <stdio.h>
#include <conio.h>

void NhapDuLieu(int &n)
{
	printf("\nNhap so nguyen: ");
	scanf("%d", &n);
}

// có dùng biến tạm
void HoanViCach1(int &a, int &b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

// không dùng biến tạm
void HoanViCach2(int &a, int &b)
{
	a = a + b; // gán đại
	b = a - b; // b = a
	a = a - b; // a = b
}

void SapXep(int &a, int &b, int &c, int &d)
{
	if(a > b)
	{
		HoanViCach1(a, b);
	}
	if(a > c)
	{
		HoanViCach1(a, c);
	}
	if(a > d)
	{
		HoanViCach1(a, d);
	}
	if(b > c)
	{
		HoanViCach1(b, c);
	}
	if(b > d)
	{
		HoanViCach1(b, d);
	}
	if(c > d)
	{
		HoanViCach1(c, d);
	}
}

int main()
{
	int a, b, c, d;
	NhapDuLieu(a);
	NhapDuLieu(b);
	NhapDuLieu(c);
	NhapDuLieu(d);

	printf("\nDay so ban dau la: %d --> %d --> %d --> %d", a, b, c, d);

	SapXep(a, b, c, d);

	printf("\nDay so sau khi sap xep la: %d --> %d --> %d --> %d", a, b, c, d);

	//printf("\nTruoc khi hoan vi a = %d & b = %d", a, b);

	//HoanViCach1(a, b);
	//HoanViCach2(a, b);

	//printf("\nSau khi hoan vi a = %d & b = %d", a, b);

	getch();
	return 0;
}