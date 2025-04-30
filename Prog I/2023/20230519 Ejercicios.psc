//1.Se ingresan 20 números por teclado y se indica si alguno fue negativo mediante un mensaje
//Algoritmo E1
//	Definir a Como numero
//	validar<-0
//	Escribir "Ingrese 5 numeros"
//	Para i=1 Hasta 5 
//		Leer a
//		Si a=<0 Entonces
//			validar<-1
//		Fin Si
//	Fin Para
//	
//	Si validar=0 Entonces
//		Escribir "Todos los valores fueron positivos"
//	SiNo
//		Escribir "Al menos un valor fue negativo"
//	Fin Si
//	
//FinAlgoritmo
//2.Se leen 20 números y se emite un mensaje indicando cuántos fueron negativos.
//Algoritmo E2
//	Definir a Como numero
//	validar<-0
//	Escribir "Ingrese 5 numeros"
//	Para i=1 Hasta 5 
//		Leer a
//		Si a<=0 Entonces
//			validar=validar+1
//		Fin Si
//	Fin Para
//	
//	Si validar<>0 Entonces
//		Escribir "Un total de " validar " valores fueron negativos"
//	SiNo
//		Escribir "Todos fueron positivos"
//	Fin Si
//FinAlgoritmo
//3.Se leen 20 números y se emite su promedio.
//Algoritmo E3
//	Definir a Como numero
//	Escribir "Ingrese 5 numeros"
//	Para i=1 Hasta 5 
//		Leer a
//		suma=suma+a
//	FinPara
//	Escribir "Su promedio es: " suma/5
//FinAlgoritmo
//4.Se lee un entero N y luego N número reales. Se emite el menor de ellos.
//Algoritmo E4
//	Definir a, N, Minimo Como numero
//	Escribir "Cuantos enteros quiere?"
//	Leer N
//	Para i=1 Hasta N 
//		Leer a
//		Si i=1 o a<=Minimo Entonces
//			Minimo=a
//		Fin Si
//	Fin Para
//	Escribir "El minimo es " Minimo
//FinAlgoritmo
//5.Se leen N números; se emite su promedio.
//Algoritmo E5
//	Definir a, N, suma Como numero
//	suma<-0
//	Escribir "Cuantos enteros quiere?"
//	Leer N
//	Para i=1 Hasta N 
//		Leer a
//		suma=suma+a
//	Fin Para
//	Escribir "El promedio es " suma/N
//FinAlgoritmo
//6.Se lee una serie de N números, de a uno y se emite:
//a) la cantidad de positivos;
//b) el valor del primer y último números leídos;
//c) la sumatoria;
//Algoritmo E6
//	Definir a, N, suma Como numero
//	suma<-0
//	Escribir "Cuantos enteros quiere?"
//	Leer N
//	Para i=1 Hasta N 
//		Leer a
//		suma=suma+a
//	Fin Para
//	Escribir "El promedio es " suma/N
//FinAlgoritmo
//7.Se lee un número no determinado de veces un entero no nulo. El fin de datos se indica con
//un 0.Se desea emitir el valor del promedio de los números positivos leídos.
//Algoritmo E7
//	Definir a, suma, i Como numero
//	i<-0
//	suma<-0
//	Escribir "Ingrese la cantidad de numeros que desea, pulse 0 Para finalizar"
//	Repetir
//		Leer a
//		Si a<>0 Entonces
//			i=i+1
//			suma=suma+a
//		Fin Si
//	Hasta Que a=0
//	Escribir "El promedio es " suma/i
//FinAlgoritmo
//8. Se ingresa un número no determinado de valores enteros. El último es -1. La computadora
//indica cuál fue el máximo número ingresado.
//Algoritmo E8
//	Definir a, N, Minimo Como numero
//	Escribir "Meta numeros y pulse 0 para finalizar, el mínimo estandarizado es -1"
//	Minimo<--1
//	Repetir
//		Leer a
//		Si a<Minimo Entonces
//			Minimo=a
//		Fin Si
//	Hasta Que a=0
//	Escribir "El minimo es " Minimo
//FinAlgoritmo
//9. Se lee un número natural N y la computadora emite los números naturales pares menores
//que N.
//Algoritmo E9
//	Definir N Como Entero
//	Escribir "Inserte un numero, y yo te digo los numeros PARES NATURALES menores a ese"
//	Leer N
//	Mientras N<=0
//		Escribir "Para ser un numero natural, este debe ser mayor o igual a 1"
//		Leer N
//	FinMientras
//	Si N=1 Entonces
//		Mostrar "Es Natural pero no hay ningun natural PAR menor a él"
//	Fin Si
//	Para i<-2 Hasta N Con Paso 2 Hacer
//		Mostrar i
//	Fin Para
//FinAlgoritmo

