#include <iostream>
#include <ctime>
#include <cstring>
#include <conio.h>
#include <ctype.h>
#include <string>
#pragma warning(disable: 4996)
using namespace std;

//Bien thong tin doc gia
const int MAX_DOC_GIA = 100;
const int MAX_SACH = 100;
const int MAX_PHIEU = 100;
int readerID = 0;
char name[MAX_DOC_GIA][50];
char UID[MAX_DOC_GIA][15];
char DOB[MAX_DOC_GIA][20];
char sex[MAX_DOC_GIA][10];
char email[MAX_DOC_GIA][50];
char address[MAX_DOC_GIA][100];
char createday[MAX_DOC_GIA][20];
char expireday[MAX_DOC_GIA][20];

//Bien thong tin ve sach
char isbn[MAX_SACH][20];
char name_of_book[MAX_SACH][100];
char author[MAX_SACH][50];
char NXB[MAX_SACH][50];
int yearXB[MAX_SACH];
char type_of_book[MAX_SACH][30];
double price[MAX_SACH];
int borrow[MAX_SACH];

//ham nhap thong tin doc gia
void addreader()
{
    readerID++;
    cout << "\nNhap ho ten: ";
    cin.ignore(32767,'\n');
    cin.getline(name[readerID], 50);
    cout << "\nNhap CCCD: ";
    cin >> UID[readerID];
    cout << "\nNhap ngay sinh: ";
    cin >> DOB[readerID];
    cout << "\nNhap gioi tinh: ";
    cin >> sex[readerID];
    cout << "\nNhap email: ";
    cin >> email[readerID];
    cout << "\nNhap dia chi: ";
    cin.ignore(32767, '\n');
    cin.getline(address[readerID], 100);

    // Tạo ngày lập thẻ và ngày hết hạn tự động
    time_t now = time(0);
    tm* ltm = localtime(&now);
    sprintf_s(createday[readerID], "%04d-%02d-%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
    sprintf_s(expireday[readerID], "%04d-%02d-%02d", 1900 + ltm->tm_year + 4, 1 + ltm->tm_mon, ltm->tm_mday);

    cout << "Độc giả đã được thêm thành công!\n";
    cout << "Ngày lập thẻ: " << createday[readerID] << endl;
    cout << "Ngày hết hạn: " << expireday[readerID] << endl;
}

//Ham luu thong tin doc gia

void printline(int n) 
{
	cout << endl;
	for (int i = 0; i < n; i++) 
		cout << "_";
	cout << endl;
}
void pressAnyKey() 
{
	cout << "\nBam phim bat ky de tiep tuc...";
    _getch();
	system("cls");
}

int main()
{   
    int key;
    char filename[] = "book.txt";
    while (true)
    {
        cout << "CHUONG TRINH QUAN LY THU VIEN\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them doc gia.                                 **\n";
        cout << "**  2. Cap nhat thong tin doc gia theo CCCD.         **\n";
        cout << "**  3. Xoa thong tin doc gia theo CCCD.              **\n";
        cout << "**  4. Tim kiem doc gia theo ten/CCCD.               **\n";
        cout << "**  5. Tim kiem sach theo doc gia.                   **\n";
        cout << "**  6. Hien thi danh sach doc gia.                   **\n";
        cout << "**  0. Thoat.                                        **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            cout << "\n1. Them doc gia.";
            addreader();
            cout << "\nThem doc gia thanh cong!";
            pressAnyKey();
            break;
        case 2:
            if (readerID > 0)
            {
                cout << "\n2. Cap nhat thong tin doc gia theo CCCD. ";
                cout << "\n Nhap so CCCD: "; cin >> UID[15];
            }
            else cout << "\nKhong co doc gia nao!";
            for (int i = 0; i <= readerID; i++)
            {

            }
            pressAnyKey();
            break;
        case 3:
            if (readerID > 0)
            {
                cout << "\n3. Xoa doc gia theo CCCD.";
                cout << "\n Nhap ID: "; cin >> UID[15];
            }
            pressAnyKey();
            break;
        case 4:
            if (readerID > 0)
            {
                cout << "\n4. Tim kiem doc gia theo ten.";
                cout << "\nNhap ten de tim kiem: "; 
                cin >> name[50];
                fflush(stdin);
            }
            else cout << "\nKhong tim thay doc gia tuong ung!";
            pressAnyKey();
            break;
        case 5:
            if (readerID > 0)
            {
                cout << "\n5. Tim kiem sach theo doc gia.";
            }
            else cout << "\nKhong tim thay doc gia muon sach nay";
            pressAnyKey();
            break;
            //Hien thi danh sach doc gia 
        case 6:
            if (readerID > 0)
            {
                cout << "\n6. Hien thi danh sach doc gia.";
            }
            else cout << "\nDanh sach doc gia trong";
            for (int i = 1; i <= readerID; i++)
            {
                printline(100);
                cout << "Ma doc gia: " << i << endl;
                cout << "Ho ten: " << name[i] << endl;
                cout << "CCCD: " << UID[i] << endl;
                cout << "Ngay sinh:  " << DOB[i] << endl;
                cout << "Gioi tinh: " << sex[i] << endl;
                cout << "Dia chi: " << address[i] << endl;
                cout << "Ngay lap the: " << createday[i] << endl;
                cout << "Ngay het han: " << expireday[i] << endl;
                pressAnyKey();
                break;   
        case 0:
            cout << "\nBan da chon thoat chuong trinh!";
            _getch();
            system("clear");
            // Thong bao neu nhap phim khong hop le
        default:
            cout << "\nPhim khong hop le! Hay nhap so tuong ung voi chuc nang trong menu.";
            pressAnyKey();
            break;
        }
    }
}
