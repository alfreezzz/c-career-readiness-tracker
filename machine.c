// Saya Alfriza sebagai manusia yang berTuhan, saya mengerjakan evaluasi 
// Tugas Masa Depan dalam mata kuliah Dasar-dasar Pemrograman untuk 
// keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah 
// dispesifikasikan. Aamiin.

#include "header.h" // memanggil file header

int indeks, wordLen;    // indeks kata dan panjang kata
char cw[50];            // kata saat ini

// formatting
// https://www.w3schools.com/c/c_date_time.php
void timeStamp(char buffer[]){  // mengambil waktu saat ini
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(buffer, 100, "%Y-%m-%dT%H:%M:%S", t);
}

void guideTitle(){  // header buku panduan
    printf(BWHITE"                                  ╔═══*.·:·.☽✧    ✦✦    ✧☾.·:·.*═══╗                                  \n");
    printf(BYELLOW"⋆"CYAN"﹥━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"BWHITE"║         " BGREEN "* guide book *" BWHITE "         ║"CYAN"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━﹤"BYELLOW"⋆\n" CYAN);
    printf("∨                                 "BWHITE"╚═══*.·:·.☽✧    ✦✦    ✧☾.·:·.*═══╝"CYAN"                                 ∨\n");
}
void guideFooter(){ // footer buku panduan
    printf("|   "BRED"CATATAN PENTING!!"CYAN"                                                                                |\n");
    printf("|   "BYELLOW"1."WHITE" SELALU AKHIRI PERINTAH DENGAN TANDA DOLLAR ("YELLOW"$"WHITE")"CYAN"                                                |\n");
    printf("|   "BYELLOW"2."WHITE" Jika argumen berisi lebih dari satu kata, maka gunakanlah penulisan tanpa spasi dengan"CYAN"        |\n");
    printf("|      "WHITE"format camel case atau snake case ("BLACK"cth."WHITE" "BLUE"WebDeveloper"WHITE" atau "BLUE"Web_developer"WHITE")"CYAN"                      |\n");
    printf("|   "BYELLOW"3."WHITE" Tidak perlu menambahkan argumen untuk mengisi data "BLACK"tanggal_dibuat"WHITE" dan data "BLACK"tanggal_diubah"CYAN"     |\n");
    printf("|   "BYELLOW"4."WHITE" Jika ingin menambahkan data yang berasal dari tabel lain, pastikan bahwa "BLUE"ID"WHITE" tersebut ada"CYAN"      |\n");
    printf("|      "WHITE"di dalam tabel yang bersangkutan"CYAN"                                                              |\n");
    printf("|                                                                                                    |\n");
    printf("∧                                                                                                    ∧\n");
    printf(BYELLOW"⋆"CYAN"﹥━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━﹤"BYELLOW"⋆\n" DEFAULT);
}
void guide(){       // buku panduan
    guideTitle();

    printf("|                                                                                                    |\n");
    printf("|   "WHITE"DBMS ini digunakan untuk mencatat data terkait target pekerjaan dan kesiapan kondisi saat ini"CYAN"    |\n");
    printf("|   "WHITE"untuk mencapai target tersebut"CYAN"                                                                   |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"1. Daftar Perintah"CYAN"                                                                               |\n");
    printf("|      - "BPURPLE"SUBMIT TO"CYAN"                   : "BWHITE"Menambahkan"CYAN" data                                              |\n");
    printf("|      - "BPURPLE"CHANGE"CYAN"                      : "BWHITE"Mengubah"CYAN" data                                                 |\n");
    printf("|      - "BPURPLE"REMOVE FROM"CYAN"                 : "BWHITE"Menghapus"CYAN" data                                                |\n");
    printf("|      - "BPURPLE"PRESENT FROM"CYAN"                : "BWHITE"Menampilkan"CYAN" data                                              |\n");
    printf("|      - "BPURPLE"PRESENT FROM table WHERE"CYAN"    : "BWHITE"Mencari"CYAN" data                                                  |\n");
    printf("|      - "BPURPLE"HELP"CYAN"                        : Membuka Guide Book                                            |\n");
    printf("|      - "BPURPLE"HELP ON"CYAN"                     : Membuka Guide Book berdasarkan tabel                          |\n");
    printf("|      - "BPURPLE"EXIT"CYAN"                        : "RED"Mengakhiri aplikasi"CYAN"                                           |\n");
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

    guideFooter();
}
void in(){          // tampilan awal
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
void out(){         // tampilan akhir
    printf(RED"                                           &     &                                                                                \n");
    printf("                        &#   &&   &#       #&    &    &                                                                           \n");
    printf("                        #GP5YJJJJ5GB       &BP5YYYYY5B#                                                                           \n");
    printf("                       B"BWHITE"7:^7?J5#P^:~"RED"P&   &#"BWHITE"?:^7?J5BP~:"RED"~P                                                                          \n");
    printf("                     &5"BWHITE"B5GP"BBLACK"      "BWHITE"PG5B?"RED"#  P"BWHITE"B5GP"BBLACK"      "BWHITE"G5B"RED"7#           "BRED"_           _       _        __     __                        \n"RED);
    printf("                     G"BWHITE"PG5B"BBLACK"        "BWHITE"B5GP#"RED"BB"BWHITE"^G5B"BBLACK"        "BWHITE"B5GP"RED"J#        "BRED"| |         | |     | |       \\ \\   / /                        \n"RED);
    printf("                     P"BWHITE"BPBG5"BBLACK"      "BWHITE"5GBPBG"RED"#G"BWHITE"BPBG5"BBLACK"      "BWHITE"5GBPB"RED"~#        "BRED"| |     __ _| | __ _| | __ _   \\ \\_/ /__ _   _  ___ _   _  ___ \n"RED);
    printf("                     B"BWHITE"#P5BP&P5BPGBP5#P"RED"5BB"BWHITE"^P5BP&P5BPGBP5#P"RED"J         "BRED"| |    / _` | |/ _` | |/ _` |   \\   / _ \\ | | |/ _ \\ | | |/ _ \\\n");
    printf("                     &"RED"P"BWHITE"^GP#P5BP&P5BPG"RED"JBPGP"BWHITE"^GP#P5BP&P5BPG"RED"?#"BRED"#&       | |___| (_| | | (_| | | (_| |    | |  __/ |_| |  __/ |_| |  __/\n");
    printf("                   &#B"RED"BG&"BWHITE"GP5B#P5BGB"RED"75GPPPGGJ"BWHITE"~P5B#P5BGB"RED"75GGGB#"BRED"&&    |______\\__,_|_|\\__,_|_|\\__,_|    |_|\\___|\\__, |\\___|\\__, |\\___|\n");
    printf("                &##"RED"BGPPPGGPYJ??JY5GGPPPPPPPGGPYJ??JY5GGPPPPPGGB"BRED"#&                                            __/ |      __/ |     \n");
    printf("              &#"RED"BGPPPPPPPPPGGGGGGGPPPPPPPPPPPGGGGGGGGPPPPPPPPPPGB"BRED"#&                                         |___/      |___/      \n");
    printf("            ##"RED"BGPPP"BRED"5P5Y5"RED"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP"BRED"Y5P5"RED"PPPGB"BRED"##           \n");
    printf("           #"RED"BBPPPPP"BRED"5555"RED"PG&         "BWHITE"#P5BP&P5BPG"RED"           &G"BRED"5Y5"RED"PPPPPGB"BRED"B&         \n");
    printf("         &##"RED"GPPPPPPP"BRED"5"RED"PPPP&         "BWHITE"&GP5B#P5BGB"RED"          #GPP"BRED"5"RED"PPPPPPPPB"BRED"B#        \n");
    printf("        &#"RED"BPPPPPPPPPPPPPP#          "BWHITE"#P5G B5PB"RED"         #GPPPPPPPPPPPPPPB"BRED"#&       \n");
    printf("       &#"RED"BPPPPPPPPPPPPPPPB                          &GPPPPPPPPPPPPPPPPP"BRED"B#B&&&   \n");
    printf(" #&&&&#B#GG"RED"PPPPPPPPPPPPPPP&                       &GPPPPPPPPPPPPPPPPGG"BRED"BBBB"RED"GBB"BRED"B#&\n");
    printf(" #G"RED"PPPGGGG"BRED"BBBG"RED"PPPPPPPPPPPPG    "BRED"&&&#######&"RED"     &#GPPPPPPPPPPPPPPPP"BRED"BBBGG"RED"PPPPPPP"BRED"#&\n");
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

// response
void success(int code){ // pesan berhasil
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
            printf(GREEN "Berhasil\n" DEFAULT);
            break;
        }
    }
}
void error(int code){   // pesan error
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
        case 15: {
            printf(RED "masukkan id yang akan dicari woy\n" DEFAULT);
            break;    
        }
        case 16: {
            printf(RED "melebihi ukuran data woy\n" DEFAULT);
            break;    
        }
        default: {
            printf(RED "itu query apaan woy\n" DEFAULT);
            break;
        }
    }
}

