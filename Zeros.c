#include <stdio.h>

int n;
int v[35];

int countZeros(int begin, int end){

    int middle = (begin+end)/2;

    if(v[begin] == v[end] && v[begin] == 0){
        return (n - begin);
    }

    if(v[begin] == 0){
        return (end - begin) + 1;
    }

    if(v[end] == 1){
       return (n - end) - 1;
    }

    if(v[middle] == 1){
        return countZeros(middle + 1, end);
    }else{
       return countZeros(begin, middle - 1);
    }

}

int main(){

    int tc, total, i, quant;

    scanf("%d", &total);

    for(tc = 0; tc < total; tc++){
        scanf("%d", &n);

        for(i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }

        quant = countZeros(0, n-1);

        printf("%d\n", quant);

    }

    return 0;
}
