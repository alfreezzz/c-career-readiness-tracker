// Saya Alfriza sebagai manusia yang berTuhan, saya mengerjakan evaluasi 
// Tugas Masa Depan dalam mata kuliah Dasar-dasar Pemrograman untuk 
// keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah 
// dispesifikasikan. Aamiin.

#include <stdio.h>      // library bawaan bahasa C
#include <string.h>     // library string
#include <time.h>       // library mengambil tanggal dan waktu
#include <stdbool.h>    // library boolean

#define DEFAULT "\e[0;0m"   // warna default teks
// makro warna teks (regular)
#define BLACK   "\e[0;30m"  // warna hitam
#define RED     "\e[0;31m"  // warna merah
#define GREEN   "\e[0;32m"  // warna hijau
#define YELLOW  "\e[0;33m"  // warna kuning
#define BLUE    "\e[0;34m"  // warna biru
#define PURPLE  "\e[0;35m"  // warna ungu
#define CYAN    "\e[0;36m"  // warna cyan
#define WHITE   "\e[0;37m"  // warna putih

// makro warna teks (bold)
#define BBLACK   "\e[1;30m"  // warna hitam
#define BRED     "\e[1;31m"  // warna merah
#define BGREEN   "\e[1;32m"  // warna hijau
#define BYELLOW  "\e[1;33m"  // warna kuning
#define BBLUE    "\e[1;34m"  // warna biru
#define BPURPLE  "\e[1;35m"  // warna ungu
#define BCYAN    "\e[1;36m"  // warna cyan
#define BWHITE   "\e[1;37m"  // warna putih

// makro warna background
// #define BGBLACK   "\e[0;40m"  // warna hitam
// #define BGRED     "\e[0;41m"  // warna merah
// #define BGGREEN   "\e[0;42m"  // warna hijau
// #define BGYELLOW  "\e[0;43m"  // warna kuning
// #define BGBLUE    "\e[0;44m"  // warna biru
// #define BGPURPLE  "\e[0;45m"  // warna ungu
// #define BGCYAN    "\e[0;46m"  // warna cyan
// #define BGWHITE   "\e[0;47m"  // warna putih

#define TABLETEMPLATE char id[10], createdAt[20], updatedAt[20] // makro template tabel
#define EOP '$'                                                 // makro simbol EOP (End Of Process)

typedef struct{
    TABLETEMPLATE;
    char name[50];
} category;

// variabel untuk mesin kata
extern int indeks, wordLen;
extern char cw[50];

// formatting
void timeStamp(char buffer[]);

// ui
void guide();
void in();

// response
void success(int code);
void error(int code);

// mesin kata
int eop(char ribbon[]);
void start(char ribbon[]);
void reset();
void inc(char ribbon[]);
char* getcw();
int getwlen();

// metode tabel kategori
void postCategory(char command[]);      // tambah data
void updateCategory(char command[]);    // ubah data
void deleteCategory(char command[]);    // hapus data