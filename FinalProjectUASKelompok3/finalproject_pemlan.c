//AYO SEMANGATTT!!!!!!!!!!!!!!!!!!!

#include <stdio.h>
#include <string.h>
#include <shlwapi.h>
#include <math.h>
#include <conio.h>

struct data_film{
    
    char judul_film[50];
    char genre_film[50];
    int tahunrilis_film;
    char sutradara_film[50];
    char studio_film[50];

}film[100];

struct request_film{
    
    char judul_requestfilm[50];
    int tahunrilis_requestfilm[50];
    char studio_requestfilm[50];

}requestfilm[100];

void login();
void home_admin();
void list_film_admin();
void home_user();
void list_film_user();
void search_film();
void transaksi_film();
void insert_datafilm();
void read_datafilm();
void update_datafilm();
void bubblesort_judulfilm();
void selectionsort_genrefilm();
void interpolationsearch_tahunrilisfilm();
void insertionsort_sutradarafilm();
void insertionsort_studiofilm();
void sequentialsearch_genrefilm();
void binarysearch_judulfilm();
void jumpsearch_sutradarafilm();
void interpolationsearch_tahunrilisfilm();
void insert_requestfilm();

int main(){

    login();
    return 0;

}

void login(){

    int pilih;

    printf("Login as\n");
    printf("[1]. Admin\n");
    printf("[2]. User\n");
    scanf("%i",&pilih);

    switch (pilih){
    case 1:

        home_admin();
        break;
    
    default:

        home_user();
        break;
    }
}

void home_admin(){

    int pilihan;

    printf("==========Selamat datang=========\n");
    printf("===============Menu==============\n");
    printf("[1]. Home\n");
    printf("[2]. List Film\n");
    printf("[3]. Search Film\n");
    printf("[4]. Transaksi Film\n");
    printf("[5]. Tentang Kami\n");
    printf("================================\n");
    printf("Masukkan Pilihan Anda : ");
    scanf("%i",&pilihan);

    switch (pilihan){
    case 1:

        home_admin();
        break;
        
    case 2:

        list_film_admin();
        break;

    case 3:
    
        search_film();
        break;

    case 4:

        transaksi_film();
        break;

    case 5:

        printf("Program ini ditujukan untuk final project Pemograman Lanjut D081");
        break;
    
    default:
    
        printf("Selesai! Terima kasih^^");
        break;
    }
}

void list_film_admin(){

    int pilih;
    printf("Menu Kelola Data\n");
    printf("[1]. Insert Data yang tersedia\n");
    printf("[2]. Lihat Data\n");
    printf("[3]. Update Data\n");
    printf("[4]. Delete Data\n");
    scanf("%i", &pilih);

    switch (pilih){
    case 1:

        insert_datafilm();
        break;

    case 2:

        read_datafilm();
        break;

    case 3:

        update_datafilm();
        break;
    
    default:

        list_film_admin();
        break;
    }
}

void home_user(){

    int pilihan;

    printf("==========Selamat datang=========\n");
    printf("===============Menu==============\n");
    printf("[1]. Home\n");
    printf("[2]. List Film\n");
    printf("[3]. Search Film\n");
    printf("[4]. Transaksi Film\n");
    printf("[5]. Tentang Kami\n");
    printf("================================\n");
    printf("Masukkan Pilihan Anda : ");
    scanf("%i",&pilihan);

    switch (pilihan){
    case 1:

        home_user();
        break;
        
    case 2:

        list_film_user();
        break;

    case 3:
    
        search_film();
        break;

    case 4:

        transaksi_film();
        break;

    case 5:

        printf("Program ini ditujukan untuk final project Pemograman Lanjut D081");
        break;
    
    default:
        printf("Selesai! Terima kasih^^");
        break;
    }
}

