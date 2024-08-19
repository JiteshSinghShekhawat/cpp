#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        if (pi - low > 20) sort(arr, low, pi - 1);
        else insertionSort(arr, low, pi - 1);
        if (high - pi > 20) sort(arr, pi + 1, high);
        else insertionSort(arr, pi + 1, high);
    }
}

int main() {
    const int SIZE = 1e7;
    vector<int> large_array(SIZE);
    srand(time(0));

    for (int i = 0; i < SIZE; ++i) {
        large_array[i] = rand() % 1000000;
    }

    vector<int> temp = large_array;

    auto start = chrono::high_resolution_clock::now();
    sort(large_array, 0, SIZE - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_custom_sort = end - start;

    auto start_std_sort = chrono::high_resolution_clock::now();
    sort(temp.begin(), temp.end());
    auto end_std_sort = chrono::high_resolution_clock::now();
    chrono::duration<double> duration_std_sort = end_std_sort - start_std_sort;

    cout << "Time taken in custom sort: " << duration_custom_sort.count() << " seconds" << endl;
    cout << "Time taken in std::sort: " << duration_std_sort.count() << " seconds" << endl;
 
    for(int i = 0 ; i < SIZE ; i++ ) {
        if(large_array[i] != temp[i]){
            cout<<"NO";
            return 1;
        }
    }
    return 0;
}
