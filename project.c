#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //INCLUYO ESTA LIBRERIA PARA PODER HACER UN TIMEOUT ENTRE FUNCIONES.

// VARIABLES INCIALES GLOBALES, NO NECESITAN SER INGRESADAS COMO PARAMETROS DENTRO DE LA FUNCION, SOLO SE UTILIZAN.
int width = 100;
int height = 100;

void fillArray(int Array[width][height], int inRow, int inColumn){ //FUNCION PARA CREAR LA MATRIZ Y PEDIRLE AL USUARIO QUE INGRESE LOS VALORES DE LA MISMA.

	int i, j; //VARIABLES PARA ALMACENAR
	//CICLO FOR PARA CREAR LA MATRIZ
	for(i = 0 ; i < inRow ; i++){
		for(j = 0 ; j < inColumn ; j++){
			do{//CICLO PARA QUE SI EL USUARIO INGRESA UN NUMERO MENOR O IGUAL A 0 O 1 SE REPEITA.
			printf("Ingrese la altura de la zona[%i][%i]: ", i, j);
			scanf("%d", &Array[i][j]);
			}while(Array[i][j] <= 0 || Array[i][j] == 1);
		}
	}
}

//FUNCION HECHA PARA PODER PODER HACER PAUSAS Y LIMPIAR LA CONSOLA ENTRE FUNCIONES Y NO SE VEA TAN "RUSTICO"
void timeOutCls(){
	usleep(500000); //HAGO EL TIMEOUT
	system("cls"); //BORRO LA CONSOLA PARA PODER TENER UNA CONSOLA MAS LIMPIA
}

void printArray(int Array[width][height], int inRow, int inColumn){ //FUNCION PARA IMPRIMIR LA MATRIZ DESPUES DE CREARLA.

	int i, j;
	printf("\033[0;33m"); //COLOREO DE AMARILLO
	printf("==============================Z-O-N-A==============================\n\n");
	printf("\033[0m");//VUELVO AL COLOR BLANCO
	//CICLO FOR PARA RECORRER LA COLUMNA Y MOSTRARLE AL USUARIO EL NUMERO DE COLUMNAS DE SU MATRIZ.
	printf("\033[0;31m");
	for(j = 0 ; j < inColumn ; j++){
		printf("\tCol%i", j); //MUESTRO POR PANTALLA EL NUMERO DE COLUMNAS QUE EXISTEN POR ENCIMA DE LA MATRIZ.
	}
	printf("\033[0m");
	printf("\n");
	//Ciclo for para recorrer la matriz y mostrarla.
	for(i = 0 ; i < inRow ; i++){
		for(j = 0 ; j < inColumn ; j++){
			printf("\t[%i]  ", Array[i][j]); //MUESTRO LA MATRIZ
		}
		printf("\033[0;31m");
		printf("Fil %i", i); //MUESTRO POR PANTALLA PANTALLA EL NUMERO DE FILAS POR UN BORDE DE LA MATRIZ.
		printf("\033[m");
		printf("\n");
	}
	printf("\033[0;32m");
	//printf("==============================Z-O-N-A==============================\n\n\n");
	printf("\033[0m");
}

//FUNCION PARA CAMBIAR LOS VALORES DE LA MATRIZ AL EXPLTOAR EL VOLCAN.
void calcLava(int Array[width][height], int row, int column){

	int i, j;
	int center = Array[row][column]; //DEFINO LA VARIABLE CENTER CON LOS VALORES DE LA MATRIZ, ESTO PARA NO FACILITAR ESCRITURA DE CODIGO.

	//VARIABLES PARA RECORRER LA MATRIZ Y SACAR LOS VALORES, TAMBIEN PARA FACILITAR ESCRITURA DE CODIGO.
	//CON LAS VARIABLES l Y r RECORREMOS LAS FILAS DE ABAJO HACIA ARRIBA
    int l = row - 1; 
    int r = row + 1;

	//CON LAS VARIABLES y Y b RECORRES LAS COLUMNAS DE IZQUIERDA A DERECHA.
    int t = column - 1;
    int b = column + 1;

	//CONDICIONES PARA VER SI EN LA MATRIZ EL NUMERO DE ARRIBA, ABAJO, IZQUIERDA O DERECHA ES MENOR AL DEL CENTRO SEA CAMBIADO POR UN 0, ESTI SIGUE SUCESIVAMENTE HASTA RECORRER TODOS LOS PUNTOS DE LA MATRIZ.
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

}

// CON ESTA FUNCION HAREMOS QUE EL USUARIO INGRESE EL SECTOR DONDE QUIERE QUE EXPLOTE Y A LA VEZ LO MOSTRAREMOS POR PANTALLA LOS CAMBIOS REALIZADOS EN LA MATRIZ.
void volcano(int Array[width][height], int inRow, int inColumn){

	int i, j;
	int row, column; //VARIABLE PARA ALMACENAR LAS COORDENADAS DONDE QUIERE QUE EXPLOTE
	printf("\033[0;33m");
	printf("\n=========================E-X-P-L-O-S-I-O-N=========================");
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
	printf("\033[0;31m");
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
		printf("\033[0;31m");
		printf("\tFil%i", i);//MUESTRO POR PANTALLA LA CANTIDAD DE FILAS POR EL BORDE AL FINAL DE LA MATRIZ.
		printf("\033[0m");
		printf("\n");
	}
	printf("\033[0;33m");
	printf("\n=========================E-X-P-L-O-S-I-O-N=========================\n");
}

int main() {

	int saveValor, row, column;
	int Array[width][height];
	int inRow, inColumn; //VARIABLES PARA ALMACENAR EL ALTO Y ANCHO DE LA MATRIZ.

	printf("\033[0;33m"); //PINTO LOS MENSAJES POR PANTALLA DE COLOR AMARILLO
	//LE PIDO AL USUARIO EL ALTO Y ANCHO DE LA MATRIZ.
	//BUCLE PARA QUE EL USARIO NO INGRESE UN NUMERO MENOR O IGUAL A 1.
	do{
		printf("Ingrese de cuanto de largo quiere que sea el terreo: ");
		scanf("%i", &inRow);
	}while(inRow <= 0 || inRow == 1);

	//BUCLE PAA QUE EL USUARIO NO INGRESE UN NUMERO MENOR O IGUAL A 1.
	do{
		printf("Ingrese de cuanto de alto quiere que sea el terreno: ");
		scanf("%i", &inColumn);
	}while(inColumn <= 0 || inColumn == 1);
	
	timeOutCls();//LLAMO A LA FUNCION TIMEOUT
	printf("=====================================I-N-F-O=====================================\n");
	printf("\tSu terreno se ha establecido con un alto de %i y con un ancho de %i", inColumn, inRow);
	printf("\n=====================================I-N-F-O=====================================\n");
	printf("\033[0m"); //VUELVO A COLOR BLANCO
	usleep(500000);
	fillArray(Array, inRow, inColumn);//LLAMO A LA FUNCION fillArray
	timeOutCls();//LLAMO A LA FUNCION timeOut
	printArray(Array, inRow, inColumn);//LLAMO A LA FUNCION printArray
	volcano(Array, inRow, inColumn);//LLAMO A LA FUNCION volcano
}