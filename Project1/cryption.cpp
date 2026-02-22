#include "Header.hpp"

//dencypts all data entry using the encriptionkey and sends a copy of the data
Data keycreation::encryption(Data info, char* key)
{
    Data info2;
    strcpy(info2.website, encrypt(info.website, key, strlen(info.website)));
    strcpy(info2.email, encrypt(info.email, key, strlen(info.email)));
    strcpy(info2.username, encrypt(info.username, key, strlen(info.username)));
    strcpy(info2.password, encrypt(info.password, key, strlen(info.password)));
    strcpy(info2.date, encrypt(info.date, key, strlen(info.date)));
    return info2;
}

//decypts all data entry using the encriptionkey and sends a copy of the data
Data keycreation::dectyption(Data info, char* key)
{
    Data info2;
    strcpy(info2.website, decrypt(info.website, key, strlen(info.website)));
    strcpy(info2.email, decrypt(info.email, key, strlen(info.email)));
    strcpy(info2.username, decrypt(info.username, key, strlen(info.username)));
    strcpy(info2.password, decrypt(info.password, key, strlen(info.password)));
    strcpy(info2.date, decrypt(info.date, key, strlen(info.date)));
    return info2;
}

//encypts a data entry using the encriptionkey and sends it back
char* keycreation::encrypt(char* info, char* key, int size) {
    for (int index = 0; index < size; index++) {
        for (int kindex = 0; kindex < 17; kindex++) {
            if (key[kindex] % 2 == 0) {//if even
                info[index] += key[kindex];
                info[index] -= kindex;
            }
            if (key[kindex] % 2 == 1) {//if odd
                info[index] -= key[kindex];
                info[index] += kindex;
            }
        }
    }
    return info;
}


//decypts a data entry using the encriptionkey and sends it back
char* keycreation::decrypt(char* info, char* key, int size){
    for (int index = 0; index < size; index++) {
        for (int kindex = 17 - 1; kindex >= 0; kindex--) {
            if (key[kindex] % 2 == 0) {//if even
                info[index] += kindex;
                info[index] -= key[kindex];
            }
            if (key[kindex] % 2 == 1) {//if odd
                info[index] -= kindex;
                info[index] += key[kindex];
            }
        }
    }

    return info;
}






