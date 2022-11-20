#include<iostream>

using namespace std;

//배열 출력 함수
void displayArr(int* arr, size_t arrSize){
    for(int i = 0; i < arrSize; i++){
        printf("%d\n", arr[i]);
    }
}

//정렬함수
int* arrSort(int* arr, size_t arrSize){
    for(int i = 0; i < arrSize; i++){
        for(int j = i + 1; j < arrSize; j++){
            if(arr[i] > arr[j]){ //변경
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return arr;
}

int main(){
    //배열 사이즈 입력
    int arrSize = 0;
    scanf("%d", &arrSize);

    //배열 생성
    int* arr = new int[arrSize];

    //배열 값 입력
    for(int i = 0; i < arrSize; i++){
        int number = 0;
        scanf("%d", &number);
        arr[i] = number;
    }
    
    //배열 정렬
    arrSort(arr, arrSize);

    //배열 출력
    displayArr(arr,arrSize);   
}