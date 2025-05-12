
#ifndef UTILES_H_  // guardas de inclusión
    #define UTILES_H_
    /*
    Las guardas de inclusión (también llamadas include guards) 
    son una técnica en C y C++ 
    que evita que el contenido de un archivo de encabezado (.h) 
    sea incluido más de una vez durante la compilación.
    #ifndef UTILES_H_: pregunta al preprocesador 
    si no se ha definido el identificador UTILES_H_.

    #define UTILES_H_: si no estaba definido, ahora lo define. 
    Esto marca que ya se incluyó el archivo.

    #endif: cierra la condición #ifndef.
    */

    #include <stdlib.h> // recordar que los corchetes angulares se utilizan para librerias standard
    #include <stdio.h>
    #include <time.h>
    #include <string.h>
    #include <conio.h>


    void linea(int x)
    {
        int i;
        for (i = 0; i < x-1; i++)
            printf("*");
        printf("\n");
    }

    void limpiarBuffer()
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    void utf8()
    {
        #ifdef _WIN32
        system("chcp 65001 < nul");
        #endif
    }

    int leerEntero(const char *mensaje)
    {
        char buffer[100];
        int numero;
        int flag = 1;

        while (flag)
        {
            printf("%s", mensaje);
            if (fgets(buffer, sizeof(buffer), stdin) != NULL)
            {
                if (sscanf(buffer, "%d", &numero) == 1)
                {
                    flag = 0;
                }
                else
                {
                    printf("Entrada inválida. Intente nuevamente.\n");
                }
            }
        }
        return numero;
    }

    void tecla()
    {
        system("pause");
    }

    void nada() 
    {
        printf("Hola desde utils.c\n");
    }
#endif /* UTILES_H_ */
