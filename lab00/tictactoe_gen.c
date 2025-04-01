#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char **board, int board_size)
{
    int cell = 0;

    print_sep(board_size);
    for (int row = 0; row < board_size; ++row) {
        for (int column = 0; column < board_size; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(board_size);
    }
}

char get_winner(char board[][], int board_size){

    char winner = '-';
    bool hay_ganador = false;

    //algoritmo que corrobora si hay ganador en las filas
    for (int i = 0; i < board_size; i++){
        for (int j = 0; j < board_size; j++)
        {
            * 
        }        
    }

    //algoritmo que corrobora si hay ganador en las columnas
    if (winner == '-'){
        for (int j = 0; j < board_size; j++){
        }
    }

    //algoritmo que corrobora si hay ganador en las diagonales
    
    if (winner == '-'){    
    }

    if (winner == '-'){
    }

    return winner;
}

bool has_free_cell(char **board, int board_size)
{
    bool free_cell = false;
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            if(board[i][j] == '-'){
                free_cell = true;
            }
        }
    }
    
    return free_cell;
}


int main(void)
{
    printf("Tateti Completito\n");
    
    printf("\n");

    printf("Ingrese el tamaño del tablero:\n");
    int board_size;
    scanf("%d", &board_size);

    int board[board_size][board_size];

    //asignación base del tablero.
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            board[i][j] = '-';
        }
        
    }

    //Impresión del tablero
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board, board_size)) {
        print_board(board, board_size);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / board_size;
            int column = cell % board_size;
            if (board[row][column] == '-') {
                board[row][column] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board, board_size);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board, board_size);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
