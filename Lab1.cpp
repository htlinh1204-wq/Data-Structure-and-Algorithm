#include <iostream>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

void BaiTap1();
void BaiTap2();
void BaiTap3();
void BaiTap4();
void BaiTap5();
void BaiTap6();
void BaiTap7();
void BaiTap8();
int dequy(int n);
void BaiTap9();
void nhapDanhSach(int* danhsach, int &n);



int main() {
    int luaChon;
    do {
        cout << "\n---- LAB 1 ----" << endl;
        cout << "1. Bai tap 1" << endl;
        cout << "2. Bai tap 2" << endl;
        cout << "3. Bai tap 3" << endl;
        cout << "4. Bai tap 4" << endl;
        cout << "5. Bai tap 5" << endl;
        cout << "6. Bai tap 6" << endl;
        cout << "7. Bai tap 7" << endl;
        cout << "8. Bai tap 8" << endl;
        cout << "9. Bai tap 9" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: BaiTap1(); break; 
        case 2: BaiTap2(); break;
        case 3: BaiTap3(); break;
        case 4: BaiTap4(); break;
        case 5: BaiTap5(); break;
        case 6: BaiTap6(); break;
        case 7: BaiTap7(); break;
        case 8: BaiTap8(); break;
        case 9: BaiTap9(); break;
        case 0: cout << "Thoat" << endl; break;
        default: cout << "Nhap sai" << endl; break;
        }
    } while (luaChon != 0);

    system("pause");
    return 0;
}


//--------------Baitap--------------------------------

void BaiTap1() {
    cout << endl;
    cout << " BAI TAP 1: DEM SO LAN XUAT HIEN CUA 1 SO NGUYEN " << endl;

    int n;
    int x;
    int dem = 0;

    cout << " Nhap so phan tu cua danh sach:"; cin >> n;
  
    int* danhsach = new int[n];
    for (int i = 0; i < n; i++) {
        cout << " Nhap so trong DS:"; cin >> danhsach[i];
    }

    cout << " Nhap so can dem: "; cin >> x;
    for (int i = 0; i < n; i++) {
        if (danhsach[i] == x)
            dem += 1;
    }
    cout << " So lan xuat hien so " << x << " trong danh sach la: " << dem <<" lan "<< endl;

    delete[] danhsach;

    /*PHAN TICH DO PHUC TAP
    Vong lap thu nhat lap n lan --> O(n)
    Vong lap thu 2 + dieu kien if + phep cong --> O(n+2)
    Ket luan: Thuat toan co do phuc tap la O(n)
    */
}

void BaiTap2() {
    cout << endl;
    cout << " BAI TAP 2: TIM GIA TRI LON NHAT (MAX) " << endl;


    int x;


    int n;
    int danhsach[100];
    nhapDanhSach(danhsach, n);

    int MAX = danhsach[0];

    //--------ThuatToan-----------//
    for (int i = 0; i < n; i++) {
        if (MAX < danhsach[i]) {
            MAX = danhsach[i];
        }
    }
    //---------------------------//

    cout << " So lon nhat trong danh sach la so: " << MAX << endl;
    /*PHAN TICH DO PHUC TAP
    Vong lap for chay n lan --> O(n)
    Thuc hien so sanh n lan --> O(1)
    Ket luan: Thuat toan co do phuc tap la O(n)
    */
}

void BaiTap3() {
    cout << endl;
    cout << " BAI TAP 3: TIM GIA TRI LON THU HAI " << endl;

    int n;
    int danhsach[100];
    nhapDanhSach(danhsach, n);

    int MAX1 = danhsach[0];
    int MAX2 = 0;

    //-------ThuatToan-----------//
    for (int i = 0; i < n; i++) {
        if (MAX1 < danhsach[i]) {
            MAX2 = MAX1;
            MAX1 = danhsach[i];
        }
        else
            if (MAX2 < danhsach[i])
                MAX2 = danhsach[i];
    }
    //---------------------------//

    cout << " So lon thu hai trong danh sach la so: " << MAX2 << endl;

    /*PHAN TICH DO PHUC TAP
    Vong lap for chay n lan --> O(n)
    Thuc hien so sanh 2 lan o truong hop xau nhat--> O(2)
    Ket luan: Thuat toan co do phuc tap la O(n)
    */
}

void BaiTap4() {
    cout << endl;
    cout << "BAI TAP 4: KIEM TRA CHUOI DOI XUNG" << endl;

    string s;
    cout << "Nhap chuoi: ";
    cin >> s;

    int left = 0;
    int right = s.length() - 1;

    //----------ThuatToan-------------//
    while (left < right) {
        if (s[left] != s[right]) {
            cout << " NO";
            return;
        }
        left++;
        right--;
    }
    cout << " YES";
    //-----------------------------//


    /*PHAN TICH DO PHUC TAP
    Vong lap while lap n lan --> O(n)
    Dieu kien IF moi lan so sanh (left +1 va right -1) khoang cach giam 2 --> O(n/2)
    Ket Luan: Do phuc tap la O(n)
    */
}

