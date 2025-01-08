#include <iostream>
#include "CRM.h"

using namespace std;

void tampilkanMenu() {
    cout << "\n--- Menu CRM ---\n";
    cout << "1. Tambah Pelanggan\n";
    cout << "2. Ubah Pelanggan\n";
    cout << "3. Hapus Pelanggan\n";
    cout << "4. Tampilkan Semua Pelanggan\n";
    cout << "5. Cari Pelanggan (Iteratif)\n";
    cout << "6. Cari Pelanggan (Rekursif)\n";
    cout << "7. Keluar\n";
    cout << "Masukkan pilihan Anda: ";
}

int main() {
    CRM crm;
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            int id;
            string nama, email;
            cout << "Masukkan ID: ";
            cin >> id;
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan Email: ";
            getline(cin, email);
            crm.tambahPelanggan(Customer(id, nama, email));
            break;
        }
        case 2: {
            int id;
            string nama, email;
            cout << "Masukkan ID pelanggan yang akan diubah: ";
            cin >> id;
            cout << "Masukkan Nama Baru: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan Email Baru: ";
            getline(cin, email);
            if (crm.ubahPelanggan(id, nama, email))
                cout << "Pelanggan berhasil diubah.\n";
            else
                cout << "Pelanggan tidak ditemukan.\n";
            break;
        }
        case 3: {
            int id;
            cout << "Masukkan ID pelanggan yang akan dihapus: ";
            cin >> id;
            if (crm.hapusPelanggan(id))
                cout << "Pelanggan berhasil dihapus.\n";
            else
                cout << "Pelanggan tidak ditemukan.\n";
            break;
        }
        case 4:
            crm.tampilkanPelanggan();
            break;
        case 5: {
            int id;
            cout << "Masukkan ID untuk pencarian: ";
            cin >> id;
            int index = crm.cariPelangganIteratif(id);
            if (index != -1)
                cout << "Pelanggan ditemukan di indeks: " << index << endl;
            else
                cout << "Pelanggan tidak ditemukan.\n";
            break;
        }
        case 6: {
            int id;
            cout << "Masukkan ID untuk pencarian: ";
            cin >> id;
            int index = crm.cariPelangganRekursif(id, 0, crm.getPelanggan().size() - 1);
            if (index != -1)
                cout << "Pelanggan ditemukan di indeks: " << index << endl;
            else
                cout << "Pelanggan tidak ditemukan.\n";
            break;
        }
        case 7:
            cout << "Keluar dari program...\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 7);

    return 0;
}
