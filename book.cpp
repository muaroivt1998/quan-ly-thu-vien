#include <iostream>
#include <cstring>
#include <conio.h>
#include <string>
#include <cmath>
using namespace std;

const int MAX_SACH = 100;

//Bien thong tin ve sach
char isbn[MAX_SACH][100];
char name_of_book[MAX_SACH][100];
char author[MAX_SACH][100];
char NXB[MAX_SACH][100];
int yearXB[MAX_SACH];
char type_of_book[MAX_SACH][100];
double price[MAX_SACH];
int sl[MAX_SACH];
int book = 0;

//ham nhap thong tin sach
void addbook()
{
    if (book >= 100) cout << "Khong the them sach vao du lieu thu vien! Da dat gioi han toi da." << endl;
    cout << "\nNhap ISBN: ";
    cin >> isbn[book];
    cout << "\nNhap ten sach: ";
    cin.ignore(32767, '\n');
    cin.getline(name_of_book[book], 100);
    cout << "\nNhap tac gia: ";
    cin.ignore(32767, '\n');
    cin.getline(author[book], 100);
    cout << "\nNhap ten NXB: ";
    cin.ignore(32767, '\n');
    cin.getline(NXB[book], 100);
    cout << "\nNhap nam xuat ban: ";
    cin >> yearXB[book];
    cout << "\nNhap the loai sach: ";
    cin.ignore(32767, '\n');
    cin.getline(type_of_book[book], 100);
    cout << "\nNhap gia tien sach: ";
    cin >> price[book];
    cout << endl;
    cout << "Nhap so luong sach: ";
    cin >> sl[book];
    cout << endl;
    book++;
}

