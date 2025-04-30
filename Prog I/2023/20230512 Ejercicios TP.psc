//Algoritmo Ejercicio_1
//	Definir L1, L2, L3 Como Real
//	Definir may, med, men Como Real
//	Escribir "Ingrese los lados de un triángulo: "
//	Escribir "Lado 1:"
//	Leer L1
//	Escribir "Lado 2:"
//	Leer L2
//	Escribir "Lado 3:"
//	Leer L3
//	
//	Si L1>0 y L2>0 y L3>0 Entonces
//		
//		si L1>L2 y L1>L3
//			may<-L1
//			si L2>L3
//				med<-L2
//				men<-L3
//			SiNo
//				med<-L3
//				men<-L2
//			FinSi
//		FinSi
//		
//		si L2>L1 y L2>L3
//			may<-L2
//			si L1>L3
//				med<-L1
//				men<-L3
//			SiNo
//				med<-L3
//				men<-L1
//			FinSi
//		FinSi
//		
//		si L3>L2 y L3>L1
//			may<-L3
//			si L1>L2
//				med<-L1
//				men<-L2
//			SiNo
//				med<-L2
//				men<-L1
//			FinSi
//		FinSi
//		
//		Si (med+men>may) Entonces
//			Si L1<>L2 y L2<>L3 Entonces
//				Mostrar "El triangulo es un Escaleno, todos sus lados son diferentes"
//			SiNo
//				Si (L1==L2) y (L2==L3)
//					Mostrar "El triangulo es un Equilatero, todos sus lados son iguales"
//				SiNo
//					Mostrar "El triangulo es un Isoceles, dos de sus lados son iguales"
//				Fin Si
//				
//			Fin Si
//		SiNo
//			Escribir "Para que un triángulo sea válido, la suma de dos lados más pequeños deben ser mayor al lado más grande"
//		Fin Si
//	SiNo
//		Escribir "Para que un triangulo sea válido, todos sus lados deben ser positivos"
//	Fin Si
//FinAlgoritmo
//
//
//Algoritmo Ejercicio_2
//	Definir dia, mes, año Como Entero
//	Definir nombre Como Caracter
//	i<-0
//	Escribir "Ingrese una fecha en el formato DDMMYYY"
//	Leer dia
//	Leer mes
//	Leer año
//	
//	Si dia>0 y mes>0 y año>=0 Entonces
//		Si mes==1 o mes==3 o mes==5 o mes==7 o mes==8 o mes==10 o mes==12 y mes>1 y mes>12 Entonces
//			Si dia>31 Entonces
//				Mostrar "El dia no es valido"
//				i<-1
//			Fin Si
//		SiNo
//			Si mes==4 o mes==6 o mes==9 o mes==11 Entonces
//				Si dia>30 Entonces
//					i<-1
//				Fin Si
//			SiNo
//				Si mes==2 o año%4==0 Entonces
//					Si dia>29 Entonces
//						i<-1
//					SiNo
//						si dia>28 y año%4<>0 Entonces
//							i<-1
//						FinSi
//					Fin Si
//				SiNo
//					i<-1
//				FinSi
//			FinSi
//			si i==1
//				Mostrar "El dia no es valido"
//			FinSi
//		FinSi
//		
//		Segun mes Hacer
//			1:
//				nombre<-'Enero'
//			2:
//				nombre<-'Febrero'
//			3:
//				nombre<-'Marzo'
//			4:
//				nombre<-'Abril'
//			5:
//				nombre<-'Mayo'
//			6:
//				nombre<-'Junio'
//			7:
//				nombre<-'Julio'
//			8:
//				nombre<-'Agosto'
//			9:
//				nombre<-'Septiembre'
//			10:
//				nombre<-'Octubre'
//			11:
//				nombre<-'Noviembre'
//			12:
//				nombre<-'Diciembre'
//			De Otro Modo:
//				Mostrar "El mes solo puede ser del 1 al 12"
//				i<-1
//		FinSegun
//		
//		Si año>=100 Entonces
//			Mostrar "El año no puede ser mayor a 99"
//			i<-1
//		Fin Si
//		
//	SiNo
//		Mostrar "Ni el día, ni el mes, ni el año pueden ser negativos"
//		i<-1
//	Fin Si
//	
//	Si i=0
//		Mostrar "Fecha: " dia " de " nombre " del " año+2000
//	FinSi
//
//FinAlgoritmo
//
//Algoritmo Ejercicio_3
//	Definir interruptor1, interruptor2, interruptor3 Como Entero
//	interruptor1<-azar(2)
//	interruptor2<-azar(2)
//	interruptor3<-azar(2)
//	Si interruptor1==1 y interruptor2==1 y interruptor3==1 Entonces
//		Mostrar "Prendió"
//	SiNo
//		Mostrar ". . ."
//	Fin Si
//FinAlgoritmo