// mesin kata
int eop(char ribbon[]){     // mengecek eop
    if(ribbon[indeks] == EOP){
        return 1;
    } else {
        return 0;
    }
}
void start(char ribbon[]){  // memulai mesin kata
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
void reset(){               // mengosongkan kata saat ini
    wordLen = 0;
    cw[wordLen] = '\0';
}
void inc(char ribbon[]){    // memajukan kata
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
char* getcw(){              // mengambil kata saat ini
    return cw;
}
int getwlen(){              // mengambil panjang kata saat ini
    return wordLen;
}

// searching
// https://stackoverflow.com/questions/75400003/is-there-a-way-to-make-a-single-function-operate-on-different-structures-having
void binarySearch(void* arr, int n, char* search, bool *found, int *idx, int type){ // mencari data
    int i, j;           // indeks bawah dan atas
    i = 0, j = n - 1;   // mengisi nilai
    char id[10];        // menyimpan id dari tipe bentukan yang digunakan

    // proses pencarian
    while((!(*found)) && (i <= j)){
        *idx = (i + j) / 2; // mengisi nilai tengah dari indeks bawah dan atas

        // menentukan tipe bentukan yang digunakan
        switch(type){
            case 1: {
                strcpy(id, ((position*)arr)[*idx].id);
                break;
            }
            case 2: {
                strcpy(id, ((skill*)arr)[*idx].id);
                break;
            }
            case 3: {
                strcpy(id, ((target*)arr)[*idx].id);
                break;
            }
            case 4: {
                strcpy(id, ((organization*)arr)[*idx].id);
                break;
            }
            case 5: {
                strcpy(id, ((certificate*)arr)[*idx].id);
                break;
            }
            case 6: {
                strcpy(id, ((experience*)arr)[*idx].id);
                break;
            }
            case 7: {
                strcpy(id, ((category*)arr)[*idx].id);
                break;
            }
            case 8: {
                strcpy(id, ((project*)arr)[*idx].id);
                break;
            }
            default: {
                error(1);
                break;
            }
        }

        if(strcmp(id, search) == 0){
            *found = true;
        } else if (strcmp(id, search) > 0){
            j = *idx - 1;   // mengambil indeks tengah ke bawah
        } else {
            i = *idx + 1;   // mengambil indeks tengah ke atas
        }
    }
}

// ui tabel
// https://stackoverflow.com/questions/75400003/is-there-a-way-to-make-a-single-function-operate-on-different-structures-having
int longestName(void* data, int n, int type){
    char name[50];      // menyimpan name dari tipe bentukan yang digunakan
    int lenMaxName = 0; // panjang dari nama terpanjang
    
    for(int i = 0; i < n; i++){
        // menentukan tipe bentukan yang digunakan
        switch(type){
            case 1: {
                strcpy(name, ((position*)data)[i].name);
                break;
            }
            case 2: {
                strcpy(name, ((skill*)data)[i].name);
                break;
            }
            case 4: {
                strcpy(name, ((organization*)data)[i].name);
                break;
            }
            case 5: {
                strcpy(name, ((certificate*)data)[i].name);
                break;
            }
            case 7: {
                strcpy(name, ((category*)data)[i].name);
                break;
            }
            case 8: {
                strcpy(name, ((project*)data)[i].name);
                break;
            }
            default: {
                error(1);
                break;
            }
        }
        // jika lebih kecil maka nilai diperbarui
        if(lenMaxName < strlen(name)){
            lenMaxName = strlen(name);
        }
    }
    return lenMaxName;
}
void showCategoryTable(int lenMaxName, int n, category* data){
    // header table
    printf(WHITE"+--------+-");
    for(int i = 1; i <= lenMaxName || i <= 4; i++){
        printf("-");
    }
    printf("-+---------------------+---------------------+\n");
    printf("| "BWHITE"ID"WHITE"     |");
    printf(" "BWHITE"Nama"WHITE" ");
    for(int i = 1; i <= lenMaxName && i <= lenMaxName - 4; i++){
        printf(" ");
    }
    printf("| "BWHITE"Tanggal_dibuat"WHITE"      | "BWHITE"Tanggal_diubah"WHITE"      |\n");
    printf("+--------+-");
    for(int i = 1; i <= lenMaxName || i <= 4; i++){
        printf("-");
    }
    printf("-+---------------------+---------------------+\n");

    // body table
    for(int i = 0; i < n; i++){
        int lenMaxID = 6;
        // ID
        printf("| %s ", data[i].id);
        if((lenMaxID - strlen(data[i].id)) > 0){
            for(int j = 1; (j <= lenMaxID - strlen(data[i].id)) ; j++){
                printf(" ");
            }
        } else {
            for(int j = 1; j <= 2 - lenMaxID ; j++){
                printf(" ");
            }
        }
        // NAMA
        printf("| %s ", data[i].name);
        if((lenMaxName - strlen(data[i].name)) > 0){
            for(int j = 1; (j <= lenMaxName - strlen(data[i].name)) ; j++){
                printf(" ");
            }
        } else {
            for(int j = 1; j <= 4 - lenMaxName ; j++){
                printf(" ");
            }
        }
        // TANGGAL DIBUAT & DIUBAH
        printf("| %s | %s |\n", data[i].createdAt, data[i].updatedAt);
    }

    // footer table
    printf("+--------+-");
    for(int i = 1; i <= lenMaxName || i <= 4; i++){
        printf("-");
    }
    printf("-+---------------------+---------------------+\n"DEFAULT);
}

// prosedur fungsi perintah tabel kategori
void getCategory(char command[]){       // menampilkan data
    int recordSum = 0;  // jumlah rekaman dalam tabel
    category temp[100]; // array rekaman untuk ditampilkan
    category record;    // rekaman saat ini untuk disalin

    FILE *categoryTable;    // kaitan untuk mengakses file
    categoryTable = fopen("tables/tcategory.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(categoryTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);

    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika ditemukan EOF atau data kosong
        error(12);
        fclose(categoryTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(categoryTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(categoryTable); // menutup file

        if(eop(command) == 1){  // jika tidak melakukan pencarian
            // menampilkan data
            showCategoryTable(longestName(temp, recordSum, 7), recordSum, temp);
        } else {    // jika tidak melakukan pencarian
            inc(command);
            if(strcmp(getcw(), "WHERE") == 0){
                if(eop(command) == 0){
                    inc(command);
                    if(eop(command) == 1){
                        char search[50];
                        strcpy(search, getcw());
                        
                        if(strcmp(search, IDDUMMY) == 0){
                            error(11);
                        } else {
                            int idx;            // indeks dan iterasi
                            bool found = false; // cek ditemukan

                            // proses pencarian
                            binarySearch(temp, recordSum, search, &found, &idx, 7);
                            
                            if(found){  // jika data ditemukan
                                category foundData[1];
                                strcpy(foundData[0].id, temp[idx].id);
                                strcpy(foundData[0].name, temp[idx].name);
                                strcpy(foundData[0].createdAt, temp[idx].createdAt);
                                strcpy(foundData[0].updatedAt, temp[idx].updatedAt);
                                showCategoryTable(strlen(temp[idx].name), 1, foundData);
                            } else {
                                error(11);
                            }
                        }
                    } else {
                        error(14);
                    }
                } else {
                    error(15);
                }
            } else {
                error(0);
            }
        }
    }
}
void postCategory(char command[]){      // menambahkan data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp
    
    int recordSum = 0;      // jumlah rekaman di dalam tabel
    category temp[100];     // array rekaman untuk menggeserkan nilai rekaman baru
    category record, new;   // rekaman saat ini dan rekaman yang baru
    
    FILE *categoryTable;    // kaitan untuk mengakses file
    categoryTable = fopen("tables/tcategory.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(categoryTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);

    // jika tidak ditemukan EOF dan data tidak kosong
    if(strcmp(record.id, IDDUMMY) != 0 && strcmp(record.id, "") != 0){
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(categoryTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
    }
    fclose(categoryTable); // menutup file
    
    inc(command);   
    if(eop(command) == 0){
        if(strlen(getcw()) < sizeof(record.id)){
            strcpy(new.id, getcw());    // mengambil id masukan user
    
            inc(command);
            if(eop(command) == 1){
                if(strlen(getcw()) < sizeof(record.name)){
                    strcpy(new.name, getcw());  // mengambil nama masukan user
        
                    // mengambil tanggal dan waktu saat ini
                    strcpy(new.createdAt, dateTime);
                    strcpy(new.updatedAt, dateTime);
        
                    bool isDuplicate = false;   // cek id duplikat
                    // kondisi memasukkan rekaman baru ke dalam array
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
                        // rekaman baru di paling belakang
                        strcpy(temp[recordSum].id, new.id);
                        strcpy(temp[recordSum].name, new.name);
                        strcpy(temp[recordSum].createdAt, new.createdAt);
                        strcpy(temp[recordSum].updatedAt, new.updatedAt);
                        recordSum++;
                    } else {
                        // rekaman baru memiliki posisi di tengah
                        int i = 0;  // iterasi dan indeks
                        bool isStop = false;    // cek berhenti
                        // cari posisi
                        while((i < recordSum) && (!isStop)){
                            if(strcmp(temp[i].id, new.id) == 0){
                                // terdapat id yang redundan
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
                            // menggeserkan rekaman di posisi tengah
                            for(int j = recordSum - 1; j >= i; j--){
                                strcpy(temp[j+1].id, temp[j].id);
                                strcpy(temp[j+1].name, temp[j].name);
                                strcpy(temp[j+1].createdAt, temp[j].createdAt);
                                strcpy(temp[j+1].updatedAt, temp[j].updatedAt);
                            }
                            // memasukkan rekaman baru di posisi tengah
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
                        fprintf(categoryTable, "%s", EOFCATEGORY);
                        fclose(categoryTable);
                    }
                } else {
                    error(16);
                }
            } else {
                error(6);
            }
        } else {
            error(16);
        }
    } else {
        error(4);
    }
}
void updateCategory(char command[]){    // mengubah data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp

    int recordSum = 0;      // jumlah rekaman di dalam tabel
    category temp[100];     // array rekaman untuk menggeserkan nilai rekaman baru
    category record, new;   // rekaman saat ini dan rekaman yang baru

    FILE *categoryTable;    // kaitan untuk mengakses file
    categoryTable = fopen("tables/tcategory.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(categoryTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(categoryTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(categoryTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
        
        fclose(categoryTable); // menutup file
        
        inc(command);
        char search[50]; // cari nilai id
        strcpy(search, getcw()); // mengambil id masukan user
        
        int i = 0;  // iterasi dan index
        bool isFound = false;   // cek ditemukan
        // proses pencarian
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
                    if(strlen(getcw()) < sizeof(record.name)){
                        strcpy(new.name, getcw());          // mengambil nama masukan user
                        strcpy(new.updatedAt, dateTime);    // mengubah tanggal diubah
        
                        // mengubah menjadi nilai baru
                        strcpy(temp[i].name, new.name);
                        strcpy(temp[i].updatedAt, new.updatedAt);
    
                        success(1);
                    } else {
                        error(16);
                    }
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
        fprintf(categoryTable, "%s", EOFCATEGORY);
        fclose(categoryTable);   
    }
}
void deleteCategory(char command[]){    // menghapus data
    int recordSum = 0;      // jumlah rekaman di dalam tabel
    category temp[100];     // array rekaman untuk menggeserkan nilai rekaman baru
    category record, new;   // rekaman saat ini dan rekaman yang baru

    FILE *categoryTable;    // kaitan untuk mengakses file
    categoryTable = fopen("tables/tcategory.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(categoryTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(categoryTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(categoryTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(categoryTable); // menutup file
        
        inc(command);
        char search[50]; // cari nilai id
        strcpy(search, getcw()); // mengambil id masukan user
        
        if(eop(command) == 1){
            int idx = 0;    // iterasi dan index
            bool isFound = false;   // cek ditemukan
            // proses pencarian 
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
                    // rekaman dihapus di paling depan
                    // geser semua isi array ke belakang
                    for(int i = 0; i < recordSum - 1; i++){
                        strcpy(temp[i].id, temp[i+1].id);
                        strcpy(temp[i].name, temp[i+1].name);
                        strcpy(temp[i].createdAt, temp[i+1].createdAt);
                        strcpy(temp[i].updatedAt, temp[i+1].updatedAt);
                    }
                    recordSum--;
                } else if (idx == recordSum - 1){
                    // rekaman dihapus di paling belakang
                    recordSum--;
                } else {
                    // rekaman dihapus memiliki posisi di tengah
                    int i = 0;  // iterasi dan index
                    bool isStopped = false; // cek ditemukan
                    // cari posisi
                    while((i < recordSum) && !isStopped){
                        if(i >= idx){
                            isStopped = true;
                        } else {
                            i++;
                        }
                    }
                    // menggeserkan rekaman di posisi tengah
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
            categoryTable = fopen("tables/tcategory.dat", "w");
            for(int i = 0; i < recordSum; i++){
                fprintf(categoryTable, "%s %s %s %s\n", temp[i].id, temp[i].name, temp[i].createdAt, temp[i].updatedAt);
            }
            fprintf(categoryTable, "%s", EOFCATEGORY);
            fclose(categoryTable);
        } else {
            error(14);
        }
    }
}
void guideCategory(){                   // buku panduan kategori
    guideTitle();

    printf("|                                                                                                    |\n");
    printf("|   "WHITE"Tabel kategori digunakan untuk menyimpan relasi kategori dalam tabel proyek"CYAN"                      |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"STRUKTUR DATA"CYAN"                                                                                    |\n");
    printf("|      "WHITE"1. id              : "CYAN"Kode unik                                                                |\n");
    printf("|      "WHITE"2. nama            : "CYAN"Nama kategori proyek                                                     |\n");
    printf("|      "WHITE"3. tanggal_dibuat  : "CYAN"waktu data dibuat                                                        |\n");
    printf("|      "WHITE"4. tanggal_diubah  : "CYAN"waktu data diubah                                                        |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"PENGGUNAAN PERINTAH"CYAN"                                                                              |\n");
    printf("|      "WHITE"1. Menampilkan data : "BPURPLE"PRESENT FROM "BLUE"tcategory"YELLOW"$"CYAN"                                                 |\n");
    printf("|      "WHITE"2. Mencari data     : "BPURPLE"PRESENT FROM"BLUE" tcategory "BPURPLE"WHERE"CYAN" id"YELLOW"$"CYAN"                                        |\n");
    printf("|      "WHITE"3. Menambahkan data : "BPURPLE"SUBMIT TO "BLUE"tcategory "CYAN"id nama"YELLOW"$"CYAN"                                            |\n");
    printf("|      "WHITE"4. Mengubah data    : "BPURPLE"CHANGE "BLUE"tcategory "CYAN"id nama"YELLOW"$"CYAN"                                               |\n");
    printf("|      "WHITE"5. Menghapus data   : "BPURPLE"REMOVE FROM "BLUE"tcategory "CYAN"id"YELLOW"$"CYAN"                                               |\n");
    printf("|                                                                                                    |\n");

    guideFooter();
}
