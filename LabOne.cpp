#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
struct user{
    int age;
    char name[100];
    struct user *next;
}*head = NULL, *tail = NULL;

struct user *newUser(int age, char name[100]){
    // reserve
    struct user *node = (user*) malloc (sizeof(struct user));
    // copy data ke dalam bubble
    node -> age = age;
    strcpy(node -> name, name);

    //buat ekor atau bubble baru
    node -> next = NULL;
    return node;
}

void pushHead(int age, char name[]){
    //buat bubble kosongnya + isinya
    struct user *node = newUser(age, name);

    //cek ada data atau engga
    if(head == NULL){
        head = tail = node;

    }else{
        node -> next = head;
        head = node;
    }
}

void pushTail(int age, char name[]){
    struct user *node = newUser(age, name);
    if(head == NULL)
        head = tail = NULL;
    else{
        tail -> next = node;
        tail = node;
    }
}

void pushMid(int age, char name[]){
    struct user *node = newUser(age, name);
    if(head == NULL){
        head = tail = node;
    }else if(age < head -> age){
        pushHead(age, name);
    }else if(age >= tail -> age){
        pushTail(age, name);
    }else{
        struct user *curr = head;
        while(curr -> next != NULL && curr -> next -> age < age){
            curr = curr -> next;
        }
        node -> next = curr -> next;
        curr -> next = node;
    }
}

void popHead(){
    if(head == NULL){
        return;
    }else if(head == tail){ //data cuman satu   
        free(head);
        head = tail = NULL;
    }
    // data lebih dari satu
    else{
        struct user *temp = head;
        head = head -> next;
        free(temp);
    }
}

void popTail(){
    if(head == NULL){
        return;
    }else if(head == tail){
        free(head);
        head = tail = NULL;
    }else{
        struct user *curr = head;
        while(curr -> next != tail){
            curr = curr -> next;
        }
        free(curr -> next);
        curr -> next = NULL;
        curr = tail;
    }
}

void popMid(int age){
    if(head == NULL){
        return;
    }else{
        if(head -> age == age){
            popHead();
        }else if(tail -> age == age){
            popTail();
        }else{
            struct user *curr = head;
            while(curr -> next != NULL & curr -> next -> age != age){
                curr = curr -> next;
            }
            if(curr -> next == NULL){
                printf("Not Found\n");
                return;
            }
            struct user *temp = curr -> next;
            curr -> next = temp -> next;
            free(temp);
            return;
        }
    }
}

void printAll(){
    if(head == NULL){
        puts("No Data");
    }
    struct user *curr = head;
    while(curr != NULL){
        printf("Age: %d, Name: %s\n", curr->age, curr->name);
        curr = curr -> next;
    }
}

// stack = push head(add yang baru) dan pop head (delete)

int main(){
    // pushHead(10, "Tata");
    // pushHead(12, "Jordy");
    // pushHead(9, "Gabriellas");
    // pushTail(21, "Titi");

    pushMid(1, "Bebe");
    pushMid(3, "Bobo");
    pushMid(2, "Bibi");
    printAll();
    // popHead();
    // puts("After pop Head");
    // printAll();
    // puts("After pop tail");
    // popTail();
    // printAll();
    puts("After pop mid");
    popMid(2);
    printAll();

    return 0;
}