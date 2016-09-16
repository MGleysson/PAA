
#include <bits/stdc++.h>

using namespace std;

class Aresta
{
	int vertice1, vertice2, peso;

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

	// sobrescrita do operador "<"
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
		if(subset[i] == -1)
			return i;
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
		//vector<Aresta> arvore;
		int cost = 0;
		int size_arestas = arestas.size();

		sort(arestas.begin(), arestas.end());

		int * subset = new int[V];

		memset(subset, -1, sizeof(int) * V);

		for(int i = 0; i < size_arestas; i++)
		{
			int v1 = buscar(subset, arestas[i].obterVertice1());
			int v2 = buscar(subset, arestas[i].obterVertice2());

			if(v1 != v2)
			{
				//arvore.push_back(arestas[i]);
				unir(subset, v1, v2);
				cost += arestas[i].obterPeso();
			}
		}

		return cost;

	}
};


map<string, int> M;

int station(string& s) {
    if (M.find(s) != M.end())
        return (M[s]);
    else
        return ((M[s]=M.size()));

}

int main(int argc, char *argv[]){

    int s, c, cost;
    string v1;
    string v2;
    string origem;

    do{
        cin >> s >> c;

        if(s == 0 && c == 0) break;

        M.clear();

        string stations[s];

        Grafo g(s);

        for(int i = 0; i < s; i++){
           cin >> stations[i];
        }

        for(int i = 0; i < c; i++){
            cin >> v1 >> v2 >> cost;

            int v1_int = station(v1) - 1;
            int v2_int = station(v2) - 1;

            cout << v1_int << " - " << v2_int<< endl;

            g.adicionarAresta(v1_int, v2_int, cost);

        }

        cin >> origem;
        int origem_int = station(origem)-1;

        cout << origem_int << endl;

        cout << "Chegou aqui!" << endl;

    }while(s!=0 && c!=0);

	return 0;
}

