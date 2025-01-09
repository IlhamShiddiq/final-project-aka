#ifndef CRM_H
#define CRM_H

#include <vector>
#include "Customer.h"

using namespace std;

class CRM {
private:
    vector<Customer> pelanggan;

public:
    void tambahPelanggan(const Customer& pelangganBaru);
    bool ubahPelanggan(int id, const string& nama, const string& email);
    bool hapusPelanggan(int id);
    void tampilkanPelanggan() const;
    void urutkanPelanggan(); // Fungsi untuk mengurutkan pelanggan berdasarkan ID
    int cariPelangganIteratif(int id) const;
    int cariPelangganRekursif(int id, int awal, int akhir) const;
    vector<Customer>& getPelanggan();
};

#endif
