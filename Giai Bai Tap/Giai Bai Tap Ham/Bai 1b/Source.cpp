/*
ax + b = 0
cách giải: biện luận theo hệ số
đi kèm với ẩn có mũ cao nhất

TH1:
+ a = 0
	=> pt co dang: b = 0
	+ b = 0 => pt vô số nghiệm
	+ b != 0 => pt vô nghiệm

TH2:
a != 0 => tính nghiệm x = -b/a
*/
#include <stdio.h>
#include <conio.h>

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

int main()
{
	double a, b, x;
	NhapDuLieu(a);
	NhapDuLieu(b);
	GiaiPTBac1(a, b);

	// giả sử ở dưới này ta có nhu cầu lấy nghiệm x ra để xử lý thì làm sao ???
	// => truyền tham chiếu x vào thủ tục GiaiPTBac1

	getch();
	return 0;
}


