//Se ingresa un valor de dos cifras, realizar un algoritmo que devuelva la
//cifra de las unidades y la cifra de las decenas

//Algoritmo Ejercicio_1
//	Definir num Como Entero
//	Escribir 'Inserte numero';
//	Leer num;
//	Escribir 'Decimales:' trunc(num/10)
//	Escribir 'Unidades:' num MOD 10;
	
//FinAlgoritmo

//Escribir un programa para que, ingrese un número de tres cifras, imprima
//o uestre por pantalla la cifra central. En la entrada de datos un mensaje
//debe decir "Indicar un número de tres cifras", la salida será:
//Valor: XXX Central: X
//Algoritmo Ejercicio_2
//	Definir num Como Entero;
//	Escribir "Ingrese un numero de 3 cifras"
//	Leer num
//	Escribir "Valor:" num
//	Escribir "Cifra central:" (num-trunc(num/100)*100)-(num-trunc(num/100)*100-trunc((num-trunc(num/100)*100)/10))
//FinAlgoritmo

//Un negocio de prendas de vestir decide hacer una liquidación de fin de temporada, le
//aplica a la mercadería un descuento del 18% sobre el precio marcado. Escribir un
//programa para que ingrese el precio de una prenda y obtenga el precio con descuento. En
//la entrada de datos un mensaje debe decir: "Indicar precio de lista", la salida será:
//Precio de lista: $XXXXX,XX
//Descuento: 18% (sobre el precio de lista)
//Total, a abonar: $XXXX,XX
//Algoritmo Ejercicio_3
//	Definir precio, descuento Como Real
//	descuento<-0.18
//	Leer precio
//	Escribir "Precio: $" precio;
//	Escribir "Descuento: " descuento*100 "%";
//	Escribir "Total a abonar: $" precio-precio*descuento;
//FinAlgoritmo

//Escribir un programa para que ingrese un numero de dos cifras, imprima un nuevo
//	número que resulte de sus cifras permutadas. En la entrada de datos un mensaje debe
//decir: "Indicar un número de dos cifras", la salida será:
//	Valor: XK (ej: 57)
//		Valor permutado: KX (ej: 75)
//Algoritmo Ejercicio_4
//	Definir num, pri, seg Como Entero
//	Escribir "Escribir un numero de 2 decimales"
//	Leer num;
//	pri<-trunc(num/10)
//	seg<-num mod 10
//	num<-seg*10+pri
//	Escribir num
//FinAlgoritmo

//Dada una fecha expresada con un entero de 6 dígitos, donde los dos primeros dígitos
//expresan el día, el tercero y el cuarto expresan el mes y los dos últimos expresan el año,
//obtener el mes. En la entrada de datos debe decir "Indicar una fecha como un entero de 6
//dígitos", la salida será:
//Fecha: DDMMAA (ej: 120614)
//	Mes: MM (ej: 06)
//Algoritmo Ejercicio_5
//	Definir fecha, mes Como Entero
//	Escribir "Escribir la fecha con 6 digitos"
//	Leer fecha
//	mes<- trunc((fecha mod 10000)/100)
//	Escribir mes
//FinAlgoritmo

//calcular area y perimetro de un cuadrado
//Algoritmo Ejercicio_6
//	Definir lado Como Entero
//	Leer lado
//	Escribir "Area: " lado*lado
//	Escribir "Perimetro: " lado*4
//FinAlgoritmo

//Ingresar el valor de una hora de trabajo y la cantidad de horas trabajadas, realizar un
//algoritmo que calcule el sueldo bruto
//Algoritmo Ejercicio_7
//	Definir cantidad, horas Como Entero
//	Escribir "Cuanto cobra por hora?"
//	leer cantidad
//	Escribir "Cuantas horas laburó?"
//	leer horas
//	Escribir "Sueldo: " cantidad * horas
//FinAlgoritmo

//Convertir de Fhrenheit a Celsius
//Algoritmo Ejercicio_8
//	Definir grados Como Real
//	Leer grados
//	Escribir grados "° Fahrenheit son " (grados-32)/1.8 "° Celsius"
//FinAlgoritmo

//Ingresar hora minutos y segundos, e indicar cuantos segundos hay en ese intervalo
//Algoritmo Ejercicio_9
//	Definir hor, min, seg Como Entero
//	Leer hor, min, seg
//	Escribir "En total hay: " hor*60*60 + min*60 + seg " segundos";
//FinAlgoritmo

//Ingresar numero de 3 digitos, y mostrar el numero las cifras por separado
//Valor XXX Unidades X Decenas X Centenas X
//Algoritmo Ejercicio_10
//	Definir num Como Entero;
//	Escribir "Ingrese un numero de 3 cifras"
//	Leer num
//	Escribir "Valor:" num
//	Escribir "Centenas:" trunc(num/100)
//	Escribir "Decenas: " trunc(num/10)-trunc((trunc(num/10))/10)*10
//	Escribir "Unidades:" num-trunc(num/10)*10
//
//FinAlgoritmo
	