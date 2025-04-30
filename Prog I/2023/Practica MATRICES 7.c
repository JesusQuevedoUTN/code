#include "Libs/utils.h" 

//strlen LONGITUD CADENA
//strcat METE 1 CADENA EN OTRA
//strcpy COPIA CADENA
//strcmp comparador == de cadenas
//strtok pone los tokens

#define CANT_ALUMNOS 9
#define CANT_CLASES 16

float calcPorcPresentismo(char filaAsistencia[CANT_CLASES]);
int estaAptoParaRendirFinal(float porcPresentismo);
void mostrarAlumnosAptosFinal(cadena apellidos[CANT_ALUMNOS],
                              char asistencias[CANT_ALUMNOS][CANT_CLASES]);

int main()
{
    /*
    7) Para ser contratado como desarrollador/a por un instituto terciario se te pide que realices el
    siguiente prototipo a modo de prueba.
    La institución te brinda los datos de una comisión donde se impartió clase: Los apellidos de los
    alumnos (guardados en un array) y una matriz de caracteres que representa la asistencia de cada
    alumno para cada clase.
    Cada columna en la matriz representa una jornada de clase. Cada fila en la matriz representa a un
    alumno, cuyo índice coincide con el del array de apellidos paralelo.
    Una 'P' significa Presente. Una 'T' significa Tarde. Una 'A' significa Ausente. Un ausente suma
    una falta completa. Una llegada tarde suma media falta. La condición para rendir el examen final es
    haber obtenido una asistencia mayor o igual al 75%.
    Realizá un programa que resuelva y muestre, con al menos una función para cada punto, lo citado a
    continuación:
    A) Mostrar los apellidos de los alumnos aptos para rendir final, junto al porcentaje de
    presentismo de cada uno.
    B) Obtener el número total de llegadas tarde para todo el período de cursada.
    C) Obtener la cantidad de clases con asistencia perfecta de la manera más eficiente posible. (Las
    llegadas tarde cuentan como presente).
    D) Devolver (no mostrar por consola) el porcentaje de presentismo por cada clase. (Las llegadas
    tarde cuentan como presente).
    E) Mostrar los apellidos de los alumnos que dejaron la cursada (más de 4 ausencias seguidas)
    */
    cadena apellidos[CANT_ALUMNOS] = {"Alberti", "Azcuénaga", "Belgrano", "Castelli",
                                      "Larrea", "Matheu", "Moreno", "Paso", "Saavedra"};
    char asistencias[CANT_ALUMNOS][CANT_CLASES] = {
        {'P', 'P', 'P', 'P', 'P', 'P', 'T', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'T'},
        {'A', 'P', 'P', 'P', 'P', 'P', 'A', 'P', 'P', 'P', 'T', 'P', 'P', 'P', 'A', 'P'},
        {'T', 'P', 'A', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'A', 'P', 'P'},
        {'P', 'P', 'T', 'T', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'},
        {'T', 'P', 'P', 'P', 'P', 'A', 'P', 'P', 'A', 'P', 'P', 'A', 'P', 'P', 'P', 'A'},
        {'P', 'P', 'P', 'P', 'T', 'T', 'P', 'P', 'P', 'P', 'A', 'P', 'P', 'P', 'P', 'A'},
        {'P', 'P', 'A', 'P', 'P', 'P', 'T', 'T', 'A', 'P', 'P', 'A', 'P', 'A', 'P', 'P'},
        {'P', 'P', 'P', 'P', 'A', 'A', 'T', 'P', 'P', 'P', 'P', 'A', 'A', 'P', 'P', 'A'},
        {'P', 'P', 'A', 'P', 'A', 'T', 'P', 'P', 'A', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}};
    mostrarAlumnosAptosFinal(apellidos, asistencias); // Punto A
    return 0;
}

// Mostrar los apellidos de los alumnos aptos para rendir final, junto al porcentaje de
// presentismo de cada uno
void mostrarAlumnosAptosFinal(cadena apellidos[CANT_ALUMNOS],
                              char asistencias[CANT_ALUMNOS][CANT_CLASES])
{
    float porcPresentismo;
    for (int a = 0; a < CANT_ALUMNOS; a++)
    {
        porcPresentismo = calcPorcPresentismo(asistencias[a]);
        if (estaAptoParaRendirFinal(porcPresentismo))
        {
            printf("%s (%.2f %%)\n", apellidos[a], porcPresentismo);
        }
    }
}

float calcPorcPresentismo(char filaAsistencia[CANT_CLASES])
{
    float ausentismo = 0;
    for (int i = 0; i < CANT_CLASES; i++)
    {
        char letra = filaAsistencia[i];
        if (letra == 'A')
        {
            ausentismo += 1;
        }
        else if (letra == 'T')
        {
            ausentismo += 0.5;
        }
    }
    float presentismo = CANT_CLASES - ausentismo;
    return presentismo * 100 / CANT_CLASES;
}

int estaAptoParaRendirFinal(float porcPresentismo)
{
    const float PORC_PARA_DAR_FINAL = 75;
    return porcPresentismo >= PORC_PARA_DAR_FINAL;
}