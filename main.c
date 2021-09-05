#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
#include <locale.h>  


// Функция сортировки прямым выбором 
void selectionSort(unsigned long* num, int size)
{
    int min;
    unsigned long temp; // для поиска минимального элемента и для обмена 

    for (int i = 0; i < size - 1; i++)
    {
        min = i; // запоминаем индекс текущего элемента 
        // ищем минимальный элемент чтобы поместить на место i-ого 
        for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого 
        {
            if (num[j] < num[min]) // если элемент меньше минимального, 
                min = j;       // запоминаем его индекс в min 
        }
        temp = num[i];      // меняем местами i-ый и минимальный элементы 
        num[i] = num[min];
        num[min] = temp;
    }
}

// Функция сортировки простыми вставками 
void inclusionSort(unsigned long* num, int size)
{
    // Для всех элементов кроме начального 
    for (int i = 1; i < size; i++)
    {
        unsigned long value = num[i]; // запоминаем значение элемента 
        int index = i;     // и его индекс 
        while ((index > 0) && (num[index - 1] > value))
        {   // смещаем другие элементы к концу массива пока они меньше index 
            num[index] = num[index - 1];
            index--;    // смещаем просмотр к началу массива 
        }
        num[index] = value; // рассматриваемый элемент помещаем на освободившееся место 
    }
}

//Функция быстрой сортировки 
void quickSort(unsigned long* numbers, int left, int right)
{
    unsigned long pivot; // разрешающий элемент 
    unsigned long l_hold = left; //левая граница 
    unsigned long r_hold = right; // правая граница 

    pivot = numbers[left];

    while (left < right) // пока границы не сомкнутся 
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot] 
        if (left != right) // если границы не сомкнулись 
        {
            numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего 
            left++; // сдвигаем левую границу вправо  
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot] 
        if (left != right) // если границы не сомкнулись 
        {
            numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right] 
            right--; // сдвигаем правую границу вправо  
        }
    }

    numbers[left] = pivot; // ставим разрешающий элемент на место 
    pivot = left;
    left = l_hold;
    right = r_hold;

    if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива 
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
}



int main()
{
    unsigned long* S;
    setlocale(LC_ALL, "Russian");
    int m;
    printf("Введите размер массива: ");
    scanf_s("%d", &m);
    if ((m < 100) || (m > 100000))
    {
        printf("Error");
        exit(0);
    }


    printf("1 - Сортировка выбором\n");
    printf("2 - Сортировка простыми вставками\n");
    printf("3 - Быстрая сортировка\n");

    unsigned long* A;
    unsigned long* B;
    unsigned long* C;

    srand(time(NULL));
    clock_t t;

    A = (unsigned long*)malloc(m * sizeof(unsigned long));
    B = (unsigned long*)malloc(m * sizeof(unsigned long));
    C = (unsigned long*)malloc(m * sizeof(unsigned long));

    for (int i = 0; i < m; i++)
    {
        A[i] = (unsigned long)(rand() % 4294967295 + 100000);
        // printf("%lu ", A[i]); 
    }
    for (int i = 0; i < m; i++)
    {
        B[i] = A[i];
        C[i] = A[i];
    }

    printf("\n Результат сортировки выбором \n");
    t = clock();
    selectionSort(A, m);
    t = clock() - t;

    for (int i = 0; i < m; i++)
    {
        //printf("%lu ", A[i]); 
    }

    printf("\n Time = %f (seconds).\n", ((double)t) / CLOCKS_PER_SEC);
    free(A);

    srand(time(NULL));
    clock_t p;

    printf("\n Результат сортировки простыми вставками \n");
    p = clock();
    inclusionSort(B, m);
    p = clock() - p;

    for (int i = 0; i < m; i++)
    {
        //printf("%lu ", B[i]);
    }

    printf("\n Time = %f (seconds).\n", ((double)p) / CLOCKS_PER_SEC);
    free(B);

    srand(time(NULL));
    clock_t k;

    printf("\n Результат быстрой сортировки \n");
    k = clock();
    quickSort(C, 0, m - 1);
    k = clock() - k;

    for (int i = 0; i < m; i++)
    {
        // printf("%lu ", C[i]); 
    }

    printf("\n Time = %f (seconds).\n", ((double)k) / CLOCKS_PER_SEC);
    getchar();
    free(C);

    return 0;

}