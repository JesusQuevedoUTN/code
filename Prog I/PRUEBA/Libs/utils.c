//ENTERO
int leerEntero(cadena mensaje){
    int numero;
    puts(mensaje);
    fflush(stdin);
    scanf("%d", &numero);
    return numero;
}

//FLOAT
float leerFloat(cadena mensaje){
    float numero;
    puts(mensaje);
    fflush(stdin);
    scanf("%f", &numero);
    return numero;
}

//CHAR
char leerCaracter(cadena mensaje){
    char caracter;
    puts(mensaje);
    fflush(stdin);
    scanf("%c", &caracter);
    return caracter;
}

//LEER ENTRE...
int leerEnteroEntre(int valorMin,int valorMax,cadena mensaje) {
    int valor = leerEntero(mensaje);
    while(valor<valorMin || valor>valorMax)
    {
        printf("ERROR. El valor debe estar entre %d y %d.\nVuelva a intentarlo\n\n", valorMin, valorMax);
        fflush(stdin);
        valor = leerEntero(mensaje);
    }
    return valor;
}
float leerFloatEntre(float valorMin,float valorMax,cadena mensaje) {
    float valor = leerFloat(mensaje);
    while (valor<valorMin || valor>valorMax)
    {
        printf("ERROR. El valor debe estar entre %.2f y %.f.\nVuelva a intentarlo\n\n", valorMin, valorMax);
        fflush(stdin);
        valor = leerFloat(mensaje);
    }
    return valor;
}

//MAYOR A...
int leerEnteroMayorA(int numero,cadena mensaje) {
    int valor = leerEntero(mensaje);

    while(valor<numero && numero < __INT_MAX__)
    {
        printf("ERROR. El valor debe ser mayor a %d.\nVuelva a intentarlo\n\n", numero);
        valor = leerEntero(mensaje);
    }
    return valor;
}
int leerFloatMayorA(float numero,cadena mensaje) {
    float valor = leerFloat(mensaje);

    while(valor<numero && numero < __INT_MAX__)
    {
        printf("ERROR. El valor debe ser mayor a %f.\nVuelva a intentarlo\n\n", numero);
        valor = leerFloat(mensaje);
    }
    return valor;
}

