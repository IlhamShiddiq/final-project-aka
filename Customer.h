#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
private:
    int id;
    string nama;
    string email;

public:
    Customer(int id, const string& nama, const string& email);
    int getId() const;
    string getNama() const;
    string getEmail() const;
    void setNama(const string& nama);
    void setEmail(const string& email);
};

#endif
