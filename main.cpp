#include "promo.h"

int main() {
    listPromo LP;
    listProduk LPD;
    listRelasi LR;

    createListPromo(LP);
    createListProduk(LPD);
    createListRelasi(LR);

    int pilih = -1;

    while (pilih != 0) {
        cout << "\n=== MENU ===\n";
        cout << "1. Input Promo\n";
        cout << "2. Input Produk\n";
        cout << "3. Hubungkan Produk ke Promo\n";
        cout << "4. Cek Promo Produk\n";
        cout << "5. Hapus Produk\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            infotypePromo p;
            cout << "ID Promo: "; getline(cin, p.idPromo);
            cout << "Nama Promo: "; getline(cin, p.namaPromo);
            cout << "Tanggal Mulai: "; cin >> p.tglMulai;
            cout << "Tanggal Selesai: "; cin >> p.tglSelesai;
            cout << "Diskon (%): "; cin >> p.diskon;
            cin.ignore();
            insertLastPromo(LP, createElmPromo(p));
        }

        else if (pilih == 2) {
            infotypeProduk d;
            cout << "ID Produk: "; getline(cin, d.idProduk);
            cout << "Nama Produk: "; getline(cin, d.namaProduk);
            cout << "Harga: "; cin >> d.harga;
            cin.ignore();
            insertLastProduk(LPD, createElmProduk(d));
        }

        else if (pilih == 3) {
            string idP, idD;
            cout << "ID Promo: "; getline(cin, idP);
            cout << "ID Produk: "; getline(cin, idD);
            adr_prom p = searchPromo(LP, idP);
            adr_prod d = searchProduk(LPD, idD);
            if (p && d)
                insertLastRelasi(LR, createElmRelasi(p, d));
            else
                cout << "Promo / Produk tidak ditemukan\n";
        }

        else if (pilih == 4) {
            string id;
            int tgl;
            cout << "ID Produk: "; getline(cin, id);
            cout << "Tanggal Cek: "; cin >> tgl;
            cin.ignore();
            adr_prod d = searchProduk(LPD, id);
            if (d) cekPromoProduk(LR, d, tgl);
            else cout << "Produk tidak ditemukan\n";
        }

        else if (pilih == 5) {
            string id;
            cout << "ID Produk: "; getline(cin, id);
            adr_prod d = searchProduk(LPD, id);
            if (d) {
                deleteRelasiByProduk(LR, d);
                deleteProduk(LPD, d);
                cout << "Produk dihapus\n";
            } else {
                cout << "Produk tidak ditemukan\n";
            }
        }
    }

    return 0;
}
