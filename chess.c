#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo { //Estructura para representar las celdas en el tablero
    char tipo; //Tipo de pieza (P, A, C, T, Q, K o '.')
    struct Nodo *norte, *sur, *este, *oeste; //Apuntadores a las casillas
} Nodo;

typedef struct stack_node { //Estructura para representar un nodo en el stack
    char info[10]; //información sobre la posición
    int valor; //valor de la pieza capturada 
    struct stack_node *next; //apuntador a siguiente nodo en la pila
}stack_node;

//Función para crear un nodo de pila con información y valor 
stack_node* crearstack_node(char info[], int valor) {
    stack_node* nuevoStackNode = (stack_node*)malloc(sizeof(stack_node));
    strcpy(nuevoStackNode->info, info); //copia la información de la posición
    nuevoStackNode->valor = valor; //asigna el valor
    nuevoStackNode->next = NULL; //se inicializa el siguiente como NULL
    return nuevoStackNode;
}
// Función para insertar en la pila en orden de valor
void push(stack_node** top, char posicion[], int valor) {
    stack_node* nuevoNodo = crearstack_node(posicion, valor);
    //si la pila está vacía o el valor es mayor o igual que el del nodo superior
    if (*top == NULL || (*top)->valor <= valor) {
        nuevoNodo->next = *top; //el nuevo nodo apunta al actual hasta arriba
        *top = nuevoNodo; //el nuevo nodo se convierte en el de hasta arriba del stack
    } else {
        //busca donde debe insertarlo por orden
        stack_node* current = *top;
        while (current->next != NULL && current->next->valor > valor) {
            current = current->next;
        }
        nuevoNodo->next = current->next; //inserta el nodo en su lugar de acuerdo al orden
        current->next = nuevoNodo;
    }
}
// Muestra los elementos actuales del stack
void display(stack_node* stack_top) 
{
  stack_node * nptr = stack_top;
  
  if (nptr == NULL)
  {
      printf("\nStack vacío...sin movimientos\n");
      return;
  }
  
  printf("Movimientos válidos:\n");
  int cont = 1;
  while (nptr != NULL)
  {
    printf(" %d : %s\n", cont++, nptr->info); //imprime cada nodo
    nptr = nptr->next;
  }
  
}
//Crear un nodo nuevo en el tablero 
Nodo* crearNodo(char tipo) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->tipo = tipo;
    //inicializa todos los punteros de dirección como NULL
    nuevoNodo->norte = nuevoNodo->sur = nuevoNodo->este = nuevoNodo->oeste = NULL;
    return nuevoNodo;
}
//Imprime el tablero 
void imprimirTablero(Nodo *tablero[8][8]) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i); //imprime el numero de fila
        for (int j = 0; j < 8; j++) {
            printf("%c ", tablero[i][j]->tipo);//imprime el tipo de cada pieza
        }
        printf("%d\n", 8 - i);
    }
    printf("  A B C D E F G H\n");
}
//Función para leer el archivo que contiene el tablero con las piezas
void leerArchivo(char *nombreArchivo, Nodo *tablero[8][8], int *fila, int *columna){
    //Ruta de donde se encuentra el archivo sin el nombre del archivo (CAMBIAR).
    char path[] = "C:\\Users\\hp\\OneDrive\\Documentos\\Ale\\ITESO stuff\\3er semestre\\DED\\DED--Ale\\";
    char * ptr;
    ptr = strcat( path, nombreArchivo );//Concatenar la ruta con el nombre del archivo
    FILE *archivo = fopen(path, "r");//abre el archivo en modo de lectura
    if(archivo == NULL){
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    //Leer cada línea del archivo y crear el tablero
    char linea[20];
    for(int i=0; i<8; i++){
        fgets(linea, sizeof(linea), archivo); //lee una línea del archivo
        for(int j=0; j<8; j++){
             tablero[i][j] = crearNodo(linea[j * 2]);//Crea nodo con la pieza
        }
    }
    //Lee la posición(coordenada) de la pieza protagonista
    fgets(linea, sizeof(linea), archivo);
    *fila = 8 - (linea[1] - '0'); //convierte la fila del archivo a índice del tablero
    *columna = linea[0] - 'A'; //convierte la columna a índice
    fclose(archivo); //cierra el archivo
}
//Se obtiene el valor de la pieza según el tipo de pieza que sea
int obtenerValorPieza(char tipo) {
    switch (tipo) {
        case 'P': return 1;
        case 'A': return 3;
        case 'C': return 3;
        case 'T': return 5;
        case 'Q': return 8;
        case 'K': return 10;
        case '.': return 0;
        default: return 0;
    }
}
//Calcula los movimientos válidos de la torre y los almacena en el stack
void movimientos(Nodo *tablero[8][8], int fila, int columna, stack_node** stack_top) {
    printf("--------Movimientos válidos:--------\n");

    //Movimientos hacia el oeste
    for (int j = columna - 1; j >= 0; j--) {
        if (tablero[fila][j]->tipo != '.') {
            int obtenerValor = obtenerValorPieza(tablero[fila][j]->tipo);
            printf("%c%d - %d, ", 'A' + j, 8 - fila, obtenerValor);
            char valor[10];
            sprintf(valor, "%c%d - %d", 'A' + j, 8 - fila, obtenerValor);
            push(stack_top, valor, obtenerValor); //inserta en stack si hay una pieza
            break;
        }
        printf("%c%d - 0, ", 'A' + j, 8 - fila);
    }

    //Movimientos hacia el norte
    for (int i = fila - 1; i >= 0; i--) {
        if (tablero[i][columna]->tipo != '.') {
            //printf("%c%d - %d, ", 'A' + columna, 8 - i, obtenerValorPieza(tablero[i][columna]->tipo));
            int obtenerValor = obtenerValorPieza(tablero[i][columna]->tipo);
            printf("%c%d - %d, ", 'A' + i, 8 - fila, obtenerValor);
            char valor[10];
            sprintf(valor, "%c%d - %d", 'A' + i, 8 - fila, obtenerValor);
            push(stack_top, valor, obtenerValor); //inserta en stack si hay una pieza
            break;
        }
        printf("%c%d - 0, ", 'A' + columna, 8 - i);
    }

    //Movimientos hacia el este
    for (int j = columna + 1; j < 8; j++) {
        if (tablero[fila][j]->tipo != '.') {
            //printf("%c%d - %d, ", 'A' + j, 8 - fila, obtenerValorPieza(tablero[fila][j]->tipo));
            int obtenerValor = obtenerValorPieza(tablero[fila][j]->tipo);
            printf("%c%d - %d, ", 'A' + j, 8 - fila, obtenerValor);
            char valor[10];
            sprintf(valor, "%c%d - %d", 'A' + j, 8 - fila, obtenerValor);
            push(stack_top, valor, obtenerValor); //inserta en stack si hay una pieza
            break;
        }
        printf("%c%d - 0, ", 'A' + j, 8 - fila);
    }

    //Movimientos hacia el sur
    for (int i = fila + 1; i < 8; i++) {
        if (tablero[i][columna]->tipo != '.') {
            //printf("%c%d - %d, ", 'A' + columna, 8 - i, obtenerValorPieza(tablero[i][columna]->tipo));
            int obtenerValor = obtenerValorPieza(tablero[i][columna]->tipo);
            printf("%c%d - %d, ", 'A' + i, 8 - fila, obtenerValor);
            char valor[10];
            sprintf(valor, "%c%d - %d", 'A' + i, 8 - fila, obtenerValor);
            push(stack_top, valor, obtenerValor); //inserta en stack si hay una pieza
            break;
        }
        printf("%c%d - 0, ", 'A' + columna, 8 - i);
    }

    printf("\n");
}
//Libera la memoria del stack
void freeStack(stack_node* stack_top) {
    stack_node* temp;
    while (stack_top != NULL) {
        temp = stack_top;
        stack_top = stack_top->next;
        free(temp);
    }
}

int main() {
    Nodo *tablero[8][8];
    //Se inicializa el tablero con nodos vacíos
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tablero[i][j] = crearNodo('.');
        }
    }

    // Conectar los nodos con los adyacentes
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i > 0) tablero[i][j]->norte = tablero[i-1][j];
            if (i < 7) tablero[i][j]->sur = tablero[i+1][j];
            if (j > 0) tablero[i][j]->oeste = tablero[i][j-1];
            if (j < 7) tablero[i][j]->este = tablero[i][j+1];
        }
    }

    int fila, columna; //posición de pieza protagonista
    char nombreArchivo[200];
    printf("Ingrese el nombre del archivo de entrada: ");
    scanf("%s", nombreArchivo);

    //Se llama a la función leerArchivo con el nombre del archivo ingresado por el usuario
    leerArchivo(nombreArchivo, tablero, &fila, &columna);
    
    // Imprimir el tablero con las piezas del archivo ya leído
    printf("--------Tablero--------\n");
    imprimirTablero(tablero);
    printf("%c%d\n", 'A' + columna, 8 - fila);//imprime la posición de la pieza protagonista
   
    //Se llama a la función movimientos para obtener los movimientos que puede hacer la torre
    stack_node *stack_top = NULL;
    movimientos(tablero, fila, columna, &stack_top);
    printf("--------Stack con movimientos válidos--------\n");
    //se imprime el stack con los movimientos válidos ordenados
    display(stack_top);
    printf("\n");

    // Liberar el tablero
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            free(tablero[i][j]);
        }
    }
    //liberar  el stack
    freeStack(stack_top);

    return 0;
}