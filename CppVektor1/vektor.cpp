#include "vektor.h"

size_t Vektor::defSize=13;
double Vektor::defValue=13;

///Másoló konstruktor
Vektor::Vektor(const Vektor& v): pVec(new double[v.nElements]), nElements(v.nElements){
    for(size_t i=0;i<v.nElements;i++)
        this->pVec[i]=v.pVec[i];
}

///Destruktor
Vektor::~Vektor(){
    delete[] pVec;
}

///Értékadó oerátor
Vektor& Vektor::operator=(const Vektor& v){
    if (this==&v)
        return *this;
    this->nElements=v.nElements;
    delete[] this->pVec;
    this->pVec= new double[this->nElements];
    for(size_t i=0;i<this->nElements;i++)
        (*this)[i]=v.pVec[i];
    return *this;
}

///Indexelõoperátorok
double& Vektor::operator[](size_t idx){
    if(idx<0 || idx>=this->nElements)
        throw "JEX651";
    return this->pVec[idx];
}

const double& Vektor::operator[](size_t idx) const{
    if(idx<0 || idx>=this->nElements)
        throw "JEX651";
    return this->pVec[idx];
}

///Szorzó operátor
Vektor operator*(double val, const Vektor& vec){
    Vektor temp=vec;
    for(size_t i=0;i<temp.size();i++)
    temp[i]*=val;
    return temp;
}
