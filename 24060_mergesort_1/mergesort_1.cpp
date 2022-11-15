#include <iostream>
#include <array>

using namespace std;

int tempArr[500000]; //병합정렬을 위한 임시 배열
int searchNumber = -1; //K번 째 저장 되는 수
int saveCount = 1; //현재까지의 저장 횟수
int targetCount = 0;

void sort(int* arr, int p, int r){
    int i = p;
    int q = (p + r) / 2;
    int j = q + 1;
    int t = p;
    
    while(i <= q && j <= r){
        if(arr[i] < arr[j]){
            tempArr[t] = arr[i];
            t++;
            i++;
        }else{
            tempArr[t] = arr[j];
            t++;
            j++;
        }
    }

    while(i <= q){ //왼쪽 배열 남음
        tempArr[t] = arr[i];
        t++;
        i++;
    }
    while(j <= r){ //오른쪽 배열이 남음
        tempArr[t] = arr[j];
        t++;
        j++;
    }

    while(p <= r){
        //저장발생
        arr[p] = tempArr[p];
        if(targetCount == saveCount){
            searchNumber = tempArr[p];
        }
        p++;
        saveCount++;
    }
}

void mergeSort(int* arr, int p, int r){
    if(p < r){
        mergeSort(arr, p, (p + r) / 2); //왼쪽 배열
        mergeSort(arr, (p + r) / 2 + 1, r); //오른쪽 배열
        sort(arr, p, r);
    }
}

int main(){
    //배열 크기 입력
    size_t arraySize = 0;
    scanf("%d", &arraySize);

    //저장값 입력
    scanf("%d", &targetCount);
    
    //배열 값 입력
    int* myArray = new int[arraySize];
    for(int i = 0; i < arraySize; i++){
        int num = 0;
        scanf("%d", &num);
        myArray[i] = num;
    }

    //정렬
    mergeSort(myArray, 0, arraySize - 1);

    //정답 출력
    cout << searchNumber;
    delete [] myArray;
}