//CONFIRMAR
int confirmaUsuario(cadena mensaje){
    char letra = leerCaracter(mensaje);
    int condicion = 0, consecuencia = 0;

    while ( !(letra=='S' || letra=='s' || letra=='N' || letra=='n') )
    {
        letra = leerCaracter("Error. solo puede ingresar los valores S o N\n\nVuelva a intentarlo");
    }

    if (letra=='N' || letra=='n')
    {
        condicion = -1;
    }

    return condicion == consecuencia;
}
int esLetra(char letra)
{
    int condicion = 0, conclusion=0;
    if (!((letra >= 65 && letra <=90) || (letra >= 97 && letra <= 122)))
    {
        condicion=1;
    }
    return condicion==conclusion;
}
int esPalabra(char vec[], int x)
{
    int condicion = 0, conclusion=0;
    if ( !(vec[x-1] != ' ' && vec[x] == ' ') )
    {
        condicion=1;
    }
    return condicion==conclusion;
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

//INICIAR VECTOR
void inicializarVectorDeEnteros(int vec[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        vec[i]=0;
    }
}

//LEER VECTOR
void leerVectorDeEnteros(cadena mensaje, int vec[], int cant) {
for (int i = 0; i < cant; i++)
{
printf("[%d] ", i); 
vec[i] = leerEntero(mensaje); 
}
}
void leerVectorDeFloats(cadena mensaje, float vec[], int cant) {
for (int i = 0; i < cant; i++) {
printf("[%d] ", i);
vec[i] = leerFloat(mensaje);
}
}
void leerVectorDeCaracteres(cadena mensaje, char vec[], int cant) {
for (int i = 0; i < cant; i++)
{
    printf("[%d] ", i);
    vec[i] = leerCaracter(mensaje);
}
}

//LEER VECTOR ENTRE
void leerVectorDeEnterosEntre(int valorMin, int valorMax, cadena mensaje, int vec[], int cant) {
for (int i = 0; i < cant; i++)
{
printf("[%d] ", i);
vec[i] = leerEnteroEntre(valorMin, valorMax, mensaje);
}
}
void leerVectorDeFloatsEntre(float valorMin, float valorMax, cadena mensaje, float vec[], int cant) {
for (int i = 0; i < cant; i++)
{
printf("[%d] ", i); 
vec[i] = leerFloatEntre(valorMin, valorMax,mensaje);
}
}

//MOSTRAR VECTOR
void mostrarVectorDeEnteros(int vec[], int cant) {
for (int i = 0; i < cant; i++)
{
printf("[%d]= %d   ", i, vec[i]);
}
}
void mostrarVectorDeFloats(float vec[], int cant) {
for (int i = 0; i < cant; i++)
{
printf("[%d]= %.3f   ", i, vec[i]);
}
}
void mostrarVectorDeCaracteres(char vec[], int cant) {
for (int i = 0; i < cant; i++)
{
printf("[%d]= %c   ", i, vec[i]);
}
}

//ORDENAR VECTOR ASC Y DESC
void ordenarVectorDeEnterosAscendente(int vec[], int cant) {
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
void ordenarVectorDeEnterosDescendente(int vec[], int cant) {
    for (int i = 0; i < cant; i++)
    {
        for (int j = 0; j<cant-1; j++)
        {
            if(vec[j]<vec[j+1])
            {
                cambiarPosicionDeEnteros(&vec[j], &vec[j+1]);
            }
        }
    }
}

//CONTADOR DE CARACTERES
int contadorDePalabras(char vec[], int cant)
{
    int contador=0;
    for (int i = cant ; i > 0; i--)
        {
            if ( (i == cant && vec[i-1] != ' ')  || (vec[i-1] != ' ' && vec[i] == ' ') )
            {
                contador++;
            }
        }
    return contador;
}
int contadorDeLetras(char vec[], int cant)
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

//LEER CADENAS
void leerCadena(cadena mensaje, cadena target) {
puts(mensaje);
fflush(stdin);
gets(target);
}
void leerCadenaEntre(int minLength, int maxLength, cadena mensaje, cadena target) {
gets(target);
int largo = strlen(target);

    while (largo > maxLength || largo < minLength)
    {
        puts(mensaje);
        gets(target);
        largo = strlen(target);
    }
}

//LEER MATRIZ
void leerMatrizDeEnteros(cadena mensaje, int f, int c, int mat[f][c]) {
for (int i = 0; i < f; i++)
{
    leerVectorDeEnteros(mensaje, mat[i], c);
}
}
void leerMatrizDeFloats(cadena mensaje, int f, int c, float mat[f][c]) {
for (int i = 0; i < f; i++)
{
    leerVectorDeFloats(mensaje, mat[i], c);
}
}

//MOSTRAR MATRIZ
void mostrarMatrizDeEnteros(int f, int c, int mat[f][c]) {
for (int fila = 0; fila < f; fila++)
{
    printf("\nFila = [%d]\n",fila);
    mostrarVectorDeEnteros(mat[fila],c);
}
}
void mostrarMatrizDeFloats(int f, int c, float mat[f][c]) {
for (int fila = 0; fila < f; fila++)
{
    printf("\nFila = [%d]\n",fila);
    mostrarVectorDeFloats(mat[fila],c);
}
}

//ARCHIVO
void abrirArchivo(FILE** ppArch, cadena ruta, cadena modo) {
    *ppArch = fopen(ruta, modo);
    if (*ppArch != NULL) {
        printf("***ARCHIVO '%s' ABIERTO CORRECTAMENTE EN MODO '%s'***\n", ruta, modo);
    } else {
        printf("***NO SE PUDO ABRIR EL ARCHIVO '%s' EN MODO '%s'***\n", ruta, modo);
    }
}

void cerrarArchivo(FILE* pArch, cadena ruta) {
    int result = fclose(pArch);
    if (result == 0) {
        printf("***ARCHIVO '%s' CERRADO CORRECTAMENTE***\n", ruta);
    } else {
        printf("***NO SE PUDO CERRAR EL ARCHIVO '%s'***\n", ruta);
    }
}

void limpiarCadena(cadena texto) {
    cadena limpia = "";
    int posicion = 0, longitud = strlen(texto);
    for (int i = 0; i < longitud; i++) {
        if (    (texto[i] >= 'A' && texto[i] <= 'Z') || (texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] == ' ' && texto[i-1] != ' ')    )
        {
            limpia[posicion] = texto[i];
            posicion++;
        }
    }
    strcpy(texto, limpia);
}

void MARCA_DE_AGUA(){
/*               %%%%%=                   
               @@@@@@@@   =@@%%-          
              @@@@@@@@@@%@@@@@@@          
             @@@@@@@@@@@@@@@@@@@@@%%%     
           %@@@@@@@@@@@@@@@@@@@@@@@@@%    
         %@@@@@@@@@@@@@@@@@@@@@@@@@@+     
        #@@@@@@@@@@@@@@@@@@@@@@@@%*       
       %@@@@@@@@@@@@@@@@@@@@@@@@          
      %@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%     
     @@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@@.  
    @@@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@@  
   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%  
   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%  
    %%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   
       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#    
       @@@@@@@@@@@@@@@@@@@@@@@@@@@@       
       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@      
      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*     
     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+     
     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      
      %%@@@@@@@@@@@@@@@@@@@@@@%%%@        
         *%%%%@%@%%%%%%%%%@%              */
//0-0-0-0-0-0-0-0-0 Jessus Quev 0-0-0-0-0-0-0-0-0-0-0 
}