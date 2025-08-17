#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "game.h" 

void playGame(int* board, int size, int scoreToWin) { // start the game for each size of matrix(3x3 - 2x2 -4x4) and checks the next move after making sure the input is correctly handeled.
    clearboard(board, size);
    int check = 1;
    int check_Empty = 0;
    int score_value = 0;
    int best_value = 0;
    int biggest_tille = 0;
    int* biggestTile = &biggest_tille;
    int* score = &score_value;
    int* best = &best_value;

    printBoard(board, size, score, best);
    while (check) {
        if (isGameOver(board, size)) {
            printf("Game Over, Your score is:%d.\n", *score);
            break;
        }
        int flag = 0;
        char choice;
        printMenu();
        scanf(" %c", &choice);
        choice = tolower(choice);
        switch (choice) {
        case 'n':
            *score = 0;
            clearboard(board, size);
            startBoard(board, size);
            printBoard(board, size, score, best);
            break;

        case 'r':
            check_Empty = checkEmptyBoard(board, size);
            if (check_Empty) {
                check_Empty = 0;
                printf("Need to start game first\n");
                break;
            } 
            moveRight(board, size, &flag, score);
            startBoard_1(board, size, flag);
            checkBiggestTile(board, biggestTile, size);
            if (*score > *best) {
                *best = *score;
            }
            printBoard(board, size, score, best);
            if (*biggestTile == scoreToWin) {
                printf("You have reached Score to win: %d, Staring a new game.\n", scoreToWin);
                *score = 0;
                *biggestTile = 0;
                clearboard(board, size);
                startBoard(board, size);
                printBoard(board, size, score, best);
            }
            break;

        case 'l':
            check_Empty = checkEmptyBoard(board, size);
            if (check_Empty) {
                check_Empty = 0;
                printf("Need to start game first\n");
                break;
            } 
            moveLeft(board, size, &flag, score);
            startBoard_1(board, size, flag);
            checkBiggestTile(board, biggestTile, size);
            if (*score > *best) {
                *best = *score;
            }
            printBoard(board, size, score, best);
            if (*biggestTile == scoreToWin) {
                printf("You have reached Score to win: %d, Staring a new game.\n", scoreToWin);
                *score = 0;
                *biggestTile = 0;
                clearboard(board, size);
                startBoard(board, size);
                printBoard(board, size, score, best);
            }
            break;

        case 'u':
            check_Empty = checkEmptyBoard(board, size);
            if (check_Empty) {
                check_Empty = 0;
                printf("Need to start game first\n");
                break;
            } 
            moveUp(board, size, &flag, score);
            startBoard_1(board, size, flag);
            checkBiggestTile(board, biggestTile, size);
            if (*score > *best) {
                *best = *score;
            }
            printBoard(board, size, score, best);
            if (*biggestTile == scoreToWin) {
                printf("You have reached Score to win: %d, Staring a new game.\n", scoreToWin);
                *score = 0;
                *biggestTile = 0;
                clearboard(board, size);
                startBoard(board, size);
                printBoard(board, size, score, best);
            }
            break;

        case 'd':
            check_Empty = checkEmptyBoard(board, size);
            if (check_Empty) {
                check_Empty = 0;
                printf("Need to start game first\n");
                break;
            } 
            moveDown(board, size, &flag, score);
            startBoard_1(board, size, flag);
            checkBiggestTile(board, score, size);
            if (*score > *best) {
                *best = *score;
            }
            printBoard(board, size, biggestTile, best);
            if (*biggestTile == scoreToWin) {
                printf("You have reached Score to win: %d, Staring a new game.\n", scoreToWin);
                *score = 0;
                *biggestTile = 0;
                clearboard(board, size);
                startBoard(board, size);
                printBoard(board, size, score, best);
            }
            break;

        case 'e':
            printf("Ending previous game - your score %d best score %d\n", *score, *best);
            printf("Bye Bye \n");
            check = 0;
            break;

        default:
            printf("Wrong input, Please type valid input: \n");
            break;
        }

    }

}
void moveUp(int* board, int size, int* flag, int* score){ // moving  tiles up -> merges -> move result up (in the current matrix), and puts value 1 in pointer flag if the move is accured, 0 if the move does not accured.
    int moved = 0;
    for (int col = 0; col < size; col++) {
        for (int row = 1; row < size; row++) {
            if (*(board + row * size + col) != 0) {
                int targetRow = row;
                while (targetRow > 0 && *(board + (targetRow - 1) * size + col) == 0) {
                    *(board + (targetRow - 1) * size + col) = *(board + targetRow * size + col);
                    *(board + targetRow * size + col) = 0;
                    targetRow--;
                    moved = 1;
                }
            }
        }

        for (int row = 1; row < size; row++) {
            if (*(board + row * size + col) != 0 &&
                *(board + (row - 1) * size + col) == *(board + row * size + col)) {
                *(board + (row - 1) * size + col) *= 2;
                *score = *score + (*(board + (row - 1) * size + col));
                *(board + row * size + col) = 0;
                moved = 1;
                break;
            }
        }

        for (int row = 1; row < size; row++) {
            if (*(board + row * size + col) != 0) {
                int targetRow = row;
                while (targetRow > 0 && *(board + (targetRow - 1) * size + col) == 0) {
                    *(board + (targetRow - 1) * size + col) = *(board + targetRow * size + col);
                    *(board + targetRow * size + col) = 0;
                    targetRow--;
                    moved = 1;
                }
            }
        }
    }
    *flag = moved ? 1 : 0;
}



