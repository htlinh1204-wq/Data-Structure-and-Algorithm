#include <iostream>
using namespace std;

// KHAI BAO CAU TRUC DU LIEU (DATA STRUCTURES)

//Bai 2 voi 5: Cau truc Node cho Danh sach lien ket don / Hang doi
struct NodeSLL {
    int data;
    NodeSLL* next;
};

// --- Bai 3: Cau truc Node cho Danh sach lien ket kep ---
struct NodeDLL {
    int data;
    NodeDLL* next;
    NodeDLL* prev;
};

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

    return 0;
}


// BAI 1: DANH SACH DAC
void inDanhSach1(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void BaiTap1() {
    cout << "\n BAI 1: DANH SACH DAC" << endl;
    const int MAX = 100;
    int a[MAX];
    int n = 0;

    int testcase[] = { 10, 50, 20, 70, 30, 60, 40 };
    n = 7;
    for (int i = 0; i < n; i++) a[i] = testcase[i];

    cout << "Danh sach ban dau: "; inDanhSach1(a, n);

    //Tim kiem x = 30
    int x_tim = 30, viTriTim = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == x_tim) { viTriTim = i; break; }
    }
    if (viTriTim != -1) cout << "Tim thay " << x_tim << " tai vi tri (index): " << viTriTim << endl;
    else cout << "Khong tim thay " << x_tim << endl;

    //Chen x = 70 vao vi tri i = 3
    int x_chen = 70, pos_chen = 3;
    if (n < MAX&& pos_chen >= 0 && pos_chen <= n) {
        for (int i = n; i > pos_chen; i--) a[i] = a[i - 1]; // Dich cac phan tu ra sau
        a[pos_chen] = x_chen;
        n++;
        cout << "Sau khi chen " << x_chen << " vao vi tri " << pos_chen << ": "; inDanhSach1(a, n);
    }

    //Xoa phan tu tai vi tri
    int pos_xoa = 3;
    if (pos_xoa >= 0 && pos_xoa < n) {
        for (int i = pos_xoa; i < n - 1; i++) a[i] = a[i + 1];
        n--;
        cout << "Sau khi xoa phan tu tai vi tri " << pos_xoa << ": "; inDanhSach1(a, n);
    }

    // Tim kiem x = 5
    x_tim = 5; viTriTim = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == x_tim) { viTriTim = i; break; }
    }
    if (viTriTim != -1) cout << "Tim kiem x = " << x_tim << ": Tra ve " << viTriTim << endl;
    else cout << "Tim kiem x = " << x_tim << ": Tra ve -1 (Khong tim thay)." << endl;
}


// BAI 2: DANH SACH LIEN KET DON
void inListSLL(NodeSLL* head) {
    NodeSLL* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void BaiTap2() {
    cout << "\n BAI 2: DANH SACH LIEN KET DON " << endl;
    NodeSLL* first = NULL; // Khoi tao theo yeu cau

    // Khoi tao mang mau theo testcase: 10 -> 20 -> 15 -> 5 -> NULL
    int arr[] = { 10, 20, 15, 5 };
    for (int i = 3; i >= 0; i--) {
        NodeSLL* newNode = new NodeSLL;
        newNode->data = arr[i];
        newNode->next = first;
        first = newNode;
    }
    cout << "Danh sach dang co: "; inListSLL(first);

    //Them vao dau x = 30
    int x_them = 30;
    NodeSLL* nodeThemDau = new NodeSLL;
    nodeThemDau->data = x_them;
    nodeThemDau->next = first;
    first = nodeThemDau;
    cout << "Sau khi them dau " << x_them << ": "; inListSLL(first);

    //Xoa phan tu dau
    if (first != NULL) {
        NodeSLL* nodeCanXoa = first;
        first = first->next;
        delete nodeCanXoa; // Giai phong bo nho
        cout << "Sau khi xoa dau: "; inListSLL(first);
    }
}


// BAI 3: DANH SACH LIEN KET KEP
void BaiTap3() {
    cout << "\n BAI 3: DANH SACH LIEN KET KEP " << endl;
    NodeDLL* head = NULL;
    NodeDLL* last = NULL; // Con tro last de duyet nguoc

    // Ham them vao cuoi cuc bo
    auto InsertLast = [&](int x) {
        NodeDLL* newNode = new NodeDLL;
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = last; // Cap nhat prev cua node moi

        if (head == NULL) {
            head = newNode;
            last = newNode;
        }
        else {
            last->next = newNode; // Cap nhat next cua node cu
            last = newNode;
        }
        };

    // Tao du lieu input: 10 <-> 20 <-> 15
    InsertLast(10);
    InsertLast(20);
    InsertLast(15);

    cout << "Danh sach tu dau xuong cuoi: ";
    NodeDLL* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } cout << "NULL\n";

    // Duyet nguoc bang con tro last
    cout << "Output (Duyet nguoc): ";
    temp = last;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->prev != NULL) cout << ", ";
        temp = temp->prev;
    }
    cout << endl;
}


