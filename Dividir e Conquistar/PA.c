#include <stdio.h>

int r;
int v[15];

int findElement(int begin, int end){

    int diff1, diff2, middle;

    if(end - begin == 1){
       return (v[begin] + r);
    }

    middle = (begin+end)/2;
    diff1 = v[middle] - v[begin];
    diff2 = v[end] - v[middle];

    if(diff2 > diff1){
        return findElement(middle, end);
    }else{
        return findElement(begin, middle);
    }
}

int main(){

    int tc, n, total, j, e;
    scanf("%d", &total);

    for(tc = 0; tc < total; tc++){
        scanf("%d", &n);

        for(j = 0; j < n; j++){
            scanf("%d", &v[j]);
        }

        r = (v[n-1] - v[0])/n;

        e = findElement(0, n-1);
        printf("%d\n", e);
    }

    return 0;
}
