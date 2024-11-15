#include <iostream>
#include <chrono>
#include <algorithm>
#include "linkedList.h"





template <typename E>
void radixSort(LinkedList<E>& list, int base) {
    // Usar el método getMax de LinkedList para obtener el valor máximo
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
    int size, base;
    char repeat;

    
    std::cout << "Ingrese el tamaño de la lista a ordenar: ";
    std::cin >> size;
    std::cout << "Ingrese la base numérica a utilizar en el ordenamiento: ";
    std::cin >> base;

    // Crear lista de enteros aleatorios usando LinkedList
    LinkedList<int> list;
    for (int i = 0; i < size; i++) {
        list.append(rand() % 1000); // Ejemplo: números aleatorios de 0 a 999
    }

    std::cout << "Lista antes del ordenamiento:\n";
    list.print();

    // Medir tiempo de ejecución del ordenamiento
    auto start = std::chrono::high_resolution_clock::now();
    radixSort(list, base);
    auto end = std::chrono::high_resolution_clock::now();

    // Calcular tiempo transcurrido
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tiempo de ordenamiento: " << duration.count() << " segundos\n";

    std::cout << "Lista después del ordenamiento:\n";
    list.print();

    std::cin >> repeat;

    

    return 0;
}