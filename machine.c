// Saya Alfriza sebagai manusia yang berTuhan, saya mengerjakan evaluasi 
// Tugas Masa Depan dalam mata kuliah Dasar-dasar Pemrograman untuk 
// keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah 
// dispesifikasikan. Aamiin.

#include "header.h"

int indeks, wordLen;
char cw[50];

void timeStamp(char buffer[]){
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(buffer, 100, "%Y-%m-%dT%H:%M:%S", t);
}

void guide(){
    printf(CYAN"                                 ╔═══*.·:·.☽✧    ✦✦    ✧☾.·:·.*═══╗                                 \n");
    printf("⋆﹥━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━║         " BYELLOW "* guide book *" CYAN "         ║━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━﹤⋆\n");
    printf("|                                ╚═══*.·:·.☽✧    ✦✦    ✧☾.·:·.*═══╝                                |\n");
    printf("|                                                                                                  |\n");
    printf("|   1.                                                                                             |\n");
    printf("|                                                                                                  |\n");
    printf("⋆﹥━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━﹤⋆\n");
}

void in(){
    printf("\n" CYAN);
    printf("   █████████   ████     ██████                                                                         \n");
    printf("  ███▒▒▒▒▒███ ▒▒███    ███▒▒███                                                                        \n");
    printf(" ▒███    ▒███  ▒███   ▒███ ▒▒▒  ████████   ██████   ██████   █████████  █████████  █████████           \n");
    printf(" ▒███████████  ▒███  ███████   ▒▒███▒▒███ ███▒▒███ ███▒▒███ ▒█▒▒▒▒███  ▒█▒▒▒▒███  ▒█▒▒▒▒███            \n");
    printf(" ▒███▒▒▒▒▒███  ▒███ ▒▒▒███▒     ▒███ ▒▒▒ ▒███████ ▒███████  ▒   ███▒   ▒   ███▒   ▒   ███▒             \n" BLUE);
    printf(" ▒███    ▒███  ▒███   ▒███      ▒███     ▒███▒▒▒  ▒███▒▒▒     ███▒   █   ███▒   █   ███▒   █           \n");
    printf(" █████   █████ █████  █████     █████    ▒▒██████ ▒▒██████   █████████  █████████  █████████  █████████\n");
    printf("▒▒▒▒▒   ▒▒▒▒▒ ▒▒▒▒▒  ▒▒▒▒▒     ▒▒▒▒▒      ▒▒▒▒▒▒   ▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒ \n");
    printf("\n" PURPLE);
    printf("         _ _  ______                                                                  _ _ \n");
    printf("        ( | ) |  ___|                                                                ( | )\n");
    printf("         V V  | |_ ___   ___ _   _ ___    ___  _ __     ___ __ _ _ __ ___  ___ _ __   V V \n");
    printf("              |  _/ _ \\ / __| | | / __|  / _ \\| '_ \\   / __/ _` | '__/ _ \\/ _ \\ '__|      \n");
    printf("              | || (_) | (__| |_| \\__ \\ | (_) | | | | | (_| (_| | | |  __/  __/ |_        \n");
    printf("              \\_| \\___/ \\___|\\__,_|___/  \\___/|_| |_|  \\___\\__,_|_|  \\___|\\___|_( )       \n");
    printf("                                                                                |/        \n");
    printf("                                                                                                   v1.0\n");
    printf("=======================================================================================================\n" DEFAULT);
    printf("\n");

    guide();
}

void success(int code){
    switch(code){
        case 0: {
            printf(GREEN "Data berhasil ditambahkan\n" DEFAULT);
            break;
        }
        case 1: {
            printf(GREEN "Data berhasil diedit\n" DEFAULT);
            break;
        }
        case 2: {
            printf(GREEN "Data berhasil dihapus\n" DEFAULT);
            break;
        }
        default: {
            printf(GREEN "yeyy berhasil\n" DEFAULT);
            break;
        }
    }
}

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
            printf(RED "masukkin eop nya (%c) di akhir perintah woy\n", EOP, DEFAULT);
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
        case 11: {
            printf(RED "data tidak ditemukan woy\n" DEFAULT);
            break;    
        }
        case 12: {
            printf(RED "data kosong woy\n" DEFAULT);
            break;    
        }
        case 13: {
            printf(RED "masukkan nilai yang akan diubah woy\n" DEFAULT);
            break;    
        }
        case 14: {
            printf(RED "melebihi query woy\n" DEFAULT);
            break;    
        }
        default: {
            printf(RED "itu query apaan woy\n" DEFAULT);
            break;
        }
    }
}

