/*
* @file main.cpp
* @brief main-файл
*/
#include <iostream>
#include "lect.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "sortings.h"
#include <chrono>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    std::vector<lect> data(100000);
    int i = 0;

    std::ifstream file("Array.txt");

    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            std::string l_name1, l_name2, l_name3, l_fac, l_degree, l_title1, l_title2;
            std::istringstream iss(line);  // поток для считывания данных из строчки
            iss >> l_name1 >> l_name2 >> l_name3 >> l_fac >> l_degree >> l_title1 >> l_title2;
            std::string l_name = l_name1 + " " + l_name2 + " " + l_name3;
            std::string l_title = l_title1 + " " + l_title2;
            data[i].setData(l_name, l_fac, l_degree, l_title);
            i++;
        }
    }
    else { std::cout << "не удалось открыть файл Array.txt"; }

    int data_size=0;
  /////////////////////////////// Подсчёт времени сортировки 100, 500, 1000, 2500, 5000, 10000, 20000,40000, 80000 и 100000 строк таблицы
    
    /*
    int data_sizes[10] = { 100, 500, 1000, 2500, 5000, 10000, 20000,40000, 80000, 100000 };
    auto start = chrono::steady_clock::now();
    auto end = chrono::steady_clock::now();

   
    for (int i = 0; i < 10; i++)
    {
        data_size = data_sizes[i];

        std::vector<lect> bbl;
        int q = 0;
        while (bbl.size() != data_size)
        {
            bbl.push_back(data[q]);
            q += 1;
        }

        start= chrono::steady_clock::now();
        bubble(bbl, data_size);
        end=chrono::steady_clock::now();
        cout << "Bubble, size "<<data_size<<" :" << '\n' << "Elapsed time in milliseconds : "
            << chrono::duration_cast<chrono::milliseconds>(end - start).count()
            << " ms" << '\n' << '\n';
    }
    for (int i = 0; i < 10; i++)
    {
        data_size = data_sizes[i];

        std::vector<lect> qwk;
        int q = 0;
        while (qwk.size() != data_size)
        {
            qwk.push_back(data[q]);
            q += 1;
        }

        start = chrono::steady_clock::now();
        quickSort(qwk, 0, data_size - 1);
        end = chrono::steady_clock::now();
        cout << "Quick sorting, size " << data_size << " :" << '\n' << "Elapsed time in milliseconds : "
            << chrono::duration_cast<chrono::milliseconds>(end - start).count()
            << " ms" << '\n' << '\n';
    }
    for (int i = 0; i < 10; i++)
    {
        data_size = data_sizes[i];

        std::vector<lect> merge;
        int q = 0;
        while (merge.size() != data_size)
        {
            merge.push_back(data[q]);
            q += 1;
        }

        start = chrono::steady_clock::now();
        mergeSort(merge, 0, merge.size() - 1);
        end = chrono::steady_clock::now();
        cout << "Merge sorting, size " << data_size << " :" << '\n' << "Elapsed time in milliseconds : "
            << chrono::duration_cast<chrono::milliseconds>(end - start).count()
            << " ms" << '\n' << '\n';
    }*/

    
    
    //////////////////////////// Запись в файл

    data_size = 1000;

   std::vector<lect> qwk;
   int q = 0;
   while (qwk.size() != data_size)
   {
       qwk.push_back(data[q]);
       q += 1;
   }
   std::vector<lect> merge = qwk;
   std::vector<lect> bbl = qwk;
   
   bubble(bbl, bbl.size());
    std::ofstream outf{"bubble.txt"};
    for (int i = 0; i < bbl.size(); i++)
    {
        outf << bbl[i].getFac() << '\t' << bbl[i].getName() << '\t' << bbl[i].getDegree() << '\t' << bbl[i].getTitle() << '\n';
    }
    outf.close();

    quickSort(qwk, 0, data_size - 1);

    std::ofstream outf1{ "quick.txt" };
    for (int i = 0; i < qwk.size(); i++)
    {
        outf1 << qwk[i].getFac() << '\t' << qwk[i].getName() << '\t' << qwk[i].getDegree() << '\t' << qwk[i].getTitle() << '\n';
    }
    outf1.close();

    mergeSort(merge, 0, merge.size() - 1);

    std::ofstream outf2{ "merge.txt" };
    for (int i = 0; i < merge.size(); i++)
    {
        outf2 << merge[i].getFac() << '\t' << merge[i].getName() << '\t' << merge[i].getDegree() << '\t' << merge[i].getTitle() << '\n';
    }
    outf2.close();

    return 0;
}
