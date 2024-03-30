#include "grid_validation.h"

const int SUM_TO_9 = 9 * 10 / 2;

bool grid_validation::is_valid(std::array<int, 81> grid) {

    for (int k = 0; k < 9; k++) {  // We test each row, column and square
        if (is_row_valid(grid, k) && is_column_valid(grid, k) && is_square_valid(grid, k)) {
            continue;
        } else {
            return false;  // return false at the first error
        }
    }   

    return true;  // return true if the grid pass the test
}

int grid_validation::get_index(int x, int y) {
    
    return y * 9 + x;  // 9x9 grid with 0 <= x, y <= 8
}

bool grid_validation::is_row_valid(std::array<int, 81> grid, int row_index) {

    std::array<int, 9> row;  // creating an array to store only the necessary number
    int row_starting_index = get_index(0, row_index);

    for (int k = 0; k < 9; k++) {  // Stores the row in an array
        row[k] = row_starting_index + k;
    }

    int sum_of_row {0};

    for (int i = 0; i < 9; i++) {  // Sums all the number of the array
        sum_of_row += row[i];
    }

    return sum_of_row == SUM_TO_9;  // the sum must be equal to 1 + 2 + ... + 9 in order to be correct
}

bool grid_validation::is_column_valid(std::array<int, 81> grid, int column_index) {

    std::array<int, 9> column;  // creating an array to store only the necessary number
    int column_starting_index = get_index(column_index, 0);

    for (int k = 0; k < 9; k++) {  // Stores the column in an array
        column[k] = get_index(column_index, k);
    }

    int sum_of_column {0};

    for (int i = 0; i < 9; i++) {  // Sums all the number of the array
        sum_of_column += column[i];
    }

    return sum_of_column == SUM_TO_9;  // the sum must be equal to 1 + 2 + ... + 9 in order to be correct
}

bool grid_validation::is_square_valid(std::array<int, 81> grid, int square_index) {

    std::array<int, 9> square;  // creating an array to store only the necessary number
    int square_starting_x = square_index % 3 * 3;
    int square_starting_y = (square_index / 3) * 3;

    /* 
    square_index % 3 gives the abscisse of the square on a 3x3 grid
    square_index / 3 gives the ordinate of the square on a 3x3 grid

    I multiple these index by 3 in order to have the coordinate of the smaller 9x9 grid
    */  

    for (int i = 0; i < 3; i++) {  // stores the square in an array
        for (int j = 0; j < 3; j++) {
            square[i * 3 + j] = get_index(square_starting_x + j, square_starting_y + i);
        }
    }

    /*
    I'm filling the square array in the order shown below:
        0 1 2
        3 4 5
        6 7 8
    */

   int sum_of_square {0};

    for (int i = 0; i < 9; i++) {  // Sums all the number of the array
        sum_of_square += square[i];
    }

    return sum_of_square == SUM_TO_9;  // the sum must be equal to 1 + 2 + ... + 9 in order to be correct
}