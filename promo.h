#ifndef PROMO_H_INCLUDED
#define PROMO_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct elmPromo* adr_prom;
typedef struct elmProduk* adr_prod;
typedef struct elmRelasi* adr_rel;

struct infotypePromo {
    string idPromo;
    string namaPromo;
    int tglMulai;
    int tglSelesai;
    float diskon;
};

struct infotypeProduk {
    string idProduk;
    string namaProduk;
    int harga;
};

struct elmPromo {
    infotypePromo info;
    adr_prom next, prev;
};

struct elmProduk {
    infotypeProduk info;
    adr_prod next, prev;
};

struct elmRelasi {
    adr_prom promo;
    adr_prod produk;
    adr_rel next;
};

struct listPromo {
    adr_prom first, last;
};

struct listProduk {
    adr_prod first, last;
};

struct listRelasi {
    adr_rel first;
};

void createListPromo(listPromo &L);
adr_prom createElmPromo(infotypePromo x);
void insertLastPromo(listPromo &L, adr_prom p);
adr_prom searchPromo(listPromo L, string id);
void createListProduk(listProduk &L);
adr_prod createElmProduk(infotypeProduk x);
void insertLastProduk(listProduk &L, adr_prod p);
adr_prod searchProduk(listProduk L, string id);
bool deleteProduk(listProduk &L, adr_prod p);
void createListRelasi(listRelasi &L);
adr_rel createElmRelasi(adr_prom p, adr_prod d);
void insertLastRelasi(listRelasi &L, adr_rel r);
void deleteRelasiByProduk(listRelasi &L, adr_prod d);
void cekPromoProduk(listRelasi LR, adr_prod prod, int tanggalCek);

#endif
