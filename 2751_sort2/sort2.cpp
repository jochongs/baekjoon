#include <iostream>
#include <array>

using namespace std;

int tempArr[1000000];

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
        p++;
    }
}

void mergeSort(int* arr, int p, int r){
    if(r <= p + 1){
        sort(arr, p, r);
    }else{
        mergeSort(arr, p, (p + r) / 2); //왼쪽 배열
        mergeSort(arr, (p + r) / 2 + 1, r); //오른쪽 배열
        sort(arr, p, r);
    }
}

int main(){
    size_t arraySize = 0;
    scanf("%d", &arraySize);

    int* myArray = new int[arraySize];
    for(int i = 0; i < arraySize; i++){
        int num = 0;
        scanf("%d", &num);
        myArray[i] = num;
    }

    mergeSort(myArray, 0, arraySize - 1);
    for(int i = 0; i < arraySize; i++){
        printf("%d\n", myArray[i]);
    }
}