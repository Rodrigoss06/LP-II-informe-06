#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
// Declaración de la clase Alumno

class Alumno
{

private:
    string nombre;
    int edad;
    float promedio;
public:
    // Método constructor
    Alumno(string nombre, int edad, float promedio) : nombre(nombre), edad(edad), promedio(promedio) {}

    // Getters
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    float getPromedio() const { return promedio; }

    // Sobrecarga del operador de comparación <
    bool operator<(const Alumno &otro) const
    {
        return promedio < otro.promedio;
    }

    // Método para obtener una representación en string del objeto Alumno
    string toString() const
    {
        return "Nombre: " + nombre + ", Edad: " + to_string(edad) + ", Promedio: " + to_string(promedio);
    }
};

// Declaración de la clase Grupo
class Grupo
{
private:
    vector<Alumno> alumnos;
    int cantidad;
public:
    // Método constructor
    Grupo(int cantidad) : cantidad(cantidad) {}
    // Método para agregar un alumno al grupo
    void agregarAlumno(string nombre, int edad, float promedio)
    {
        if (alumnos.size() < cantidad)
        {
            alumnos.push_back(Alumno(nombre, edad, promedio));
        }
        else
        {
            cout << "No se puede agregar más alumnos, el grupo está completo." << endl;
        }
    }

    // Método para ordenar los alumnos por promedio
    void ordenarPorPromedio()
    {
        sort(alumnos.begin(), alumnos.end());
    }
    // Método para calcular el promedio del grupo
    float promedioGrupo() const
    {
        if (alumnos.empty())
        {
            return 0;
        }
        float suma = 0;
        for (const auto &alumno : alumnos)
        {
            suma += alumno.getPromedio();
        }
        return suma / alumnos.size();
    }
    // Método para obtener al alumno con el mejor promedio
    Alumno mejorPromedio() const
    {
        if (alumnos.empty())
        {
            throw logic_error("No hay alumnos en el grupo.");
        }
        auto mejorAlumno = max_element(alumnos.begin(), alumnos.end());
        return *mejorAlumno;
    }

    // Método para obtener una representación en string del grupo
    string toString() const
    {
        string grupoStr = "Grupo:\n";
        for (const auto &alumno : alumnos)
        {
            grupoStr += alumno.toString() + "\n";
        }
        return grupoStr;
    }
};

// Función principal del programa

int main()
{
    // Creación del objeto Grupo con capacidad para 5 alumnos
    Grupo grupo(5);
    // Se agregan alumnos al grupo
    grupo.agregarAlumno("Juan", 20, 19.5);
    grupo.agregarAlumno("María", 21, 11.8);
    grupo.agregarAlumno("Pedro", 19, 12.2);
    grupo.agregarAlumno("Luisa", 20, 16.9);
    grupo.agregarAlumno("Carlos", 22, 11.1);
    // Muestra el estado del grupo
    cout << grupo.toString() << endl;
    // Muestra el promedio del grupo
    cout << "Promedio del grupo: " << grupo.promedioGrupo() << endl;
    // Muestra al alumno con el mejor promedio
    try
    {
        cout << "Mejor promedio:\n" << grupo.mejorPromedio().toString() << endl;
    }
    catch (const logic_error &e)
    {
        cout << e.what() << endl;
    }
    // Ordena los alumnos por promedio y muestra el estado del grupo
    grupo.ordenarPorPromedio();
    cout << grupo.toString() << endl;
    return 0;
}