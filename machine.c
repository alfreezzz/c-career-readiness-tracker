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

// ui aplikasi
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
    printf("|      - "BPURPLE"JOIN ON"CYAN"                     : "BWHITE"Menggabungkan"CYAN" tabel                                           |\n");
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
    printf(" #B"RED"PPPPPPPPP"BRED"GGG"RED"PPPPPPPPPPPPB&"BRED"##BBBBBBBBBBB#&"RED" &BGPPPPPPPPPPPPPPPPPP"BRED"G"RED"PPPPPPPPPP"BRED"BB \n");
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
            printf(GREEN "Data berhasil diubah\n" DEFAULT);
            break;
        }
        case 2: {
            printf(GREEN "Data berhasil dihapus\n" DEFAULT);
            break;
        }
        default: {
            printf(GREEN "Berhasil hore\n" DEFAULT);
            break;
        }
    }
}
void error(int code){   // pesan error
    switch(code){
        case 0: {
            printf(RED "Query tidak valid\n" DEFAULT);
            break;
        }
        case 1: {
            printf(RED "Tabel tersebut tidak valid, daftar tabel yang tersedia:\n" DEFAULT);
            printf(RED "1. tposition\n" DEFAULT);
            printf(RED "2. tskill\n" DEFAULT);
            printf(RED "3. ttarget\n" DEFAULT);
            printf(RED "4. torganization\n" DEFAULT);
            printf(RED "5. tcertificate\n" DEFAULT);
            printf(RED "6. texperience\n" DEFAULT);
            printf(RED "7. tcategory\n" DEFAULT);
            printf(RED "8. tproject\n" DEFAULT);
            break;
        }
        case 2: {
            printf(RED "Mohon masukkan EOP (%c) pada akhir perintah\n", EOP, DEFAULT);
            break;
        }
        case 3: {
            printf(RED "Nama tabel kosong, daftar tabel yang tersedia:\n" DEFAULT);
            printf(RED "1. tposition\n" DEFAULT);
            printf(RED "2. tskill\n" DEFAULT);
            printf(RED "3. ttarget\n" DEFAULT);
            printf(RED "4. torganization\n" DEFAULT);
            printf(RED "5. tcertificate\n" DEFAULT);
            printf(RED "6. texperience\n" DEFAULT);
            printf(RED "7. tcategory\n" DEFAULT);
            printf(RED "8. tproject\n" DEFAULT);
            break;
        }
        case 4: {
            printf(RED "Data yang dibutuhkan tabel kurang lengkap\n" DEFAULT);
            break;    
        }
        case 5: {
            printf(RED "Mohon masukkan data untuk tabel\n" DEFAULT);
            break;    
        }
        case 6: {
            printf(RED "Data yang dimasukkan melebihi jumlah data yang dibutuhkan tabel\n" DEFAULT);
            break;    
        }
        case 7: {
            printf(RED "Tidak boleh ada data dengan ID yang sama\n" DEFAULT);
            break;    
        }
        case 8: {
            printf(RED "Mohon masukkan ID untuk data yang akan diubah\n" DEFAULT);
            break;    
        }
        case 9: {
            printf(RED "Mohon masukkan ID untuk data yang akan dihapus\n" DEFAULT);
            break;    
        }
        case 10: {
            printf(RED "Query kurang lengkap, mohon masukkan query yang valid\n" DEFAULT);
            break;    
        }
        case 11: {
            printf(RED "Data tidak ditemukan\n" DEFAULT);
            break;    
        }
        case 12: {
            printf(RED "Tabel tidak ada datanya\n" DEFAULT);
            break;    
        }
        case 13: {
            printf(RED "Mohon masukkan nilai yang akan diubah\n" DEFAULT);
            break;    
        }
        case 14: {
            printf(RED "Query melebihi yang seharusnya, mohon masukkan query yang valid\n" DEFAULT);
            break;    
        }
        case 15: {
            printf(RED "Mohon masukkan ID dari data yang akan dicari\n" DEFAULT);
            break;    
        }
        case 16: {
            printf(RED "Data yang dimasukkan melebihi batas ukuran\n" DEFAULT);
            break;    
        }
        case 17: {
            printf(RED "Query tidak valid\n" DEFAULT);
            printf(RED "Mungkin maksud anda \"SUBMIT TO..\"?\n" DEFAULT);
            break;    
        }
        case 18: {
            printf(RED "Query tidak valid\n" DEFAULT);
            printf(RED "Mungkin maksud anda \"REMOVE FROM..\"?\n" DEFAULT);
            break;    
        }
        case 19: {
            printf(RED "Query tidak valid\n" DEFAULT);
            printf(RED "Mungkin maksud anda \"PRESENT FROM..\"?\n" DEFAULT);
            break;    
        }
        case 20: {
            printf(RED "Query tidak valid\n" DEFAULT);
            printf(RED "Mungkin maksud anda \"HELP ON..\"?\n" DEFAULT);
            break;    
        }
        case 21: {
            printf(RED "Query tidak valid\n" DEFAULT);
            printf(RED "Mungkin maksud anda \"PRESENT FROM table WHERE..\"?\n" DEFAULT);
            break;    
        }
        case 22: {
            printf(RED "Tabel relasi tidak memiliki data\n" DEFAULT);
            break;    
        }
        case 23: {
            printf(RED "ID relasi tidak ditemukan\n" DEFAULT);
            break;    
        }
        case 24: {
            printf(RED "Data memiliki relasi dengan tabel lain\n" DEFAULT);
            break;    
        }
        case 25: {
            printf(RED "Query tidak valid\n" DEFAULT);
            printf(RED "Mungkin maksud anda \"JOIN ON..\"?\n" DEFAULT);
            break;    
        }
        case 26: {
            printf(RED "Relasi tabel tersebut tidak valid\n" DEFAULT);
            printf(RED "Daftar relasi: (urutan tidak penting)\n" DEFAULT);
            printf(RED "- tposition tskill ttarget\n" DEFAULT);
            printf(RED "- torganization tcertificate\n" DEFAULT);
            printf(RED "- torganization tposition texperience\n" DEFAULT);
            printf(RED "- tcategory tproject\n" DEFAULT);
            break;    
        }
        case 27: {
            printf(RED "Error: ada data yang memiliki relasi yang tidak valid\n" DEFAULT);
            break;    
        }
        case 28: {
            printf(RED "Mohon masukkan tabel yang memiliki relasi dengan tabel tersebut\n" DEFAULT);
            printf(RED "Daftar relasi: (urutan tidak penting)\n" DEFAULT);
            printf(RED "- tposition tskill ttarget\n" DEFAULT);
            printf(RED "- torganization tcertificate\n" DEFAULT);
            printf(RED "- torganization tposition texperience\n" DEFAULT);
            printf(RED "- tcategory tproject\n" DEFAULT);
            break;    
        }
        default: {
            printf(RED "Bug belum diperbaiki\n" DEFAULT);
            break;
        }
    }
}

