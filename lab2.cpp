#include<iostream>
#include "LinkedList.h"
using namespace std;

struct Node {
	int data;
	Node *next;
};

void BaiTap1();
void BaiTap2();
void BaiTap3();
void BaiTap4();
void BaiTap5();
void inmang(int a[],int &n);


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

//--------BAITAP1---------
void inmang(int a[], int &n) {
	for (int i = 0; i < n; i++) {
		cout << "Gia tri phan tu thu " << i+1 << " la: " << a[i] << endl;
	}
}

void BaiTap1() {

	int mang[100];
	int n = 0;
	int socantim;
	bool khongtimthay = true;
	int socanchen;
	int vitrichen;

	//Nhap va in ds dac
	cout << "Nhap so luong phan tu cua danh sach: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i+1 << ": "; cin >> mang[i];
	}
	cout << endl; inmang(mang, n);
	
	cout << endl;

	//Tim kiem 
	cout << "Nhap so can tim: "; cin >> socantim;
	for (int i = 0; i < n; i++) {
		if (mang[i] == socantim) {
			cout << "Vi tri so can tim la: " << i << endl; 
			khongtimthay = false;
		}
	}
	if (khongtimthay) {
		cout << "Khong tim thay !\n";
	}
	cout << endl;

	// Chen
	cout << "Nhap so can chen trong danh sach: "; cin >> socanchen;
	cout << "Nhap vi tri can chen: "; cin >> vitrichen;
	if (vitrichen > n)
		cout << "Vi tri can chen lon hon so luong phan tu trong danh sach (lon hon " << n << " ) " << endl;
	else {
		for (int i = n; i >= vitrichen; i--) mang[i] = mang[i - 1];
		mang[vitrichen - 1] = socanchen;
		cout << "Da chen " << socanchen << " vao vi tri thu " << vitrichen << " trong danh sach .\n";
		n++;
		inmang(mang, n);
	}
}

//---------BAITAP2---------

void BaiTap2() {

}
void BaiTap3() {

}
void BaiTap4() {

}
void BaiTap5() {

}

