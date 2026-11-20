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
// https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
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
#define IDDUMMY         "XXXXXX"                                   // tanda EOF (End Of File) / nilai dummy ID 
#define DATEDUMMY       "XXXXXXXX"                                 // nilai dummy tanggal
#define MAX             999                                        // nilai maksimal array rekaman

// EOF setiap tabel
#define EOFPOSITION     (IDDUMMY" XXX "DATEDUMMY" "DATEDUMMY)                                                           // posisi
#define EOFSKILL        (IDDUMMY" XXX XXXXX "DATEDUMMY" "DATEDUMMY)                                                     // skill
#define EOFTARGET       (IDDUMMY" "IDDUMMY" "IDDUMMY" 9 "DATEDUMMY" "DATEDUMMY)                                         // target
#define EOFORGANIZATION (IDDUMMY" XXX "DATEDUMMY" "DATEDUMMY)                                                           // organisasi
#define EOFCERTIFICATE  (IDDUMMY" XXX "IDDUMMY" "DATEDUMMY" "DATEDUMMY" "IDDUMMY" XXXXXXXXXX "DATEDUMMY" "DATEDUMMY)    // sertifikat
#define EOFEXPERIENCE   (IDDUMMY" "IDDUMMY" "IDDUMMY" "DATEDUMMY" "DATEDUMMY" "DATEDUMMY" "DATEDUMMY)                   // pengalaman
#define EOFCATEGORY     (IDDUMMY" XXX "DATEDUMMY" "DATEDUMMY)                                                           // kategori
#define EOFPROJECT      (IDDUMMY" XXX XXXXXXXXXX "DATEDUMMY" "IDDUMMY" "DATEDUMMY" "DATEDUMMY)                          // proyek

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
    bool isSkilled; 
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
bool eop(char ribbon[]);    // mengecek eop
void start(char ribbon[]);  // memulai mesin kata
void reset();               // mengosongkan kata saat ini
void inc(char ribbon[]);    // memajukan kata
char* getcw();              // mengambil kata saat ini
int getwlen();              // mengambil panjang kata saat ini

// searching
void searchId(void* arr, int n, char* search, bool *found, int *idx, int type); // mencari data id
int longestName(void* data, int n, int type);                                   // mencari nama terpanjang
int longestUrl(void* data, int n, int type);                                    // mencari url terpanjang
int longestCredential(certificate* data, int n);                                // mencari krensial terpanjang

// ui tabel
void showPositionTable(int lenMaxName, int n, position* data);                      // tabel posisi
void showSkillTable(int lenMaxName, int n, skill* data);                            // tabel skill
void showTargetTable(int n, target* data);                                          // tabel target
void showOrganizationTable(int lenMaxName, int n, organization* data);              // tabel organisasi
void showCertificateTable(int lenMaxName, int lenMaxUrl, int n, certificate* data); // tabel sertifikat
void showExperienceTable(int n, experience* data);                                  // tabel pengalaman
void showCategoryTable(int lenMaxName, int n, category* data);                      // tabel kategori
void showProjectTable(int lenMaxName, int lenMaxUrl, int n, project* data);         // tabel proyek

// ui tabel join
// tabel gabungan posisi, skill, dan target
void showPositionSkillTarget(int maxTarName, int maxPosName, int maxSklName, int tarSum, int posSum, int sklSum, target* tarData, position* posData, skill* sklData);
// tabel gabungan organisasi, dan sertifikat
void showOrganizationCertificate(int maxCerName, int maxUrl, int maxOrgName, int cerSum, int orgSum, certificate* cerData, organization* orgData);
// tabel gabungan organisasi, posisi, dan pengalaman
void showOrganizationPositionExperience(int maxExpName, int maxOrgName, int maxPosName, int expSum, int orgSum, int posSum, experience* expData, organization* orgData, position* posData);
// tabel gabungan kategori, dan proyek
void showCategoryProject(int maxProName, int maxUrl, int maxCatName, int proSum, int catSum, project* proData, category* catData);

// perintah tabel posisi
void getPosition(char command[]);       // menampilkan data
void postPosition(char command[]);      // menambahkan data
void updatePosition(char command[]);    // mengubah data
void deletePosition(char command[]);    // menghapus data
void guidePosition();                   // panduan posisi

// perintah tabel skill
void getSkill(char command[]);       // menampilkan data
void postSkill(char command[]);      // menambahkan data
void updateSkill(char command[]);    // mengubah data
void deleteSkill(char command[]);    // menghapus data
void guideSkill();                   // panduan skill

// perintah tabel target
void getTarget(char command[]);       // menampilkan data
void postTarget(char command[]);      // menambahkan data
void updateTarget(char command[]);    // mengubah data
void deleteTarget(char command[]);    // menghapus data
void guideTarget();                   // panduan target

// perintah tabel organisasi
void getOrganization(char command[]);       // menampilkan data
void postOrganization(char command[]);      // menambahkan data
void updateOrganization(char command[]);    // mengubah data
void deleteOrganization(char command[]);    // menghapus data
void guideOrganization();                   // panduan organisasi

// perintah tabel sertifikat
void getCertificate(char command[]);       // menampilkan data
void postCertificate(char command[]);      // menambahkan data
void updateCertificate(char command[]);    // mengubah data
void deleteCertificate(char command[]);    // menghapus data
void guideCertificate();                   // panduan sertifikat

// perintah tabel pengalaman
void getExperience(char command[]);       // menampilkan data
void postExperience(char command[]);      // menambahkan data
void updateExperience(char command[]);    // mengubah data
void deleteExperience(char command[]);    // menghapus data
void guideExperience();                   // panduan pengalaman

// perintah tabel kategori
void getCategory(char command[]);       // menampilkan data
void postCategory(char command[]);      // menambahkan data
void updateCategory(char command[]);    // mengubah data
void deleteCategory(char command[]);    // menghapus data
void guideCategory();                   // panduan kategori

// perintah tabel proyek
void getProject(char command[]);       // menampilkan data
void postProject(char command[]);      // menambahkan data
void updateProject(char command[]);    // mengubah data
void deleteProject(char command[]);    // menghapus data
void guideProject();                   // panduan proyek

// perintah join
void joinTargetPositionSkill(char command[]);               // menggabungkan tabel target, posisi, dan skill
void joinCertificateOrganization(char command[]);           // menggabungkan tabel sertifikat, dan organisasi
void joinExperienceOrganizationPosition(char command[]);    // menggabungkan tabel pengalaman, organisasi, dan posisi
// atas ini belum dibuat

void joinProjectCategory(char command[]);                   // menggabungkan tabel kategori, dan proyek
