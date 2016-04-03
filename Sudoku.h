#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
class Sudoku{
public:
    Sudoku();
    static const int sudokuSize = 81;

    bool isPossibleAnswer(int index , int value);
    int  getZeroIndex();
    void showMap();
    int getQuesMap(int index);
    int getAnsMap(int index);
    void setQuesMap(int index ,int value);
    void setAnsMap(int index ,int value);
    void setMap(int index ,int value);
    bool isSolvable();
    bool isCorrect();
    bool isFinishedMap();
    bool checkUnity(int arr[]);
   // bool isSameAns(int arr1[81],int arr2[81]);
    void solveOne();
    int updatePossible(int record[81][10]);

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
    int quesMap[sudokuSize];
    int ansMap[sudokuSize];
    int numberOfAnswer ;

};
