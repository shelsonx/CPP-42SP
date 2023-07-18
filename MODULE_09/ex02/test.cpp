#include <iostream>
#include <vector>

// Função para mesclar duas sublistas ordenadas
void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // Copia os elementos para as sublistas temporárias
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    // Mescla as sublistas ordenadamente
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes da primeira sublista, se houver
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copia os elementos restantes da segunda sublista, se houver
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Função de ordenação Merge Insert Sort
void mergeInsertSort(std::vector<int>& arr, int left, int right, int threshold) {
    if (left < right) {
        // Verifica se a lista é pequena o suficiente para usar o Insertion Sort
        if (right - left <= threshold) {
            for (int i = left + 1; i <= right; i++) {
                int key = arr[i];
                int j = i - 1;
                while (j >= left && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }
        } else {
            int middle = left + (right - left) / 2;
            mergeInsertSort(arr, left, middle, threshold);
            mergeInsertSort(arr, middle + 1, right, threshold);
            merge(arr, left, middle, right);
        }
    }
}

// Função auxiliar para chamar o Merge Insert Sort
void mergeInsertionSort(std::vector<int>& arr, int threshold) {
    mergeInsertSort(arr, 0, arr.size() - 1, threshold);
}

// Função para exibir um vetor
void printVector(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {9, 2, 7, 4, 5, 1, 8, 3, 6};
    int threshold = 5;

    std::cout << "Array antes da ordenação: ";
    printVector(arr);

    mergeInsertionSort(arr, threshold);

    std::cout << "Array após a ordenação: ";
    printVector(arr);

    return 0;
}
