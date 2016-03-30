#include<iostream>
class Sudoku{
public:
    Sudoku();
    Sudoku(const int init_map[]);
    void setMap(const int set_map[]);
    int getElement(int index);
    bool isCorrect();
    static const int sudokuSize = 81;

private:
    bool checkUnity(int arr[])
    int map[sudokuSize];

};
