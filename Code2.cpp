#include <iostream>

using namespace std;

// Class definition for BubbleSort
class BubbleSort {
public:
    // Constructor with initialization list to allocate memory and populate the array in descending order
    BubbleSort(int size) : size(size) {
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = size - i;
        }
    }

    // Destructor to free dynamically allocated memory
    ~BubbleSort() {
        delete[] arr;
    }

    // Bubble sort algorithm implementation
    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap arr[j] and arr[j + 1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Display the first and last 'count' elements of the array
    void displayFirstAndLast(int count) const {
        cout << "First " << count << " elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';

        cout << "Last " << count << " elements: ";
        for (int i = size - count; i < size; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }

    // Get the execution time of the sorting process
    double getExecutionTime() const {
        return executionTime;
    }

    // Measure the execution time of the sorting process
    void measureExecutionTime() {
        clock_t start = clock();
        sort();
        clock_t end = clock();

        // Calculate and store the execution time in seconds
        executionTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    }

private:
    int* arr; // Pointer to the dynamically allocated array
    int size; // Size of the array
    double executionTime; // Variable to store the execution time
};

// Main function
int main() {
    const int N = 100000;

    // Create an instance of BubbleSort with an array of size N
    BubbleSort bubbleSort(N);

    // Measure the execution time of the sorting process
    bubbleSort.measureExecutionTime();

    // Display the first and last 10 elements of the sorted array
    bubbleSort.displayFirstAndLast(10);

    // Display the execution time
    cout << "Execution Time: " << bubbleSort.getExecutionTime() << " s\n";

    return 0;
}
