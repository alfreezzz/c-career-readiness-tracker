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
        case 1: {
            printf(RED "gada tabel itu woy\n" DEFAULT);
            break;
        }
        case 2: {
            printf(RED "masukkin eop nya ($) di akhir perintah woy\n" DEFAULT);
            break;
        }
        case 3: {
            printf(RED "masukkin nama tabelnya woy\n" DEFAULT);
            break;
        }
        case 4: {
            printf(RED "data yang dimasukkan kurang lengkap woy\n" DEFAULT);
            break;    
        }
        case 5: {
            printf(RED "masukkin datanya woy\n" DEFAULT);
            break;    
        }
        case 6: {
            printf(RED "melebihi data yang dibutuhkan woy\n" DEFAULT);
            break;    
        }
        case 7: {
            printf(RED "tidak boleh ada data dengan id yang sama woy\n" DEFAULT);
            break;    
        }
        case 8: {
            printf(RED "pilih data (dari id) yang bakal diubah woy\n" DEFAULT);
            break;    
        }
        case 9: {
            printf(RED "pilih data (dari id) yang bakal dihapus woy\n" DEFAULT);
            break;    
        }
        case 10: {
            printf(RED "query nya kurang lengkap woy\n" DEFAULT);
            break;    
        }
        default: {
            printf(RED "gada query itu woy\n" DEFAULT);
            break;
        }
    }
}

int eop(char ribbon[]){
    if(ribbon[indeks] == '$'){
        return 1;
    } else {
        return 0;
    }
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

// category
void postCategory(char command[]){
    int recordSum = 0;
    category temp[100];
    category record, new;
    
    FILE *categoryTable;
    categoryTable = fopen("tables/tcategory.dat", "r");
    
    printf("mulai proses memasukkan isi file ke array\n");
    fscanf(categoryTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);

    if(strcmp(record.id, "XXXXXXXX") == 0 || strcmp(record.id, "") == 0){
        printf("arsip kosong\n");
    } else {
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(categoryTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, "XXXXXXXX") != 0);
    }
    fclose(categoryTable);
    
    inc(command);
    if(eop(command) == 0){
        strcpy(new.id, getcw());

        inc(command);
        if(eop(command) == 1){
            strcpy(new.name, getcw());

            strcpy(new.createdAt, "Nov-12-2026");
            strcpy(new.updatedAt, "Nov-12-2026");

            bool isDuplicate = false;
            // kondisi memasukkan ke dalam array
            if(strcmp(new.id, temp[0].id) < 0){
                // rekaman baru di paling depan
                // geser semua isi array ke belakang
                for(int i = recordSum - 1; i >= 0; i--){
                    strcpy(temp[i+1].id, temp[i].id);
                    strcpy(temp[i+1].name, temp[i].name);
                    strcpy(temp[i+1].createdAt, temp[i].createdAt);
                    strcpy(temp[i+1].updatedAt, temp[i].updatedAt);
                }
                recordSum++;
                strcpy(temp[0].id, new.id);
                strcpy(temp[0].name, new.name);
                strcpy(temp[0].createdAt, new.createdAt);
                strcpy(temp[0].updatedAt, new.updatedAt);
            } else if (strcmp(new.id, temp[recordSum - 1].id) > 0){
                // rekaman baru di belakang
                strcpy(temp[recordSum].id, new.id);
                strcpy(temp[recordSum].name, new.name);
                strcpy(temp[recordSum].createdAt, new.createdAt);
                strcpy(temp[recordSum].updatedAt, new.updatedAt);
                recordSum++;
            } else {
                // rekaman baru memiliki posisi di tengah
                int i = 0;
                bool isStop = false;
                // cari posisi
                while((i < recordSum) && (!isStop)){
                    if(strcmp(temp[i].id, new.id) == 0){
                        error(7);
                        isDuplicate = true;
                        isStop = true;
                    } else if (strcmp(temp[i].id, new.id) > 0){
                        isStop = true;
                    } else {
                        i++;
                    }
                }
                if(!isDuplicate){
                    for(int j = recordSum - 1; j >= i; j--){
                        strcpy(temp[j+1].id, temp[j].id);
                        strcpy(temp[j+1].name, temp[j].name);
                        strcpy(temp[j+1].createdAt, temp[j].createdAt);
                        strcpy(temp[j+1].updatedAt, temp[j].updatedAt);
                    }
                    strcpy(temp[i].id, new.id);
                    strcpy(temp[i].name, new.name);
                    strcpy(temp[i].createdAt, new.createdAt);
                    strcpy(temp[i].updatedAt, new.updatedAt);
                    recordSum++;
                }
            }
            if(!isDuplicate){
                // flush ke file
                categoryTable = fopen("tables/tcategory.dat", "w");
                for(int i = 0; i < recordSum; i++){
                    fprintf(categoryTable, "%s %s %s %s\n", temp[i].id, temp[i].name, temp[i].createdAt, temp[i].updatedAt);
                }
                fprintf(categoryTable, "XXXXXXXX XXX XXXXX XXXXX");
                fclose(categoryTable);
                
                printf("memasukkan data selesai\n");
            }
        } else {
            error(6);
        }
    } else {
        error(4);
    }
}