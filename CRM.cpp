#include "CRM.h"
#include <iostream>

void CRM::tambahPelanggan(const Customer& pelangganBaru) {
    pelanggan.push_back(pelangganBaru);
}

bool CRM::ubahPelanggan(int id, const string& nama, const string& email) {
    for (auto& pelangganItem : pelanggan) {
        if (pelangganItem.getId() == id) {
            pelangganItem.setNama(nama);
            pelangganItem.setEmail(email);
            return true;
        }
    }
    return false;
}

bool CRM::hapusPelanggan(int id) {
    for (size_t i = 0; i < pelanggan.size(); ++i) {
        if (pelanggan[i].getId() == id) {
            pelanggan.erase(pelanggan.begin() + i);
            return true;
        }
    }
    return false;
}

void CRM::tampilkanPelanggan() const {
    if (pelanggan.empty()) {
        cout << "Tidak ada pelanggan yang terdaftar." << endl;
        return;
    }
    for (const auto& pelangganItem : pelanggan) {
        cout << "ID: " << pelangganItem.getId()
             << ", Nama: " << pelangganItem.getNama()
             << ", Email: " << pelangganItem.getEmail() << endl;
    }
}

int CRM::cariPelangganIteratif(int id) const {
    for (size_t i = 0; i < pelanggan.size(); ++i) {
        if (pelanggan[i].getId() == id) return i;
    }
    return -1;
}

int CRM::cariPelangganRekursif(int id, int awal, int akhir) const {
    if (awal > akhir) return -1;
    int tengah = (awal + akhir) / 2;
    if (pelanggan[tengah].getId() == id) return tengah;
    if (pelanggan[tengah].getId() > id)
        return cariPelangganRekursif(id, awal, tengah - 1);
    return cariPelangganRekursif(id, tengah + 1, akhir);
}

vector<Customer>& CRM::getPelanggan() {
    return pelanggan;
}
