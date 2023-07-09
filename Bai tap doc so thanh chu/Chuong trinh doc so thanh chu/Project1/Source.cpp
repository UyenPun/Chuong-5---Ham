#include <iostream>
using namespace std;

void DocSoCo1ChuSo(int x)
{
	if(x == 0)
		cout << "khong ";
	else if(x == 1)
		cout << "mot ";
	else if(x == 2)
		cout << "hai ";
	else if(x == 3)
		cout << "ba ";
	else if(x == 4)
		cout << "bon ";
	else if(x == 5)
		cout << "nam ";
	else if(x == 6)
		cout << "sau ";
	else if(x == 7)
		cout << "bay ";
	else if(x == 8)
		cout << "tam ";
	else if(x == 9)
		cout << "chin ";
}

void DocSoCo2ChuSo(int x)
{
	int HangChuc = x / 10;
	int HangDonVi = x % 10;

	if(HangChuc != 1)
		DocSoCo1ChuSo(HangChuc);

	cout << "muoi ";
	
	if(HangDonVi != 0)
	{
		if(HangDonVi == 5)
			cout << "lam ";
		else
			DocSoCo1ChuSo(HangDonVi);
	}
}

void DocSoCo3ChuSo(int x)
{
	int HangTram = x / 100;
	int HangChucVaDonVi = x % 100;
	int HangChuc = HangChucVaDonVi / 10;
	int HangDonVi = HangChucVaDonVi % 10;

	DocSoCo1ChuSo(HangTram);

	cout << "tram ";

	if(HangChuc != 0)
		DocSoCo2ChuSo(HangChucVaDonVi);
	else
	{
		if(HangDonVi != 0)
		{
			cout << "le ";
			DocSoCo1ChuSo(HangDonVi);
		}
	}
}

void DocPhuAm(int SoDauPhay)
{
	if(SoDauPhay == 1 || SoDauPhay == 4)
		cout << "nghin ";
	else if(SoDauPhay == 2 || SoDauPhay == 5)
		cout << "trieu ";
	else if(SoDauPhay == 3 || SoDauPhay == 6)
		cout << "ty ";
}

int DemSoChuSo(long long int x)
{
	/*int dem = 0;
	
	if(x == 0)
		dem = 1;*/

	int dem = x == 0 ? 1 : 0;

	while(x != 0)
	{
		x /= 10;
		dem++;
	}
	return dem;
}

int main()
{
	long long int n = -123456789;

	long long int temp_n = n;

	if(temp_n < 0)
	{
		temp_n *= -1; // nhân để cho nó thành số dương
		cout << "am ";
	}
	
	//int SoChuSo = temp_n == 0 ? 1 : (long long int)log10((double)temp_n) + 1; // Dùng hàm log10 này để đi tính số chữ số của 1 số sẽ bị sai với trường hợp 999... (15 chữ số 9) nó quá gần với 10^16 => nó tính ra luôn kết quả là 16 chữ số thay vì chỉ có 15 chữ số
	//cout << "\nSo chu so = " << SoChuSo << endl;

	int SoChuSo = DemSoChuSo(temp_n);

	int SoDauPhay = (SoChuSo - 1) / 3;

	long long int LuyThua = pow(10, 3 * SoDauPhay);
		
	int CumSo = temp_n / LuyThua;
	//cout << CumSo << " => ";

	if(CumSo < 10)
		DocSoCo1ChuSo(CumSo);
	else if(CumSo < 100)
		DocSoCo2ChuSo(CumSo);
	else if(CumSo < 1000)
		DocSoCo3ChuSo(CumSo);

	DocPhuAm(SoDauPhay);

	//cout << endl;
	temp_n %= LuyThua;

	while(temp_n != 0)
	{
		SoDauPhay--;
		LuyThua = pow(10, 3 * SoDauPhay);
		
		//cout << temp_n / LuyThua << endl;
		CumSo = temp_n / LuyThua;
		//cout << CumSo << " => ";

		if(CumSo != 0)
		{
			DocSoCo3ChuSo(CumSo);

			DocPhuAm(SoDauPhay);
		}

		//cout << endl;

		temp_n %= LuyThua;
	}
	
	system("pause");
	return 0;
}