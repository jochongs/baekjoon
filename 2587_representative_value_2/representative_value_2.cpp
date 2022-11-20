#include <iostream>

using namespace std;

//정렬함수
void arrSort(int *arr, size_t arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[i] > arr[j])
            { //변경
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    //출력 값
    int average = 0;
    int inputCount = 5;

    //배열 생성
    int *arr = new int[inputCount];

    //값 입력
    for (size_t i = 0; i < inputCount; i++)
    {
        //평균값 저장
        int inputNumber = 0;
        scanf("%d", &inputNumber);
        average += inputNumber / inputCount;

        //배열에 입력
        arr[i] = inputNumber;
    }

    //값 정렬
    arrSort(arr, inputCount);

    //값 출력
    printf("%d\n%d", average, arr[inputCount / 2]);
}