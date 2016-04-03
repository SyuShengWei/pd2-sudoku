#include <iostream>
#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku()
{
	numberOfAnswer = 0;
	for(int i = 0 ; i < sudokuSize ; i++){
		setAnsMap(i,0);
		setQuesMap(i,0);
		map[i] = 0 ;
	}
}


void Sudoku::showMap()
{
	for(int i = 0 ; i < sudokuSize ; ++i)
	{
		cout<<map[i]<<" ";
		if (i%9 == 8)
			cout << endl;
	}
}

void Sudoku::giveQuestion()
{
	int mapSeed[]= {
	6,4,5,3,1,2,9,7,8,9,7,8,6,4,5,3,1,2,3,1,2,9,7,8,6,4,5,
	4,5,6,1,2,3,7,8,9,7,8,9,4,5,6,1,2,3,1,2,3,7,8,9,4,5,6,
	5,6,4,2,3,1,8,9,7,8,9,7,5,6,4,2,3,1,2,3,1,8,9,7,5,6,4
	};	//initial a map
	for(int i = 0 ; i < sudokuSize ; i++)
		map[i] = mapSeed[i];

	//random change
	srand(time(NULL));
	int i =0
	while(i<20){
    changeNum(rand()%9 +1 , rand()%9 + 1);
	changeCol(rand()% 3 , rand()% 3);
	changeRow(rand()% 3 , rand()% 3);
	rotate(rand()%101);
	flip(rand()%2);
	i++;
	}
	//dig map
	int dig_time = 0 ;
	dig_time = rand () % 81 ;
	for(int i = 0 ; i < dig_time ; ++i)
		map[rand()%81] = 0 ;

	showMap();
}


bool Sudoku::isCorrect()
{
  for(int i = 0;i < 81;++i)
  {
    quesMap[i] = -1;
    if (!isPossibleAnswer(i,ansMap[i]))
    {
      return false;
    }
    quesMap[i] = ansMap[i];
  }
  return true;
}


void Sudoku::readIn()
{
    int temp;
	for(int i = 0 ; i < sudokuSize ; ++i){
		cin >>  temp ;
		setAnsMap(i,temp);
		setQuesMap(i,temp);
		setMap(i ,temp);
	}
}

void Sudoku::changeNum(int a , int b)
{
	vector<int> indexA,indexB;
	for(int i = 0 ; i < sudokuSize ; ++i)//find Index of all A
	{
		if(map[i] == a)
			indexA.push_back(i);
		else if(map[i] == b)
			indexB.push_back(i);
	}
	for(int i = 0  ; i<indexA.size() ; ++i)
		map[indexA.at(i)] = b ;
	for(int i = 0 ; i<indexB.size() ; ++i )
		map[indexB.at(i)] = a;
}

void Sudoku::changeRow(int a, int b)
{
	int buffer[27];
	for(int i = 0 ; i < 27 ; ++i)
		buffer[i] = map[27*a+i];
	for(int i = 0 ; i < 27 ; ++i)
		map[27*a+i] = map[27*b+i];
	for(int i = 0 ; i < 27 ; ++i)
		map[27*b+i] = buffer[i];
}

void Sudoku::changeCol(int a,int b)
{
	int buffer[27];
	for(int j= 0 ; j < 3 ; ++j)
	{
		for(int i = 0 ; i < 9 ;++i)
			buffer[9*j+i] = map[3*a + j+ 9*i];
	}

	for(int j= 0 ; j < 3 ; ++j)
	{
		for(int i = 0 ; i < 9 ;++i)
			map[3*a + j+ 9*i] = map[3*b + j+ 9*i];
	}

	for(int j= 0 ; j < 3 ; ++j)
	{
		for(int i = 0 ; i < 9 ;++i)
			map[3*b+ j+ 9*i] = buffer[9*j+i] ;
	}
}
void Sudoku::rotate(int  n)//rotate 90 degree
{
	int originalMap[9][9] ;
	int rotatedMap[9][9];
	for(int j = 0 ; j <  9 ; ++j)//transform int[] into int[][]
	{
		for(int i = 0 ; i < 9 ; ++i)
		{
			originalMap[i] [j] = map [i+j*9] ;
		}
	}
	for(int i = 0 ; i < n ; ++ i)
	{
		for(int x = 0 ; x < 9 ; x++)//rotate
		{
			for(int y = 0 ; y < 9 ; y++)
				rotatedMap[x][y] = originalMap[y][8-x];
		}
		for(int x = 0 ; x < 9 ; x++)//update originalMap[]
		{
			for(int y = 0 ; y < 9 ; y++)
				originalMap[x][y] = rotatedMap[x][y];
		}
	}

	for(int j = 0 ; j < 9; ++j)//update map
	{
		for(int i = 0 ; i< 9 ; ++i)
		{
			map[i+9*j] = rotatedMap[i][j];
		}
	}
}

