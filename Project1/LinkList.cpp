#include "Header.hpp"

void LinkList::linkFunCall(int selection, Node** pHead)
{
	switch (selection) {
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
	}

}

//reading from encripted file, key should be good, file should not be empty
int LinkList::loadlist(Node** pHead, FILE* inputStream, char* key){
	int success = 0;
	if (*pHead != NULL) {
		clearList(pHead);//clean, need clean function
	}
	char line[LINE_SIZE] = "";
	Data info;
	//ignores one line from file
	fgets(line, LINE_SIZE, inputStream);
	while (fgets(line, LINE_SIZE, inputStream) != NULL) {
		info = loadLine(line);
		//info = dectyption(info, key);
		success = insertatfront(pHead, info);
	}
	if (*pHead != NULL) {
		success = 1;
	}
	return success;
}

Data LinkList::loadLine(char* line){
	Data info = {};
	strcpy(info.website, strtok(line, ","));
	strcpy(info.email, strtok(NULL, ","));
	strcpy(info.username, strtok(NULL, ","));
	strcpy(info.password, strtok(NULL, ","));
	strcpy(info.date, strtok(NULL, "\n"));
	return info;
}

int LinkList::insertatfront(Node** pHead, Data info){
	int success = 0;
	Node* pMem = creatNode(info);
	Node* pCur = *pHead;
	
	if (pCur == NULL) {
		*pHead = pMem;
		success = 1;
	}
	else {
		pCur->pPrev = pMem;
		pMem->pNext = pCur;
		pCur = pMem;
		success = 1;
	}
	return success;
}

Node* LinkList::creatNode(Data info){
	Node* pMem = (Node*)malloc(sizeof(Node));
	if (pMem != NULL) {
		pMem->data = info;
		pMem->pNext = NULL;
		pMem->pPrev = NULL;
	}
	return pMem;
}

void LinkList::clearList(Node** pHead){
	Node* pCur = *pHead;

	while (pCur->pNext != NULL) {
		pCur = pCur->pNext;
		free(pCur->pPrev);
	}
	if (pCur->pNext == NULL) {
		free(pCur);
	}
	if (pCur != *pHead) {
		*pHead == NULL;
	}
}

void LinkList::savelist(Node* pHead, FILE* outStream, char* key){
	Node* pCur = pHead;
	char line[LINE_SIZE] = "";
	//pCur->data = encryption(pCur->data, key)
	strcat(line, pCur->data.website);
	strcat(line, ",\0");
	strcat(line, pCur->data.email);
	strcat(line, ",\0");
	strcat(line, pCur->data.username);
	strcat(line, ",\0");
	strcat(line, pCur->data.password);
	strcat(line, ",\0");
	strcat(line, pCur->data.date);
	strcat(line, ",\n\0");


	fputs(line, outStream);
}

void LinkList::displayFull(Node* pHead){
	system("cls");
	Node* pCur = pHead;
	int count = 1;
	while (pCur != NULL) {
		std::cout << "Entry " << count << std::endl;
		std::cout << "Site: " << pCur->data.website << std::endl;
		std::cout << "Email: " << pCur->data.email << std::endl;
		std::cout << "Username: " << pCur->data.username << std::endl;
		std::cout << "Password: " << pCur->data.password << std::endl;
		std::cout << "Date: " << pCur->data.date << std::endl;
		std::cout <<""<< std::endl;
		count += 1;
		pCur = pCur->pNext;
	}
	system("pause");
}

void LinkList::displayType(Node* pHead, char* type){
	Node* pCur = pHead;
	int count = 1;
	while (pCur != NULL) {
		if (strcmp(pCur->data.email, type) == 0) {
			std::cout << "Entry " << count << std::endl;
			std::cout << "Site: " << pCur->data.website << std::endl;
			std::cout << "Email: " << pCur->data.email << std::endl;
			std::cout << "Username: " << pCur->data.username << std::endl;
			std::cout << "Password: " << pCur->data.password << std::endl;
			std::cout << "Date: " << pCur->data.date << std::endl;
			std::cout << "" << std::endl;
			count += 1;
		}
		pCur = pCur->pNext;
	}
}

Node* LinkList::search(Node* pHead, int value){
	Node* pCur = pHead;
	int count = 1;
	while(pCur != NULL && count < value){
		count += 1;
		pCur = pCur->pNext;
	}
	
	return pCur;
}

void LinkList::deleteNode(Node** pHead, Node* pCur) {
	if (pCur != NULL) {
		if (pCur->pPrev == NULL) {
			*pHead = pCur->pNext;
			free(pCur);
		}
		else if (pCur->pNext == NULL) {
			pCur->pPrev->pNext = NULL;
			free(pCur);
		}
		else {
			pCur->pPrev->pNext = pCur->pNext;
			pCur->pNext->pPrev = pCur->pPrev;
			free(pCur);
		}
	}
}

int LinkList::insert(Node** pHead, FILE* inputStream){
	int success = 0;
	char line[LINE_SIZE] = "";
	Data info;
	info = loadLine(line);
	success = insertatfront(pHead, info);
	
	return success;
}










