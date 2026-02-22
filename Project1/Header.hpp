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


//all data stored in the linked list
typedef struct Passdata {
	char password[PASS_SIZE];
	char website[SITE_SIZE];
	char date[DATE_SIZE];
	char email[email_SIZE];
	char username[USERNAME_SIZE];

}Data;

//Node to be made in the heap as a link list
typedef struct memnode {
	Data data;
	struct memnode *pNext;
	struct memnode* pPrev;
}Node;


//all functions to make and manige the linked list
class LinkList {
public:

	//reads encripted file and loads
	int loadlist(Node** pHead, FILE* inputStream, char* key);

	//takes in a read "line" and seperates it into data feilds
	Data loadLine(char* line);


	//creats a node for data and insets it at the front of a linked list
	int insertatfront(Node** pHead, Data info);
	//creats a node in the heap
	Node* creatNode(Data info);
	//cleans out the linked list
	void clearList(Node** pHead);//list should not be empty
	//encryps and saves all data in the linked list ans reads it to a file
	void savelist(Node* pHead, FILE* outStream, char* key);
	//cleans line for next use
	void cleanline(char* line);
	//displays eveything in the linked list to system window
	void displayFull(Node* pHead);
	//displays all of a specified email in the linked list to system window
	void displayEmail(Node* pHead, char* email);
	//displays all of a specified website in the linked list to system window
	void displaySite(Node* pHead, char* site);
	//searches the linked list for a node given a value
	Node* search(Node* pHead, int value);
	//deletes a given node in the linked list
	void deleteNode(Node** pHead, Node* pCur);
	//allows user to insert a new entry into the linked list
	int insert(Node** pHead, FILE* inputStream);

};

//hold the functions to encrypt and decrypt the data
class keycreation {
public:
	//takes in a full data node and encryps all of its entrys
	Data encryption(Data info, char* key);
	//takes in a full data node and decryps all of its entrys
	Data dectyption(Data info, char* key);
	//takes in a data point and encryps it 
	char* encrypt(char* info, char* key, int size);
	//takes in a data point and encryps it 
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