void list_film_user(){

    int pilih;

    printf("[1]. Request Film");
    printf("[2]. Daftar Film\n");
    scanf("%i", &pilih);

    switch (pilih){
    case 1:
        insert_requestfilm();
        break;
    
    case 2:
        printf("Daftar Film\n");
        read_datafilm();
        printf("Urutkan Berdasarkan\n");        
        printf("[1]. Judul Film\n");
        printf("[2]. Genre Film\n");
        printf("[3]. Tahun Rilis Film\n");
        printf("[4]. Sutradara Film\n");
        printf("[5]. Studio Film\n");
        scanf("%i",&pilih);

        switch (pilih){
            case 1:

                bubblesort_judulfilm();
                break;
    
            case 2:

                selectionsort_genrefilm();
                break;

            case 3:

                interpolationsearch_tahunrilisfilm();
                break;

            case 4:

                insertionsort_sutradarafilm();
                break;
            
            case 5:

                insertionsort_studiofilm();
                break;

            default:

                list_film_user();
                break;
        }

    default:
        break;
    }
    

}

void search_film(){

    int pilih;

    printf("Cari berdasarkan\n");
    printf("[1]. Judul Film\n");
    printf("[2]. Genre Film\n");
    printf("[3]. Tahun Rilis Film\n");
    printf("[4]. Sutradara Film\n");
    printf("[5]. Studio Film\n");
    scanf("%i",&pilih);

    switch (pilih){
    case 1:
        
        sequentialsearch_genrefilm();
        break;

    case 2:

        binarysearch_judulfilm();
        break;

    case 3:

        interpolationsearch_tahunrilisfilm();
        break;

    case 4:

        jumpsearch_sutradarafilm();
        break;  

    default:

        search_film();
        break;
    }
}

void transaksi_film(){

    int pilih;
    read_datafilm();
    printf("Silakan pilih filmnya : ");
    printf("%i",&pilih);

}

void insert_datafilm(){

    int pilih;
    int urutan_datafilm = 0;
    FILE *datafilm;
    datafilm = fopen("datafilm.txt","r");

    while(fread(&film,sizeof(film),1,datafilm)==1){
        urutan_datafilm++;
    }
    fclose(datafilm);

    datafilm = fopen("datafilm.txt","a");
    printf("%i",urutan_datafilm);
    printf("Insert Data Film\n");
    printf("Masukkan Judul Film : ");
    fflush(stdin); gets(film[urutan_datafilm].judul_film);
    printf("Masukkan Genre Film : ");
    fflush(stdin); gets(film[urutan_datafilm].genre_film);
    printf("Masukkan Tahun Rilis Film : ");
    scanf("%i", &film[urutan_datafilm].tahunrilis_film);
    printf("Masukkan Sutradara Film : ");
    fflush(stdin); gets(film[urutan_datafilm].sutradara_film);
    printf("Masukkan Studio Film : ");
    fflush(stdin); gets(film[urutan_datafilm].studio_film);
    fwrite(&film,sizeof(film),1,datafilm);

    printf("Data berhasil ditambahkan\n");
    fclose(datafilm);
    printf("Lanjut atau selesai?\n");
        printf("1. Lanjut\n");
        printf("2. Selesai\n");
        printf("Pilihan anda = ");
        printf("\n");
        scanf("%i",&pilih);
        switch (pilih){
        case 1:
            home_admin();
            break;
        
        default:
            printf("Selesai^^");
            break;
        }
        return;
}

void read_datafilm(){

    FILE *datafilm;
    int jml_datafilm = 0;
    int pilih;
    datafilm = fopen("datafilm.txt","r");
    while(fread(&film,sizeof(film),1,datafilm)==1){
        jml_datafilm++;
    }
    fclose(datafilm);
    printf("Jumlah data : %i",jml_datafilm);

    datafilm = fopen("datafilm.txt","r");

    for (int i = 0; i < jml_datafilm; i++){
        printf("data ke : %i\n",i+1);
        printf("Judul : %s\n",film[i].judul_film);
        printf("Genre : %s\n",film[i].genre_film);
        printf("Tahun Rilis : %i\n",film[i].tahunrilis_film);
        printf("Sutradara : %s\n",film[i].sutradara_film);
        printf("Studio : %s\n",film[i].studio_film);
    }

    fclose(datafilm);
}

