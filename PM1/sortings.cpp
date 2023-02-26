/*
* @file sortings.cpp
* @brief файл реализации сортировок
*/
#include <iostream>
#include "lect.h"
#include "sortings.h"
#include <vector>

void bubble(std::vector<lect> &bbl, int size)
{
    if (size <= bbl.size())
    {
        lect x;
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j > i; j--)
            {
                if (bbl[j - 1] > bbl[j])
                {
                    x = bbl[j - 1];
                    bbl[j - 1] = bbl[j];
                    bbl[j] = x;
                }
            }
        }
    }
}


void quickSort(std::vector<lect>& qwk, int low, int high)
{

    int i = low;
    int j = high;
    lect x;
    lect p = qwk[(i + j) / 2];
    while (i <= j)
    {
        while (qwk[i] < p)
            i++;
        while (qwk[j] > p)
            j--;
        if (i <= j)
        {
            x = qwk[i];
            qwk[i] = qwk[j];
            qwk[j] = x;
            i++;
            j--;
        }
    }

    if (j > low)
        quickSort(qwk, low, j);
    if (i < high)
        quickSort(qwk, i, high);


}

void merge(std::vector<lect>& array, int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

   
    std::vector<lect> leftArray;
    std::vector<lect> rightArray;
    for (auto i = 0; i < subArrayOne; i++) leftArray.push_back(array[left + i]);
    for (auto j = 0; j < subArrayTwo; j++) rightArray.push_back(array[mid + 1 + j]);

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    leftArray.clear();
    rightArray.clear();
}


void mergeSort(std::vector<lect>& array, int const begin, int const end)
{
    if (begin >= end)
        return; 

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);

}