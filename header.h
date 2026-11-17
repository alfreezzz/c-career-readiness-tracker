// Saya Alfriza sebagai manusia yang berTuhan, saya mengerjakan evaluasi 
// Tugas Masa Depan dalam mata kuliah Dasar-dasar Pemrograman untuk 
// keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah 
// dispesifikasikan. Aamiin.

#include <stdio.h>      // library bawaan bahasa C
#include <string.h>     // library string
#include <time.h>       // library mengambil tanggal dan waktu
#include <stdbool.h>    // library boolean

#define DEFAULT "\033[0;0m"   // reset warna teks

// makro warna teks (regular)
#define BLACK   "\033[0;30m"  // warna hitam
#define RED     "\033[0;31m"  // warna merah
#define GREEN   "\033[0;32m"  // warna hijau
#define YELLOW  "\033[0;33m"  // warna kuning
#define BLUE    "\033[0;34m"  // warna biru
#define PURPLE  "\033[0;35m"  // warna ungu
#define CYAN    "\033[0;36m"  // warna cyan
#define WHITE   "\033[0;37m"  // warna putih

// makro warna teks (bold)
#define BBLACK   "\033[1;30m"  // warna hitam
#define BRED     "\033[1;31m"  // warna merah
#define BGREEN   "\033[1;32m"  // warna hijau
#define BYELLOW  "\033[1;33m"  // warna kuning
#define BBLUE    "\033[1;34m"  // warna biru
#define BPURPLE  "\033[1;35m"  // warna ungu
#define BCYAN    "\033[1;36m"  // warna cyan
#define BWHITE   "\033[1;37m"  // warna putih

#define EOP '$' // simbol EOP (End Of Process)

#define TABLETEMPLATE   char id[7], createdAt[20], updatedAt[20]   // template tabel
#define IDDUMMY         "XXXXXX"                                    // tanda EOF (End Of File) / nilai dummy ID 
#define DATEDUMMY       "XXXXXXXX"                                  // nilai dummy tanggal

// EOF setiap tabel
#define EOFPOSITION     (IDDUMMY" XXX "DATEDUMMY" "DATEDUMMY)
#define EOFSKILL        (IDDUMMY" XXX XXXXX "DATEDUMMY" "DATEDUMMY)
#define EOFTARGET       (IDDUMMY" "IDDUMMY" "IDDUMMY" X "DATEDUMMY" "DATEDUMMY)
#define EOFORGANIZATION (IDDUMMY" XXX "DATEDUMMY" "DATEDUMMY)
#define EOFCERTIFICATE  (IDDUMMY" XXX "IDDUMMY" "DATEDUMMY" "DATEDUMMY" "IDDUMMY" XXXXXXXXXX "DATEDUMMY" "DATEDUMMY)
#define EOFEXPERIENCE   (IDDUMMY" "IDDUMMY" "IDDUMMY" "DATEDUMMY" "DATEDUMMY" "DATEDUMMY" "DATEDUMMY)
#define EOFCATEGORY     (IDDUMMY" XXX "DATEDUMMY" "DATEDUMMY)
#define EOFPROJECT      (IDDUMMY" XXX XXXXXXXXXX "DATEDUMMY" "IDDUMMY" "DATEDUMMY" "DATEDUMMY)

// struktur data
typedef struct{ // posisi
    TABLETEMPLATE;
    char name[50];
} position;

typedef struct{ // keahlian
    TABLETEMPLATE;
    char name[50], proficiency[50];
} skill;

typedef struct{ // target pekerjaan
    TABLETEMPLATE;
    char positionId[20], skillId[20];
    char isSkilled; 
} target;

typedef struct{ // organisasi
    TABLETEMPLATE;
    char name[50];
} organization;

typedef struct{ // sertifikasi
    TABLETEMPLATE;
    char name[50], issuerId[10], startDate[20], endDate[20], credentialId[50], url[100];
} certificate;

typedef struct{ // pengalaman
    TABLETEMPLATE;
    char organizationId[10], positionId[10], startDate[20], endDate[20];
} experience;

typedef struct{ // kategori
    TABLETEMPLATE;
    char name[50];
} category;

typedef struct{ // proyek
    TABLETEMPLATE;
    char name[50], url[100], finishedDate[20], categoryId[10];
} project;

extern int indeks, wordLen; // indeks kata dan panjang kata
extern char cw[50];         // kata saat ini

// formatting
void timeStamp(char buffer[]);  // mengambil waktu saat ini

// ui aplikasi
void guideTitle();  // header buku panduan 
void guideFooter(); // footer buku panduan 
void guide();       // buku panduan
void in();          // tampilan awal
void out();         // tampilan akhir

// response
void success(int code); // pesan berhasil
void error(int code);   // pesan error

// mesin kata
int eop(char ribbon[]);     // mengecek eop
void start(char ribbon[]);  // memulai mesin kata
void reset();               // mengosongkan kata saat ini
void inc(char ribbon[]);    // memajukan kata
char* getcw();              // mengambil kata saat ini
int getwlen();              // mengambil panjang kata saat ini

// searching
void searchId(void* arr, int n, char* search, bool *found, int *idx, int type); // mencari data

// ui tabel
int longestName(void* data, int n, int type);
int longestUrl(void* data, int n, int type);
void showCategoryTable(int lenMaxName, int n, category* data);
void showProjectTable(int lenMaxName, int lenMaxUrl, int n, project* data);

// perintah tabel kategori
void getCategory(char command[]);       // menampilkan data
void postCategory(char command[]);      // menambahkan data
void updateCategory(char command[]);    // mengubah data
void deleteCategory(char command[]);    // menghapus data
void guideCategory();                   // panduan kategori
void getCategory(char command[]);       // menampilkan data

// perintah tabel proyek
void getProject(char command[]);       // menampilkan data
void postProject(char command[]);      // menambahkan data
void updateProject(char command[]);    // mengubah data
void deleteProject(char command[]);    // menghapus data
void guideProject();                   // panduan kategori
