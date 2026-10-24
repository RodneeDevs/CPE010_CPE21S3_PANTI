#include <iostream>
#include <vector>
#include <thread>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    while (j <= right) {
        temp.push_back(arr[j++]);
    }

    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

void parallelMergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    std::thread leftThread(parallelMergeSort, std::ref(arr), left, mid);
    std::thread rightThread(parallelMergeSort, std::ref(arr), mid + 1, right);

    leftThread.join();
    rightThread.join();

    merge(arr, left, mid, right);
}

int main() {
    std::vector<int> arr = {117, 4859, 7, 1204, 40000};

    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    parallelMergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}