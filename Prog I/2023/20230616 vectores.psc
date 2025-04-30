//Cargar un vector 5 elementos de forma aleatoria y mostrarlo y calcular su suma
//Algoritmo Ejercicio1
//	Definir vector, suma Como Entero
//	Dimension vector(5)
//	
//	Para i<-1 Hasta 5
//		vector(i) <- 0
//	Fin Para
//	
//	Para i<-1 Hasta 5
//		vector(i) <- Aleatorio(-50,50)
//		suma=suma+vector(i)
//		Mostrar "Vector: " vector(i)
//		Mostrar "Suma: " suma
//	Fin Para
//	Mostrar ""
//	Mostrar "Total Final " suma
//	
//FinAlgoritmo

//Cargar un vector 20 elementos y sumar solo los pares
//Algoritmo Ejercicio2
//	Definir vector, suma Como Entero
//	Dimension vector(20)
//	
//	Para i<-1 Hasta 20
//		vector(i) <- 0
//	Fin Para
//	
//	Para i<-1 Hasta 20
//		vector(i) <- Aleatorio(-50,50)
//		Si vector(i)%2 =0 Entonces
//			suma=suma+vector(i)
//			Mostrar "Vector par: " vector(i)
//			Mostrar "Suma: " suma
//		SiNo
//			Mostrar "Vector impar: " vector(i)
//		Fin Si
//	Fin Para
//	Mostrar ""
//	Mostrar "Total Final " suma
//FinAlgoritmo

//Cargar un vector con 100 numeros al azar e indicar porcentaje de numeros positivos,
//negativos y 0
//Algoritmo Ejercicio3
//	Definir vector, suma, total, ceros, positivos, negativos Como Entero
//	Dimension vector(100)
//	
//	Para i<-1 Hasta 100
//		vector(i) <- 0
//	Fin Para
//	
//	Para i<-1 Hasta 100
//		vector(i) <- Aleatorio(-50,50)
//		Si vector(i)=0 Entonces
//			ceros=ceros+1
//		SiNo
//			Si vector(i)>0 Entonces
//				positivos=positivos+1
//			SiNo
//				negativos=negativos+1
//			Fin Si
//		Fin Si
//		total=total+1
//	Fin Para
//	Mostrar ""
//	Mostrar "Positivos: " positivos*total/100 "%"
//	Mostrar "Negativos: " negativos*total/100 "%"
//	Mostrar "Ceros:     " ceros*total/100 "%"
//FinAlgoritmo