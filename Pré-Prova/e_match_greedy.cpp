#include<bits/stdc++.h>
using namespace std;

int c = 1;

bool compare(int i, int j) {
  return (i > j);
}

int main() {
  int b, s;

  do {
    cin >> b >> s;

    if (b == 0 && s == 0)
      break;

    vector<int> bachelor;
    vector<int> spinster;

    cout << "Case " << c++ << ": ";

    for (int i = 0; i < b; ++i){
      int v;
      cin >> v;
      bachelor.push_back(v);
    }

    for (int i = 0; i < s; ++i){
      int v;
      cin >> v;
      spinster.push_back(v);
    }

    sort (bachelor.begin(), bachelor.end(), compare);
    sort (spinster.begin(), spinster.end(), compare);

    // Procuro a spinster com idade mais próxima à do bachelor mais velho

    int diff = INT_MAX;

    vector< pair<int,int> > casais;

    int posic = 0;

    for (int j = 0; j < s; ++j) {
        if (abs(bachelor[0] - spinster[j]) < diff){
          diff = abs(bachelor[0] - spinster[j]);
          posic = j;
        } else break;
    }

    //cout << "A melhor pro mais velho é a " << spinster[posic] << endl;

    int i, j;
    for (i = 0, j = posic; i < b && j != s; ++i, ++j){
      casais.push_back(make_pair(bachelor[i], spinster[j%s]));
      //cout << bachelor[i] << " e " << spinster[j%s] << endl;
    }

    for (j = posic-1; i < b && j>= 0; ++i, --j){
      casais.push_back(make_pair(bachelor[i], spinster[j%s]));
      //cout << bachelor[i] << " e " << spinster[j%s] << endl;
    }

    //for (int i = 0; i < casais.size(); ++i)
      //cout << casais[i].first << " casou com " << casais[i].second << endl;

    int quant = (b-casais.size());
    if (quant != 0)
      cout << quant << " " << bachelor[bachelor.size()-1] << endl;
    else
      cout << 0 << endl;

} while(b != 0 && s != 0);

}
