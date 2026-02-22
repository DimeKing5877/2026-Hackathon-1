#include "UIHeader.hpp"
#include "Header.hpp"

//functions that collect user iputed data for the website, email, username, password, and date
void getWebsite(char* websiteDestination) {
	std::cout << "Enter the website: ";
	std::cin.getline(websiteDestination, SITE_SIZE);
}
void getEmail(char* emailDestination) {
	std::cout << "Enter the email: ";
	std::cin.getline(emailDestination, email_SIZE);
}
void getUsername(char* usernameDestination) {
	std::cout << "Enter the username: ";
	std::cin.getline(usernameDestination, USERNAME_SIZE);

}
void getPassword(char* passwordDestination) {
	std::cout << "Enter the password: ";
	std::cin.getline(passwordDestination, PASS_SIZE);

}
void getDate(char* dateDestination) {
	std::cout << "Enter the date (MM/DD/YYYY): ";
	std::cin.getline(dateDestination, DATE_SIZE);

}
