/* 
giả sử lúc đầu a = 6, b = 9
thì sau khi hoán vị (đổi chỗ)
thì a = 9, b = 6
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

int main()
{
	int a, b;
	NhapDuLieu(a);
	NhapDuLieu(b);
	printf("\nTruoc khi hoan vi a = %d & b = %d", a, b);

	//HoanViCach1(a, b);
	HoanViCach2(a, b);

	printf("\nSau khi hoan vi a = %d & b = %d", a, b);

	getch();
	return 0;
}