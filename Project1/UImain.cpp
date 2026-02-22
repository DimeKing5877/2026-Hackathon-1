#include "UIHeader.hpp"

void UImain() {
	//checks if the user has a key or needs to generat one
	std::string userKey = userKeyEntry();


}
std::string userKeyEntry(const std::string& filename) {
	//declare a string variable to hold the user input for the encription key
	std::string userKey;
	//CHeck if the encripted file is empty
	int checkEncript = checkEncriptedList(filename);
	if (checkEncript == 1) {
		//file is not empty, so we can sort list into a linked list
		userKey = promptUserForKey();
		//int checkKey = checkUserKey();
	}
	else if (checkEncript == 0) {
		//file is empty, so we need to generate an encription key before exepting user input
		userKey = generateIncriptionKey();
	}
	else {
		std::cout << "Error checking the encripted file." << std::endl;
	}
	return userKey;
}

//checks if the encripted file is empty or not, returns 1 if the file is not empty, 0 if the file is empty, 
// and -1 if there was an error opening the file
int checkEncriptedList(const std::string& filename) {
	std::string line;
	//open the file and check if it is empty
	std::ifstream encFile(filename);
	if (encFile.is_open()){
		std::getline(encFile, line);
		if (line.empty()) {
			//if the file is empty, return 0
			return 0;
		}
		else {
			//if the file is not empty, return 1
			return 1;
		}
	}
	else {
		//file open failed
		std::cout << "Error opening the encripted file." << std::endl;
		return -1;
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
}
//generatesw a random encription key and saves it to the encripted file, returns the generated key as a string
std::string generateIncriptionKey(){
	//generate a random encription key and save it to the encripted file
	std::string key;
	const int keyLength = 16; //length of the encription key
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; //characters to use in the encription key
	srand(time(0)); //seed the random number generator
	for (int i = 0; i < keyLength; i++) {
		key += charset[rand() % (sizeof(charset) - 1)]; //generate a random character and add it to the key
	}
	//save the generated key to the encripted file
	std::ofstream encFile("encripted.txt");
	if (encFile.is_open()) {
		encFile << key << std::endl; //write the generated key to the file
		encFile.close(); //close the file
		std::cout << "Generated encription key: " << key << std::endl;
		return key;
	}
	else {
		std::cout << "Error opening the encripted file." << std::endl;
		return "";
	}
}









//char* encryptString(const std::string& input, const std::string& key) {
//	//encrypt the input string using the encription key and return the encripted string
//	std::string encrypted;
//	for (size_t i = 0; i < input.length(); i++) {
//		encrypted += input[i] ^ key[i % key.length()]; //XOR the input character with the corresponding character in the key
//	}
//	char* encryptedCStr = new char[encrypted.length() + 1]; //allocate memory for the encripted string
//	strcpy(encryptedCStr, encrypted.c_str()); //copy the encripted string to a C-style string
//	return encryptedCStr; //return the encripted string
}