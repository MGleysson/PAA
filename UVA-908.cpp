
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
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
			sum += arvore[i].obterPeso();
		}

        return sum;
	}
};


int main(int argc, char *argv[])
{
    int tc;

    cin >> tc;

    while(tc--){
       int n, k, m, node1, node2, cost;
       int cost_total = 0;

        cin >> n;

        Grafo g(n);

        for(int i=0; i<n-1; i++){
            cin >> node1 >> node2 >> cost;
            cost_total += cost;
        }

        cin >> k;

        for(int i=0; i < k; i++){
            cin >> node1 >> node2 >> cost;
            g.adicionarAresta(node1-1, node2-1, cost);
        }

        cin >> m;

        for(int i=0; i < m; i++){
            cin >> node1 >> node2 >> cost;
            g.adicionarAresta(node1-1, node2-1, cost);
        }

        cout << cost_total << endl << g.mst_cost() << endl;

    }

	return 0;
}
