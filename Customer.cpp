#include "Customer.h"

Customer::Customer(int id, const string& nama, const string& email)
    : id(id), nama(nama), email(email) {}

int Customer::getId() const { return id; }

string Customer::getNama() const { return nama; }

string Customer::getEmail() const { return email; }

void Customer::setNama(const string& nama) { this->nama = nama; }

void Customer::setEmail(const string& email) { this->email = email; }
