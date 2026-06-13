#include <iostream>
using namespace std;

struct Jadwal {
    string kereta;
    string asal;
    string tujuan;
    string jam;
};

Jadwal data[100];
int jumlah = 0;

void tambahJadwal() {
    cout << "\n=== Tambah Jadwal ===\n";

    cout << "Nama Kereta : ";
    cin >> data[jumlah].kereta;

    cout << "Stasiun Asal : ";
    cin >> data[jumlah].asal;

    cout << "Stasiun Tujuan : ";
    cin >> data[jumlah].tujuan;

    cout << "Jam Berangkat : ";
    cin >> data[jumlah].jam;

    jumlah++;

    cout << "Jadwal berhasil ditambahkan!\n";
}

void tampil
