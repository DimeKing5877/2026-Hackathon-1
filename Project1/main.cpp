#include "Header.hpp"
#include "UIHeader.hpp"

int main(void) {
	//UImain();
	//encription key char array
	char encriptionKey[16] = "";
	getEncriptionKey(encriptionKey);

	//key is checked
	int success = 1;
	int answer = 0;
	LinkList list;
	Node* pHead = NULL;
	system("cls");
	
	if (checkEncriptedList("encripted.txt") != "") {//file is empty
		FILE* inStream = fopen("encripted.txt", "r");
		if (inStream != NULL) {
			success = list.loadlist(&pHead, inStream, encriptionKey);
			fclose(inStream);
		}
	}

	if (success == 1) {
		while (answer != 8) {
			system("cls");
			//print incription key
			std::cout << "Encription key: " << encriptionKey << std::endl;
			//print main menu
			mainmenu();
			//prompt user for input and check if it is valid
			std::cout << "Enter your selection: ";
			//get user input
			if (std::cin >> answer) {
				//input is asked and checked
				switch (answer) {
				case 1:
					list.displayFull(pHead);
					break;
				case 2:
					if (pHead != NULL) {
						system("cls");
						std::string site;
						char siteChr[SITE_SIZE] = "";
						std::cout << "what site would you like to search: ";
						if (std::cin >> site) {
							//converts string to char array
							strcpy(siteChr, site.c_str());
							//searches for site and displays entry
							list.displayEmail(pHead, siteChr);
						}
						system("pause");
						system("cls");
					}
					break;
				case 3:
					if (pHead != NULL) {
						std::string email;
						char emailChr[email_SIZE] = "";
						std::cout << "what email would you like to search" << std::endl;
						if (std::cin >> email) {
							//converts string to char array
							strcpy(emailChr, email.c_str());
							//searches for email and displays entry
							list.displayEmail(pHead, emailChr);
						}
						system("pause");
						system("cls");
					}
					break;
				case 4:
					int value = 0;
					list.displayFull(pHead);
					std::cout << "What entry would you like to delete: ";
					if (std::cin >> value) {
						list.deleteNode(&pHead, list.search(pHead, value));
					}
					else {
						std::cout << "delete failed: " ;
					}
					system("pause");
					system("cls");
					break;
				case 5:
					insertUserData(&pHead);
					break;
				case 6:
					editExistingEntry(&pHead);
					break;

				case 7:
					getNewEncriptionKey(encriptionKey);
					break;
				case 8://exit
					if (pHead != NULL) {
						FILE* outFile = fopen("encripted.txt", "w");
						if (outFile != NULL) {
							list.savelist(pHead, outFile, encriptionKey);
							fclose(outFile);
						}
					}
					break;
				}
			}
			else {
				std::cout << "Invalid input. Please enter a number between 1 and 7." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
	}
	else {
		std::cout << "Failed to load the encripted file. Please check the file and the encription key." << std::endl;
	}

	if (pHead != NULL) {
		list.clearList(&pHead);
	}
	return 0;
}