void update_datafilm(){

    int pilih;
    int c = 0;
    FILE *datafilm;
    char update_film[50];
    datafilm = fopen("datafilm.txt","rb+");
    printf("Masukkan Judul yang ingin di edit : ");
    fflush(stdin); gets(update_film);
    while(fread(&film,sizeof(film),1,datafilm)==1){
        if (strcasecmp(update_film,film[c].judul_film)==0){
            printf("Masukkan Judul Film : ");
            fflush(stdin); gets(film[c].judul_film);
            printf("Masukkan Genre Film : ");
            fflush(stdin); gets(film[c].genre_film);
            printf("Masukkan Tahun Rilis Film : ");
            scanf("%i", &film[c].tahunrilis_film);
            printf("Masukkan Sutradara Film : ");
            fflush(stdin); gets(film[c].sutradara_film);
            printf("Masukkan Studio Film : ");
            fflush(stdin); gets(film[c].studio_film);
            fseek(datafilm,-sizeof(film),SEEK_CUR);
            fwrite(&film,sizeof(film),1,datafilm);
            printf("Data Berhasil Diperbaharui^^\n");
            break;
        }
        c++;
    }
    fclose(datafilm);
    printf("Lanjut atau selesai?\n");
        printf("1. Lanjut\n");
        printf("2. Selesai\n");
        printf("Pilihan anda = ");
        printf("\n");
        scanf("%i",&pilih);
        switch (pilih){
        case 1:
            home_admin();
            break;
        
        default:
            printf("Selesai^^");
            break;
        }
        return;
    return;
}

void insert_requestfilm(){

    int pilih;
    int urutan_datafilm = 0;
    FILE *datarequestfilm;
    datarequestfilm = fopen("datarequestfilm.txt","r");

    while(fread(&requestfilm,sizeof(requestfilm),1,datarequestfilm)==1){
        urutan_datafilm++;
    }
    fclose(datarequestfilm);

    datarequestfilm = fopen("datarequestfilm.txt","a");
    printf("%i",urutan_datafilm);
    printf("Insert Data Film\n");
    printf("Masukkan Judul Film : ");
    fflush(stdin); gets(requestfilm[urutan_datafilm].judul_requestfilm);
    printf("Masukkan Tahun Rilis Film : ");
    scanf("%i", &requestfilm[urutan_datafilm].tahunrilis_requestfilm);
    printf("Masukkan Studio Film : ");
    fflush(stdin); gets(requestfilm[urutan_datafilm].studio_requestfilm);
    fwrite(&requestfilm,sizeof(requestfilm),1,datarequestfilm);

    printf("Data berhasil ditambahkan\n");
    fclose(datarequestfilm);
    printf("Lanjut atau selesai?\n");
        printf("1. Lanjut\n");
        printf("2. Selesai\n");
        printf("Pilihan anda = ");
        printf("\n");
        scanf("%i",&pilih);
        switch (pilih){
        case 1:
            home_user();
            break;
        
        default:
            printf("Selesai^^");
            break;
        }
        return;
}

