/*
For a giving grid, verifies if it respect the rules of sudoku.

Take array of 81 numbers and return true if it is valid, else false.
*/

#include <array>
#include <vector>

namespace grid_validation {

    bool is_valid (std::array<int, 81> grid);

    bool is_row_valid(std::array<int, 81> grid, int row_index);
    bool is_column_valid(std::array<int, 81> grid, int column_index);
    bool is_square_valid(std::array<int, 81> grid, int square_index);

    int get_index(int x, int y);
}