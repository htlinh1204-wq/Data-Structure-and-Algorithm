#include<iostream>
using namespace std;



void BaiTap1();
void BaiTap2();
void BaiTap3();
void BaiTap4();
void BaiTap5();


int main() {
	int luaChon;
	do {
		cout << "\n---------LAB 2: CAU TRUC DU LIEU CO BAN -----------" << endl;
		cout << "1. Bai 1: Danh sach dac " << endl;
		cout << "2. Bai 2: Danh sach lien ket don " << endl;
		cout << "3. Bai 3: Danh sach lien ket kep " << endl;
		cout << "4. Bai 4: Ngan xep " << endl;
		cout << "5. Bai 5: Hang doi " << endl;
		cout << "0. Thoat" << endl;
		cout << "--------------------------------------" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> luaChon;

		switch (luaChon) {
		case 1: BaiTap1(); break;
		case 2: BaiTap2(); break;
		case 3: BaiTap3(); break;
		case 4: BaiTap4(); break;
		case 5: BaiTap5(); break;
		case 0: cout << "Dang thoat. " << endl; break;
		default: cout << "Vui long nhap lai!" << endl; break;
		}
	} while (luaChon != 0);

	system("pause");
	return 0;
}

//Baitap1
void BaiTap1() {

	int mang[100];
	int n = 0;
	cout << "Nhap gia tri cua n: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << n << " : "; cin >> mang[i];
	}
	cout << endl;
	for (int j = 0; j < n; j++) {
		cout << "Gia tri phan tu thu " << n << " : " << mang[j];
	}
	cout << endl;
}