int eop(char ribbon[]){
    if(ribbon[indeks] == EOP){
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
    while((ribbon[indeks] != ' ') && (ribbon[indeks] != EOP)){
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
    while((ribbon[indeks] != ' ') && (ribbon[indeks] != EOP)){
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
    char dateTime[100];
    timeStamp(dateTime);
    
    int recordSum = 0;
    category temp[100];
    category record, new;
    
    FILE *categoryTable;
    categoryTable = fopen("tables/tcategory.dat", "r");
    
    fscanf(categoryTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);

    if(strcmp(record.id, "XXXXXXXX") != 0 && strcmp(record.id, "") != 0){
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

            strcpy(new.createdAt, dateTime);
            strcpy(new.updatedAt, dateTime);

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
                success(0);
                // flush ke file
                categoryTable = fopen("tables/tcategory.dat", "w");
                for(int i = 0; i < recordSum; i++){
                    fprintf(categoryTable, "%s %s %s %s\n", temp[i].id, temp[i].name, temp[i].createdAt, temp[i].updatedAt);
                }
                fprintf(categoryTable, "XXXXXXXX XXX XXXXX XXXXX");
                fclose(categoryTable);
            }
        } else {
            error(6);
        }
    } else {
        error(4);
    }
}

void updateCategory(char command[]){
    char dateTime[100];
    timeStamp(dateTime);

    int recordSum = 0;
    category temp[100];
    category record, new;

    FILE *categoryTable;
    categoryTable = fopen("tables/tcategory.dat", "r");

    fscanf(categoryTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, "XXXXXXXX") == 0 || strcmp(record.id, "") == 0){
        error(12);
        fclose(categoryTable);
    } else {
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(categoryTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, "XXXXXXXX") != 0);
        
        fclose(categoryTable);
        
        inc(command);
        char search[50];
        strcpy(search, getcw());
        
        int i = 0;
        bool isFound = false;
        while(!isFound && i < recordSum){
            if(strcmp(temp[i].id, search) == 0){
                isFound = true;
            } else {
                i++;
            }
        }
        
        if(!isFound){
            error(11);
        } else {
            if(eop(command) == 0){
                inc(command);
                if(eop(command) == 1){
                    strcpy(new.name, getcw());
                    strcpy(new.updatedAt, dateTime);
    
                    strcpy(temp[i].name, new.name);
                    strcpy(temp[i].updatedAt, new.updatedAt);

                    success(1);
                } else {
                    error(6);
                }
            } else {
                error(13);
            }
        }
        
        // flush ke file
        categoryTable = fopen("tables/tcategory.dat", "w");
        for(int i = 0; i < recordSum; i++){
            fprintf(categoryTable, "%s %s %s %s\n", temp[i].id, temp[i].name, temp[i].createdAt, temp[i].updatedAt);
        }
        fprintf(categoryTable, "XXXXXXXX XXX XXXXX XXXXX");
        fclose(categoryTable);   
    }
}

void deleteCategory(char command[]){
    int recordSum = 0;
    category temp[100];
    category record, new;

    FILE *tableCategory;
    tableCategory = fopen("tables/tcategory.dat", "r");

    fscanf(tableCategory, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, "XXXXXXXX") == 0 || strcmp(record.id, "") == 0){
        error(12);
        fclose(tableCategory);
    } else {
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(tableCategory, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, "XXXXXXXX") != 0);

        fclose(tableCategory);
        
        inc(command);
        char search[50];
        strcpy(search, getcw());
        
        if(eop(command) == 1){
            int idx = 0;
            bool isFound = false;
            while(!isFound && idx < recordSum){
                if(strcmp(temp[idx].id, search) == 0){
                    isFound = true;
                } else {
                    idx++;
                }
            }
            
            if(!isFound){
                error(11);
            } else {
                // kondisi memasukkan ke dalam array
                if(idx == 0){
                    // rekaman baru di paling depan
                    // geser semua isi array ke belakang
                    for(int i = 0; i < recordSum - 1; i++){
                        strcpy(temp[i].id, temp[i+1].id);
                        strcpy(temp[i].name, temp[i+1].name);
                        strcpy(temp[i].createdAt, temp[i+1].createdAt);
                        strcpy(temp[i].updatedAt, temp[i+1].updatedAt);
                    }
                    recordSum--;
                } else if (idx == recordSum - 1){
                    // rekaman baru di belakang
                    recordSum--;
                } else {
                    // rekaman baru memiliki posisi di tengah
                    int i = 0;
                    bool isStopped = false;
                    // cari posisi
                    while((i < recordSum) && !isStopped){
                        if(i >= idx){
                            isStopped = true;
                        } else {
                            i++;
                        }
                    }
                    for(int j = i; j < recordSum - 1; j++){
                        strcpy(temp[j].id, temp[j+1].id);
                        strcpy(temp[j].name, temp[j+1].name);
                        strcpy(temp[j].createdAt, temp[j+1].createdAt);
                        strcpy(temp[j].updatedAt, temp[j+1].updatedAt);
                    }
                    recordSum--;
                }
                success(2);
            }
    
            // flush ke file
            tableCategory = fopen("tables/tcategory.dat", "w");
            for(int i = 0; i < recordSum; i++){
                fprintf(tableCategory, "%s %s %s %s\n", temp[i].id, temp[i].name, temp[i].createdAt, temp[i].updatedAt);
            }
            fprintf(tableCategory, "XXXXXXXX XXX XXXXX XXXXX");
            fclose(tableCategory);
        } else {
            error(14);
        }
    }
}