//POR ALGUN MOTIVO DEL 10 AL 14 NO SE GUARDARON, NO SÉ PORQUÉ, ASÍ QUE NO LOS VOY A REHACER, DIRECTAMENTE HARÉ DEL 15 AL 19

//10. Se leen dos enteros N y M, y se emite la tabla de multiplicar de N entre 1 y M.
//11. Se ingresa un número natural N, seguido de N reales. Se emite el promedio de los números
//positivos, el promedio de los números negativos y la cantidad de ceros.
//12. Se leen N números enteros y se emite el mayor y la posición en la que ingresó por primera
//vez.
//13. Se lee un número entero N mayor o igual que 0 y, la computadora muestra el factorial del
//mismo.
//14. Se ingresa número n y a continuación n enteros de 3 cifras, informar cuántos de ellos son
//capicúas.


//15. En un locutorio se realizan 3 tipos de llamadas. 
//1- local, se abona $0,50 por minuto.
//2- urbana, se abona $4 los primeros 3 minutos y $2 cada minuto adicional. 
//3- interurbana, se ingresa una tarifa T1 para los primeros 3 minutos y una tarifa T2 para cada minuto
//adicional (t1 y t2 dependen del país de destino).
//La duración de la llamada es un número entero. Se ingresa tipo de llamada y duración, se desea informar:
//Tipo de llamada, duración e importe a abonar. Al cambiar el turno se ingresa F y se emite el importe total
//recaudado. Validar que solo pueda ingresar los números 1, 2 o 3 para empezar a operar.
//Algoritmo E15
//	Definir llamada, tiempo Como Entero
//	Definir nombre Como Caracter
//	Definir T3, TAd, aporte, aporteTotal  Como Real
//	
//	Repetir
//		Mostrar "Desea ingresar una llamada?"
//		Mostrar "PULSE S PARA SEGUIR, Y F PARA NEGARSE"
//		Repetir
//			Leer nombre
//			si nombre<>'S' y nombre<>'F' y nombre<>'s' y nombre<>'f'
//				Mostrar "PULSE S PARA SEGUIR, Y F PARA NEGARSE"
//			FinSi
//		Hasta Que nombre=='S' o nombre=='F' o nombre=='s' o nombre=='f'
//		
//		Si nombre=='S' o nombre=='s' Entonces	
//			Mostrar "Bienvenidos a llamadas LLamadón Co., Cuantos minutos estuvo en su llamada?"
//			Repetir
//				Leer tiempo
//				Si tiempo<0 Entonces
//					Mostrar "ERROR. No puede estar tiempo negativo en una llamada, vuelva a intentar"
//				Fin Si
//			Hasta Que tiempo>=0
//			
//			Mostrar "Que tipo de llamada fue?"
//			Mostrar "1. Local" 
//			Mostrar "2. Urbana"
//			Mostrar "3. Interurbana"
//			Repetir
//				Leer llamada
//				Segun llamada Hacer
//					1:
//						aporte<-tiempo*0.5
//					2:
//						Si tiempo<=3 Entonces
//							aporte<-4
//						SiNo
//							aporte<-4+(tiempo-3)*2
//						Fin Si
//					3:
//						Mostrar "De cuanto es la Tarifa del país al que llamará?"
//						Repetir
//							Leer T3
//							Si T3<0 Entonces
//								Mostrar "ERROR. Una tarifa no puede ser negativa"
//							Fin Si
//						Hasta Que T3>0
//						Mostrar "De cuanto es la segunda Tarifa?"
//						Repetir
//							Leer TAd
//							Si TAd<0 Entonces
//								Mostrar "ERROR. Una tarifa no puede ser negativa"
//							Fin Si
//						Hasta Que TAd>0
//						Si tiempo<=3 Entonces
//							aporte<-T3
//						SiNo
//							aporte<-T3+(tiempo-3)*TAd
//						Fin Si
//					De Otro Modo:
//						Mostrar "Solo tenemos 3 tipos de llamada, vuelvalo a intentar"
//				Fin Segun
//			Hasta Que llamada=1 o llamada=2 o llamada=3
//			aporteTotal<-aporteTotal+aporte
//			Mostrar "Usted estuvo " tiempo " minutos en la llamada tipo " llamada
//			Mostrar "Debe abonar $" aporte
//			Mostrar ""
//		Fin Si
//	Hasta Que nombre='F'
//	Mostrar "Dios lo bendiga, adios"
//	Mostrar "El total recaudado es $" aporteTotal
//	
//FinAlgoritmo
//
//16. Se ingresa un número entero y, la computadora indica si es primo o no.
//Algoritmo E16
//	Definir a, p Como Entero
//	p<-0
//	Mostrar "Ingrese un entero, le diré si es primo o no"
//	Repetir
//		Leer a
//		si a<=0
//			Mostrar "Un numero igual o menor a cero no puede ser primo por definicion"
//		FinSi
//	Hasta Que a>0
//	Para i<-2 Hasta a
//		si a MOD i = 0
//			p<-p+1
//		FinSi
//	Fin Para
//	Si p<=1 Entonces
//		Mostrar a " es Primo"
//	SiNo
//		Mostrar a " NO es Primo"
//	Fin Si
//FinAlgoritmo
//17. Se ingresa un número entero N y se emiten los N primeros números primos.
//
//Algoritmo E17
//	
//FinAlgoritmo
//

