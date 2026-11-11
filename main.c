// Saya Alfriza sebagai manusia yang berTuhan, saya mengerjakan evaluasi 
// Tugas Masa Depan dalam mata kuliah Dasar-dasar Pemrograman untuk 
// keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah 
// dispesifikasikan. Aamiin.

#include "header.h"

int main(){

    printf(BLUE "Hello world!\n" DEFAULT);
    printf("%s / %s\n", __DATE__, __TIME__);

    bool exit = false;
    do{
        char command[250];
        printf(GREEN "DBMS@alfreezzz" MAGENTA " CIHUY32 " YELLOW "/c/career tracker\n" DEFAULT);
        printf("$ ");
        scanf("%249[^\n]s", command);
        getchar();

        start(command);

        if(strcmp(getcw(), "SUBMIT") == 0){
            inc(command);
            if(strcmp(getcw(), "TO") == 0){

            } else {
                error(0);
            }
        } else if (strcmp(getcw(), "CHANGE") == 0){

        } else if (strcmp(getcw(), "REMOVE") == 0){
            inc(command);
            if(strcmp(getcw(), "FROM") == 0){

            } else {
                error(0);
            }
        } else if (strcmp(getcw(), "PRESENT") == 0){
            inc(command);
            if(strcmp(getcw(), "FROM") == 0){

            } else {
                error(0);
            }
        } else if (strcmp(getcw(), "HELP") == 0){

        } else if(strcmp(getcw(), "EXIT") == 0){
            exit = true;
        } else if (strcmp(getcw(), "jangan") == 0){
            inc(command);
            if(strcmp(getcw(), "lupa") == 0){
                inc(command);
                if(strcmp(getcw(), "berkah") == 0){
                    inc(command);
                    if(strcmp(getcw(), "dan") == 0){
                        inc(command);
                        if(strcmp(getcw(), "bahagia") == 0){
                            inc(command);
                            if(strcmp(getcw(), "hari") == 0){
                                inc(command);
                                if(strcmp(getcw(), "ini") == 0){
                                    break;
                                } else {
                                    error(0);
                                }
                            } else {
                                error(0);
                            }
                        } else {
                            error(0);
                        }
                    } else {
                        error(0);
                    }
                } else {
                    error(0);
                }
            } else {
                error(0);
            }
        } else {
            error(0);
        }
    } while(!exit);

    return 0;
}