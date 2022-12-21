#include <stdio.h>
#include <time.h>
#define TAM 100000

#include <stdio.h>
#include <stdlib.h>

#define NARRAY 100000   // tamanho do Array 
#define NBUCKET 100  // Numero de baldes
#define INTERVAL 10000  // capacidade de cada balde

struct Node {
  int data;
  struct Node *next;
};

void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node *list);
int getBucketIndex(int value);

// funcao de ordenacao
void BucketSort(int arr[]) {
  int i, j;
  struct Node **buckets;

  // cria baldes e aloca memoria
  buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);

  // inicializa baldes vazios
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = NULL;
  }

  // enche os baldes com elementos 
  for (i = 0; i < NARRAY; ++i) {
    struct Node *current;
    int pos = getBucketIndex(arr[i]);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }


  // ordena os elementos em cada balde
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = InsertionSort(buckets[i]);
  }


  // coloca os elementos ordenados no array
  for (j = 0, i = 0; i < NBUCKET; ++i) {
    struct Node *node;
    node = buckets[i];
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  return;
}

// funcao para ordenar os elementos de cada balde
struct Node *InsertionSort(struct Node *list) {
  struct Node *k, *nodeList;
  if (list == 0 || list->next == 0) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = 0;
  while (k != 0) {
    struct Node *ptr;
    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != 0) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }
  return nodeList;
}

int getBucketIndex(int value) {
  return value / INTERVAL;
}

void print(int ar[]) {
  int i;
  for (i = 0; i < NARRAY; ++i) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}





 // Printa um array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


 void main(){
	int vetor[TAM];

	int x=0;

	for(int i = TAM; i != 0; i--){
        vetor[x] = i;
        x++;
	}

//CASO 1

clock_t t;

t = clock();
BucketSort(vetor);
t = clock() - t;
printf("Caso 1 \n");
printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC)));
printf("\n \n");


//CASO 2

int vetor2[TAM];


	for(int i = 0; i < TAM; i++){
        vetor2[i] = i+1;
	}


clock_t t2;

t2 = clock();
BucketSort(vetor2);
t2 = clock() - t2;
printf("Caso 2 \n");
printf("Tempo de execucao: %lf", ((double)t2)/((CLOCKS_PER_SEC)));
printf("\n \n");

int vetor3[TAM];
	x=TAM/2;

	for(int i = 0; i < TAM/2; i++){
        vetor3[i] = i+1;
	}
	for(int i = TAM; i != TAM/2; i--){
        vetor3[x] = i;
        x++;
	}

//CASO 3

clock_t t3;

t3 = clock();
BucketSort(vetor3);
t3 = clock() - t3;
printf("Caso 3 \n");
printf("Tempo de execucao: %lf", ((double)t3)/((CLOCKS_PER_SEC)));
printf("\n \n");



int vetor4[TAM];
	x=0;

	for(int i = TAM/2; i != 0; i--){
        vetor4[x] = i;
        x++;
	}

	for(int i = TAM/2; i < TAM; i++){
        vetor4[i] = i+1;
	}

//CASO 4

clock_t t4;

t4 = clock();
BucketSort(vetor4);
t4 = clock() - t4;
printf("Caso 4 \n");
printf("Tempo de execucao: %lf", ((double)t4)/((CLOCKS_PER_SEC)));
printf("\n \n");


//CASO 5

int vetor5[TAM];
	srand(time(NULL));


	for(int i = 0; i < TAM; i++){
        vetor5[i] = rand();
	}

clock_t t5;

t5 = clock();
BucketSort(vetor5);
t5 = clock() - t5;
printf("Caso 5 \n");
printf("Tempo de execucao: %lf", ((double)t5)/((CLOCKS_PER_SEC)));
printf("\n \n");

}
