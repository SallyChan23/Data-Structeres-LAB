#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50
struct mahasiswa{
    char name[100];
    int score;
    mahasiswa *next, *prev;
}*head[SIZE], *tail[SIZE];

struct mahasiswa *newMahasiswa(char name[], int score){
    struct mahasiswa *node = (mahasiswa*) malloc(sizeof(mahasiswa));
    strcpy(node -> name, name);
    node -> score = score;
    node -> next = node -> prev = NULL;
    return node;

    return node;
}

int hash(char name[]){
    int hashkey = 0;
    int len = strlen(name);
    for(int i = 0; i < len; i++){
        hashkey += name[i];
    }
    return hashkey % SIZE;
}

void insert(char name[], int score){
    int index = hash(name);
    struct mahasiswa *node = newMahasiswa(name, score);

    if(head[index] == NULL){
        head[index] = tail[index] = node;
    }
    //collision
    else{
        //push tail
        tail[index] -> next = node;
        node -> prev = tail[index];
        tail[index] = node;
    }
}

void view(){
    struct mahasiswa *curr;
    for(int i = 0; i < SIZE; i++){
        if(head[i] != NULL){
            curr = head[i];
            while(curr){
                printf("Name: %s, Score: %d\n", curr -> name, curr -> score);
                curr = curr -> next;
            }
        }
    }
}

void removers(char name[]){
    int hashkey = hash(name);
    struct mahasiswa *curr, *temp;

    if(head[hashkey] == NULL){
        printf("Data Not Found!\n");
        return;
    }else{
        //pop head
        if(strcmp(head[hashkey] -> name, name) == 0){
            if(head[hashkey] == tail[hashkey]){
                free(head[hashkey]);
                head[hashkey] = tail[hashkey] = NULL;
            }else{
                temp = head[hashkey];
                head[hashkey] = head[hashkey] -> next;
            }
        }
        //pop tail
        else if(strcmp(tail[hashkey] -> name, name) == 0){
            temp = tail[hashkey];
            tail[hashkey] = tail[hashkey] -> prev;
            free(temp);
            tail[hashkey] -> next = NULL;
        }
        //pop mid
        else{
            curr = head[hashkey];
            while(curr){
                if(strcmp(curr -> name, name) == 0){
                    temp = curr -> next;
                    temp -> prev = curr -> prev;
                    curr -> prev -> next = temp;
                    free(curr);
                    break;
                }
                curr = curr -> next;
            }
        }
    }
}

int main(){
    insert("Gaby", 80);
    insert("Jordy", 90);
    insert("Gabriella", 100);
    insert("Gab", 80);
    view();
    puts(" ");
    puts("After Delete\n");
    removers("Jordy");
    view();
    return 0;
}
