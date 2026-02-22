<<<<<<< Updated upstream
#include "Header.hpp"
=======
#include "Header.hpp"
#include "UIHeader.hpp"



int main(void) {
	//UImain();
	//encription key char array
	char encriptionKey[16] = "";
	getEncriptionKey(encriptionKey);


	LinkList list;
	Node* pHead = NULL;
	int answer = 0, success = 0;


	
	if (checkEncriptedList("encripted.txt") != "") {//file is empty
		FILE* inStream = fopen("encripted.txt", "r");
		if (inStream != NULL) {
			success = list.loadlist(&pHead, inStream, encriptionKey);
			fclose(inStream);
		}
	}

	while (answer != 8) {
		mainmenu();
		//input is asked and checked
		switch (answer) {
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:
			list.displayFull(pHead);
			int value = 0;
			std::cout << "Which to delete(entry #)" << std::endl;
			if (std::cin >> value) {
				list.deleteNode(&pHead, list.search(pHead, value));
			}
			break;
		case 5:

			break;
		case 6:

			break;

		case 7:

			break;

		case 8://exit
			if (pHead != NULL) {
				FILE* outFile = fopen("encripted.txt", "w");
				if (outFile != NULL) {
					list.savelist(pHead, outFile, encriptionKey);
				}
				fclose(outFile);
			}
			break;
		}
	}
	if (pHead != NULL) {
		list.clearList(&pHead);
	}

	

	return 0;
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
>>>>>>> Stashed changes
