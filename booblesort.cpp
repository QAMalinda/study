#include <iostream>

void BubbleSort(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Обмен значений, если текущий элемент больше следующего
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // Если на текущей итерации не было обмена, то массив уже отсортирован
        if (!swapped) {
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    int begin = 0;
    int end = 10;

    const int SIZE = 10;
    int array[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        array[i] = begin + rand() % (end + 1);
    }
    BubbleSort(array, SIZE);
    for (int i = 0; i < SIZE; ++i) {
        std::cout << array[i]<<" " ;
    }

    return 0;
}