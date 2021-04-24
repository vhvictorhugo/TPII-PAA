

#include <bits/stdc++.h>
using namespace std;
#define N 100

// Numero de linhas e colunas
int n, m;

// declaração da matriz de max
// 1oo linhas por 100 colunas
int a[N][N];

// Variável visitada é usada para manter
// rastreia todas as posições visitadas
// Variable dp é usado para armazenar
// soma máxima até a posição atual
vector<vector<int> > dp(N, vector<int>(N)),
	visited(N, vector<int>(N));

// Para armazenar a soma atual
int current_sum = 0;
int current_sum = 0;


// Para atualização contínua de
// soma máxima exigida
int total_sum = 0;
int total_sum = 0;

// Função para inserir a matriz de tamanho n * m
void inputMatrix()
{
	n = 3;
	m = 3;
	a[0][0] = 500;
	a[0][1] = 100;
	a[0][2] = 230;
	a[1][0] = 1000;
	a[1][1] = 300;
	a[1][2] = 100;
	a[2][0] = 200;
	a[2][1] = 1000;
	a[2][2] = 200;
}

// Função para calcular a soma máxima do caminho
int maximum_sum_path(int i, int j)
{
	// Verificando a condição de limite
	if (i == n - 1 && j == m - 1)
		return a[i][j];

	// Verificar se (i, j) é visitado ou não
	if (visited[i][j])
		return dp[i][j];

	// A marcação (i, j) é visitada
	visited[i][j] = 1;

// Atualizando a soma máxima até
// a posição atual no dp
	int& total_sum = dp[i][j];

	// Verificar se a posição não
// visitou a última linha ou a última coluna.
// Fazendo chamadas recursivas para todo o possível
// move-se da célula atual e, em seguida, adiciona o
// máximo retornado pelas chamadas e atualizando-o.
	if (i < n - 1 & j < m - 1) {
		int current_sum = max(maximum_sum_path(i, j + 1),
							max(
								maximum_sum_path(i + 1, j + 1),
								maximum_sum_path(i + 1, j)));
		total_sum = a[i][j] + current_sum;
	}

// Verificando se
// posição alcançou a última linha
	else if (i == n - 1)
		total_sum = a[i][j]
					+ maximum_sum_path(i, j + 1);

// Se a posição estiver na última coluna
	else
		total_sum = a[i][j]
					+ maximum_sum_path(i + 1, j);

	// Retornando o valor máximo atualizado
	return total_sum;
}

// Driver Code
int main()
{
	inputMatrix();

	// Chamando a função implementada
	int maximum_sum = maximum_sum_path(0, 0);

	cout << maximum_sum;
	return 0;
}
