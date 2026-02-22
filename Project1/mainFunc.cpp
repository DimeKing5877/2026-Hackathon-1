#include "Header.hpp"
#include "UIHeader.hpp"
//prints the main menu options for the user
void mainmenu(void) {
	std::cout << "main menu: " << std::endl;
	std::cout << "1.) Print all information" << std::endl;
	std::cout << "2.) Print only set Sites" << std::endl;
	std::cout << "3.) Print only set email" << std::endl;
	std::cout << "4.) Delete entry" << std::endl;
	std::cout << "5.) insert new entry" << std::endl;
	std::cout << "6.) edit existing entry" << std::endl;
	std::cout << "7.) generate a new Key" << std::endl;
	std::cout << "8.) save and exit" << std::endl;
}

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

void editExistingEntry(Node** pHead) {
	system("cls");
	//print linked list
	LinkList list;
	list.displayFull(*pHead);
	//initilize values for user input
	int value;
	std::cout << "Enter the value of the entry you want to edit: ";
	std::cin >> value;
	Node* pCur = list.search(*pHead, value);
	if (pCur != NULL) {
		edit(pCur);
	}
	else {
		std::cout << "Entry not found." << std::endl;
	}
}

void edit(Node* pCur) {
	//propmt user for what they want to edit and get new data for the entry
	int answer = 0;
	std::cout << "1) Website!" << std::endl;
	std::cout << "2) Email! " << std::endl;
	std::cout << "3) Username! " << std::endl;
	std::cout << "4) Password! " << std::endl;
	std::cout << "5) Date! " << std::endl;
	std::cout << "What would you like to edit?" << std::endl;
	if (std::cin >> answer) {
		std::cin.ignore();
		switch (answer) {
		case 1:
			getWebsite(pCur->data.website);
			break;
		case 2:
			getEmail(pCur->data.email);
			break;
		case 3:
			getUsername(pCur->data.username);
			break;
		case 4:
			getPassword(pCur->data.password);
			break;
		case 5:
			getDate(pCur->data.date);
			break;
		default:
			std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
	else {
		std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void getNewEncriptionKey(char* charKey) {
	std::string filename = "encripted.txt";
	//gnerates a new random key for the user
	std::string userKey = generateIncriptionKey();
	//pritn user key
	std::cout << "User key: " << userKey << std::endl;
	//convert user key to char array
	strcpy(charKey, userKey.c_str());
	system("pause");
}