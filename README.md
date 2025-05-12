## ����������
��������� ���������:  
```
class SortingStrategy {
public:
    virtual void sort(std::vector<int>&) = 0;
    virtual ~SortingStrategy() = default;
};
```
���������:
BubbleSort - ����������� ����������
QuickSort - ������� ����������
InsertionSort - ���������� ���������

�������
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

## SOLID ��������
Single Responsibility:
������ ����� �������� ������ �� ���� �������� ����������
Open/Closed:
����� ��������� ����������� ��� ��������� ������������� ����
