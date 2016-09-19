#include<iostream>

using namespace std;

int newer(int *v, int end ){
    int i;
    int temp = v[0];
    for(i = 1; i < end; i++){
        if(temp > v[i]){
            temp = v[i];
        }
    }
    return temp;
}
int main () {
    int i;
    int *bach, *spin, nbach, nspin;
    int output1[25],output2[25];
    int c = 0;

    cin >> nbach >> nspin;
    while (nbach!=0 && nspin!=0){
    bach = new int[nbach];
    spin = new int[nspin];
    for ( i = 0; i < nbach; i++ ) {
        cin >> bach[i];
    }
    for ( i = 0; i < nspin; i++ ) {
        cin >> spin[i];
    }

    if(nbach > nspin){
        output1[c] = nbach - nspin;
        output2[c] = newer( bach, nbach );
    }

    if(nbach <= nspin){
        output1[c] = 0;
    }

    c++;

    cin >> nbach >> nspin;

    }

    for ( i = 0; i < c; i++ ) {
        if ( output1[i] != 0 )
            cout <<"Case "<<i+1<<": "<<output1[i]<<" "<<output2[i];
        else
            cout <<"Case "<<i+1<<": 0";
        cout << "\n";
    }

}

