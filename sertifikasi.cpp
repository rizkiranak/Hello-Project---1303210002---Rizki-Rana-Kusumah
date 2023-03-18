#include "sertifikasi.h"

// Deklarasi Prosedur dan Fungsi dasar (Create List, Create Element)
void createListSertifikasi(List_sertifikasi &L){
    first(L) = nil;
}
void createListPegawai(List_pegawai &L){
    first(L) = nil;
    last(L) = nil;
}
void createListRelasi(List_relasi &L){
    first(L) = nil;
    last(L) = nil;
}
adr_sertifikasi createElmSertifikasi(infotype_sertifikasi x){
    adr_sertifikasi P;
    P = new elm_sertifikasi;
    info(P) = x;
    next(P) = nil;
    return P;
}
adr_pegawai createElmPegawai(infotype_pegawai x){
    adr_pegawai P;
    P = new elm_pegawai;
    info(P) = x;
    next(P) = nil;
    prev(P) = nil;
    return P;
}
adr_relasi createElmRelasi(adr_sertifikasi s, adr_pegawai p){
    adr_relasi P;
    P = new elm_relasi;
    sertifikasi(P) = s;
    pegawai(P) = p;
    next(P) = nil;
    prev(P) = nil;
    return P;
}

// Deklarasi Prosedur dan Fungsi sesuai permintaan soal
// a. Tambahkan data sertifikasi baru
void insertSertifikasi(List_sertifikasi &L, adr_sertifikasi P){
    if(first(L) == nil){ // Jika list kosong
        first(L) = P; // P di assign ke First(L)
    }else{ // Jika list tidak kosong
        adr_sertifikasi Q = first(L); // Q di assign ke First(L) terlebih dahulu untuk mencari elemen terakhir
        while(next(Q) != nil){ // Looping untuk mencari elemen terakhir
            Q = next(Q);
        }
        next(Q) = P; // P di assign ke next(Q) atau elemen terakhir
    }
} //Insert Last
// b. Tambahkan data pegawai baru
void insertPegawai(List_pegawai &L, adr_pegawai P){ // Circular Double Linked List
    if(first(L) == nil){ // Jika list kosong
        first(L) = P; // P di assign ke First(L)
        last(L) = P; // P di assign ke Last(L)
        next(P) = P;
        prev(P) = P;
    } else { // Jika list tidak kosong
        next(P) = first(L); // P di assign ke next(P) atau First(L)
        prev(P) = last(L); // P di assign ke prev(P) atau Last(L)
        next(last(L)) = P; // P di assign ke next(Last(L))
        prev(first(L)) = P; // P di assign ke prev(First(L))
        last(L) = P; // P di assign ke Last(L)
    }
} //Insert Last
// c. Mencari data pegawai tertentu berdasarkan nama
adr_pegawai findPegawai(List_pegawai L, string nama){
    adr_pegawai P = first(L); // P di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
    while(P != last(L) && info(P).nama != nama){ // Looping untuk mencari elemen yang dicari
        P = next(P);
    }
    if(info(P).nama == nama){ /*Jika elemen yang dicari ditemukan (ini juga digunakan ketika list hanya terdiri dari 1 elemen dan juga ketika elemen yang dicari berada di elemen terakhir,
                                karena looping berhenti ketika P == last(L), maka elemen terakhir tidak akan dicek lagi, oleh karena itu dicek lagi di if ini)*/
        return P; // Mengembalikan P
    } else { // Jika elemen yang dicari tidak ditemukan
        return nil; // Mengembalikan nil
    }
}
adr_sertifikasi findSertifikasi(List_sertifikasi L, string jenis){ // Single Linked List
    adr_sertifikasi P;
    P = first(L);
    while(P != nil && info(P).jenis != jenis){ // Looping untuk mencari elemen yang dicari, berhenti ketika P telah sampai elemen terakhir atau elemen yang dicari ditemukan
        P = next(P);
    }
    return P; // Mengembalikan P, jika P == nil maka elemen yang dicari tidak ditemukan, dan returnnya nil
}
// d. Menambahkan relasi antara sertifikasi dan pegawai
void insertRelasi(List_relasi &L, adr_relasi P){
    if(first(L) == nil){ // Jika list kosong
        first(L) = P; // P di assign ke First(L)
        last(L) = P; // P di assign ke Last(L)
        next(P) = P;
        prev(P) = P;
    } else { // Jika list tidak kosong
        next(P) = first(L); // P di assign ke next(P) atau First(L)
        prev(P) = last(L); // P di assign ke prev(P) atau Last(L)
        next(last(L)) = P; // P di assign ke next(Last(L))
        prev(first(L)) = P; // P di assign ke prev(First(L))
        last(L) = P; // P di assign ke Last(L)
    }
} //Insert Last ke List Relasi (Circular Double Linked List)
// e. Menampilkan data pegawai yang memiliki sertifikasi tertentu
void showPegawaiSertifikasi(List_relasi L, adr_sertifikasi s){
    adr_relasi P = first(L); // P di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
    int i = 1;
    if(first(L) != nil){
        cout << "Pegawai yang memiliki sertifikasi " << info(s).jenis << " adalah : " << endl;
        while(P != last(L)){ // Looping untuk mencari elemen yang dicari, berhenti ketika P telah sampai elemen terakhir
            if(sertifikasi(P) == s){ // Jika sertifikasi(P) == s, maka tampilkan nama pegawai
                cout << i << ". " << info(pegawai(P)).nama << endl;
                i++;
            }
            P = next(P);
        }
        if(sertifikasi(P) == s){ // Jika sertifikasi(P) == s, maka tampilkan nama pegawai, ini juga digunakan ketika list hanya terdiri dari 1 elemen dan juga ketika elemen yang dicari berada di elemen terakhir,
                                // karena looping berhenti ketika P == last(L), maka elemen terakhir tidak akan dicek lagi, oleh karena itu dicek lagi di if ini
            cout << i << ". " << info(pegawai(P)).nama << endl;
        }
    } else { // Jika list kosong
        cout << "List relasi kosong, tidak bisa menampilkan" << endl;
    }
}
// f. Menghapus data sertifikasi dan menghapus relasinya
void deleteSertifikasi(List_sertifikasi &L, adr_sertifikasi &P){ // delete di P, single linked list
    if(first(L) == P){ // Jika P adalah elemen pertama
        first(L) = next(P); // First(L) di assign ke next(P)
    } else { // Jika P bukan elemen pertama, bisa jadi elemen terakhir atau elemen di tengah
        adr_sertifikasi Q = first(L); // Q di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
        while(next(Q) != P){ // Looping untuk mencari elemen yang dicari (elemen sebelum P), berhenti ketika next(Q) == P
            Q = next(Q);
        }
        next(Q) = next(P); // next(Q) di assign ke next(P)
    }
}
void deleteRelasi(List_relasi &L, adr_relasi &P){
    if(first(L) == P){ // Jika P adalah elemen pertama
        if(next(P) == P){ // Jika list hanya terdiri dari 1 elemen
            first(L) = nil; // First(L) di assign ke nil
            last(L) = nil; // Last(L) di assign ke nil
        } else { // Jika list terdiri dari lebih dari 1 elemen
            first(L) = next(P); // First(L) di assign ke next(P)
            next(last(L)) = first(L); // next(Last(L)) di assign ke First(L)
            prev(first(L)) = last(L); // prev(First(L)) di assign ke Last(L)
        }
        prev(P) = nil; // prev(P) di assign ke nil
    } else { // Jika P bukan elemen pertama, bisa jadi elemen terakhir atau elemen di tengah
        adr_relasi Q = first(L); // Q di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
        while(next(Q) != P){ // Looping untuk mencari elemen yang dicari (elemen sebelum P), berhenti ketika next(Q) == P
            Q = next(Q);
        }
        next(Q) = next(P); // next(Q) di assign ke next(P)
        prev(next(P)) = Q; // prev(next(P)) di assign ke Q
        prev(P) = nil; // prev(P) di assign ke nil
    }
}
void deleteSertifikasiRelasi(List_relasi &L, adr_sertifikasi &P, List_sertifikasi &L2){
    adr_relasi Q = first(L); // Q di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
    while(Q != last(L)){ // Looping untuk mencari elemen yang dicari, berhenti ketika Q telah sampai elemen terakhir
        if(sertifikasi(Q) == P){ // Jika sertifikasi(Q) == P, maka hapus relasi tersebut
            deleteRelasi(L, Q);
        }
        Q = next(Q);
    }
    if(sertifikasi(Q) == P){ // Jika sertifikasi(Q) == P, maka hapus relasi tersebut, ini juga digunakan ketika list hanya terdiri dari 1 elemen dan juga ketika elemen yang dicari berada di elemen terakhir,
                            // karena looping berhenti ketika Q == last(L), maka elemen terakhir tidak akan dicek lagi, oleh karena itu dicek lagi di if ini
        deleteRelasi(L, Q);
    }
    deleteSertifikasi(L2, P);
}
// g. Menghapus data pegawai yang memiliki sertifikasi tertentu
void deletePegawaiSertifikasi(List_relasi &L, adr_sertifikasi &P){ // Karena kita hanya mengetahui sertifikasi yang dimiliki pegawai, maka kita harus mencari relasi yang memiliki sertifikasi tersebut, baru hapus relasi tersebut
    adr_relasi Q = first(L); // Q di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
    while(Q != last(L)){ // Looping untuk mencari elemen yang dicari, berhenti ketika Q telah sampai elemen terakhir
        if(sertifikasi(Q) == P){ // Jika sertifikasi(Q) == P, maka hapus relasi Q
            deleteRelasi(L, Q);
        }
        Q = next(Q);
    }
    if(sertifikasi(Q) == P){ // Jika sertifikasi(Q) == P, maka hapus relasi Q, ini juga digunakan ketika list hanya terdiri dari 1 elemen dan juga ketika elemen yang dicari berada di elemen terakhir,
                            // karena looping berhenti ketika Q == last(L), maka elemen terakhir tidak akan dicek lagi, oleh karena itu dicek lagi di if ini
        deleteRelasi(L, Q);
    }
}
// h. Menampilkan seluruh pegawai dan sertifikasinya
void showAll(List_relasi L){
    if(first(L) != nil){ // Jika list tidak kosong
        adr_relasi P = first(L); // P di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
        int i = 1;
        while(P != last(L)){ // Looping untuk mencari elemen yang dicari, berhenti ketika P telah sampai elemen terakhir
            cout << i << ". " << info(pegawai(P)).nama << " - " << info(sertifikasi(P)).jenis << endl;
            i++;
            P = next(P);
        }
        cout << i << ". " << info(pegawai(P)).nama << " - " << info(sertifikasi(P)).jenis << endl; // Ini juga digunakan ketika list hanya terdiri dari 1 elemen dan juga ketika elemen yang dicari berada di elemen terakhir,
                                                                                            // karena looping berhenti ketika P == last(L), maka elemen terakhir tidak akan dicek lagi, oleh karena itu dicek lagi di if ini
    } else { // Jika list kosong
        cout << "List relasi kosong" << endl;
    }
}
// i. Menampilkan data pegawai yang memiliki sertifikasi terbanyak
void showPegawaiSertifikasiTerbanyak(List_relasi L){
    if(first(L) != nil){ // Jika list tidak kosong
        adr_relasi P = first(L); // P di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
        int max = 0;
        while(P != last(L)){ // Looping untuk mencari elemen yang dicari
            int count = 0;
            adr_relasi Q = first(L); // Q di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
            while(Q != last(L)){ // Looping untuk mencari elemen yang dicari
                if(pegawai(P) == pegawai(Q)){ // Jika pegawai(P) == pegawai(Q), maka count ditambah 1
                    count++;
                }
                Q = next(Q);
            }
            if(pegawai(P) == pegawai(Q)){ // Ini juga digunakan ketika list hanya terdiri dari 1 elemen dan juga ketika elemen yang dicari berada di elemen terakhir,
                                        // karena looping berhenti ketika Q == last(L), maka elemen terakhir tidak akan dicek lagi, oleh karena itu dicek lagi di if ini
                count++;
            }
            if(count > max){ // Jika count > max, maka max di assign ke count
                max = count;
            }
            P = next(P);
        }
        int count = 0;
        adr_relasi Q = first(L); // Q di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
        while(Q != last(L)){ // Looping untuk mencari elemen yang dicari
            if(pegawai(P) == pegawai(Q)){ // Jika pegawai(P) == pegawai(Q), maka count ditambah 1
                count++;
            }
            Q = next(Q);
        }
        if(pegawai(P) == pegawai(Q)){ // Ini juga digunakan ketika list hanya terdiri dari 1 elemen dan juga ketika elemen yang dicari berada di elemen terakhir,
                                    // karena looping berhenti ketika Q == last(L), maka elemen terakhir tidak akan dicek lagi, oleh karena itu dicek lagi di if ini
            count++;
        }
        if(count > max){ // Jika count > max, maka max di assign ke count
            max = count;
        }
        P = first(L); // P di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
        while(P != last(L)){ // Looping untuk mencari elemen yang dicari
            int count = 0;
            adr_relasi Q = first(L); // Q di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
            while(Q != last(L)){ // Looping untuk mencari elemen yang dicari
                if(pegawai(P) == pegawai(Q)){ // Jika pegawai(P) == pegawai(Q), maka count ditambah 1
                    count++;
                }
                Q = next(Q);
            }
            if(pegawai(P) == pegawai(Q)){ // Ini juga digunakan ketika list hanya terdiri dari 1 elemen dan juga ketika elemen yang dicari berada di elemen terakhir,
                                        // karena looping berhenti ketika Q == last(L), maka elemen terakhir tidak akan dicek lagi, oleh karena itu dicek lagi di if ini
                count++;
            }
            if(count == max){ // Jika count == max, maka data pegawai(P) ditampilkan
                cout << "Pegawai dengan sertifikasi paling banyak adalah : " << info(pegawai(P)).nama << endl;
            }
            P = next(P);
        }
    } else { // Jika list kosong
        cout << "List relasi kosong" << endl;
    }
}
// j. Menampilkan data sertifikasi yang paling banyak diikuti pegawai
void showSertifikasiTerbanyak(List_relasi L){
    if(first(L) != nil){ // Jika list tidak kosong
        adr_relasi P = first(L); // P di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
        int max = 0;
        while(P != last(L)){ // Looping untuk mencari elemen yang dicari
            int count = 0;
            adr_relasi Q = first(L); // Q di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
            while(Q != last(L)){ // Looping untuk mencari elemen yang dicari
                if(sertifikasi(P) == sertifikasi(Q)){ // Jika sertifikasi(P) == sertifikasi(Q), maka count ditambah 1
                    count++;
                }
                Q = next(Q);
            }
            if(sertifikasi(P) == sertifikasi(Q)){ // Ini juga digunakan ketika list hanya terdiri dari 1 elemen dan juga ketika elemen yang dicari
                                                // berada di elemen terakhir, karena looping berhenti ketika Q == last(L), maka elemen terakhir tidak akan dicek lagi,
                                                // oleh karena itu dicek lagi di if ini
                count++;
            }
            if(count > max){ // Jika count > max, maka max di assign ke count
                max = count;
            }
            P = next(P);
        }
        int count = 0;
        adr_relasi Q = first(L); // Q di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
        while(Q != last(L)){ // Looping untuk mencari elemen yang dicari
            if(sertifikasi(P) == sertifikasi(Q)){ // Jika sertifikasi(P) == sertifikasi(Q), maka count ditambah 1
                count++;
            }
            Q = next(Q);
        }
        if(sertifikasi(P) == sertifikasi(Q)){ // Ini juga digunakan ketika list hanya terdiri dari 1 elemen dan juga ketika elemen yang dicari
                                            // berada di elemen terakhir, karena looping berhenti ketika Q == last(L), maka elemen terakhir tidak akan dicek lagi,
                                            // oleh karena itu dicek lagi di if ini
            count++;
        }
        if(count > max){ // Jika count > max, maka max di assign ke count
            max = count;
        }
        P = first(L); // P di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
        while(P != last(L)){ // Looping untuk mencari elemen yang dicari
            int count = 0;
            adr_relasi Q = first(L); // Q di assign ke First(L) terlebih dahulu untuk mencari elemen yang dicari
            while(Q != last(L)){ // Looping untuk mencari elemen yang dicari
                if(sertifikasi(P) == sertifikasi(Q)){ // Jika sertifikasi(P) == sertifikasi(Q), maka count ditambah 1
                    count++;
                }
                Q = next(Q);
            }
            if(sertifikasi(P) == sertifikasi(Q)){ // Ini juga digunakan ketika list hanya terdiri dari 1 elemen dan juga ketika elemen yang dicari
                                                // berada di elemen terakhir, karena looping berhenti ketika Q == last(L), maka elemen terakhir tidak akan dicek lagi,
                                                // oleh karena itu dicek lagi di if ini
                count++;
            }
            if(count == max){ // Jika count == max, maka data sertifikasi(P) ditampilkan
                cout << "Sertifikasi yang paling banyak diikuti pegawai adalah : " << info(sertifikasi(P)).jenis << endl;
            }
            P = next(P);
        }
    }else{ // Jika list kosong
        cout << "List Kosong" << endl;
    }
}
// k. Menu(Program Utama)
int Menu(){
    int pilihanmenu = 0;
    cout << "\t\t Menu" << endl;
    cout << "1. Tambah Sertifikasi" << endl;
    cout << "2. Tambah Pegawai" << endl;
    cout << "3. Cari Pegawai" << endl;
    cout << "4. Tambah Relasi" << endl;
    cout << "5. Cari pegawai yang mengikuti sertifikasi tertentu" << endl;
    cout << "6. Hapus sertifikasi dan relasinya" << endl;
    cout << "7. Hapus pegawai yang mengikuti sertifikasi tertentu" << endl;
    cout << "8. Tampilkan semua pegawai dan sertifikasi yang diikuti" << endl;
    cout << "9. Tampilkan pegawai yang memiliki sertifikasi terbanyak" << endl;
    cout << "10. Tampilkan sertifikasi yang paling banyak diikuti pegawai" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilih menu : ";
    cin >> pilihanmenu;
    return pilihanmenu;
}
