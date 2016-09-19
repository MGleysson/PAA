#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m, d, h;

  do {

    cin >> n >> m;

    //indica fim dos casos
    if (n == 0 && m == 0)
      break;

    vector<int> diameter;
    vector<int> height;

    for (int i = 0; i < n; ++i){
      cin >> d;
      diameter.push_back(d);
    }

    for (int i = 0; i < m; ++i){
      cin >> h;
      height.push_back(h);
    }

    //Ordena os vectors
    sort(diameter.begin(), diameter.begin()+n);
    sort(height.begin(), height.begin()+m);

    int i;
    int j;
    bool win = true;
    int gold = 0;

    ///Percorro todas as cabeças
    for (i = 0, j = 0; i < n && win == true; ++i){
      ///Acabaram os cavaleiros, mas se estou dentro do loop, não acabaram as cabeças!
      if (j == m){
        win = false;
        break;
      } else if (height[j] >= diameter[i]){   ///se o cavaleiro atual pode vencer a cabeça atual
        gold += height[j];
        j++;
      } else {                                ///se o cavaleiro não consegue, vou para o próximo (j++).
        j++;
        i--;                                  ///diminuo i porque o for vai aumentar. Dessa maneira, o valor permanece inalterado.
      }
    }

    if (win)
      cout << gold << endl;
    else
      cout << "Loowater is doomed!" << endl;

  } while(n != 0 && m != 0);

}
