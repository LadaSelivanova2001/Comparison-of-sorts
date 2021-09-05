#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
#include <locale.h>  


// ������� ���������� ������ ������� 
void selectionSort(unsigned long* num, int size)
{
    int min;
    unsigned long temp; // ��� ������ ������������ �������� � ��� ������ 

    for (int i = 0; i < size - 1; i++)
    {
        min = i; // ���������� ������ �������� �������� 
        // ���� ����������� ������� ����� ��������� �� ����� i-��� 
        for (int j = i + 1; j < size; j++)  // ��� ��������� ��������� ����� i-��� 
        {
            if (num[j] < num[min]) // ���� ������� ������ ������������, 
                min = j;       // ���������� ��� ������ � min 
        }
        temp = num[i];      // ������ ������� i-�� � ����������� �������� 
        num[i] = num[min];
        num[min] = temp;
    }
}

// ������� ���������� �������� ��������� 
void inclusionSort(unsigned long* num, int size)
{
    // ��� ���� ��������� ����� ���������� 
    for (int i = 1; i < size; i++)
    {
        unsigned long value = num[i]; // ���������� �������� �������� 
        int index = i;     // � ��� ������ 
        while ((index > 0) && (num[index - 1] > value))
        {   // ������� ������ �������� � ����� ������� ���� ��� ������ index 
            num[index] = num[index - 1];
            index--;    // ������� �������� � ������ ������� 
        }
        num[index] = value; // ��������������� ������� �������� �� �������������� ����� 
    }
}

//������� ������� ���������� 
void quickSort(unsigned long* numbers, int left, int right)
{
    unsigned long pivot; // ����������� ������� 
    unsigned long l_hold = left; //����� ������� 
    unsigned long r_hold = right; // ������ ������� 

    pivot = numbers[left];

    while (left < right) // ���� ������� �� ��������� 
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--; // �������� ������ ������� ���� ������� [right] ������ [pivot] 
        if (left != right) // ���� ������� �� ���������� 
        {
            numbers[left] = numbers[right]; // ���������� ������� [right] �� ����� ������������ 
            left++; // �������� ����� ������� ������  
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++; // �������� ����� ������� ���� ������� [left] ������ [pivot] 
        if (left != right) // ���� ������� �� ���������� 
        {
            numbers[right] = numbers[left]; // ���������� ������� [left] �� ����� [right] 
            right--; // �������� ������ ������� ������  
        }
    }

    numbers[left] = pivot; // ������ ����������� ������� �� ����� 
    pivot = left;
    left = l_hold;
    right = r_hold;

    if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� ������� 
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
}



int main()
{
    unsigned long* S;
    setlocale(LC_ALL, "Russian");
    int m;
    printf("������� ������ �������: ");
    scanf_s("%d", &m);
    if ((m < 100) || (m > 100000))
    {
        printf("Error");
        exit(0);
    }


    printf("1 - ���������� �������\n");
    printf("2 - ���������� �������� ���������\n");
    printf("3 - ������� ����������\n");

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

    printf("\n ��������� ���������� ������� \n");
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

    printf("\n ��������� ���������� �������� ��������� \n");
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

    printf("\n ��������� ������� ���������� \n");
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