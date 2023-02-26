#pragma once
#include <string>
#include "lect.h"
#include <vector>

/** @brief Сортировка пузырьком
*  @param vector<lect>
*  @param int
*/
void bubble(std::vector<lect> &bbl, int size);
/** @brief Быстрая сортировка
*  @param vector<lect>
*  @param int
*  @param int
*  @param int
*/
void quickSort(std::vector<lect>& qwk, int low, int high);
/** @brief Подметод сортировки слиянием(объявлен для рекурсии)
*  @param vector<lect>
*  @param int
*  @param int
*  @param int
*/
void merge(std::vector<lect>& array, int const left, int const mid, int const right);
/** @brief Сортировка слиянием
*  @param vector<lect>
*  @param int
*  @param int
*/
void mergeSort(std::vector<lect>& array, int const begin, int const end);