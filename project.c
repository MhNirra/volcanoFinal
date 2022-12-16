#include <stdio.h>
#include <stdlib.h>

int width = 100;
int height = 100;


void fillArray(int Array[width][height], int inRow, int inColumn){ //FUNCION PARA CREAR LA MATRIZ Y PEDIRLE AL USUARIO QUE INGRESE LOS VALORES DE LA MISMA.


	int i, j; //VARIABLES PARA ALMACENAR
	printf("%i%i%i%i", width, height, inRow, inColumn);
	//CICLO FOR PARA CREAR LA MATRIZ
	for(i = 0 ; i < inRow ; i++){
		for(j = 0 ; j < inColumn ; j++){
			printf("Ingrese la altura de la zona[%i][%i]: ", i, j);
			scanf("%d", &Array[i][j]);
		}
	}
}

/* void timeOut(){ //Creo una funcion para poder limpiar la consola y el programa se vea de mejor forma. */
/* 	sleep(1); */
/* 	system("cls"); */
/* } */

void printArray(int Array[width][height], int inRow, int inColumn){ //FUNCION PARA IMPRIMIR LA MATRIZ DESPUES DE CREARLA.

	int i, j;
	printf("\nNuestro zona queda de la siguiente manera: \n");

	//CICLO FOR PARA RECORRER LA COLUMNA Y MOSTRARLE AL USUARIO EL NUMERO DE COLUMNAS DE SU MATRIZ.
	for(j = 0 ; j < inColumn ; j++){
		printf("\tCol%i", j);

	}
	printf("\n");
	//Ciclo for para recorrer la matriz y mostrarla.
	for(i = 0 ; i < inRow ; i++){
		for(j = 0 ; j < inColumn ; j++){
			printf("\t[%i]  ", Array[i][j]);
		}
		printf("Fil %i", i);
		printf("\n");
	}

}

void calcLava(int Array[width][height], int row, int column){

	int center = Array[row][column];

    int l = row - 1;
    int r = row + 1;

    int t = column - 1;
    int b = column + 1;

	if (l >= 0 && center > Array[l][column]) {
		calcLava(Array, l, column);
		Array[l][column] = 0;
	}
    
    if (r < width && center > Array[r][column]) {
		calcLava(Array, r, column);
		Array[r][column] = 0;
	}

	if (t >= 0 && center > Array[row][t]) {
		calcLava(Array, row, t);
		Array[row][t] = 0;
	}

	if (b < height && center > Array[row][b]) {
		calcLava(Array, row, b);
		Array[row][b] = 0;
	}

    Array[row][column] = 0;

    return;
}

void volcano(int Array[width][height], int inRow, int inColumn){//Funcion para que el usuario seleccione donde quiere que explote el volcan.

	int i, j;
	int row, column; //VARIABLE PARA ALMACENAR LAS COORDENADAS DONDE QUIERE QUE EXPLOTE
	printf("============================================================");
	printf("\nDonde quiere que explote el volcan: ");
	printf("\nFila: ");
	scanf("%i", &row);

	printf("Columna: ");
	scanf("%i", &column);

	printf("El volcan explotara en el punto: [%i][%i], altura %i", row, column, Array[row][column]);
	printf("\n============================================================\n");

	calcLava(Array, row, column);

	printf("\n\tNuestro terreno quedara de la siguiente manera\n");
	printf("\n");

	for(i = 0 ; i < inRow ; i++){
		for(j = 0 ; j < inColumn ; j++){
	 		printf("\t[%i]", Array[i][j]);
	 	}
		printf("\n");
	}
	printf("============================================================\n");
}


int main() {

	int saveValor, row, column;
	int Array[width][height];
	int inRow, inColumn; //VARIABLES PARA ALMACENAR EL ALTO Y ANCHO DE LA MATRIZ.

	//le pido al usuario el alto y ancho de su matriz.
	do{
		printf("Ingrese de cuanto de largo quiere que sea el terreo: ");
		scanf("%i", &inRow);
	}while(inRow <= 0 || inRow == 1);

	do{
		printf("Ingrese de cuanto de alto quiere que sea el terreno: ");
		scanf("%i", &inColumn);
	}while(inColumn <= 0 || inColumn == 1);

	fillArray(Array, inRow, inColumn);
	//timeOut();

	printArray(Array, inRow, inColumn);
	volcano(Array, inRow, inColumn);
	//calcLava(Array, row, column);

}
