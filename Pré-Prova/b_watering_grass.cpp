
#include <bits/stdc++.h>
using namespace std;

#define MAX 10005

struct Interval{

    double left;
    double right;

    bool operator < (const Interval &interval){
        return left < interval.left;
    }

} intervals[MAX];

double dx(int r, double w){

    return (sqrt((double)r*r - (w/2.0)*(w/2.0)) );

}

int min_sprinklers(int k, int l){

    int counter = 0;
    double rightmost = 0.0;
    int i, j;

    for(i = 0; i < k; i = j){

        if(intervals[i].left > rightmost) break;

        for(j = i + 1; j < k && intervals[j].left <= rightmost; ++j){

            if(intervals[j].right > intervals[i].right){
               i = j;
            }

        }

        ++counter;

        rightmost = intervals[i].right;

        if (rightmost >= l) break;

    }

    if(rightmost >= l) return counter;

    return -1;

}


int main (){

    int n, l, k, pos, rad;
    double w;

    while(cin >> n >> l >> w){

        k = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &pos, &rad);

            if(rad > (w/2.0)){
                intervals[k].left = (double) pos - dx(rad, w);
                intervals[k].right = (double) pos + dx(rad, w);

                k++;
            }
        }

        sort(intervals, intervals+k);

        cout << min_sprinklers(k , l) << endl;

    }

    return 0;
}
/*

double curL = 0, rReach = 0;
        size_t i = 1;
        size_t nSprinklers = 0;
        while (rReach < l)
        {
            double newCurL = curL;
            size_t farthest = 0;
            // Take the interval that covers as far right as possible.
            for (; i < circles.size(); ++i)
            {
                if (circles[i].L > curL)
                    break;
                if (circles[i].R >= newCurL)
                {
                    newCurL = circles[i].R;
                    farthest = i;
                }
            }
            if (farthest == 0)
                break;
            ++nSprinklers;
            rReach = curL = newCurL;
        }
        if (rReach < l)
            cout << "-1" << endl;
        else
            cout << nSprinklers << endl;
    }

*/
