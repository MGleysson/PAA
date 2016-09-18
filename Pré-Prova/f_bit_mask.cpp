
#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n, l, r, ans, l1, r1;

    while(scanf("%lld %lld %lld", &n, &l, &r) == 3){

        ans = 0;
        long long i;

        for(i=31; i >= 0; i--){
             if(n&(1LL<<i)) {

                r1 = ans + (1LL<<i);

                if(r1 <= l)
                    ans += 1LL<<i;

            } else {
                l1 = ans + (1LL<<i);

                if(l1 <= r)
                    ans += 1LL<<i;
            }
        }

        printf("%lld\n", ans);

    }

    return 0;
}
