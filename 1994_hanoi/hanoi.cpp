#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void hanoi(int plateNumber, int fromColumn, int subColumn, int toColumn){
    if(plateNumber == 1){
        printf("%d %d\n",fromColumn,toColumn);
    }else{
        hanoi(plateNumber - 1,fromColumn,toColumn,subColumn);
        printf("%d %d\n",fromColumn,toColumn);
        hanoi(plateNumber - 1,subColumn,fromColumn,toColumn);
    }
}

int main(){
    int plateNumber = 0;
    cin >> plateNumber;

    string moveCount = to_string(pow(2, plateNumber));

    moveCount = moveCount.substr(0,moveCount.find('.'));
    moveCount[moveCount.length() - 1] -= 1;
    
    cout << moveCount << endl;
    if(plateNumber <= 20){
        hanoi(plateNumber,1,2,3);
    }
}