// Saya Alfriza sebagai manusia yang berTuhan, saya mengerjakan evaluasi 
// Tugas Masa Depan dalam mata kuliah Dasar-dasar Pemrograman untuk 
// keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah 
// dispesifikasikan. Aamiin.

#include "header.h"

int indeks, wordLen;
char cw[50];

void error(int code){
    switch(code){
        case 0: {
            printf(RED "gada query itu woy\n" DEFAULT);
            break;
        }
        default: {
            printf(RED "gada query itu woy\n" DEFAULT);
            break;
        }
    }
    printf("\n");
}

void start(char ribbon[]){
    indeks = 0;
    wordLen = 0;
    while(ribbon[indeks] == ' '){
        indeks++;
    }
    while((ribbon[indeks] != ' ') && (ribbon[indeks] != '$')){
        cw[wordLen] = ribbon[indeks];
        wordLen++;
        indeks++;
    }
    cw[wordLen] = '\0';
}

void reset(){
    wordLen = 0;
    cw[wordLen] = '\0';
}

void inc(char ribbon[]){
    wordLen = 0;
    while(ribbon[indeks] == ' '){
        indeks++;
    }
    while((ribbon[indeks] != ' ') && (ribbon[indeks] != '$')){
        cw[wordLen] = ribbon[indeks];
        wordLen++;
        indeks++;
    }
    cw[wordLen] = '\0';
}

char* getcw(){
    return cw;
}

int getwlen(){
    return wordLen;
}

int eop(char ribbon[]){
    if(ribbon[indeks] == '$'){
        return 1;
    } else {
        return 0;
    }
}