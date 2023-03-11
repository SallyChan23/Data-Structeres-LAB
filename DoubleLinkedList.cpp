// Queue -> Push Head + Pop Tail (First in first out / FIFO)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct User{
	char name[51];
	int age;
	User *next;
	User *prev;
}*head = NULL, *tail = NULL;

User *createNewUser(char name[], int age){
	User *newUser = (User*)malloc(sizeof(User));
	strcpy(newUser->name, name);
	newUser->age = age;
	newUser->next = NULL;
	newUser->prev = NULL;
	return newUser;
}

void pushHead(char name[], int age){
	User *newUser = createNewUser(name, age);
	if(!head){
		head = tail = newUser;
		return;
	}
	else{
		newUser->next = head;
		head->prev = newUser;
		head = newUser;
	}
}

void pushTail(char name[], int age){
	User *newUser = createNewUser(name, age);
	if(!head){
		head = tail = newUser;
		return;
	}
	else{
		tail->next = newUser;
		newUser->prev = tail;
		tail = newUser;
	}
}

void pushMid(char name[], int age){
	User *newUser = createNewUser(name, age);
	
	if(!head){
		head = tail = newUser;
		return;
	}
	else if(strcmp(newUser->name, head->name) < 0){
		pushHead(name, age);
	}
	else if(strcmp(newUser->name, tail->name) > 0){
		pushTail(name, age);
	}
	else{
		User *curr = head;
		while(strcmp(curr->next->name, newUser->name) < 0){
			curr = curr->next;
		}
		User *afterCurr = curr->next;
		afterCurr->prev = newUser;	//curr->next->prev = newUser;
		newUser->next = afterCurr;	//newUser->next = curr->next;
		curr->next = newUser;
		newUser->prev = curr;
	}
}

void popHead(){
	if(!head){
		return;
	}
	else if(head == tail){
		free(head);
		head = tail = NULL;
		return;
	}
	User *temp = head;
	head = temp->next;
	
	temp->next = NULL;
	head->prev = NULL;
	
	free(temp);
	temp = NULL;
}

void popTail(){
	if(!head){
		return;
	}
	else if(head == tail){
		free(head);
		head = tail = NULL;
		return;
	}
	User *temp = tail;
	tail = temp->prev;
	
//	temp->prev = NULL;
	tail->next = NULL;
	
	free(temp);
	temp = NULL;
}

void popMid(char deleteName[]){
	if(!head){
		return;
	}
	else if(head == tail){
		free(head);
		head = tail = NULL;
		return;
	}
	else if(strcmp(deleteName, head->name) == 0){
		popHead();
		return;
	}
	else if(strcmp(deleteName, tail->name) == 0){
		popTail();
		return;
	}
	
	User *curr = head;
	while(curr != NULL && strcmp(curr->name, deleteName) != 0){
		curr = curr->next;
	}
	
	if(curr == NULL){
		printf("Data Not Found!\n");
		return;
	}
	
	User *before = curr->prev;
	User *after = curr->next;
	
	before->next = after;
	after->prev = before;
	
	curr->prev = NULL;
	curr->next = NULL;
	
	free(curr);
	curr = NULL;
}

void printAll(){
	User *curr = head;
	
	if(!head){
		printf("No data...");
	}

	while(curr){
		printf("%s %d\n", curr->name, curr->age);
		curr=curr->next;
	}
}

int main(){
	
//	pushHead("Budi", 19);
//	pushHead("Andi", 20);
//	pushHead("Jordy", 20);

//	pushTail("Budi", 19);
//	pushTail("Andi", 20);
//	pushTail("Jordy", 20);
//	
	pushMid("Budi", 19);
	pushMid("Andi", 20);
	pushMid("Jordy", 20);
	pushMid("Doni", 20);
	
	printAll();
	
	printf("\nAfter Delete\n");
	popHead();
	printAll();
	
	printf("\nAfter Delete\n");
	popTail();
	printAll();

	printf("\nAfter Delete\n");
	popMid("Budi");
	printAll();
	
	return 0;
}