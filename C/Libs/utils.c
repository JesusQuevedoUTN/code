//ENTERO
int LeerEntero(char* mensaje){
    int numero;
    puts(mensaje);
    fflush(stdin);
    scanf("%d", &numero);
    return numero;
}
void LeerEnteroVoid(int *numero, char* mensaje){
    puts(mensaje);
    fflush(stdin);
    scanf("%d", &numero);
}

//FLOAT
float LeerFloat(char* mensaje){
    float numero;
    puts(mensaje);
    fflush(stdin);
    scanf("%f", &numero);
    return numero;
}
void LeerFloatVoid(float *numero, char* mensaje){
    puts(mensaje);
    fflush(stdin);
    scanf("%f", &numero);
}

//CHAR
char LeerCaracter(char* mensaje){
    char caracter;
    puts(mensaje);
    fflush(stdin);
    scanf("%c", &caracter);
    return caracter;
}
void LeerCaracterVoid(char* caracter, char* mensaje){
    puts(mensaje);
    fflush(stdin);
    scanf("%c", &caracter);
}

//LEER ENTRE...
int LeerEnteroEntre(int valorMin,int valorMax, char* mensaje) {
    int valor = LeerEntero(mensaje);
    while(valor<valorMin || valor>valorMax)
    {
        printf("ERROR. El valor debe estar entre %d y %d.\nVuelva a intentarlo\n\n", valorMin, valorMax);
        fflush(stdin);
        valor = LeerEntero(mensaje);
    }
    return valor;
}
float LeerFloatEntre(float valorMin,float valorMax,char* mensaje) {
    float valor = LeerFloat(mensaje);
    while (valor<valorMin || valor>valorMax)
    {
        printf("ERROR. El valor debe estar entre %.2f y %.f.\nVuelva a intentarlo\n\n", valorMin, valorMax);
        fflush(stdin);
        valor = LeerFloat(mensaje);
    }
    return valor;
}

//MAYOR A...
int LeerEnteroMayorA(int numero,char*  mensaje) {
    int valor = LeerEntero(mensaje);

    while(valor<numero && numero < __INT_MAX__)
    {
        printf("ERROR. El valor debe ser mayor a %d.\nVuelva a intentarlo\n\n", numero);
        valor = LeerEntero(mensaje);
    }
    return valor;
}
int LeerFloatMayorA(float numero,char*  mensaje) {
    float valor = LeerFloat(mensaje);

    while(valor<numero && numero < __INT_MAX__)
    {
        printf("ERROR. El valor debe ser mayor a %f.\nVuelva a intentarlo\n\n", numero);
        valor = LeerFloat(mensaje);
    }
    return valor;
}

//CONFIRMAR
int confirmaUsuario(char*  mensaje){
    char letra = LeerCaracter(mensaje);
    int condicion = 0, consecuencia = 0;

    while ( !(letra=='S' || letra=='s' || letra=='N' || letra=='n') )
    {
        letra = LeerCaracter("Error. solo puede ingresar los valores S o N\n\nVuelva a intentarlo");
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
void leerVectorDeEnteros(char*  mensaje, int vec[], int cant) {
for (int i = 0; i < cant; i++)
{
printf("[%d] ", i);
vec[i] = LeerEntero(mensaje);
}
}
void leerVectorDeFloats(char*  mensaje, float vec[], int cant) {
for (int i = 0; i < cant; i++) {
printf("[%d] ", i);
vec[i] = LeerFloat(mensaje);
}
}
void leerVectorDeCaracteres(char*  mensaje, char vec[], int cant) {
for (int i = 0; i < cant; i++)
{
    printf("[%d] ", i);
    vec[i] = LeerCaracter(mensaje);
}
}

//LEER VECTOR ENTRE
void leerVectorDeEnterosEntre(int valorMin, int valorMax, char*  mensaje, int vec[], int cant) {
for (int i = 0; i < cant; i++)
{
printf("[%d] ", i);
vec[i] = LeerEnteroEntre(valorMin, valorMax, mensaje);
}
}
void leerVectorDeFloatsEntre(float valorMin, float valorMax, char*  mensaje, float vec[], int cant) {
for (int i = 0; i < cant; i++)
{
printf("[%d] ", i);
vec[i] = LeerFloatEntre(valorMin, valorMax,mensaje);
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

//LEER char* S
void leerCadena(char*  mensaje, char*  target) {
puts(mensaje);
gets(target);
}
void leerCadenaEntre(int minLength, int maxLength, char* mensaje, char* target) {
int largo;
do
{
    puts(mensaje);
    gets(target);
    largo = strlen(target);
}while (largo > maxLength || largo < minLength);
}

//LEER MATRIZ
void leerMatrizDeEnteros(char*  mensaje, int f, int c, int mat[f][c]) {
for (int i = 0; i < f; i++)
{
    leerVectorDeEnteros(mensaje, mat[i], c);
}
}
void leerMatrizDeFloats(char*  mensaje, int f, int c, float mat[f][c]) {
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


