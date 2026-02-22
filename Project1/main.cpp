#include "Header.hpp"
#include "UIHeader.hpp"



int main(void) {
	//UImain();
	//encription key char array
	char encriptionKey[16] = "";
	getEncriptionKey(encriptionKey);




	//key is checked


	FILE* inStream = fopen(".txt", "r");

	success = list.loadlist(&pHead, inStream, key);


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

			break;
		case 5:

			break;
		case 6:

			break;
		
		case 7:

			break;
		}
	}

	list.savelist(pHead, outFile, key);

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