// BAI 4: NGAN XEP (STACK) 
void BaiTap4() {
    cout << "\n BAI 4: NGAN XEP (STACK) " << endl;
    const int MAX_STACK = 100;
    int stack[MAX_STACK];
    int sp = -1; // stack pointer

    // Ham cuc bo
    auto isEmpty = [&]() { return sp == -1; };
    auto Push = [&](int x) {
        if (sp < MAX_STACK - 1) {
            stack[++sp] = x;
            cout << "Thuc hien Push(" << x << "). Phan tu " << x << " nam tren dinh (sp tang).\n";
        }
        else {
            cout << "Ngan xep day!\n";
        }
        };
    auto Pop = [&]() {
        if (!isEmpty()) {
            int val = stack[sp--]; // Gia tri tra ve va giam sp
            cout << "Gia tri tra ve cua Pop(): " << val << " (phan tu vua them vao bi lay ra dau tien).\n";
            return val;
        }
        else {
            cout << "Ngan xep rong!\n";
            return -1;
        }
        };

    cout << "Stack hien tai (dinh o tren): RONG (sp = " << sp << ")\n";
    Push(25); //
    Pop();    //
}


// BAI 5: HANG DOI (QUEUE)

void BaiTap5() {
    cout << "\n--- BAI 5: HANG DOI (QUEUE) ---" << endl;
    NodeSLL* front = NULL;
    NodeSLL* rear = NULL;

    // Ham them vao cuoi (rear)
    auto PushQueue = [&](int x) {
        NodeSLL* newNode = new NodeSLL;
        newNode->data = x;
        newNode->next = NULL;
        if (rear == NULL) { // Queue dang rong
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        };

    // Ham lay ra o dau (front)
    auto PopQueue = [&]() {
        if (front == NULL) {
            cout << "Hang doi rong!\n";
            return -1;
        }
        NodeSLL* temp = front;
        int val = temp->data;
        front = front->next; // front dich chuyen sang phan tu tiep theo

        if (front == NULL) rear = NULL; // Neu lay xong queue rong
        delete temp;
        return val;
        };

    // Gia lap Hang doi hien tai: front -> 10 -> 20 -> 30 <- rear
    PushQueue(10);
    PushQueue(20);
    PushQueue(30);
    cout << "Hang doi hien tai: front -> 10, 20, 30 <- rear" << endl;

    // Thuc hien thao tac
    cout << "Thuc hien: Pop()\n";
    int val_pop = PopQueue();
    cout << "Gia tri lay ra: " << val_pop << endl;

    // In hang doi con lai
    cout << "Hang doi con lai: front -> ";
    NodeSLL* t = front;
    if (t == NULL) cout << "RONG";
    while (t != NULL) {
        cout << t->data;
        if (t->next != NULL) cout << ", ";
        t = t->next;
    }
    cout << " <- rear (front da dich chuyen sang phan tu tiep theo)" << endl;
}