//Ham xoa thong tin sach
void deletebook()
{
    char searchbook[1][100]; //Bien tim kiem
    cout << "Nhap ten sach";
    cin >> searchbook[1];
    for (int i = 0; i < book; i++)
    {
        if (strstr(name_of_book[i], searchbook[1]) != NULL)
        {
            for (int j = i; j < book - 1; j++)
            {
                strcpy_s(name_of_book[j], name_of_book[j + 1]);
                strcpy_s(isbn[j], isbn[j + 1]);
                strcpy_s(author[j], author[j + 1]);
                strcpy_s(NXB[j], NXB[j + 1]);
                yearXB[j] = yearXB[j + 1];
                strcpy_s(type_of_book[j], type_of_book[j + 1]);
                price[j] = price[j + 1];
                sl[j] = sl[j + 1];
            }
            book--;
            cout << "Da xoa toan bo thong tin cua sach: " << searchbook[1][100] << " thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay sach co ten da nhap!" << endl;
}

// Thong ke sach theo the loai
void booktypestat()
{
    char searchtype[1][100];
    int count = 0;
    cout << "\nNhap the loai sach can loc!" << endl;
    cin >> searchtype[1];
    for (int i = 0; i < book; i++)
    {
        if (strcmp(type_of_book[book], searchtype[1]) == 0)
            count++;
    }
    cout << "Co " << count << " sach theo the loai " << searchtype[1][100] << " trong thu vien!" << endl;
}


//BIEN CHO THE MUON VA TRA SACH
#define MAX_CARD 100
#define MAX_BORROW_BOOK 5

long long borrowday[MAX_CARD], borrowmonth[MAX_CARD], borrowyear[MAX_CARD];
long long calreturnday[MAX_CARD], calreturnmonth[MAX_CARD], calreturnyear[MAX_CARD];
long long realreturnday[MAX_CARD], realreturnmonth[MAX_CARD], realreturnyear[MAX_CARD];
char readerborrow[MAX_CARD][15];
char UID_of_borrowbook[MAX_CARD][MAX_BORROW_BOOK][20];
int numborrowbook[MAX_CARD];
int numcard = 0; // so luong phieu
int maxd = 0;
int mo[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int tim = -1;
double sumfinefee[MAX_CARD], lostfinefee[MAX_CARD], delayfinefee[MAX_CARD], delayday[MAX_CARD];

//PHIEU MUON SACH
void borrowbook()
{
    if (numcard >= MAX_CARD)
        cout << "Khong the lap them phieu!" << endl;
    cout << "Nhap ma CCCD doc gia: " << endl;
    cin >> readerborrow[numcard];
    cout << "Nhap nam muon: " << endl;
    cin >> borrowyear[numcard];
    cout << "Nhap thang muon: " << endl;
    cin >> borrowmonth[numcard];
    cout << "Nhap ngay muon: " << endl;
    cin >> borrowday[numcard];
    if ((borrowyear[numcard] % 400 == 0 || (borrowyear[numcard] % 4 == 0 && borrowyear[numcard] % 100 != 0)))
        mo[1] = 29;
    while (borrowmonth[numcard] >= 13 || borrowmonth[numcard] <= 0 || borrowday[numcard] <= 0 || borrowday[numcard] > mo[borrowmonth[numcard] - 1])
    {
        cout << "Date is not existed \n";
        cout << "Nhap thang muon: " << endl;
        cin >> borrowmonth[numcard];
        cout << "Nhap ngay muon: " << endl;
        cin >> borrowday[numcard];
    }
    cout << "Ngay muon the: " << borrowday[numcard] << "/" << borrowmonth[numcard] << "/" << borrowyear[numcard] << endl;
    calreturnday[numcard] = borrowday[numcard] + 7;
    calreturnmonth[numcard] = borrowmonth[numcard];
    calreturnyear[numcard] = borrowyear[numcard];
    if (calreturnday[numcard] > mo[borrowmonth[numcard] - 1])
    {
        calreturnmonth[numcard]++;
        calreturnday[numcard] = calreturnday[numcard] - mo[borrowmonth[numcard] - 1];
        if (calreturnmonth[numcard] >= 13)
        {
            calreturnyear[numcard]++;
            calreturnmonth[numcard] = 1;
        }
    }
    cout << "Ngay du kien tra the: " << calreturnday[numcard] << "/" << calreturnmonth[numcard] << "/" << calreturnyear[numcard] << endl;
    cout << "Nhap so luong sach muon (toi da " << MAX_BORROW_BOOK << "): ";
    cin >> numborrowbook[numcard];
    for (int i = 0; i < numborrowbook[numcard]; i++)
    {
        cout << "Nhap ISBN sach thu " << i + 1 << ": ";
        cin >> UID_of_borrowbook[numcard][i];
    }
    cout << "Phieu muon da duoc lap.\n";
    numcard++;
}

// PHIEU TRA SACH
void returnbook()
{
    char searchUID[1][20];
    cout << "Nhap so CCCD doc gia muon tra sach: ";
    cin >> searchUID[1];
    for (int i = 0; i < numcard; i++)
    {
        if (strstr(readerborrow[i], searchUID[1]) != NULL)
        {
            tim = i;
            break;
        }
    }
    if (tim == -1)
    {
        cout << "Khong tim thay phieu muon chua tra!\n";
    }
    cout << "Nhap nam tra thuc te: " << endl;
    cin >> realreturnyear[numcard];
    cout << "Nhap thang tra thuc te: " << endl;
    cin >> realreturnmonth[numcard];
    cout << "Nhap ngay tra thuc te: " << endl;
    cin >> realreturnday[numcard];
    if ((realreturnyear[numcard] % 400 == 0 || (realreturnyear[numcard] % 4 == 0 && realreturnyear[numcard] % 100 != 0)))
        mo[1] = 29;
    while (realreturnmonth[numcard] >= 13 || realreturnmonth[numcard] <= 0 || realreturnday[numcard] <= 0 || realreturnday[numcard] > mo[realreturnmonth[numcard] - 1])
    {
        cout << "Date is not existed \n";
        cout << "Nhap thang tra thuc te: " << endl;
        cin >> realreturnmonth[numcard];
        cout << "Nhap ngay tra thuc te: " << endl;
        cin >> realreturnday[numcard];
    }
    cout << "Ngay tra sach thuc te: " << realreturnday[numcard] << "/" << realreturnmonth[numcard] << "/" << realreturnyear[numcard] << endl;
    delayday[numcard] = 0; lostfinefee[numcard] = 0; delayfinefee[numcard] = 0; sumfinefee[numcard] = 0;
    if ((realreturnday[numcard] > calreturnday[numcard]) && (realreturnmonth[numcard] == calreturnmonth[numcard]) && (realreturnyear[numcard] == calreturnyear[numcard]))
    {
        delayday[numcard] = realreturnday[numcard] - calreturnday[numcard];
    }
    if ((realreturnmonth[numcard] > calreturnmonth[numcard]) && (realreturnyear[numcard] == calreturnyear[numcard]))
    {
        delayday[numcard] = (realreturnmonth[numcard] - calreturnmonth[numcard]) * 30 - (calreturnday[numcard] - realreturnday[numcard]);
    }
    if (realreturnyear[numcard] > calreturnyear[numcard])
    {
        delayday[numcard] = (realreturnyear[numcard] - calreturnyear[numcard]) * 365 - (calreturnmonth[numcard] - realreturnmonth[numcard]) * 30 - (calreturnday[numcard] - realreturnday[numcard]);
    }
    if (delayday[numcard] > 0)
    {
        delayfinefee[numcard] = delayday[numcard] * 5000 * numborrowbook[tim];
        cout << "Tra tre " << delayday[numcard] << " ngay. Phat tre han: " << delayfinefee[numcard] << " VND\n";
    }
    else
    {
        cout << "Tra dung han. Khong co tien phat do tre han.\n";
    }

    // Tinh tien phat lam mat sach
    for (int i = 0; i < numborrowbook[tim]; i++)
    {
        char ans;
        cout << "Sach [" << UID_of_borrowbook[tim][i] << "] co bi mat khong? (y/n): ";
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            int lostprice[MAX_CARD][MAX_BORROW_BOOK];
            cout << "Nhap gia tien sach (VND): ";
            cin >> lostprice[tim][i];
            lostfinefee[numcard] = lostfinefee[numcard] + lostprice[tim][i] * 2;
        }
    }
    sumfinefee[numcard] = delayfinefee[numcard] + lostfinefee[numcard];
    cout << "Tong tien phat: " << sumfinefee[numcard] << " VND\n";
    cout << "Phieu tra da duoc cap nhat.\n";
}