void moveDown(int* board, int size, int* flag, int* score) { // moving  tiles down -> merges -> move result down (in the current matrix), and puts value 1 in pointer flag if the move is accured, 0 if the move does not accured.
    int moved = 0;
    for (int col = 0; col < size; col++) {
        for (int row = size - 2; row >= 0; row--) {
            if (*(board + row * size + col) != 0) {
                int targetRow = row;
                while (targetRow < size - 1 && *(board + (targetRow + 1) * size + col) == 0) {
                    *(board + (targetRow + 1) * size + col) = *(board + targetRow * size + col);
                    *(board + targetRow * size + col) = 0;
                    targetRow++;
                    moved = 1;
                }
            }
        }


        for (int row = size - 2; row >= 0; row--) {
            if (*(board + row * size + col) != 0 &&
                *(board + (row + 1) * size + col) == *(board + row * size + col)) {
                *(board + (row + 1) * size + col) *= 2;
                *score = *score + (*(board + (row + 1) * size + col));
                *(board + row * size + col) = 0;
                moved = 1;
                break;
            }
        }

        for (int row = size - 2; row >= 0; row--) {
            if (*(board + row * size + col) != 0) {
                int targetRow = row;
                while (targetRow < size - 1 && *(board + (targetRow + 1) * size + col) == 0) {
                    *(board + (targetRow + 1) * size + col) = *(board + targetRow * size + col);
                    *(board + targetRow * size + col) = 0;
                    targetRow++;
                    moved = 1;
                }
            }
        }
    }
    *flag = moved ? 1 : 0;
}







void moveRight(int* board, int size, int* flag, int* score) { // moving  tiles right -> merges -> move result right (in the current matrix), and puts value 1 in pointer flag if the move is accured, 0 if the move does not accured.
    int moved = 0;
    for (int row = 0; row < size; row++) {
        for (int col = size - 2; col >= 0; col--) {
            if (*(board + row * size + col) != 0) {
                int targetCol = col;
                while (targetCol < size - 1 && *(board + row * size + targetCol + 1) == 0) {
                    *(board + row * size + targetCol + 1) = *(board + row * size + targetCol);
                    *(board + row * size + targetCol) = 0;
                    targetCol++;
                    moved = 1;
                }
            }
        }
        for (int col = size - 2; col >= 0; col--) {
            if (*(board + row * size + col) != 0 &&
                *(board + row * size + col + 1) == *(board + row * size + col)) {
                *(board + row * size + col + 1) *= 2;
                *score = *score + (*(board + row * size + col + 1));
                *(board + row * size + col) = 0;
                moved = 1;
                break;
            }
        }

        for (int col = size - 2; col >= 0; col--) {
            if (*(board + row * size + col) != 0) {
                int targetCol = col;
                while (targetCol < size - 1 && *(board + row * size + targetCol + 1) == 0) {
                    *(board + row * size + targetCol + 1) = *(board + row * size + targetCol);
                    *(board + row * size + targetCol) = 0;
                    targetCol++;
                    moved = 1;
                }
            }
        }
    }
    *flag = moved ? 1 : 0;
}






