
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


#include<bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    unsigned int N,L,U;

    while (cin >> N >> L >> U) {
      unsigned int M = ~N;

      for (int i=31;i>=0;--i) {
        unsigned int mask = 1 << i;

        if ((M >> i) < (L >> i)) M |= mask;
        else if ((M >> i) > (U >> i)) M &= ~mask;

      }

      cout << M << endl;

    }
    return 0;
}
