#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

//COLOR
#define BLACK 66 //B
#define WHITE 87 //W
#define BALCK_PRINT 2 //RED - BLACK
#define WHITE_PRINT 7 //WHITE - YELLOW
#define BACKGROUND 0; // BLACK


//TYPE
#define BOARD_EDGE 88 // X
#define EMPTY_SQUARE 0

//PIECES
#define ROOK 35 //#
#define KNIGHT 52 //4
#define BISHOP 65 //A
#define PAWN 80 //P
#define QUEEN 38 //&
#define KING 75 //K


typedef int position_piece[2];

typedef struct chess_piece{
    char color;
    char color_print;
    char type;
    position_piece actual_position;
    position_piece previous_position;
    position_piece next_position;
}piece;

piece createPiece(int, int, char, char, char);


piece createPiece(int i, int j, char piece_type, char piece_color, char color_print) {
    piece new_piece;
    new_piece.type = piece_type;
    new_piece.color = piece_color;
    new_piece.color_print = color_print;
    new_piece.actual_position[0] = i;
    new_piece.actual_position[1] = j;
    new_piece.previous_position[0] = i;
    new_piece.previous_position[1] = j;
    new_piece.next_position[0] = 0;
    new_piece.next_position[1] = 0;

    return new_piece;
}



