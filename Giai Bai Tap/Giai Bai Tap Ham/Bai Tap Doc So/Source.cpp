#include <stdio.h>
#include <conio.h>
#include <math.h>

void DaoSo(int &n)
{
	int soluongchuso = log10((double)n);
	int tong = 0;
	while(n != 0)
	{
		tong += n % 10 * pow(10.0, soluongchuso--);
		n /= 10; // bỏ chữ số cuối đi
	}
	n = tong;
}

void DocChuSo(int chuso)
{
	if(chuso == 1)
	{
		printf(" Mot ");
	}
	else if(chuso == 2)
	{
		printf(" Hai ");
	}
	else if(chuso == 3)
	{
		printf(" Ba ");
	}
	else if(chuso == 4)
	{
		printf(" Bon ");
	}
	else if(chuso == 5)
	{
		printf(" Lam ");
	}
	else if(chuso == 6)
	{
		printf(" Sau ");
	}
	else if(chuso == 7)
	{
		printf(" Bay ");
	}
	else if(chuso == 8)
	{
		printf(" Tam ");
	}
	else if(chuso == 9)
	{
		printf(" Chin ");
	}
}

void DocPhuAm(int sochusoconlai)
{
	if(sochusoconlai == 1)
	{
		printf(" Muoi ");
	}
	else if(sochusoconlai == 2)
	{
		printf(" Tram ");
	}
	else if(sochusoconlai == 3)
	{
		printf(" Ngan ");
	}
	else if(sochusoconlai == 4)
	{
		printf(" Muoi ");
	}
	else if(sochusoconlai == 5)
	{
		printf(" Tram ");
	}
	else if(sochusoconlai == 6)
	{
		printf(" Trieu ");
	}
}
/* 
1234
B1: đảo thành 4321
B2: 
đọc chữ số 1 lên
n = 432
=> log10(n) + 1 = 3 tức là còn 3 chữ số
*/
void DocSo(int n)
{
	DaoSo(n); // B1
	while(n != 0)
	{
		DocChuSo(n % 10); // B2
		n /= 10; // bỏ chữ số vừa lấy ra
		DocPhuAm(log10((double)n) + 1); // B3
	}
}

int main()
{
	int n = 234567;
	DocSo(n);

	getch();
	return 0;
}