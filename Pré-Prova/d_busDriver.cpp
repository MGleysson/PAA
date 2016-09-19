
#include <bits/stdc++.h>

using namespace std;

void merge(int *v, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0;
    int fim2 = 0;

    tamanho = (fim-inicio)+1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *) malloc(tamanho*sizeof(int));

    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(v[p1] < v[p2]){
                   temp[i] = v[p1];
                   p1++;
                }else{
                    temp[i] = v[p2];
                    p2++;
                }

                if(p1>meio){
                    fim1 = 1;
                }
                if(p2>fim){
                    fim2 = 1;
                }

            }else{
                if(!fim1){
                    temp[i] = v[p1];
                    p1++;
                }else{
                    temp[i] = v[p2];
                    p2++;
                }
            }
        }

        for(j = 0, k = inicio; j<tamanho; j++, k++){
            v[k] = temp[j];
        }
    }

    free(temp);

}

// algoritmo merge sort que ordena as rotas de forma CRESCENTE
void mergeSortCRESC(int *v, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSortCRESC(v,inicio,meio);
        mergeSortCRESC(v,meio+1,fim);
        merge(v,inicio,meio,fim);
    }

}

void merge2(int *v, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0;
    int fim2 = 0;

    tamanho = (fim-inicio)+1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *) malloc(tamanho*sizeof(int));

    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(v[p1] < v[p2]){
                   temp[i] = v[p2];
                   p2++;
                }else{
                    temp[i] = v[p1];
                    p1++;
                }

                if(p1>meio){
                    fim1 = 1;
                }
                if(p2>fim){
                    fim2 = 1;
                }

            }else{
                if(!fim1){
                    temp[i] = v[p1];
                    p1++;
                }else{
                    temp[i] = v[p2];
                    p2++;
                }
            }
        }

        for(j = 0, k = inicio; j<tamanho; j++, k++){
            v[k] = temp[j];
        }
    }

    free(temp);

}


// algoritmo merge sort que ordena as rotas de forma DECRESCENTE
void mergeSortDEC(int *v, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSortDEC(v,inicio,meio);
        mergeSortDEC(v,meio+1,fim);
        merge2(v,inicio,meio,fim);
    }

}

bool compare1(int i, int j) {
    return (i > j);
}

bool compare2(int i, int j){
    return (i < j);
}

// vetores que guardam os tamanhos de cada rota (rotas do período da manhã e rotas do período da noite)
//int routes_morning[105];
//int routes_evenning[105];

vector<int> routes_morning;
vector<int> routes_evening;

int main(){

    int n, d, r, i, rm, re;

    do{
        int min_overtime = 0;

        routes_morning.clear();
        routes_evening.clear();

        scanf("%d%d%d", &n, &d, &r);

        if(n!=0 && d!=0 && r!=0){

            for(i = 0; i < n; i++){
                scanf("%d", &rm);
                routes_morning.push_back(rm);

            }

            for(i = 0; i < n; i++){
                scanf("%d", &re);
                routes_evening.push_back(re);
            }


			/*
				ordena o tamanho das rotas de forma crescente e decrescente
				pois dessa forma ao combinar uma rota da manhã com uma rota da tarde, a soma entre elas vai ser a mínima possível
			*/

            sort(routes_morning.begin(), routes_morning.end(), compare2);
            sort(routes_evening.begin(), routes_evening.end(), compare1);
            //mergeSortCRESC(routes_morning, 0, n-1);
            //mergeSortDEC(routes_evenning, 0, n-1);

			/*
				faz a distribuição de rotas para cada motorista, pegando a rota de maior tamanho da manhã com a rota de menor tamanho da noite...

			*/
            for(i = 0; i < n; i++){
				// se ultrapassar o valor limite d, calcule o custo de horas extra de trabalho.
                if((routes_morning[i]+routes_evening[i]) > d){
                    min_overtime += (((routes_morning[i]+routes_evening[i])-d)*r);
                }
            }

            printf("%d\n", min_overtime);
        }

    }while(n!=0 && d!=0 && r!=0);



    return 0;
}
