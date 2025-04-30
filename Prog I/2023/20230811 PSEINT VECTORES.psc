//hace un codigo que permita 9 caracteres, la compu debe invertirlo sin array o auxiliar
//y mostrarlo
//INMINENTE ETNENIMNNI
//Algoritmo Ejercicio_6
//	Dimension Hunger(5)
//	Definir max, pos Como Entero
//	Definir Hunger, aux como caracter
//	max<-5
//	pos<-max
//	Hunger(1)<-'a'
//	Hunger(2)<-'b'
//	Hunger(3)<-'c'
//	Hunger(4)<-'d'
//	Hunger(5)<-'e'
//	Para i<-1 Hasta max/2
//		aux<-Hunger(i)
//		hunger(i)=hunger(pos)
//		Hunger(pos)=aux
//		pos<-pos-1
//	Fin Para
//	Para i<-1 Hasta 5
//		Mostrar Hunger(i)
//	Fin Para
//FinAlgoritmo
//
//9 Caracteres, debe poner cada caracter 1 a la derecha sin array o aux
//INMINENTE EINMINENT
//Algoritmo Ejercicio_7
//	Definir max Como Entero
//	Definir Hunger, aux como caracter
//	max<-9
//	Dimension Hunger(max)
//	Hunger(1)<-'i'
//	Hunger(2)<-'n'
//	Hunger(3)<-'m'
//	Hunger(4)<-'i'
//	Hunger(5)<-'n'
//	Hunger(6)<-'e'
//	Hunger(7)<-'n'
//	Hunger(8)<-'t'
//	Hunger(9)<-'e'
//	
//	letra<-Hunger(max)
//	
//	Para i<-max Hasta 2 Con Paso -1
//		Si i<>max Entonces
//			aux<-Hunger(i)
//			Hunger(i)<-Hunger(i-1)
//		SiNo
//			Hunger(1)<-letra
//		Fin Si
//	Fin Para
//	Para i<-1 Hasta max
//		Mostrar Sin Saltar Hunger(i)
//	Fin Para
//FinAlgoritmo