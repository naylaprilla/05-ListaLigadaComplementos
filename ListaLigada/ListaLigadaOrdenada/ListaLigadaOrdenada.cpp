

#include <iostream> //	cout, cin
using namespace std; // somente para simplificar o codigo

// definicao de tipo
struct NO {
	int valor; // valor do elemento
	NO* prox; // referencia para o proximo elemento
};

// isso significa que este e o primeiro elemento da lista
NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

// Função principal
int main()
{
	menu();
}

// Inicializa a lista
void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	NO* aux = primeiro; // referencia para o primeiro elemento da lista
	while (aux != NULL) { // percorre a lista
		NO* paraExcluir = aux; // guarda a referencia para o elemento a ser excluido
		aux = aux->prox; // guarda a referencia para o proximo elemento
		free(paraExcluir); // libera a memoria alocada para o elemento
	}

	primeiro = NULL; // inicializa a lista
	cout << "Lista inicializada \n";

}

// Exibe a quantidade de elementos da lista
void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}


/* Essa função é responsável por inserir um novo elemento na lista ligada ordenada.
 -Ela solicita ao usuário que digite o valor do elemento a ser inserido.
 -Em seguida, aloca dinamicamente memória para o novo elemento e atribui o valor digitado a ele.
 -Caso a lista esteja vazia, o novo elemento se torna o primeiro da lista.
 -Caso contrário, o novo elemento é inserido em sua posição correta na lista, mantendo a ordem crescente.
 -Se o valor do novo elemento for menor que o valor do primeiro elemento da lista, o novo elemento se torna o primeiro.
 -Caso contrário, a função percorre a lista até encontrar a posição correta para inserir o novo elemento.
 -Se o valor do novo elemento já existir na lista, a função exibe uma mensagem de erro e libera a memória alocada para o novo elemento. */

void inserirElemento()
{
	NO* novo = (NO*)malloc(sizeof(NO)); // aloca memória para o novo elemento
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor; // solicita ao usuário que digite o valor do elemento

	novo->prox = NULL;

	if (primeiro == NULL) // se a lista estiver vazia, o novo elemento se torna o primeiro
	{
		primeiro = novo;
	}
	else if (novo->valor < primeiro->valor) // se o valor do novo elemento for menor que o valor do primeiro elemento da lista, o novo elemento se torna o primeiro
	{
		novo->prox = primeiro;
		primeiro = novo;
	}
	else // caso contrário, percorre a lista até encontrar a posição correta para inserir o novo elemento
	{
		NO* anterior = primeiro;
		NO* atual = primeiro->prox;

		while (atual != NULL && novo->valor > atual->valor)
		{
			anterior = atual;
			atual = atual->prox;
		}

		if (atual != NULL && novo->valor == atual->valor) // se o valor do novo elemento já existir na lista, exibe uma mensagem de erro 
		{
			cout << "Elemento duplicado. Não é possível inserir." << endl;
			free(novo); //e libera a memória alocada para o novo elemento
			return;
		}

		anterior->prox = novo; // insere o novo elemento na posição correta
		novo->prox = atual; // insere o novo elemento na posição correta
	}
}

/*  Essa função é responsável por excluir um elemento da lista ligada ordenada.
 -Ela solicita ao usuário que digite o valor do elemento a ser excluído.
 -Em seguida, percorre a lista até encontrar o elemento ou um elemento maior.
 -Se o elemento não for encontrado, a função exibe uma mensagem de erro.
 -Caso contrário, a função exclui o elemento da lista e libera a memória alocada para ele.
 -Se o elemento a ser excluído for o primeiro da lista, o próximo elemento se torna o primeiro.
 -Caso contrário, o elemento é excluído do meio ou do final da lista. */
void excluirElemento()
{
	if (primeiro == NULL) // verifica se a lista está vazia
	{
		cout << "Lista vazia. Nenhum elemento para excluir." << endl;
		return;
	}

	int valor;
	cout << "Digite o valor do elemento a ser excluído: ";
	cin >> valor;

	NO* anterior = NULL;
	NO* atual = primeiro;

	while (atual != NULL && atual->valor < valor) // percorre a lista até encontrar o elemento ou um elemento maior
	{
		anterior = atual;
		atual = atual->prox;
	}

	if (atual == NULL || atual->valor > valor) // verifica se o elemento não foi encontrado
	{
		cout << "Elemento não encontrado." << endl;
		return;
	}

	if (anterior == NULL) // se o elemento a ser excluído for o primeiro da lista
	{
		primeiro = atual->prox;
	}
	else // se o elemento a ser excluído estiver no meio ou no final da lista
	{
		anterior->prox = atual->prox;
	}

	free(atual); // libera a memória alocada para o elemento excluído
}

/*  Essa função é responsável por buscar um elemento na lista ligada ordenada.
 -Ela solicita ao usuário que digite o valor do elemento a ser buscado.
 -Em seguida, percorre a lista até encontrar o elemento ou um elemento maior.
 -Se o elemento não for encontrado, a função exibe uma mensagem de erro.
 -Caso contrário, a função exibe uma mensagem de sucesso. */

void buscarElemento()
{
	if (primeiro == NULL) // verifica se a lista está vazia
	{
		cout << "Lista vazia. Nenhum elemento para buscar." << endl;
		return;
	}

	int valor;
	cout << "Digite o valor do elemento a ser buscado: ";
	cin >> valor;

	NO* atual = primeiro;

	while (atual != NULL && atual->valor < valor) // percorre a lista até encontrar o elemento ou um elemento maior
	{
		atual = atual->prox;
	}

	if (atual == NULL || atual->valor > valor) // verifica se o elemento não foi encontrado
	{
		cout << "Elemento não encontrado." << endl;
		return;
	}

	cout << "Elemento encontrado." << endl;
}


