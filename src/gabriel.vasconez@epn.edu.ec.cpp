#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "../lib/gvcolor.h"
using namespace std;

const string GVNOMBRE_COMPLETO = "Gabriel Esteban Vasconez Barahona";
const int GVCEDULA = 1752114148;

struct gvNodo{
     int gvCapacidad_belica;
     string gvGeolocalizacion;
     string gvDetalle_arsenal;
     gvNodo *der;
     gvNodo *izq;
};

int main()
{
    cout << "Hello world!" << endl;
}
