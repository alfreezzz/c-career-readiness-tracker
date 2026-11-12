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

        if(command[strlen(command) - 1] == '$'){
            start(command);
            
            if(strcmp(getcw(), "SUBMIT") == 0){
                if(eop(command) == 0){
                    inc(command);
                    if(strcmp(getcw(), "TO") == 0){
                        if(eop(command) == 0){
                            inc(command);
                            if(eop(command) == 0){
                                if(strcmp(getcw(), "tposition") == 0){
                                    return 0;
                                } else if (strcmp(getcw(), "tskill") == 0){
                                    return 1;
                                } else if (strcmp(getcw(), "ttarget") == 0){
                                    return 2;
                                } else if (strcmp(getcw(), "torganization") == 0){
                                    return 3;
                                } else if (strcmp(getcw(), "tcertificate") == 0){
                                    return 4;
                                } else if (strcmp(getcw(), "tcategory") == 0){
                                    postCategory(command);
                                } else if (strcmp(getcw(), "tproject") == 0){
                                    return 6;
                                }
                            } else {
                                error(5);
                            }
                        } else {
                            error(3);
                        }
                    } else {
                        error(0);
                    }
                } else {
                    error(10);
                }
            } else if (strcmp(getcw(), "CHANGE") == 0){
                if(eop(command) == 0){
                    inc(command);
                    if(eop(command) == 0){
                        if(strcmp(getcw(), "tposition") == 0){
                            return 0;
                        } else if (strcmp(getcw(), "tskill") == 0){
                            return 1;
                        } else if (strcmp(getcw(), "ttarget") == 0){
                            return 2;
                        } else if (strcmp(getcw(), "torganization") == 0){
                            return 3;
                        } else if (strcmp(getcw(), "tcertificate") == 0){
                            return 4;
                        } else if (strcmp(getcw(), "tcategory") == 0){
                            return 5;
                        } else if (strcmp(getcw(), "tproject") == 0){
                            return 6;
                        }
                    } else {
                        error(8);
                    }
                } else {
                    error(3);
                }
            } else if (strcmp(getcw(), "REMOVE") == 0){
                if(eop(command) == 0){
                    inc(command);
                    if(strcmp(getcw(), "FROM") == 0){
                        if(eop(command) == 0){
                            inc(command);
                            if(eop(command) == 0){
                                if(strcmp(getcw(), "tposition") == 0){
                                    return 0;
                                } else if (strcmp(getcw(), "tskill") == 0){
                                    return 1;
                                } else if (strcmp(getcw(), "ttarget") == 0){
                                    return 2;
                                } else if (strcmp(getcw(), "torganization") == 0){
                                    return 3;
                                } else if (strcmp(getcw(), "tcertificate") == 0){
                                    return 4;
                                } else if (strcmp(getcw(), "tcategory") == 0){
                                    return 5;
                                } else if (strcmp(getcw(), "tproject") == 0){
                                    return 6;
                                }
                            } else {
                                error(9);
                            }
                        } else {
                            error(3);
                        }
                    } else {
                        error(0);
                    }
                } else {
                    error(10);
                }
            } else if (strcmp(getcw(), "PRESENT") == 0){
                if(eop(command) == 0){
                    inc(command);
                    if(strcmp(getcw(), "FROM") == 0){
                        if(eop(command) == 0){
                            inc(command);
                            if(eop(command) == 1){
                                if(strcmp(getcw(), "tposition") == 0){
                                    return 0;
                                } else if (strcmp(getcw(), "tskill") == 0){
                                    return 1;
                                } else if (strcmp(getcw(), "ttarget") == 0){
                                    return 2;
                                } else if (strcmp(getcw(), "torganization") == 0){
                                    return 3;
                                } else if (strcmp(getcw(), "tcertificate") == 0){
                                    return 4;
                                } else if (strcmp(getcw(), "tcategory") == 0){
                                    return 5;
                                } else if (strcmp(getcw(), "tproject") == 0){
                                    return 6;
                                }
                            } else {
                                error(0);
                            }
                        } else {
                            error(3);
                        }
                    } else {
                        error(0);
                    }
                } else {
                    error(10);
                }
            } else if (strcmp(getcw(), "HELP") == 0){

            } else if(strcmp(getcw(), "EXIT") == 0){
                if(eop(command) == 1){
                    exit = true;
                } else {
                    error(0);
                }
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
                                        if(eop(command) == 1){
                                            exit = true;
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
            } else {
                error(0);
            }
        } else {
            error(2);
        }
        if(!exit){
            printf("\n");
        }
    } while(!exit);

    return 0;
}