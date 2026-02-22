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

	int loadlist(Node** pHead, FILE* inputStream, char* key);

	Data loadLine(char* line);


	//functions
	int insertatfront(Node** pHead, Data info);
	Node* creatNode(Data info);
	void clearList(Node** pHead);//list should not be empty

	void savelist(Node* pHead, FILE* outStream, char* key);

	void displayFull(Node* pHead);
	void displayEmail(Node* pHead, char* email);
	void displaySite(Node* pHead, char* site);


	Node* search(Node* pHead, int value);
	void deleteNode(Node** pHead, Node* pCur);
	int insert(Node** pHead, FILE* inputStream);



};


class keycreation {
public:
	Data encryption(Data info, char* key);
	Data dectyption(Data info, char* key);

	char* encrypt(char* info, char* key, int size);
	char* decrypt(char* info, char* key, int size);
};



//Function prototypes
//prints options for the user to select from
void mainmenu(void);

//functions that collect user iputed data for the website, email, username, password, and date
void getWebsite(char* websiteDestination);
void getEmail(char* emailDestination);
void getUsername(char* usernameDestination);
void getPassword(char* passwordDestination);
void getDate(char* dateDestination);
void insertUserData(Node** pList);
void editExistingEntry(Node** pHead);
void edit(Node* pCur);