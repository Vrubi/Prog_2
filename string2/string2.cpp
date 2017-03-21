/**
 *
 * \file string2.cpp
 *
 * Itt kell megvalósítania a hiányzó tagfüggvényeket.
 * Segítségül megadtuk a C-ben megírt változatban (string1.c) használt függvényneveket.
 *
 * Ha valamit INLINE-ként valósít meg, akkor annak a .h-ba kell kerülnie,
 * akár kívül akár osztályon belül definiálja. (Az inline függvényeknek minden
 * fordítási egységben elérhetőknek kell lenniük)
 * *
 * A teszteléskor ne felejtse el beállítani a header állományban az ELKESZULT makrót.
 * A VC saját memóriafogyás ellenőrzője csak debug módban (Debug->Start) működik!
 *
 */

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Sztringműveletekhez

#include "memtrace.h"           // a standard headerek után kell lennie
#include "string2.h"


/// Konstruktor: egy char karakterből (createStrFromChar)
String::String(const char c){
    len=1;
    pData=new char[len+1];
    pData[0]=c;
    pData[1]='\0';
}
/// Destruktor (disposeString)
String::~String(){
    delete[] pData;
}
/// Konstruktor: egy nullával lezárt char sorozatból (createStringFromCharStr)
String::String(const char *str){
    len=strlen(str);
    pData=new char[len+1];
    strcpy(this->pData,str);
}

/// Másoló konstruktor
String::String(const String& str):pData(new char[str.len+1]),len(str.len){
    strcpy(this->pData,str.pData);
}

/// operator=
String String::operator=(String str){
    this->len=str.len;
    delete[] this->pData;
    this->pData=new char[len+1];
    strcpy(this->pData,str.pData);
    return *this;
}

/// [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza.
/// indexhiba esetén dobjon egy const char * típusú hibát!
char& String::operator[](int idx){
    if (idx<=0)
        throw "Szar indexeles!";
    else
        return this->pData[idx];
}

/// + operátorok, ami két sztringet ad össze (concatString)
const String String::operator+(const String str){
    this->len+=str.len;
    temp->pData=new char[temp->len+1];
    strcpy(temp->pData,this->pData);
    strcat(temp->pData,str.pData);
    return *this;
}

/// << operator, ami kiír az ostream-re


/// >> operátor, ami beolvas az istreamről egy szót
