#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Estructura para almacenar datos de cada estudiante
struct Estudiante { //"Struct" sirve para agrupar diferentes variabes en un solo array
    string nombre;   //Esta parte del código permitirá agrupar diferentes variables en un mismo array
    string fecha;
    double notas[5];
    double promedio;
    double mayor;
    double menor;
    int aprobados;
    int reprobados;
};

int main() {

    // Arreglo para los 40 estudiantes
    Estudiante estudiantes[40];  //Llamamos al struct de Estudiantes y lo comvertimos en array de 40 espacios

    int totalEstudiantes = 0;
    int opcion;

    double num1, num2, resultado;

    do {

        cout << "\n========== MENU ==========\n";
        cout << "1. Operaciones basicas\n";
        cout << "2. Registro de notas\n";
        cout << "3. Guardar resultados\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        //Switch para la elección de la opcion del menú interactivo
        switch (opcion) {

        //  OPERACIONES
        case 1: {

            int operacionMate;

            cout << "\n--- OPERACIONES BASICAS ---\n";
            cout << "1. Suma\n";
            cout << "2. Resta\n";
            cout << "3. Multiplicacion\n";
            cout << "4. Division\n";
            cout << "Seleccione una operacion: ";
            cin >> operacionMate;

            cout << "Ingrese el primer numero: ";
            cin >> num1;

            cout << "Ingrese el segundo numero: ";
            cin >> num2;

            switch (operacionMate) {

                case 1:
                    resultado = num1 + num2;
                    cout << "Resultado: " << resultado << endl;
                    break;

                case 2:
                    resultado = num1 - num2;
                    cout << "Resultado: " << resultado << endl;
                    break;

                case 3:
                    resultado = num1 * num2;
                    cout << "Resultado: " << resultado << endl;
                    break;

                case 4:
                    if (num2 != 0) {
                        resultado = num1 / num2;
                        cout << "Resultado: " << resultado << endl;
                    } else {
                        cout << "Error: No se puede dividir para cero.\n";
                    }
                    break;

                default:
                    cout << "Operacion invalida.\n";
            }

            break;
        }

        //  REGISTRO DE NOTAS
        case 2: {

            if (totalEstudiantes >= 40) {
                cout << "No se pueden registrar mas estudiantes.\n";
                break;
            }

            cout << "\n--- REGISTRO DE NOTAS ---\n";

            cin.ignore();  //cin.ignore sirve para lmpiar la entrada de datos del buffer de "\n" ya que el codigo reconoce ese caracter como que ya se ha ingresado algun dato
            //principalmente cin.ignore permite que el getline obtenga los datos del usuario y no se confunda con "\n"
            cout << "Ingrese el nombre del estudiante: ";
            getline(cin, estudiantes[totalEstudiantes].nombre); //la expresion "estudiantes[totalEstudiantes].nombre" sirve para guardar la variable nombre en el array de estudiantes

            cout << "Ingrese la fecha (dd/mm/aaaa): ";
            getline(cin, estudiantes[totalEstudiantes].fecha); //la expresion sirve para guardar la fecha en el array de estudiantes

            estudiantes[totalEstudiantes].promedio = 0;
            estudiantes[totalEstudiantes].aprobados = 0;
            estudiantes[totalEstudiantes].reprobados = 0;

            for (int i = 0; i < 5; i++) {

                cout << "Ingrese la nota " << i + 1 << ": ";
                cin >> estudiantes[totalEstudiantes].notas[i]; //.notas[i] va guardando las 5 notas de los 40 estudiantes

                estudiantes[totalEstudiantes].promedio += estudiantes[totalEstudiantes].notas[i];

                //En todo este bloque de código se va verificando la mayor nota y la menor nota de las que van ingresando
                if (i == 0) {

                    estudiantes[totalEstudiantes].mayor =
                    estudiantes[totalEstudiantes].menor =
                    estudiantes[totalEstudiantes].notas[i];

                } else {

                    if (estudiantes[totalEstudiantes].notas[i] >
                        estudiantes[totalEstudiantes].mayor) {

                        estudiantes[totalEstudiantes].mayor =
                        estudiantes[totalEstudiantes].notas[i];
                    }

                    if (estudiantes[totalEstudiantes].notas[i] <
                        estudiantes[totalEstudiantes].menor) {

                        estudiantes[totalEstudiantes].menor =
                        estudiantes[totalEstudiantes].notas[i];
                    }
                }

                if (estudiantes[totalEstudiantes].notas[i] >= 7) //cuenta la cantidad de aprobados
                    estudiantes[totalEstudiantes].aprobados++;
                else
                    estudiantes[totalEstudiantes].reprobados++; //cuenta la cantidad de reprobados
            }

            estudiantes[totalEstudiantes].promedio /= 5;

            cout << fixed << setprecision(2); //Esta linea del código sirve para configurar la salida de datos. setprecision() sirve para que los decimales siempre salgan con 2 decimales, no mas ni menos

            cout << "\nPromedio: "
                 << estudiantes[totalEstudiantes].promedio << endl;

            cout << "Nota mayor: "
                 << estudiantes[totalEstudiantes].mayor << endl;

            cout << "Nota menor: "
                 << estudiantes[totalEstudiantes].menor << endl;

            cout << "Cantidad de aprobados: "
                 << estudiantes[totalEstudiantes].aprobados << endl;

            cout << "Cantidad de reprobados: "
                 << estudiantes[totalEstudiantes].reprobados << endl;

            totalEstudiantes++;

            break;
        }

        // ================= GUARDAR RESULTADOS =================
        case 3: {

            ofstream archivo("resultados.txt");

            if (archivo.is_open()) {

                for (int i = 0; i < totalEstudiantes; i++) {

                    archivo << "========== RESULTADOS ==========\n";

                    archivo << "Estudiante #" << i + 1 << endl;

                    archivo << "Nombre: "
                            << estudiantes[i].nombre << endl;

                    archivo << "Fecha: "
                            << estudiantes[i].fecha << endl;

                    archivo << fixed << setprecision(2);

                    archivo << "Promedio: "
                            << estudiantes[i].promedio << endl;

                    archivo << "Nota mayor: "
                            << estudiantes[i].mayor << endl;

                    archivo << "Nota menor: "
                            << estudiantes[i].menor << endl;

                    archivo << "Cantidad de aprobados: "
                            << estudiantes[i].aprobados << endl;

                    archivo << "Cantidad de reprobados: "
                            << estudiantes[i].reprobados << endl;

                    archivo << "Lenguaje utilizado: C++\n";

                    archivo << "================================\n\n";
                }

                archivo.close();

                cout << "Resultados guardados correctamente en resultados.txt\n";

            } else {

                cout << "Error al abrir el archivo.\n";
            }

            break;
        }

        // ================= SALIR =================
        case 4:
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 4);

    return 0;
}