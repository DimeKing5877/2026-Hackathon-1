#include "Header.hpp"


Data keycreation::encryption(Data info, char* key)
{
    Data info2;
    strcpy(info2.website, encrypt(info.website, key, SITE_SIZE));
    strcpy(info2.email, encrypt(info.email, key, email_SIZE));
    strcpy(info2.username, encrypt(info.username, key, USERNAME_SIZE));
    strcpy(info2.password, encrypt(info.password, key, PASS_SIZE));
    strcpy(info2.date, encrypt(info.date, key, DATE_SIZE));
    return info2;
}

Data keycreation::dectyption(Data info, char* key)
{
    Data info2;
    strcpy(info2.website, decrypt(info.website, key, SITE_SIZE));
    strcpy(info2.email, decrypt(info.email, key, email_SIZE));
    strcpy(info2.username, decrypt(info.username, key, USERNAME_SIZE));
    strcpy(info2.password, decrypt(info.password, key, PASS_SIZE));
    strcpy(info2.date, decrypt(info.date, key, DATE_SIZE));
    return info2;
}

char* keycreation::encrypt(char* info, char* key, int size){
    for (int index = 0; index < size; index++) {
        for (int kindex = 0; kindex < 16; kindex++) {
            if (key[kindex] % 2 == 0) {//if even
                info[index] += key[kindex];
            }
            if (key[kindex] % 2 == 1) {//if odd
                info[index] -= key[kindex];
            }
        }
    }
      
    return info;
}

char* keycreation::decrypt(char* info, char* key, int size){
    for (int index = 0; index < size; index++) {
        for (int kindex = 16 - 1; kindex >= 0; kindex--) {
            if (key[kindex] % 2 == 0) {//if even
                info[index] -= key[kindex];
            }
            if (key[kindex] % 2 == 1) {//if odd
                info[index] += key[kindex];
            }
        }
    }

    return info;
}


