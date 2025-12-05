#ifndef PENUMPANG_H_INCLUDED
#define PENUMPANG_H_INCLUDED

// parent
struct Ojek {
    string idOjek;
    string nama;
    Ojek* next;
    Ojek* prev;
};

// child/penumpang
struct Penumpang {
    string idPenumpang;
    string nama;
    string noTelp;
    string alamat;

    Penumpang* next;
    Penumpang* prev;
};

struct Relasi {
    Penumpang* p;
    Ojek* o;
    Relasi* next;
};

Penumpang* createPenumpang(string id, string nama, string telp, string alamat);
void insertPenumpang(Penumpang*& head, Penumpang* p);
Relasi* createRelasi(Penumpang* p, Ojek* o);
void insertRelasi(Relasi*& headRelasi, Relasi* r);
Penumpang* findPenumpang(Penumpang* head, string id);
void tampilPenumpangDenganOjek(Relasi* headRelasi);


#endif // PENUMPANG_H_INCLUDED
