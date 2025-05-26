#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define ARCH_TEXTO "F:\\REPOSITORIO\\EyBD_General\\PARCIALES\\viajes.txt"
#define ARCH_CHOFERES "F:\\REPOSITORIO\\EyBD_General\\PARCIALES\\choferes.dat"
#define COSTO 100 // este es el costo por km 100 pesos
typedef struct
{
    int cod_chof;
    char nom_chof[30];
    int kms;
    float rec;
} registro;

// Funciones:
void mostrarArchivoTexto(); // muestra el archivo plano de viajes.txt
void volcarTextoABinario(); // recordar solo una vez se puede hacer
int menu();                 // genra un menu para que interactue el usuario
void utf8();                // para ver los codigos unicode
void limpiarBuffer();
void linea(int);                                     // solo genera una linea de 80 asteriscos
void sacar(char x[], registro *y);                   // aqui paso la cadena leia del archivo de texto y la estructura
void listarChoferesOrdenados(char *msg, int opcion); // listado de choferes ordenado por nombre o por codigo
int compararChoferesNombre(const void *a, const void *b);
int compararChoferesCodigo(const void *a, const void *b);
void listarChoferes(char *msg);
void pausa();

int main()
{
    int op;
    utf8();
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            mostrarArchivoTexto();
            break;
        case 2:
            volcarTextoABinario();
            break;
        case 3:
            listarChoferes("Listado del Archivo Binario puro");

            break;
        case 4:
            listarChoferesOrdenados("Listado Ordenado de choferes por Codigo", 4);
            break;
        case 5:
            listarChoferesOrdenados("Listado Ordenado de choferes por Nombre", 5);
            break;
        }
    } while (op != 6);
    linea(80);
    printf(" \nsaliendo del Programa !!\n");
}
//---------------------------------------------------------------------------------------------------------
void listarChoferes(char *msg)
{
    FILE *fc = fopen(ARCH_CHOFERES, "rb");
    registro temp;
    if (!fc)
    {
        printf("\n no se pudo abrir el archivo de %s\n", ARCH_CHOFERES);
        pausa();
    }
    else
    {
        printf("\n%s\n", msg);
        while (fread(&temp, sizeof(registro), 1, fc))
        {
            printf("%4d %-30s  $%4.2f %4d\n", temp.cod_chof, temp.nom_chof, temp.rec, temp.kms);
        }
    }
    fclose(fc);
    printf("\n\n");
    pausa();
}
//---------------------------------------------------------------------------------------------------------
void mostrarArchivoTexto()
{
    FILE *ft; // puntero a archivo texto, file texto
    char cadena[81];
    if ((ft = fopen(ARCH_TEXTO, "r")) == NULL)
        printf("\n\n***El archivo %s no pudo abrirse ***\n", ARCH_TEXTO);
    else
    {
        rewind(ft);
        linea(80);                    /// me posiciono al principio del archivo
        while (fgets(cadena, 81, ft)) //!=NULL)  hasta \n n-1 o salto de linea
            printf("%s", cadena);
        linea(80);
        fclose(ft);
    }
    printf("\n\n");
    pausa();
}
//---------------------------------------------------------------------------------------------------------
int menu()
{
    int opcion;
    system("cls");
    printf("\n Menu de opciones\n\n");
    printf("\n1.Ver archivo de texto original (texto.txt)\n");
    printf("2.Volcar archivo de texto a archivo binario consolidado (choferes.dat)\n");
    printf("3.Listar choferes plano del archivo Binario\n");
    printf("4.Ver archivo binario consolidado ordenado por código de chofer\n");
    printf("5.Ver archivo binario consolidado ordenado por apellido de chofer\n");
    printf("6.Salir\n");
    printf("\n\nOpción: ");
    scanf("%d", &opcion);
    return opcion;
}
//---------------------------------------------------------------------------------------------------------
void volcarTextoABinario()
{
    registro chofer;
    registro aux; // Para leer del temp_fc
    char cadena[81];
    int encontrado;
    FILE *ft = NULL;
    FILE *fc_original = NULL;               // Para el archivo binario final
    FILE *fc_temp = NULL;                   // Archivo binario temporal para consolidación
    char ARCH_TEMP[] = "choferes_temp.dat"; // Nombre del archivo temporal

    printf("\n--- INICIO DE VOLCADO A BINARIO ---\n");

    // 1. Abrir el archivo de texto
    ft = fopen(ARCH_TEXTO, "r");
    if (!ft)
    {
        printf("\nError al abrir el archivo de texto: %s\n", ARCH_TEXTO);
        pausa();
        return;
    }
    printf("Archivo de texto '%s' abierto.\n", ARCH_TEXTO);

    // 2. Abrir el archivo binario TEMPORAL para escritura (lo creará o truncará si existe)
    fc_temp = fopen(ARCH_TEMP, "wb+"); // wb+ crea/trunca y permite lectura/escritura
    if (!fc_temp)
    {
        printf("\nError al crear/abrir el archivo temporal: %s.\n", ARCH_TEMP);
        fclose(ft);
        pausa();
        return;
    }
    printf("Archivo temporal '%s' creado/truncado para consolidación.\n", ARCH_TEMP);

    // 3. Leer el archivo de texto y consolidar en el archivo temporal
    rewind(ft);
    while (fgets(cadena, sizeof(cadena), ft))
    {
        // Limpiar el posible '\n' o '\r\n' que fgets pudo haber leído
        cadena[strcspn(cadena, "\r\n")] = '\0';
        sacar(cadena, &chofer); // Convierte texto a struct
        printf("\n--- Procesando línea de texto: '%s' (Chofer: %d - '%s') ---\n", cadena, chofer.cod_chof, chofer.nom_chof);

        encontrado = 0;
        rewind(fc_temp); // Ir al inicio del archivo TEMPORAL para buscar

        // Buscar en el archivo TEMPORAL
        while (fread(&aux, sizeof(registro), 1, fc_temp) == 1)
        {
            //printf("  Comparando (TEMP): actual '%d-%s' con leido '%d-%s'\n",chofer.cod_chof, chofer.nom_chof, aux.cod_chof, aux.nom_chof);

            if (aux.cod_chof == chofer.cod_chof && strcmp(aux.nom_chof, chofer.nom_chof) == 0)
            {
                // Si coincide el chofer, actualizo los valores
                aux.rec += chofer.rec;
                aux.kms += chofer.kms;
                fseek(fc_temp, -sizeof(registro), SEEK_CUR); // Vuelve un registro atrás
                fwrite(&aux, sizeof(registro), 1, fc_temp);
                encontrado = 1;
                printf("  -> Chofer %d-%s ACTUALIZADO en archivo temporal.\n", chofer.cod_chof, chofer.nom_chof);
                break; // Sale del bucle de búsqueda
            }
        }

        if (!encontrado)
        {
            // Chofer NO encontrado: lo agrega al final del archivo TEMPORAL
            fseek(fc_temp, 0, SEEK_END);
            fwrite(&chofer, sizeof(registro), 1, fc_temp);
            printf("  -> Chofer %d-%s AGREGADO al archivo temporal.\n", chofer.cod_chof, chofer.nom_chof);
        }
    }

    fclose(ft); // Cierra el archivo de texto

    // 4. Copiar el contenido consolidado del archivo temporal al archivo binario final
    printf("\nCopiando datos consolidados del temporal a '%s'.\n", ARCH_CHOFERES);
    fclose(fc_temp); // Cierra el archivo temporal para asegurarnos de que todo se escribió

    // Abrir el archivo temporal para lectura
    fc_temp = fopen(ARCH_TEMP, "rb");
    if (!fc_temp)
    {
        printf("Error reabriendo temporal para lectura.\n");
        pausa();
        return;
    }

    // Abrir el archivo final para escritura (lo creará o lo truncará a 0 bytes)
    fc_original = fopen(ARCH_CHOFERES, "wb");
    if (!fc_original)
    {
        printf("Error abriendo archivo final '%s' para escritura.\n", ARCH_CHOFERES);
        fclose(fc_temp);
        pausa();
        return;
    }

    // Leer del temporal y escribir al final
    while (fread(&aux, sizeof(registro), 1, fc_temp) == 1)
    {
        fwrite(&aux, sizeof(registro), 1, fc_original);
    }

    fclose(fc_temp);     // Cierra el temporal
    fclose(fc_original); // Cierra el archivo binario final
    remove(ARCH_TEMP);   // Elimina el archivo temporal

    printf("Volcado y consolidación al archivo binario completado con éxito.\n");
    pausa();
}

