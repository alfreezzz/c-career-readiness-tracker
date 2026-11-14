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

void guideTitle(){
    printf(BWHITE"                                  ╔═══*.·:·.☽✧    ✦✦    ✧☾.·:·.*═══╗                                  \n");
    printf(BYELLOW"⋆"CYAN"﹥━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"BWHITE"║         " BGREEN "* guide book *" BWHITE "         ║"CYAN"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━﹤"BYELLOW"⋆\n" CYAN);
    printf("∨                                 "BWHITE"╚═══*.·:·.☽✧    ✦✦    ✧☾.·:·.*═══╝"CYAN"                                 ∨\n");
}

void guideNotes(){
    printf("|   "BRED"CATATAN PENTING!!"CYAN"                                                                                |\n");
    printf("|   "BYELLOW"1."WHITE" SELALU AKHIRI PERINTAH DENGAN TANDA DOLLAR ("YELLOW"$"WHITE")"CYAN"                                                |\n");
    printf("|   "BYELLOW"2."WHITE" Jika argumen berisi lebih dari satu kata, maka gunakanlah penulisan tanpa spasi dengan"CYAN"        |\n");
    printf("|      "WHITE"format camel case ("BLACK"cth."WHITE" "BLUE"WebDeveloper"WHITE")"CYAN"                                                         |\n");
    printf("|   "BYELLOW"3."WHITE" Tidak perlu menambahkan argumen untuk mengisi data "BLACK"tanggal_dibuat"WHITE" dan data "BLACK"tanggal_diubah"CYAN"     |\n");
    printf("|   "BYELLOW"4."WHITE" Jika ingin menambahkan data yang berasal dari tabel lain, pastikan bahwa "BLUE"ID"WHITE" tersebut ada"CYAN"      |\n");
    printf("|      "WHITE"di dalam tabel yang bersangkutan"CYAN"                                                              |\n");
    printf("|                                                                                                    |\n");
    printf("∧                                                                                                    ∧\n");
    printf(BYELLOW"⋆"CYAN"﹥━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━﹤"BYELLOW"⋆\n" DEFAULT);
}

