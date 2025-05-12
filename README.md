## Реализация
Интерфейс стратегии:  
```
class SortingStrategy {
public:
    virtual void sort(std::vector<int>&) = 0;
    virtual ~SortingStrategy() = default;
};
```
Стратегии:
BubbleSort - пузырьковая сортировка
QuickSort - быстрая сортировка
InsertionSort - сортировка вставками

Обертка
```
class Sorter {
    SortingStrategy* strategy;
public:
    Sorter(SortingStrategy* s) : strategy(s) {}
    void sortData(std::vector<int>& data) {
        strategy->sort(data);
    }
};
```

## SOLID принципы
Single Responsibility:
Каждый класс отвечает только за один алгоритм сортировки
Open/Closed:
Новые стратегии добавляются без изменения существующего кода
