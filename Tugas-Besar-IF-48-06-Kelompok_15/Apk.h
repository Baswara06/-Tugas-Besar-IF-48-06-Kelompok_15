#ifndef APK_H_INCLUDED
#define APK_H_INCLUDED
#include<iostream>
using namespace std;


struct Penumpang;
struct Ojol;
struct Relasi;


typedef Penumpang* adrPenumpang;
struct Penumpang {
string idPenumpang, nama;
adrPenumpang next;
adrPenumpang prev;
};


struct Relasi {
adrPenumpang penumpang;
Relasi *next;
};


typedef Ojol* adrOjol;
struct Ojol {
string idOjol, nama;
adrOjol next;
Relasi *relasiHead;
};


struct ListOjol { adrOjol first; };
struct ListPenumpang { adrPenumpang first; };


void createListOjol(ListOjol &L);
adrOjol createOjol(string id, string nama);
void insertOjol(ListOjol &L, adrOjol P);
adrOjol searchOjol(ListOjol L, string id);
void deleteOjol(ListOjol &L, string id);
void tampilOjol(ListOjol L);


void createListPenumpang(ListPenumpang &L);
adrPenumpang createPenumpang(string id, string nama);
void insertPenumpang(ListPenumpang &L, adrPenumpang C);
adrPenumpang searchPenumpang(ListPenumpang L, string id);
void deletePenumpang(ListPenumpang &L, string id);
void tampilPenumpang(ListPenumpang L);


// menggabungkan
Relasi* createRelasi(adrPenumpang C);
void tambahRelasi(adrOjol P, adrPenumpang C);
void hapusRelasi(adrOjol P, string idPenumpang);
void tampilRelasi(adrOjol P);

#endif // PENUMPANG_H_INCLUDED
