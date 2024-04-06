#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL; // isso significa que este e o primeiro/ultimo elemento da lista e ele e um ponteiro

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
void inserirElementoRecursivo(NO* atual, NO* novo);
//--------------------------

int main()
{
	menu();
}

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
	// se a lista j� possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);

	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

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


/*
A função inserirElementoRecursivo é responsável por inserir um novo elemento em uma lista ligada de forma recursiva.

A função recebe dois parâmetros: atual, que representa o nó atual da lista, e novo, que é o novo nó a ser inserido.
A função verifica se o próximo nó do nó atual é nulo. Se for nulo, significa que o nó atual é o último nó da lista.
Se o próximo nó for nulo, o ponteiro prox do nó atual é atualizado para apontar para o novo nó, inserindo-o no final da lista.
Caso contrário, se o próximo nó não for nulo, a função chama a si mesma recursivamente, passando o próximo nó como o novo nó atual.
Isso permite percorrer a lista até encontrar o último nó.
O processo de verificação e inserção é repetido até que o último nó seja encontrado e o novo nó seja inserido no final da lista.
Essa função é utilizada pela função inserirElemento, que aloca dinamicamente memória para um novo nó,
solicita ao usuário o valor do elemento a ser inserido e, em seguida, chama a função inserirElementoRecursivo para inserir o novo nó na lista ligada.
Se a lista estiver vazia, o novo nó se torna o primeiro nó da lista.*/
  
void inserirElementoRecursivo(NO* atual, NO* novo)
{
	if (atual->prox == NULL)
	{
		atual->prox = novo;
	}
	else
	{
		inserirElementoRecursivo(atual->prox, novo); 
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO)); // aloca memória para o novo elemento
	if (novo == NULL) // teste de erro - memoria insuficiente
	{
		return;
	}

	cout << "Digite o elemento: "; // solicita ao usuário que digite o valor do elemento
	cin >> novo->valor; // atribui o valor digitado ao novo elemento
	novo->prox = NULL; // atualiza o ponteiro prox do novo nó para nulo

	if (primeiro == NULL) //se a lista esta vazia
	{
		primeiro = novo; // entao primeiro recebe o novo elemento
	}
	else
	{
		inserirElementoRecursivo(primeiro, novo);
	}
}

/* void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL) // teste de erro - memoria insuficiente
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL) //se a lista esta vazia
	{
		primeiro = novo;// entao primeiro 
	}
	else
	{
		// procura o final da lista
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo; 
	}
} */

void excluirElemento()
{

}

void buscarElemento()
{

}


