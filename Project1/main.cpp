#include "Header.hpp"
#include "UIHeader.hpp"



int main(void) {
	UImain();


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