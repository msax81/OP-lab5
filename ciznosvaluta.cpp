#include "ciznosvaluta.h"

cIznosValuta::cIznosValuta()
{
}

cIznosValuta::cIznosValuta(float _vrijednost, cIznosValuta * _ref, string _oznaka)
{
    this->vrijednost = _vrijednost;
    this->oznaka = _oznaka;
    this->ref = _ref;
}

cIznosValuta cIznosValuta::operator +(float rhs)
{
    cIznosValuta tmp(this->vrijednost, this->ref, this->oznaka);
    tmp.iznos = this->iznos + rhs;
    return tmp;
}
cIznosValuta cIznosValuta::operator -(float rhs)
{
    cIznosValuta tmp(this->vrijednost, this->ref, this->oznaka);
    tmp.iznos = this->iznos - rhs;
    return tmp;
}

cIznosValuta cIznosValuta::operator *(float rhs)
{
    cIznosValuta tmp(this->vrijednost, this->ref, this->oznaka);
    tmp.iznos = this->iznos * rhs;
    return tmp;
}

cIznosValuta cIznosValuta::operator /(float rhs)
{
    cIznosValuta tmp(this->vrijednost, this->ref, this->oznaka);
    tmp.iznos = this->iznos / rhs;
    return tmp;
}

void cIznosValuta::operator =(float rhs)
{
    this->iznos = rhs;
}

cIznosValuta cIznosValuta::operator -(const cIznosValuta & rhs)const
{
    cIznosValuta * tmp_a = new cIznosValuta(this->vrijednost , this->ref , this->oznaka);
    cIznosValuta * tmp_b = new cIznosValuta(rhs.vrijednost, rhs.ref , rhs.oznaka);

    cIznosValuta * tmp;
    tmp_a->iznos = this->iznos;
    tmp_b->iznos = rhs.iznos;
    tmp = tmp_a;
    float koeff_a=1;
    while(tmp->ref != NULL)
    {
        koeff_a *= tmp->vrijednost;
        tmp = tmp->ref;
    }
    koeff_a *= tmp->vrijednost;
    tmp = tmp_b;
    float koeff_b=1;
    while(tmp->ref != NULL)
    {
        koeff_b *= tmp->vrijednost;
        tmp = tmp->ref;
    }
    koeff_b *= tmp->vrijednost;
    cIznosValuta rez(tmp_a->vrijednost, tmp_a->ref, tmp_a->oznaka);
    rez.iznos = tmp_a->iznos - tmp_b->iznos*koeff_a/koeff_b;
    return rez;

}

cIznosValuta cIznosValuta::operator +(const cIznosValuta & rhs)const
{
    //prošetati do valute petljom kako bi c=a+b bilo (iznos_a/koef_a + iznos_b/koef_b)/koef_a
    // u valutu c, a koef je while po this/rhs preko tmp za koef*=tmp.vrijednost
    cIznosValuta * tmp_a = new cIznosValuta(this->vrijednost , this->ref , this->oznaka);
    cIznosValuta * tmp_b = new cIznosValuta(rhs.vrijednost, rhs.ref , rhs.oznaka);

    cIznosValuta * tmp;
    tmp_a->iznos = this->iznos;
    tmp_b->iznos = rhs.iznos;
    tmp = tmp_a;
    float koeff_a=1;
    while(tmp->ref != NULL)
    {
        koeff_a *= tmp->vrijednost;
        tmp = tmp->ref;
    }
    koeff_a *= tmp->vrijednost;
    tmp = tmp_b;
    float koeff_b=1;
    while(tmp->ref != NULL)
    {
        koeff_b *= tmp->vrijednost;
        tmp = tmp->ref;
    }
    koeff_b *= tmp->vrijednost;
    cIznosValuta rez(tmp_a->vrijednost, tmp_a->ref, tmp_a->oznaka);
    rez.iznos = tmp_a->iznos + tmp_b->iznos*koeff_a/koeff_b;
    return rez;

}

void cIznosValuta::operator =(const cIznosValuta & rhs)
{
    if(this != &rhs)
    {
        this->oznaka = rhs.oznaka;
        this->iznos = rhs.iznos;
        this->ref = rhs.ref;
        this->vrijednost = rhs.vrijednost;
    }
}

float cIznosValuta::getIznos()
{
    return this->iznos;
}

string cIznosValuta::getOznaka()
{
    return this->oznaka;
}

cIznosValuta::cIznosValuta(const cIznosValuta & rhs)
{
    this->iznos = rhs.iznos;
    this->oznaka = rhs.oznaka;
    this->ref = rhs.ref;
    this->vrijednost = rhs.vrijednost;
};