//---------------------------------------------------------------------------------------------------------


// SACAR VERSION SIMPLE
void sacar(char x[], registro *y) // Modifico el Registro por Dirección
{
    char *cod, *nombre, *km; //  punteros para los campos del registro, recordar que todo lo partido es devuelto como cadena

    cod = strtok(x, ",");
    y->cod_chof = atoi(cod); // Convertir a entero el codigo de chofer

    nombre = strtok(NULL, ",");
    strcpy(y->nom_chof, nombre);

    km = strtok(NULL, ",");
    y->kms = atoi(km);

    y->rec = (float)y->kms * COSTO;
}


// sacar version mejorada con controles de cadena

/*

void sacar(char x[], registro *y)
{
    char *cod_str, *nombre_str, *km_str;
    size_t len;

    printf("  [funcion SACAR] Cadena original recibida: '%s'\n", x); // VER LO QUE LLEGA

    // Código del chofer
    cod_str = strtok(x, ",");
    if (cod_str != NULL)
    {
        y->cod_chof = atoi(cod_str);
    }
    else
    {
        y->cod_chof = 0;
    }

    // Nombre del chofer
    nombre_str = strtok(NULL, ",");
    if (nombre_str != NULL)
    {
        // Limpiar espacios en blanco y el carácter de retorno de carro (\r) al final
        len = strlen(nombre_str);
        printf("  [SACAR] Nombre ANTES de limpiar: '%s' (len: %d)\n", nombre_str, len); // VER NOMBRE CRUDO
        while (len > 0 && (isspace((unsigned char)nombre_str[len - 1]) || nombre_str[len - 1] == '\r'))
        {
            nombre_str[--len] = '\0';
        }
        strcpy(y->nom_chof, nombre_str);
        printf("  [SACAR] Nombre DESPUES de limpiar: '%s' (len: %d)\n", y->nom_chof, strlen(y->nom_chof)); // VER NOMBRE LIMPIO
    }
    else
    {
        strcpy(y->nom_chof, "");
    }

    // Kilómetros
    km_str = strtok(NULL, ",");
    if (km_str != NULL)
    {
        len = strlen(km_str);
        while (len > 0 && (isspace((unsigned char)km_str[len - 1]) || km_str[len - 1] == '\r')) // VERIFICAR SI HAY ESPACIOS
        {
            km_str[--len] = '\0';
        }
        y->kms = atoi(km_str);
    }
    else
    {
        y->kms = 0;
    }

    y->rec = (float)y->kms * COSTO;
}
*/

