#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>  // Para cambiar el color de la salida

using namespace std;

void leer_archivo(string nombre_archivo) {
    // Definir variables
    string linea;
    int num_linea = 0;
    vector<string> coordenadas_validas;

    // Abrir el archivo
    ifstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        return;
    }

    // Leer el archivo línea por línea
    while (getline(archivo, linea)) {
        // Mostrar un mensaje de loading
        cout << "Leyendo archivo: " << (num_linea * 100 / 10) << "%\r";
        cout.flush();
        num_linea++;

        // Verificar si la línea leída es una coordenada válida
        size_t pos1 = linea.find(",");
        size_t pos2 = linea.find(",", pos1 + 1);
        if (pos1 == string::npos || pos2 == string::npos || pos2 == linea.length() - 1) {
            // La línea no es una coordenada válida
            cout << "\033[31mError en la línea " << num_linea << ": no es una coordenada válida.\033[0m" << endl;
            continue;
        }

        // Extraer los campos de la coordenada
        string cap = linea.substr(0, pos1);
        string geo = linea.substr(pos1 + 1, pos2 - pos1 - 1);
        string tipo_arsenal = linea.substr(pos2 + 1);

        // Verificar si la coordenada ya fue leída previamente
        string coordenada = cap + "," + geo + "," + tipo_arsenal;
        if (find(coordenadas_validas.begin(), coordenadas_validas.end(), coordenada) != coordenadas_validas.end()) {
            // La coordenada ya fue leída previamente
            continue;
        }

        
        // Agregar la coordenada a la lista de coordenadas válidas y mostrarla en color verde
        coordenadas_validas.push_back(coordenada);
        cout << "\033[32m" << cap << ", " << geo << ", " << tipo_arsenal << "\033[0m" << endl;
    }

    // Cerrar el archivo
    archivo.close();

    // Mostrar el resultado de la lectura
    cout << "Se leyeron " << coordenadas_validas.size() << " coordenadas válidas." << endl;
}

int main() {
    leer_archivo("files/gvArchivo_de_texto.txt");
    return 0;
}
