/*#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

// Quản lý độc giả
const int MAX_DOC_GIA = 100;
const int MAX_SACH = 100;
const int MAX_PHIEU = 100;
char maDocGia[MAX_DOC_GIA][20];
char hoTen[MAX_DOC_GIA][50];
char cmnd[MAX_DOC_GIA][20];
char ngaySinh[MAX_DOC_GIA][20];
char gioiTinh[MAX_DOC_GIA][10];
char email[MAX_DOC_GIA][50];
char diaChi[MAX_DOC_GIA][100];
char ngayLapThe[MAX_DOC_GIA][20];
char ngayHetHan[MAX_DOC_GIA][20];

// Quản lý sách
char isbn[MAX_SACH][20];
char tenSach[MAX_SACH][100];
char tacGia[MAX_SACH][50];
char nhaXuatBan[MAX_SACH][50];
int namXuatBan[MAX_SACH];
char theLoai[MAX_SACH][30];
double giaSach[MAX_SACH];
int soQuyenSach[MAX_SACH];

// Quản lý phiếu mượn
char maDocGiaMuon[MAX_PHIEU][20];
char ngayMuon[MAX_PHIEU][20];
char ngayTraDuKien[MAX_PHIEU][20];
char ngayTraThucTe[MAX_PHIEU][20];
char danhSachISBN[MAX_PHIEU][10][20]; // Mỗi phiếu có tối đa 10 sách

void themDocGia() {
    cout << "Nhập mã độc giả: ";
    cin >> maDocGia[0];
    cout << "Nhập họ tên: ";
    cin.ignore();
    cin.getline(hoTen[0], 50);
    cout << "Nhập CMND: ";
    cin >> cmnd[0];
    cout << "Nhập ngày sinh: ";
    cin >> ngaySinh[0];
    cout << "Nhập giới tính: ";
    cin >> gioiTinh[0];
    cout << "Nhập email: ";
    cin >> email[0];
    cout << "Nhập địa chỉ: ";
    cin.ignore();
    cin.getline(diaChi[0], 100);

    // Tạo ngày lập thẻ và ngày hết hạn tự động
    time_t now = time(0);
    tm *ltm = localtime(&now);
    sprintf(ngayLapThe[0], "%04d-%02d-%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
    sprintf(ngayHetHan[0], "%04d-%02d-%02d", 1900 + ltm->tm_year + 4, 1 + ltm->tm_mon, ltm->tm_mday);

    cout << "Độc giả đã được thêm thành công!\n";
    cout << "Ngày lập thẻ: " << ngayLapThe[0] << endl;
    cout << "Ngày hết hạn: " << ngayHetHan[0] << endl;
}

int main() {
    int choice;
    do {
        cout << "------ Quản lý thư viện ------\n";
        cout << "1. Thêm độc giả\n";
        cout << "0. Thoát\n";
        cout << "Chọn: ";
        cin >> choice;
        switch (choice) {
            case 1:
                themDocGia();
                break;
            case 0:
                cout << "Thoát chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ.\n";
        }
    } while (choice != 0);

    return 0;
}*/