void guide(){
    guideTitle();

    printf("|                                                                                                    |\n");
    printf("|   "BLUE"DBMS ini digunakan untuk mencatat data terkait target pekerjaan dan kesiapan kondisi saat ini"CYAN"    |\n");
    printf("|   "BLUE"untuk mencapai target tersebut"CYAN"                                                                   |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"1. Daftar Perintah"CYAN"                                                                               |\n");
    printf("|      - "BPURPLE"SUBMIT TO"CYAN"      : "BWHITE"Menambahkan"CYAN" data                                                           |\n");
    printf("|      - "BPURPLE"CHANGE"CYAN"         : "BWHITE"Mengubah"CYAN" data                                                              |\n");
    printf("|      - "BPURPLE"REMOVE FROM"CYAN"    : "BWHITE"Menghapus"CYAN" data                                                             |\n");
    printf("|      - "BPURPLE"PRESENT FROM"CYAN"   : "BWHITE"Menampilkan"CYAN" data                                                           |\n");
    printf("|      - "BPURPLE"HELP"CYAN"           : Membuka Guide Book                                                         |\n");
    printf("|      - "BPURPLE"HELP ON"CYAN"        : Membuka Guide Book berdasarkan tabel                                       |\n");
    printf("|      - "BPURPLE"EXIT"CYAN"           : "RED"Mengakhiri aplikasi"CYAN"                                                        |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"2. Master Data"CYAN"                                                                                   |\n");
    printf("|      - "BYELLOW"Posisi"CYAN"         : "BLUE"tposition"CYAN"     (id, nama, tanggal_dibuat, tanggal_diubah)                   |\n");
    printf("|      - "BYELLOW"Keahlian"CYAN"       : "BLUE"tskill"CYAN"        (id, nama, kecakapan, tanggal_dibuat, tanggal_diubah)        |\n");
    printf("|      - "BYELLOW"Target"CYAN"         : "BLUE"ttarget"CYAN"       (id, id_posisi, id_skill, sudah_dikuasai, tanggal_dibuat,"CYAN"    |\n");
    printf("|                                        tanggal_diubah)                                             |\n");
    printf("|      - "BYELLOW"Organisasi"CYAN"     : "BLUE"torganization"CYAN" (id, nama, tanggal_dibuat, tanggal_diubah)                   |\n");
    printf("|      - "BYELLOW"Sertifikasi"CYAN"    : "BLUE"tcertificate"CYAN"  (id, nama, id_organisasi, tanggal_dimulai, tanggal_berakhir,"CYAN" |\n");
    printf("|                                        kredensial, url, tanggal_dibuat, tanggal_diubah)            |\n");
    printf("|      - "BYELLOW"Pengalaman"CYAN"     : "BLUE"texperience"CYAN"   (id, id_organisasi, id_posisi, tanggal_dimulai,"CYAN"              |\n");
    printf("|                                        tanggal_berakhir, tanggal_dibuat, tanggal_diubah)           |\n");
    printf("|      - "BYELLOW"Kategori"CYAN"       : "BLUE"tcategory"CYAN"     (id, nama, tanggal_dibuat, tanggal_diubah)                   |\n");
    printf("|      - "BYELLOW"Proyek"CYAN"         : "BLUE"tproject"CYAN"      (id, nama, url, tanggal_selesai, id_kategori,"CYAN"                |\n");
    printf("|                                        tanggal_dibuat, tanggal_diubah)                             |\n");
    printf("|      "WHITE"Untuk informasi lebih lanjut terkait bagaimana cara menampilkan, menambahkan, mengubah, atau"CYAN"  |\n");
    printf("|      "WHITE"menghapus data, silakan gunakan perintah "CYAN"\""BPURPLE"HELP ON"CYAN"\" "WHITE"dilanjutkan dengan nama tabel,"CYAN"             |\n");
    printf("|      "BLACK"cth. "BPURPLE"HELP ON "BLUE"tposition"YELLOW"$"CYAN"                                                                       |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"3. Format ID "CYAN"(bisa disesuaikan "BRED"ASALKAN KONSISTEN"CYAN")                                                |\n");
    printf("|      - "BYELLOW"Posisi"CYAN"         : "WHITE"POS"CYAN"-(Nomor ID)    "BLACK"cth. "WHITE"POS001"CYAN"                                              |\n");
    printf("|      - "BYELLOW"Keahlian"CYAN"       : "WHITE"SKL"CYAN"-(Nomor ID)    "BLACK"cth. "WHITE"SKL001"CYAN"                                              |\n");
    printf("|      - "BYELLOW"Target"CYAN"         : "WHITE"TAR"CYAN"-(Nomor ID)    "BLACK"cth. "WHITE"TAR001"CYAN"                                              |\n");
    printf("|      - "BYELLOW"Organisasi"CYAN"     : "WHITE"ORG"CYAN"-(Nomor ID)    "BLACK"cth. "WHITE"ORG001"CYAN"                                              |\n");
    printf("|      - "BYELLOW"Sertifikasi"CYAN"    : "WHITE"CER"CYAN"-(Nomor ID)    "BLACK"cth. "WHITE"CER001"CYAN"                                              |\n");
    printf("|      - "BYELLOW"Pengalaman"CYAN"     : "WHITE"EXP"CYAN"-(Nomor ID)    "BLACK"cth. "WHITE"EXP001"CYAN"                                              |\n");
    printf("|      - "BYELLOW"Kategori"CYAN"       : "WHITE"CAT"CYAN"-(Nomor ID)    "BLACK"cth. "WHITE"CAT001"CYAN"                                              |\n");
    printf("|      - "BYELLOW"Proyek"CYAN"         : "WHITE"PRJ"CYAN"-(Nomor ID)    "BLACK"cth. "WHITE"PRJ001"CYAN"                                              |\n");
    printf("|                                                                                                    |\n");

    guideNotes();
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
    printf("\n" BPURPLE);
    printf("         _ _  ______                                                                  _ _              \n");
    printf("        ( | ) |  ___|                                                                ( | )             \n");
    printf("         V V  | |_ ___   ___ _   _ ___    ___  _ __     ___ __ _ _ __ ___  ___ _ __   V V              \n");
    printf("              |  _/ _ \\ / __| | | / __|  / _ \\| '_ \\   / __/ _` | '__/ _ \\/ _ \\ '__|              \n");
    printf("              | || (_) | (__| |_| \\__ \\ | (_) | | | | | (_| (_| | | |  __/  __/ |_                   \n");
    printf("              \\_| \\___/ \\___|\\__,_|___/  \\___/|_| |_|  \\___\\__,_|_|  \\___|\\___|_( )           \n");
    printf("                                                                                |/                     \n");
    printf("                                                                                                   v1.0\n");
    printf("=======================================================================================================\n" DEFAULT);
    printf("\n");

    guide();
    printf("\n");
}

void out(){
    printf(RED"                                           &     &                                                                                \n");
    printf("                        &#   &&   &#       #&    &    &                                                                           \n");
    printf("                        #GP5YJJJJ5GB       &BP5YYYYY5B#                                                                           \n");
    printf("                       B"BWHITE"7:^7?J5#P^:~"RED"P&   &#"BWHITE"?:^7?J5BP~:"RED"~P                                                                          \n");
    printf("                     &5"BWHITE"::::"BBLACK"      "BWHITE"::::?"RED"#  P"BWHITE"::::"BBLACK"      "BWHITE":::"RED"7#          "BRED"_           _       _        __     __                        \n"RED);
    printf("                     G"BWHITE"::::"BBLACK"        "BWHITE":::::"RED"BB"BWHITE"^:::"BBLACK"        "BWHITE"::::"RED"J#        "BRED"| |         | |     | |       \\ \\   / /                        \n"RED);
    printf("                     P"BWHITE":::::"BBLACK"      "BWHITE"::::::"RED"#G"BWHITE":::::"BBLACK"      "BWHITE":::::"RED"~#        "BRED"| |     __ _| | __ _| | __ _   \\ \\_/ /__ _   _  ___ _   _  ___ \n"RED);
    printf("                     B"BWHITE"::::::::::::::::"RED"5BB"BWHITE"^:::::::::::::::"RED"J         "BRED"| |    / _` | |/ _` | |/ _` |   \\   / _ \\ | | |/ _ \\ | | |/ _ \\\n");
    printf("                     &"RED"P"BWHITE"^:::::::::::::"RED"JBPGP"BWHITE"^:::::::::::::"RED"?#"BRED"#&       | |___| (_| | | (_| | | (_| |    | |  __/ |_| |  __/ |_| |  __/\n");
    printf("                   &#B"RED"BG"BWHITE"?~^^^^^^:^^"RED"75GPPPGGJ"BWHITE"~^^^^^^^^^"RED"75GGGB#"BRED"&&    |______\\__,_|_|\\__,_|_|\\__,_|    |_|\\___|\\__, |\\___|\\__, |\\___|\n");
    printf("                &##"RED"BGPPPGGPYJ??JY5GGPPPPPPPGGPYJ??JY5GGPPPPPGGB"BRED"#&                                            __/ |      __/ |     \n");
    printf("              &#"RED"BGPPPPPPPPPGGGGGGGPPPPPPPPPPPGGGGGGGGPPPPPPPPPPGB"BRED"#&                                         |___/      |___/      \n");
    printf("            ##"RED"BGPPP5P5Y5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPY5P5PPPGB"BRED"##           \n");
    printf("           #"RED"BBPPPPP5555PG&         "BWHITE"#~:^:~:::^G"RED"           &G5Y5PPPPPGB"BRED"B&         \n");
    printf("         &##"RED"GPPPPPPP5PPPP&         "BWHITE"&~^:^~::^:B"RED"          #GPP5PPPPPPPPB"BRED"B#        \n");
    printf("        &#"RED"BPPPPPPPPPPPPPP#          "BWHITE"#P5G B5PB"RED"         #GPPPPPPPPPPPPPPB"BRED"#&       \n");
    printf("       &#"RED"BPPPPPPPPPPPPPPPB                          &GPPPPPPPPPPPPPPPPP"BRED"B#B&&&   \n");
    printf(" #&&&&#B#GG"RED"PPPPPPPPPPPPPPP&                       &GPPPPPPPPPPPPPPPPGG"BRED"BBBB"RED"GBB"BRED"B#&\n");
    printf(" #G"RED"PPP"BRED"GGGG"RED"BBBGPPPPPPPPPPPPG    "BRED"&&&#######&"RED"     &#GPPPPPPPPPPPPPPPP"BRED"BBBGG"RED"PPPPPPP"BRED"#&\n");
    printf(" #B"RED"PPPPPPPPP"BRED"GGG"RED"PPPPPPPPPPPPB&"BRED"##BBBBBBBBBBB#&"RED" &BGPPPPPPPPPPPPPPPPPPGPPPPPPPPPP"BRED"BB \n");
    printf(" &&#GP"RED"PPPPPPPPPPPPPPPPPPPPPP"RED"G"BRED"BBBBBBBBBBBBBB"RED"GGPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"BRED"G#   \n");
    printf("    #B"RED"PPPPPPPPPPPPPPPPPP"BRED"GGGGG"RED"G"BRED"BBBBBBBBBBB"RED"GG"BRED"GGGGGG"RED"PPPPPPPPPPPPPPPPPPPPPPPPG#"BRED"#&   \n");
    printf("     G#"RED"GPPPPPPPPPPPPPP"BRED"GGGGGGGG"RED"GBBBBBBBBBG"BRED"GBGGGGGGGG"RED"PPPPPPPPPPPPPPPPPPPPPPG"BRED"#&    \n");
    printf("     G#"RED"PPPPPPPPPPPPPPP"BRED"GGGGGGGGGP5PPPPP5YYJPGGGGGGGG"RED"PPPPPPPPPPPPPPPPPPPPPPP"BRED"#&    \n");
    printf("     ##"RED"PPPPPPPPPPPPPPPPPP"BRED"GGGGGGJ???YYYJ???5GGGGGG"RED"PPPPPPPPPPPPPPPPPPPPPPPPP"BRED"##    \n");
    printf("     B#"RED"GPPPPPPPPPPPPPPPPPPPPPP"BRED"G5JY5"RED"PPPPPP5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"BRED"##    \n");
    printf("     ##"RED"GPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPG"BRED"##    \n");
    printf("     ##"RED"GPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"BRED"##     \n");
    printf("     &#"RED"BPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPG"BRED"##     \n");
    printf("      B#"RED"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"BRED"##      \n");
    printf("      ##"RED"GPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPG"BRED"##      \n");
    printf("      &#"RED"BPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"BRED"##      \n");
    printf("       ##"RED"GPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPG"BRED"##     \n");
    printf("        #B"RED"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPB"BRED"#&   \n");
    printf("        #B"RED"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"BRED"G#    \n");
    printf("       &#"RED"GPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGG"BRED"##    \n");
    printf("       &#"RED"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGGGBB"BRED"##&      \n");
    printf("      &#"RED"GPPPPPPPPPPPPPPPPPPPPPPPPGGBBB"BRED"######BBBBBBBBBBBBBBBBB#B###&&&&&         \n");
    printf("      ##"RED"PPPPPPPPPPPPPPPPPGGG"BRED"BB###&&&&&                                          \n");
    printf("      &#"RED"GPPPPPPPPGGGG"BRED"BB###&&&                                                   \n");
    printf("       "BRED"&#BBBBBBB#B#&&&                                                          \n"DEFAULT);
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