
#include <iostream>
#include "String.h"
using namespace std;

//Konstruktor für einen leeren String
String::String() {
    size = 0;
    str = new char[1];
    str[0] = '\0';
}

//Konstruktor mit einem Zeichen als Parameter
String::String(char c) {
    size = 1;
    str = new char[2];
    str[0] = c;
    str[1] = '\0';
}

//Konstruktor für eine Zeichenkette als Parameter
String::String(const char *s) {
    size = 0;
    while(*s != '\0') {
        ++size;
        ++s;
    }
    s -= size;
    str = new char[size+1];
    for(size_t i = 0; i <= size; ++i) {
        str[i] = *s;
        ++s;
    }
}

//Konstruktor für einen String als Parameter
String::String(const String& s) {
    size = s.size;
    str = new char[size];

    for (size_t i = 0; i <= size; ++i) {
        str[i] = s.str[i];
    }
}

//Destruktor
String::~String() { delete[] str; }

/*
 Methode zum Arrayzugriff
 Gibt das Zeichen am Index aus
 Bei ungültigen Index gibt er eine Fehlermeldung aus
 */
char& String::operator[](int index) {
    return str[index];
}

/*
 Methode zum Zuweisen eines Strings
 Der gegebene String wird als neuer String benutzt
 */
String& String::operator=(String& s) {
    char* tmp = new char[s.size];

    size = s.size;
    for (size_t i = 0; i <= size; ++i) {
        tmp[i] = s.str[i];
    }
    delete[] str;
    str = tmp;
    return *this;
}

/*
 Methode zur Konkatenantion eines Strings
 Der gegebenen String wird zum aktuellen String angehängt
 */
String& String::operator+=(String& s) {
    size_t sizetmp = size;
    char* strtmp = new char[s.size+size];
    size += s.size;
    size_t i;

    for (i = 0; i < sizetmp; ++i) { // Ganzer String ohne \0
        strtmp[i] = str[i];
    }
    for (size_t u = 0; i <= size; ++i, u++) {
        strtmp[i] = s.str[u];
    }
    delete[] str;
    str = strtmp;
    return *this;
}
