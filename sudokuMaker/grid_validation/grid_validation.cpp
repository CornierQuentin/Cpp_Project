#include "grid_validation.h"
#include <iostream>

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
        row[k] = grid[row_starting_index + k];
    }

    // We assume that the numbers in the array are between 1 and 9
    std::array<int, 10> occurence = {0}; // array to store the number of occurence of each number

    for (int i = 0; i < 9; i++) {  // for each number in the row we add its occurence
        if (occurence[row[i]] < 1) {  // if it's 0 we increment it
            occurence[row[i]]++;
        } else {  // if it's above or equal to 1, it doesn't respect the sudoku rule, becaus there are two occurence of the same number
            return false;
        }
    }

    return true;  // if it goes through all the test above, there is only one occurence of each number and the row is valid
}

bool grid_validation::is_column_valid(std::array<int, 81> grid, int column_index) {

    std::array<int, 9> column;  // creating an array to store only the necessary number
    int column_starting_index = get_index(column_index, 0);

    for (int k = 0; k < 9; k++) {  // Stores the column in an array
        column[k] = grid[get_index(column_index, k)];
    }

    // We assume that the numbers in the array are between 1 and 9
    std::array<int, 10> occurence = {0}; // array to store the number of occurence of each number

    for (int i = 0; i < 9; i++) {  // for each number in the column we add its occurence
        if (occurence[column[i]] < 1) {  // if it's 0 we increment it
            occurence[column[i]]++;
        } else {  // if it's above or equal to 1, it doesn't respect the sudoku rule, becaus there are two occurence of the same number
            return false;
        }
    }

    return true;  // if it goes through all the test above, there is only one occurence of each number and the column is valid
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
            square[i * 3 + j] = grid[get_index(square_starting_x + j, square_starting_y + i)];
        }
    }

    /*
    I'm filling the square array in the order shown below:
        0 1 2
        3 4 5
        6 7 8
    */

   // We assume that the numbers in the array are between 1 and 9
   std::array<int, 10> occurence = {0}; // array to store the number of occurence of each number

    for (int i = 0; i < 9; i++) {  // for each number in the square we add its occurence
        if (occurence[square[i]] < 1) {  // if it's 0 we increment it
            occurence[square[i]]++;
        } else {  // if it's above or equal to 1, it doesn't respect the sudoku rule, becaus there are two occurence of the same number
            return false;
        }
    }

    return true;  // if it goes through all the test above, there is only one occurence of each number and the square is valid
}