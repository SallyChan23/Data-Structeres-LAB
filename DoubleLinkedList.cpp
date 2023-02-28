#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct User{
    char name[51];
    int age;
    User* next;
    User* prev;
}*head = NULL, *tail = NULL;

User* createNewUser(char name[], int age){
    User* newUser = (User*) malloc (sizeof(User));
    strcpy(newUser -> name, name);
    newUser -> age = age;
    newUser -> next = NULL;
    newUser -> prev = NULL;
    return newUser;
}

void pushHead(char name[], int age){
    User* newUser = createNewUser(name, age);
    if(head == NULL){
        head = tail = newUser;
        return;
    }else{
        User* curr = head;
        while(strcmp(curr -> next -> name, newUser -> name) < 0){
            curr = curr;
        }
    }

    newUser -> next = head;
    head -> prev = newUser;
    head = newUser;
}
void pushMid(char name[]p, int age)[{
    User* newUser = createNewUser(name, age);
    if(head == NULL){
        head = tail = newUser;
        return;
    }
}

void pushTail(char name[], int age){
    User* newUser = createNewUser(name, age);
    if(head == NULL){
        head = tail = newUser;
        return;
    }
    newUser -> prev = tail;
    tail -> next = newUser;
    tail = newUser;
}

void popHead(){
    if(head == NULL){
        return;
    }
    if(head == tail){
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }
    User* temp = head;
    head = temp -> next;
    temp -> next = NULL;
    temp -> prev = NULL;

    free(temp);
    temp = NULL;
}

void popTail(){
    if(head == NULL){
        return;
    }
    if(head == tail){
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }
    USer* temp = tail;
    tail = temp -> prev;
    tail -> next = NULL:
    free(temp);
    temp = NULL;
}

void printAll(){
    User* curr = head;
    while(curr != NULL){
        printf("Name: %s, age: %d\n", curr -> name, curr -> age);
        curr = curr -> next;
    }
}


int main(){
    // pushHead("Budi", 19);
    // pushHead("Andi", 20);
    // pushHead("Jordy", 20);
    pushTail("Budi", 19);
    pushTail("Andi", 20);
    pushTail("Jordy", 20);
}