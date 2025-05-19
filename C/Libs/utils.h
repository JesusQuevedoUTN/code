#ifndef UTILS_H_INCLUDED
    #define UTILS_H_INCLUDED

    #include<stdio.h> //stdio.h significa standar input-output. Header(caneceras)

    #include<string.h>
    #include<stdlib.h>
    #include<stdbool.h>
    #include<math.h>
    #include<ctype.h>

    //UTILS
    void tecla()
    {
        system("pause");
    }

    void limpiarBuffer() {
        int c;
        while ((c = getchar()) != '\n' && c!= EOF);
    }
    void utf8()
    {
        #ifdef _WIN32
        system("chcp 65001 < nul");
        #endif
    }
    
    //MIOS
    void iniciar()
    {
        utf8();
        system("cls");
    }
    void pausa()
    {
        system("pause");
        clean();
    }
    void clean(){
        system("cls");
    }

    //FILE
void iniciarBinario(FILE* (*archivo), char* nombreArchivo)
{
    if ( (*archivo) == NULL)
    {
        (*archivo) = fopen(nombreArchivo, "wb+");
        if ( (*archivo) == NULL)
        {
            printf("No se pudo crear el archivo %s.\n", nombreArchivo);
            return 1;
        }
        printf("El archivo %s ha sido creado.\n", nombreArchivo);
    }
    else
    {
        printf("El archivo %s ha sido abierto para lectura y escritura.\n", nombreArchivo);
    }
}


    //ENTERO
    int LeerEntero(){
        int numero;
        limpiarBuffer();
        scanf("%d", &numero);
        return numero;
    }

    //FLOAT
    float LeerFloat(){
        float numero;
        limpiarBuffer();
        scanf(" %f", &numero);
        return numero;
    }

    //CHAR
    char LeerCaracter(){
        char caracter;
        limpiarBuffer();
        scanf("%c", &caracter);
        return caracter;
    }

    //LEER ENTRE...
    int LeerEnteroEntre(int valorMin,int valorMax) {
        int valor = LeerEntero();
        while(valor<valorMin || valor>valorMax)
        {
            printf("ERROR. Fuera de rango [%d - %d].\n", valorMin, valorMax);
            valor = LeerEntero();
        }
        return valor;
    }

    float LeerFloatEntre(float valorMin,float valorMax) {
        float valor = LeerFloat();
        while (valor<valorMin || valor>valorMax)
        {
            printf("ERROR. El valor debe estar entre %.2f y %.f.\nVuelva a intentarlo\n\n", valorMin, valorMax);
            limpiarBuffer();
            valor = LeerFloat();
        }
        return valor;
    }

    int esLetra(char letra)
    {
        return (letra >= 'a' && letra <='z') || (letra >= 'A' && letra <= 'Z');
    }

    int esPrimo(int primo)
    {
        int i = 2;
        while (primo%i!=0 && i<primo)
        {
            i++;
        }
        return i == primo;
    }
    int sonIgualesCaracteres(char x, char y)
    {
        return x==y;
    }

    //PROMEDIO
    float promedio(int total, int parcial) {
        return (float)total/parcial;
    }

    //CAMBIAR POSICION
    void cambiarPosicionDeEnteros(int *x, int *y)
    {
        int aux = *x;
        *x=*y;
        *y=aux;
    }

    void cambiarPosicionDeCaracteres(char *x, char *y)
    {
        char aux = *x;
        *x=*y;
        *y=aux;
    }

    //ORDENAR VECTOR ASC Y DESC
    void ordenarVectorDeEnterosAscendente(int* vec, int cant) {
        for (int i = 0; i < cant; i++)
        {
            for (int j = 0; j<cant-1; j++)
            {
                if(vec[j]>vec[j+1])
                {
                    cambiarPosicionDeEnteros(&vec[j], &vec[j+1]);
                }
            }
        }
    }

    int contadorDeLetras(char* vec, int cant)
    {
        int contador=0;
        for (int i = cant ; i > 0; i--)
            {
                if (vec[i-1] != ' ')
                {
                    contador++;
                }
            }
        return contador;
    }

    int baseADecimal(char* numero, int base)
    {
        int sumatoria =     0;
        int digito;
        char c;
        int len = strlen(numero);

        for (int i = 0; i < len ; i++)
        {
            c = toupper(numero[(len-1)-i]);
            
            if (isdigit(c))
            {
                digito = c -'0';
            }
            else
            {
                digito = c - 'A' + 10;
            }
            
            sumatoria = sumatoria + digito * pow(base,i);
        }

        return sumatoria;
    }


    void nada()
    {
        
    }


#endif//UTILS_H_INCLUDED