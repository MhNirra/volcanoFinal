# Se viene la lava
## _Realizado en el lenguaje de programación C_

![C](https://emiliopm.com/wp-content/uploads/2018/10/cursoCIntermedio.png)

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

## Desarrolladores

>Este proyecto fue realizado por
> Matias Neira Henriquez
> Bastian Carrillo Rebolledo
> Benjamin Pastor Huentemil

## Descripción del programa: 

- Un importante vulcanólogo, con objeto de estudiar las consecuencias destructoras de un volcán en una determinada área, pretende desarrollar un sistema informático que le ayude en su tarea. Para ello, nos pide que realicemos el siguiente subprograma junto con el programa necesario para realizar la prueba.
- El cual recibe un arreglo bidimensional que representa el plano de la zona a estudiar, donde cada elemento contiene un número entero que representa la altura de ese punto respecto al nivel del mar. Así mismo, recibe un punto (fila y columna) de dicho plano donde surge el cráter de un volcán. La función que Ud. implemente predecirá el recorrido que realiza la lava, y la mostrará en el arreglo bidimensional de salida (lava), donde el asterisco (‘*’) representa que la lava ha pasado por ese punto, y el espacio en blanco (’ ’) representa que la lava no ha pasado por dicho punto. El flujo de lava se desplaza según el siguiente esquema a partir del cráter:
- Desde un determinado punto, siempre se mueve hacia los puntos circundantes que se encuentran a menor altura. Los puntos circundantes de uno dado serán el superior, inferior, izquierdo y derecho (no se considerarán los diagonales). Así sucesivamente se repite el proceso para todos los puntos donde haya alcanzado el flujo de lava.

## Herramientas utilizadas: 

- Como editor de texto  [Visual Studio Code]
- Para realizar consultas con otros programadores  [Stack OverFlow]
- Para comunicarnos como grupo [Discord]
- Compartir el código entre nosotros [GitHub]

> Este programa fue desarrollado a través
> de programas y sitios que casi
> todo programador conoce.
> Nuestro mejor entorno para el desarrollo del código
> fue Visual Studio Code, StackOverflow para las
> consultas, discord para comunicarnos entre el grupo y
> GitHub para guardar el código y que todos trabajaramos en él

## Objetivos
Como principal objetivo era realizar un cambio de valores
dentro de la matriz generada por el usuario, estos cambios serian a numeros
menores el cual el usuario desee iniciar.

## Dificultades
La principal dificultad en nuestro proyecto no fue la realización del código, sino
que fue entender el programa, ya que como grupo entendimos algo totalmente distinto a lo
que se debía realizar.
En cuanto a código no tuvimos mayor dificultad, logramos realizar el proyecto en un buen tiempo y con una buena
lógica incorporada.
## Funciones

>Al momento de programar almacenamos todo en distintas 
>Funciones, las cuales cada una tenian una instrucción
>Diferente y las llamabamos al momento de usarlas.
>A continuación estarán las funciones utilizadas.

Cada función recibía distintos parametros los cuales eran declarados en el main-

fillArray(Array, inRow, inColumn);
```sh
	//CICLO FOR PARA CREAR LA MATRIZ
	for(i = 0 ; i < inRow ; i++){
		for(j = 0 ; j < inColumn ; j++){
			do{//CICLO PARA QUE SI EL USUARIO INGRESA UN NUMERO MENOR O IGUAL A 0 O 1 SE REPITA.
			printf("Ingrese la altura de la zona[%i][%i]: ", i, j);
			scanf("%d", &Array[i][j]);
			}while(Array[i][j] <= 0 || Array[i][j] == 1);
		}
	}
```
printArray(Array, inRow, inColumn);
```sh
    //RECORREMOS LA MATRIZ Y LA PRINTEAMOS
	for(i = 0 ; i < inRow ; i++){
		for(j = 0 ; j < inColumn ; j++){
			printf("\t[%i]  ", Array[i][j]); //MUESTRO LA MATRIZ
		}
		printf("\n");
	}
```
calcLava(Array, row, column);
```sh
if (l >= 0 && center > Array[l][column]) {
		calcLava(Array, l, column);
		Array[l][column] = 0; //CAMBIO EL NUMERO MENOR PORU 0 
			
	}
    
    if (r < width && center > Array[r][column]) {
		calcLava(Array, r, column);
		Array[r][column] = 0; //CAMBIO EL NUMERO MENOR POR UN 0
	}

	if (t >= 0 && center > Array[row][t]) {
		calcLava(Array, row, t);
		Array[row][t] = 0; //CAMBIO EL NUMERO MENOR POR UN 0
	}

	if (b < height && center > Array[row][b]) {
		calcLava(Array, row, b);
		Array[row][b] = 0; //CAMBIO EL NUMERO MENOR POR UN 0 
	}

    Array[row][column] = 0;
    return; //RETORNO LOS VALORES
```
volcano(Array, inRow, inColumn);
```sh
	printf("\n\n\t\tSeleccione el lugar de explosion \n\n");
	printf("Las filas son las siguientes: ");
	//CICLO FOR PARA SACAR LA CANTIDAD DE FILAS Y MOSTRARSELAS AL USUARIO.
	for(i = 0 ; i < inRow ; i++){
		printf("|%i| ", i); //MUESTRO AL USUARIO LA CANTIDAD DE FILAS QUE HAY PARA QUE PUEDA INGRESAR CUAL QUIERES. EJ: |0||1|2|3|...
	}
	printf("\nLas columnas son las siguientes: ");
	//CICLO FOR PARA SACAR LA CANTIDAD DE COLUMNAS Y MOSTRARSELAS AL USUARIO.
	for(j = 0 ; j < inColumn ; j++){
		printf("|%i| ", j); //MUESTRO AL USUARIO LA CANTIDAD DE COLUMNAS QUE HAY PARA QUE PUEDA INGRESAR CUAL QUIERE Y NO SELECCIONA UNA QUE NO EXISTA, POR EJ: |0|1|2|3|....
	}
	printf("\n");
	//EN CASO DE SELECIONAR UN VALOR QUE NO EXISTA, POR EJEMPLO SI EL NUMERO DE FILAS LLEGAS HASTA 4 Y SELECCIONA EL 5, LE VOLVERA A PEDIR AL USUARIO QUE INGRESE EL VALOR, ESTO DADO QUE NO ESTA EL VALOR QUE EL USUARIO SELECCIONO
	//BUCLE PARA QUE EL USUARIO INGRESE UNA CASILLA CORRESPONDIENTE A LAS CUALES ESTÁN DENTRO DEL PROGRAMA
	do{
		printf("Fila: ");
		scanf("%i", &row);
	}while(row > inRow - 1); //SE LE RESTA 1 PORQUE EN LAS MATRICES SE EMPIEZA A CONTAR DESDE 0

	//BUCLE PARA QUE EL USUARIO INGRESE UNA CASILLA CORRESPONDIENTE A LAS CUALES ESTÁN DENTRO DEL PROGRAMA
	do{
		printf("Columna: ");
		scanf("%i", &column);
	}while(column > inColumn - 1);//SE LE RESTA 1 PORQUE EN LAS MATRICES SE EMPIEZA A CONTAR DESDE 0
	printf("El volcan explotara en el punto: [%i][%i], altura %i", row, column, Array[row][column]);
	printf("\n\n=========================E-X-P-L-O-S-I-O-N=========================\n");
	calcLava(Array, row, column); //LLAMO A LA FUNCION DONDE CAMBIO TODOS LOS VALORES DE LA MATRIZ POR UN 0.
	printf("\n\tNuestro terreno quedara de la siguiente manera\n");
	printf("\n");
	printf("\033[0m");

	//CICLO FOR PARA RECORRER LA COLUMNA Y MOSTRARLE AL USUARIO EL NUMERO DE COLUMNAS DE SU MATRIZ.
	printf("\033[0;33m");
	for(j = 0 ; j < inColumn ; j++){
		printf("\tCol%i", j); //MUESTRO LA CANTIDAD DE COLUMNAS POR ENCIMA DE LA MATRIZ.
	}
	printf("\033[0m");
	printf("\n");
	//CICLO PARA MOSTRAR LA MATRIZ Y PARA SACAR EL NUMERO DE FILAS DE LA MISMA.
	for(i = 0 ; i < inRow ; i++){
		for(j = 0 ; j < inColumn ; j++){
	 		printf("\t[%i]", Array[i][j]); //MUESTRO LA MATRIZ POR PANTALLA
	 	}
		printf("\033[0;33m");
		printf("\tFil%i", i);//MUESTRO POR PANTALLA LA CANTIDAD DE FILAS POR EL BORDE AL FINAL DE LA MATRIZ.
		printf("\033[0m");
		printf("\n");
	}
```
## Investigación

Como todo proyecto de programación, debimos indagar y estudiar para poder realizar un código más limpio y
puro, por ende consultamos en sitios y comunidades de programadores.

| Lugares | Link |
| ------ | ------ |
| StackOverflow | [https://stackoverflow.com][PlDb] |
| GitHub | [https://github.com][PlGh] |
| Discord | [https://discord.com][PlGd] |
| W3Schools | [https://www.w3schools.com][PlOd] |
| Programiz | [https://www.programiz.com][PlMe] |
| GeeksfoGeeks | [https://www.geeksforgeeks.org][PlGa] |

## Metodología de trabajo

Como metodologia de trabajo seguimos una serie de objetivos a cumplir para llevar a cabo el proyecto.
- Lograr comprender la idea del proyecto
- Plantear distintas formas de realizar el código y elegir la más "Conveniente"
- Distribucion del trabajo
- Juntarnos 2 dias a la semana como mínino para poder ver y analizar los cambios

## Desarrolladores

>Este proyecto fue realizado por
> Matias Neira Henriquez
> Bastian Carrillo Rebolledo
> Benjamin Pastor Huentemil

## Conclusión

El proyecto nos ayudó a comprender el uso de las funciones.

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)


   [Visual Studio Code]: <https://code.visualstudio.com>
   [Stack OverFlow]: <https://stackoverflow.com>
   [Discord]: <https://discord.com>
   [GitHub]: <https://github.com>


   [PlDb]: <https://github.com/joemccann/dillinger/tree/master/plugins/dropbox/README.md>
   [PlGh]: <https://github.com/joemccann/dillinger/tree/master/plugins/github/README.md>
   [PlGd]: <https://github.com/joemccann/dillinger/tree/master/plugins/googledrive/README.md>
   [PlOd]: <https://github.com/joemccann/dillinger/tree/master/plugins/onedrive/README.md>
   [PlMe]: <https://github.com/joemccann/dillinger/tree/master/plugins/medium/README.md>
   [PlGa]: <https://github.com/RahulHP/dillinger/blob/master/plugins/googleanalytics/README.md>