void Sudoku::flip(int n)
{
	int originalMap[9][9] ;
	int flippedMap[9][9];
	for(int j = 0 ; j <  9 ; ++j)//transform int[] into int[][]
	{
		for(int i = 0 ; i < 9 ; ++i)
		{
			originalMap[i] [j] = map [i+j*9] ;
		}
	}

	if(n == 0)
	{
		for(int i = 0 ; i < 9 ; ++i)
		{
			for(int j = 0 ; j < 9 ;++j)
				flippedMap[i][j] = originalMap[i][8-j];
		}
	}
	else
	{
		for(int j = 0 ; j < 9 ; ++j)
		{
			for(int i = 0 ; i < 9 ; ++i )
				flippedMap[i][j] = originalMap[8-i][j];
		}
	}
	for(int j = 0 ; j < 9; ++j)//update map
	{
		for(int i = 0 ; i< 9 ; ++i)
		{
			map[i+9*j] = flippedMap[i][j];
		}
	}
}

void Sudoku::transform()
{
	//readIn();
	srand(time(NULL));
	changeNum(rand()%9 +1 , rand()%9 + 1);
	changeCol(rand()% 3 , rand()% 3);
	changeRow(rand()% 3 , rand()% 3);
	rotate(rand()%101);
	flip(rand()%2);
	showMap();
}



int Sudoku::getQuesMap(int index){
    return quesMap[index];
}

int Sudoku::getAnsMap(int index){
    return ansMap[index];
}

void Sudoku::setQuesMap(int index,int value){
    quesMap[index] = value;
}

void Sudoku::setAnsMap(int index,int value){
    ansMap[index] = value;
}

void Sudoku::setMap(int index,int value){
    map[index] = value;
}

int Sudoku::getZeroIndex(){

    for(int i = 0 ; i < 81;++i){
        if(quesMap[i] == 0)
            return i;
    }
    return -1;
}

bool Sudoku::isPossibleAnswer(int index ,int value){
    int row , col ,cell;
    row = index / 9;
    col = index % 9;
    cell = (row / 3) *27+(col/3)*3;
    for(int i = 0 ; i < 9 ; i++){
        if(getQuesMap(row * 9 + i) == value)
            return false;
        else if(getQuesMap(col + i * 9) == value)
            return false;
        else if((i+1) / 3 == 0 && getQuesMap(cell + i%3 ) == value)
            return false;
        else if((i+1) / 3 == 1 && getQuesMap(cell + 9 + i % 3) == value)
            return false;
        else if((i+1) / 3 == 2 && getQuesMap(cell + 18 + i % 3) == value)
            return false;
    }
    return true ;
}

void Sudoku::solveFunction(){
    int zeroIndex = 0;
    zeroIndex = getZeroIndex();
    //cout<<zeroIndex;
    if(numberOfAnswer > 1){
        cout<<"2"<<endl;
        exit(1);
    }
    void solveOne();
    if(zeroIndex == -1){
        if(isCorrect()){
            for(int i = 0;i < 81;i++)
                setMap(i , ansMap[i]);
            numberOfAnswer ++ ;
        }
    }
    else{
        for(int i = 1 ;i <=9 ; i++){
            setAnsMap(zeroIndex ,i);
            if(isPossibleAnswer(zeroIndex,i)){
                setQuesMap(zeroIndex,i);
                solveFunction();
            }
            setQuesMap(zeroIndex,0);
        }
        setAnsMap(zeroIndex,0);
    }
}