void bubblesort_judulfilm(){

    int pilih;
    int jml_datafilm = 0;
    FILE *datafilm;
    datafilm = fopen("datafilm.txt","r");
    while(fread(&film,sizeof(film),1,datafilm)==1){
        jml_datafilm++;
    }
    
    for (int i = 0; i < jml_datafilm; i++){
        for (int j = 0; j < jml_datafilm-1; j++){
            if (strcmp(film[j].judul_film,film[j+1].judul_film)>0){
                char temp[50],temp1[50];int temp2;char temp3[50],temp4[50];
                strcpy(temp,film[j].judul_film);
                strcpy(film[j].judul_film,film[j+1].judul_film);
                strcpy(film[j+1].judul_film,temp);

                strcpy(temp1,film[j].genre_film);
                strcpy(film[j].genre_film,film[j+1].genre_film);
                strcpy(film[j+1].genre_film,temp1);

                temp2 = film[j].tahunrilis_film;
                film[j].tahunrilis_film = film[j+1].tahunrilis_film;
                film[j+1].tahunrilis_film = temp2;

                strcpy(temp3,film[j].sutradara_film);
                strcpy(film[j].sutradara_film,film[j+1].sutradara_film);
                strcpy(film[j+1].sutradara_film,temp3);

                strcpy(temp4,film[j].studio_film);
                strcpy(film[j].studio_film,film[j+1].studio_film);
                strcpy(film[j+1].judul_film,temp4);
            }
        }
    }
    
    for (int c = 0; c < jml_datafilm; c++){
        printf("data ke : %i\n",c+1);
        printf("Judul : %s\n",film[c].judul_film);
        printf("Genre : %s\n",film[c].genre_film);
        printf("Tahun Rilis : %i\n",film[c].tahunrilis_film);
        printf("Sutradara : %s\n",film[c].sutradara_film);
        printf("Studio : %s\n",film[c].studio_film);
    }
    
    fclose(datafilm);

    printf("Lanjut atau selesai?\n");
        printf("1. Lanjut\n");
        printf("2. Selesai\n");
        printf("Pilihan anda = ");
        printf("\n");
        scanf("%i",&pilih);
        switch (pilih){
        case 1:
            home_user();
            break;
        
        default:
            printf("Selesai^^");
            break;
        }
        return;
}

void selectionsort_genrefilm(){

    int pilih;
    int jml_datafilm = 0;
    int position;
    FILE *datafilm;
    datafilm = fopen("datafilm.txt","r");
    while(fread(&film,sizeof(film),1,datafilm)==1){
        jml_datafilm++;
    }

    for (int c = 0; c < jml_datafilm-1; c++){
        position = c;
            for (int d = c+1; d < jml_datafilm; d++){
                if (strcmp(film[position].genre_film,film[d].genre_film)>0){
                    position = d;
                }
            }
            if (position != c){
                char temp[50],temp1[50];int temp2;char temp3[50],temp4[50];
                
                strcpy(temp,film[c].judul_film);
                strcpy(temp1,film[c].genre_film);
                temp2 = film[c].tahunrilis_film;
                strcpy(temp3,film[c].sutradara_film);
                strcpy(temp4,film[c].studio_film);

                strcpy(film[c].judul_film,film[position].judul_film);
                strcpy(film[c].genre_film,film[position].genre_film);
                film[c].tahunrilis_film = film[position].tahunrilis_film;
                strcpy(film[c].sutradara_film,film[position].sutradara_film);
                strcpy(film[c].studio_film,film[position].studio_film);

                strcpy(film[position].judul_film,temp);
                strcpy(film[position].genre_film,temp1);
                film[position].tahunrilis_film = temp2;
                strcpy(film[position].sutradara_film,temp3);
                strcpy(film[position].studio_film,temp4);

            }
    }

    for (int c = 0; c < jml_datafilm; c++){
        printf("data ke : %i\n",c+1);
        printf("Judul : %s\n",film[c].judul_film);
        printf("Genre : %s\n",film[c].genre_film);
        printf("Tahun Rilis : %i\n",film[c].tahunrilis_film);
        printf("Sutradara : %s\n",film[c].sutradara_film);
        printf("Studio : %s\n",film[c].studio_film);
    }
    
    fclose(datafilm);

    printf("Lanjut atau selesai?\n");
        printf("1. Lanjut\n");
        printf("2. Selesai\n");
        printf("Pilihan anda = ");
        printf("\n");
        scanf("%i",&pilih);
        switch (pilih){
        case 1:
            home_user();
            break;
        
        default:
            printf("Selesai^^");
            break;
        }
        return;
}

