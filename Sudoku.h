#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
class Sudoku{
public:
    Sudoku();
    static const int sudokuSize = 81;

    void setMap(int index , int value) ;
    void setQuestionMap(int index ,int value);
    int    getMap(int index );
    int    getQuestionMap(int index );
    bool isPossibleAnswer(int index);
    int getZeroIndex();
    void showMap();
    bool isSolvable();

    void giveQuestion();
    void readIn();
    void solve();
    void solveFunction();
    void changeNum(int a , int b);
    void changeRow(int a , int b);
    void changeCol(int a ,int  b);
    void rotate(int n);
    void flip(int n);
    void transform();

private:
    int map[sudokuSize];
    int questionMap[sudokuSize];
    int numberOfAnswer;
    int answer[sudokuSize];
    int nonZero ;
    int possibleNumber[sudokuSize][9];
    int howManyImPossible[sudokuSize];
};
