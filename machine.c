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
        case 29: {
            printf(RED "Level kecakapan harus di antara berikut:\n" DEFAULT);
            printf(RED "pemula, menengah, mahir\n" DEFAULT);
            break;    
        }
        case 30: {
            printf(RED "Penguasaan harus di antara berikut:\n" DEFAULT);
            printf(RED "0, 1\n\n" DEFAULT);
            printf(RED "0 = belum dikuasai, 1 = sudah dikuasai\n" DEFAULT);
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
int longestCredential(certificate* data, int n){
    int lenMaxCredential = strlen(data[0].credentialId); // panjang dari nama terpanjang
    
    for(int i = 1; i < n; i++){
        // jika lebih kecil maka nilai diperbarui
        if(lenMaxCredential < strlen(data[i].credentialId)){
            lenMaxCredential = strlen(data[i].credentialId);
        }
    }
    return lenMaxCredential;
}

// ui tabel
// https://stackoverflow.com/questions/75400003/is-there-a-way-to-make-a-single-function-operate-on-different-structures-having
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
void showSkillTable(int lenMaxName, int n, skill* data){
    // header table
    printf(WHITE"+--------+-");
    for(int i = 1; i <= lenMaxName || i <= 4; i++){
        printf("-");
    }
    printf("-+-----------+---------------------+---------------------+\n");
    printf("| "BWHITE"ID"WHITE"     |");
    printf(" "BWHITE"Nama"WHITE" ");
    for(int i = 1; i <= lenMaxName && i <= lenMaxName - 4; i++){
        printf(" ");
    }
    printf("| "BWHITE"Kecakapan"WHITE" | "BWHITE"Tanggal_dibuat"WHITE"      | "BWHITE"Tanggal_diubah"WHITE"      |\n");
    printf("+--------+-");
    for(int i = 1; i <= lenMaxName || i <= 4; i++){
        printf("-");
    }
    printf("-+-----------+---------------------+---------------------+\n");

    // body table
    for(int i = 0; i < n; i++){
        int lenMaxID = 6;
        int lenMaxProf = 9;
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
        // KECAKAPAN
        printf("| %s ", data[i].proficiency);
        for(int j = strlen(data[i].proficiency); j < lenMaxProf; j++){
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
    printf("-+-----------+---------------------+---------------------+\n"DEFAULT);
}
void showTargetTable(int n, target* data){
    // header table
    printf(WHITE"+--------+-----------+----------+----------------+---------------------+---------------------+\n");
    printf("| "BWHITE"ID"WHITE"     | "BWHITE"ID_posisi"WHITE" | "BWHITE"ID_skill"WHITE" | "BWHITE"Sudah_dikuasai"WHITE" | "BWHITE"Tanggal_dibuat"WHITE"      | "BWHITE"Tanggal_diubah"WHITE"      |\n");
    printf("+--------+-----------+----------+----------------+---------------------+---------------------+\n");

    // body table
    for(int i = 0; i < n; i++){
        int lenMaxID = 6;
        int lenMaxPosID = 9;
        int lenMaxSklID = 8;
        // ID
        printf("| %s ", data[i].id);
        for(int j = strlen(data[i].id); j < lenMaxID; j++){
            printf(" ");
        }
        // ID POSISI
        printf("| %s ", data[i].positionId);
        for(int j = strlen(data[i].positionId); j < lenMaxPosID; j++){
            printf(" ");
        }
        // ID SKILL
        printf("| %s ", data[i].skillId);
        for(int j = strlen(data[i].skillId); j < lenMaxSklID; j++){
            printf(" ");
        }
        // STATUS PENGUASAAN
        printf("| %d              ", data[i].isSkilled);
        // TANGGAL DIBUAT & DIUBAH
        printf("| %s | %s |\n", data[i].createdAt, data[i].updatedAt);
    }

    // footer table
    printf("+--------+-----------+----------+----------------+---------------------+---------------------+\n"DEFAULT);
}
void showOrganizationTable(int lenMaxName, int n, organization* data){
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
void showCertificateTable(int lenMaxName, int lenMaxCredential, int lenMaxUrl, int n, certificate* data){
    // header table
    printf(WHITE"+--------+-");
    for(int i = 1; i <= lenMaxName || i <= 4; i++){
        printf("-");
    }
    printf("-+---------------+-----------------+------------------+-");
    for(int i = 1; i <= lenMaxCredential || i <= 13; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= lenMaxUrl || i <= 3; i++){
        printf("-");
    }
    printf("-+---------------------+---------------------+\n");
    printf("| "BWHITE"ID"WHITE"     |");
    printf(" "BWHITE"Nama"WHITE" ");
    for(int i = 1; i <= lenMaxName && i <= lenMaxName - 4; i++){
        printf(" ");
    }
    printf("| "BWHITE"ID_organisasi"WHITE" | "BWHITE"Tanggal_dimulai"WHITE" | "BWHITE"Tanggal_berakhir"WHITE" ");
    printf("| "BWHITE"ID_kredensial"WHITE" ");
    for(int i = 1; i <= lenMaxCredential && i <= lenMaxCredential - 13; i++){
        printf(" ");
    }
    printf("| "BWHITE"Url"WHITE" ");
    for(int i = 1; i <= lenMaxUrl && i <= lenMaxUrl - 3; i++){
        printf(" ");
    }
    printf("| "BWHITE"Tanggal_dibuat"WHITE"      | "BWHITE"Tanggal_diubah"WHITE"      |\n");
    printf("+--------+-");
    for(int i = 1; i <= lenMaxName || i <= 4; i++){
        printf("-");
    }
    printf("-+---------------+-----------------+------------------+-");
    for(int i = 1; i <= lenMaxCredential || i <= 13; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= lenMaxUrl || i <= 3; i++){
        printf("-");
    }
    printf("-+---------------------+---------------------+\n");
    
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
        // ID ORGANISASI
        int issuerLen = 13;
        printf("| %s ", data[i].issuerId);
        for(int j = strlen(data[i].issuerId); j < issuerLen; j++){
            printf(" ");
        }
        // TANGGAL DIMULAI
        int lenMaxStartDate = 15;
        printf("| %s ", data[i].startDate);
        for(int j = strlen(data[i].startDate); j < lenMaxStartDate; j++){
            printf(" ");
        }
        // TANGGAL BERAKHIR
        printf("| %s ", data[i].endDate);
        int lenMaxEndDate = 16;
        for(int j = strlen(data[i].endDate); j < lenMaxEndDate; j++){
            printf(" ");
        }
        // KREDENSIAL
        int credLen = 13;
        if(lenMaxCredential > credLen){
            credLen = lenMaxCredential;
        }
        printf("| %s ", data[i].url);
        for(int j = strlen(data[i].url); j < credLen; j++){
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
        // TANGGAL DIBUAT & DIUBAH
        printf("| %s | %s |\n", data[i].createdAt, data[i].updatedAt);
    }
    
    // footer table
    printf("+--------+-");
    for(int i = 1; i <= lenMaxName || i <= 4; i++){
        printf("-");
    }
    printf("-+---------------+-----------------+------------------+-");
    for(int i = 1; i <= lenMaxCredential || i <= 13; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= lenMaxUrl || i <= 3; i++){
        printf("-");
    }
    printf("-+---------------------+---------------------+\n"DEFAULT);
}
void showExperienceTable(int n, experience* data){
    // header table
    printf(WHITE"+--------+---------------+-----------+-----------------+------------------+---------------------+---------------------+\n");
    printf("| "BWHITE"ID"WHITE"     | "BWHITE"ID_organisasi"WHITE" | "BWHITE"ID_posisi"WHITE" | "BWHITE"Tanggal_dimulai"WHITE" | "BWHITE"Tanggal_berakhir"WHITE" | "BWHITE"Tanggal_dibuat"WHITE"      | "BWHITE"Tanggal_diubah"WHITE"      |\n");
    printf("+--------+---------------+-----------+-----------------+------------------+---------------------+---------------------+\n");

    // body table
    for(int i = 0; i < n; i++){
        int lenMaxID = 6;
        int lenMaxOrgID = 13;
        int lenMaxPosID = 9;
        int lenMaxStartDate = 15;
        int lenMaxEndDate = 16;
        // ID
        printf("| %s ", data[i].id);
        for(int j = strlen(data[i].id); j < lenMaxID; j++){
            printf(" ");
        }
        // ID ORGANISASI
        printf("| %s ", data[i].organizationId);
        for(int j = strlen(data[i].organizationId); j < lenMaxOrgID; j++){
            printf(" ");
        }
        // ID POSISI
        printf("| %s ", data[i].positionId);
        for(int j = strlen(data[i].positionId); j < lenMaxPosID; j++){
            printf(" ");
        }
        // TANGGAL DIMULAI
        printf("| %s ", data[i].startDate);
        for(int j = strlen(data[i].startDate); j < lenMaxStartDate; j++){
            printf(" ");
        }
        // TANGGAL BERAKHIR
        printf("| %s ", data[i].endDate);
        for(int j = strlen(data[i].endDate); j < lenMaxEndDate; j++){
            printf(" ");
        }
        // TANGGAL DIBUAT & DIUBAH
        printf("| %s | %s |\n", data[i].createdAt, data[i].updatedAt);
    }

    // footer table
    printf("+--------+---------------+-----------+-----------------+------------------+---------------------+---------------------+\n"DEFAULT);
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

// ui tabel join
// tabel gabungan posisi, skill, dan target
void showPositionSkillTarget(int maxPosName, int maxSklName, int tarSum, int posSum, int sklSum, target* tarData, position* posData, skill* sklData){
    // header table
    printf(WHITE"+--------+-");
    for(int i = 1; i <= maxPosName || i <= 6; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxSklName || i <= 5; i++){
        printf("-");
    }
    printf("-+----------------+---------------------+---------------------+\n");
    printf("| "BWHITE"ID"WHITE"     | "BWHITE"Posisi"WHITE" ");
    for(int i = 1; i <= maxPosName && i <= maxPosName - 6; i++){
        printf(" ");
    }
    printf("| "BWHITE"Skill"WHITE" ");
    for(int i = 1; i <= maxSklName && i <= maxSklName - 5; i++){
        printf(" ");
    }
    printf("| "BWHITE"Sudah_dikuasai"WHITE" | "BWHITE"Tanggal_dibuat"WHITE"      | "BWHITE"Tanggal_diubah"WHITE"      |\n");
    printf("+--------+-");
    for(int i = 1; i <= maxPosName || i <= 6; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxSklName || i <= 5; i++){
        printf("-");
    }
    printf("-+----------------+---------------------+---------------------+\n");

    bool isError = false; // jika ada nilai foreign yang tidak valid
    // body table
    for(int i = 0; i < tarSum; i++){
        char posName[50];   // nama posisi jika ditemukan
        int j = 0;          // iterasi
        bool foundPos = false; // kondisi berhenti
        // proses pencarian foreign key
        do{
            if(strcmp(tarData[i].positionId, posData[j].id) == 0){
                strcpy(posName, posData[j].name);
                foundPos = true;
            }
            j++;
        } while(j < posSum && !foundPos);

        char sklName[50];   // nama skill jika ditemukan
        j = 0;              // iterasi
        bool foundSkl = false; // kondisi berhenti
        // proses pencarian foreign key
        do{
            if(strcmp(tarData[i].skillId, sklData[j].id) == 0){
                strcpy(sklName, sklData[j].name);
                foundSkl = true;
            }
            j++;
        } while(j < sklSum && !foundSkl);

        int lenMaxID = 6;
        // ID
        printf("| %s ", tarData[i].id);
        for(int j = strlen(tarData[i].id); j < lenMaxID; j++){
            printf(" ");
        }
        // POSISI
        int lenPos = 6;
        if(maxPosName > lenPos){
            lenPos = maxPosName;
        }
        if(foundPos){
            printf("| %s ", posName);
            for(int j = strlen(posName); j < lenPos; j++){
                printf(" ");
            }
        } else {
            printf("| %s ", tarData[i].positionId);
            for(int j = strlen(tarData[i].positionId); j < lenPos; j++){
                printf(" ");
            }
            isError = true;
        }
        // SKILL
        int lenSkl = 5;
        if(maxSklName > lenSkl){
            lenSkl = maxSklName;
        }
        if(foundSkl){
            printf("| %s ", sklName);
            for(int j = strlen(sklName); j < lenSkl; j++){
                printf(" ");
            }
        } else {
            printf("| %s ", tarData[i].skillId);
            for(int j = strlen(tarData[i].skillId); j < lenSkl; j++){
                printf(" ");
            }
            isError = true;
        }
        // STATUS PENGUASAAN
        printf("| %d              ", tarData[i].isSkilled);
        // TANGGAL DIBUAT & DIUBAH
        printf("| %s | %s |\n", tarData[i].createdAt, tarData[i].updatedAt);
    }
    // footer table
    printf("+--------+-");
    for(int i = 1; i <= maxPosName || i <= 6; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxSklName| i <= 5; i++){
        printf("-");
    }
    printf("-+----------------+---------------------+---------------------+\n"DEFAULT);

    if(isError){
        error(27);
    }
}
// tabel gabungan organisasi, dan sertifikat
void showOrganizationCertificate(int maxCerName, int maxUrl, int maxOrgName, int maxCred, int cerSum, int orgSum, certificate* cerData, organization* orgData){
    // header table
    printf(WHITE"+--------+-");
    for(int i = 1; i <= maxCerName || i <= 4; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxOrgName || i <= 10; i++){
        printf("-");
    }
    printf("-+-----------------+------------------+-");
    for(int i = 1; i <= maxCred || i <= 13; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxUrl || i <= 3; i++){
        printf("-");
    }
    printf("-+---------------------+---------------------+\n");
    printf("| "BWHITE"ID"WHITE"     |");
    printf(" "BWHITE"Nama"WHITE" ");
    for(int i = 1; i <= maxCerName && i <= maxCerName - 4; i++){
        printf(" ");
    }
    printf("| "BWHITE"Organisasi"WHITE" ");
    for(int i = 1; i <= maxOrgName && i <= maxOrgName - 10; i++){
        printf(" ");
    }
    printf("| "BWHITE"Tanggal_dimulai"WHITE" | "BWHITE"Tanggal_berakhir"WHITE" ");
    printf("| "BWHITE"ID_kredensial"WHITE" ");
    for(int i = 1; i <= maxCred && i <= maxCred - 13; i++){
        printf(" ");
    }
    printf("| "BWHITE"Url"WHITE" ");
    for(int i = 1; i <= maxUrl && i <= maxUrl - 3; i++){
        printf(" ");
    }
    printf("| "BWHITE"Tanggal_dibuat"WHITE"      | "BWHITE"Tanggal_diubah"WHITE"      |\n");
    printf("+--------+-");
    for(int i = 1; i <= maxCerName || i <= 4; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxOrgName || i <= 10; i++){
        printf("-");
    }
    printf("-+-----------------+------------------+-");
    for(int i = 1; i <= maxCred || i <= 13; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxUrl || i <= 3; i++){
        printf("-");
    }
    printf("-+---------------------+---------------------+\n");
    
    bool isError = false; // jika ada nilai foreign yang tidak valid
    // body table
    for(int i = 0; i < cerSum; i++){
        char cerName[50];   // nama kategori jika ditemukan
        int j = 0;          // iterasi
        bool found = false; // kondisi berhenti
        // proses pencarian foreign key
        do{
            if(strcmp(cerData[i].issuerId, orgData[j].id) == 0){
                strcpy(cerName, orgData[j].name);
                found = true;
            }
            j++;
        } while(j < orgSum && !found);

        int lenMaxID = 6, lenMaxDate = 15;
        // ID
        printf("| %s ", cerData[i].id);
        for(int j = strlen(cerData[i].id); j < lenMaxID; j++){
            printf(" ");
        }
        // NAMA
        int nameLen = 4;
        if(maxCerName > nameLen){
            nameLen = maxCerName;
        }
        printf("| %s ", cerData[i].name);
        for(int j = strlen(cerData[i].name); j < nameLen; j++){
            printf(" ");
        }
        // ORGANISASI
        int issuerLen = 10;
        if(maxOrgName > issuerLen){
            issuerLen = maxOrgName;
        }
        if(found){
            printf("| %s ", cerName);
            for(int j = strlen(cerName); j < issuerLen; j++){
                printf(" ");
            }
        } else {
            printf("| %s ", cerData[i].issuerId);
            for(int j = strlen(cerData[i].issuerId); j < issuerLen; j++){
                printf(" ");
            }
            isError = true;
        }
        // TANGGAL DIMULAI
        int lenMaxStartDate = 15;
        printf("| %s ", cerData[i].startDate);
        for(int j = strlen(cerData[i].startDate); j < lenMaxStartDate; j++){
            printf(" ");
        }
        // TANGGAL BERAKHIR
        printf("| %s ", cerData[i].endDate);
        int lenMaxEndDate = 16;
        for(int j = strlen(cerData[i].endDate); j < lenMaxEndDate; j++){
            printf(" ");
        }
        // KREDENSIAL
        int credLen = 13;
        if(maxCred > credLen){
            credLen = maxCred;
        }
        printf("| %s ", cerData[i].url);
        for(int j = strlen(cerData[i].url); j < credLen; j++){
            printf(" ");
        }
        // URL
        int urlLen = 3;
        if(maxUrl > urlLen){
            urlLen = maxUrl;
        }
        printf("| %s ", cerData[i].url);
        for(int j = strlen(cerData[i].url); j < urlLen; j++){
            printf(" ");
        }
        // TANGGAL DIBUAT & DIUBAH
        printf("| %s | %s |\n", cerData[i].createdAt, cerData[i].updatedAt);
    }
    
    // footer table
    printf("+--------+-");
    for(int i = 1; i <= maxCerName || i <= 4; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxOrgName || i <= 10; i++){
        printf("-");
    }
    printf("-+-----------------+------------------+-");
    for(int i = 1; i <= maxCred || i <= 13; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxUrl || i <= 3; i++){
        printf("-");
    }
    printf("-+---------------------+---------------------+\n"DEFAULT);

    if(isError){
        error(27);
    }
}
// tabel gabungan organisasi, posisi, dan pengalaman
void showOrganizationPositionExperience(int maxOrgName, int maxPosName, int expSum, int orgSum, int posSum, experience* expData, organization* orgData, position* posData){
    // header table
    printf(WHITE"+--------+-");
    for(int i = 1; i <= maxOrgName || i <= 10; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxPosName || i <= 6; i++){
        printf("-");
    }
    printf("-+-----------------+------------------+---------------------+---------------------+\n");
    printf("| "BWHITE"ID"WHITE"     | "BWHITE"Organisasi"WHITE" ");
    for(int i = 1; i <= maxOrgName && i <= maxOrgName - 10; i++){
        printf(" ");
    }
    printf("| "BWHITE"Posisi"WHITE" ");
    for(int i = 1; i <= maxPosName && i <= maxPosName - 6; i++){
        printf(" ");
    }
    printf("| "BWHITE"Tanggal_dimulai"WHITE" | "BWHITE"Tanggal_berakhir"WHITE" | "BWHITE"Tanggal_dibuat"WHITE"      | "BWHITE"Tanggal_diubah"WHITE"      |\n");
    printf("+--------+-");
    for(int i = 1; i <= maxOrgName || i <= 10; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxPosName || i <= 6; i++){
        printf("-");
    }
    printf("-+-----------------+------------------+---------------------+---------------------+\n");

    bool isError = false; // jika ada nilai id_organisasi yang tidak valid
    // body table
    for(int i = 0; i < expSum; i++){
        char orgName[50];   // nama organisasi jika ditemukan
        int j = 0;          // iterasi
        bool foundOrg = false; // kondisi berhenti
        // proses pencarian foreign key
        do{
            if(strcmp(expData[i].organizationId, orgData[j].id) == 0){
                strcpy(orgName, orgData[j].name);
                foundOrg = true;
            }
            j++;
        } while(j < orgSum && !foundOrg);

        char posName[50];   // nama posisi jika ditemukan
        j = 0;              // iterasi
        bool foundPos = false; // kondisi berhenti
        // proses pencarian foreign key
        do{
            if(strcmp(expData[i].positionId, posData[j].id) == 0){
                strcpy(posName, posData[j].name);
                foundPos = true;
            }
            j++;
        } while(j < orgSum && !foundPos);

        int lenMaxID = 6;
        int lenMaxStartDate = 15;
        int lenMaxEndDate = 16;
        // ID
        printf("| %s ", expData[i].id);
        for(int j = strlen(expData[i].id); j < lenMaxID; j++){
            printf(" ");
        }
        // ORGANISASI
        int lenOrg = 10;
        if(maxOrgName > lenOrg){
            lenOrg = maxOrgName;
        }
        if(foundOrg){
            printf("| %s ", orgName);
            for(int j = strlen(orgName); j < lenOrg; j++){
                printf(" ");
            }
        } else {
            printf("| %s ", expData[i].organizationId);
            for(int j = strlen(expData[i].organizationId); j < lenOrg; j++){
                printf(" ");
            }
            isError = true;
        }
        // POSISI
        int lenPos = 6;
        if(maxPosName > lenPos){
            lenPos = maxPosName;
        }
        if(foundPos){
            printf("| %s ", posName);
            for(int j = strlen(posName); j < lenPos; j++){
                printf(" ");
            }
        } else {
            printf("| %s ", expData[i].positionId);
            for(int j = strlen(expData[i].positionId); j < lenPos; j++){
                printf(" ");
            }
            isError = true;
        }
        // TANGGAL DIMULAI
        printf("| %s ", expData[i].startDate);
        for(int j = strlen(expData[i].startDate); j < lenMaxStartDate; j++){
            printf(" ");
        }
        // TANGGAL BERAKHIR
        printf("| %s ", expData[i].endDate);
        for(int j = strlen(expData[i].endDate); j < lenMaxEndDate; j++){
            printf(" ");
        }
        // TANGGAL DIBUAT & DIUBAH
        printf("| %s | %s |\n", expData[i].createdAt, expData[i].updatedAt);
    }
    // footer table
    printf("+--------+-");
    for(int i = 1; i <= maxOrgName || i <= 10; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 1; i <= maxPosName || i <= 6; i++){
        printf("-");
    }
    printf("-+-----------------+------------------+---------------------+---------------------+\n"DEFAULT);

    if(isError){
        error(27);
    }
}
// tabel gabungan kategori, dan proyek
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
    
    bool isError = false; // jika ada nilai foreign yang tidak valid
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
                            searchId(temp, recordSum, search, &found, &idx, 1);
                            
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
        searchId(temp, recordSum, search, &isFound, &i, 1);
        
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

            fscanf(targetTable, "%s %s %s %d %s %s", targetRecord.id, targetRecord.positionId, targetRecord.skillId, &targetRecord.isSkilled, targetRecord.createdAt, targetRecord.updatedAt);

            bool foundTarId = false;
            if(strcmp(targetRecord.id, IDDUMMY) != 0 && strcmp(search, IDDUMMY) != 0 && strcmp(targetRecord.id, "") != 0) {
                // mencari id relasi
                while((strcmp(targetRecord.id, IDDUMMY) != 0) && (strcmp(targetRecord.positionId, search) != 0)){
                    fscanf(targetTable, "%s %s %s %d %s %s", targetRecord.id, targetRecord.positionId, targetRecord.skillId, &targetRecord.isSkilled, targetRecord.createdAt, targetRecord.updatedAt);
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
                // mencari id relasi
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
                searchId(temp, recordSum, search, &isFound, &idx, 1);
                
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

// perintah tabel skill
void getSkill(char command[]){       // menampilkan data
    int recordSum = 0;  // jumlah rekaman dalam tabel
    skill temp[MAX];    // array rekaman untuk ditampilkan
    skill record;       // rekaman saat ini untuk disalin

    FILE *skillTable;    // kaitan untuk mengakses file
    skillTable = fopen("tables/tskill.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(skillTable, "%s %s %s %s %s\n", record.id, record.name, record.proficiency, record.createdAt, record.updatedAt);

    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika ditemukan EOF atau data kosong
        error(12);
        fclose(skillTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].proficiency, record.proficiency);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(skillTable, "%s %s %s %s %s\n", record.id, record.name, record.proficiency, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(skillTable); // menutup file

        if(eop(command)){  // jika tidak melakukan pencarian
            // menampilkan data
            showSkillTable(longestName(temp, recordSum, 2), recordSum, temp);
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
                            searchId(temp, recordSum, search, &found, &idx, 2);
                            
                            if(found){  // jika data ditemukan
                                skill foundData[1];
                                foundData[0] = temp[idx];
                                showSkillTable(strlen(temp[idx].name), 1, foundData);
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
void postSkill(char command[]){      // menambahkan data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp
    
    int recordSum = 0;      // jumlah rekaman di dalam tabel
    skill temp[MAX];        // array rekaman untuk menggeserkan nilai rekaman baru
    skill record, new;      // rekaman saat ini dan rekaman yang baru
    
    FILE *skillTable;    // kaitan untuk mengakses file
    skillTable = fopen("tables/tskill.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(skillTable, "%s %s %s %s %s\n", record.id, record.name, record.proficiency, record.createdAt, record.updatedAt);

    // jika tidak ditemukan EOF dan data tidak kosong
    if(strcmp(record.id, IDDUMMY) != 0 && strcmp(record.id, "") != 0){
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].proficiency, record.proficiency);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(skillTable, "%s %s %s %s %s\n", record.id, record.name, record.proficiency, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
    }
    fclose(skillTable); // menutup file
    
    inc(command);   
    if(!eop(command)){
        if(strlen(getcw()) < sizeof(record.id)){
            strcpy(new.id, getcw());    // mengambil id masukan user
    
            inc(command);
            if(!eop(command)){
                if(strlen(getcw()) < sizeof(record.name)){
                    strcpy(new.name, getcw());  // mengambil nama masukan user

                    inc(command);
                    if(eop(command)){
                        if(strlen(getcw()) < sizeof(record.proficiency)){
                            if(strcmp(getcw(), "pemula") == 0 || strcmp(getcw(), "menengah") == 0 || strcmp(getcw(), "mahir") == 0){
                                
                                strcpy(new.proficiency, getcw());   // mengambil kecakapan masukan user
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
                                        strcpy(temp[i+1].proficiency, temp[i].proficiency);
                                        strcpy(temp[i+1].createdAt, temp[i].createdAt);
                                        strcpy(temp[i+1].updatedAt, temp[i].updatedAt);
                                    }
                                    recordSum++;
                                    strcpy(temp[0].id, new.id);
                                    strcpy(temp[0].name, new.name);
                                    strcpy(temp[0].proficiency, new.proficiency);
                                    strcpy(temp[0].createdAt, new.createdAt);
                                    strcpy(temp[0].updatedAt, new.updatedAt);
                                } else if (strcmp(new.id, temp[recordSum - 1].id) > 0){
                                    // rekaman baru di paling belakang
                                    strcpy(temp[recordSum].id, new.id);
                                    strcpy(temp[recordSum].name, new.name);
                                    strcpy(temp[recordSum].proficiency, new.proficiency);
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
                                            strcpy(temp[j+1].proficiency, temp[j].proficiency);
                                            strcpy(temp[j+1].createdAt, temp[j].createdAt);
                                            strcpy(temp[j+1].updatedAt, temp[j].updatedAt);
                                        }
                                        // memasukkan rekaman baru di posisi tengah
                                        strcpy(temp[i].id, new.id);
                                        strcpy(temp[i].name, new.name);
                                        strcpy(temp[i].proficiency, new.proficiency);
                                        strcpy(temp[i].createdAt, new.createdAt);
                                        strcpy(temp[i].updatedAt, new.updatedAt);
                                        recordSum++;
                                    }
                                }
                                if(!isDuplicate){
                                    showSkillTable(longestName(temp, recordSum, 2), recordSum, temp);
                                    success(0);
                                    // flush ke file
                                    skillTable = fopen("tables/tskill.dat", "w");
                                    for(int i = 0; i < recordSum; i++){
                                        fprintf(skillTable, "%s %s %s %s %s\n", temp[i].id, temp[i].name, temp[i].proficiency, temp[i].createdAt, temp[i].updatedAt);
                                    }
                                    fprintf(skillTable, "%s", EOFSKILL);
                                    fclose(skillTable);
                                }
                            } else {
                                error(29);
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
}
void updateSkill(char command[]){    // mengubah data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp

    int recordSum = 0;      // jumlah rekaman di dalam tabel
    skill temp[MAX];        // array rekaman untuk menggeserkan nilai rekaman baru
    skill record, new;      // rekaman saat ini dan rekaman yang baru

    FILE *skillTable;    // kaitan untuk mengakses file
    skillTable = fopen("tables/tskill.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(skillTable, "%s %s %s %s %s\n", record.id, record.name, record.proficiency, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(skillTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].proficiency, record.proficiency);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(skillTable, "%s %s %s %s %s\n", record.id, record.name, record.proficiency, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
        
        fclose(skillTable); // menutup file
        
        inc(command);
        char search[50]; // cari nilai id
        strcpy(search, getcw()); // mengambil id masukan user
        
        int i = 0;  // iterasi dan index
        bool isFound = false;   // cek ditemukan
        // proses pencarian
        searchId(temp, recordSum, search, &isFound, &i, 2);
        
        if(!isFound){
            error(11);
        } else {
            if(!eop(command)){
                inc(command);
                if(!eop(command)){
                    if(strlen(getcw()) < sizeof(record.name)){
                        strcpy(new.name, getcw());          // mengambil nama masukan user

                        inc(command);
                        if(eop(command)){
                            if(strlen(getcw()) < sizeof(record.proficiency)){
                                if(strcmp(getcw(), "pemula") == 0 || strcmp(getcw(), "menengah") == 0 || strcmp(getcw(), "mahir") == 0){
                                    strcpy(new.proficiency, getcw());   // mengambil kecakapan masukan user
                                    strcpy(new.updatedAt, dateTime);    // mengubah tanggal diubah
                                    
                                    // mengubah menjadi nilai baru
                                    strcpy(temp[i].name, new.name);
                                    strcpy(temp[i].proficiency, new.proficiency);
                                    strcpy(temp[i].updatedAt, new.updatedAt);
                
                                    showSkillTable(longestName(temp, recordSum, 2), recordSum, temp);
                                    success(1);
                                } else {
                                    error(29);
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
                error(13);
            }
        }
        // flush ke file
        skillTable = fopen("tables/tskill.dat", "w");
        for(int i = 0; i < recordSum; i++){
            fprintf(skillTable, "%s %s %s %s %s\n", temp[i].id, temp[i].name, temp[i].proficiency, temp[i].createdAt, temp[i].updatedAt);
        }
        fprintf(skillTable, "%s", EOFSKILL);
        fclose(skillTable);   
    }
}
void deleteSkill(char command[]){    // menghapus data
    int recordSum = 0;   // jumlah rekaman di dalam tabel
    skill temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
    skill record, new;   // rekaman saat ini dan rekaman yang baru

    FILE *skillTable;    // kaitan untuk mengakses file
    skillTable = fopen("tables/tskill.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(skillTable, "%s %s %s %s %s\n", record.id, record.name, record.proficiency, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(skillTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].proficiency, record.proficiency);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(skillTable, "%s %s %s %s %s\n", record.id, record.name, record.proficiency, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(skillTable); // menutup file
        
        inc(command);
        char search[50]; // cari nilai id
        strcpy(search, getcw()); // mengambil id masukan user
        
        if(eop(command)){
            target targetRecord;

            FILE *targetTable;
            targetTable = fopen("tables/ttarget.dat", "r");

            fscanf(targetTable, "%s %s %s %d %s %s", targetRecord.id, targetRecord.positionId, targetRecord.skillId, &targetRecord.isSkilled, targetRecord.createdAt, targetRecord.updatedAt);

            bool foundTarId = false;
            if(strcmp(targetRecord.id, IDDUMMY) != 0 && strcmp(search, IDDUMMY) != 0 && strcmp(targetRecord.id, "") != 0) {
                // mencari id relasi
                while((strcmp(targetRecord.id, IDDUMMY) != 0) && (strcmp(targetRecord.positionId, search) != 0)){
                    fscanf(targetTable, "%s %s %s %d %s %s", targetRecord.id, targetRecord.positionId, targetRecord.skillId, &targetRecord.isSkilled, targetRecord.createdAt, targetRecord.updatedAt);
                }
                if(strcmp(targetRecord.positionId, search) == 0){
                    foundTarId = true;
                }
            }
            fclose(targetTable);

            if(!foundTarId){
                int idx = 0;    // iterasi dan index
                bool isFound = false;   // cek ditemukan
                // proses pencarian 
                searchId(temp, recordSum, search, &isFound, &idx, 2);
                
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
                            strcpy(temp[i].proficiency, temp[i+1].proficiency);
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
                            strcpy(temp[j].proficiency, temp[j+1].proficiency);
                            strcpy(temp[j].createdAt, temp[j+1].createdAt);
                            strcpy(temp[j].updatedAt, temp[j+1].updatedAt);
                        }
                        recordSum--;
                    }
                    showSkillTable(longestName(temp, recordSum, 2), recordSum, temp);
                    success(2);
                }
                // flush ke file
                skillTable = fopen("tables/tskill.dat", "w");
                for(int i = 0; i < recordSum; i++){
                    fprintf(skillTable, "%s %s %s %s %s\n", temp[i].id, temp[i].name, temp[i].proficiency, temp[i].createdAt, temp[i].updatedAt);
                }
                fprintf(skillTable, "%s", EOFSKILL);
                fclose(skillTable);
            } else {
                error(24);
            }
        } else {
            error(14);
        }
    }
}
void guideSkill(){                   // buku panduan skill
    guideTitle();

    printf("|                                                                                                    |\n");
    printf("|   "WHITE"Tabel skill digunakan untuk menyimpan data skill yang dimiliki dan relasi skill dalam tabel"CYAN"      |\n");
    printf("|   "WHITE"target"CYAN"                                                                                           |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"STRUKTUR DATA"CYAN"                                                                                    |\n");
    printf("|      "WHITE"1. id              : "CYAN"Kode unik                                                                |\n");
    printf("|      "WHITE"2. nama            : "CYAN"Nama skill                                                               |\n");
    printf("|      "WHITE"2. kecakapan       : "CYAN"Level penguasaan skill (pemula, menengah, mahir)                         |\n");
    printf("|      "WHITE"3. tanggal_dibuat  : "CYAN"Waktu data dibuat                                                        |\n");
    printf("|      "WHITE"4. tanggal_diubah  : "CYAN"Waktu data diubah                                                        |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"PENGGUNAAN PERINTAH"CYAN"                                                                              |\n");
    printf("|      "WHITE"1. Menampilkan data      : "BPURPLE"PRESENT FROM "BLUE"tskill"YELLOW"$"CYAN"                                               |\n");
    printf("|      "WHITE"2. Mencari data          : "BPURPLE"PRESENT FROM"BLUE" tskill "BPURPLE"WHERE"CYAN" id"YELLOW"$"CYAN"                                      |\n");
    printf("|      "WHITE"3. Menambahkan data      : "BPURPLE"SUBMIT TO "BLUE"tskill "CYAN"id nama kecakapan"YELLOW"$"CYAN"                                |\n");
    printf("|      "WHITE"4. Mengubah data         : "BPURPLE"CHANGE "BLUE"tskill "CYAN"id nama kecakapan"YELLOW"$"CYAN"                                   |\n");
    printf("|      "WHITE"5. Menghapus data        : "BPURPLE"REMOVE FROM "BLUE"tskill "CYAN"id"YELLOW"$"CYAN"                                             |\n");
    printf("|      "WHITE"6. Menggabungkan tabel   : "BPURPLE"JOIN ON "BLUE"tskill tposition ttarget"YELLOW"$"CYAN"                                  |\n");
    printf("|                                                                                                    |\n");

    guideFooter();
}

// perintah tabel target
void getTarget(char command[]){       // menampilkan data
    int recordSum = 0;  // jumlah rekaman dalam tabel
    target temp[MAX];   // array rekaman untuk ditampilkan
    target record;      // rekaman saat ini untuk disalin

    FILE *targetTable;    // kaitan untuk mengakses file
    targetTable = fopen("tables/ttarget.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(targetTable, "%s %s %s %d %s %s\n", record.id, record.positionId, record.skillId, &record.isSkilled, record.createdAt, record.updatedAt);

    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika ditemukan EOF atau data kosong
        error(12);
        fclose(targetTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].positionId, record.positionId);
            strcpy(temp[recordSum].skillId, record.skillId);
            temp[recordSum].isSkilled = record.isSkilled;
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(targetTable, "%s %s %s %d %s %s\n", record.id, record.positionId, record.skillId, &record.isSkilled, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(targetTable); // menutup file

        if(eop(command)){  // jika tidak melakukan pencarian
            // menampilkan data
            showTargetTable(recordSum, temp);
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
                            searchId(temp, recordSum, search, &found, &idx, 3);
                            
                            if(found){  // jika data ditemukan
                                target foundData[1];
                                foundData[0] = temp[idx];
                                showTargetTable(1, foundData);
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
void postTarget(char command[]){      // menambahkan data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp
    
    int recordSum = 0;      // jumlah rekaman di dalam tabel
    target temp[MAX];       // array rekaman untuk menggeserkan nilai rekaman baru
    target record, new;     // rekaman saat ini dan rekaman yang baru
    
    FILE *targetTable;    // kaitan untuk mengakses file
    targetTable = fopen("tables/ttarget.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(targetTable, "%s %s %s %d %s %s\n", record.id, record.positionId, record.skillId, &record.isSkilled, record.createdAt, record.updatedAt);

    // jika tidak ditemukan EOF dan data tidak kosong
    if(strcmp(record.id, IDDUMMY) != 0 && strcmp(record.id, "") != 0){
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].positionId, record.positionId);
            strcpy(temp[recordSum].skillId, record.skillId);
            temp[recordSum].isSkilled = record.isSkilled;
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(targetTable, "%s %s %s %d %s %s\n", record.id, record.positionId, record.skillId, &record.isSkilled, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
    }
    fclose(targetTable); // menutup file
    
    inc(command);   
    if(!eop(command)){
        if(strlen(getcw()) < sizeof(record.id)){
            strcpy(new.id, getcw());    // mengambil id masukan user
    
            inc(command);
            if(!eop(command)){
                if(strlen(getcw()) < sizeof(record.positionId)){

                    position positionRecord;
                    FILE *positionTable;
                    positionTable = fopen("tables/tposition.dat", "r");

                    char searchPosition[10];
                    strcpy(searchPosition, getcw());

                    fscanf(positionTable, "%s %s %s %s", positionRecord.id, positionRecord.name, positionRecord.createdAt, positionRecord.updatedAt);

                    bool foundPosId = false;
                    if(strcmp(positionRecord.id, IDDUMMY) == 0){
                        error(12);
                    } else if (strcmp(searchPosition, IDDUMMY) == 0){
                        error(11);
                    } else {
                        // mencari id relasi
                        while((strcmp(positionRecord.id, IDDUMMY) != 0) && (strcmp(positionRecord.id, searchPosition) != 0)){
                            fscanf(positionTable, "%s %s %s %s\n", positionRecord.id, positionRecord.name, positionRecord.createdAt, positionRecord.updatedAt);
                        }
                        if(strcmp(positionRecord.id, searchPosition) == 0){
                            foundPosId = true;
                        } else {
                            error(23);
                        }
                    }
                    fclose(positionTable);

                    if(foundPosId){
                        strcpy(new.positionId, getcw());  // mengambil posisi masukan user
    
                        inc(command);
                        if(!eop(command)){
                            if(strlen(getcw()) < sizeof(record.skillId)){
                                
                                skill skillRecord;
                                FILE *skillTable;
                                skillTable = fopen("tables/tskill.dat", "r");

                                char searchPosition[10];
                                strcpy(searchPosition, getcw());

                                fscanf(skillTable, "%s %s %s %s %s", skillRecord.id, skillRecord.name, skillRecord.proficiency, skillRecord.createdAt, skillRecord.updatedAt);

                                bool foundSklId = false;
                                if(strcmp(skillRecord.id, IDDUMMY) == 0){
                                    error(12);
                                } else if (strcmp(searchPosition, IDDUMMY) == 0){
                                    error(11);
                                } else {
                                    // mencari id relasi
                                    while((strcmp(skillRecord.id, IDDUMMY) != 0) && (strcmp(skillRecord.id, searchPosition) != 0)){
                                        fscanf(skillTable, "%s %s %s %s %s\n", skillRecord.id, skillRecord.name, skillRecord.proficiency, skillRecord.createdAt, skillRecord.updatedAt);
                                    }
                                    if(strcmp(skillRecord.id, searchPosition) == 0){
                                        foundSklId = true;
                                    } else {
                                        error(23);
                                    }
                                }
                                fclose(skillTable);

                                if(foundSklId){
                                    strcpy(new.skillId, getcw());
        
                                    inc(command);
                                    if(eop(command)){
                                        if(strcmp(getcw(), "0") == 0 || strcmp(getcw(), "1") == 0){
                                            sscanf(getcw(), "%d", &new.isSkilled);  // mengambil skill masukan user
    
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
                                                    strcpy(temp[i+1].positionId, temp[i].positionId);
                                                    strcpy(temp[i+1].skillId, temp[i].skillId);
                                                    temp[i+1].isSkilled = temp[i].isSkilled;
                                                    strcpy(temp[i+1].createdAt, temp[i].createdAt);
                                                    strcpy(temp[i+1].updatedAt, temp[i].updatedAt);
                                                }
                                                recordSum++;
                                                strcpy(temp[0].id, new.id);
                                                strcpy(temp[0].positionId, new.positionId);
                                                strcpy(temp[0].skillId, new.skillId);
                                                temp[0].isSkilled = new.isSkilled;
                                                strcpy(temp[0].createdAt, new.createdAt);
                                                strcpy(temp[0].updatedAt, new.updatedAt);
                                            } else if (strcmp(new.id, temp[recordSum - 1].id) > 0){
                                                // rekaman baru di paling belakang
                                                strcpy(temp[recordSum].id, new.id);
                                                strcpy(temp[recordSum].positionId, new.positionId);
                                                strcpy(temp[recordSum].skillId, new.skillId);
                                                temp[recordSum].isSkilled = new.isSkilled;
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
                                                        strcpy(temp[j+1].positionId, temp[j].positionId);
                                                        strcpy(temp[j+1].skillId, temp[j].skillId);
                                                        temp[j+1].isSkilled = temp[j].isSkilled;
                                                        strcpy(temp[j+1].createdAt, temp[j].createdAt);
                                                        strcpy(temp[j+1].updatedAt, temp[j].updatedAt);
                                                    }
                                                    // memasukkan rekaman baru di posisi tengah
                                                    strcpy(temp[i].id, new.id);
                                                    strcpy(temp[i].positionId, new.positionId);
                                                    strcpy(temp[i].skillId, new.skillId);
                                                    temp[i].isSkilled = new.isSkilled;
                                                    strcpy(temp[i].createdAt, new.createdAt);
                                                    strcpy(temp[i].updatedAt, new.updatedAt);
                                                    recordSum++;
                                                }
                                            }
                                            if(!isDuplicate){
                                                showTargetTable(recordSum, temp);
                                                success(0);
                                                // flush ke file
                                                targetTable = fopen("tables/ttarget.dat", "w");
                                                for(int i = 0; i < recordSum; i++){
                                                    fprintf(targetTable, "%s %s %s %d %s %s\n", temp[i].id, temp[i].positionId, temp[i].skillId, temp[i].isSkilled, temp[i].createdAt, temp[i].updatedAt);
                                                }
                                                fprintf(targetTable, "%s", EOFTARGET);
                                                fclose(targetTable);
                                            }
                                        } else {
                                            error(30);
                                        }
                                    } else {
                                        error(6);
                                    }
                                }
                            } else {
                                error(16);
                            }
                        } else {
                            error(4);
                        }
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
void updateTarget(char command[]){    // mengubah data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp

    int recordSum = 0;    // jumlah rekaman di dalam tabel
    target temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
    target record, new;   // rekaman saat ini dan rekaman yang baru

    FILE *targetTable;    // kaitan untuk mengakses file
    targetTable = fopen("tables/ttarget.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(targetTable, "%s %s %s %d %s %s\n", record.id, record.positionId, record.skillId, &record.isSkilled, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(targetTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].positionId, record.positionId);
            strcpy(temp[recordSum].skillId, record.skillId);
            temp[recordSum].isSkilled = record.isSkilled;
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(targetTable, "%s %s %s %d %s %s\n", record.id, record.positionId, record.skillId, &record.isSkilled, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
        
        fclose(targetTable); // menutup file
        
        inc(command);
        char search[50]; // cari nilai id
        strcpy(search, getcw()); // mengambil id masukan user
        
        int i = 0;  // iterasi dan index
        bool isFound = false;   // cek ditemukan
        // proses pencarian
        searchId(temp, recordSum, search, &isFound, &i, 3);
        
        if(!isFound){
            error(11);
        } else {
            if(!eop(command)){
                inc(command);
                if(!eop(command)){
                    if(strlen(getcw()) < sizeof(record.positionId)){
                        position positionRecord;

                        FILE *positionTable;
                        positionTable = fopen("tables/tposition.dat", "r");

                        char search[10];
                        strcpy(search, getcw());

                        fscanf(positionTable, "%s %s %s %s", positionRecord.id, positionRecord.name, positionRecord.createdAt, positionRecord.updatedAt);

                        bool foundPosId = false;
                        if(strcmp(positionRecord.id, IDDUMMY) == 0){
                            error(12);
                        } else if (strcmp(search, IDDUMMY) == 0){
                            error(11);
                        } else {
                            // mencari id relasi
                            while((strcmp(positionRecord.id, IDDUMMY) != 0) && (strcmp(positionRecord.id, search) != 0)){
                                fscanf(positionTable, "%s %s %s %s\n", positionRecord.id, positionRecord.name, positionRecord.createdAt, positionRecord.updatedAt);
                            }
                            if(strcmp(positionRecord.id, search) == 0){
                                foundPosId = true;
                            }
                        }
                        fclose(positionTable);

                        if(foundPosId){
                            strcpy(new.positionId, getcw());          // mengambil id posisi masukan user
    
                            inc(command);
                            if(!eop(command)){
                                if(strlen(getcw()) < sizeof(record.skillId)){
                                    skill skillRecord;

                                    FILE *skillTable;
                                    skillTable = fopen("tables/tskill.dat", "r");

                                    char search[10];
                                    strcpy(search, getcw());

                                    fscanf(skillTable, "%s %s %s %s %s", skillRecord.id, skillRecord.name, skillRecord.proficiency, skillRecord.createdAt, skillRecord.updatedAt);

                                    bool foundSklId = false;
                                    if(strcmp(skillRecord.id, IDDUMMY) == 0){
                                        error(12);
                                    } else if (strcmp(search, IDDUMMY) == 0){
                                        error(11);
                                    } else {
                                        while((strcmp(skillRecord.id, IDDUMMY) != 0) && (strcmp(skillRecord.id, search) != 0)){
                                            fscanf(skillTable, "%s %s %s %s %s\n", skillRecord.id, skillRecord.name, skillRecord.proficiency, skillRecord.createdAt, skillRecord.updatedAt);
                                        }
                                        if(strcmp(skillRecord.id, search) == 0){
                                            foundSklId = true;
                                        }
                                    }
                                    fclose(skillTable);

                                    if(foundSklId){
                                        strcpy(new.skillId, getcw());
        
                                        inc(command);
                                        if(eop(command)){
                                            if(strcmp(getcw(), "0") == 0 || strcmp(getcw(), "1") == 0){
                                                sscanf(getcw(), "%d", &new.isSkilled);  // mengambil id skill masukan user
                                                strcpy(new.updatedAt, dateTime);        // mengubah tanggal diubah
            
                                                // mengubah menjadi nilai baru
                                                strcpy(temp[i].positionId, new.positionId);
                                                strcpy(temp[i].skillId, new.skillId);
                                                temp[i].isSkilled = new.isSkilled;
                                                strcpy(temp[i].updatedAt, new.updatedAt);
                            
                                                showTargetTable(recordSum, temp);
                                                success(1);
                                            } else {
                                                error(30);
                                            }
                                        } else {
                                            error(6);
                                        }
                                    } else {
                                        error(23);
                                    }
                                } else {
                                    error(16);
                                }
                            } else {
                                error(4);
                            }
                        } else {
                            error(23);
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
        targetTable = fopen("tables/ttarget.dat", "w");
        for(int i = 0; i < recordSum; i++){
            fprintf(targetTable, "%s %s %s %d %s %s\n", temp[i].id, temp[i].positionId, temp[i].skillId, temp[i].isSkilled, temp[i].createdAt, temp[i].updatedAt);
        }
        fprintf(targetTable, "%s", EOFTARGET);
        fclose(targetTable);   
    }
}
void deleteTarget(char command[]){    // menghapus data
    int recordSum = 0;      // jumlah rekaman di dalam tabel
    target temp[MAX];      // array rekaman untuk menggeserkan nilai rekaman baru
    target record, new;    // rekaman saat ini dan rekaman yang baru

    FILE *targetTable;    // kaitan untuk mengakses file
    targetTable = fopen("tables/ttarget.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(targetTable, "%s %s %s %d %s %s\n", record.id, record.positionId, record.skillId, &record.isSkilled, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(targetTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].positionId, record.positionId);
            strcpy(temp[recordSum].skillId, record.skillId);
            temp[recordSum].isSkilled = record.isSkilled;
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(targetTable, "%s %s %s %d %s %s\n", record.id, record.positionId, record.skillId, &record.isSkilled, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(targetTable); // menutup file
        
        inc(command);
        char search[50]; // cari nilai id
        strcpy(search, getcw()); // mengambil id masukan user
        
        if(eop(command)){
            int idx = 0;    // iterasi dan index
            bool isFound = false;   // cek ditemukan
            // proses pencarian 
            searchId(temp, recordSum, search, &isFound, &idx, 3);
            
            if(!isFound){
                error(11);
            } else {
                // kondisi memasukkan ke dalam array
                if(idx == 0){
                    // rekaman dihapus di paling depan
                    // geser semua isi array ke belakang
                    for(int i = 0; i < recordSum - 1; i++){
                        strcpy(temp[i].id, temp[i+1].id);
                        strcpy(temp[i].positionId, temp[i+1].positionId);
                        strcpy(temp[i].skillId, temp[i+1].skillId);
                        temp[i].isSkilled = temp[i+1].isSkilled;
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
                        strcpy(temp[j].positionId, temp[j+1].positionId);
                        strcpy(temp[j].skillId, temp[j+1].skillId);
                        temp[j].isSkilled = temp[j+1].isSkilled;
                        strcpy(temp[j].createdAt, temp[j+1].createdAt);
                        strcpy(temp[j].updatedAt, temp[j+1].updatedAt);
                    }
                    recordSum--;
                }
                showTargetTable(recordSum, temp);
                success(2);
            }
            // flush ke file
            targetTable = fopen("tables/ttarget.dat", "w");
            for(int i = 0; i < recordSum; i++){
                fprintf(targetTable, "%s %s %s %d %s %s\n", temp[i].id, temp[i].positionId, temp[i].skillId, temp[i].isSkilled, temp[i].createdAt, temp[i].updatedAt);
            }
            fprintf(targetTable, "%s", EOFTARGET);
            fclose(targetTable);
        } else {
            error(14);
        }
    }
}
void guideTarget(){                   // buku panduan target
    guideTitle();

    printf("|                                                                                                    |\n");
    printf("|   "WHITE"Tabel target digunakan untuk menyimpan data target pekerjaan yang diincar"CYAN"                        |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"STRUKTUR DATA"CYAN"                                                                                    |\n");
    printf("|      "WHITE"1. id              : "CYAN"Kode unik                                                                |\n");
    printf("|      "WHITE"2. id_posisi       : "CYAN"Kode unik dari nama posisi                                               |\n");
    printf("|      "WHITE"3. id_skill        : "CYAN"Kode unik dari nama skill                                                |\n");
    printf("|      "WHITE"4. sudah_dikuasai  : "CYAN"Status penguasaan (0 atau 1)                                             |\n");
    printf("|      "WHITE"6. tanggal_dibuat  : "CYAN"Waktu data dibuat                                                        |\n");
    printf("|      "WHITE"7. tanggal_diubah  : "CYAN"Waktu data diubah                                                        |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"PENGGUNAAN PERINTAH"CYAN"                                                                              |\n");
    printf("|      "WHITE"1. Menampilkan data      : "BPURPLE"PRESENT FROM "BLUE"ttarget"YELLOW"$"CYAN"                                              |\n");
    printf("|      "WHITE"2. Mencari data          : "BPURPLE"PRESENT FROM"BLUE" ttarget "BPURPLE"WHERE"CYAN" id"YELLOW"$"CYAN"                                     |\n");
    printf("|      "WHITE"3. Menambahkan data      : "BPURPLE"SUBMIT TO "BLUE"ttarget "CYAN"id id_posisi id_skill sudah_dikuasai"YELLOW"$"CYAN"            |\n");
    printf("|      "WHITE"4. Mengubah data         : "BPURPLE"CHANGE "BLUE"ttarget "CYAN"id id_posisi id_skill sudah_dikuasai"YELLOW"$"CYAN"               |\n");
    printf("|      "WHITE"5. Menghapus data        : "BPURPLE"REMOVE FROM "BLUE"ttarget "CYAN"id"YELLOW"$"CYAN"                                            |\n");
    printf("|      "WHITE"6. Menggabungkan tabel   : "BPURPLE"JOIN ON "BLUE"ttarget tposition tskill"YELLOW"$"CYAN"                                  |\n");
    printf("|                                                                                                    |\n");

    guideFooter();
}

// perintah tabel organisasi
void getOrganization(char command[]){       // menampilkan data
    int recordSum = 0;       // jumlah rekaman dalam tabel
    organization temp[MAX];  // array rekaman untuk ditampilkan
    organization record;     // rekaman saat ini untuk disalin

    FILE *organizationTable;    // kaitan untuk mengakses file
    organizationTable = fopen("tables/torganization.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(organizationTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);

    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika ditemukan EOF atau data kosong
        error(12);
        fclose(organizationTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(organizationTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(organizationTable); // menutup file

        if(eop(command)){  // jika tidak melakukan pencarian
            // menampilkan data
            showOrganizationTable(longestName(temp, recordSum, 4), recordSum, temp);
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
                            searchId(temp, recordSum, search, &found, &idx, 4);
                            
                            if(found){  // jika data ditemukan
                                organization foundData[1];
                                foundData[0] = temp[idx];
                                showOrganizationTable(strlen(temp[idx].name), 1, foundData);
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
void postOrganization(char command[]){      // menambahkan data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp
    
    int recordSum = 0;          // jumlah rekaman di dalam tabel
    organization temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
    organization record, new;   // rekaman saat ini dan rekaman yang baru
    
    FILE *organizationTable;    // kaitan untuk mengakses file
    organizationTable = fopen("tables/torganization.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(organizationTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);

    // jika tidak ditemukan EOF dan data tidak kosong
    if(strcmp(record.id, IDDUMMY) != 0 && strcmp(record.id, "") != 0){
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(organizationTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
    }
    fclose(organizationTable); // menutup file
    
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
                        showOrganizationTable(longestName(temp, recordSum, 4), recordSum, temp);
                        success(0);
                        // flush ke file
                        organizationTable = fopen("tables/torganization.dat", "w");
                        for(int i = 0; i < recordSum; i++){
                            fprintf(organizationTable, "%s %s %s %s\n", temp[i].id, temp[i].name, temp[i].createdAt, temp[i].updatedAt);
                        }
                        fprintf(organizationTable, "%s", EOFORGANIZATION);
                        fclose(organizationTable);
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
void updateOrganization(char command[]){    // mengubah data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp

    int recordSum = 0;          // jumlah rekaman di dalam tabel
    organization temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
    organization record, new;   // rekaman saat ini dan rekaman yang baru

    FILE *organizationTable;    // kaitan untuk mengakses file
    organizationTable = fopen("tables/torganization.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(organizationTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(organizationTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(organizationTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
        
        fclose(organizationTable); // menutup file
        
        inc(command);
        char search[50]; // cari nilai id
        strcpy(search, getcw()); // mengambil id masukan user
        
        int i = 0;  // iterasi dan index
        bool isFound = false;   // cek ditemukan
        // proses pencarian
        searchId(temp, recordSum, search, &isFound, &i, 4);
        
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
    
                        showOrganizationTable(longestName(temp, recordSum, 4), recordSum, temp);
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
        organizationTable = fopen("tables/torganization.dat", "w");
        for(int i = 0; i < recordSum; i++){
            fprintf(organizationTable, "%s %s %s %s\n", temp[i].id, temp[i].name, temp[i].createdAt, temp[i].updatedAt);
        }
        fprintf(organizationTable, "%s", EOFORGANIZATION);
        fclose(organizationTable);   
    }
}
void deleteOrganization(char command[]){    // menghapus data
    int recordSum = 0;          // jumlah rekaman di dalam tabel
    organization temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
    organization record, new;   // rekaman saat ini dan rekaman yang baru

    FILE *organizationTable;    // kaitan untuk mengakses file
    organizationTable = fopen("tables/torganization.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(organizationTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(organizationTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(organizationTable, "%s %s %s %s\n", record.id, record.name, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(organizationTable); // menutup file
        
        inc(command);
        char search[50]; // cari nilai id
        strcpy(search, getcw()); // mengambil id masukan user
        
        if(eop(command)){
            certificate certificateRecord;

            FILE *certificateTable;
            certificateTable = fopen("tables/tcertificate.dat", "r");

            fscanf(certificateTable, "%s %s %s %s %s %s %s %s %s", certificateRecord.id, certificateRecord.name, certificateRecord.issuerId, certificateRecord.startDate, certificateRecord.endDate, certificateRecord.credentialId, certificateRecord.url, certificateRecord.createdAt, certificateRecord.updatedAt);

            bool foundCerId = false;
            if(strcmp(certificateRecord.id, IDDUMMY) != 0 && strcmp(search, IDDUMMY) != 0 && strcmp(certificateRecord.id, "") != 0) {
                // mencari id relasi
                while((strcmp(certificateRecord.id, IDDUMMY) != 0) && (strcmp(certificateRecord.issuerId, search) != 0)){
                    fscanf(certificateTable, "%s %s %s %s %s %s %s %s %s", certificateRecord.id, certificateRecord.name, certificateRecord.issuerId, certificateRecord.startDate, certificateRecord.endDate, certificateRecord.credentialId, certificateRecord.url, certificateRecord.createdAt, certificateRecord.updatedAt);
                }
                if(strcmp(certificateRecord.issuerId, search) == 0){
                    foundCerId = true;
                }
            }
            fclose(certificateTable);
            
            experience experienceRecord;

            FILE *experienceTable;
            experienceTable = fopen("tables/texperience.dat", "r");

            fscanf(experienceTable, "%s %s %s %s %s %s %s", experienceRecord.id, experienceRecord.organizationId, experienceRecord.organizationId, experienceRecord.startDate, experienceRecord.endDate, experienceRecord.createdAt, experienceRecord.updatedAt);

            bool foundExpId = false;
            if(strcmp(experienceRecord.id, IDDUMMY) != 0 && strcmp(search, IDDUMMY) != 0 && strcmp(experienceRecord.id, "") != 0) {
                // mencari id relasi
                while((strcmp(experienceRecord.id, IDDUMMY) != 0) && (strcmp(experienceRecord.organizationId, search) != 0)){
                    fscanf(experienceTable, "%s %s %s %s %s %s %s", experienceRecord.id, experienceRecord.organizationId, experienceRecord.organizationId, experienceRecord.startDate, experienceRecord.endDate, experienceRecord.createdAt, experienceRecord.updatedAt);
                }
                if(strcmp(experienceRecord.organizationId, search) == 0){
                    foundExpId = true;
                }
            }
            fclose(experienceTable);

            if(!foundCerId && !foundExpId){
                int idx = 0;    // iterasi dan index
                bool isFound = false;   // cek ditemukan
                // proses pencarian 
                searchId(temp, recordSum, search, &isFound, &idx, 4);
                
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
                    showOrganizationTable(longestName(temp, recordSum, 4), recordSum, temp);
                    success(2);
                }
                // flush ke file
                organizationTable = fopen("tables/torganization.dat", "w");
                for(int i = 0; i < recordSum; i++){
                    fprintf(organizationTable, "%s %s %s %s\n", temp[i].id, temp[i].name, temp[i].createdAt, temp[i].updatedAt);
                }
                fprintf(organizationTable, "%s", EOFORGANIZATION);
                fclose(organizationTable);
            } else {
                error(24);
            }
        } else {
            error(14);
        }
    }
}
void guideOrganization(){                   // buku panduan organisasi
    guideTitle();

    printf("|                                                                                                    |\n");
    printf("|   "WHITE"Tabel organisasi digunakan untuk menyimpan relasi organisasi dalam tabel sertifikat dan "CYAN"         |\n");
    printf("|   "WHITE"pengalaman"CYAN"                                                                                       |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"STRUKTUR DATA"CYAN"                                                                                    |\n");
    printf("|      "WHITE"1. id              : "CYAN"Kode unik                                                                |\n");
    printf("|      "WHITE"2. nama            : "CYAN"Nama organisasi                                                          |\n");
    printf("|      "WHITE"3. tanggal_dibuat  : "CYAN"Waktu data dibuat                                                        |\n");
    printf("|      "WHITE"4. tanggal_diubah  : "CYAN"Waktu data diubah                                                        |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"PENGGUNAAN PERINTAH"CYAN"                                                                              |\n");
    printf("|      "WHITE"1. Menampilkan data      : "BPURPLE"PRESENT FROM "BLUE"torganization"YELLOW"$"CYAN"                                        |\n");
    printf("|      "WHITE"2. Mencari data          : "BPURPLE"PRESENT FROM"BLUE" torganization "BPURPLE"WHERE"CYAN" id"YELLOW"$"CYAN"                               |\n");
    printf("|      "WHITE"3. Menambahkan data      : "BPURPLE"SUBMIT TO "BLUE"torganization "CYAN"id nama"YELLOW"$"CYAN"                                   |\n");
    printf("|      "WHITE"4. Mengubah data         : "BPURPLE"CHANGE "BLUE"torganization "CYAN"id nama"YELLOW"$"CYAN"                                      |\n");
    printf("|      "WHITE"5. Menghapus data        : "BPURPLE"REMOVE FROM "BLUE"torganization "CYAN"id"YELLOW"$"CYAN"                                      |\n");
    printf("|      "WHITE"6. Menggabungkan tabel   : "BPURPLE"JOIN ON "BLUE"torganization tcertificate"YELLOW"$"CYAN"                                |\n");
    printf("|                                 "BPURPLE"JOIN ON "BLUE"torganization texperience tposition"YELLOW"$"CYAN"                       |\n");
    printf("|                                                                                                    |\n");

    guideFooter();
}

// perintah tabel sertifikat
void getCertificate(char command[]){       // menampilkan data
    int recordSum = 0;      // jumlah rekaman dalam tabel
    certificate temp[MAX];  // array rekaman untuk ditampilkan
    certificate record;     // rekaman saat ini untuk disalin

    FILE *certificateTable;    // kaitan untuk mengakses file
    certificateTable = fopen("tables/tcertificate.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(certificateTable, "%s %s %s %s %s %s %s %s %s\n", record.id, record.name, record.issuerId, record.startDate, record.endDate, record.credentialId, record.url, record.createdAt, record.updatedAt);

    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika ditemukan EOF atau data kosong
        error(12);
        fclose(certificateTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].issuerId, record.issuerId);
            strcpy(temp[recordSum].startDate, record.startDate);
            strcpy(temp[recordSum].endDate, record.endDate);
            strcpy(temp[recordSum].credentialId, record.credentialId);
            strcpy(temp[recordSum].url, record.url);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(certificateTable, "%s %s %s %s %s %s %s %s %s\n", record.id, record.name, record.issuerId, record.startDate, record.endDate, record.credentialId, record.url, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(certificateTable); // menutup file

        if(eop(command)){  // jika tidak melakukan pencarian
            // menampilkan data
            showCertificateTable(longestName(temp, recordSum, 5), longestCredential(temp, recordSum), longestUrl(temp, recordSum, 5), recordSum, temp);
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
                            searchId(temp, recordSum, search, &found, &idx, 5);
                            
                            if(found){  // jika data ditemukan
                                certificate foundData[1];
                                foundData[0] = temp[idx];
                                showCertificateTable(strlen(temp[idx].name), strlen(temp[idx].credentialId), strlen(temp[idx].url), 1, foundData);
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
void postCertificate(char command[]){      // menambahkan data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp
    
    int recordSum = 0;          // jumlah rekaman di dalam tabel
    certificate temp[MAX];      // array rekaman untuk menggeserkan nilai rekaman baru
    certificate record, new;    // rekaman saat ini dan rekaman yang baru
    
    FILE *certificateTable;    // kaitan untuk mengakses file
    certificateTable = fopen("tables/tcertificate.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(certificateTable, "%s %s %s %s %s %s %s %s %s\n", record.id, record.name, record.issuerId, record.startDate, record.endDate, record.credentialId, record.url, record.createdAt, record.updatedAt);

    // jika tidak ditemukan EOF dan data tidak kosong
    if(strcmp(record.id, IDDUMMY) != 0 && strcmp(record.id, "") != 0){
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].issuerId, record.issuerId);
            strcpy(temp[recordSum].startDate, record.startDate);
            strcpy(temp[recordSum].endDate, record.endDate);
            strcpy(temp[recordSum].credentialId, record.credentialId);
            strcpy(temp[recordSum].url, record.url);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(certificateTable, "%s %s %s %s %s %s %s %s %s\n", record.id, record.name, record.issuerId, record.startDate, record.endDate, record.credentialId, record.url, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
    }
    fclose(certificateTable); // menutup file
    
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
                        if(strlen(getcw()) < sizeof(record.issuerId)){
                            organization organizationRecord;

                            FILE *organizationTable;
                            organizationTable = fopen("tables/torganization.dat", "r");

                            char search[10];
                            strcpy(search, getcw());

                            fscanf(organizationTable, "%s %s %s %s", organizationRecord.id, organizationRecord.name, organizationRecord.createdAt, organizationRecord.updatedAt);

                            bool foundOrgId = false;
                            if(strcmp(organizationRecord.id, IDDUMMY) == 0){
                                error(12);
                            } else if (strcmp(search, IDDUMMY) == 0){
                                error(11);
                            } else {
                                // mencari id relasi
                                while((strcmp(organizationRecord.id, IDDUMMY) != 0) && (strcmp(organizationRecord.id, search) != 0)){
                                    fscanf(organizationTable, "%s %s %s %s\n", organizationRecord.id, organizationRecord.name, organizationRecord.createdAt, organizationRecord.updatedAt);
                                }
                                if(strcmp(organizationRecord.id, search) == 0){
                                    foundOrgId = true;
                                } else {
                                    error(23);
                                }
                            }
                            fclose(organizationTable);

                            if(foundOrgId){
                                strcpy(new.issuerId, getcw());   // mengambil organisasi masukan user
    
                                inc(command);
                                if(!eop(command)){
                                    if(strlen(getcw()) < sizeof(record.startDate)){
                                        strcpy(new.startDate, getcw());  // mengambil tanggal_dimulai masukan user
    
                                        inc(command);
                                        if(!eop(command)){
                                            if(strlen(getcw()) < sizeof(record.endDate)){
                                                strcpy(new.endDate, getcw());    // mengambil tanggal_berakhir masukan user

                                                inc(command);
                                                if(!eop(command)){
                                                    if(strlen(getcw()) < sizeof(record.credentialId)){
                                                        strcpy(new.credentialId, getcw());  // mengambil kredensial id masukan user

                                                        inc(command);
                                                        if(eop(command)){
                                                            if(strlen(getcw()) < sizeof(record.url)){
                                                                strcpy(new.url, getcw());   // mengambil url masukan user

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
                                                                        strcpy(temp[i+1].issuerId, temp[i].issuerId);
                                                                        strcpy(temp[i+1].startDate, temp[i].startDate);
                                                                        strcpy(temp[i+1].endDate, temp[i].endDate);
                                                                        strcpy(temp[i+1].credentialId, temp[i].credentialId);
                                                                        strcpy(temp[i+1].url, temp[i].url);
                                                                        strcpy(temp[i+1].createdAt, temp[i].createdAt);
                                                                        strcpy(temp[i+1].updatedAt, temp[i].updatedAt);
                                                                    }
                                                                    recordSum++;
                                                                    strcpy(temp[0].id, new.id);
                                                                    strcpy(temp[0].name, new.name);
                                                                    strcpy(temp[0].issuerId, new.issuerId);
                                                                    strcpy(temp[0].startDate, new.startDate);
                                                                    strcpy(temp[0].endDate, new.endDate);
                                                                    strcpy(temp[0].credentialId, new.credentialId);
                                                                    strcpy(temp[0].url, new.url);
                                                                    strcpy(temp[0].createdAt, new.createdAt);
                                                                    strcpy(temp[0].updatedAt, new.updatedAt);
                                                                } else if (strcmp(new.id, temp[recordSum - 1].id) > 0){
                                                                    // rekaman baru di paling belakang
                                                                    strcpy(temp[recordSum].id, new.id);
                                                                    strcpy(temp[recordSum].name, new.name);
                                                                    strcpy(temp[recordSum].issuerId, new.issuerId);
                                                                    strcpy(temp[recordSum].startDate, new.startDate);
                                                                    strcpy(temp[recordSum].endDate, new.endDate);
                                                                    strcpy(temp[recordSum].credentialId, new.credentialId);
                                                                    strcpy(temp[recordSum].url, new.url);
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
                                                                            strcpy(temp[j+1].issuerId, temp[j].issuerId);
                                                                            strcpy(temp[j+1].startDate, temp[j].startDate);
                                                                            strcpy(temp[j+1].endDate, temp[j].endDate);
                                                                            strcpy(temp[j+1].credentialId, temp[j].credentialId);
                                                                            strcpy(temp[j+1].url, temp[j].url);
                                                                            strcpy(temp[j+1].createdAt, temp[j].createdAt);
                                                                            strcpy(temp[j+1].updatedAt, temp[j].updatedAt);
                                                                        }
                                                                        // memasukkan rekaman baru di posisi tengah
                                                                        strcpy(temp[i].id, new.id);
                                                                        strcpy(temp[i].name, new.name);
                                                                        strcpy(temp[i].issuerId, new.issuerId);
                                                                        strcpy(temp[i].startDate, new.startDate);
                                                                        strcpy(temp[i].endDate, new.endDate);
                                                                        strcpy(temp[i].credentialId, new.credentialId);
                                                                        strcpy(temp[i].url, new.url);
                                                                        strcpy(temp[i].createdAt, new.createdAt);
                                                                        strcpy(temp[i].updatedAt, new.updatedAt);
                                                                        recordSum++;
                                                                    }
                                                                }
                                                                if(!isDuplicate){
                                                                    showCertificateTable(longestName(temp, recordSum, 5), longestCredential(temp, recordSum), longestUrl(temp, recordSum, 5), recordSum, temp);
                                                                    success(0);
                                                                    // flush ke file
                                                                    certificateTable = fopen("tables/tcertificate.dat", "w");
                                                                    for(int i = 0; i < recordSum; i++){
                                                                        fprintf(certificateTable, "%s %s %s %s %s %s %s %s %s\n", temp[i].id, temp[i].name, temp[i].issuerId, temp[i].startDate, temp[i].endDate, temp[i].credentialId, temp[i].url, temp[i].createdAt, temp[i].updatedAt);
                                                                    }
                                                                    fprintf(certificateTable, "%s", EOFCERTIFICATE);
                                                                    fclose(certificateTable);
                                                                }
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
void updateCertificate(char command[]){    // mengubah data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp

    int recordSum = 0;          // jumlah rekaman di dalam tabel
    certificate temp[MAX];      // array rekaman untuk menggeserkan nilai rekaman baru
    certificate record, new;    // rekaman saat ini dan rekaman yang baru

    FILE *certificateTable;    // kaitan untuk mengakses file
    certificateTable = fopen("tables/tcertificate.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(certificateTable, "%s %s %s %s %s %s %s %s %s\n", record.id, record.name, record.issuerId, record.startDate, record.endDate, record.credentialId, record.url, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(certificateTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].issuerId, record.issuerId);
            strcpy(temp[recordSum].startDate, record.startDate);
            strcpy(temp[recordSum].endDate, record.endDate);
            strcpy(temp[recordSum].credentialId, record.credentialId);
            strcpy(temp[recordSum].url, record.url);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(certificateTable, "%s %s %s %s %s %s %s %s %s\n", record.id, record.name, record.issuerId, record.startDate, record.endDate, record.credentialId, record.url, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
        
        fclose(certificateTable); // menutup file
        
        inc(command);
        char search[50]; // cari nilai id
        strcpy(search, getcw()); // mengambil id masukan user
        
        int i = 0;  // iterasi dan index
        bool isFound = false;   // cek ditemukan
        // proses pencarian
        searchId(temp, recordSum, search, &isFound, &i, 5);
        
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
                            if(strlen(getcw()) < sizeof(record.issuerId)){
                                organization organizationRecord;

                                FILE *organizationTable;
                                organizationTable = fopen("tables/torganization.dat", "r");

                                char search[10];
                                strcpy(search, getcw());

                                fscanf(organizationTable, "%s %s %s %s", organizationRecord.id, organizationRecord.name, organizationRecord.createdAt, organizationRecord.updatedAt);

                                bool foundOrgId = false;
                                if(strcmp(organizationRecord.id, IDDUMMY) == 0){
                                    error(12);
                                } else if (strcmp(search, IDDUMMY) == 0){
                                    error(11);
                                } else {
                                    // mencari id relasi
                                    while((strcmp(organizationRecord.id, IDDUMMY) != 0) && (strcmp(organizationRecord.id, search) != 0)){
                                        fscanf(organizationTable, "%s %s %s %s\n", organizationRecord.id, organizationRecord.name, organizationRecord.createdAt, organizationRecord.updatedAt);
                                    }
                                    if(strcmp(organizationRecord.id, search) == 0){
                                        foundOrgId = true;
                                    } else {
                                        error(23);
                                    }
                                }
                                fclose(organizationTable);

                                if(foundOrgId){
                                    strcpy(new.issuerId, getcw());   // mengambil organisasi masukan user
    
                                    inc(command);
                                    if(!eop(command)){
                                        if(strlen(getcw()) < sizeof(record.startDate)){
                                            strcpy(new.startDate, getcw());  // mengambil tanggal_dimulai masukan user
    
                                            inc(command);
                                            if(!eop(command)){
                                                if(strlen(getcw()) < sizeof(record.endDate)){
                                                    strcpy(new.endDate, getcw());    // mengambil tanggal_berakhir masukan user

                                                    inc(command);
                                                    if(!eop(command)){
                                                        if(strlen(getcw()) < sizeof(record.credentialId)){
                                                            strcpy(new.credentialId, getcw());  // mengambil kredensial id masukan user

                                                            inc(command);
                                                            if(eop(command)){
                                                                if(strlen(getcw()) < sizeof(record.url)){
                                                                    strcpy(new.url, getcw());           // mengambil url masukan user
                                                                    strcpy(new.updatedAt, dateTime);    // mengubah tanggal diubah
                
                                                                    // mengubah menjadi nilai baru
                                                                    strcpy(temp[i].name, new.name);
                                                                    strcpy(temp[i].issuerId, new.issuerId);
                                                                    strcpy(temp[i].startDate, new.startDate);
                                                                    strcpy(temp[i].endDate, new.endDate);
                                                                    strcpy(temp[i].credentialId, new.credentialId);
                                                                    strcpy(temp[i].url, new.url);
                                                                    strcpy(temp[i].updatedAt, new.updatedAt);
                                                
                                                                    showCertificateTable(longestName(temp, recordSum, 5), longestCredential(temp, recordSum), longestUrl(temp, recordSum, 5), recordSum, temp);
                                                                    success(1);
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
        certificateTable = fopen("tables/tcertificate.dat", "w");
        for(int i = 0; i < recordSum; i++){
            fprintf(certificateTable, "%s %s %s %s %s %s %s %s %s\n", temp[i].id, temp[i].name, temp[i].issuerId, temp[i].startDate, temp[i].endDate, temp[i].credentialId, temp[i].url, temp[i].createdAt, temp[i].updatedAt);
        }
        fprintf(certificateTable, "%s", EOFCERTIFICATE);
        fclose(certificateTable);   
    }
}
void deleteCertificate(char command[]){    // menghapus data
    int recordSum = 0;          // jumlah rekaman di dalam tabel
    certificate temp[MAX];      // array rekaman untuk menggeserkan nilai rekaman baru
    certificate record, new;    // rekaman saat ini dan rekaman yang baru

    FILE *certificateTable;    // kaitan untuk mengakses file
    certificateTable = fopen("tables/tcertificate.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(certificateTable, "%s %s %s %s %s %s %s %s %s\n", record.id, record.name, record.issuerId, record.startDate, record.endDate, record.credentialId, record.url, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(certificateTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].name, record.name);
            strcpy(temp[recordSum].issuerId, record.issuerId);
            strcpy(temp[recordSum].startDate, record.startDate);
            strcpy(temp[recordSum].endDate, record.endDate);
            strcpy(temp[recordSum].credentialId, record.credentialId);
            strcpy(temp[recordSum].url, record.url);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(certificateTable, "%s %s %s %s %s %s %s %s %s\n", record.id, record.name, record.issuerId, record.startDate, record.endDate, record.credentialId, record.url, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(certificateTable); // menutup file
        
        inc(command);
        char search[50]; // cari nilai id
        strcpy(search, getcw()); // mengambil id masukan user
        
        if(eop(command)){
            int idx = 0;    // iterasi dan index
            bool isFound = false;   // cek ditemukan
            // proses pencarian 
            searchId(temp, recordSum, search, &isFound, &idx, 5);
            
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
                        strcpy(temp[i].issuerId, temp[i+1].issuerId);
                        strcpy(temp[i].startDate, temp[i+1].startDate);
                        strcpy(temp[i].endDate, temp[i+1].endDate);
                        strcpy(temp[i].credentialId, temp[i+1].credentialId);
                        strcpy(temp[i].url, temp[i+1].url);
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
                        strcpy(temp[j].issuerId, temp[j+1].issuerId);
                        strcpy(temp[j].startDate, temp[j+1].startDate);
                        strcpy(temp[j].endDate, temp[j+1].endDate);
                        strcpy(temp[j].credentialId, temp[j+1].credentialId);
                        strcpy(temp[j].url, temp[j+1].url);
                        strcpy(temp[j].createdAt, temp[j+1].createdAt);
                        strcpy(temp[j].updatedAt, temp[j+1].updatedAt);
                    }
                    recordSum--;
                }
                showCertificateTable(longestName(temp, recordSum, 5), longestCredential(temp, recordSum), longestUrl(temp, recordSum, 5), recordSum, temp);
                success(2);
            }
            // flush ke file
            certificateTable = fopen("tables/tcertificate.dat", "w");
            for(int i = 0; i < recordSum; i++){
                fprintf(certificateTable, "%s %s %s %s %s %s %s %s %s\n", temp[i].id, temp[i].name, temp[i].issuerId, temp[i].startDate, temp[i].endDate, temp[i].credentialId, temp[i].url, temp[i].createdAt, temp[i].updatedAt);
            }
            fprintf(certificateTable, "%s", EOFCERTIFICATE);
            fclose(certificateTable);
        } else {
            error(14);
        }
    }
}
void guideCertificate(){                   // buku panduan sertifikat
    guideTitle();

    printf("|                                                                                                    |\n");
    printf("|   "WHITE"Tabel sertifikat digunakan untuk menyimpan data sertifikat yang pernah diperoleh"CYAN"                 |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"STRUKTUR DATA"CYAN"                                                                                    |\n");
    printf("|      "WHITE"1. id               : "CYAN"Kode unik                                                               |\n");
    printf("|      "WHITE"2. nama             : "CYAN"Nama sertifikat                                                         |\n");
    printf("|      "WHITE"3. id_organisasi    : "CYAN"Kode unik dari nama organisasi                                          |\n");
    printf("|      "WHITE"4. tanggal_dimulai  : "CYAN"Tanggal sertifikat dimulai/diperoleh (cth. 2025_May)                    |\n");
    printf("|      "WHITE"5. tanggal_berakhir : "CYAN"Tanggal sertifikat berakhir (cth. 2035_May atau -)                      |\n");
    printf("|      "WHITE"6. kredensial       : "CYAN"Kode kredensial                                                         |\n");
    printf("|      "WHITE"7. url              : "CYAN"Url hasil sertifikat (opsional: -)                                      |\n");
    printf("|      "WHITE"8. tanggal_dibuat   : "CYAN"Waktu data dibuat                                                       |\n");
    printf("|      "WHITE"9. tanggal_diubah   : "CYAN"Waktu data diubah                                                       |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"PENGGUNAAN PERINTAH"CYAN"                                                                              |\n");
    printf("|      "WHITE"1. Menampilkan data      : "BPURPLE"PRESENT FROM "BLUE"tcertificate"YELLOW"$"CYAN"                                         |\n");
    printf("|      "WHITE"2. Mencari data          : "BPURPLE"PRESENT FROM"BLUE" tcertificate "BPURPLE"WHERE"CYAN" id"YELLOW"$"CYAN"                                |\n");
    printf("|      "WHITE"3. Menambahkan data      : "BPURPLE"SUBMIT TO "BLUE"tcertificate "CYAN"id nama id_organisasi tanggal_dimulai       |\n");
    printf("|                                                        tanggal_berakhir kredensial url"YELLOW"$"CYAN"            |\n");
    printf("|      "WHITE"4. Mengubah data         : "BPURPLE"CHANGE "BLUE"tcertificate "CYAN"id nama id_organisasi tanggal_dimulai          |\n");
    printf("|                                                     tanggal_berakhir kredensial url"YELLOW"$"CYAN"               |\n");
    printf("|      "WHITE"5. Menghapus data        : "BPURPLE"REMOVE FROM "BLUE"tcertificate "CYAN"id"YELLOW"$"CYAN"                                       |\n");
    printf("|      "WHITE"6. Menggabungkan tabel   : "BPURPLE"JOIN ON "BLUE"tcertificate torganization"YELLOW"$"CYAN"                                |\n");
    printf("|                                                                                                    |\n");

    guideFooter();
}

// perintah tabel pengalaman
void getExperience(char command[]){       // menampilkan data
    int recordSum = 0;     // jumlah rekaman dalam tabel
    experience temp[MAX];  // array rekaman untuk ditampilkan
    experience record;     // rekaman saat ini untuk disalin

    FILE *experienceTable;    // kaitan untuk mengakses file
    experienceTable = fopen("tables/texperience.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(experienceTable, "%s %s %s %s %s %s %s\n", record.id, record.organizationId, record.positionId, record.startDate, record.endDate, record.createdAt, record.updatedAt);

    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika ditemukan EOF atau data kosong
        error(12);
        fclose(experienceTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].organizationId, record.organizationId);
            strcpy(temp[recordSum].positionId, record.positionId);
            strcpy(temp[recordSum].startDate, record.startDate);
            strcpy(temp[recordSum].endDate, record.endDate);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(experienceTable, "%s %s %s %s %s %s %s\n", record.id, record.organizationId, record.positionId, record.startDate, record.endDate, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(experienceTable); // menutup file

        if(eop(command)){  // jika tidak melakukan pencarian
            // menampilkan data
            showExperienceTable(recordSum, temp);
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
                            searchId(temp, recordSum, search, &found, &idx, 6);
                            
                            if(found){  // jika data ditemukan
                                experience foundData[1];
                                foundData[0] = temp[idx];
                                showExperienceTable(1, foundData);
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
void postExperience(char command[]){      // menambahkan data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp
    
    int recordSum = 0;         // jumlah rekaman di dalam tabel
    experience temp[MAX];      // array rekaman untuk menggeserkan nilai rekaman baru
    experience record, new;    // rekaman saat ini dan rekaman yang baru
    
    FILE *experienceTable;    // kaitan untuk mengakses file
    experienceTable = fopen("tables/texperience.dat", "r"); // membuka file dengan mode read
    
    // memulai proses pembacaan
    fscanf(experienceTable, "%s %s %s %s %s %s %s\n", record.id, record.organizationId, record.positionId, record.startDate, record.endDate, record.createdAt, record.updatedAt);

    // jika tidak ditemukan EOF dan data tidak kosong
    if(strcmp(record.id, IDDUMMY) != 0 && strcmp(record.id, "") != 0){
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].organizationId, record.organizationId);
            strcpy(temp[recordSum].positionId, record.positionId);
            strcpy(temp[recordSum].startDate, record.startDate);
            strcpy(temp[recordSum].endDate, record.endDate);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(experienceTable, "%s %s %s %s %s %s %s\n", record.id, record.organizationId, record.positionId, record.startDate, record.endDate, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
    }
    fclose(experienceTable); // menutup file
    
    inc(command);   
    if(!eop(command)){
        if(strlen(getcw()) < sizeof(record.id)){
            strcpy(new.id, getcw());    // mengambil id masukan user
    
            inc(command);
            if(!eop(command)){
                if(strlen(getcw()) < sizeof(record.organizationId)){
                    organization organizationRecord;

                    FILE *organizationTable;
                    organizationTable = fopen("tables/torganization.dat", "r");

                    char search[10];
                    strcpy(search, getcw());

                    fscanf(organizationTable, "%s %s %s %s", organizationRecord.id, organizationRecord.name, organizationRecord.createdAt, organizationRecord.updatedAt);

                    bool foundOrgId = false;
                    if(strcmp(organizationRecord.id, IDDUMMY) == 0){
                        error(12);
                    } else if (strcmp(search, IDDUMMY) == 0){
                        error(11);
                    } else {
                        // mencari id relasi 
                        while((strcmp(organizationRecord.id, IDDUMMY) != 0) && (strcmp(organizationRecord.id, search) != 0)){
                            fscanf(organizationTable, "%s %s %s %s\n", organizationRecord.id, organizationRecord.name, organizationRecord.createdAt, organizationRecord.updatedAt);
                        }
                        if(strcmp(organizationRecord.id, search) == 0){
                            foundOrgId = true;
                        } else {
                            error(23);
                        }
                    }
                    fclose(organizationTable);

                    if(foundOrgId){
                        strcpy(new.organizationId, getcw());  // mengambil organisasi masukan user
    
                        inc(command);
                        if(!eop(command)){
                            if(strlen(getcw()) < sizeof(record.positionId)){
                                position positionRecord;

                                FILE *positionTable;
                                positionTable = fopen("tables/tposition.dat", "r");

                                char search[10];
                                strcpy(search, getcw());

                                fscanf(positionTable, "%s %s %s %s", positionRecord.id, positionRecord.name, positionRecord.createdAt, positionRecord.updatedAt);

                                bool foundPosId = false;
                                if(strcmp(positionRecord.id, IDDUMMY) == 0){
                                    error(12);
                                } else if (strcmp(search, IDDUMMY) == 0){
                                    error(11);
                                } else {
                                    // mencari id relasi
                                    while((strcmp(positionRecord.id, IDDUMMY) != 0) && (strcmp(positionRecord.id, search) != 0)){
                                        fscanf(positionTable, "%s %s %s %s\n", positionRecord.id, positionRecord.name, positionRecord.createdAt, positionRecord.updatedAt);
                                    }
                                    if(strcmp(positionRecord.id, search) == 0){
                                        foundPosId = true;
                                    } else {
                                        error(23);
                                    }
                                }
                                fclose(positionTable);
                    
                                if(foundPosId){
                                    strcpy(new.positionId, getcw());    // mengambil posisi masukan user
        
                                    inc(command);
                                    if(!eop(command)){
                                        if(strlen(getcw()) < sizeof(record.startDate)){
                                            strcpy(new.startDate, getcw()); // mengambil tanggal_dimulai masukan user
        
                                            inc(command);
                                            if(eop(command)){
                                                if(strlen(getcw()) < sizeof(record.endDate)){
                                                    strcpy(new.endDate, getcw());   // mengambil tanggal_berakhir masukan user
        
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
                                                            strcpy(temp[i+1].organizationId, temp[i].organizationId);
                                                            strcpy(temp[i+1].positionId, temp[i].positionId);
                                                            strcpy(temp[i+1].startDate, temp[i].startDate);
                                                            strcpy(temp[i+1].endDate, temp[i].endDate);
                                                            strcpy(temp[i+1].createdAt, temp[i].createdAt);
                                                            strcpy(temp[i+1].updatedAt, temp[i].updatedAt);
                                                        }
                                                        recordSum++;
                                                        strcpy(temp[0].id, new.id);
                                                        strcpy(temp[0].organizationId, new.organizationId);
                                                        strcpy(temp[0].positionId, new.positionId);
                                                        strcpy(temp[0].startDate, new.startDate);
                                                        strcpy(temp[0].endDate, new.endDate);
                                                        strcpy(temp[0].createdAt, new.createdAt);
                                                        strcpy(temp[0].updatedAt, new.updatedAt);
                                                    } else if (strcmp(new.id, temp[recordSum - 1].id) > 0){
                                                        // rekaman baru di paling belakang
                                                        strcpy(temp[recordSum].id, new.id);
                                                        strcpy(temp[recordSum].organizationId, new.organizationId);
                                                        strcpy(temp[recordSum].positionId, new.positionId);
                                                        strcpy(temp[recordSum].startDate, new.startDate);
                                                        strcpy(temp[recordSum].endDate, new.endDate);
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
                                                                strcpy(temp[j+1].organizationId, temp[j].organizationId);
                                                                strcpy(temp[j+1].positionId, temp[j].positionId);
                                                                strcpy(temp[j+1].startDate, temp[j].startDate);
                                                                strcpy(temp[j+1].endDate, temp[j].endDate);
                                                                strcpy(temp[j+1].createdAt, temp[j].createdAt);
                                                                strcpy(temp[j+1].updatedAt, temp[j].updatedAt);
                                                            }
                                                            // memasukkan rekaman baru di posisi tengah
                                                            strcpy(temp[i].id, new.id);
                                                            strcpy(temp[i].organizationId, new.organizationId);
                                                            strcpy(temp[i].positionId, new.positionId);
                                                            strcpy(temp[i].startDate, new.startDate);
                                                            strcpy(temp[i].endDate, new.endDate);
                                                            strcpy(temp[i].createdAt, new.createdAt);
                                                            strcpy(temp[i].updatedAt, new.updatedAt);
                                                            recordSum++;
                                                        }
                                                    }
                                                    if(!isDuplicate){
                                                        showExperienceTable(recordSum, temp);
                                                        success(0);
                                                        // flush ke file
                                                        experienceTable = fopen("tables/texperience.dat", "w");
                                                        for(int i = 0; i < recordSum; i++){
                                                            fprintf(experienceTable, "%s %s %s %s %s %s %s\n", temp[i].id, temp[i].organizationId, temp[i].positionId, temp[i].startDate, temp[i].endDate, temp[i].createdAt, temp[i].updatedAt);
                                                        }
                                                        fprintf(experienceTable, "%s", EOFEXPERIENCE);
                                                        fclose(experienceTable);
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
                            } else {
                                error(16);
                            }
                        } else {
                            error(4);
                        }
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
void updateExperience(char command[]){    // mengubah data
    char dateTime[100];     // menyimpan tanggal dan waktu saat ini
    timeStamp(dateTime);    // mengisi nilai dateTime dari fungsi timeStamp

    int recordSum = 0;        // jumlah rekaman di dalam tabel
    experience temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
    experience record, new;   // rekaman saat ini dan rekaman yang baru

    FILE *experienceTable;    // kaitan untuk mengakses file
    experienceTable = fopen("tables/texperience.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(experienceTable, "%s %s %s %s %s %s %s\n", record.id, record.organizationId, record.positionId, record.startDate, record.endDate, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(experienceTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].organizationId, record.organizationId);
            strcpy(temp[recordSum].positionId, record.positionId);
            strcpy(temp[recordSum].startDate, record.startDate);
            strcpy(temp[recordSum].endDate, record.endDate);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(experienceTable, "%s %s %s %s %s %s %s\n", record.id, record.organizationId, record.positionId, record.startDate, record.endDate, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);
        
        fclose(experienceTable); // menutup file
        
        inc(command);
        char search[50]; // cari nilai id
        strcpy(search, getcw()); // mengambil id masukan user
        
        int i = 0;  // iterasi dan index
        bool isFound = false;   // cek ditemukan
        // proses pencarian
        searchId(temp, recordSum, search, &isFound, &i, 6);
        
        if(!isFound){
            error(11);
        } else {
            if(!eop(command)){
                inc(command);
                if(!eop(command)){
                    if(strlen(getcw()) < sizeof(record.organizationId)){
                        organization organizationRecord;

                        FILE *organizationTable;
                        organizationTable = fopen("tables/torganization.dat", "r");

                        char search[10];
                        strcpy(search, getcw());

                        fscanf(organizationTable, "%s %s %s %s", organizationRecord.id, organizationRecord.name, organizationRecord.createdAt, organizationRecord.updatedAt);

                        bool foundOrgId = false;
                        if(strcmp(organizationRecord.id, IDDUMMY) == 0){
                            error(12);
                        } else if (strcmp(search, IDDUMMY) == 0){
                            error(11);
                        } else {
                            // mencari id relasi
                            while((strcmp(organizationRecord.id, IDDUMMY) != 0) && (strcmp(organizationRecord.id, search) != 0)){
                                fscanf(organizationTable, "%s %s %s %s\n", organizationRecord.id, organizationRecord.name, organizationRecord.createdAt, organizationRecord.updatedAt);
                            }
                            if(strcmp(organizationRecord.id, search) == 0){
                                foundOrgId = true;
                            } else {
                                error(23);
                            }
                        }
                        fclose(organizationTable);

                        if(foundOrgId){
                            strcpy(new.organizationId, getcw());          // mengambil organisasi masukan user
    
                            inc(command);
                            if(!eop(command)){
                                if(strlen(getcw()) < sizeof(record.positionId)){
                                    position positionRecord;

                                    FILE *positionTable;
                                    positionTable = fopen("tables/tposition.dat", "r");

                                    char search[10];
                                    strcpy(search, getcw());

                                    fscanf(positionTable, "%s %s %s %s", positionRecord.id, positionRecord.name, positionRecord.createdAt, positionRecord.updatedAt);

                                    bool foundPosId = false;
                                    if(strcmp(positionRecord.id, IDDUMMY) == 0){
                                        error(12);
                                    } else if (strcmp(search, IDDUMMY) == 0){
                                        error(11);
                                    } else {
                                        // mencari id relasi
                                        while((strcmp(positionRecord.id, IDDUMMY) != 0) && (strcmp(positionRecord.id, search) != 0)){
                                            fscanf(positionTable, "%s %s %s %s\n", positionRecord.id, positionRecord.name, positionRecord.createdAt, positionRecord.updatedAt);
                                        }
                                        if(strcmp(positionRecord.id, search) == 0){
                                            foundPosId = true;
                                        } else {
                                            error(23);
                                        }
                                    }
                                    fclose(positionTable);

                                    if(foundPosId){
                                        strcpy(new.positionId, getcw());    // mencari posisi masukan user
        
                                        inc(command);
                                        if(!eop(command)){
                                            if(strlen(getcw()) < sizeof(record.startDate)){
                                                strcpy(new.startDate, getcw()); // mengambil tanggal_dimulai masukan user
        
                                                inc(command);
                                                if(eop(command)){
                                                    if(strlen(getcw()) < sizeof(record.endDate)){
                                                        strcpy(new.endDate, getcw());       // mengambil tanggal_berakhir masukan user
                                                        strcpy(new.updatedAt, dateTime);    // mengubah tanggal diubah
                    
                                                        // mengubah menjadi nilai baru
                                                        strcpy(temp[i].organizationId, new.organizationId);
                                                        strcpy(temp[i].positionId, new.positionId);
                                                        strcpy(temp[i].startDate, new.startDate);
                                                        strcpy(temp[i].endDate, new.endDate);
                                                        strcpy(temp[i].updatedAt, new.updatedAt);
                                    
                                                        showExperienceTable(recordSum, temp);
                                                        success(1);
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
                                } else {
                                    error(16);
                                }
                            } else {
                                error(4);
                            }
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
        experienceTable = fopen("tables/texperience.dat", "w");
        for(int i = 0; i < recordSum; i++){
            fprintf(experienceTable, "%s %s %s %s %s %s %s\n", temp[i].id, temp[i].organizationId, temp[i].positionId, temp[i].startDate, temp[i].endDate, temp[i].createdAt, temp[i].updatedAt);
        }
        fprintf(experienceTable, "%s", EOFEXPERIENCE);
        fclose(experienceTable);   
    }
}
void deleteExperience(char command[]){    // menghapus data
    int recordSum = 0;        // jumlah rekaman di dalam tabel
    experience temp[MAX];     // array rekaman untuk menggeserkan nilai rekaman baru
    experience record, new;   // rekaman saat ini dan rekaman yang baru

    FILE *experienceTable;    // kaitan untuk mengakses file
    experienceTable = fopen("tables/texperience.dat", "r"); // membuka file dengan mode read

    // memulai proses pembacaan
    fscanf(experienceTable, "%s %s %s %s %s %s %s\n", record.id, record.organizationId, record.positionId, record.startDate, record.endDate, record.createdAt, record.updatedAt);
    
    if(strcmp(record.id, IDDUMMY) == 0 || strcmp(record.id, "") == 0){
        // jika EOF ditemukan atau data kosong
        error(12);
        fclose(experienceTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array sampai ditemukan EOF
        do{
            strcpy(temp[recordSum].id, record.id);
            strcpy(temp[recordSum].organizationId, record.organizationId);
            strcpy(temp[recordSum].positionId, record.positionId);
            strcpy(temp[recordSum].startDate, record.startDate);
            strcpy(temp[recordSum].endDate, record.endDate);
            strcpy(temp[recordSum].createdAt, record.createdAt);
            strcpy(temp[recordSum].updatedAt, record.updatedAt);
            recordSum++;
            fscanf(experienceTable, "%s %s %s %s %s %s %s\n", record.id, record.organizationId, record.positionId, record.startDate, record.endDate, record.createdAt, record.updatedAt);
        } while(strcmp(record.id, IDDUMMY) != 0);

        fclose(experienceTable); // menutup file
        
        inc(command);
        char search[50]; // cari nilai id
        strcpy(search, getcw()); // mengambil id masukan user
        
        if(eop(command)){
            int idx = 0;    // iterasi dan index
            bool isFound = false;   // cek ditemukan
            // proses pencarian 
            searchId(temp, recordSum, search, &isFound, &idx, 6);
            
            if(!isFound){
                error(11);
            } else {
                // kondisi memasukkan ke dalam array
                if(idx == 0){
                    // rekaman dihapus di paling depan
                    // geser semua isi array ke belakang
                    for(int i = 0; i < recordSum - 1; i++){
                        strcpy(temp[i].id, temp[i+1].id);
                        strcpy(temp[i].organizationId, temp[i+1].organizationId);
                        strcpy(temp[i].positionId, temp[i+1].positionId);
                        strcpy(temp[i].startDate, temp[i+1].startDate);
                        strcpy(temp[i].endDate, temp[i+1].endDate);
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
                        strcpy(temp[j].organizationId, temp[j+1].organizationId);
                        strcpy(temp[j].positionId, temp[j+1].positionId);
                        strcpy(temp[j].startDate, temp[j+1].startDate);
                        strcpy(temp[j].endDate, temp[j+1].endDate);
                        strcpy(temp[j].createdAt, temp[j+1].createdAt);
                        strcpy(temp[j].updatedAt, temp[j+1].updatedAt);
                    }
                    recordSum--;
                }
                showExperienceTable(recordSum, temp);
                success(2);
            }
            // flush ke file
            experienceTable = fopen("tables/texperience.dat", "w");
            for(int i = 0; i < recordSum; i++){
                fprintf(experienceTable, "%s %s %s %s %s %s %s\n", temp[i].id, temp[i].organizationId, temp[i].positionId, temp[i].startDate, temp[i].endDate, temp[i].createdAt, temp[i].updatedAt);
            }
            fprintf(experienceTable, "%s", EOFEXPERIENCE);
            fclose(experienceTable);
        } else {
            error(14);
        }
    }
}
void guideExperience(){                   // buku panduan pengalaman
    guideTitle();

    printf("|                                                                                                    |\n");
    printf("|   "WHITE"Tabel pengalaman digunakan untuk menyimpan data pengalaman yang pernah diperoleh"CYAN"                 |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"STRUKTUR DATA"CYAN"                                                                                    |\n");
    printf("|      "WHITE"1. id               : "CYAN"Kode unik                                                               |\n");
    printf("|      "WHITE"2. id_organisasi    : "CYAN"Kode unik dari nama organisasi                                          |\n");
    printf("|      "WHITE"3. id_posisi        : "CYAN"Kode unik dari nama posisi                                              |\n");
    printf("|      "WHITE"4. tanggal_dimulai  : "CYAN"Tanggal pengalaman dimulai (cth. 2025_May)                              |\n");
    printf("|      "WHITE"5. tanggal_berakhir : "CYAN"Tanggal pengalaman berakhir (cth. 2025_Agustus atau -)                  |\n");
    printf("|      "WHITE"6. tanggal_dibuat   : "CYAN"Waktu data dibuat                                                       |\n");
    printf("|      "WHITE"7. tanggal_diubah   : "CYAN"Waktu data diubah                                                       |\n");
    printf("|                                                                                                    |\n");
    printf("|   "BGREEN"PENGGUNAAN PERINTAH"CYAN"                                                                              |\n");
    printf("|      "WHITE"1. Menampilkan data      : "BPURPLE"PRESENT FROM "BLUE"texperience"YELLOW"$"CYAN"                                          |\n");
    printf("|      "WHITE"2. Mencari data          : "BPURPLE"PRESENT FROM"BLUE" texperience "BPURPLE"WHERE"CYAN" id"YELLOW"$"CYAN"                                 |\n");
    printf("|      "WHITE"3. Menambahkan data      : "BPURPLE"SUBMIT TO "BLUE"texperience "CYAN"id id_organisasi id_posisi tanggal_dimulai   |\n");
    printf("|                                                       tanggal_berakhir"YELLOW"$"CYAN"                            |\n");
    printf("|      "WHITE"4. Mengubah data         : "BPURPLE"CHANGE "BLUE"texperience "CYAN"id id_organisasi id_posisi tanggal_dimulai      |\n");
    printf("|                                                    tanggal_berakhir"YELLOW"$"CYAN"                               |\n");
    printf("|      "WHITE"5. Menghapus data        : "BPURPLE"REMOVE FROM "BLUE"texperience "CYAN"id"YELLOW"$"CYAN"                                        |\n");
    printf("|      "WHITE"6. Menggabungkan tabel   : "BPURPLE"JOIN ON "BLUE"texperience torganization tposition"YELLOW"$"CYAN"                       |\n");
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
        searchId(temp, recordSum, search, &isFound, &i, 7);
        
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
                // mencari id relasi
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
                searchId(temp, recordSum, search, &isFound, &idx, 7);
                
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
                                foundData[0] = temp[idx];
                                showProjectTable(strlen(temp[idx].name), strlen(temp[idx].url), 1, foundData);
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
                            strcpy(new.url, getcw());   // mengambil url masukan user

                            inc(command);
                            if(!eop(command)){
                                if(strlen(getcw()) < sizeof(record.finishedDate)){
                                    strcpy(new.finishedDate, getcw());  // mengambil tanggal_selesai masukan user

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
                                                // mencari id relasi
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
                                                strcpy(new.categoryId, getcw());    // mengambil kategori masukan user
    
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
    project temp[MAX];      // array rekaman untuk menggeserkan nilai rekaman baru
    project record, new;    // rekaman saat ini dan rekaman yang baru

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
        searchId(temp, recordSum, search, &isFound, &i, 8);
        
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
                                strcpy(new.url, getcw());   // mengambil url masukan user

                                inc(command);
                                if(!eop(command)){
                                    if(strlen(getcw()) < sizeof(record.finishedDate)){
                                        strcpy(new.finishedDate, getcw());  // mengambil tanggal_selesai masukan user

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
                                                    // mencari id relasi
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
                                                    strcpy(new.categoryId, getcw());    // mengambil kategori masukan user
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
    project temp[MAX];      // array rekaman untuk menggeserkan nilai rekaman baru
    project record, new;    // rekaman saat ini dan rekaman yang baru

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
            searchId(temp, recordSum, search, &isFound, &idx, 8);
            
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
void joinTargetPositionSkill(char command[]){               // menggabungkan tabel target, posisi, dan skill
    int sklSum = 0;          // jumlah rekaman dalam tabel skill
    skill tempSkl[MAX];      // array rekaman skill untuk ditampilkan
    skill sklRecord;         // rekaman skill saat ini untuk disalin

    FILE *skillTable;    // kaitan untuk mengakses file skill
    skillTable = fopen("tables/tskill.dat", "r"); // membuka file skill dengan mode read
    
    // memulai proses pembacaan
    fscanf(skillTable, "%s %s %s %s %s\n", sklRecord.id, sklRecord.name, sklRecord.proficiency, sklRecord.createdAt, sklRecord.updatedAt);

    if(strcmp(sklRecord.id, IDDUMMY) == 0 || strcmp(sklRecord.id, "") == 0){
        // jika ditemukan EOF atau data kosong
        error(12);
        fclose(skillTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array skill sampai ditemukan EOF
        do{
            strcpy(tempSkl[sklSum].id, sklRecord.id);
            strcpy(tempSkl[sklSum].name, sklRecord.name);
            strcpy(tempSkl[sklSum].proficiency, sklRecord.proficiency);
            strcpy(tempSkl[sklSum].createdAt, sklRecord.createdAt);
            strcpy(tempSkl[sklSum].updatedAt, sklRecord.updatedAt);
            sklSum++;
            fscanf(skillTable, "%s %s %s %s %s\n", sklRecord.id, sklRecord.name, sklRecord.proficiency, sklRecord.createdAt, sklRecord.updatedAt);
        } while(strcmp(sklRecord.id, IDDUMMY) != 0);

        fclose(skillTable); // menutup file skill

        int posSum = 0;         // jumlah rekaman dalam tabel posisi
        position tempPos[MAX];  // array rekaman posisi untuk ditampilkan
        position posRecord;     // rekaman posisi saat ini untuk disalin

        FILE *positionTable;    // kaitan untuk mengakses file posisi
        positionTable = fopen("tables/tposition.dat", "r"); // membuka file posisi dengan mode read
        
        // memulai proses pembacaan
        fscanf(positionTable, "%s %s %s %s\n", posRecord.id, posRecord.name, posRecord.createdAt, posRecord.updatedAt);

        if(strcmp(posRecord.id, IDDUMMY) == 0 || strcmp(posRecord.id, "") == 0){
            // jika ditemukan EOF atau data kosong
            error(12);
            fclose(positionTable);
        } else {
            // jika tidak ditemukan EOF dan data tidak kosong
            // mengisi rekaman ke dalam array posisi sampai ditemukan EOF
            do{
                strcpy(tempPos[posSum].id, posRecord.id);
                strcpy(tempPos[posSum].name, posRecord.name);
                strcpy(tempPos[posSum].createdAt, posRecord.createdAt);
                strcpy(tempPos[posSum].updatedAt, posRecord.updatedAt);
                posSum++;
                fscanf(positionTable, "%s %s %s %s\n", posRecord.id, posRecord.name, posRecord.createdAt, posRecord.updatedAt);
            } while(strcmp(posRecord.id, IDDUMMY) != 0);

            fclose(positionTable); // menutup file posisi

            int tarSum = 0;      // jumlah rekaman dalam tabel target
            target tempTar[MAX]; // array rekaman target untuk ditampilkan
            target tarRecord;    // rekaman target saat ini untuk disalin

            FILE *targetTable;    // kaitan untuk mengakses file target
            targetTable = fopen("tables/ttarget.dat", "r"); // membuka file target dengan mode read
            
            // memulai proses pembacaan
            fscanf(targetTable, "%s %s %s %d %s %s\n", tarRecord.id, tarRecord.positionId, tarRecord.skillId, &tarRecord.isSkilled, tarRecord.createdAt, tarRecord.updatedAt);

            if(strcmp(tarRecord.id, IDDUMMY) == 0 || strcmp(tarRecord.id, "") == 0){
                // jika ditemukan EOF atau data kosong
                error(12);
                fclose(targetTable);
            } else {
                // jika tidak ditemukan EOF dan data tidak kosong
                // mengisi rekaman ke dalam array target sampai ditemukan EOF
                do{
                    strcpy(tempTar[tarSum].id, tarRecord.id);
                    strcpy(tempTar[tarSum].positionId, tarRecord.positionId);
                    strcpy(tempTar[tarSum].skillId, tarRecord.skillId);
                    tempTar[tarSum].isSkilled = tarRecord.isSkilled;
                    strcpy(tempTar[tarSum].createdAt, tarRecord.createdAt);
                    strcpy(tempTar[tarSum].updatedAt, tarRecord.updatedAt);
                    tarSum++;
                    fscanf(targetTable, "%s %s %s %d %s %s\n", tarRecord.id, tarRecord.positionId, tarRecord.skillId, &tarRecord.isSkilled, tarRecord.createdAt, tarRecord.updatedAt);
                } while(strcmp(tarRecord.id, IDDUMMY) != 0);

                fclose(targetTable); // menutup file

                // hasil join
                showPositionSkillTarget(longestName(tempPos, posSum, 1), longestName(tempSkl, sklSum, 2), tarSum, posSum, sklSum, tempTar, tempPos, tempSkl);
            }
        }
    }
}
void joinCertificateOrganization(char command[]){           // menggabungkan tabel organisasi dan sertifikat
    int orgSum = 0;             // jumlah rekaman dalam tabel organisasi
    organization tempOrg[MAX];  // array rekaman organisasi untuk ditampilkan
    organization orgRecord;     // rekaman organisasi saat ini untuk disalin

    FILE *organizationTable;    // kaitan untuk mengakses file organisasi
    organizationTable = fopen("tables/torganization.dat", "r"); // membuka file organisasi dengan mode read
    
    // memulai proses pembacaan
    fscanf(organizationTable, "%s %s %s %s\n", orgRecord.id, orgRecord.name, orgRecord.createdAt, orgRecord.updatedAt);

    if(strcmp(orgRecord.id, IDDUMMY) == 0 || strcmp(orgRecord.id, "") == 0){
        // jika ditemukan EOF atau data kosong
        error(12);
        fclose(organizationTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array organisasi sampai ditemukan EOF
        do{
            strcpy(tempOrg[orgSum].id, orgRecord.id);
            strcpy(tempOrg[orgSum].name, orgRecord.name);
            strcpy(tempOrg[orgSum].createdAt, orgRecord.createdAt);
            strcpy(tempOrg[orgSum].updatedAt, orgRecord.updatedAt);
            orgSum++;
            fscanf(organizationTable, "%s %s %s %s\n", orgRecord.id, orgRecord.name, orgRecord.createdAt, orgRecord.updatedAt);
        } while(strcmp(orgRecord.id, IDDUMMY) != 0);

        fclose(organizationTable); // menutup file organisasi

        int cerSum = 0;             // jumlah rekaman dalam tabel sertifikat
        certificate temCer[MAX];    // array rekaman sertifikat untuk ditampilkan
        certificate cerRecord;      // rekaman sertifikat saat ini untuk disalin

        FILE *certificateTable;    // kaitan untuk mengakses file sertifikat
        certificateTable = fopen("tables/tcertificate.dat", "r"); // membuka file sertifikat dengan mode read
        
        // memulai proses pembacaan
        fscanf(certificateTable, "%s %s %s %s %s %s %s %s %s\n", cerRecord.id, cerRecord.name, cerRecord.issuerId, cerRecord.startDate, cerRecord.endDate, cerRecord.credentialId, cerRecord.url, cerRecord.createdAt, cerRecord.updatedAt);

        if(strcmp(cerRecord.id, IDDUMMY) == 0 || strcmp(cerRecord.id, "") == 0){
            // jika ditemukan EOF atau data kosong
            error(12);
            fclose(certificateTable);
        } else {
            // jika tidak ditemukan EOF dan data tidak kosong
            // mengisi rekaman ke dalam array proyek sampai ditemukan EOF
            do{
                strcpy(temCer[cerSum].id, cerRecord.id);
                strcpy(temCer[cerSum].name, cerRecord.name);
                strcpy(temCer[cerSum].issuerId, cerRecord.issuerId);
                strcpy(temCer[cerSum].startDate, cerRecord.startDate);
                strcpy(temCer[cerSum].endDate, cerRecord.endDate);
                strcpy(temCer[cerSum].credentialId, cerRecord.credentialId);
                strcpy(temCer[cerSum].url, cerRecord.url);
                strcpy(temCer[cerSum].createdAt, cerRecord.createdAt);
                strcpy(temCer[cerSum].updatedAt, cerRecord.updatedAt);
                cerSum++;
                fscanf(certificateTable, "%s %s %s %s %s %s %s %s %s\n", cerRecord.id, cerRecord.name, cerRecord.issuerId, cerRecord.startDate, cerRecord.endDate, cerRecord.credentialId, cerRecord.url, cerRecord.createdAt, cerRecord.updatedAt);
            } while(strcmp(cerRecord.id, IDDUMMY) != 0);

            fclose(certificateTable); // menutup file

            // hasil join
            showOrganizationCertificate(longestName(temCer, cerSum, 5), longestUrl(temCer, cerSum, 5), longestName(tempOrg, orgSum, 4), longestCredential(temCer, cerSum), cerSum, orgSum, temCer, tempOrg);
        }
    }
}
void joinExperienceOrganizationPosition(char command[]){    // menggabungkan tabel pengalaman, organisasi, dan posisi
    int orgSum = 0;                 // jumlah rekaman dalam tabel organisasi
    organization tempOrg[MAX];      // array rekaman organisasi untuk ditampilkan
    organization orgRecord;         // rekaman organisasi saat ini untuk disalin

    FILE *organizationTable;    // kaitan untuk mengakses file organisasi
    organizationTable = fopen("tables/torganization.dat", "r"); // membuka file organisasi dengan mode read
    
    // memulai proses pembacaan
    fscanf(organizationTable, "%s %s %s %s\n", orgRecord.id, orgRecord.name, orgRecord.createdAt, orgRecord.updatedAt);

    if(strcmp(orgRecord.id, IDDUMMY) == 0 || strcmp(orgRecord.id, "") == 0){
        // jika ditemukan EOF atau data kosong
        error(12);
        fclose(organizationTable);
    } else {
        // jika tidak ditemukan EOF dan data tidak kosong
        // mengisi rekaman ke dalam array organisasi sampai ditemukan EOF
        do{
            strcpy(tempOrg[orgSum].id, orgRecord.id);
            strcpy(tempOrg[orgSum].name, orgRecord.name);
            strcpy(tempOrg[orgSum].createdAt, orgRecord.createdAt);
            strcpy(tempOrg[orgSum].updatedAt, orgRecord.updatedAt);
            orgSum++;
            fscanf(organizationTable, "%s %s %s %s\n", orgRecord.id, orgRecord.name, orgRecord.createdAt, orgRecord.updatedAt);
        } while(strcmp(orgRecord.id, IDDUMMY) != 0);

        fclose(organizationTable); // menutup file organisasi

        int posSum = 0;         // jumlah rekaman dalam tabel posisi
        position tempPos[MAX];  // array rekaman posisi untuk ditampilkan
        position posRecord;     // rekaman posisi saat ini untuk disalin

        FILE *positionTable;    // kaitan untuk mengakses file posisi
        positionTable = fopen("tables/tposition.dat", "r"); // membuka file posisi dengan mode read
        
        // memulai proses pembacaan
        fscanf(positionTable, "%s %s %s %s\n", posRecord.id, posRecord.name, posRecord.createdAt, posRecord.updatedAt);

        if(strcmp(posRecord.id, IDDUMMY) == 0 || strcmp(posRecord.id, "") == 0){
            // jika ditemukan EOF atau data kosong
            error(12);
            fclose(positionTable);
        } else {
            // jika tidak ditemukan EOF dan data tidak kosong
            // mengisi rekaman ke dalam array posisi sampai ditemukan EOF
            do{
                strcpy(tempPos[posSum].id, posRecord.id);
                strcpy(tempPos[posSum].name, posRecord.name);
                strcpy(tempPos[posSum].createdAt, posRecord.createdAt);
                strcpy(tempPos[posSum].updatedAt, posRecord.updatedAt);
                posSum++;
                fscanf(positionTable, "%s %s %s %s\n", posRecord.id, posRecord.name, posRecord.createdAt, posRecord.updatedAt);
            } while(strcmp(posRecord.id, IDDUMMY) != 0);

            fclose(positionTable); // menutup file posisi

            int expSum = 0;          // jumlah rekaman dalam tabel pengalaman
            experience tempExp[MAX]; // array rekaman pengalaman untuk ditampilkan
            experience expRecord;    // rekaman pengalaman saat ini untuk disalin

            FILE *experienceTable;    // kaitan untuk mengakses file pengalaman
            experienceTable = fopen("tables/texperience.dat", "r"); // membuka file pengalaman dengan mode read
            
            // memulai proses pembacaan
            fscanf(experienceTable, "%s %s %s %s %s %s %s\n", expRecord.id, expRecord.organizationId, expRecord.positionId, expRecord.startDate, expRecord.endDate, expRecord.createdAt, expRecord.updatedAt);

            if(strcmp(expRecord.id, IDDUMMY) == 0 || strcmp(expRecord.id, "") == 0){
                // jika ditemukan EOF atau data kosong
                error(12);
                fclose(experienceTable);
            } else {
                // jika tidak ditemukan EOF dan data tidak kosong
                // mengisi rekaman ke dalam array pengalaman sampai ditemukan EOF
                do{
                    strcpy(tempExp[expSum].id, expRecord.id);
                    strcpy(tempExp[expSum].organizationId, expRecord.organizationId);
                    strcpy(tempExp[expSum].positionId, expRecord.positionId);
                    strcpy(tempExp[expSum].startDate, expRecord.startDate);
                    strcpy(tempExp[expSum].endDate, expRecord.endDate);
                    strcpy(tempExp[expSum].createdAt, expRecord.createdAt);
                    strcpy(tempExp[expSum].updatedAt, expRecord.updatedAt);
                    expSum++;
                    fscanf(experienceTable, "%s %s %s %s %s %s %s\n", expRecord.id, expRecord.organizationId, expRecord.positionId, expRecord.startDate, expRecord.endDate, expRecord.createdAt, expRecord.updatedAt);
                } while(strcmp(expRecord.id, IDDUMMY) != 0);

                fclose(experienceTable); // menutup file

                // hasil join
                showOrganizationPositionExperience(longestName(tempOrg, orgSum, 4), longestName(tempPos, posSum, 1), expSum, orgSum, posSum, tempExp, tempOrg, tempPos);
            }
        }
    }
}
void joinProjectCategory(char command[]){                   // menggabungkan tabel kategori dan proyek
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
