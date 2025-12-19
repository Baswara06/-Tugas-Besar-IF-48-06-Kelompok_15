#include "Apk.h"


void createListOjol(ListOjol &L){
  L.first = NULL;
}

adrOjol createOjol(string id, string nama) {
  adrOjol P = new Ojol;
  P->idOjol = id;
  P->nama = nama;
  P->next = NULL;
  P->relasiHead = NULL;
  return P;
}


void insertOjol(ListOjol &L, adrOjol P){
  if(L.first == NULL){ 
    L.first = P;
  }else{
    adrOjol Q = L.first;
  while(Q->next != NULL) Q = Q->next;
  Q->next = P;
}
}


adrOjol searchOjol(ListOjol L, string id){
adrOjol P = L.first;
while(P != NULL && P->idOjol != id){ 
  P = P->next;
}
return P;
}


void deleteOjol(ListOjol &L, string id){
  adrOjol prec = NULL, P = L.first;
  while(P != NULL && P->idOjol != id){
    prec = P;
    P = P->next;
  }
  if(P != NULL){
    if(prec == NULL){
      L.first = P->next;
    }else {
      prec->next = P->next;
      delete P;
}
}
}


void tampilOjol(ListOjol L){
  cout << "\nDaftar Ojol:\n";
  adrOjol P = L.first;
  while(P != NULL){
  cout << "- " << P->idOjol << " | " << P->nama << endl;
  P = P->next;
}
}
