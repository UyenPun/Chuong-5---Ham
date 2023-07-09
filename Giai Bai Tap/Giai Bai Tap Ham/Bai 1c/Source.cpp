/* 
ax^2 + bx + c = 0

TH1: a = 0
=> lúc này pt có dạng: bx + c = 0
=> chính là pt bậc 1
=> gọi lại hàm GiaiPTBac1

TH2: a != 0
=> Tính denta rồi biện luận
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

void NhapDuLieu(double &x)
{
	printf("\nNhap so thuc: ");
	scanf("%lf", &x);
}

// ax + b = 0
void GiaiPTBac1(double a, double b)
{
	// pt co dang: b = 0
	if(a == 0)
	{
		if(b == 0)
		{
			printf("\nPT co vo so nghiem");
		}
		else
		{
			printf("\nPT vo nghiem");
		}
	}
	else
	{
		double x = -b / a;
		printf("\nPT co nghiem x = %lf", x);
	}
}

void GiaiPTBac2(double a, double b, double c)
{
	// TH1: a = 0
	if(a == 0) // pt co dang: bx + c = 0
	{
		GiaiPTBac1(b, c); // b chính là a ở hàm trên, c chính là b ở hàm trên
	}
	else
	{
		double denta = b * b - 4 * a * c;
		if(denta < 0)
		{
			printf("\nPT vo nghiem");
		}
		else if(denta == 0)
		{
			double x = -b / (2 * a);
			printf("\nPT co nghiem kep x1 = x2 = %lf", x);
		}
		else // denta > 0
		{
			double x1 = (-b + sqrt(denta)) / (2 * a);
			double x2 = (-b - sqrt(denta)) / (2 * a);

			printf("\nPT co 2 nghiem phan biet:\nx1 = %lf\nx2 = %lf", x1, x2);
		}
	}
}

int main()
{
	double a, b, c;
	NhapDuLieu(a);
	NhapDuLieu(b);
	NhapDuLieu(c);

	GiaiPTBac2(a, b, c);

	getch();
	return 0;
}