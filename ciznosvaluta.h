#ifndef CIZNOSVALUTA_H
#define CIZNOSVALUTA_H

#include <iostream>
#include <string>

using namespace std;

class cIznosValuta
{
private:
    string oznaka;
    float iznos;
    cIznosValuta * ref;
    float vrijednost;
public:
    cIznosValuta();
    cIznosValuta(float _vrijednost, cIznosValuta * _ref, string _oznaka);
    cIznosValuta operator +(float rhs);
    cIznosValuta operator -(float rhs);
    cIznosValuta operator *(float rhs);
    cIznosValuta operator /(float rhs);
    void operator =(float rhs);
    cIznosValuta operator -(const cIznosValuta & rhs)const;
    cIznosValuta operator +(const cIznosValuta & rhs)const;
    void operator =(const cIznosValuta & rhs);

    float getIznos();
    string getOznaka();
    cIznosValuta(const cIznosValuta & rhs);
};

#endif // CIZNOSVALUTA_H
