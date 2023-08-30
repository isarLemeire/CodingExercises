#include <iostream>
#include <random>

using namespace std;

void exchange(int list[], int i, int j){
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

void printList(int list[], int size){
    for (int i = 0; i < size; ++i) {
        cout << " " << list[i];
    }
    cout << endl;
}

void insertionSort(int list[], int size){
	for(int i = 1; i < size; i++){
		int key = list[i]; 
		int j = i - 1;
		while(j >= 0 && list[j] > key){
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = key;
	}
}

void merge(int arr[], int p, int q, int r){
// 0, 5, 10

    int leftSize = q - p + 2;
    int rightSize = r - q + 1;
    int left[leftSize];
    int right[rightSize];

    for(int i = 0; i < leftSize; i++){
        left[i] = arr[p + i];
    }
    
    for(int i = 0; i < rightSize; i++){
        right[i] = arr[q + 1 + i];
    }
    left[leftSize - 1] = INT32_MAX; // Use INT_MAX as the sentinel value
    right[rightSize - 1] = INT32_MAX;

    int i = 0;
    int j = 0;
    for(int k = p; k <= r; k++){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
    }
}

void mergeSort(int* list, int p, int r){
    if(p >= r){
        return;
    }
    int q = p + (r - p)/2;
    mergeSort(list, p, q);
    mergeSort(list, q + 1, r);
    merge(list, p, q, r);
}

int parent(int i){
    return i/2;
}

int left(int i){
    return 2*i;
}

int right(int i){
    return 2*i + 1;
}

void maxHeapify(int list[], int size, int i){
    int largest = i;
    int l = left(i);
    int r = right(i);
    if(l < size){
        if(list[l] > list[largest]){
            largest = l;
        }
    }
    if(r < size){
        if(list[r] > list[largest]){
            largest = r;
        }
    }
    if(i != largest){
        exchange(list, largest, i);
        maxHeapify(list, size, largest);
    }
}

void BuildMaxHeap(int list[], int size){
    for(int i = size/2; i >= 0 ; i--){
        maxHeapify(list, size, i);
    }
}

void heapSort(int list[], int size){
    BuildMaxHeap(list, size);
    for(int i = size - 1; i >= 0; i--){
        exchange(list, 0, i);
        maxHeapify(list, i, 0);
        printList(list, size);
    }
}

int partition(int list[], int p, int r){
    int pivot = list[r];
    int i = p - 1;
    for(int j = p; j < r ; j++){
        if(list[j] < pivot){
            i++;
            exchange(list, i, j);
        }
    }
    exchange(list, i+1, r);
    return i + 1;
}

void quickSort(int list[], int p, int r){
    if(p < r){
        int q = partition(list, p, r);
        quickSort(list, p, q-1);
        quickSort(list, q+1, r);
    }
}

int maximum(int list[], int size){
    int largest = INT32_MIN;
    for (int i = 0; i < size; i++)
    {
        if(largest < list[i]){
            largest = list[i];
        }
    }
    return largest;
}

void countSort(int list[], int size){
    int m = maximum(list, size) + 1;
    
    int B[m];
    int temp[size];
    for(int i = 0; i < m; i++){
        B[i] = 0;
    }
    for(int i = 0; i < size; i++){
        temp[i] = list[i];
        B[temp[i]]++;
    }
    for(int i = 1; i < m; i++){
        B[i] = B[i] + B[i - 1];
    }
    for(int i = 0; i < size; i++){
        list[B[temp[i]] - 1] = temp[i];
        B[temp[i]]--;
    }
}

int select(int list[], int p, int r, int i){
    if(p == r)
        return list[p];
    int q = partition(list, p, r);
    if(q == i) 
        return list[q];
    if(i < q){
        return select(list, p, q - 1, i);
    } else{
        return select(list, q+1, r, i - (q + 1 - p));
    }
}


int main() {

    const int numIntegers = 10; // Number of random integers you want to generate
    int randomIntegers[numIntegers];

    for (int i = 0; i < numIntegers; ++i) {
        randomIntegers[i] = rand() % 100 + 1; // Generates integers between 1 and 100
    }

    cout << endl;
    cout << "Random Integers:";
    printList(randomIntegers, numIntegers);
    cout << endl;

    countSort(randomIntegers, numIntegers);

    cout << "Random Sorted Integers:";
    printList(randomIntegers, numIntegers);
    cout << endl;
    
	return 0;
}