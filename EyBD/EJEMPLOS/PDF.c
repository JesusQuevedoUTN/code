// alea2.c: Ejemplo de archivos de acceso aleatorio.
// Incluye la opción de ordenar el archivo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stRegistro \
 char valido; // Campo que indica si el registro es valido S->Válido, N->Inválido
 char nombre[34];
 int dato[4];
};
int Menu();
void Leer(struct stRegistro *reg);
void Mostrar(struct stRegistro *reg);
void Listar(long n, struct stRegistro *reg);
long LeeNumero();
void Empaquetar(FILE **fa);
void Ordenar(FILE *fa);
void Intercambia(FILE *fa, long iz, long de);
char *LeeCampo(FILE *fa, long n, char *buf);
void QuickSort(FILE *fa, long inicio, long final);
int main()
{
 struct stRegistro reg;
 FILE *fa;
 int opcion;
 long numero;
 fa = fopen("alea.dat", "r+b"); // Este modo permite leer y
escribir
 if(!fa) fa = fopen("alea.dat", "w+b"); // si el archivo no existe,
lo crea.
 do {
 opcion = Menu();
 switch(opcion) {
 case '1': // Añadir registro
 Leer(&reg);
 // Insertar al final:
 fseek(fa, 0, SEEK_END);
 fwrite(&reg, sizeof(struct stRegistro), 1, fa);
 break;
 case '2': // Mostrar registro
 system("cls");
 printf("Mostrar registro: ");
 numero = LeeNumero();
 fseek(fa, numero*sizeof(struct stRegistro), SEEK_SET);
 fread(&reg, sizeof(struct stRegistro), 1, fa);
 Mostrar(&reg);
 break;
 case '3': // Eliminar registro
 system("cls");
 printf("Eliminar registro: ");
 numero = LeeNumero();
 fseek(fa, numero*sizeof(struct stRegistro), SEEK_SET);
 fread(&reg, sizeof(struct stRegistro), 1, fa);
 reg.valido = 'N';
 fseek(fa, numero*sizeof(struct stRegistro), SEEK_SET);
 fwrite(&reg, sizeof(struct stRegistro), 1, fa);
 break;
 case '4': // Mostrar todo
 rewind(fa);
 numero = 0;
 system("cls");
 printf("Nombre Datos\n");
 while(fread(&reg, sizeof(struct stRegistro), 1, fa))
 Listar(numero++, &reg);
 system("PAUSE");
 break;
 case '5': // Eliminar marcados
 Empaquetar(&fa);
 break;
 case '6': // Ordenar
 Empaquetar(&fa);
 Ordenar(fa);
 break;
 }
 } while(opcion != '0');
 fclose(fa);
 return 0;
}
// Muestra un menú con las opciones disponibles y captura una opción
del usuario
int Menu()
{
 char resp[20];
 do {
 system("cls");
 printf("MENU PRINCIPAL\n");
 printf("--------------\n\n");
 printf("1- Insertar registro\n");
 printf("2- Mostrar registro\n");
 printf("3- Eliminar registro\n");
 printf("4- Mostrar todo\n");
 printf("5- Eliminar registros marcados\n");
 printf("6- Ordenar archivo\n");
 printf("0- Salir\n");
 fgets(resp, 20, stdin);
 } while(resp[0] < '0' && resp[0] > '6');
 return resp[0];
}
// Permite que el usuario introduzca un registro por pantalla
void Leer(struct stRegistro *reg)
{
 int i;
 char numero[6];
 system("cls");
 printf("Leer registro:\n\n");
 reg->valido = 'S';
 printf("Nombre: ");
 fgets(reg->nombre, 34, stdin);
 // la función fgets captura el retorno de línea, hay que eliminarlo:
 for(i = strlen(reg->nombre)-1; i && reg->nombre[i] < ' '; i--)
 reg->nombre[i] = 0;
 for(i = 0; i < 4; i++) {
 printf("Dato[%1d]: ", i);
 fgets(numero, 6, stdin);
 reg->dato[i] = atoi(numero);
 }
}
// Muestra un registro en pantalla, si no está marcado como borrado
void Mostrar(struct stRegistro *reg)
{
 int i;
 system("cls");
 if(reg->valido == 'S') {
    printf("Nombre: %s\n", reg->nombre);
 for(i = 0; i < 4; i++)
 printf("Dato[%1d]: %d\n", i, reg->dato[i]);
 }
 system("PAUSE");
}
// Muestra un registro por pantalla en forma de listado,
// si no está marcado como borrado
void Listar(long n, struct stRegistro *reg)
{
 int i;
 if(reg->valido == 'S') {
 printf("[%6ld] %-34s", n, reg->nombre);
 for(i = 0; i < 4; i++) printf(", %4d", reg->dato[i]);
 printf("\n");
 }
}
// Lee un número suministrado por el usuario
long LeeNumero()
{
 char numero[6];
 fgets(numero, 6, stdin);
 return atoi(numero);
}
// Elimina los registros marcados como borrados
void Empaquetar(FILE **fa)
{
 FILE *ftemp;
 struct stRegistro reg;
 ftemp = fopen("alea.tmp", "wb");
 rewind(*fa);
 while(fread(&reg, sizeof(struct stRegistro), 1, *fa))
 if(reg.valido == 'S')
 fwrite(&reg, sizeof(struct stRegistro), 1, ftemp);
 fclose(ftemp);
 fclose(*fa);
 remove("alea.bak");
 rename("alea.dat", "alea.bak");
 rename("alea.tmp", "alea.dat");
 *fa = fopen("alea.dat", "r+b");
}
void Ordenar(FILE *fa)
{
 long nRegs;
 fseek(fa, 0, SEEK_END);
 nRegs = ftell(fa)/sizeof(struct stRegistro);
 QuickSort(fa, 0L, nRegs-1);
}
void QuickSort(FILE *fa, long inicio, long final)
{
 long iz, de;
 char mitad[34];
 static char cad[34];

 iz = inicio;
 de = final;
 strcpy(mitad, LeeCampo(fa, (iz+de)/2, cad));
 do {
 while(strcmp(LeeCampo(fa, iz, cad), mitad) < 0 && iz < final)
iz++;
 while(strcmp(mitad, LeeCampo(fa, de, cad)) < 0 && de > inicio)
de--;
 if(iz < de) Intercambia(fa, iz, de);
 if(iz <= de) {
 iz++;
 de--;
 }
 } while(iz <= de);
 if(inicio < de) QuickSort(fa, inicio, de);
 if(iz < final) QuickSort(fa, iz, final);
}
char *LeeCampo(FILE *fa, long n, char *buf)
{
 struct stRegistro reg;
 fseek(fa, n*sizeof(struct stRegistro), SEEK_SET);
 fread(&reg, sizeof(struct stRegistro), 1, fa);
 strcpy(buf, reg.nombre);
 return buf;
}
void Intercambia(FILE *fa, long iz, long de)
{
 struct stRegistro reg1, reg2;
 fseek(fa, iz*sizeof(struct stRegistro), SEEK_SET);
 fread(&reg1, sizeof(struct stRegistro), 1, fa);
 fseek(fa, de*sizeof(struct stRegistro), SEEK_SET);
 fread(&reg2, sizeof(struct stRegistro), 1, fa);
 fseek(fa, iz*sizeof(struct stRegistro), SEEK_SET);
 fwrite(&reg2, sizeof(struct stRegistro), 1, fa);
 fseek(fa, de*sizeof(struct stRegistro), SEEK_SET);
 fwrite(&reg1, sizeof(struct stRegistro), 1, fa);
}