//---------------------------------------------------------------------------------------------------------
void listarChoferesOrdenados(char *msg, int opcion)
{
    registro temp;        // genero un archivo temporal porque no se cuantos registros utilizo
    registro *aux;        // genero un puntero para el archivo temporal
    registro *vec = NULL; // vector de clientes de dimension desconociada
    int n = 0;            // n es el numero de clientes

    FILE *fc = fopen(ARCH_CHOFERES, "rb");
    if (!fc)
    {
        printf("\n no se pudo abrir el archivo de %s\n", ARCH_CHOFERES);
        pausa();
    }
    else
    {
        while (fread(&temp, sizeof(registro), 1, fc))
        {
            // leo el archivo y voy agregando los choferes a mi vector
            // pide una nueva área de memoria dinámica del tamaño necesario para guardar n + 1 choferes.
            aux = (registro *)realloc(vec, (n + 1) * sizeof(registro));
            // genero el espacio en memoria para el chofer
            // Esa nueva dirección se guarda en aux
            if (aux == NULL)
            {
                printf("Error de memoria.\n");
                pausa();
            }
            // Ahora aux apunta a la nueva área de memoria
            // vec ahora apunta al nuevo bloque de memoria (más grande).

            vec = aux;     // actualizo el vector o sea
            vec[n] = temp; // le asigno el valor al chofer
            // Esto copia el contenido del chofer recién leído (temp)
            // a la posición n del vector vec.
            n++;
            // leo el archivo y voy agregando los choferes a mi vector
            // leo un chofer de archivo
        }
        if (opcion == 5)
        {
            qsort(vec, n, sizeof(registro), compararChoferesNombre); // ordenado por nombre
        }
        else
            qsort(vec, n, sizeof(registro), compararChoferesCodigo); // ordenado por codigo
        // ordeno el vector de choferes por nombre
        // compararChoferes es una función que compara dos choferes
        // y devuelve -1 si el primero es menor que el segundo
        // devuelve 0 si son iguales
        // devuelve 1 si el primero es mayor que el segundo
        // por ultimo informo
        printf("\n%s:\n", msg); // imprimo el mensaje o titulo pasado por parametro
        for (int i = 0; i < n; i++)
            printf("%4d %-30s - $%4.2f %4d\n", vec[i].cod_chof, vec[i].nom_chof, vec[i].rec, vec[i].kms);
        limpiarBuffer();
        pausa();
        free(vec);
        fclose(fc);
    }
}
//---------------------------------------------------------------------------------------------------------
int compararChoferesNombre(const void *a, const void *b)
{
    registro *c1 = (registro *)a; // convierte a en un registro
    registro *c2 = (registro *)b; // convierte b en un registro
    char nombre1[30], nombre2[30];
    strcpy(nombre1, c1->nom_chof); // copia el nombre del chofer a en nombre1
    strcpy(nombre2, c2->nom_chof); // copia el nombre del chofer b en nombre2

    // Convertimos a mayúsculas
    for (int i = 0; nombre1[i]; i++)
        nombre1[i] = toupper(nombre1[i]);
    for (int i = 0; nombre2[i]; i++)
        nombre2[i] = toupper(nombre2[i]);

    return strcmp(nombre1, nombre2); // compara los nombres
}

int compararChoferesCodigo(const void *a, const void *b)
{
    registro *c1 = (registro *)a;
    registro *c2 = (registro *)b;
    return c1->cod_chof - c2->cod_chof; // compara los códigos
}

int compararChoferesCodigo2(const void *a, const void *b)
{
    return ((registro *)a)->cod_chof - ((registro *)b)->cod_chof;
}

//---------------------------------------------------------------------------------------------------------
void linea(int x)
{
    int i;
    printf("\n");
    for (i = 0; i < x - 1; i++)
        printf("*");
    printf("\n");
}
//---------------------------------------------------------------------------------------------------------
void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
//---------------------------------------------------------------------------------------------------------
void utf8()
{
#ifdef _WIN32
    system("chcp 65001");
#endif
}
//---------------------------------------------------------------------------------------------------------

void pausa()
{
#ifdef _WIN32
    system("pause");
#endif
}