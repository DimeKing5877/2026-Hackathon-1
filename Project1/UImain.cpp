#include "UIHeader.hpp"

std::string userKeyEntry(const std::string& filename) {
	//declare a string variable to hold the user input for the encription key
	std::string userKey;
	//empty string
	std::string emptyString = "";
	//CHeck if the encripted file is empty
	std::string fileKey = checkEncryptedList(filename);
	if (fileKey != emptyString) {
		//file is not empty, so we can sort list into a linked list
		userKey = promptUserForKey();
		int checkKey = checkUserKey(userKey, fileKey);
		if (checkKey != 1) {
			//the keys do not match, so we can display an error message and prompt again
			std::cout << "The encription keys do not match. Please try again." << std::endl;
			system("pause");
			userKeyEntry(filename);
		}
	}
	else {
		//file is empty, so we need to generate an encription key before exepting user input
		userKey = generateEncryptionKey();
	}
	return userKey;
}
int checkUserKey(const std::string& userKey, const std::string& fileKey) {
	//check if the user input key matches the key in the encripted file, returns 1 if the keys match, 0 if the keys do not match
	if (userKey == fileKey) {
		std::cout << "The encription keys match. You can proceed with the encription process." << std::endl;
		return 1;
	}
	else {
		return 0;
	}
}
//checks if the encripted file is empty or not, returns 1 if the file is not empty, 0 if the file is empty, 
// and -1 if there was an error opening the file
std::string checkEncryptedList(const std::string& filename) {
	//empty string
	std::string emptyString = "";
	//declare a string variable to hold the first line of the encripted file being the key
	std::string line;
	//open the file and check if it is empty
	std::ifstream encFile(filename);
	if (encFile.is_open()){
		std::getline(encFile, line);
		if (line.empty()) {
			//if the file is empty, return 0
			return emptyString;
		}
		else {
			//if the file is not empty, return 1
			return line;
		}
	}
	else {
		//file open failed
		std::cout << "Error opening the encripted file." << std::endl;
	}
	//close the file
	encFile.close();
}
//prmpt the user for the encription key and return the key as a string
std::string promptUserForKey() {
	system("cls"); //clear the console screen
	//prompt the user for the encription key
	std::string userKey;
	std::cout << "Please enter the encription key: ";
	if (std::cin >> userKey) {
		//if the user input is valid, we can proceed with the encription process
		std::cout << "You entered: " << userKey << std::endl;
	}
	else {
		//if the user input is invalid, we can display an error message and prompt again
		std::cout << "Invalid input. Please enter a valid encription key." << std::endl;
		promptUserForKey();
	}
	return userKey;
}
//generatesw a random encription key and saves it to the encripted file, returns the generated key as a string
std::string generateEncryptionKey(){
	//generate a random encription key and save it to the encripted file
	std::string key;
	const int keyLength = 16; //length of the encription key
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; //characters to use in the encription key
	srand(time(0)); //seed the random number generator
	for (int i = 0; i < keyLength; i++) {
		key += charset[rand() % (sizeof(charset) - 1)]; //generate a random character and add it to the key
	}
	//save the generated key to the encripted file
	return key;
}
