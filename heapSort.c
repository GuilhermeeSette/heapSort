#include <iostream>
using namespace std;

//HeapSort

//Função que coloca o maior elemento do array no indice 0
void maiorRoot(int max_H[], int n, int i) {
  int maior = i; //Máximo do Heap
  int left_c = 2 * i + 1; //Filho esquerdo
  int right_c = 2 * i + 2; //Filho direito


  // Se o filho esquerdo é maior que o elemento root, então o filho esquerdo é o novo maior
  if(left_c < n && max_H[left_c] > max_H[maior]){
    maior = left_c;
  }

  // Se o filho direito é maior que o elemento root, então o filho direito é o novo maior
  else if(left_c < n && max_H[left_c] > max_H[maior]){
    maior = left_c;
  }

  if (maior != i) {
    swap(max_H[i],max_H[maior]);

    maiorRoot(max_H, n, maior)
  }

}

//Função que executa o HeapSort
void HeapSort(int heap[], int n) {

  //Constroi um heap
  for (int i = n/2-1;i>=0;i--) {
    maiorRoot(heap, n, i);
  }

  for (int i = n-1; i>=0; i--) {
    //Move o root atual para o final
    swap(heap[0],heap[i]);

    //Chama o maiorRoot para o heap reduzido
    maiorRoot(heap, n, 0);
  }

}

// Printa o Array
void printHeap(int heap[], int n) {
  for(int i=0; i<n; i++){
    cout << heap[i] << " ";
  }
  cout << "\n";
}

int main(int argc, char const *argv[]) {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr)/sizeof(arr[0]);

  heapSort(arr, n);

  cout << "Sorted array is \n";
  printArray(arr, n);
  //return 0;
}
