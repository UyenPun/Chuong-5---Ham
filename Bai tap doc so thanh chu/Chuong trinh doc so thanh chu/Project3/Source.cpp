/* 
Yêu cầu nâng cao 4: Khi xuất ra số cần đọc thành chữ thì số xuất ra phải tự ngăn cách những dấu phẩy để cho người sử dụng chương trình dễ dò bằng mắt thay vì phải ngồi duyệt tay
vd: Nhập vào số: 123456789987654321
Kết quả xuất ra màn hình sẽ trông như thế này:
123,456,789,987,654,321: một trăm hai mươi ba triệu bốn trăm năm mươi sáu nghìn bảy trăm tám mươi chín tỷ chín trăm tám mươi bảy triệu sáu trăm năm mươi bốn nghìn ba trăm hai mươi mốt
*/

#include <iostream>
#include <io.h> // thư viện định nghĩa cho hàm _setmode
#include <fcntl.h> // thư viện định nghĩa cho hàm _setmode
#include <stdlib.h>
#include <conio.h>
using namespace std;

void DocSoCo1ChuSo(int x)
{
	if(x == 0)
		wcout << L"không ";
	else if(x == 1)
		wcout << L"một ";
	else if(x == 2)
		wcout << "hai ";
	else if(x == 3)
		wcout << "ba ";
	else if(x == 4)
		wcout << L"bốn ";
	else if(x == 5)
		wcout << L"năm ";
	else if(x == 6)
		wcout << L"sáu ";
	else if(x == 7)
		wcout << L"bảy ";
	else if(x == 8)
		wcout << L"tám ";
	else if(x == 9)
		wcout << L"chín ";
}

void DocSoCo2ChuSo(int x)
{
	int HangChuc = x / 10;
	int HangDonVi = x % 10;

	if(HangChuc != 1)
	{
		DocSoCo1ChuSo(HangChuc);
		wcout << L"mươi ";
	}
	else
		wcout << L"mười ";

	if(HangDonVi != 0)
	{
		if(HangDonVi == 5)
			wcout << L"lăm ";
		else if(HangChuc > 1 && HangDonVi == 1)
			wcout << L"mốt ";
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

	wcout << L"trăm ";

	if(HangChuc != 0)
		DocSoCo2ChuSo(HangChucVaDonVi);
	else
	{
		if(HangDonVi != 0)
		{
			wcout << L"lẻ ";
			DocSoCo1ChuSo(HangDonVi);
		}
	}
}

void DocPhuAm(int SoDauPhay)
{
	//if(SoDauPhay == 1 || SoDauPhay == 4 || SoDauPhay == 7 || SoDauPhay == 10 || SoDauPhay == 13)
	if(SoDauPhay % 3 == 1)
		wcout << L"nghìn ";
	//else if(SoDauPhay == 2 || SoDauPhay == 5 || SoDauPhay == 8 || SoDauPhay == 11 || SoDauPhay == 14)
	else if(SoDauPhay % 3 == 2)
		wcout << L"triệu ";
	//else if(SoDauPhay == 3 || SoDauPhay == 6 || SoDauPhay == 9 || SoDauPhay == 12 || SoDauPhay == 15)
	else if(SoDauPhay % 3 == 0 && SoDauPhay != 0)
		wcout << L"tỷ ";
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

void PhanCachDauPhayGiuaCacCumSo(long long int n)
{
	if(n < 0)
	{
		n *= -1; // nhân để cho nó thành số dương
		wcout << "-";
	}

	int SoChuSo = DemSoChuSo(n);

	int SoDauPhay = (SoChuSo - 1) / 3;

	long long int LuyThua = pow(10, 3 * SoDauPhay);
		
	int CumSo = n / LuyThua;
	wcout << CumSo;

	n %= LuyThua;

	SoDauPhay--;
	
	while(SoDauPhay >= 0)
	{
		LuyThua = pow(10, 3 * SoDauPhay);
		
		CumSo = n / LuyThua;
		wcout << ",";
		wprintf(L"%03d", CumSo); // %03d nghĩa là xuất ra số phải đủ 3 chữ số, nếu không đủ 3 chữ số thì xuất kèm theo ở trước đó những chữ số 0 sao cho gom đủ thành 3 chữ số
		
		/*
		// Đoạn code này sẽ dùng nếu như không nhớ được hay không biết hàm wprintf với định dạng %03d ở trên
		if(DemSoChuSo(CumSo) == 1)
			wcout << "00";
		else if(DemSoChuSo(CumSo) == 2)
			wcout << "0";

		wcout << CumSo;
		*/

		n %= LuyThua;

		SoDauPhay--;
	}
}

void DocSoThanhChu(long long int n)
{
	if(n < 0)
	{
		n *= -1; // nhân để cho nó thành số dương
		wcout << L"âm ";
	}

	int SoChuSo = DemSoChuSo(n);

	int SoDauPhay = (SoChuSo - 1) / 3;

	long long int LuyThua = pow(10, 3 * SoDauPhay);
		
	int CumSo = n / LuyThua;

	if(CumSo < 10)
		DocSoCo1ChuSo(CumSo);
	else if(CumSo < 100)
		DocSoCo2ChuSo(CumSo);
	else if(CumSo < 1000)
		DocSoCo3ChuSo(CumSo);

	DocPhuAm(SoDauPhay);

	n %= LuyThua;

	SoDauPhay--;
	
	while(SoDauPhay >= 0)
	{
		LuyThua = pow(10, 3 * SoDauPhay);
		
		CumSo = n / LuyThua;
	
		if(CumSo != 0)
		{
			DocSoCo3ChuSo(CumSo);

			DocPhuAm(SoDauPhay);
		}
		else
		{
			if(SoDauPhay == 3 || SoDauPhay == 6)
				wcout << L"tỷ ";
		}

		n %= LuyThua;

		SoDauPhay--;
	}
}

int main()
{
quaylai:
	_setmode(_fileno(stdout), _O_WTEXT); // Kích hoạt chế độ bảng mã Unicode (có dấu)
	
	// [a, b] => a + rand() % (b - a + 1)
	// [0, 10 tỷ] => 0 + rand() % 1000000001
	long long int n;
	wcout << L"Nhập vào giá trị số cần đọc: ";
	cin >> n;
	PhanCachDauPhayGiuaCacCumSo(n);
	wcout << endl;
	DocSoThanhChu(n);

	wcout << L"\n\nBạn có muốn tiếp tục không? Nhấn phím c để tiếp tục";
	char c = getch();
	if(c == 'c' || c == 'C')
	{
		system("cls");
		goto quaylai;
	}

	system("pause");
	return 0;
}