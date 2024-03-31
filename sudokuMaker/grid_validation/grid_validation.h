/*
For a given grid, verifies if it respect the rules of sudoku.

Take array of 81 numbers and return true if it is valid, else false.
*/

#include <array>
#include <vector>

namespace grid_validation {

    /*****************************************************************************
       * For a given grid, verifies if it respect the rules of sudoku.
       * 
       * @param grid an array of integers which represents the sudoku
       * 
       * @return a boolean, true if the grid is valid, else false
    *****************************************************************************/
    bool is_valid (std::array<int, 81> grid);

    /*****************************************************************************
       * For a given row, verifies if it respect the rules of sudoku.
       * 
       * @param grid an array of integers which represents the sudoku
       * @param row_index an interger that represents the index of the row starting from the top
       * 
       * @return a boolean, true if the row is valid, else false
    *****************************************************************************/
    bool is_row_valid(std::array<int, 81> grid, int row_index);

    /*****************************************************************************
       * For a given column, verifies if it respect the rules of sudoku.
       * 
       * @param grid an array of integers which represents the sudoku
       * @param column_index an interger that represents the index of the column starting from the left
       * 
       * @return a boolean, true if the grid is column, else false
    *****************************************************************************/
    bool is_column_valid(std::array<int, 81> grid, int column_index);

    /*****************************************************************************
       * For a given square a sudoku, verifies if it respect the rules of sudoku.
       * 
       * @param grid an array of integers which represents the sudoku
       * @param square_index an interger that represents the index of the square starting from 
       * the top right corner to the bottom left corner
       * 
       * @return a boolean, true if the square is valid, else false
    *****************************************************************************/
    bool is_square_valid(std::array<int, 81> grid, int square_index);

    /*****************************************************************************
       * A sudoku is represented as an array of 81 integers and this function translate the coordinate
       * of the grid representation to the index in the vectorial one.
       * 
       * @param x an integer which represents the abscisse 
       * @param y an integer which represents the ordinate
       * 
       * @return return the index in the vector representation
    *****************************************************************************/
    int get_index(int x, int y);
}