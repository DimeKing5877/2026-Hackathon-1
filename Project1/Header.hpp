#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>

#define PASS_SIZE 20
#define SITE_SIZE 20
#define DATE_SIZE 14
#define email_SIZE 50
#define USERNAME_SIZE 20
#define LINE_SIZE 150

typedef struct Passdata {
	char password[PASS_SIZE];
	char website[SITE_SIZE];
	char date[DATE_SIZE];
	char email[email_SIZE];
	char username[USERNAME_SIZE];

}Data;

typedef struct memnode {
	Data data;
	struct memnode *pNext;
	struct memnode* pPrev;
}Node;



class LinkList {
public:


	void linkFunCall(int selection, Node** pHead);
	int loadlist(Node** pHead, FILE* inputStream, char* key);


	//functions
	int insertatfront(Node** pHead, Data info);
	Node* creatNode(Data info);
	void clearList(Node** pHead);//list should not be empty

	void savelist(Node* pHead, FILE* outStream, char* key);

	void displayFull(Node* pHead);
	void displayType(Node* pHead, char* type);

	void deleteNode(Node** pHead, Node* pCur);
	int insert(Node** pHead, FILE* inputStream);
	void edit(Node* pHead);



};


class keycreation {
public:
	Data encryption(Data info, char* key);
	Data dectyption(Data info, char* key);

private:
	char* encrypt(char* info, char* key, int size);
	char* decrypt(char* info, char* key, int size);
};
