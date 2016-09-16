

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <stdlib.h>

using namespace std;

class Aresta
{
	int vertice1;
	int vertice2;
	int peso;

public:

	Aresta(int v1, int v2, int peso)
	{
		vertice1 = v1;
        vertice2 = v2;
		this->peso = peso;
	}

	int obterVertice1()
	{
		return vertice1;
	}

	int obterVertice2()
	{
		return vertice2;
	}

	int obterPeso()
	{
		return peso;
	}

	bool operator < (const Aresta& aresta2) const
	{
		return (peso < aresta2.peso);
	}
};


class Grafo
{
	int V;
	vector<Aresta> arestas;

public:

	Grafo(int V)
	{
		this->V = V;
	}

	void adicionarAresta(int v1, int v2, int peso)
	{
		Aresta aresta(v1, v2, peso);
		arestas.push_back(aresta);
	}


	int buscar(int subset[], int i)
	{
		if(subset[i] == -1) return i;

		return buscar(subset, subset[i]);
	}

	void unir(int subset[], int v1, int v2)
	{
		int v1_set = buscar(subset, v1);
		int v2_set = buscar(subset, v2);
		subset[v1_set] = v2_set;
	}

	int mst_cost()
	{
		vector<Aresta> arvore;
		int size_arestas = arestas.size();

		sort(arestas.begin(), arestas.end());

		int *subset = new int[V];

		memset(subset, -1, sizeof(int) * V);

		for(int i = 0; i < size_arestas; i++)
		{
			int v1 = buscar(subset, arestas[i].obterVertice1());
			int v2 = buscar(subset, arestas[i].obterVertice2());

			if(v1 != v2)
			{
				arvore.push_back(arestas[i]);
				unir(subset, v1, v2);
			}
		}


		int size_arvore = arvore.size();

        int sum;

		for(int i = 0; i < size_arvore; i++)
		{
		    //cout << "Pesos: " << arvore[i].obterPeso() << endl;
			sum += arvore[i].obterPeso();
		}

        return sum;
	}
};

map<string, int> M;

int city(string& s) {
    if (M.find(s) != M.end())
        return (M[s]-1);
    else
        return ((M[s]=M.size())-1);

}

int main(int argc, char *argv[])
{
    int tc;

    cin >> tc;

    while(tc--){
       int cities, links, cost;
        string v1;
        string v2;
        M.clear();

        cin >> cities >> links;

        Grafo g(cities);

        for(int i = 0; i < links; i++){
            cin >> v1 >> v2 >> cost;

            int v1_int = city(v1);
            int v2_int = city(v2);

            //cout << v1_int << " - " << v2_int << endl;

            g.adicionarAresta(v1_int, v2_int, cost);
        }


        cout <<  g.mst_cost() << endl;

    }

	return 0;
}

