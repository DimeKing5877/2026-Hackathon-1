#pragma once

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <fstream>
//#include <sstream>
//#include <iomanip>
//#include <fileapi.h>
void UImain();
void getEncryptionKey(char* charKey);
std::string userKeyEntry(const std::string& filename);
int checkUserKey(const std::string& userKey, const std::string& fileKey);
std::string checkEncryptedList(const std::string& filename);
std::string promptUserForKey();
std::string generateEncryptionKey();
void getNewEncryptionKey(char* charKey);