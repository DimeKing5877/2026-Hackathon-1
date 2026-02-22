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
void getEncriptionKey(char* charKey);
std::string userKeyEntry(const std::string& filename);
int checkUserKey(const std::string& userKey, const std::string& fileKey);
std::string checkEncriptedList(const std::string& filename);
std::string promptUserForKey();
std::string generateIncriptionKey();
void getNewEncriptionKey(char* charKey);