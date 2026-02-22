#include "Header.hpp"
#include "UIHeader.hpp"



int main(void) {
	Node* pHead = NULL;
	int answer = 0;
	LinkList list;
	keycreation incription;
	char key[16] = "";
	int success = 0;

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
void UImain() {
	std::string filename = "encripted.txt";
	//checks if the user has a key or needs to generat one
	std::string userKey = userKeyEntry(filename);
	//pritn user key
	std::cout << "User key: " << userKey << std::endl;
	system("pause");
}