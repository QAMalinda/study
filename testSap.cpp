#include <iostream>

int main() {
    int n;
    std::cout << "Введите количество элементов в массиве: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int negativeEvenSum = 0;
    int negativeEvenCount = 0;
    int maxNegativeEven = -1;
    int minNegativeEven = 0;

    for (int i = 0; i < n; i += 2) {
        if (arr[i] < 0) {
            negativeEvenSum += arr[i];
            negativeEvenCount++;
            if (arr[i] > maxNegativeEven || maxNegativeEven == -1) {
                maxNegativeEven = arr[i];
            }
            if (arr[i] < minNegativeEven || minNegativeEven == 0) {
                minNegativeEven = arr[i];
            }
        }
    }
    std::cout << "Наибольшее значение отрицательных элементов с четными индексами: " << maxNegativeEven << std::endl;
    std::cout << "Наименьшее значение отрицательных элементов с четными индексами: " << minNegativeEven << std::endl;
    double average = 0;
    int counter = 0;

    for ( int i = 0; i < n; i++ ) {

        if ( i % 2 == 0 ) {
            average += arr[i];
            counter += 1;
        }
    }
    average /= counter;
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= 0) {
            arr[i] = average;
        }
    }

    std::cout << "Среднее арифметическое отрицательных элементов с четными индексами: " << average << std::endl;

    std::cout << "Итоговый массив:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
