#include <iostream>
#include <chrono>


bool Unique(const int A[], int n, long long& op_count) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n-1; j++) {
            op_count ++;
            if (A[i] == A[j]) {
                return false;
            }
        }
    }
    return true;
}


void benchmark_unique(int n) {
    // Generate worst-case array (all distinct values)
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }


    long long op_count = 0;


    // Start timer
    auto start = std::chrono::high_resolution_clock::now();
   
    Unique(arr, n, op_count);
   
    // Stop timer
    auto end = std::chrono::high_resolution_clock::now();
    double time_ms = std::chrono::duration(end - start).count();


    std::cout << "N = " << n
              << "\t Operations = " << op_count
              << "\t Time = " << time_ms << " ms" << std::endl;


    delete[] arr;
}


int main() {
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {1, 3, 5, 7, 9};


    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);


    // Doubling input sizes to evaluate scaling ratio
    benchmark_unique(1000);
    benchmark_unique(2000);
    benchmark_unique(4000);
    benchmark_unique(8000);
    benchmark_unique(16000);


    return 0;
}
