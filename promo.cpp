#include "promo.h"

void createListPromo(listPromo &L) {
    L.first = L.last = nullptr;
}

adr_prom createElmPromo(infotypePromo x) {
    adr_prom p = new elmPromo;
    p->info = x;
    p->next = p->prev = nullptr;
    return p;
}

void insertLastPromo(listPromo &L, adr_prom p) {
    if (!L.first) {
        L.first = L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

adr_prom searchPromo(listPromo L, string id) {
    adr_prom p = L.first;
    while (p) {
        if (p->info.idPromo == id) return p;
        p = p->next;
    }
    return nullptr;
}

void createListProduk(listProduk &L) {
    L.first = L.last = nullptr;
}

adr_prod createElmProduk(infotypeProduk x) {
    adr_prod p = new elmProduk;
    p->info = x;
    p->next = p->prev = nullptr;
    return p;
}

void insertLastProduk(listProduk &L, adr_prod p) {
    if (!L.first) {
        L.first = L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

adr_prod searchProduk(listProduk L, string id) {
    adr_prod p = L.first;
    while (p) {
        if (p->info.idProduk == id) return p;
        p = p->next;
    }
    return nullptr;
}

bool deleteProduk(listProduk &L, adr_prod p) {
    if (!p) return false;

    if (p == L.first && p == L.last) {
        L.first = L.last = nullptr;
    } else if (p == L.first) {
        L.first = p->next;
        L.first->prev = nullptr;
    } else if (p == L.last) {
        L.last = p->prev;
        L.last->next = nullptr;
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    delete p;
    return true;
}

void createListRelasi(listRelasi &L) {
    L.first = nullptr;
}

adr_rel createElmRelasi(adr_prom p, adr_prod d) {
    adr_rel r = new elmRelasi;
    r->promo = p;
    r->produk = d;
    r->next = nullptr;
    return r;
}

void insertLastRelasi(listRelasi &L, adr_rel r) {
    if (!L.first) L.first = r;
    else {
        adr_rel q = L.first;
        while (q->next) q = q->next;
        q->next = r;
    }
}

void deleteRelasiByProduk(listRelasi &L, adr_prod d) {
    adr_rel cur = L.first, prev = nullptr;
    while (cur) {
        if (cur->produk == d) {
            if (!prev) L.first = cur->next;
            else prev->next = cur->next;
            delete cur;
            cur = (prev ? prev->next : L.first);
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}

void cekPromoProduk(listRelasi LR, adr_prod prod, int tgl) {
    adr_rel r = LR.first;
    bool aktif = false;

    cout << "\nProduk: " << prod->info.namaProduk << endl;
    cout << "Harga : " << prod->info.harga << endl;

    while (r) {
        if (r->produk == prod) {
            adr_prom p = r->promo;
            if (tgl >= p->info.tglMulai && tgl <= p->info.tglSelesai) {
                float hargaAkhir =
                    prod->info.harga - (prod->info.harga * p->info.diskon / 100);
                cout << "Promo Aktif: " << p->info.namaPromo << endl;
                cout << "Harga Akhir: " << hargaAkhir << endl;
                aktif = true;
            }
        }
        r = r->next;
    }

    if (!aktif)
        cout << "Tidak ada promo aktif\n";
}
