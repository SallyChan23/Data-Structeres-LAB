#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

int count = 0;

struct mahasiswa{
    char name[100];
    int score;
}*array[SIZE];

struct mahasiswa *newMahasiswa(char name[], int score){
    struct mahasiswa *node = (mahasiswa*)malloc(sizeof(mahasiswa));
    strcpy(node -> name, name);
    node -> score = score;
    return node;
}

int hash (char name[]){
    int hashkey = 0;
    int len = strlen(name);
    for(int i = 0; i < len; i++){
        hashkey += name[i];
    }
    return hashkey % SIZE;
}

void insert(char name[], int score){
    int index = hash(name);
    
    //array full
    if(count == SIZE){
        printf("Array Full");
    }

    //collesion
    while(array[index] != NULL){
        index = (index  + 1) % SIZE;
    }

    //lacinya kosong
    array[index] = newMahasiswa(name, score);
    count++;
}

void view(){
    for(int i = 0; i < SIZE; i++){
        if(array[i] != NULL){
            printf("Name: %s\n", array[i] -> name);
            printf("Score: %d\n", array[i] -> score);
            printf("Key: %d\n", hash(array[i] -> name));
        }else{
            printf("\n");
        }
    }
}

int main(){
    insert("Gaby", 60);
    insert("Jordy", 90);
    return 0;
}