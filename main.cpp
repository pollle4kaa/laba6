#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

//Интерфейс стратегии (контракт для всех сортировок)
class SortingStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0; //"Договор"
    virtual ~SortingStrategy() {}
};

//Пузырьковая сортировка
/*
Проходит по массиву много раз
Сравнивает пары соседних элементов
Если они в неправильном порядке - меняет местами
Сложность - O(n^2) (в худшем-среднем), O(n) (в лучшем)
*/
class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < data.size()-1; j++) {
                if (data[j] > data[j+1]) {
                    std::swap(data[j], data[j+1]);
                }
            }
        }
    }
};

//Быстрая сортировка (через std::sort)
/*
Разделяет массив на части
Сортирует каждую часть отдельно
Сложность - O(nlogn) (в лучшем-среднем), O(n^2) (в худшем)
*/

/*
//Реализация через STL
class QuickSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::sort(data.begin(), data.end());
    }
};
*/
class QuickSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        qsort(data, 0, data.size() - 1);
    }

    void qsort(std::vector<int>& data, int l, int r) {
        int i = l, j = r, p = data[(l+r) / 2];
        while (i <= j) {
            while (data[i] < p) i++;
            while (data[j] > p) j--;
            if (i <= j) std::swap(data[i++], data[j--]);
        }
        if (l < j) qsort(data, l, j);
        if (i < r) qsort(data, i, r);
    }
};

//Сортировка вставками
/*
Берет элементы по одному
Вставляет каждый в правильное место в уже отсортированной части
Сложность - O(n^2) (в худшем-среднем), O(n) (в лучшем)
*/
class InsertionSort : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        for (size_t i = 1; i < data.size(); i++) {
            int key = data[i];
            int j = i-1;
            while (j >= 0 && data[j] > key) {
                data[j+1] = data[j];
                j--;
            }
            data[j+1] = key;
        }
    }
};

//Класс, использующий стратегию
class Sorter {
    SortingStrategy* strategy;
public:
    Sorter(SortingStrategy* strategy) : strategy(strategy) {}

    void sortData(std::vector<int>& data) {
        strategy->sort(data);
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::vector<int> numbers = {4, 3, 9, 1, 4, 7};

    //Создаем стратегии
    BubbleSort bubble;
    QuickSort quick;
    InsertionSort insertion;

    //Создаем сортировщики
    Sorter bubbleSorter(&bubble);
    Sorter quickSorter(&quick);
    Sorter insertionSorter(&insertion);

    //Копируем массив
    std::vector<int> numbers1 = numbers;
    std::vector<int> numbers2 = numbers;
    std::vector<int> numbers3 = numbers;

    //Сортируем
    bubbleSorter.sortData(numbers1);
    quickSorter.sortData(numbers2);
    insertionSorter.sortData(numbers3);

    //Выводим результаты
    std::cout << "Исходный массив: ";
    for (int n : numbers) std::cout << n << " ";

    std::cout << std::endl << "Пузырьковая: ";
    for (int n : numbers1) std::cout << n << " ";

    std::cout << std::endl << "Быстрая: ";
    for (int n : numbers2) std::cout << n << " ";

    std::cout << std::endl << "Вставками: ";
    for (int n : numbers3) std::cout << n << " ";

    return 0;
}