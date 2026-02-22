#include "Header.hpp"
#include "UIHeader.hpp"

//gets user input for website, email, username, password, and date, 
// then creates a new node with the user input and inserts it at the front of the linked list
void insertUserData(Node** pList) {
	system("cls");
	Data info;
	LinkList list;
	//get new line from file to clear buffer
	std::cin.ignore();
	getWebsite(info.website);
	getEmail(info.email);
	getUsername(info.username);
	getPassword(info.password);
	getDate(info.date);
	list.insertatfront(pList, info);
}

void getEncriptionKey(char* charKey) {
	std::string filename = "encripted.txt";
	//checks if the user has a key or needs to generat one
	std::string userKey = userKeyEntry(filename);
	//pritn user key
	std::cout << "User key: " << userKey << std::endl;
	//convert user key to char array
	strcpy(charKey, userKey.c_str());
	system("pause");
}