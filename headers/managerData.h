#ifndef managerData
#define managerData

#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <strings.h>

// Datos para ingreso de alumnos
struct Alumno {
    std::string carnet;
    std::string nombre;
    std::string apellido;
    std::string fechaNacimiento;
    int edad;
    std::string direccion;
    int telefono;
    std::string correoElectronico;
    std::string profesionDiversificado;
    int añoGraduacion;
};

// Datos para ingreso de cursos
struct Curso {
    std::string codigoCurso;
    std::string nombre;
    int prerrequisitos; // Puede ser un vector de códigos de cursos
    int creditos;
    std::string horario;
};

// Datos para ingreso de catedráticos
struct Catedratico {
    std::string codigoCatedratico;
    std::string nombre;
    std::string apellido;
    std::string direccion;
    std::string profesion;
    int telefono;
    std::string correoElectronico;
};

// Datos para ingreso de notas
struct Nota {
    std::string carnet;
    std::string codigoCurso;
    std::string codigoCatedratico;
    float punteoPrimerParcial;
    float punteoSegundoParcial;
    float zona; // Tareas, exámenes cortos y proyectos
    float examenFinal;
    float examenRetrasada; // Solo si el estudiante perdió el curso
};

// Datos para ingreso de pagos
struct Pago {
    std::string codigoAlumno; // Puede ser un código único para cada alumno
    std::string codigoPago;
    std::string nombrePago;
    std::string facultad;
    float cuotaPago;
};

// clase que maneja los datos
class SQLiteManager
{
private:
    sqlite3 *db; // puntero a la base de datos
public:
    SQLiteManager(const char *dbname);
    ~SQLiteManager();
    
    
    // funciones
    bool openDataBase(const std::string &nombreDB);

    void closeDataBase();

    void querryDataBase(const std::string &texto);
    
};
#endif /* managerData */