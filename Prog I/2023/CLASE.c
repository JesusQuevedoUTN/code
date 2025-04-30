#include "Libs\utils.h"

typedef struct
{
    int dni;
    cadena nombre;
    int edad;
}Alumno;

typedef struct 
{
    cadena codigo;
    cadena titulo;
    int hsDuradcion;
    Alumno inscriptos[25];
}Curso;

Curso cursos[5];
const Curso CURSO_NULL ={"","", 0, {} };
const Alumno ALUMNO_NULL ={0, "", 0};


void inscribirAlumnos();
void mostrarAlumnosInscriptos();
Alumno buscarAlumnoEnLaBD(int dni);
Alumno buscarAlumnoEnCurso(int dni, Curso cu);
void inscribir(Alumno alu, Curso cu);
Curso buscarCurso(cadena codigo);


int main() {
    inscribirAlumnos();
    mostrarAlumnosInscriptos();
    return 0;
}


void inscribirAlumnos(){
    int dni = leerEnteroEntre(-1,100000000,"");
    while (dni != -1)
    {
        cadena cod;
        leerCadena("", cod);
        Curso cu = buscarCurso(cod);
        if (cu != NULL)
        {
            Alumno elAlumno = buscarAlumnoEnCurso(dni,cu);
            if (elAlumno!=NULL)
            {
                Alumno elAlumno = buscarAlumnoEnLaBD(dni);
                if (elAlumno == NULL)
                {
                    elAlumno = cargarAlumno(dni)
                }
            inscribir(elAlumno, cu);
            }
        }
    }
}

Alumno buscarAlumnoEnLaBD(int dni){
    Alumno encontrado = NULL;
    int i = 0;
    while (i<5 && encontrado==NULL)
    {
        encontrado = buscarAlumnoEnCurso(dni, cursos[i]);
        i++;
    }
    return encontrado;
}
Alumno buscarAlumnoEnCurso(int dni, Curso cu){
    int i =0;
    Alumno a = NULL;
    while (i<25 && cu.inscriptos[i] != NULL && cu.inscriptos[i].dni!=dni)
    {
        i++;
    }
    if (i<25)
    {
        a = cu.inscriptos;
    }
    return a;
}
void inscribir(Alumno alu, Curso cu){
    int i= 0;
    while (i<25 && cu.inscriptos[i] != NULL)
    {
        i++;
    }
    if (i<25)
    {
        cu.inscriptos[i]=alu;
    }
}
Curso buscarCurso(cadena codigo){
    int i=0;
    Curso cu = NULL;
    while (i<5 && strcmp(codigo,cursos[i].codigo))
    {
        i++;
    }
    if (i<5)
    {
        cu=cursos[i];
    }
    return cu;
}