void moveLeft(int* board, int size, int* flag, int* score) { // moving  tiles left -> merges -> move result left (in the current matrix), and puts value 1 in pointer flag if the move is accured, 0 if the move does not accured.
    int moved = 0;
    for (int row = 0; row < size; row++) {
        for (int col = 1; col < size; col++) {
            if (*(board + row * size + col) != 0) {
                int targetCol = col;
                while (targetCol > 0 && *(board + row * size + targetCol - 1) == 0) {
                    *(board + row * size + targetCol - 1) = *(board + row * size + targetCol);
                    *(board + row * size + targetCol) = 0;
                    targetCol--;
                    moved = 1;
                }
            }
        }

        for (int col = 1; col < size; col++) {
            if (*(board + row * size + col) != 0 &&
                *(board + row * size + col - 1) == *(board + row * size + col)) {
                *(board + row * size + col - 1) *= 2;
                *score = *score + *(board + row * size + col - 1);
                *(board + row * size + col) = 0;
                moved = 1;
                break;
            }
        }

        for (int col = 1; col < size; col++) {
            if (*(board + row * size + col) != 0) {
                int targetCol = col;
                while (targetCol > 0 && *(board + row * size + targetCol - 1) == 0) {
                    *(board + row * size + targetCol - 1) = *(board + row * size + targetCol);
                    *(board + row * size + targetCol) = 0;
                    targetCol--;
                    moved = 1;
                }
            }
        }
    }
    *flag = moved ? 1 : 0;
}

void checkBiggestTile(int* board, int* biggestTile, int size) { // iterates over every tile in the matrix, and puts in pointer biggesttile the tile that has the biggest value.
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (*(board + i * size + j) >= *biggestTile) {
            	*biggestTile = *(board + i * size + j);
            }
        }
    }
}



void startBoard(int* board, int size) { //puts randomly 2 integer numbers (this function is being called only when starting the game - before the first move),
// value 2 in possibility of 70% and value 4 in possibility of 30%.
    int i, num;
    int row, col;
    for (i = 0; i < 2; i++)
    {
        num = chooseRandomNum();
        chooseRandomBoardSpot(board, size, &row, &col);
        *(board + (row * size) + col) = num;
    }

}


void startBoard_1(int* board, int size, int flag) { // puts randomly 1 integer number if the move has been accured(this function is being called after the user chose direction to move)
//value 2 in possibility of 70% and value 4 in possibility of 30%.
    if (!flag)
        printf("Nothing to move in this direction, Please choose another option: \n");
    else {
        int num;
        int row, col;
        num = chooseRandomNum();
        chooseRandomBoardSpot(board, size, &row, &col);
        *(board + (row * size) + col) = num;
    }

}







void chooseRandomBoardSpot(int* board, int size, int* row, int* col) { // choose random EMPTY board spot for inserting random values.
    do {
        *row = rand() % size;
        *col = rand() % size;
    } while (*(board + (*row) * size + (*col)) != 0);
}

int chooseRandomNum() { // checks if the value from rand() is smaller than for_2 which it's 0.7, if true -returns the number 2, else, returns the number 4(0.3 probability).
    float for_2 = 0.7;
    if (((float)rand() / RAND_MAX) < for_2) {
        return 2; 
    }
    else {
        return 4; 
    }
}

void clearboard(int* board, int size) { // iterates over the matrix (sizeXsize) and puts 0 in all tiles.
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            *(board + (i * size) + j) = 0;
        }
    }
}

int isGameOver(int* board, int size) { // checks if there is no possible moves that can be accured, if no moves, returns value 0 which it means that the game is over, if there is at least 1 possible move that can be accured, 
//returns vaule 1
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int current = *(board + i * size + j);

            if (current == 0) {
                return 0;
            }

            if (i > 0 && *(board + (i - 1) * size + j) == current) {
                return 0;
            }

            if (i < size - 1 && *(board + (i + 1) * size + j) == current) {
                return 0;
            }

            if (j > 0 && *(board + i * size + (j - 1)) == current) {
                return 0;
            }

            if (j < size - 1 && *(board + i * size + (j + 1)) == current) {
                return 0;
            }
        }
    }

    return 1;
}

int checkEmptyBoard(int* board, int size) { // checks if all tiles in the matrix are equal to 0, if true, returns 1, else returns 0.
    int i, j;
    int check = 0; 
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (*(board + (i * size) + j) != 0)
                return check;
        }
    }
    check = 1;
    return check;

}





void printBoard(int* board, int size, int* score, int* best) { // print board by address with matching values for each tile.
    int i, j;

    printf("Score: %d Best %d \n", *score, *best);

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("-----");
        }

        printf("-\n");
        printf("|");

        for (j = 0; j < size; j++) {
            int value = *(board + (i * size) + j);
            if (value != 0)
                printf(" %2d |", *(board + (i * size) + j));
            else
                printf("    |");
        }

        printf("\n");
    }

    for (j = 0; j < size; j++) {
        printf("-----");
    }

    printf("-\n");
}

void printMenu() { //prints the menu after each move or start the game.
    printf("Please choose one of the following options: \n");
    printf("N/n - New Game\n");
    printf("R/r - Move Right\n");
    printf("L/l - Move Left\n");
    printf("U/u - Move Up\n");
    printf("D/d - Move Down\n");
    printf("E/e exit\n");
}















