#include <iostream>
using namespace std;

int main() {
    int cantidad;

    cout << "Ingrese la cantidad de estudiantes (maximo 20): ";
    cin >> cantidad;

    // Validar cantidad
    while (cantidad < 1 || cantidad > 20) {
        cout << "Cantidad invalida. Ingrese un numero entre 1 y 20: ";
        cin >> cantidad;
    }

    float calificaciones[20][4]; // 20 estudiantes, 4 notas cada uno
    float promedios[20];

    float sumaGeneral = 0;
    float mayor = 0;
    float menor = 100;

    int aprobados = 0;
    int reprobados = 0;

    // Entrada de datos
    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante " << i + 1 << endl;

        float suma = 0;

        for (int j = 0; j < 4; j++) {
            do {
                cout << "Ingrese la calificacion " << j + 1 << ": ";
                cin >> calificaciones[i][j];
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 100);

            suma += calificaciones[i][j];

            // Calcular mayor y menor
            if (calificaciones[i][j] > mayor) {
                mayor = calificaciones[i][j];
            }

            if (calificaciones[i][j] < menor) {
                menor = calificaciones[i][j];
            }
        }

        promedios[i] = suma / 4;
        sumaGeneral += promedios[i];

        if (promedios[i] >= 70) {
            aprobados++;
        }
        else {
            reprobados++;
        }
    }

    // Salida de datos
    cout << "\n--- RESULTADOS ---\n";

    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante " << i + 1 << ": ";

        for (int j = 0; j < 4; j++) {
            cout << calificaciones[i][j] << " ";
        }

        cout << "| Promedio: " << promedios[i];
    }

    float promedioGeneral = sumaGeneral / cantidad;

    cout << "\n\nPromedio general del grupo: " << promedioGeneral << endl;
    cout << "Calificacion mas alta: " << mayor << endl;
    cout << "Calificacion mas baja: " << menor << endl;

    cout << "Aprobados: " << aprobados << endl;
    cout << "Reprobados: " << reprobados << endl;

    return 0;
}