/*
Yêu cầu nâng cao 5: Nếu như ở yêu cầu trước phải nhập xong hết 1 số rồi enter thì nó mới hiện ra số đó có các dấu phẩy ngăn cách và cách đọc của số đó thì bây giờ chúng ta sẽ nâng cấp nó lên 1 phiên bản tối ưu hơn như sau:

Đó là ngay khi nhấn xuống phím số thì chữ số đó hiện ra trên màn hình kèm theo cách đọc tương ứng và chữ số hiện ra đó được ngăn cách các dấu phẩy

vd:
Nhấn phím 1
trên màn hình hiện ra:
1
một

Nhấn phím 2
trên màn hình hiện ra:
12
mười hai

Nhấn phím 3
trên màn hình hiện ra:
123
một trăm hai mươi ba

Nhấn phím 4
trên màn hình hiện ra:
1,234
một nghìn hai trăm ba mươi bốn

Nhấn phím 5
trên màn hình hiện ra:
12,345
mười hai nghìn ba trăm bốn mươi lăm

Nhấn phím 6
trên màn hình hiện ra:
123,456
một trăm hai mươi ba nghìn bốn trăm năm mươi sáu

Nhấn phím 7
trên màn hình hiện ra:
1,234,567
một triệu hai trăm ba mươi bốn nghìn năm trăm sáu mươi bảy

...

Nếu giả sử nhấn phím xóa thì nó sẽ xóa đi chữ số cuối cùng của số đang có hiện tại và cập nhật lại

Nhấn phím xóa (backspace)
trên màn hình hiện ra:
123,456
một trăm hai mươi ba nghìn bốn trăm năm mươi sáu

Nhấn phím xóa (backspace)
trên màn hình hiện ra:
12,345
mười hai nghìn ba trăm bốn mươi lăm

Nhấn phím xóa (backspace)
trên màn hình hiện ra:
1,234
một nghìn hai trăm ba mươi bốn

Lưu ý: Mỗi lần nhấn phím số hay phím xóa thì nó sẽ xóa dữ liệu màn hình trước đó mà hiển thị lại giá trị mới, tức là lúc nào màn hình cũng chỉ có duy nhất 2 dòng được xuất ra trong đó 1 dòng là số, 1 dòng là chữ
*/

#include <iostream>
#include <conio.h>
#include <io.h> // thư viện định nghĩa cho hàm _setmode
#include <fcntl.h> // thư viện định nghĩa cho hàm _setmode
#include <Windows.h>
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
	_setmode(_fileno(stdout), _O_WTEXT); // Kích hoạt chế độ bảng mã Unicode (có dấu)
	wcout << L"Mời bạn nhập vào giá trị số: " << endl;
	char c;
	long long int number = 0;
	long long int Maximum_Value_Type = (long long int)pow(2, 8 * sizeof(number) - 1) - 1;
	while(true)
	{
		c = getch();
		
		if((c >= '0' && c <= '9') || c == 8)
		{
			if(c >= '0' && c <= '9')
			{
				if(number > (Maximum_Value_Type - ((int)c - 48)) / 10)
				{
					wcout << L"\nBạn đã vượt quá giới hạn lưu trữ";
					Sleep(1000);
				}
				else
					number = number * 10 + (c - 48);
			}
			else if(c == 8) // back space
			{
				number /= 10; // bỏ đi chữ số cuối
			}
			system("cls");
			wcout << L"Mời bạn nhập vào giá trị số: " << endl;
			PhanCachDauPhayGiuaCacCumSo(number);
			wcout << endl;
			DocSoThanhChu(number);
		}
	}

	system("pause");
	return 0;
}