void insertionsort_sutradarafilm(){
    
    int pilih;
    int d;
    int jml_datafilm = 0;
    FILE *datafilm;
    datafilm = fopen("datafilm.txt","r");
    while(fread(&film,sizeof(film),1,datafilm)==1){
        jml_datafilm++;
    }

    for(int c = 0; c < jml_datafilm; c++){
        char temp[50],temp1[50];int temp2;char temp3[50],temp4[50];
        strcpy(temp,film[c].judul_film);
        strcpy(temp1,film[c].genre_film);
        temp2 = film[c].tahunrilis_film;
        strcpy(temp3,film[c].sutradara_film);
        strcpy(temp4,film[c].studio_film);
        d = c-1;
            while (d>=0 && strcmp(film[d].sutradara_film,temp3)>0){
                strcpy(film[d+1].judul_film,film[d].judul_film);
                strcpy(film[d+1].genre_film,film[d].genre_film);
                film[d+1].tahunrilis_film = film[d].tahunrilis_film;
                strcpy(film[d+1].sutradara_film,film[d].sutradara_film);
                strcpy(film[d+1].studio_film,film[d].studio_film);
                d = d-1;
            }
            strcpy(film[d+1].judul_film,temp);
            strcpy(film[d+1].genre_film,temp1);
            film[d+1].tahunrilis_film = temp2;
            strcpy(film[d+1].sutradara_film,temp3);
            strcpy(film[d+1].studio_film,temp4);
    }

    fclose(datafilm);
}

void insertionsort_studiofilm(){

    int pilih;
    int d;
    int jml_datafilm = 0;
    FILE *datafilm;
    datafilm = fopen("datafilm.txt","r");
    while(fread(&film,sizeof(film),1,datafilm)==1){
        jml_datafilm++;
    }

    for(int c = 0; c < jml_datafilm; c++){
        char temp[50],temp1[50];int temp2;char temp3[50],temp4[50];
        strcpy(temp,film[c].judul_film);
        strcpy(temp1,film[c].genre_film);
        temp2 = film[c].tahunrilis_film;
        strcpy(temp3,film[c].sutradara_film);
        strcpy(temp4,film[c].studio_film);
        d = c-1;
            while (d>=0 && strcmp(film[d].studio_film,temp4)>0){
                strcpy(film[d+1].judul_film,film[d].judul_film);
                strcpy(film[d+1].genre_film,film[d].genre_film);
                film[d+1].tahunrilis_film = film[d].tahunrilis_film;
                strcpy(film[d+1].sutradara_film,film[d].sutradara_film);
                strcpy(film[d+1].studio_film,film[d].studio_film);
                d = d-1;
            }
            strcpy(film[d+1].judul_film,temp);
            strcpy(film[d+1].genre_film,temp1);
            film[d+1].tahunrilis_film = temp2;
            strcpy(film[d+1].sutradara_film,temp3);
            strcpy(film[d+1].studio_film,temp4);
    }
    fclose(datafilm);
}

void sequentialsearch_genrefilm(){

    int pilih;
    char search_genre[50];
    int jml_datafilm = 0;
    FILE *datafilm;
    datafilm = fopen("datafilm.txt","r");
    while(fread(&film,sizeof(film),1,datafilm)==1){
        jml_datafilm++;
    }

    printf("Masukkan genre yang ingin dicari : ");
    fflush(stdin); gets(search_genre);
    for (int i = 0; i < jml_datafilm; i++){
        if (StrStrIA(film[i].genre_film,search_genre)){
            printf("data ditemukan!\n");
            printf("Judul : %s\n",film[i].judul_film);
            printf("Genre : %s\n",film[i].genre_film);
            printf("Tahun Rilis : %i\n",film[i].tahunrilis_film);
            printf("Sutradara : %s\n",film[i].sutradara_film);
            printf("Studio : %s\n",film[i].studio_film);
        }
    }
       
}

