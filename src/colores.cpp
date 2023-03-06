#include <iostream>
#include "../lib/gvcolor.h"
//#include <cstdlib> //Para exit(0), que es mejor que system("exit") -preguntar al profe por que-.
using namespace std;
int n;
string opc;

int vasconezSerie08(int elementos)
{
	int a = 3;

	cout << "\n";
	for (int i = 0; i < elementos; i++)
	{
		cout << LBLUE << a << RESET << "\t";
		a = a + 5;
	}

	return 0;
}

bool vasconezSerie18Impar(int niveles)
{
	cout << "\n";
    for (int i = 0; i < niveles; i++)
	{
    	for (int j = 0; j < niveles; j++)
		{
            if (j % 2 == 0)
			{
				if (i == j || i == niveles - j - 1)
				{
                	cout << "1  ";
            	} 
				else 
				{
                cout << "   ";
            	}
			}
			else
			{
				if (i == j || i == niveles - j - 1)
				{
                	cout << "0  ";
            	}
				else
				{
                	cout << "   ";
            	}
			}
        }
        cout << "\n\n";
    }
	return true;
}

bool vasconezSerie18Par(int niveles)
{
	cout << "\n";
	niveles = niveles + 1;

    for (int i = 0; i < niveles; i++)
	{
    	for (int j = 0; j < niveles; j++)
		{
			if (i == niveles / 2 && j == niveles / 2)
				{
					cout << "   ";
				}
            else if (j % 2 == 0)
			{
				if (i == j || i == niveles - j - 1)
				{
                	cout << "1  ";
            	} 
				else 
				{
                cout << "   ";
            	}
			}
			else
			{
				if (i == j || i == niveles - j - 1)
				{
                	cout << "0  ";
            	}
				else 
				{
                	cout << "   ";
            	}
			}
        }
        cout << "\n\n";
    }
	return true;
}

string vasconezSerie28(string palabra)
{
	string reordenamiento;
	int intentos = 2;
	cout << LGREEN << "\n\nAnagramas" << LBLUE << "\n\nReordene correctamente las letras para formar una palabra: " << RED << palabra << RESET << endl;
	cin >> reordenamiento;
	for (int i = 0; i <= intentos; intentos--)
	{
		if (reordenamiento != "enrique")
		{
			if (intentos != 0)
			{
				cout << RED << "Respuesta incorrecta, intentalo nuevamente." << RESET << endl;
				cout << "Intentos restantes: " << intentos << endl;
				cin >> reordenamiento;
			}
		}
		else if (reordenamiento == "enrique")
		{
			cout << LBLUE << "Perfecto!\n" << LGREEN << "La palabra es " << reordenamiento << RESET << endl;
			return reordenamiento;
		}
	}
	cout << LGREEN << "Perdiste. La respuesta correcta es: " << RED << "enrique" << RESET << endl;
	return reordenamiento;
}

void menu()
{
	cout << LGREEN << "\n\nMENU:" << RESET << endl
		 << "1. Serie 08: " << MAGENTA << "3, 8, 13, 18, 23, 28, 33, 38, ..." << RESET << endl
		 << "2. Serie 18: Pedir niveles" << endl
		 << "3. Serie 28: Anagramas de palabras" << endl
		 << "0. Salir"    << endl;
	cout << "\nIngresa una opcion: " << endl;
	cin >> opc;

	if (opc == "1")
	{
		vasconezSerie08(n);
	}
	else if (opc == "2")
	{
		if (n % 2 != 0)
		{
			vasconezSerie18Impar(n);
		}
		else if (n % 2 == 0)
		{
			vasconezSerie18Par(n);
		}
	}
	else if (opc == "3")
	{
		vasconezSerie28("quieren");
	}
	else if (opc == "0")
	{
		//exit (0);
		opc = "0";
	}
	else 
	{
		system("clear");
		cout << RED << "Opcion no valida" << RESET << endl;
		menu();
	}
}

void regresar_o_salir()
{
	cout << "\n\nIngresa una opcion: " << endl
		 << "1. Regresar al menu"  << endl
		 << "0. Salir"             << endl;
	cin >> opc;

	if (opc == "1")
	{
		system("clear");
	}
	else if (opc == "0")
	{
		//exit(0);
		opc = "0";
	}
	else
	{
		system("clear");
		cout << RED << "Opcion no valida" << RESET << endl;
		regresar_o_salir();
	}
}

int main()
{
	system("clear");
	cout << MAGENTA << "Hola!\n\nGabriel Esteban Vasconez Barahona\n\n1752114148" << RESET << endl;
	cout << LBLUE << "\n\nIngresa el numero de elementos/niveles de las series (SOLO NUMEROS): " << RESET << endl;
	cin >> n;
	while (opc != "0")
	{
		menu();
		if (opc != "0")
		{
			regresar_o_salir();
		}
	}

	return 0;
}