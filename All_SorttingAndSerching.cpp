// SORTING SEARCHING //
/*
1. Selection Sort (chon lua truc tiep)
2. Insertion Sort (chen truc tiep)
3. Bubble Sort (noi bot)
4. Interchange Sort (doi cho truc tiep)
5. Merge Sort (sap xep tron)
6. Quick Sort (phan hoach)
7. Heap Sort

*/
#include <iostream>
#include<fstream>
#define MAX 100

using namespace std;


void Swap(int&, int&);
void nhapMang(int a[], int&);
void Xuatmang(int a[], int&);
void Menu(int& choice, int a[], int&);

void Selection_Sort(int a[], int&);
void Bubble_Sort(int a[], int&);
void Insertion_Sort(int a[], int&);
void Interchange_Sort(int a[], int&);
void Merge_Sort(int a[], int&); // Trộn ! chú ý

void Quick_Sort(int a[], int&);
void Heap_Sort(int a[], int&);



int main() {

	int a[100];
	int n;
	int choice;

	/*ifstream file;
	file.open("Text2.txt", ios::out);
	file >> n;
	for (int i = 0; i < n; i++) {
		file >> a[i];
	}*/
	nhapMang(a, n);
	Xuatmang(a, n);
	Menu(choice, a, n);

	/*file.close();*/


	system("pause");
	return 0;
}




// Selection Sort

void Selection_Sort(int a[], int& n) // Tim MIN cua danh sach ---> dua lan luot ve vi tri DAU TIEN (a[0])
{
	cout << "Thuat toan xap xep Selection Sort" << endl;
	for (int i = 0; i < n - 1; i++) {
		int min_pos = i; // Tao bien min ROI
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_pos]) // So sanh
				min_pos = j; // Thay doi gia tri MIN 
		}
		Swap(a[min_pos], a[i]); // Thay doi vi tri Min
	}
	Xuatmang(a,n);
}

// Bubble Sort
void Bubble_Sort(int a[], int& n) // Xet CAP gia tri tu vi tri CUOI ---. dua gia tri MIN dan ve phia dau a[0]
{
	cout << "Thuat toan xap xep Buble Sort " << endl;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1]) // So sanh a[j] ---> dua MIN ve trc

				Swap(a[j], a[j - 1]); // Doi vi tri
		}
	}
	Xuatmang(a, n);
}

// Insertion Sort 
void Insertion_Sort(int a[], int& n) {
	cout << "Thuat toan xap xep Insertion Sort" << endl;
	int j, x;
	for (int i = 1; i < n; i++)
	{
		x = a[i]; // Gan gia tri ROI cho X
		j = i - 1;
		while (j >= 0 && x < a[j]) // So sanh X va gia tri dung truoc (a[j])
		{
			a[j + 1] = a[j]; // Tinh tien a[j] (gia tri > X) ---> day ve phia sau
			j--; // Giam J ---> xet tiep don vi phia truoc cho den a[0]
		}
		a[j + 1] = x; // Dua X tien ve phai 1 don vi ---> vi tri cua "i" o buoc tiep theo
	}
	Xuatmang(a, n);
}

//Interchange Sort
void Interchange_Sort(int a[],int& n) {

}

//Merge Sort
void Merge_Sort(int a[], int& n) {

}

//Quick Sort
void Quick_Sort(int a[], int& n) {

}

//Heap Sort
void Heap_Sort(int a[], int& n) {

}





void Swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

void nhapMang(int a[], int &n) {
	cout << endl;
	cout << " Nhap mang gom " << n << " phan tu" << endl;
	for (int i = 0; i < n; i++) {
		cout << " Nhap phan tu thu " << i + 1 << " : ";  cin >> a[i];
	}
}
void Xuatmang(int a[], int &n) {
	cout << "\n" << "Mang " << "voi " << n << " phan tu <> \n";
	for (int i = 0; i < n; i++) {
		cout << " a[" << i << "] : " << a[i] << endl;
	}
}

void Menu(int &choice, int a[], int& n) {
	do {
		cout << "// SORTING SEARCHING //" << "\n";
		cout << "Moi lua chon thuat toan xap xep\n";
		cout << "1.Selection Sort \n";
		cout << "2.Bubble Sort \n";
		cout << "3.Insertion Sort \n";
		cout << "4.Interchange Sort \n";
		cout << "5.Merge Sort \n";
		cout << "6.Quick Sort \n";
		cout << "7.Heap Sort \n";
		cout << "0.Thoat \n";

		cout << "Moi ban nhap lua chon (0-7): "; cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:  Selection_Sort(a, n);
			cout <<"\n\n\n";
			break;
		case 2:  Bubble_Sort(a, n);
			cout << "\n\n\n";
			break;
		case 3:  Insertion_Sort(a, n);
			cout << "\n\n\n";
			break;
		case 4: Interchange_Sort(a,n);
			cout << "\n\n\n";
			break;
		case 5: Merge_Sort(a,n);
			cout << "\n\n\n";
			break;
		case 6: Quick_Sort(a,n);
			cout << "\n\n\n";
			break;
		case 7: Heap_Sort(a, n);
			cout << "\n\n\n";
			break;
		default: cout << "Loi! Moi nhap lai\n\n\n";
			break;
		}
	} while (choice != 0); cout << "Ban da thoat chuong trinh !" << endl;
}

