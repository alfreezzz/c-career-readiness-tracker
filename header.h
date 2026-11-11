// Saya Alfriza sebagai manusia yang berTuhan, saya mengerjakan evaluasi 
// Tugas Masa Depan dalam mata kuliah Dasar-dasar Pemrograman untuk 
// keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah 
// dispesifikasikan. Aamiin.

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define DEFAULT "\033[0m"   // warna default
#define BLACK   "\033[30m"  // warna hitam
#define RED     "\033[31m"  // warna merah
#define GREEN   "\033[32m"  // warna hijau
#define YELLOW  "\033[33m"  // warna kuning
#define BLUE    "\033[34m"  // warna biru
#define MAGENTA "\033[35m"  // warna ungu
#define CYAN    "\033[36m"  // warna 
#define WHITE   "\033[37m"  // warna putih

// variabel untuk mesin kata
extern int indeks, wordLen;
extern char cw[50];

void error(int code);

// mesin kata
void start(char ribbon[]);
void reset();
void inc(char ribbon[]);
char* getcw();
int getwlen();
int eop(char ribbon[]);