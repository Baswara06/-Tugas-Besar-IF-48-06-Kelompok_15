
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
void insertOjolFirst(ListOjol &L, adrOjol P);
void insertOjolLast(ListOjol &L, adrOjol P);
void deleteOjolFirst(ListOjol &L);
void deleteOjolLast(ListOjol &L);

void createListPenumpang(ListPenumpang &L);
adrPenumpang createPenumpang(string id, string nama);
void insertPenumpang(ListPenumpang &L, adrPenumpang C);
adrPenumpang searchPenumpang(ListPenumpang L, string id);
void deletePenumpang(ListPenumpang &L, string id);
void tampilPenumpang(ListPenumpang L);
void insertPenumpangFirst(ListPenumpang &L, adrPenumpang P);
void insertPenumpangLast(ListPenumpang &L, adrPenumpang P);
void deletePenumpangFirst(ListPenumpang &L);
void deletePenumpangLast(ListPenumpang &L);


// menggabungkan
Relasi* createRelasi(adrPenumpang C);
void tambahRelasi(adrOjol P, adrPenumpang C);
void hapusRelasi(adrOjol P, string idPenumpang);
void tampilRelasi(adrOjol P);

//studycase
void driverTergiat(ListOjol L);
void penumpangRelasiTerbanyak(ListOjol LO, ListPenumpang LP);

//menu
void mainMenu(ListOjol &LO, ListPenumpang &LP);
void menuAdmin(ListOjol LO, ListPenumpang LP);
void menuStudiKasus(ListOjol &LO, ListPenumpang &LP);


#endif // PENUMPANG_H_INCLUDED
