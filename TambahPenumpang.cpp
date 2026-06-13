#include <iostream>
#include <string>
using namespace std;

// Struct Node Tambah Penumpang
struct Penumpang {
    int id;
    string nama;
    string asal;
    string tujuan;
    Penumpang* next;
};

Penumpang* head = NULL;
int idCounter = 1;

// Tambah Penumpang
void tambahPenumpang() {
    Penumpang* baru = new Penumpang();
    baru->id = idCounter++;
    cout << "\n=== TAMBAH PENUMPANG ===" << endl;
    cout << "Nama Penumpang : "; cin.ignore(); getline(cin, baru->nama);
    cout << "Stasiun Asal   : "; getline(cin, baru->asal);
    cout << "Stasiun Tujuan : "; getline(cin, baru->tujuan);
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Penumpang* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "\n? Penumpang berhasil ditambahkan! (ID: " << baru->id << ")" << endl;
}

// Tampilkan Semua Penumpang
void tampilkanPenumpang() {
    cout << "\n=== DAFTAR PENUMPANG ===" << endl;
    if (head == NULL) {
        cout << "Belum ada data penumpang." << endl;
        return;
    }
    cout << "--------------------------------------------" << endl;
    cout << "ID\tNama\t\tAsal\t\tTujuan" << endl;
    cout << "--------------------------------------------" << endl;
    Penumpang* temp = head;
    while (temp != NULL) {
        cout << temp->id << "\t" << temp->nama << "\t\t"
             << temp->asal << "\t\t" << temp->tujuan << endl;
        temp = temp->next;
    }
    cout << "--------------------------------------------" << endl;
}

// Cari Penumpang
void cariPenumpang() {
    cout << "\n=== CARI PENUMPANG ===" << endl;
    string keyword;
    cout << "Masukkan nama penumpang: "; cin.ignore(); getline(cin, keyword);

    Penumpang* temp = head;
    bool ketemu = false;
    while (temp != NULL) {
        if (temp->nama == keyword) {
            cout << "\n? Penumpang ditemukan!" << endl;
            cout << "ID     : " << temp->id << endl;
            cout << "Nama   : " << temp->nama << endl;
            cout << "Asal   : " << temp->asal << endl;
            cout << "Tujuan : " << temp->tujuan << endl;
            ketemu = true;
        }
        temp = temp->next;
    }
    if (!ketemu) {
        cout << "? Penumpang tidak ditemukan." << endl;
    }
}

// Hapus Penumpang
void hapusPenumpang() {
    cout << "\n=== HAPUS PENUMPANG ===" << endl;
    if (head == NULL) {
        cout << "Belum ada data penumpang." << endl;
        return;
    }
    int idHapus;
    cout << "Masukkan ID penumpang yang dihapus: "; cin >> idHapus;

    // Hapus di head
    if (head->id == idHapus) {
        Penumpang* hapus = head;
        head = head->next;
        delete hapus;
        cout << "? Penumpang berhasil dihapus!" << endl;
        return;
    }

    // Hapus di tengah/akhir
    Penumpang* temp = head;
    while (temp->next != NULL) {
        if (temp->next->id == idHapus) {
            Penumpang* hapus = temp->next;
            temp->next = hapus->next;
            delete hapus;
            cout << "? Penumpang berhasil dihapus!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "? ID tidak ditemukan." << endl;
}

// Menu Data Penumpang
void menuDataPenumpang() {
    int pilihan;
    do {
        cout << "\n=== DATA PENUMPANG ===" << endl;
        cout << "1. Tambah Penumpang" << endl;
        cout << "2. Tampilkan Semua Penumpang" << endl;
        cout << "3. Cari Penumpang" << endl;
        cout << "4. Hapus Penumpang" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Pilihan: "; cin >> pilihan;

        switch (pilihan) {
            case 1: tambahPenumpang(); break;
            case 2: tampilkanPenumpang(); break;
            case 3: cariPenumpang(); break;
            case 4: hapusPenumpang(); break;
            case 0: cout << "Kembali ke menu utama..." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);
}

int main() {
    menuDataPenumpang();
    return 0;
}