void Sudoku::solve(){

    int nonZero =0;
  for(int i = 0 ; i < sudokuSize ; i++)
    {
        if(map[i])
            nonZero++;
    }

    if(isFinishedMap()){
        cout<<"1"<<endl;
        showMap();
    }

    else if(!isSolvable()){
        cout<<"0"<<endl ;
        return ;
    }
    else if(nonZero < 16) {
        cout<<"2"<<endl;
        return ;
    }
    else{
        solveFunction();
        //showMap() ;
        if(numberOfAnswer == 0)
            cout<<numberOfAnswer<<endl;
        else if(numberOfAnswer == 1){
            cout<<numberOfAnswer<<endl;
            showMap();
        }
        else
            cout<<numberOfAnswer<<endl;
   }
}

bool Sudoku::isSolvable()
{
    for(int i = 0 ; i < sudokuSize ; i++){
        int row , col , cell ;
        row = i / 9;
        col = i % 9 ;
        cell = (row / 3 ) *  27  +(col / 3 ) * 3 ;
        if(map[i]){
            for(int j = 0 ; j < 9 ;  j++){
                if( map[row*9 + j ] == map[i]  && row*9 + j != i)
                    return false ;
                else if(map[col + j * 9 ] == map[i] && col + j * 9 != i)
                    return false ;
                else if( (i+1) / 3 == 0 && map[cell + j % 3 ] == map[i] && cell + j%3 != i )
                    return false ;
                else if( (i+1) / 3 == 1 && map[cell + 9 + j %3 ] == map[i]&& cell + j%3 +9!= i )
                    return false ;
                else if( (i+1) / 3 == 2 && map[cell + 18 + j %3] == map[i]&& cell + j%3 +18!= i )
                    return false ;
            }
        }
    }
    return true ;
}

bool Sudoku::checkUnity(int arr[])
{
    int check[9];
    for(int i = 0 ; i < 9 ; i ++)
        check[i] = 0;
    for(int i = 0 ; i < 9 ; i ++)
        ++check[arr[i]-1];
    for(int i = 0 ; i < 9 ; i++)
        if(check[i] != 1)
            return false;
    return true ;
}

bool Sudoku::isFinishedMap()
{
    int check[9];
    int location;
    for(int i=0; i<81; i+=9) // check rows
    {
        for(int j=0; j<9; ++j)
            check[j] = map[i+j];
        if(!checkUnity(check))
            return false;
    }
    for(int i=0; i<9; ++i) // check columns
    {
        for(int j=0; j<9; ++j)
            check[j] = map[i+9*j];
        if(!checkUnity(check))
            return false;
    }
    for(int i=0; i<9; ++i) // check cells
    {
        for(int j=0; j<9; ++j){
            location = 27*(i/3) + 3*(i%3)+9*(j/3) + (j%3);
            check[j] = map[location];
        }
        if(!checkUnity(check))
        return false;
    }
    return true;
}

void Sudoku::solveOne()
{
    int record[81][10];
    for(int i = 0;i < 81;i++){
        for(int j = 0 ; j < 81;j++){
            if(j == 0)
                record[i][j] = 9;
            else
                record[i][j] = 1;
        }
    }
    int answer = 0;
    answer = updatePossible(record);
    for(int i = 0 ;i < 81 ;i++){
        if(record[i][0] == 1){
            record[i][0] = 9;
            for(int j = 1 ;j <= 9 ;j++){
                if(record[i][j]){
                    map[i]=j;
                    answer = updatePossible(record);
                }
            }
        }
    i = -1 ;
    }
    if (answer == 81 ){
        if(isFinishedMap())
            numberOfAnswer ++;
    }
}

int Sudoku::updatePossible(int record[81][10])
{
    int answer = 0;             //[i][0] is how many possible remain
                                //[i][1~9] is if number is possible (Y,N)=(1,0)
    for(int index = 0 ; index < 81 ;index ++)
    {
        if(map[index])
            answer ++;
        else{
            for (int i = 0 ;i < 9;i++){
                int point = map[((index/(9*3))*3+i/3)*9 + ((index%9)/3)*3+i%3];

                if(map[(index/9)*9+i]&& record[index][map[(index/9)*9+i]]){
                    record[index][0]--;
                    record[index][map[(index/9)*9+i]] = 0;
                }
                else if(map[i*9+index%9]&& record[index][map[i*9+index%9]]){
                    record[index][0]--;
                    record[index][map[i*9+index%9]] = 0;
                }
                else if(map[((index/27)*3+i/3)*9 + ((index%9)/3)*3+i%3]&& record[index][point]){
                    record[index][0]--;
                    record[index][point] = 0;
                }
            }
        }
    }
    return answer ;
}
