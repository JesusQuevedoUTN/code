//Ingresar dos números reales cualesquiera distinto de cero, imprimir la leyenda "Producto
//Positivo" si tienen el mismo signo o "producto negativo" si tienen distinto signo
//Algoritmo x1
//	Definir pri, seg Como Entero
//	leer pri, seg
//	si pri>0 y seg>0 o pri<0 y seg<0
//		entonces escribir "Producto positivo"
//	FinSi
//	si pri>0 y seg<0 o pri<0 y seg>0
//		entonces escribir "Producto negativo"
//	FinSi
//FinAlgoritmo
//
//Ingresar dos números reales cualesquiera, imprimir la leyenda "Producto Positivo" ,
//"producto negativo" o "Producto nulo" según corresponda
//Algoritmo x2
//	Definir pri, seg Como Entero
//	leer pri, seg
//	si pri>0 y seg>0 o pri<0 y seg<0 
//		escribir "Producto positivo"
//	FinSi
//	si pri>0 y seg<0 o pri<0 y seg>0 
//		escribir "Producto negativo"
//	FinSi
//	si pri=0 o seg=0
//		Escribir "Producto nulo"
//	FinSi
//FinAlgoritmo
//
//Ingresar dos números reales, realizar un algoritmo que devuelva: La suma, la resta,
//el producto y el cociente si este es posible
//Algoritmo x3
//	Definir Marcos, Jaime Como Entero
//	Leer Marcos, Jaime
//	Escribir "Suma:     " Marcos+Jaime
//	Escribir "Resta:    " Marcos-Jaime
//	Escribir "Producto: " Marcos*Jaime
//	si Jaime <> 0
//		Escribir "Division: " Marcos/Jaime
//	FinSi
//	si Jaime = 0
//		Escribir "No se puede"
//	FinSi
//	
//FinAlgoritmo
//
//Escribir un programa que, ingresando dos valores reales, informe si el primer valor
//ingresado es mayor o menor que el segundo valor ingresado.
//Algoritmo x4
//	Definir ariel, baba Como Entero
//	leer ariel, baba
//	si ariel > baba
//		Escribir "El primer valor es más grande"
//	FinSi
//	si ariel < baba
//		Escribir "El primer valor es más pequeño"
//	FinSi
//FinAlgoritmo
//
//Escribir un programa que, ingresando dos valores reales, informe si el primer valor
//ingresado es mayor, menor o igual que el segundo valor ingresado.
//Algoritmo x5
//	Definir ariel, baba Como Entero
//	leer ariel, baba
//	si ariel > baba
//		Escribir "El primer valor es más grande"
//	FinSi
//	si ariel < baba
//		Escribir "El primer valor es más pequeño"
//	FinSi
//	si ariel = baba
//		Escribir "El primer valor es igual"
//	FinSi
//FinAlgoritmo
//
//Realice un algoritmo que ingresando 2 valores reales los devuelva ordenados de
//menor a mayor.
//Algoritmo x6
//	Definir pri, seg, mas, menos Como Entero
//	Leer pri, seg
//	si pri > seg
//		mas<-pri
//		menos<-seg
//	FinSi
//	si pri < seg
//		mas<-seg
//		menos<-pri
//	FinSi
//	
//	Escribir "Menor: " menos
//	Escribir "Mayor: " mas
//FinAlgoritmo
//
//Realice un algoritmo que ingresando 2 valores reales los devuelva ordenados de
//menor a mayor.
//Algoritmo x7
//	Definir pri, seg, mas, menos Como Entero
//	Leer pri, seg
//	si pri > seg
//		mas<-pri
//		menos<-seg
//	FinSi
//	si pri < seg
//		mas<-seg
//		menos<-pri
//	FinSi
//	
//	Escribir "Mayor: " mas
//	Escribir "Menor: " menos
//FinAlgoritmo
//
// Ingresar un valor entero de dos cifras, realizar un algoritmo que devuelva el valor de
//cada una de sus cifras ordenadas de mayor a menor.
//Algoritmo x8
//	Definir num Como Entero
//	Escribir 'Inserte numero';
//	Leer num;
//	si (trunc(num/10)) < (num MOD 10)
//		Escribir "Mayor: " num MOD 10
//		Escribir "Menor: " trunc(num/10)
//	FinSi
//	
//	si (trunc(num/10)) > (num MOD 10)
//		Escribir "Mayor: " trunc(num/10)
//		Escribir "Menor: " num MOD 10 
//	FinSi
//FinAlgoritmo
//
// Ingresar un valor entero de tres cifras, realizar un algoritmo que devuelva el valor de
//cada una de sus cifras ordenadas de menor a mayor.
//Algoritmo x9
//	Definir num, centenas, decenas, unidades, may, med, men Como Entero;
//	Escribir "Ingrese un numero de 3 cifras"
//	Leer num
//	centenas<-trunc(num/100)
//	decenas<-trunc(num/10)-trunc((trunc(num/10))/10)*10
//	unidades<-num-trunc(num/10)*10
//	
//	si centenas>decenas y centenas>unidades
//		may<-centenas
//		si decenas>unidades
//			med<-decenas
//			men<-unidades
//		SiNo
//			med<-unidades
//			men<-decenas
//		FinSi
//	FinSi
//	
//	si decenas>centenasy y decenas>unidades
//		may<-decenas
//		si centenas>unidades
//			med<-centenas
//			men<-unidades
//		SiNo
//			med<-unidades
//			men<-centenas
//		FinSi
//	FinSi
//	
//	si unidades>decenas y unidades>centenas
//		may<-unidades
//		si centenas>decenas
//			med<-centenas
//			men<-decenas
//		SiNo
//			med<-decenas
//			men<-centenas
//		FinSi
//	FinSi
//	
//	Escribir "Menor: " men
//	Escribir "Medio: " med
//	Escribir "Mayor :" may
//FinAlgoritmo
//			
// Ingresar dos números A y B dejar en A el mayor y en B el menor.
//Algoritmo x10
//	Definir A, B Como Entero
//	leer A, B
//	si A>B
//		Escribir "Mayor: " A
//		Escribir "Menor: " B
//	SiNo
//		Escribir "Hagalo bien"
//	FinSi
//FinAlgoritmo
//
// Ingresar tres números A, B y C ordenarlos de mayor a menor de modo que el mayor queda
//en A el menor queda en C y el restante en B. Imprimir A, B, C.
//Algoritmo x11
//	Definir A, B, C, may, med, men Como Entero;
//	Escribir "Ingrese un numero de 3 cifras"
//	Leer A, B, C
//	
//	si A>B y A>C
//		may<-A
//		si B>C
//			med<-B
//			men<-C
//		SiNo
//			med<-C
//			men<-B
//		FinSi
//	FinSi
//	
//	si B>A y B>C
//		may<-B
//		si A>C
//			med<-A
//			men<-C
//		SiNo
//			med<-C
//			men<-A
//		FinSi
//	FinSi
//	
//	si C>B y C>A
//		may<-C
//		si A>B
//			med<-A
//			men<-B
//		SiNo
//			med<-B
//			men<-A
//		FinSi
//	FinSi
//	Escribir "Menor: " men
//	Escribir "Medio: " med
//	Escribir "Mayor :" may
//FinAlgoritmo
//
// Ingresar dos valores reales emitir la división del mayor por el menor, si es posible.
//Algoritmo x12
//	Definir A, B, may, men Como Real
//	Leer A, B
//	Si A>B
//		may<-A
//		men<-B
//	FinSi
//	Si B>A
//		men<-B
//		may<-A
//	FinSi
//	
//	Si men=0
//		Escribir "Lim-0"
//	FinSi
//	Si men<>0
//		Escribir may/men
//	FinSi
//FinAlgoritmo
//
// Ingresar el nombre y la edad de una persona, el programa informa si es o no mayor
//de edad.
//Algoritmo x13
//	Definir edad Como Entero
//	Definir nombre Como Caracter
//	Leer nombre, edad
//	si edad >= 18
//		Escribir "Tas ruco"
//	SiNo
//		Escribir "Anda a dormir"
//	FinSi
//FinAlgoritmo
//
// En un almacén se hace un 20% de descuento a los clientes cuya compra supere los
//$10000, se ingresa el importe y se debe informar cual será la cantidad que pagara por
//su compra.
//Algoritmo x14
//	Definir compra Como Real
//	descuento<-20
//	Leer compra
//	si	compra>=10000
//		Escribir "Debe pagar: " compra-compra*descuento/100
//	SiNo
//		Escribir "Debe pagar: " compra
//	FinSi
//FinAlgoritmo
//
// Un obrero necesita calcular su salario semanal, el cual se obtiene de la siguiente
//manera: Si trabaja 40 horas o menos se le paga un salario de $16 por hora, si
//trabaja más de 40 horas se le paga un salario de $16 por cada una de las primeras
//40 horas y un salario de $20 por cada hora extra.
//Algoritmo x15
//	Definir horas Como Entero
//	Leer horas
//	limite<-40
//	normal<-16
//	extra<-20
//	si horas<=limite
//		Escribir horas*normal
//	SiNo
//		Escribir limite*normal+(horas-limite)*extra
//	FinSi
//FinAlgoritmo
//
// Se ingresa un número natural del 1 al 7, el programa devuelve el nombre del día de
//la semana al cual corresponde. (Ej.: Si ingresa 1 debe devolver lunes).
//Algoritmo x16
//	Definir dia Como Entero
//	Leer dia
//	
//	si	dia=1
//		Escribir "Lunes"
//	FinSi
//	si	dia=2
//		Escribir "Martes"
//	FinSi
//	si	dia=3
//		Escribir "Miercoles"
//	FinSi
//	si	dia=4
//		Escribir "Jueves"
//	FinSi
//	si	dia=5
//		Escribir "Viernes"
//	FinSi
//	si	dia=6
//		Escribir "Sabado"
//	FinSi
//	si	dia=7
//		Escribir "Domingo"
//	FinSi
//	si dia<=0 o dia >7
//		Escribir "No es tan dificil, sabes?"
//	FinSi
//FinAlgoritmo