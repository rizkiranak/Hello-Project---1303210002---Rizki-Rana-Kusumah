#ifndef SERTIFIKASI_H_INCLUDED
#define SERTIFIKASI_H_INCLUDED

#include <iostream>

using namespace std;
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define sertifikasi(P) P->sertifikasi
#define pegawai(P) P->pegawai
#define nil NULL

struct sertifikasi{
    string jenis;
};
struct pegawai{
    string nama;
};

typedef sertifikasi infotype_sertifikasi;
typedef pegawai infotype_pegawai;

typedef struct elm_sertifikasi *adr_sertifikasi;
typedef struct elm_pegawai *adr_pegawai;
typedef struct elm_relasi *adr_relasi;

struct elm_sertifikasi{ // Single Linked List
    infotype_sertifikasi info;
    adr_sertifikasi next;
};
struct elm_pegawai{ // Circular Double Linked List
    infotype_pegawai info;
    adr_pegawai next;
    adr_pegawai prev;
};
struct elm_relasi{ // Circular Double Linked List
    adr_sertifikasi sertifikasi;
    adr_pegawai pegawai;
    adr_relasi next;
    adr_relasi prev;
};

struct List_sertifikasi{
    adr_sertifikasi first;
};
struct List_pegawai{
    adr_pegawai first;
    adr_pegawai last;
};
struct List_relasi{
    adr_relasi first;
    adr_relasi last;
};

// Deklarasi Prosedur dan Fungsi dasar (Create List, Create Element)
void createListSertifikasi(List_sertifikasi &L);
void createListPegawai(List_pegawai &L);
void createListRelasi(List_relasi &L);
adr_sertifikasi createElmSertifikasi(infotype_sertifikasi x);
adr_pegawai createElmPegawai(infotype_pegawai x);
adr_relasi createElmRelasi(adr_sertifikasi s, adr_pegawai p);

// Deklarasi Prosedur dan Fungsi sesuai permintaan soal
// a. Tambahkan data sertifikasi baru
void insertSertifikasi(List_sertifikasi &L, adr_sertifikasi P); //Insert Last
// b. Tambahkan data pegawai baru
void insertPegawai(List_pegawai &L, adr_pegawai P); //Insert Last
// c. Mencari data pegawai tertentu berdasarkan nama
adr_pegawai findPegawai(List_pegawai L, string nama);
adr_sertifikasi findSertifikasi(List_sertifikasi L, string jenis);
// d. Menambahkan relasi antara sertifikasi dan pegawai
void insertRelasi(List_relasi &L, adr_relasi P); //Insert Last ke List Relasi
// e. Menampilkan data pegawai yang memiliki sertifikasi tertentu
void showPegawaiSertifikasi(List_relasi L, adr_sertifikasi s);
// f. Menghapus data sertifikasi dan menghapus relasinya
void deleteSertifikasi(List_sertifikasi &L, adr_sertifikasi &P);
void deleteRelasi(List_relasi &L, adr_relasi &P);
void deleteSertifikasiRelasi(List_relasi &L, adr_sertifikasi &P, List_sertifikasi &L2);
// g. Menghapus data pegawai yang memiliki sertifikasi tertentu
void deletePegawaiSertifikasi(List_relasi &L, adr_sertifikasi &P);
// h. Menampilkan seluruh pegawai dan sertifikasinya
void showAll(List_relasi L);
// i. Menampilkan data pegawai yang memiliki sertifikasi terbanyak
void showPegawaiSertifikasiTerbanyak(List_relasi L);
// j. Menampilkan data sertifikasi yang paling banyak diikuti pegawai
void showSertifikasiTerbanyak(List_relasi L);
// k. Menu(Program Utama)
int Menu();
#endif // SERTIFIKASI_H_INCLUDED
