#include <iostream>
#include <ctime>
#include <cstring>
#include <conio.h>
#include <string>
#pragma warning(disable: 4996)

using namespace std;

//Bien thong tin doc gia
const int MAX_DOC_GIA = 100;
int readerID = 0;
char name[MAX_DOC_GIA][50];
char UID[MAX_DOC_GIA][15];
char DOB[MAX_DOC_GIA][20];
char sex[MAX_DOC_GIA][3];
char email[MAX_DOC_GIA][50];
char address[MAX_DOC_GIA][100];
char createday[MAX_DOC_GIA][20];
char expireday[MAX_DOC_GIA][20];


//ham nhap thong tin doc gia
void addreader()
{
    if (readerID >= 100) cout << "Khong the chua them du lieu doc gia!" << endl;
    cout << "\nNhap ho ten: ";
    cin.ignore(32767, '\n');
    cin.getline(name[readerID], 50);
    cout << "\nNhap CCCD: ";
    cin >> UID[readerID];
    cout << "\nNhap ngay sinh: ";
    cin >> DOB[readerID];
    cout << "\nChon gioi tinh: 1. Nam || 2. Nu ";
    int sexkey;
    cin >> sexkey;
    while (sexkey != 1 && sexkey != 2)
    {
        cout << "Phim ko hop le,  moi nhap lai phim 1 hoac 2!" << endl;
        cin >> sexkey;
    }
    switch (sexkey)
    {
    case 1:
        strcpy(sex[readerID], "Nam");
        cout << "Gioi tinh la: " << sex[readerID] << endl;
        break;
    case 2:
        strcpy(sex[readerID], "Nu");
        cout << "Gioi tinh la: " << sex[readerID] << endl;
        break;
    }
    cout << "\nNhap email: ";
    cin >> email[readerID];
    cout << "\nNhap dia chi: ";
    cin.ignore(32767, '\n');
    cin.getline(address[readerID], 100);

    // Tao ngay lap the va het han tu dong
    time_t now = time(0);
    tm* ltm = localtime(&now);
    sprintf_s(createday[readerID], "%04d-%02d-%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
    sprintf_s(expireday[readerID], "%04d-%02d-%02d", 1900 + ltm->tm_year + 4, 1 + ltm->tm_mon, ltm->tm_mday);
    cout << "Doc gia da duoc them thanh cong!\n";
    cout << "Ngay lap the: " << createday[readerID] << endl;
    cout << "Ngay het han: " << expireday[readerID] << endl;
    readerID++;
}

// HAM XOA DOC GIA
void deletereader()
{
    char searchUID[1][100]; //Bien tim kiem
    cout << "Nhap so CCCD cua doc gia can xoa" << endl;
    cin >> searchUID[1];
    for (int i = 0; i < readerID; i++)
    {
        if (strstr(UID[i], searchUID[1]) != NULL)
        {
            for (int j = i; j < readerID - 1; j++)
            {
                strcpy(name[j], name[j + 1]);
                strcpy(UID[j], UID[j + 1]);
                strcpy(DOB[j], DOB[j + 1]);
                strcpy(email[j], email[j + 1]);
                strcpy(address[j], address[j + 1]);
                strcpy(sex[j], sex[j + 1]);
                strcpy(createday[j], createday[j + 1]);
                strcpy(expireday[j], expireday[j + 1]);
            }
            readerID--;
            cout << "Da xoa doc gia co so CCCD " << searchUID[1][15] << " thanh cong!" << endl;
        }
    }
    cout << "Khong tim thay doc gia co so CCCD da nhap!" << endl;
}

// Thong ke doc gia theo gioi tinh
void readergenderstat()
{
    int countman = 0, countwoman = 0;
    cout << "\nNhap gioi tinh can loc: 1. Nam  || 2. Nu" << endl;
    int key;
    cin >> key;
    while (key != 1 && key != 2)
    {
        cout << "Phim khong hop le! Moi nhap phim 1 hoac 2!" << endl;
        cin >> key;
    }
    switch (key)
    {
    case 1:
        for (int i = 0; i < readerID; i++)
        {
            if (strcmp(sex[readerID], "Nam") == 0)
                countman++;
        }
        cout << "So doc gia nam trong thu vien la: " << countman << " nguoi!" << endl;
        break;
    case 2:
        for (int i = 0; i < readerID; i++)
        {
            if (strcmp(sex[readerID], "Nu") == 0)
                countwoman++;
        }
        cout << "So doc gia nu trong thu vien la: " << countwoman << " nguoi!" << endl;
        break;
    }
}