//ME ABURRÍ DE ESTE, ES DE NOCHE, YA ESTÁ

//18. Durante el día, una farmacia ingresa los importes de sus ventas. Junto a cada importe, se
//ingresa una 'C', si la venta fue realizada con descuento por obra social, o una 'S', si la venta
//fue sin descuento. Al final del día, se ingresa una venta negativa. La computadora muestra el
//monto total de las ventas del día y el porcentaje de clientes que compraron con descuento.
//Algoritmo E18
//	Definir venta Como Real
//	Definir descuento Como Entero
//	Definir obra Como Caracter
//	
//	Repetir
//		Leer venta
//		Mostrar "Tiene obra social?"
//		Repetir
//			Leer obra
//			Si obra<>'C' y obra<>'S' y obra<>'c' y obra<>'s' Entonces
//				Mostrar "ERROR. solo hay 2 opciones"
//			Fin Si
//		Hasta Que obra='C' o obra='S'
//	Hasta Que venta<0
//	
//FinAlgoritmo
//
//19. Prepara un programa que permita imprimir cada una de las sucesiones numéricas que se
//presentan a continuación:
//a)
//1 2 3 4 5 6 7
//1 2 3 4 5 6 7
//1 2 3 4 5 6 7
//1 2 3 4 5 6 7
//b)
//1 1 1 1 1 1 1
//2 2 2 2 2 2 2
//3 3 3 3 3 3 3
//Algoritmo E19
//	Leer a
////	Para i<-1 Hasta a 
////		Para p<-1 Hasta 7
////			Mostrar Sin Saltar p
////		Fin Para
////		Mostrar ""
////	Fin Para
////	Para i<-1 Hasta a 
////		Para p<-1 Hasta 7
////			Mostrar Sin Saltar i
////		Fin Para
////		Mostrar ""
////	Fin Para	
//FinAlgoritmo