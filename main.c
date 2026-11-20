// Saya Alfriza sebagai manusia yang berTuhan, saya mengerjakan evaluasi 
// Tugas Masa Depan dalam mata kuliah Dasar-dasar Pemrograman untuk 
// keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah 
// dispesifikasikan. Aamiin.

#include "header.h" // memanggil file header

int main(){

    in();

    bool exit = false;  // cek keluar
    do{ // jalankan aplikasi selama exit bernilai false
        char command[301];  // perintah/masukan user
        
        // custom terminal prompt
        printf(GREEN "DBMS@alfreezzz" PURPLE " CIHUY32 " YELLOW "/c/career tracker" CYAN " (master)\n" DEFAULT);
        printf("$ ");
        
        scanf("%300[^\n]s", command);   // mengambil masukkan user
        getchar();

        if(command[strlen(command) - 1] == EOP){    // mengecek eop
            start(command);
            
            if(strcmp(getcw(), "SUBMIT") == 0){             // menambahkan data
                if(!eop(command)){
                    inc(command);
                    if(strcmp(getcw(), "TO") == 0){
                        if(!eop(command)){
                            inc(command);
                            if(strcmp(getcw(), "tposition") == 0){
                                if(!eop(command)){
                                    postPosition(command);
                                } else {
                                    error(5);
                                }
                            } else if (strcmp(getcw(), "tskill") == 0){
                                if(!eop(command)){
                                    postSkill(command);
                                } else {
                                    error(5);
                                }
                            } else if (strcmp(getcw(), "ttarget") == 0){
                                if(!eop(command)){
                                    postTarget(command);
                                } else {
                                    error(5);
                                }
                            } else if (strcmp(getcw(), "torganization") == 0){
                               if(!eop(command)){
                                    postOrganization(command);
                                } else {
                                    error(5);
                                }
                            } else if (strcmp(getcw(), "tcertificate") == 0){
                                return 4;
                            } else if (strcmp(getcw(), "texperience") == 0){
                                if(!eop(command)){
                                    postExperience(command);
                                } else {
                                    error(5);
                                }
                            } else if (strcmp(getcw(), "tcategory") == 0){
                                if(!eop(command)){
                                    postCategory(command);
                                } else {
                                    error(5);
                                }
                            } else if (strcmp(getcw(), "tproject") == 0){
                                if(!eop(command)){
                                    postProject(command);
                                } else {
                                    error(5);
                                }
                            } else {
                                error(1);
                            }
                        } else {
                            error(3);
                        }
                    } else {
                        error(17);
                    }
                } else {
                    error(10);
                }
            } else if (strcmp(getcw(), "CHANGE") == 0){     // mengubah data
                if(!eop(command)){
                    inc(command);
                    if(strcmp(getcw(), "tposition") == 0){
                        if(!eop(command)){
                            updatePosition(command);
                        } else {
                            error(13);
                        }
                    } else if (strcmp(getcw(), "tskill") == 0){
                        if(!eop(command)){
                            updateSkill(command);
                        } else {
                            error(13);
                        }
                    } else if (strcmp(getcw(), "ttarget") == 0){
                        if(!eop(command)){
                            updateTarget(command);
                        } else {
                            error(13);
                        }
                    } else if (strcmp(getcw(), "torganization") == 0){
                        if(!eop(command)){
                            updateOrganization(command);
                        } else {
                            error(13);
                        }
                    } else if (strcmp(getcw(), "tcertificate") == 0){
                        return 4;
                    } else if (strcmp(getcw(), "texperience") == 0){
                        if(!eop(command)){
                            updateExperience(command);
                        } else {
                            error(13);
                        }
                    } else if (strcmp(getcw(), "tcategory") == 0){
                        if(!eop(command)){
                            updateCategory(command);
                        } else {
                            error(13);
                        }
                    } else if (strcmp(getcw(), "tproject") == 0){
                        if(!eop(command)){
                            updateProject(command);
                        } else {
                            error(13);
                        }
                    } else {
                        error(1);
                    }
                } else {
                    error(3);
                }
            } else if (strcmp(getcw(), "REMOVE") == 0){     // menghapus data
                if(!eop(command)){
                    inc(command);
                    if(strcmp(getcw(), "FROM") == 0){
                        if(!eop(command)){
                            inc(command);
                            if(strcmp(getcw(), "tposition") == 0){
                                if(!eop(command)){
                                    deletePosition(command);
                                } else {
                                    error(9);
                                }
                            } else if (strcmp(getcw(), "tskill") == 0){
                                if(!eop(command)){
                                    deleteSkill(command);
                                } else {
                                    error(9);
                                }
                            } else if (strcmp(getcw(), "ttarget") == 0){
                                if(!eop(command)){
                                    deleteTarget(command);
                                } else {
                                    error(9);
                                }
                            } else if (strcmp(getcw(), "torganization") == 0){
                                if(!eop(command)){
                                    deleteOrganization(command);
                                } else {
                                    error(9);
                                }
                            } else if (strcmp(getcw(), "tcertificate") == 0){
                                return 4;
                            } else if (strcmp(getcw(), "texperience") == 0){
                                if(!eop(command)){
                                    deleteExperience(command);
                                } else {
                                    error(9);
                                }
                            } else if (strcmp(getcw(), "tcategory") == 0){
                                if(!eop(command)){
                                    deleteCategory(command);
                                } else {
                                    error(9);
                                }
                            } else if (strcmp(getcw(), "tproject") == 0){
                                if(!eop(command)){
                                    deleteProject(command);
                                } else {
                                    error(9);
                                }
                            } else {
                                error(1);
                            }
                        } else {
                            error(3);
                        }
                    } else {
                        error(18);
                    }
                } else {
                    error(10);
                }
            } else if (strcmp(getcw(), "PRESENT") == 0){    // menampilkan data
                if(!eop(command)){
                    inc(command);
                    if(strcmp(getcw(), "FROM") == 0){
                        if(!eop(command)){
                            inc(command);
                            if(strcmp(getcw(), "tposition") == 0){
                                getPosition(command);
                            } else if (strcmp(getcw(), "tskill") == 0){
                                getSkill(command);
                            } else if (strcmp(getcw(), "ttarget") == 0){
                                getTarget(command);
                            } else if (strcmp(getcw(), "torganization") == 0){
                                getOrganization(command);
                            } else if (strcmp(getcw(), "tcertificate") == 0){
                                return 4;
                            } else if (strcmp(getcw(), "texperience") == 0){
                                getExperience(command);
                            } else if (strcmp(getcw(), "tcategory") == 0){
                                getCategory(command);
                            } else if (strcmp(getcw(), "tproject") == 0){
                                getProject(command);
                            } else {
                                error(1);
                            }
                        } else {
                            error(3);
                        }
                    } else {
                        error(19);
                    }
                } else {
                    error(10);
                }
            } else if (strcmp(getcw(), "JOIN") == 0){       // menggabungkan tabel
                if(!eop(command)){
                    inc(command);
                    if(strcmp(getcw(), "ON") == 0){
                        if(!eop(command)){
                            inc(command);
                            if(strcmp(getcw(), "tposition") == 0){
                                if(!eop(command)){
                                    inc(command);
                                    if(strcmp(getcw(), "tskill") == 0){
                                        if(!eop(command)){
                                            inc(command);
                                            if(strcmp(getcw(), "ttarget") == 0){
                                                if(eop(command)){
                                                    joinTargetPositionSkill(command);
                                                } else {
                                                    error(14);
                                                }
                                            } else {
                                                error(26);
                                            }
                                        } else {
                                            error(28);
                                        }
                                    } else if (strcmp(getcw(), "ttarget") == 0){
                                        if(!eop(command)){
                                            inc(command);
                                            if(strcmp(getcw(), "tskill") == 0){
                                                if(eop(command)){
                                                    joinTargetPositionSkill(command);
                                                } else {
                                                    error(14);
                                                }
                                            } else {
                                                error(26);
                                            }
                                        } else {
                                            error(28);
                                        }
                                    } else if (strcmp(getcw(), "torganization") == 0){
                                        if(!eop(command)){
                                            inc(command);
                                            if(strcmp(getcw(), "texperience") == 0){
                                                if(eop(command)){
                                                    joinExperienceOrganizationPosition(command);
                                                } else {
                                                    error(14);
                                                }
                                            } else {
                                                error(26);
                                            }
                                        } else {
                                            error(28);
                                        }
                                    } else if (strcmp(getcw(), "texperience") == 0){
                                        if(!eop(command)){
                                            inc(command);
                                            if(strcmp(getcw(), "torganization") == 0){
                                                if(eop(command)){
                                                    joinExperienceOrganizationPosition(command);
                                                } else {
                                                    error(14);
                                                }
                                            } else {
                                                error(26);
                                            }
                                        } else {
                                            error(28);
                                        }
                                    } else {
                                        error(26);
                                    }
                                } else {
                                    error(28);
                                }
                            } else if (strcmp(getcw(), "tskill") == 0){
                                if(!eop(command)){
                                    inc(command);
                                    if(strcmp(getcw(), "tposition") == 0){
                                        if(!eop(command)){
                                            inc(command);
                                            if(strcmp(getcw(), "ttarget") == 0){
                                                if(eop(command)){
                                                    joinTargetPositionSkill(command);
                                                } else {
                                                    error(14);
                                                }
                                            } else {
                                                error(26);
                                            }
                                        } else {
                                            error(28);
                                        }
                                    } else if (strcmp(getcw(), "ttarget") == 0){
                                        if(!eop(command)){
                                            inc(command);
                                            if(strcmp(getcw(), "tposition") == 0){
                                                if(eop(command)){
                                                    joinTargetPositionSkill(command);
                                                } else {
                                                    error(14);
                                                }
                                            } else {
                                                error(26);
                                            }
                                        } else {
                                            error(28);
                                        }
                                    } else {
                                        error(26);
                                    }
                                } else {
                                    error(28);
                                }
                            } else if (strcmp(getcw(), "ttarget") == 0){
                                if(!eop(command)){
                                    inc(command);
                                    if(strcmp(getcw(), "tposition") == 0){
                                        if(!eop(command)){
                                            inc(command);
                                            if(strcmp(getcw(), "tskill") == 0){
                                                if(eop(command)){
                                                    joinTargetPositionSkill(command);
                                                } else {
                                                    error(14);
                                                }
                                            } else {
                                                error(26);
                                            }
                                        } else {
                                            error(28);
                                        }
                                    } else if (strcmp(getcw(), "tskill") == 0){
                                        if(!eop(command)){
                                            inc(command);
                                            if(strcmp(getcw(), "tposition") == 0){
                                                if(eop(command)){
                                                    joinTargetPositionSkill(command);
                                                } else {
                                                    error(14);
                                                }
                                            } else {
                                                error(26);
                                            }
                                        } else {
                                            error(28);
                                        }
                                    } else {
                                        error(26);
                                    }
                                } else {
                                    error(28);
                                }
                            } else if (strcmp(getcw(), "torganization") == 0){
                                if(!eop(command)){
                                    inc(command);
                                    if(strcmp(getcw(), "tcertificate") == 0){
                                        if(eop(command)){
                                            joinCertificateOrganization(command);
                                        } else {
                                            error(14);
                                        }
                                    } else if (strcmp(getcw(), "texperience") == 0){
                                        if(!eop(command)){
                                            inc(command);
                                            if(strcmp(getcw(), "tposition") == 0){
                                                if(eop(command)){
                                                    joinExperienceOrganizationPosition(command);
                                                } else {
                                                    error(14);
                                                }
                                            } else {
                                                error(26);
                                            }
                                        } else {
                                            error(28);
                                        }
                                    } else if (strcmp(getcw(), "tposition") == 0){
                                        if(!eop(command)){
                                            inc(command);
                                            if(strcmp(getcw(), "texperience") == 0){
                                                if(eop(command)){
                                                    joinExperienceOrganizationPosition(command);
                                                } else {
                                                    error(14);
                                                }
                                            } else {
                                                error(26);
                                            }
                                        } else {
                                            error(28);
                                        }
                                    } else {
                                        error(26);
                                    }
                                } else {
                                    error(28);
                                }
                            } else if (strcmp(getcw(), "tcertificate") == 0){
                                if(!eop(command)){
                                    inc(command);
                                    if(strcmp(getcw(), "torganization") == 0){
                                        if(eop(command)){
                                            joinCertificateOrganization(command);
                                        } else {
                                            error(14);
                                        }
                                    } else {
                                        error(26);
                                    }
                                } else {
                                    error(28);
                                }
                            } else if (strcmp(getcw(), "texperience") == 0){
                                if(!eop(command)){
                                    inc(command);
                                    if(strcmp(getcw(), "torganization") == 0){
                                        if(!eop(command)){
                                            inc(command);
                                            if(strcmp(getcw(), "tposition") == 0){
                                                if(eop(command)){
                                                    joinExperienceOrganizationPosition(command);
                                                } else {
                                                    error(14);
                                                }
                                            } else {
                                                error(26);
                                            }
                                        } else {
                                            error(28);
                                        }
                                    } else if (strcmp(getcw(), "tposition") == 0){
                                        if(!eop(command)){
                                            inc(command);
                                            if(strcmp(getcw(), "torganization") == 0){
                                                if(eop(command)){
                                                    joinExperienceOrganizationPosition(command);
                                                } else {
                                                    error(14);
                                                }
                                            } else {
                                                error(26);
                                            }
                                        } else {
                                            error(28);
                                        }
                                    } else {
                                        error(26);
                                    }
                                } else {
                                    error(28);
                                }
                            } else if (strcmp(getcw(), "tcategory") == 0){
                                if(!eop(command)){
                                    inc(command);
                                    if(strcmp(getcw(), "tproject") == 0){
                                        if(eop(command)){
                                            joinProjectCategory(command);
                                        } else {
                                            error(14);
                                        }
                                    } else {
                                        error(26);
                                    }
                                } else {
                                    error(28);
                                }
                            } else if (strcmp(getcw(), "tproject") == 0){
                                if(!eop(command)){
                                    inc(command);
                                    if(strcmp(getcw(), "tcategory") == 0){
                                        if(eop(command)){
                                            joinProjectCategory(command);
                                        } else {
                                            error(14);
                                        }
                                    } else {
                                        error(26);
                                    }
                                } else {
                                    error(28);
                                }
                            } else {
                                error(1);
                            }
                        } else {
                            error(3);
                        }
                    } else {
                        error(25);
                    }
                } else {
                    error(10);
                }
            } else if (strcmp(getcw(), "HELP") == 0){       // membuka buku panduan
                if(eop(command)){
                    guide();
                } else {
                    inc(command);
                    if(strcmp(getcw(), "ON") == 0){
                        if(!eop(command)){
                            inc(command);
                            if(strcmp(getcw(), "tposition") == 0){
                                if(eop(command)){
                                    guidePosition();
                                } else {
                                    error(14);
                                }
                            } else if (strcmp(getcw(), "tskill") == 0){
                                if(eop(command)){
                                    guideSkill();
                                } else {
                                    error(14);
                                }
                            } else if (strcmp(getcw(), "ttarget") == 0){
                                if(eop(command)){
                                    guideTarget();
                                } else {
                                    error(14);
                                }
                            } else if (strcmp(getcw(), "torganization") == 0){
                                if(eop(command)){
                                    guideOrganization();
                                } else {
                                    error(14);
                                }
                            } else if (strcmp(getcw(), "tcertificate") == 0){
                                if(eop(command)){
                                    guideCertificate();
                                } else {
                                    error(14);
                                }
                            } else if (strcmp(getcw(), "texperience") == 0){
                                if(eop(command)){
                                    guideExperience();
                                } else {
                                    error(14);
                                }
                            } else if (strcmp(getcw(), "tcategory") == 0){
                                if(eop(command)){
                                    guideCategory();
                                } else {
                                    error(14);
                                }
                            } else if (strcmp(getcw(), "tproject") == 0){
                                if(eop(command)){
                                    guideProject();
                                } else {
                                    error(14);
                                }
                            } else {
                                error(1);
                            }
                        } else {
                            error(3);
                        }
                    } else {
                        error(20);
                    }
                }
            } else if(strcmp(getcw(), "EXIT") == 0){        // mengakhiri aplikasi
                if(eop(command)){
                    exit = true;
                } else {
                    error(14);
                }
            } else if (strcmp(getcw(), "jangan") == 0){     // easter egg
                if(!eop(command)){
                    inc(command);
                    if(strcmp(getcw(), "lupa") == 0){
                        if(!eop(command)){
                            inc(command);
                            if(strcmp(getcw(), "berkah") == 0){
                                if(!eop(command)){
                                    inc(command);
                                    if(strcmp(getcw(), "dan") == 0){
                                        if(!eop(command)){
                                            inc(command);
                                            if(strcmp(getcw(), "bahagia") == 0){
                                                if(!eop(command)){
                                                    inc(command);
                                                    if(strcmp(getcw(), "hari") == 0){
                                                        if(!eop(command)){
                                                            inc(command);
                                                            if(strcmp(getcw(), "ini") == 0){
                                                                if(eop(command)){
                                                                    out();
                                                                    exit = true;
                                                                } else {
                                                                    error(14);
                                                                }
                                                            } else {
                                                                error(0);
                                                            }
                                                        } else {
                                                            error(10);
                                                        }
                                                    } else {
                                                        error(0);
                                                    }
                                                } else {
                                                    error(10);
                                                }
                                            } else {
                                                error(0);
                                            }
                                        } else {
                                            error(10);
                                        }
                                    } else {
                                        error(0);
                                    }
                                } else {
                                    error(10);
                                }
                            } else {
                                error(0);
                            }
                        } else {
                            error(10);
                        }
                    } else {
                        error(0);
                    }
                } else {
                    error(10);
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