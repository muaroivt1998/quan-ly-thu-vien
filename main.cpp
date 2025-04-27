#include <iostream>
#include <ctime>
#include <cstring>
#include <conio.h>
#include <string>
#include <cmath>
#include "Header.h"
#pragma warning(disable: 4996)
using namespace std;

// Ham bam phim bat ky de thoat tac vu
void pressAnyKey()
{
    cout << "\nBam phim bat ky de tiep tuc...";
    _getch();
    cin.ignore();
    system("cls");
}

// Ham in cac ky tu "_" lien tiep de ngan cach
void printline(int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << "_";
    cout << endl;
}


// CHUONG TRINH CHINH KET HOP QUAN LY DOC GIA VÀ SACH
int main()
{
    int key;
    while (true)
    {
        cout << "CHUONG TRINH QUAN LY DOC GIA\n";
        cout << "*************************MENU*****************************************\n";
        cout << "**  1. Them doc gia.                                                **\n";
        cout << "**  2. Cap nhat thong tin doc gia theo CCCD.                        **\n";
        cout << "**  3. Xoa thong tin doc gia theo CCCD.                             **\n";
        cout << "**  4. Tim kiem doc gia theo CCCD.                                  **\n";
        cout << "**  5. Tim kiem doc gia theo ho ten.                                **\n";
        cout << "**  6. Hien thi danh sach doc gia.                                  **\n";
        cout << "**  7. Them sach vao thu vien.                                      **\n";
        cout << "**  8. Cap nhat thong tin sach.                                     **\n";
        cout << "**  9. Xoa thong tin sach khoi thu vien.                            **\n";
        cout << "**  10. Tim kiem sach theo ISBN.                                    **\n";
        cout << "**  11. Tim kiem sach theo ten.                                     **\n";
        cout << "**  12. Hien thi du lieu sach trong thu vien.                       **\n";
        cout << "**  13. Lap phieu muon sach thu vien.                               **\n";
        cout << "**  14. Lap phieu tra sach thu vien.                                **\n";
        cout << "**  15. Thong ke so luong sach trong thu vien.                      **\n";
        cout << "**  16. Thong ke so luong sach theo the loai trong thu vien.        **\n";
        cout << "**  17. Thong ke so luong doc gia trong thu vien.                   **\n";
        cout << "**  18. Thong ke so luong doc gia theo gioi tinh trong thu vien.    **\n";
        cout << "**  0. Thoat chuong trinh.                                          **\n";
        cout << "**********************************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            cout << "\n1. Them doc gia.";
            cout << "Nhap so luong doc gia can them: " << endl;
            int n;
            cin >> n;
            if (n == 1)
            {
                addreader();
                cout << "\nThem doc gia thanh cong!";
            }
            if (n >= 2)
            {
                for (int i = 1; i < n; i++)
                {
                    addreader();
                    cout << "\nThem doc gia thanh cong!";
                    cout << "\nNhan Enter 1 lan truoc khi tiep tuc!";
                }
                addreader();
                cout << "\nThem doc gia thanh cong!";
            }
            pressAnyKey();
            break;
        case 2:
            char searchUID[1][15];
            if (readerID > 0)
            {
                cout << "\n2. Cap nhat thong tin doc gia theo CCCD. ";
                cout << "\n Nhap so CCCD: ";
                cin >> searchUID[1];
            }
            else cout << "\nKhong co doc gia nao!";
            for (int i = 0; i < readerID; i++)
            {
                if (strstr(UID[i], searchUID[1]) != NULL)
                {
                    cout << "**  1. Cap nhat ho ten.                               \n";
                    cout << "**  2. Cap nhat so CCCD.                              \n";
                    cout << "**  3. Cap nhat ngay sinh.                            \n";
                    cout << "**  4. Cap nhat gioi tinh.                            \n";
                    cout << "**  5. Cap nhat email                                 \n";
                    cout << "**  6. Cap nhat dia chi                               \n";
                    cout << "**  0. Tro ve man hinh chinh.                         \n";
                    cout << "******************************************************\n";
                    cout << "Nhap tuy chon: ";
                    cin >> key;
                    switch (key)
                    {
                    case 1:
                        cout << "Moi nhap ho ten moi: " << endl;
                        cin >> name[i];
                        cout << "Ho ten moi la: " << name[i] << endl;
                        fflush(stdin);
                        pressAnyKey();
                        break;
                    case 2:
                        cout << "Moi nhap so CCCD moi: " << endl;
                        cin >> UID[i];
                        cout << "So CCCD moi la: " << UID[i] << endl;
                        fflush(stdin);
                        pressAnyKey();
                        break;
                    case 3:
                        cout << "Moi nhap ngay sinh moi: " << endl;
                        cin >> DOB[i];
                        cout << "Ngay sinh moi la: " << DOB[i] << endl;
                        fflush(stdin);
                        pressAnyKey();
                        break;
                    case 4:
                        cout << "Moi nhap gioi tinh moi: " << endl;
                        cin >> sex[i];
                        cout << "Gioi tinh moi la: " << sex[i] << endl;
                        fflush(stdin);
                        pressAnyKey();
                        break;
                    case 5:
                        cout << "Moi nhap email moi: " << endl;
                        cin >> email[i];
                        cout << "Dia chi email moi la: " << email[i] << endl;
                        fflush(stdin);
                        pressAnyKey();
                        break;
                    case 6:
                        cout << "Moi nhap dia chi moi: " << endl;
                        cin >> address[i];
                        cout << "Dia chi moi la: " << address[i] << endl;
                        fflush(stdin);
                        pressAnyKey();
                        break;
                    case 0:
                        cout << "\nTro ve man hinh quan ly!";
                        _getch();
                        main();
                        // Thong bao neu nhap phim khong hop le
                    default:
                        cout << "\nPhim khong hop le! Hay nhap so tuong ung voi chuc nang trong menu.";
                        pressAnyKey();
                        break;
                    }
                }
            }
            pressAnyKey();
            break;
        case 3:
            cout << "\n3. Xoa doc gia theo so CCCD.";
            deletereader();
            pressAnyKey();
            break;
        case 4:
            int i;
            if (readerID > 0)
            {
                cout << "\n4. Tim kiem doc gia theo CCCD.";
                cout << "\nNhap so CCCD de tim kiem: ";
                cin >> searchUID[1][100];
                for (i = 0; i < readerID; i++)
                {
                    if (strstr(UID[i], searchUID[1]) != NULL)
                    {
                        cout << "Da tim thay doc gia tuong ung:" << endl;
                        cout << i + 1 << ". " << name[i] << endl;
                        cout << "So CCCD: " << UID[i] << endl;
                        cout << "Ngay sinh: " << DOB[i] << endl;
                        cout << "Gioi tinh: " << sex[i] << endl;
                        cout << "Email: " << email[i] << endl;
                        cout << "Dia chi: " << address[i] << endl;
                        cout << "Ngay lap the: " << createday[i] << endl;
                        cout << "Ngay het han: " << expireday[i] << endl;
                    }
                }
                fflush(stdin);
                if (i >= readerID) cout << "\nKhong tim thay doc gia tuong ung!";
            }
            else cout << "Khong ton tai doc gia nao!" << endl;
            pressAnyKey();
            break;
        case 5:
            char searchname[1][50]; // Bien tim kiem
            if (readerID > 0)
            {
                cout << "\n5. Tim kiem doc gia theo ten.";
                cout << "\nNhap ten doc gia de tim kiem: ";
                cin >> searchname[1];
                for (i = 0; i < readerID; i++)
                {
                    if (strstr(name[i], searchname[1]) != NULL)
                    {
                        cout << "Da tim thay doc gia tuong ung:" << endl;
                        cout << i + 1 << ". " << name[i] << endl;
                        cout << "So CCCD: " << UID[i] << endl;
                        cout << "Ngay sinh: " << DOB[i] << endl;
                        cout << "Gioi tinh: " << sex[i] << endl;
                        cout << "Email: " << email[i] << endl;
                        cout << "Dia chi: " << address[i] << endl;
                        cout << "Ngay lap the: " << createday[i] << endl;
                        cout << "Ngay het han: " << expireday[i] << endl;
                    }
                }
                fflush(stdin);
                if (i >= readerID) cout << "\nKhong tim thay doc gia tuong ung!";
            }
            else cout << "Khong ton tai doc gia nao!" << endl;
            pressAnyKey();
            break;
            //Hien thi danh sach doc gia 
        case 6:
            if (readerID > 0)
            {
                cout << "\n6. Hien thi danh sach doc gia.";
            }
            else cout << "\nDanh sach doc gia trong";
            for (int i = 0; i < readerID; i++)
            {
                printline(100);
                cout << "Ma doc gia: " << i + 1 << endl;
                cout << "Ho ten: " << name[i] << endl;
                cout << "CCCD: " << UID[i] << endl;
                cout << "Email: " << email[i] << endl;
                cout << "Ngay sinh:  " << DOB[i] << endl;
                cout << "Gioi tinh: " << sex[i] << endl;
                cout << "Dia chi: " << address[i] << endl;
                cout << "Ngay lap the: " << createday[i] << endl;
                cout << "Ngay het han: " << expireday[i] << endl;
            }
            pressAnyKey();
            break;
        case 7:
            cout << "\n7. Them sach.";
            cout << "Nhap so luong sach can them" << endl;
            cin >> n;
            if (n == 1)
            {
                addbook();
                cout << "\nThem sach thanh cong!";
            }
            if (n >= 2)
            {
                for (int i = 1; i < n; i++)
                {
                    addbook();
                    cout << "\nThem sach thanh cong!";
                    cout << "\nNhan Enter 1 lan truoc khi tiep tuc!";
                }
                addbook();
                cout << "\nThem sach thanh cong!";
            }
        case 8:
            char searchbook[1][100];
            if (book > 0)
            {
                cout << "\n8. Cap nhat thong tin sach";
                cout << "\n Nhap ten sach: ";
                cin >> searchbook[1];
            }
            else cout << "\nKhong co sach nao trong du lieu!";
            for (int i = 0; i < book; i++)
            {
                if (strstr(name_of_book[i], searchbook[1]) != NULL)
                {
                    cout << "**  1. Cap nhat so ISBN.\n";
                    cout << "**  2. Cap nhat ten sach.\n";
                    cout << "**  3. Cap nhat ten tac gia.\n";
                    cout << "**  4. Cap nhat NXB.\n";
                    cout << "**  5. Cap nhat nam xuat ban.\n";
                    cout << "**  6. Cap nhat the loai.\n";
                    cout << "**  7. Cap nhat gia tien.\n";
                    cout << "**  8. Cap nhat so luong.\n";
                    cout << "**  0. Tro ve man hinh quan ly.\n";
                    cout << "*******************************************************\n";
                    cout << "Nhap tuy chon: ";
                    cin >> key;
                    switch (key)
                    {
                    case 1:
                        cout << "Moi nhap so ISBN moi: " << endl;
                        cin >> isbn[i];
                        cout << "So ISBN moi la: " << isbn[i] << endl;
                        fflush(stdin);
                        pressAnyKey();
                        break;
                    case 2:
                        cout << "Moi cap nhat ten sach: " << endl;
                        cin >> name_of_book[i];
                        cout << "Ten sach duoc cap nhat thanh: " << name_of_book[i] << endl;
                        fflush(stdin);
                        pressAnyKey();
                        break;
                    case 3:
                        cout << "Moi cap nhat ten tac gia moi: " << endl;
                        cin >> author[i];
                        cout << "Ten tac gia moi la: " << author[i] << endl;
                        fflush(stdin);
                        pressAnyKey();
                        break;
                    case 4:
                        cout << "Moi cap nhat ten nha xuat ban moi: " << endl;
                        cin >> NXB[i];
                        cout << "Ten nha xuat ban moi la: " << NXB[i] << endl;
                        fflush(stdin);
                        pressAnyKey();
                        break;
                    case 5:
                        cout << "Moi cap nhat nam xuat ban: " << endl;
                        cin >> yearXB[i];
                        cout << "Nam xuat ban da duoc cap nhat thanh nam: " << yearXB[i] << endl;
                        fflush(stdin);
                        pressAnyKey();
                        break;
                    case 6:
                        cout << "Moi cap nhat lai the loai sach: " << endl;
                        cin >> type_of_book[i];
                        cout << "The loai sach da duoc cap nhat thanh: " << type_of_book[i] << endl;
                        fflush(stdin);
                        pressAnyKey();
                        break;
                    case 7:
                        cout << "Moi nhap gia tien moi: " << endl;
                        cin >> price[i];
                        cout << "Gia tien moi la: " << price[i] << endl;
                        fflush(stdin);
                        pressAnyKey();
                        break;
                    case 8:
                        cout << "Moi cap nhat so luong sach: " << endl;
                        cin >> sl[i];
                        cout << "So luong sach hien tai: " << sl[i] << endl;
                        fflush(stdin);
                        pressAnyKey();
                        break;
                    case 0:
                        cout << "\nTro ve man hinh quan ly!";
                        _getch();
                        system("cls");
                        main();
                        // Thong bao neu nhap phim khong hop le
                    default:
                        cout << "\nPhim khong hop le! Hay nhap so tuong ung voi chuc nang trong menu.";
                        pressAnyKey();
                        break;
                    }
                }
            }
            pressAnyKey();
            break;
        case 9:
            cout << "\n9. Xoa thong tin sach.";
            deletebook();
            pressAnyKey();
            break;
        case 10:
            char searchisbn[1][100];
            if (book > 0)
            {
                cout << "\n10. Tim kiem sach theo so ISBN.";
                cout << "\nNhap so ISBN de tim kiem: ";
                cin >> searchisbn[1][1];
                for (i = 0; i < book; i++)
                {
                    if (strstr(isbn[i], searchisbn[1]) != NULL)
                    {
                        cout << "Da tim thay sach tuong ung:" << endl;
                        cout << "So ISBN: " << isbn[i] << endl;
                        cout << "Ten sach: " << name_of_book[i] << endl;
                        cout << "Tac gia: " << author[i] << endl;
                        cout << "The loai: " << type_of_book[i] << endl;
                        cout << "NXB: " << NXB[i] << endl;
                        cout << "Nam xuat ban: " << yearXB[i] << endl;
                        cout << "Gia tien: " << price[i] << endl;
                        cout << "So luong: " << sl[i] << endl;
                    }
                }
                fflush(stdin);
                if (i >= book) cout << "\nKhong tim thay sach tuong ung!";
            }
            else cout << "Khong ton tai sach trong thu vien!" << endl;
            pressAnyKey();
            break;
        case 11:
            if (book > 0)
            {
                cout << "\n11. Tim kiem sach theo ten.";
                cout << "\nNhap ten sach de tim kiem: ";
                cin >> searchbook[1];
                for (i = 0; i < book; i++)
                {
                    if (strstr(name_of_book[i], searchbook[1]) != NULL)
                    {
                        cout << "Ma ISBN: " << isbn[i] << endl;
                        cout << "Ten sach: " << name_of_book[i] << endl;
                        cout << "Tac gia: " << author[i] << endl;
                        cout << "NXB: " << NXB[i] << endl;
                        cout << "Nam xuat ban: " << yearXB[i] << endl;
                        cout << "The loai: " << type_of_book[i] << endl;
                        cout << "Gia tien: " << price[i] << endl;
                        cout << "So luong: " << sl[i] << endl;
                    }
                }
                fflush(stdin);
                if (i >= book) cout << "\nKhong tim thay sach tuong ung!";
            }
            else cout << "Khong ton tai sach trong thu vien!" << endl;
            pressAnyKey();
            break;
            //Hien thi danh sach du lieu sach trong thu vien 
        case 12:
            if (book > 0)
            {
                cout << "\n12. Hien thi danh sach du lieu sach trong thu vien.";
            }
            else cout << "\nDanh sach du lieu sach trong thu vien trong!";
            for (int i = 1; i < book; i++)
            {
                printline(100);
                cout << "Ma ISBN: " << isbn[i] << endl;
                cout << "Ten sach: " << name_of_book[i] << endl;
                cout << "Tac gia: " << author[i] << endl;
                cout << "NXB: " << NXB[i] << endl;
                cout << "Nam xuat ban: " << yearXB[i] << endl;
                cout << "The loai: " << type_of_book[i] << endl;
                cout << "Gia tien: " << price[i] << endl;
                cout << "So luong: " << sl[i] << endl;
            }
            pressAnyKey();
            break;
        case 13:
            cout << "\nPhieu muon sach thu vien" << endl;
            borrowbook();
            pressAnyKey();
            break;
        case 14:
            cout << "\nPhieu tra sach thu vien" << endl;
            returnbook();
            pressAnyKey();
            break;
        case 15:
            cout << "\nHien tai thu vien co " << book << " sach!" << endl;
            pressAnyKey();
            break;
        case 16:
            readergenderstat();
            pressAnyKey();
            break;
        case 17:
            cout << "\nHien tai thu vien co " << readerID << " doc gia!" << endl;
            pressAnyKey();
            break;
        case 18:
            booktypestat();
            pressAnyKey();
            break;
        case 0:
            cout << "\nBan da thoat chuong trinh!";
            _getch();
            system("cls");
            exit;
            // Thong bao neu nhap phim khong hop le
        default:
            cout << "\nPhim khong hop le! Hay nhap so tuong ung voi chuc nang trong menu.";
            pressAnyKey();
            break;
        }
    }
}