#include <iostream>

const int SIZE = 9;
int board[SIZE][SIZE];

bool inRow(int board[][SIZE], int row, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return true;
        }
    }

    return false;
}

bool inColumn(int board[][SIZE], int column, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][column] == num) {
            return true;
        }
    }

    return false;
}

bool inBox(int board[][SIZE], int row, int column, int num) {
    int boxRow = row - row % 3;
    int boxColumn = column - column % 3;

    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxColumn; j < boxColumn + 3; j++) {
            if (board[i][j] == num) {
                return true;
            }
        }
    }

    return false;
}

bool isValid(int board[][SIZE], int row, int column, int num) {
    bool validRow = !inRow(board, row, num);
    bool validColumn = !inColumn(board, column, num);
    bool validBox = !inBox(board, row, column, num);

    return validRow && validColumn && validBox;
}

bool solveBoard(int board[][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int column = 0; column < SIZE; column++) {
            if (board[row][column] == 0) {
                for (int num = 1; num <= SIZE; num++) {
                    if (isValid(board, row, column, num)) {
                        board[row][column] = num;

                        if (solveBoard(board)) {
                            return true;
                        
                        } else {
                            board[row][column] = 0;
                        }
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void printBoard(int board[][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        std::cout << " ";

        if (row % 3 == 0 && row != 0) {
            std::cout << "------+-------+------\n ";
        }

        for (int column = 0; column < SIZE; column++) {
            if (column % 3 == 0 && column != 0) {
                std::cout << "| ";
            }

            if (board[row][column] == 0) {
                std::cout << "  ";

            } else {
                std::cout << board[row][column] << " ";
            }
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

int main() {
    int testBoard[][SIZE] = {
        {7, 0, 2, 0, 5, 0, 6, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 0},
        {1, 0, 0, 0, 0, 9, 5, 0, 0},
        {8, 0, 0, 0, 0, 0, 0, 9, 0},
        {0, 4, 3, 0, 0, 0, 7, 5, 0},
        {0, 9, 0, 0, 0, 0, 0, 0, 8},
        {0, 0, 9, 7, 0, 0, 0, 0, 5},
        {0, 0, 0, 2, 0, 0, 0, 0, 0},
        {0, 0, 7, 0, 4, 0, 2, 0, 3}
    };

    std::cout << "Input values:\n" << std::endl;
    
    for (int i = 0; i < SIZE; i++) {
        std::cout << " ";
        std::cin
            >> board[i][0]
            >> board[i][1]
            >> board[i][2]
            >> board[i][3]
            >> board[i][4]
            >> board[i][5]
            >> board[i][6]
            >> board[i][7]
            >> board[i][8];
    }

    std::cout << "\nInputed board:\n" << std::endl;
    printBoard(board);

    if (solveBoard(board)) {
        std::cout << "Solved board:\n" << std::endl;
        printBoard(board);
    
    } else {
        std::cout << "Board unsolvable!\n" << std::endl;
    }

    return 0;
}
