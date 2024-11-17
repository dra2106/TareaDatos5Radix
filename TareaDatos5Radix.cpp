#include <iostream>
#include <chrono>
#include <algorithm>
#include "linkedList.h"





template <typename E>
void radixSort(LinkedList<E>& list, int base) {
    E maxVal = list.getMax();
    int exp = 1;

    while (maxVal / exp > 0) {
        LinkedList<E>* buckets = new LinkedList<E>[base];

        list.goToStart();
        for (int i = 0; i < list.getSize(); i++) {
            int bucketIndex = (list.getElement() / exp) % base;
            buckets[bucketIndex].append(list.getElement());
            list.next();
        }

        list.clear();
        for (int i = 0; i < base; i++) {
            buckets[i].goToStart();
            for (int j = 0; j < buckets[i].getSize(); j++) {
                list.append(buckets[i].getElement());
                buckets[i].next();
            }
        }

        delete[] buckets;
        exp *= base;
    }
}

int main() {
    int size; 
    int base;
    char repeat;

    while (true)
    {
        std::cout << "Insertar tamaño ordenamiento: ";
        std::cin >> size;
        std::cout << "Insertar base numerica: ";
        std::cin >> base;
        if (size > 1 && base > 1 && base <20 && size < 1000000) {
            break;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore();
            system("cls");
        }

    }
    

    LinkedList<int> list;
    for (int i = 0; i < size; i++) {
        list.append(rand() % 1000);
    }

    std::cout << "Lista antes del ordenamiento:\n";
    //list.print();


    auto start = std::chrono::high_resolution_clock::now();
    radixSort(list, base);
    auto end = std::chrono::high_resolution_clock::now();

    

    std::cout << "Lista después del ordenamiento:\n";
    //list.print();
    std::chrono::duration<double> duration = end - start;
    if (duration.count()<0.0001) {
        std::cout << "Tiempo de ordenamiento: " << "0" << " segundos\n";
    }
    else
    {
        std::cout << "Tiempo de ordenamiento: " << duration.count() << " segundos\n";
    }
    
   
    

    return 0;
}