void binarysearch_judulfilm(){
    
    int pilih;
    int d;
    char search_judul[50];
    int jml_datafilm = 0;
    FILE *datafilm;
    datafilm = fopen("datafilm.txt","r");
    while(fread(&film,sizeof(film),1,datafilm)==1){
        jml_datafilm++;
    }
    int j,k,l;
    j = 0;
    k = jml_datafilm - 1;
    char sementara[50];
    int status = 0;

    for(int c = 0; c < jml_datafilm; c++){
        char temp[50],temp1[50];int temp2;char temp3[50],temp4[50];
        strcpy(temp,film[c].judul_film);
        strcpy(temp1,film[c].genre_film);
        temp2 = film[c].tahunrilis_film;
        strcpy(temp3,film[c].sutradara_film);
        strcpy(temp4,film[c].studio_film);
        d = c-1;
            while (d>=0 && strcmp(film[d].judul_film,temp)>0){
                strcpy(film[d+1].judul_film,film[d].judul_film);
                strcpy(film[d+1].genre_film,film[d].genre_film);
                film[d+1].tahunrilis_film = film[d].tahunrilis_film;
                strcpy(film[d+1].sutradara_film,film[d].sutradara_film);
                strcpy(film[d+1].studio_film,film[d].studio_film);
                d = d-1;
            }
            strcpy(film[d+1].judul_film,temp);
            strcpy(film[d+1].genre_film,temp1);
            film[d+1].tahunrilis_film = temp2;
            strcpy(film[d+1].sutradara_film,temp3);
            strcpy(film[d+1].studio_film,temp4);
    }

    printf("Masukkan Judul yang ingin dicari : ");
    fflush(stdin); gets(search_judul);

    while (j<=k && status == 0){
        l = (j+k)/2;

        if (StrStrIA(film[l].judul_film,search_judul)){
            strcpy(sementara,film[l].judul_film);
        }
        if (strcmp(sementara,film[l].judul_film)==0){
            printf("data ditemukan!\n");
            printf("Judul : %s\n",film[l].judul_film);
            printf("Genre : %s\n",film[l].genre_film);
            printf("Tahun Rilis : %i\n",film[l].tahunrilis_film);
            printf("Sutradara : %s\n",film[l].sutradara_film);
            printf("Studio : %s\n",film[l].studio_film);
            status = 1;
        }else if (strcmp(search_judul,film[l].judul_film)>0){
            j = l+1;
        }else{
            k = l-1;
        }
    }
    
}

void jumpsearch_sutradarafilm(){

    int pilih,d;
    char search_sutradarafilm[50];
    int jml_datafilm = 0;
    FILE *datafilm;
    datafilm = fopen("datafilm.txt","r");
    while(fread(&film,sizeof(film),1,datafilm)==1){
        jml_datafilm++;
    }

    int length = jml_datafilm;
    int jump = sqrt(length);
    int jumper = jump;

    for(int c = 0; c < jml_datafilm; c++){
        char temp[50],temp1[50];int temp2;char temp3[50],temp4[50];
        strcpy(temp,film[c].judul_film);
        strcpy(temp1,film[c].genre_film);
        temp2 = film[c].tahunrilis_film;
        strcpy(temp3,film[c].sutradara_film);
        strcpy(temp4,film[c].studio_film);
        d = c-1;
            while (d>=0 && strcmp(film[d].sutradara_film,temp3)>0){
                strcpy(film[d+1].judul_film,film[d].judul_film);
                strcpy(film[d+1].genre_film,film[d].genre_film);
                film[d+1].tahunrilis_film = film[d].tahunrilis_film;
                strcpy(film[d+1].sutradara_film,film[d].sutradara_film);
                strcpy(film[d+1].studio_film,film[d].studio_film);
                d = d-1;
            }
            strcpy(film[d+1].judul_film,temp);
            strcpy(film[d+1].genre_film,temp1);
            film[d+1].tahunrilis_film = temp2;
            strcpy(film[d+1].sutradara_film,temp3);
            strcpy(film[d+1].studio_film,temp4);
    }

    printf("Masukkan Nama Sutradara yang ingin dicari : ");
    fflush(stdin); gets(search_sutradarafilm);
    int prev = 0;
    while (strcmp(film[jumper].sutradara_film,search_sutradarafilm)<=0 && jumper < length){

        prev = jumper;
        jumper += jump;

    }

    int status = 0;
    for (int i = prev; i <= jumper; i++){
        if(StrStrIA(film[i].sutradara_film,search_sutradarafilm)){
            status = 1;
            printf("Judul : %s\n",film[i].judul_film);
            printf("Genre : %s\n",film[i].genre_film);
            printf("Tahun Rilis : %i\n",film[i].tahunrilis_film);
            printf("Sutradara : %s\n",film[i].sutradara_film);
            printf("Studio : %s\n",film[i].studio_film);
        }
    }
    if(status == 0){
        printf("data tidak ditemukan!");
    }
}

