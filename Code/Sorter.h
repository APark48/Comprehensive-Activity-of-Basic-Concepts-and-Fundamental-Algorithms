//USING Sorther.h provided in TC1031.
#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>

template <typename T>
class Sorter
{
    public:
    Sorter() {};
    ~Sorter() {};

    void swap(int i, int j, std::vector<T> &arr)
    {
        T aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    };

    virtual void sort(std::vector<T> &arr) {};
};

template <typename T>
class Quicksort : public Sorter<T>
{
    public:
    Quicksort() {};
    ~Quicksort() {};

    void sort(std::vector<T> &arr, bool (*compare)(T &a, T &b))
    {
        quicksort(arr, 0, arr.size() - 1, compare);
    };

    void quicksort(std::vector<T> &arr, int low, int high, bool (*compare)(T &a, T &b))
    {
        if (low < high)  
        {  
            /* pi is partitioning index, arr[p] is now  
            at right place */
            int pi = partition(arr, low, high, compare);  
      
            // Separately sort elements before  
            // partition and after partition  
            quicksort(arr, low, pi - 1, compare);  
            quicksort(arr, pi + 1, high, compare);  
        }  
    };

    /* This function takes last element as pivot, places  
    the pivot element at its correct position in sorted  
    array, and places all smaller (smaller than pivot)  
    to left of pivot and all greater elements to right  
    of pivot */
    int partition (std::vector<T> &arr, int low, int high, bool (*compare)(T &a, T &b))
    {  
        T pivot = arr[high]; // pivot  
        int i = (low - 1);     // Index of smaller element  
      
        for (int j = low; j <= high - 1; j++)  
        {  
            // If current element is smaller than the pivot  
            if ((*compare)(arr[j], pivot))  
            {  
                i++; // increment index of smaller element
                Sorter<T>::swap(i, j, arr);
            }  
        }  
        Sorter<T>::swap(i+1, high, arr);
        return (i + 1);  
    }; 
};