// mesin kata
bool eop(char ribbon[]){    // mengecek eop
    if(ribbon[indeks] == EOP){
        return true;
    } else {
        return false;
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
void searchId(void* arr, int n, char* search, bool *found, int *idx, int type){ // mencari data
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
int longestUrl(void* data, int n, int type){
    char url[100];      // menyimpan url dari tipe bentukan yang digunakan
    int lenMaxUrl = 0; // panjang dari nama terpanjang
    
    for(int i = 0; i < n; i++){
        // menentukan tipe bentukan yang digunakan
        switch(type){
            case 5: {
                strcpy(url, ((certificate*)data)[i].url);
                break;
            }
            case 8: {
                strcpy(url, ((project*)data)[i].url);
                break;
            }
            default: {
                error(1);
                break;
            }
        }
        // jika lebih kecil maka nilai diperbarui
        if(lenMaxUrl < strlen(url)){
            lenMaxUrl = strlen(url);
        }
    }
    return lenMaxUrl;
}
void showPositionTable(int lenMaxName, int n, position* data){
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
        for(int j = strlen(data[i].id); j < lenMaxID; j++){
            printf(" ");
        }
        // NAMA
        int nameLen = 4;
        if(lenMaxName > nameLen){
            nameLen = lenMaxName;
        }
        printf("| %s ", data[i].name);
        for(int j = strlen(data[i].name); j < nameLen; j++){
            printf(" ");
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
        for(int j = strlen(data[i].id); j < lenMaxID; j++){
            printf(" ");
        }
        // NAMA
        int nameLen = 4;
        if(lenMaxName > nameLen){
            nameLen = lenMaxName;
        }
        printf("| %s ", data[i].name);
        for(int j = strlen(data[i].name); j < nameLen; j++){
            printf(" ");
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
void showProjectTable(int lenMaxName, int lenMaxUrl, int n, project* data){
    // header table
    printf(WHITE"+--------+-");
    for(int i = 1; i <= lenMaxName || i <= 4; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= lenMaxUrl || i <= 3; i++){
        printf("-");
    }
    printf("-+-----------------+-------------+---------------------+---------------------+\n");
    printf("| "BWHITE"ID"WHITE"     |");
    printf(" "BWHITE"Nama"WHITE" ");
    for(int i = 1; i <= lenMaxName && i <= lenMaxName - 4; i++){
        printf(" ");
    }
    printf("| "BWHITE"Url"WHITE" ");
    for(int i = 1; i <= lenMaxUrl && i <= lenMaxUrl - 3; i++){
        printf(" ");
    }
    printf("| "BWHITE"Tanggal_selesai"WHITE" ");
    printf("| "BWHITE"ID_kategori"WHITE" ");
    printf("| "BWHITE"Tanggal_dibuat"WHITE"      | "BWHITE"Tanggal_diubah"WHITE"      |\n");
    printf("+--------+-");
    for(int i = 1; i <= lenMaxName || i <= 4; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= lenMaxUrl || i <= 3; i++){
        printf("-");
    }
    printf("-+-----------------+-------------+---------------------+---------------------+\n");
    
    // body table
    for(int i = 0; i < n; i++){
        int lenMaxID = 6, lenMaxDate = 15;
        // ID
        printf("| %s ", data[i].id);
        for(int j = strlen(data[i].id); j < lenMaxID; j++){
            printf(" ");
        }
        // NAMA
        int nameLen = 4;
        if(lenMaxName > nameLen){
            nameLen = lenMaxName;
        }
        printf("| %s ", data[i].name);
        for(int j = strlen(data[i].name); j < nameLen; j++){
            printf(" ");
        }
        // URL
        int urlLen = 3;
        if(lenMaxUrl > urlLen){
            urlLen = lenMaxUrl;
        }
        printf("| %s ", data[i].url);
        for(int j = strlen(data[i].url); j < urlLen; j++){
            printf(" ");
        }
        // TANGGAL SELESAI
        int dateLen = 15;
        printf("| %s ", data[i].finishedDate);
        for(int j = strlen(data[i].finishedDate); j < lenMaxDate; j++){
            printf(" ");
        }
        // ID KATEGORI
        printf("| %s ", data[i].categoryId);
        for(int j = strlen(data[i].categoryId); j < 11; j++){
            printf(" ");
        }
        // TANGGAL DIBUAT & DIUBAH
        printf("| %s | %s |\n", data[i].createdAt, data[i].updatedAt);
    }
    
    // footer table
    printf("+--------+-");
    for(int i = 1; i <= lenMaxName || i <= 4; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= lenMaxUrl || i <= 3; i++){
        printf("-");
    }
    printf("-+-----------------+-------------+---------------------+---------------------+\n");
}
void showCategoryProject(int maxProName, int maxUrl, int maxCatName, int proSum, int catSum, project* proData, category* catData){
    // header table
    printf("+--------+-");
    for(int i = 1; i <= maxProName || i <= 4; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxUrl || i <= 3; i++){
        printf("-");
    }
    printf("-+-----------------+-");
    for(int i = 1; i <= maxCatName || i <= 8; i++){
        printf("-");
    }
    printf("-+---------------------+---------------------+\n");
    printf("| "BWHITE"ID"WHITE"     |");
    printf(" "BWHITE"Nama"WHITE" ");
    for(int i = 1; i <= maxProName && i <= maxProName - 4; i++){
        printf(" ");
    }
    printf("| "BWHITE"Url"WHITE" ");
    for(int i = 1; i <= maxUrl && i <= maxUrl - 3; i++){
        printf(" ");
    }
    printf("| "BWHITE"Tanggal_selesai"WHITE" ");
    printf("| "BWHITE"Kategori"WHITE" ");
    printf("| "BWHITE"Tanggal_dibuat"WHITE"      | "BWHITE"Tanggal_diubah"WHITE"      |\n");
    printf("+--------+-");
    for(int i = 1; i <= maxProName || i <= 4; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxUrl || i <= 3; i++){
        printf("-");
    }
    printf("-+-----------------+-");
    for(int i = 1; i <= maxCatName || i <= 8; i++){
        printf("-");
    }
    printf("-+---------------------+---------------------+\n");
    
    bool isError = false; // jika ada nilai id_kategori yang tidak valid
    // body table
    for(int i = 0; i < proSum; i++){
        char catName[50];   // nama kategori jika ditemukan
        int j = 0;          // iterasi
        bool found = false; // kondisi berhenti
        // proses pencarian foreign key
        do{
            if(strcmp(proData[i].categoryId, catData[j].id) == 0){
                strcpy(catName, catData[j].name);
                found = true;
            } else {
                found = false;
            }
            j++;
        } while(j < catSum && !found);

        int lenMaxID = 6, lenMaxDate = 15;
        // ID
        printf("| %s ", proData[i].id);
        for(int j = strlen(proData[i].id); j < lenMaxID; j++){
            printf(" ");
        }
        // NAMA
        int nameLen = 4;
        if(maxProName > nameLen){
            nameLen = maxProName;
        }
        printf("| %s ", proData[i].name);
        for(int j = strlen(proData[i].name); j < nameLen; j++){
            printf(" ");
        }
        // URL
        int urlLen = 3;
        if(maxUrl > urlLen){
            urlLen = maxUrl;
        }
        printf("| %s ", proData[i].url);
        for(int j = strlen(proData[i].url); j < urlLen; j++){
            printf(" ");
        }
        // TANGGAL SELESAI
        printf("| %s ", proData[i].finishedDate);
        for(int j = strlen(proData[i].finishedDate); j < lenMaxDate; j++){
            printf(" ");
        }
        int catLen = 8;
        if(maxCatName > catLen){
            catLen = maxCatName;
        }
        // kondisi nilai kategori_id ditemukan di tabel kategori
        if(found){
            // NAMA KATEGORI
            printf("| %s ", catName);
            for(int j = strlen(catName); j < catLen; j++){
                printf(" ");
            }
        } else {
            // ID KATEGORI
            printf("| %s ", proData[i].categoryId);
            for(int j = strlen(proData[i].categoryId); j < catLen; j++){
                printf(" ");
            }
            isError = true;
        }
        // TANGGAL DIBUAT & DIUBAH
        printf("| %s | %s |\n", proData[i].createdAt, proData[i].updatedAt);
    }
    // footer table
    printf("+--------+-");
    for(int i = 1; i <= maxProName || i <= 4; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxUrl || i <= 3; i++){
        printf("-");
    }
    printf("-+-----------------+-");
    for(int i = 1; i <= maxCatName || i <= 8; i++){
        printf("-");
    }
    printf("-+---------------------+---------------------+\n");

    if(isError){
        error(27);
    }
}

// perintah tabel posisi
void getPosition(char command[]){       // menampilkan data
    int recordSum = 0;  // jumlah rekaman dalam tabel
    position temp[MAX]; // array rekaman untuk ditampilkan
    position record;    // rekaman saat ini untuk disalin

    FILE *positionTable;    // kaitan untuk mengakses file
    positionTable = fopen("tables/tposition.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(positionTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);

    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika ditemukan EOF atau data kosong
        error(12);
        fclose(positionTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(positionTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(positionTable); // menutup file

        if(eop(command)){  // jika tidak melakukan pencarian
            // menampilkan data
            showPositionTable(longestName(temp, recordSum, 1), recordSum, temp);
        } else {    // jika tidak melakukan pencarian
            inc(command);
            if(strcmp(getcw(), "WHERE") == 0){
                if(!eop(command)){
                    inc(command);
                    if(eop(command)){
                        char search[50];
                        strcpy(search, getcw());
                        
                        if(strcmp(search, IDDUMMY) == 0){
                            error(11);
                        } else {
                            int idx;            // indeks dan iterasi
                            bool found = false; // cek ditemukan

                            // proses pencarian
                            searchId(temp, recordSum, search, &found, &idx, 7);
                            
                            if(found){  // jika data ditemukan
                                position foundData[1];
                                foundData[0] = temp[idx];
                                showPositionTable(strlen(temp[idx].name), 1, foundData);
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
                error(21);
            }
        }
    }
}
void postPosition(char command[]){      // menambahkan data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp
    
    int recordSum = 0;      // jumlah rekaman di dalam tabel
    position temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
    position record, new;   // rekaman saat ini dan rekaman yang baru
    
    FILE *positionTable;    // kaitan untuk mengakses file
    positionTable = fopen("tables/tposition.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(positionTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);

    // jika tidak ditemukan EOF dan data tidak kosong
    if(strcmp(record.id, IDDUMMY) != 0 && strcmp(record.id, "") != 0){
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(positionTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
    }
    fclose(positionTable); // menutup file
    
    inc(command);   
    if(!eop(command)){
        if(strlen(getcw()) < sizeof(record.id)){
            strcpy(new.id, getcw());    // mengambil id masukan user
    
            inc(command);
            if(eop(command)){
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
                        showPositionTable(longestName(temp, recordSum, 1), recordSum, temp);
                        success(0);
                        // flush ke file
                        positionTable = fopen("tables/tposition.dat", "w");
                        for(int i = 0; i < recordSum; i++){
                            fprintf(positionTable, "%s %s %s %s\n", temp[i].id, temp[i].name, temp[i].createdAt, temp[i].updatedAt);
                        }
                        fprintf(positionTable, "%s", EOFPOSITION);
                        fclose(positionTable);
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
void updatePosition(char command[]){    // mengubah data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp

    int recordSum = 0;      // jumlah rekaman di dalam tabel
    position temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
    position record, new;   // rekaman saat ini dan rekaman yang baru

    FILE *positionTable;    // kaitan untuk mengakses file
    positionTable = fopen("tables/tposition.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(positionTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(positionTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(positionTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
        
        fclose(positionTable); // menutup file
        
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
            if(!eop(command)){
                inc(command);
                if(eop(command)){
                    if(strlen(getcw()) < sizeof(record.name)){
                        strcpy(new.name, getcw());          // mengambil nama masukan user
                        strcpy(new.updatedAt, dateTime);    // mengubah tanggal diubah
        
                        // mengubah menjadi nilai baru
                        strcpy(temp[i].name, new.name);
                        strcpy(temp[i].updatedAt, new.updatedAt);
    
                        showPositionTable(longestName(temp, recordSum, 1), recordSum, temp);
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
        positionTable = fopen("tables/tposition.dat", "w");
        for(int i = 0; i < recordSum; i++){
            fprintf(positionTable, "%s %s %s %s\n", temp[i].id, temp[i].name, temp[i].createdAt, temp[i].updatedAt);
        }
        fprintf(positionTable, "%s", EOFPOSITION);
        fclose(positionTable);   
    }
}
void deletePosition(char command[]){    // menghapus data
    int recordSum = 0;      // jumlah rekaman di dalam tabel
    position temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
    position record, new;   // rekaman saat ini dan rekaman yang baru

    FILE *positionTable;    // kaitan untuk mengakses file
    positionTable = fopen("tables/tposition.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(positionTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(positionTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(positionTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(positionTable); // menutup file
        
        inc(command);
        char search[50]; // cari nilai id
        strcpy(search, getcw()); // mengambil id masukan user
        
        if(eop(command)){
            target targetRecord;

            FILE *targetTable;
            targetTable = fopen("tables/ttarget.dat", "r");

            fscanf(targetTable, "%s %s %s %c %s %s", targetRecord.id, targetRecord.positionId, targetRecord.skillId, targetRecord.isSkilled, targetRecord.createdAt, targetRecord.updatedAt);

            bool foundTarId = false;
            if(strcmp(targetRecord.id, IDDUMMY) != 0 && strcmp(search, IDDUMMY) != 0 && strcmp(targetRecord.id, "") != 0) {
                while((strcmp(targetRecord.id, IDDUMMY) != 0) && (strcmp(targetRecord.positionId, search) != 0)){
                    fscanf(targetTable, "%s %s %s %c %s %s", targetRecord.id, targetRecord.positionId, targetRecord.skillId, targetRecord.isSkilled, targetRecord.createdAt, targetRecord.updatedAt);
                }
                if(strcmp(targetRecord.positionId, search) == 0){
                    foundTarId = true;
                }
            }
            fclose(targetTable);
            
            experience experienceRecord;

            FILE *experienceTable;
            experienceTable = fopen("tables/texperience.dat", "r");

            fscanf(experienceTable, "%s %s %s %s %s %s %s", experienceRecord.id, experienceRecord.organizationId, experienceRecord.positionId, experienceRecord.startDate, experienceRecord.endDate, experienceRecord.createdAt, experienceRecord.updatedAt);

            bool foundExpId = false;
            if(strcmp(experienceRecord.id, IDDUMMY) != 0 && strcmp(search, IDDUMMY) != 0 && strcmp(experienceRecord.id, "") != 0) {
                while((strcmp(experienceRecord.id, IDDUMMY) != 0) && (strcmp(experienceRecord.positionId, search) != 0)){
                    fscanf(experienceTable, "%s %s %s %s %s %s %s", experienceRecord.id, experienceRecord.organizationId, experienceRecord.positionId, experienceRecord.startDate, experienceRecord.endDate, experienceRecord.createdAt, experienceRecord.updatedAt);
                }
                if(strcmp(experienceRecord.positionId, search) == 0){
                    foundExpId = true;
                }
            }
            fclose(experienceTable);

            if(!foundTarId && !foundExpId){
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
                    showPositionTable(longestName(temp, recordSum, 1), recordSum, temp);
                    success(2);
                }
                // flush ke file
                positionTable = fopen("tables/tposition.dat", "w");
                for(int i = 0; i < recordSum; i++){
                    fprintf(positionTable, "%s %s %s %s\n", temp[i].id, temp[i].name, temp[i].createdAt, temp[i].updatedAt);
                }
                fprintf(positionTable, "%s", EOFPOSITION);
                fclose(positionTable);
            } else {
                error(24);
            }
        } else {
            error(14);
        }
    }
}
void guidePosition(){                   // buku panduan posisi
    guideTitle();

    printf("|                                                                                                    |\n");
    printf("|   "WHITE"Tabel posisi digunakan untuk menyimpan relasi posisi dalam tabel target dan pengalaman"CYAN"           |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"STRUKTUR DATA"CYAN"                                                                                    |\n");
    printf("|      "WHITE"1. id              : "CYAN"Kode unik                                                                |\n");
    printf("|      "WHITE"2. nama            : "CYAN"Nama posisi pekerjaan                                                    |\n");
    printf("|      "WHITE"3. tanggal_dibuat  : "CYAN"Waktu data dibuat                                                        |\n");
    printf("|      "WHITE"4. tanggal_diubah  : "CYAN"Waktu data diubah                                                        |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"PENGGUNAAN PERINTAH"CYAN"                                                                              |\n");
    printf("|      "WHITE"1. Menampilkan data      : "BPURPLE"PRESENT FROM "BLUE"tposition"YELLOW"$"CYAN"                                            |\n");
    printf("|      "WHITE"2. Mencari data          : "BPURPLE"PRESENT FROM"BLUE" tposition "BPURPLE"WHERE"CYAN" id"YELLOW"$"CYAN"                                   |\n");
    printf("|      "WHITE"3. Menambahkan data      : "BPURPLE"SUBMIT TO "BLUE"tposition "CYAN"id nama"YELLOW"$"CYAN"                                       |\n");
    printf("|      "WHITE"4. Mengubah data         : "BPURPLE"CHANGE "BLUE"tposition "CYAN"id nama"YELLOW"$"CYAN"                                          |\n");
    printf("|      "WHITE"5. Menghapus data        : "BPURPLE"REMOVE FROM "BLUE"tposition "CYAN"id"YELLOW"$"CYAN"                                          |\n");
    printf("|      "WHITE"6. Menggabungkan tabel   : "BPURPLE"JOIN ON "BLUE"tposition tskill ttarget"YELLOW"$"CYAN"                                  |\n");
    printf("|                                 "BPURPLE"JOIN ON "BLUE"tposition torganization texperience"YELLOW"$"CYAN"                       |\n");
    printf("|                                                                                                    |\n");

    guideFooter();
}

// perintah tabel kategori
void getCategory(char command[]){       // menampilkan data
    int recordSum = 0;  // jumlah rekaman dalam tabel
    category temp[MAX]; // array rekaman untuk ditampilkan
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

        if(eop(command)){  // jika tidak melakukan pencarian
            // menampilkan data
            showCategoryTable(longestName(temp, recordSum, 7), recordSum, temp);
        } else {    // jika tidak melakukan pencarian
            inc(command);
            if(strcmp(getcw(), "WHERE") == 0){
                if(!eop(command)){
                    inc(command);
                    if(eop(command)){
                        char search[50];
                        strcpy(search, getcw());
                        
                        if(strcmp(search, IDDUMMY) == 0){
                            error(11);
                        } else {
                            int idx;            // indeks dan iterasi
                            bool found = false; // cek ditemukan

                            // proses pencarian
                            searchId(temp, recordSum, search, &found, &idx, 7);
                            
                            if(found){  // jika data ditemukan
                                category foundData[1];
                                foundData[0] = temp[idx];
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
                error(21);
            }
        }
    }
}
void postCategory(char command[]){      // menambahkan data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp
    
    int recordSum = 0;      // jumlah rekaman di dalam tabel
    category temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
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
    if(!eop(command)){
        if(strlen(getcw()) < sizeof(record.id)){
            strcpy(new.id, getcw());    // mengambil id masukan user
    
            inc(command);
            if(eop(command)){
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
                        showCategoryTable(longestName(temp, recordSum, 7), recordSum, temp);
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
    category temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
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
            if(!eop(command)){
                inc(command);
                if(eop(command)){
                    if(strlen(getcw()) < sizeof(record.name)){
                        strcpy(new.name, getcw());          // mengambil nama masukan user
                        strcpy(new.updatedAt, dateTime);    // mengubah tanggal diubah
        
                        // mengubah menjadi nilai baru
                        strcpy(temp[i].name, new.name);
                        strcpy(temp[i].updatedAt, new.updatedAt);
    
                        showCategoryTable(longestName(temp, recordSum, 7), recordSum, temp);
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
    category temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
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
        
        if(eop(command)){
            project projectRecord;

            FILE *projectTable;
            projectTable = fopen("tables/tproject.dat", "r");

            fscanf(projectTable, "%s %s %s %s %s %s %s", projectRecord.id, projectRecord.name, projectRecord.url, projectRecord.finishedDate, projectRecord.categoryId, projectRecord.createdAt, projectRecord.updatedAt);

            bool foundProId = false;
            if(strcmp(projectRecord.id, IDDUMMY) != 0 && strcmp(search, IDDUMMY) != 0 && strcmp(projectRecord.id, "") != 0) {
                while((strcmp(projectRecord.id, IDDUMMY) != 0) && (strcmp(projectRecord.categoryId, search) != 0)){
                    fscanf(projectTable, "%s %s %s %s %s %s %s", projectRecord.id, projectRecord.name, projectRecord.url, projectRecord.finishedDate, projectRecord.categoryId, projectRecord.createdAt, projectRecord.updatedAt);
                }
                if(strcmp(projectRecord.categoryId, search) == 0){
                    foundProId = true;
                }
            }
            fclose(projectTable);

            if(!foundProId){
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
                    showCategoryTable(longestName(temp, recordSum, 7), recordSum, temp);
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
                error(24);
            }
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
    printf("|      "WHITE"3. tanggal_dibuat  : "CYAN"Waktu data dibuat                                                        |\n");
    printf("|      "WHITE"4. tanggal_diubah  : "CYAN"Waktu data diubah                                                        |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"PENGGUNAAN PERINTAH"CYAN"                                                                              |\n");
    printf("|      "WHITE"1. Menampilkan data      : "BPURPLE"PRESENT FROM "BLUE"tcategory"YELLOW"$"CYAN"                                            |\n");
    printf("|      "WHITE"2. Mencari data          : "BPURPLE"PRESENT FROM"BLUE" tcategory "BPURPLE"WHERE"CYAN" id"YELLOW"$"CYAN"                                   |\n");
    printf("|      "WHITE"3. Menambahkan data      : "BPURPLE"SUBMIT TO "BLUE"tcategory "CYAN"id nama"YELLOW"$"CYAN"                                       |\n");
    printf("|      "WHITE"4. Mengubah data         : "BPURPLE"CHANGE "BLUE"tcategory "CYAN"id nama"YELLOW"$"CYAN"                                          |\n");
    printf("|      "WHITE"5. Menghapus data        : "BPURPLE"REMOVE FROM "BLUE"tcategory "CYAN"id"YELLOW"$"CYAN"                                          |\n");
    printf("|      "WHITE"6. Menggabungkan tabel   : "BPURPLE"JOIN ON "BLUE"tcategory tproject"YELLOW"$"CYAN"                                        |\n");
    printf("|                                                                                                    |\n");

    guideFooter();
}

// perintah tabel proyek
void getProject(char command[]){       // menampilkan data
    int recordSum = 0;  // jumlah rekaman dalam tabel
    project temp[MAX];  // array rekaman untuk ditampilkan
    project record;     // rekaman saat ini untuk disalin

    FILE *projectTable;    // kaitan untuk mengakses file
    projectTable = fopen("tables/tproject.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(projectTable, "%s %s %s %s %s %s %s\n", record.id, record.name, record.url, record.finishedDate, record.categoryId, record.createdAt, record.updatedAt);

    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika ditemukan EOF atau data kosong
        error(12);
        fclose(projectTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].url, record.url);
            strcpy(temp[recordSum].finishedDate, record.finishedDate);
            strcpy(temp[recordSum].categoryId, record.categoryId);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(projectTable, "%s %s %s %s %s %s %s\n", record.id, record.name, record.url, record.finishedDate, record.categoryId, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(projectTable); // menutup file

        if(eop(command)){  // jika tidak melakukan pencarian
            // menampilkan data
            showProjectTable(longestName(temp, recordSum, 8), longestUrl(temp, recordSum, 8), recordSum, temp);
        } else {    // jika tidak melakukan pencarian
            inc(command);
            if(strcmp(getcw(), "WHERE") == 0){
                if(!eop(command)){
                    inc(command);
                    if(eop(command)){
                        char search[50];
                        strcpy(search, getcw());
                        
                        if(strcmp(search, IDDUMMY) == 0){
                            error(11);
                        } else {
                            int idx;            // indeks dan iterasi
                            bool found = false; // cek ditemukan

                            // proses pencarian
                            searchId(temp, recordSum, search, &found, &idx, 8);
                            
                            if(found){  // jika data ditemukan
                                project foundData[1];
                                strcpy(foundData[0].id, temp[idx].id);
                                strcpy(foundData[0].name, temp[idx].name);
                                strcpy(foundData[0].url, temp[idx].url);
                                strcpy(foundData[0].finishedDate, temp[idx].finishedDate);
                                strcpy(foundData[0].categoryId, temp[idx].categoryId);
                                strcpy(foundData[0].createdAt, temp[idx].createdAt);
                                strcpy(foundData[0].updatedAt, temp[idx].updatedAt);
                                showProjectTable(longestName(foundData, 1, 8), longestUrl(foundData, 1, 8), 1, foundData);
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
                error(21);
            }
        }
    }
}
void postProject(char command[]){      // menambahkan data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp
    
    int recordSum = 0;      // jumlah rekaman di dalam tabel
    project temp[MAX];      // array rekaman untuk menggeserkan nilai rekaman baru
    project record, new;    // rekaman saat ini dan rekaman yang baru
    
    FILE *projectTable;    // kaitan untuk mengakses file
    projectTable = fopen("tables/tproject.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(projectTable, "%s %s %s %s %s %s %s\n", record.id, record.name, record.url, record.finishedDate, record.categoryId, record.createdAt, record.updatedAt);

    // jika tidak ditemukan EOF dan data tidak kosong
    if(strcmp(record.id, IDDUMMY) != 0 && strcmp(record.id, "") != 0){
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].url, record.url);
            strcpy(temp[recordSum].finishedDate, record.finishedDate);
            strcpy(temp[recordSum].categoryId, record.categoryId);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(projectTable, "%s %s %s %s %s %s %s\n", record.id, record.name, record.url, record.finishedDate, record.categoryId, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
    }
    fclose(projectTable); // menutup file
    
    inc(command);   
    if(!eop(command)){
        if(strlen(getcw()) < sizeof(record.id)){
            strcpy(new.id, getcw());    // mengambil id masukan user
    
            inc(command);
            if(!eop(command)){
                if(strlen(getcw()) < sizeof(record.name)){
                    strcpy(new.name, getcw());  // mengambil nama masukan user

                    inc(command);
                    if(!eop(command)){
                        if(strlen(getcw()) < sizeof(record.url)){
                            strcpy(new.url, getcw());

                            inc(command);
                            if(!eop(command)){
                                if(strlen(getcw()) < sizeof(record.finishedDate)){
                                    strcpy(new.finishedDate, getcw());

                                    inc(command);
                                    if(eop(command)){
                                        if(strlen(getcw()) < sizeof(record.categoryId)){

                                            category categoryRecord;

                                            FILE *categoryTable;
                                            categoryTable = fopen("tables/tcategory.dat", "r");

                                            char search[10];
                                            strcpy(search, getcw());

                                            fscanf(categoryTable, "%s %s %s %s", categoryRecord.id, categoryRecord.name, categoryRecord.createdAt, categoryRecord.updatedAt);

                                            bool foundCatId = false;
                                            if(strcmp(categoryRecord.id, IDDUMMY) == 0){
                                                error(12);
                                            } else if (strcmp(search, IDDUMMY) == 0){
                                                error(11);
                                            } else {
                                                while((strcmp(categoryRecord.id, IDDUMMY) != 0) && (strcmp(categoryRecord.id, search) != 0)){
                                                    fscanf(categoryTable, "%s %s %s %s\n", categoryRecord.id, categoryRecord.name, categoryRecord.createdAt, categoryRecord.updatedAt);
                                                }
                                                if(strcmp(categoryRecord.id, search) == 0){
                                                    foundCatId = true;
                                                } else {
                                                    error(23);
                                                }
                                            }
                                            fclose(categoryTable);

                                            if(foundCatId){
                                                strcpy(new.categoryId, getcw());
    
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
                                                        strcpy(temp[i+1].url, temp[i].url);
                                                        strcpy(temp[i+1].finishedDate, temp[i].finishedDate);
                                                        strcpy(temp[i+1].categoryId, temp[i].categoryId);
                                                        strcpy(temp[i+1].createdAt, temp[i].createdAt);
                                                        strcpy(temp[i+1].updatedAt, temp[i].updatedAt);
                                                    }
                                                    recordSum++;
                                                    strcpy(temp[0].id, new.id);
                                                    strcpy(temp[0].name, new.name);
                                                    strcpy(temp[0].url, new.url);
                                                    strcpy(temp[0].finishedDate, new.finishedDate);
                                                    strcpy(temp[0].categoryId, new.categoryId);
                                                    strcpy(temp[0].createdAt, new.createdAt);
                                                    strcpy(temp[0].updatedAt, new.updatedAt);
                                                } else if (strcmp(new.id, temp[recordSum - 1].id) > 0){
                                                    // rekaman baru di paling belakang
                                                    strcpy(temp[recordSum].id, new.id);
                                                    strcpy(temp[recordSum].name, new.name);
                                                    strcpy(temp[recordSum].url, new.url);
                                                    strcpy(temp[recordSum].finishedDate, new.finishedDate);
                                                    strcpy(temp[recordSum].categoryId, new.categoryId);
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
                                                            strcpy(temp[j+1].url, temp[j].url);
                                                            strcpy(temp[j+1].finishedDate, temp[j].finishedDate);
                                                            strcpy(temp[j+1].categoryId, temp[j].categoryId);
                                                            strcpy(temp[j+1].createdAt, temp[j].createdAt);
                                                            strcpy(temp[j+1].updatedAt, temp[j].updatedAt);
                                                        }
                                                        // memasukkan rekaman baru di posisi tengah
                                                        strcpy(temp[i].id, new.id);
                                                        strcpy(temp[i].name, new.name);
                                                        strcpy(temp[i].url, new.url);
                                                        strcpy(temp[i].finishedDate, new.finishedDate);
                                                        strcpy(temp[i].categoryId, new.categoryId);
                                                        strcpy(temp[i].createdAt, new.createdAt);
                                                        strcpy(temp[i].updatedAt, new.updatedAt);
                                                        recordSum++;
                                                    }
                                                }
                                                if(!isDuplicate){
                                                    showProjectTable(longestName(temp, recordSum, 8), longestUrl(temp, recordSum, 8), recordSum, temp);
                                                    success(0);
                                                    // flush ke file
                                                    projectTable = fopen("tables/tproject.dat", "w");
                                                    for(int i = 0; i < recordSum; i++){
                                                        fprintf(projectTable, "%s %s %s %s %s %s %s\n", temp[i].id, temp[i].name, temp[i].url, temp[i].finishedDate, temp[i].categoryId, temp[i].createdAt, temp[i].updatedAt);
                                                    }
                                                    fprintf(projectTable, "%s", EOFPROJECT);
                                                    fclose(projectTable);
                                                }
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
                        } else {
                            error(16);
                        }
                    } else {
                        error(4);
                    }
                } else {
                    error(16);
                }
            } else {
                error(4);
            }
        } else {
            error(16);
        }
    } else {
        error(4);
    }
}
void updateProject(char command[]){    // mengubah data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp

    int recordSum = 0;      // jumlah rekaman di dalam tabel
    project temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
    project record, new;   // rekaman saat ini dan rekaman yang baru

    FILE *projectTable;    // kaitan untuk mengakses file
    projectTable = fopen("tables/tproject.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(projectTable, "%s %s %s %s %s %s %s\n", record.id, record.name, record.url, record.finishedDate, record.categoryId, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(projectTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].url, record.url);
            strcpy(temp[recordSum].finishedDate, record.finishedDate);
            strcpy(temp[recordSum].categoryId, record.categoryId);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(projectTable, "%s %s %s %s %s %s %s\n", record.id, record.name, record.url, record.finishedDate, record.categoryId, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
        
        fclose(projectTable); // menutup file
        
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
            if(!eop(command)){
                inc(command);
                if(!eop(command)){
                    if(strlen(getcw()) < sizeof(record.name)){
                        strcpy(new.name, getcw());          // mengambil nama masukan user

                        inc(command);
                        if(!eop(command)){
                            if(strlen(getcw()) < sizeof(record.url)){
                                strcpy(new.url, getcw());

                                inc(command);
                                if(!eop(command)){
                                    if(strlen(getcw()) < sizeof(record.finishedDate)){
                                        strcpy(new.finishedDate, getcw());

                                        inc(command);
                                        if(eop(command)){
                                            if(strlen(getcw()) < sizeof(record.categoryId)){

                                                category categoryRecord;

                                                FILE *categoryTable;
                                                categoryTable = fopen("tables/tcategory.dat", "r");

                                                char search[10];
                                                strcpy(search, getcw());

                                                fscanf(categoryTable, "%s %s %s %s", categoryRecord.id, categoryRecord.name, categoryRecord.createdAt, categoryRecord.updatedAt);

                                                bool foundCatId = false;
                                                if(strcmp(categoryRecord.id, IDDUMMY) == 0){
                                                    error(12);
                                                } else if (strcmp(search, IDDUMMY) == 0){
                                                    error(11);
                                                } else {
                                                    while((strcmp(categoryRecord.id, IDDUMMY) != 0) && (strcmp(categoryRecord.id, search) != 0)){
                                                        fscanf(categoryTable, "%s %s %s %s\n", categoryRecord.id, categoryRecord.name, categoryRecord.createdAt, categoryRecord.updatedAt);
                                                    }
                                                    if(strcmp(categoryRecord.id, search) == 0){
                                                        foundCatId = true;
                                                    } else {
                                                        error(23);
                                                    }
                                                }
                                                fclose(categoryTable);

                                                if(foundCatId){
                                                    strcpy(new.categoryId, getcw());
                                                    strcpy(new.updatedAt, dateTime);    // mengubah tanggal diubah
                
                                                    // mengubah menjadi nilai baru
                                                    strcpy(temp[i].name, new.name);
                                                    strcpy(temp[i].url, new.url);
                                                    strcpy(temp[i].finishedDate, new.finishedDate);
                                                    strcpy(temp[i].categoryId, new.categoryId);
                                                    strcpy(temp[i].updatedAt, new.updatedAt);
                                
                                                    showProjectTable(longestName(temp, recordSum, 8), longestUrl(temp, recordSum, 8), recordSum, temp);
                                                    success(1);
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
                            } else {
                                error(16);
                            }
                        } else {
                            error(4);
                        }
                    } else {
                        error(16);
                    }
                } else {
                    error(4);
                }
            } else {
                error(13);
            }
        }
        // flush ke file
        projectTable = fopen("tables/tproject.dat", "w");
        for(int i = 0; i < recordSum; i++){
            fprintf(projectTable, "%s %s %s %s %s %s %s\n", temp[i].id, temp[i].name, temp[i].url, temp[i].finishedDate, temp[i].categoryId, temp[i].createdAt, temp[i].updatedAt);
        }
        fprintf(projectTable, "%s", EOFPROJECT);
        fclose(projectTable);   
    }
}
void deleteProject(char command[]){    // menghapus data
    int recordSum = 0;      // jumlah rekaman di dalam tabel
    project temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
    project record, new;   // rekaman saat ini dan rekaman yang baru

    FILE *projectTable;    // kaitan untuk mengakses file
    projectTable = fopen("tables/tproject.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(projectTable, "%s %s %s %s %s %s %s\n", record.id, record.name, record.url, record.finishedDate, record.categoryId, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(projectTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].url, record.url);
            strcpy(temp[recordSum].finishedDate, record.finishedDate);
            strcpy(temp[recordSum].categoryId, record.categoryId);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(projectTable, "%s %s %s %s %s %s %s\n", record.id, record.name, record.url, record.finishedDate, record.categoryId, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(projectTable); // menutup file
        
        inc(command);
        char search[50]; // cari nilai id
        strcpy(search, getcw()); // mengambil id masukan user
        
        if(eop(command)){
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
                        strcpy(temp[i].url, temp[i+1].url);
                        strcpy(temp[i].finishedDate, temp[i+1].finishedDate);
                        strcpy(temp[i].categoryId, temp[i+1].categoryId);
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
                        strcpy(temp[j].url, temp[j+1].url);
                        strcpy(temp[j].finishedDate, temp[j+1].finishedDate);
                        strcpy(temp[j].categoryId, temp[j+1].categoryId);
                        strcpy(temp[j].createdAt, temp[j+1].createdAt);
                        strcpy(temp[j].updatedAt, temp[j+1].updatedAt);
                    }
                    recordSum--;
                }
                showProjectTable(longestName(temp, recordSum, 8), longestUrl(temp, recordSum, 8), recordSum, temp);
                success(2);
            }
            // flush ke file
            projectTable = fopen("tables/tproject.dat", "w");
            for(int i = 0; i < recordSum; i++){
                fprintf(projectTable, "%s %s %s %s %s %s %s\n", temp[i].id, temp[i].name, temp[i].url, temp[i].finishedDate, temp[i].categoryId, temp[i].createdAt, temp[i].updatedAt);
            }
            fprintf(projectTable, "%s", EOFPROJECT);
            fclose(projectTable);
        } else {
            error(14);
        }
    }
}
void guideProject(){                   // buku panduan proyek
    guideTitle();

    printf("|                                                                                                    |\n");
    printf("|   "WHITE"Tabel proyek digunakan untuk menyimpan data proyek yang pernah dibuat"CYAN"                            |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"STRUKTUR DATA"CYAN"                                                                                    |\n");
    printf("|      "WHITE"1. id              : "CYAN"Kode unik                                                                |\n");
    printf("|      "WHITE"2. nama            : "CYAN"Nama/judul proyek                                                        |\n");
    printf("|      "WHITE"3. url             : "CYAN"Url hasil proyek (opsional: -)                                           |\n");
    printf("|      "WHITE"4. tanggal_selesai : "CYAN"Tanggal proyek selesai (cth. 2025_May atau -)                            |\n");
    printf("|      "WHITE"5. id_kategori     : "CYAN"Kode unik dari nama kategori                                             |\n");
    printf("|      "WHITE"6. tanggal_dibuat  : "CYAN"Waktu data dibuat                                                        |\n");
    printf("|      "WHITE"7. tanggal_diubah  : "CYAN"Waktu data diubah                                                        |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"PENGGUNAAN PERINTAH"CYAN"                                                                              |\n");
    printf("|      "WHITE"1. Menampilkan data      : "BPURPLE"PRESENT FROM "BLUE"tproject"YELLOW"$"CYAN"                                             |\n");
    printf("|      "WHITE"2. Mencari data          : "BPURPLE"PRESENT FROM"BLUE" tproject "BPURPLE"WHERE"CYAN" id"YELLOW"$"CYAN"                                    |\n");
    printf("|      "WHITE"3. Menambahkan data      : "BPURPLE"SUBMIT TO "BLUE"tproject "CYAN"id nama url tanggal_selesai id_kategori"YELLOW"$"CYAN"        |\n");
    printf("|      "WHITE"4. Mengubah data         : "BPURPLE"CHANGE "BLUE"tproject "CYAN"id nama url tanggal_selesai id_kategori"YELLOW"$"CYAN"           |\n");
    printf("|      "WHITE"5. Menghapus data        : "BPURPLE"REMOVE FROM "BLUE"tproject "CYAN"id"YELLOW"$"CYAN"                                           |\n");
    printf("|      "WHITE"6. Menggabungkan tabel   : "BPURPLE"JOIN ON "BLUE"tproject tcategory"YELLOW"$"CYAN"                                        |\n");
    printf("|                                                                                                    |\n");

    guideFooter();
}

// perintah join
void joinProjectCategory(char command[]){   // menggabungkan tabel kategori dan proyek
    int catSum = 0;         // jumlah rekaman dalam tabel kategori
    category tempCat[MAX];  // array rekaman kategori untuk ditampilkan
    category catRecord;     // rekaman kategori saat ini untuk disalin

    FILE *categoryTable;    // kaitan untuk mengakses file kategori
    categoryTable = fopen("tables/tcategory.dat", "r"); // membuka file kategori dengan mode read
    
    // memulai proses pembacaan
    fscanf(categoryTable, "%s %s %s %s\n", catRecord.id, catRecord.name, catRecord.createdAt, catRecord.updatedAt);

    if(strcmp(catRecord.id, IDDUMMY) == 0 || strcmp(catRecord.id, "") == 0){
        // jika ditemukan EOF atau data kosong
        error(12);
        fclose(categoryTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array kategori sampai ditemukan EOF
        do{
            strcpy(tempCat[catSum].id, catRecord.id);
            strcpy(tempCat[catSum].name, catRecord.name);
            strcpy(tempCat[catSum].createdAt, catRecord.createdAt);
            strcpy(tempCat[catSum].updatedAt, catRecord.updatedAt);
            catSum++;
            fscanf(categoryTable, "%s %s %s %s\n", catRecord.id, catRecord.name, catRecord.createdAt, catRecord.updatedAt);
        } while(strcmp(catRecord.id, IDDUMMY) != 0);

        fclose(categoryTable); // menutup file kategori

        int proSum = 0;  // jumlah rekaman dalam tabel proyek
        project tempPro[MAX]; // array rekaman proyek untuk ditampilkan
        project proRecord;    // rekaman proyek saat ini untuk disalin

        FILE *projectTable;    // kaitan untuk mengakses file proyek
        projectTable = fopen("tables/tproject.dat", "r"); // membuka file proyek dengan mode read
        
        // memulai proses pembacaan
        fscanf(projectTable, "%s %s %s %s %s %s %s\n", proRecord.id, proRecord.name, proRecord.url, proRecord.finishedDate, proRecord.categoryId, proRecord.createdAt, proRecord.updatedAt);

        if(strcmp(proRecord.id, IDDUMMY) == 0 || strcmp(proRecord.id, "") == 0){
            // jika ditemukan EOF atau data kosong
            error(12);
            fclose(projectTable);
        } else {
            // jika tidak ditemukan EOF dan data tidak kosong
            // mengisi rekaman ke dalam array proyek sampai ditemukan EOF
            do{
                strcpy(tempPro[proSum].id, proRecord.id);
                strcpy(tempPro[proSum].name, proRecord.name);
                strcpy(tempPro[proSum].url, proRecord.url);
                strcpy(tempPro[proSum].finishedDate, proRecord.finishedDate);
                strcpy(tempPro[proSum].categoryId, proRecord.categoryId);
                strcpy(tempPro[proSum].createdAt, proRecord.createdAt);
                strcpy(tempPro[proSum].updatedAt, proRecord.updatedAt);
                proSum++;
                fscanf(projectTable, "%s %s %s %s %s %s %s\n", proRecord.id, proRecord.name, proRecord.url, proRecord.finishedDate, proRecord.categoryId, proRecord.createdAt, proRecord.updatedAt);
            } while(strcmp(proRecord.id, IDDUMMY) != 0);

            fclose(projectTable); // menutup file

            // hasil join
            showCategoryProject(longestName(tempPro, proSum, 8), longestUrl(tempPro, proSum, 8), longestName(tempCat, catSum, 7), proSum, catSum, tempPro, tempCat);
        }
    }
}
