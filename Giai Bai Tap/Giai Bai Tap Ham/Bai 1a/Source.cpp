/*
A => mã ASCII là 65
a => mã ASCII là 97
*/
#include <stdio.h>
#include <conio.h>

void Nhap(char &x) // tham chiếu
{
	printf("\nNhap ky tu: ");
	scanf("%c", &x); // toán tử địa chỉ
}

char BienDoi(char x)
{
	if(x >= 'A' && x <= 'Z')
	{
		x += 32;
	}
	return x;
}

void BienDoi_2(char &x)
{
	if(x >= 'A' && x <= 'Z')
	{
		x += 32;
	}
}

int main()
{
	char x;
	Nhap(x);
	//char c = BienDoi(x);
	BienDoi_2(x);
	printf("\nSau khi bien doi la: %c", x);

	getch();
	return 0;
}