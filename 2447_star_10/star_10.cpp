#include <iostream>

using namespace std;

void star(int x, int y, int k){
    if( x / k % 3 == 1 && y / k % 3 == 1){
        printf(" ");
    }else{
        if(k == 1){
            printf("*");
        }else{
            star(x, y, k / 3);
        }
    }
}

void starStart(int k){
    for(size_t y_ = 0; y_ < k; y_++){
        for(size_t x_ = 0; x_ < k; x_++){
            star(x_, y_, k);
        }
        printf("\n");
    }
}

int main(){
    int num = 0;
    scanf("%d", &num);
    starStart(num);
}