#include <iostream>
#include <string>
using namespace std;

struct Jadwal {
    string asal;
    string tujuan;
    string waktu;
};

Jadwal jadwal[100];
int jumlah = 0;

void tambahJadwal() {
    cout << "\n=== Tambah Jadwal ===\n";

    cin.ignore();
    cout << "Asal    : ";
    getline(cin, jadwal[jumlah].asal);

    cout << "Tujuan  : ";
    getline(cin, jadwal[jumlah].tujuan);

    cout << "Waktu   : ";
    getline(cin, jadwal[jumlah].waktu);

    jumlah++;
    cout << "Jadwal berhasil ditambahkan!\n";
}

void tampilkanJadwal() {
    cout << "\n=== Semua Jadwal ===\n";

    if (jumlah == 0) {
        cout << "Belum ada jadwal.\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nJadwal " << i + 1 << endl;
        cout << "Asal   : " << jadwal[i].asal << endl;
        cout << "Tujuan : " << jadwal[i].tujuan << endl;
        cout << "Waktu  : " << jadwal[i].waktu << endl;
    }
}

void cariJadwal() {
    string tujuan;
    bool ditemukan = false;

    cin.ignore();
    cout << "\nMasukkan tujuan yang dicari: ";
    getline(cin, tujuan);

    for (int i = 0; i < jumlah; i++) {
        if (jadwal[i].tujuan == tujuan) {
            cout << "\nJadwal ditemukan:\n";
            cout << "Asal   : " << jadwal[i].asal << endl;
            cout << "Tujuan : " << jadwal[i].tujuan << endl;
            cout << "Waktu  : " << jadwal[i].waktu << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan)
        cout << "Jadwal tidak ditemukan.\n";
}

void hapusJadwal() {
    int nomor;

    tampilkanJadwal();

    if (jumlah == 0)
        return;

    cout << "\nNomor jadwal yang akan dihapus: ";
    cin >> nomor;

    if (nomor < 1 || nomor > jumlah) {
        cout << "Nomor tidak valid!\n";
        return;
    }

    for (int i = nomor - 1; i < jumlah - 1; i++) {
        jadwal[i] = jadwal[i + 1];
    }

    jumlah--;
    cout << "Jadwal berhasil dihapus!\n";
}

int main() {
    int pilihan;

    do {
        cout << "\n=== MANAJEMEN JADWAL PERJALANAN ===\n";
        cout << "1. Tambah Jadwal\n";
        cout << "2. Tampilkan Semua Jadwal\n";
        cout << "3. Cari Jadwal\n";
        cout << "4. Hapus Jadwal\n";
        cout << "0. Kembali ke Menu Utama\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahJadwal();
                break;
            case 2:
                tampilkanJadwal();
                break;
            case 3:
                cariJadwal();
                break;
            case 4:
                hapusJadwal();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