void interpolationsearch_tahunrilisfilm(){

    int pilih,d;
    int search_tahunrilisfilm;
    int jml_datafilm = 0;
    FILE *datafilm;
    datafilm = fopen("datafilm.txt","r");
    while(fread(&film,sizeof(film),1,datafilm)==1){
        jml_datafilm++;
    }
    int low = 0;
    int high = jml_datafilm-1;
    int position;
    int status = 0;

    for(int c = 0; c < jml_datafilm; c++){
        char temp[50],temp1[50];int temp2;char temp3[50],temp4[50];
        strcpy(temp,film[c].judul_film);
        strcpy(temp1,film[c].genre_film);
        temp2 = film[c].tahunrilis_film;
        strcpy(temp3,film[c].sutradara_film);
        strcpy(temp4,film[c].studio_film);
        d = c-1;
            while (d>=0 && film[d].tahunrilis_film > temp2){
                strcpy(film[d+1].judul_film,film[d].judul_film);
                strcpy(film[d+1].genre_film,film[d].genre_film);
                film[d+1].tahunrilis_film = film[d].tahunrilis_film;
                strcpy(film[d+1].sutradara_film,film[d].sutradara_film);
                strcpy(film[d+1].studio_film,film[d].studio_film);
                d = d-1;
            }
            strcpy(film[d+1].judul_film,temp);
            strcpy(film[d+1].genre_film,temp1);
            film[d+1].tahunrilis_film = temp2;
            strcpy(film[d+1].sutradara_film,temp3);
            strcpy(film[d+1].studio_film,temp4);
    }

    for (int i = 0; i < jml_datafilm; i++){
        printf("%i\n",film[i].tahunrilis_film);
    }
    
    printf("Masukkan tahun rilis yang ingin kamu cari : ");
    scanf("%i",&search_tahunrilisfilm);

    while (low <= high){
        
        position = low+((search_tahunrilisfilm-film[low].tahunrilis_film)/(film[high].tahunrilis_film-film[low].tahunrilis_film))*(high-low);

        if (film[position].tahunrilis_film == search_tahunrilisfilm){
            printf("Judul : %s\n",film[position].judul_film);
            printf("Genre : %s\n",film[position].genre_film);
            printf("Tahun Rilis : %i\n",film[position].tahunrilis_film);
            printf("Sutradara : %s\n",film[position].sutradara_film);
            printf("Studio : %s\n",film[position].studio_film);
            status = 1;
            break;
        }else if(film[position].tahunrilis_film > search_tahunrilisfilm){
            high = position - 1;
        }else{
            low = position + 1;
        }
    }

    if (status == 0){
        printf("data tidak ditemukan!");
    }
    
}
