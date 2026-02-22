#include "Header.hpp"
#include "UIHeader.hpp"



int main(void) {
	//UImain();
	//encription key char array
	char encriptionKey[16] = "";
	getEncriptionKey(encriptionKey);





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