void BaiTap5() {
    cout << endl;
    cout << " BAI TAP 5: DEM SO LUONG NGUYEN TO \n";

    int n;
    int x;
    int tong =0;
    int danhsach[100];
    nhapDanhSach(danhsach, n);

    for (int i = 0; i < n; i++) {
        bool lasonguyento = true;
        x = danhsach[i];

        if (x < 2)
            lasonguyento = false;
        else {
            for (int j = 2; j <= sqrt(x); j++) {
                if ((x % j) == 0) {
                    lasonguyento = false;
                    break;
                }
            }
        }
        if (lasonguyento)
                tong += 1;
    }
    if (tong == 0)
        cout << " Mang khong co so nguyen to .\n";
    else {
        cout << " Co " << tong << " so nguyen to trong mang ." << endl;
    }

    /*PHAN TICH DO PHUC TAP
      Vong lap for ben ngoai chay n lan --> O(n)
      Vong lap ben trong chay phu thuoc vao bien x (chay tu j=2 den sqrt(x) )
     --> 0(sqrt(x))
      Ket luan: Thuat toan co do phuc tap la O(n.sqrt(x))
      */
}

void BaiTap6() {
    cout << endl;
    cout << " BAI TAP 6: KIEM TRA TINH DUY NHAT " << endl;

    int n;
    int danhsach[100];

    nhapDanhSach(danhsach, n);
    bool trung = false;
    for (int i = 0; i < n; i++){
        if (trung)
            break;
        for (int j = i+1; j < n; j++) {
            if (danhsach[i] == danhsach[j]) {
                trung = true;
                break;
            }
        }
    }
    if (trung) {
        cout << " Danh sach bi trung.\n";
    }
    else {
        cout << " Danh sach khong co phan tu nao trung lap. \n ";
    }

    /*PHAN TICH DO PHUC TAP
    Vong lap thu nhat lap n lan --> O(n)
    Vong lap ben trong lap n lan --> 0(n)
    Ket luan: Thuat toan co do phuc tap la O(n^2)
    */
}

void BaiTap7() {
    cout << endl;
    cout << " BAI TAP 7: KIEM TRA DAU NGOAC HOP LE " << endl;

    string s;
    cout << " Nhap chuoi ngoac s: ";
    cin >> s;

    stack<char> st;
    bool hopLe = true;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) {
                hopLe = false;
                break;
            }
            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                hopLe = false;
                break;
            }
        }
    }
    if (!st.empty()) {
        hopLe = false;
    }

    if (hopLe) {
        cout << " Output: YES\n";
    }
    else {
        cout << " Output: NO\n";
    }

    /*
       PHAN TICH DO PHUC TAP
       Vong lap duyet qua cac ky tu cua chuoi s do dai n dung 1 lan.
       Cac thao tac day vao (push) va lay ra (pop) cua Stack deu chi mat O(1).
         -> Ket luan: Do phuc tap thoi gian la O(n).
    */
}

void BaiTap8() {
    cout << endl;
    cout << " BAI TAP 8: TINH TONG DE QUY " << endl;
    int n;
    cout << " Nhap gia tri so nguyen n: "; cin >> n;
    cout << " Tong de quy theo he thuc truy hoi f(n) = n + f(n-1) voi n = " << n << " la: " << dequy(n);
    cout << endl;
   
    /*PHAN TICH DO PHUC TAP
    Ket luan: Thuat toan co do phuc tap la O(n)
    */
}

int dequy(int n) {
    if (n <= 1)
        return n;
    else {
        return n + dequy(n - 1);
    }
}

void BaiTap9() {
    cout << endl;
    cout << " BAI TAP 9: TIM KIEM TUYEN TINH " << endl;
    int n;
    int danhsach[1000];

    nhapDanhSach(danhsach, n);

    int x;
    cout << " Nhap gia tri can tim x: ";
    cin >> x;

    int viTri = -1;
    for (int i = 0; i < n; i++) {
        if (danhsach[i] == x) {
            viTri = i;
            break;
        }
    }

    if (viTri != -1) {
        cout << " Output: " << viTri << endl;
    }
    else {
        cout << " Output: -1 (Khong tim thay)" << endl;
    }

    /*PHAN TICH DO PHUC TAP
Ket luan: Thuat toan co do phuc tap la O(n)
*/

}


void nhapDanhSach(int* danhsach, int &n) {
    cout << endl;
    cout << " Nhap so luong phan tu cua Danh Sach: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << " Nhap gia tri phan tu thu " << i + 1 << " : ";
        cin >> danhsach[i];
    }
}

