#include <iostream>
#include "ciznosvaluta.h"

using namespace std;

int main()
{
    cIznosValuta a(1., NULL, "EUR");

    // 7.5 	= vrijednost valute
    // a 		= referenta valuta na osnovu koje se izračunava vrijednost
    // „KN“ 	= oznaka valute
    cIznosValuta b(7.5, &a, "KN");

    cIznosValuta c(1.2, &a, "CHF");
    cIznosValuta d(c);
    cIznosValuta e(1.8, &d, "KM");

    a = 8.43; // promjena iznosa na 8.43
    b = 3.33;
    c = 4.76;
    d = 1.00;
    d = d * 3; // promjena iznosa; 3 puta umnažanje
    d = d / 2;
    d = d + 1;
    d = d - 8;

    e = a + b - c + d;

    cout << e.getIznos() << e.getOznaka() << endl; // ispisuje iznos u KM, npr. 123.44 KM
}

