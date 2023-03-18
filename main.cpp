#include "sertifikasi.h"

int main(){
    // Deklarasi Kamus
    List_sertifikasi Ls;
    List_pegawai Lp;
    List_relasi Lr;
    adr_sertifikasi Ps;
    adr_pegawai Pp;
    adr_relasi Pr;
    infotype_sertifikasi x;
    infotype_pegawai y;
    string nama, jenis;

    // Algoritma
    createListSertifikasi(Ls);
    createListPegawai(Lp);
    createListRelasi(Lr);
    int pilihan = Menu();
    while(pilihan != 0){
        switch(pilihan){
            case 1:
                cout << "Masukkan jenis sertifikasi: ";
                cin >> x.jenis;
                Ps = createElmSertifikasi(x);
                insertSertifikasi(Ls, Ps);
                cout << "Berhasil ditambahkan." <<endl;
                break;
            case 2:
                cout << "Masukkan nama pegawai: ";
                cin >> y.nama;
                Pp = createElmPegawai(y);
                insertPegawai(Lp, Pp);
                cout << "Berhasil ditambahkan." << endl;
                break;
            case 3:
                cout << "Masukkan nama pegawai yang ingin dicari: ";
                cin >> nama;
                Pp = findPegawai(Lp, nama);
                if(Pp != nil){
                    cout << "Pegawai dengan nama " << nama << " ditemukan" << endl;
                } else{
                    cout << "Pegawai dengan nama " << nama << " tidak ditemukan" << endl;
                }
                break;
            case 4:
                cout << "Masukkan nama pegawai : ";
                cin >> nama;
                Pp = findPegawai(Lp, nama); // Cari pegawainya, nantinya akan ditunjuk oleh pointer Pp
                if(Pp != nil){
                    cout << "Masukkan jenis sertifikasi : ";
                    cin >> jenis;
                    Ps = findSertifikasi(Ls, jenis); // Cari sertifikasinya nantinya akan ditunjuk oleh pointer Ps
                    if (Ps != nil){
                        Pr = createElmRelasi(Ps, Pp); // Buat elemen relasi baru menggunakan informasi Ps dan Pp tadi.
                        insertRelasi(Lr, Pr); // Masukkan elemen relasi baru ke dalam list relasi
                        cout << "Relasi berhasil ditambahkan." << endl;
                    } else{
                        cout << "Sertifikasi dengan jenis " << jenis << " tidak ditemukan, tidak bisa menambahkan relasi." << endl;
                    }
                } else{
                    cout << "Pegawai dengan nama " << nama << " tidak ditemukan, tidak bisa menambahkan relasi." << endl;
                }
                break;
            case 5:
                cout << "Masukkan jenis sertifikasi yang ingin ditampilkan pegawainya : ";
                cin >> jenis;
                Ps = findSertifikasi(Ls, jenis);
                if(Ps != nil){
                    showPegawaiSertifikasi(Lr, Ps);
                } else{
                    cout << "Jenis sertifikasi tidak ditemukan" << endl;
                }
                break;
            case 6:
                cout << "Masukkan nama sertifikasi yang ingin dihapus relasinya : ";
                cin >> jenis;
                Ps = findSertifikasi(Ls, jenis);
                if(Ps != nil){
                    deleteSertifikasiRelasi(Lr, Ps, Ls);
                    cout << "Sertifikasi dengan nama " << jenis << " berhasil dihapus" << endl;
                } else{
                    cout << "Sertifikasi dengan nama " << jenis << " tidak ditemukan, tidak bisa dihapus" << endl;
                }
                break;
            case 7:
                cout << "Masukkan jenis sertifikasi yang ingin dihapus pegawainya : ";
                cin >> jenis;
                Ps = findSertifikasi(Ls, jenis);
                if (Ps != nil){
                    deletePegawaiSertifikasi(Lr, Ps);
                    cout << "Pegawai dengan sertifikasi " << jenis << " berhasil dihapus" << endl;
                } else{
                    cout << "Sertifikasi dengan jenis " << jenis << " tidak ditemukan, tidak bisa dihapus" << endl;
                }
                break;
            case 8:
                cout << "Seluruh pegawai dan sertifikasinya : " << endl;
                showAll(Lr);
                break;
            case 9:
                showPegawaiSertifikasiTerbanyak(Lr);
                break;
            case 10:
                showSertifikasiTerbanyak(Lr);
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
                break;
        }
        pilihan = Menu();
    }
    return 0;
}
