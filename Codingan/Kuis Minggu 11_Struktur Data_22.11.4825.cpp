#include <iostream>
#include <conio.h>

using namespace std;

struct mhs {
    string nama, alamat;
    mhs* prev, * next;
};

mhs* head, * tail, * cur, * del, * newnode;

void create(string data[2]) {
    head = new mhs;
    head->nama = data[0];
    head->alamat = data[1];
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

void print() {
    if (head == NULL) {
        cout << "Data double linked list belum ada\n";
        cout << "----------------------------------\n";
    }
    else {
        cur = head;
        while (cur != NULL) {
            cout << "Nama: " << cur->nama << endl;
            cout << "Alamat: " << cur->alamat << endl;
            cur = cur->next;
            cout << "\n";
        }
    }
}

void tambahAwal(string data[2]) {
    if (head == NULL) {
        cout << "Data double linked list belum ada\n";
        cout << "-------------------------------------\n";
    }
    else {
        newnode = new mhs;
        newnode->nama = data[0];
        newnode->alamat = data[1];
        newnode->prev = NULL;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void tambahAkhir(string data[2]) {
    if (head == NULL) {
        cout << "Data double linked list belum ada\n";
        cout << "-------------------------------------\n";
    }
    else {
        newnode = new mhs;
        newnode->nama = data[0];
        newnode->alamat = data[1];
        newnode->prev = tail;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }
}

void hapusAwalNode() {
    if (head == NULL) {
        cout << "Data double linked list belum ada\n";
        cout << "-------------------------------\n";
    }
    else {
        del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
    }
}

void hapusAkhirNode() {
    if (head == NULL) {
        cout << "Data double linked list belum ada\n";
        cout << "-------------------------------\n";
    }
    else {
        del = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete del;
    }
}

int main() {
    cout << "Note awal (tunggal)" << endl;
    string data1[2] = { "data1", "magelang" };
    create(data1);
    print();
    cout << "--------------------------------" << endl;

    cout << " === Note bertambah di awal ===" << endl;
    string data2[2] = { "data2", "malang" };
    tambahAwal(data2);
    print();
    cout << "--------------------------------" << endl;
    
    cout << " === Note bertambah di akhir === " << endl;
    string data3[2] = { "data3", "jogja" };
    tambahAkhir(data3);
    print();
    cout << "--------------------------------" << endl;
    
    cout << "Menghapus Node di awal" << endl;
    cout << "--------------------------------" << endl;
    hapusAwalNode();
    print();
    cout << "--------------------------------" << endl;
    
    cout << "Menghapus Node di akhir" << endl;
    cout << "--------------------------------" << endl;
    hapusAkhirNode();
    print();
    cout << "--------------------------------" << endl;

    return 0;
}
