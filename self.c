/*
 * Студент: Пылинский Даниил Максимович
 * Группа: ПИ 1-1
 * Лабораторная работа № 9
 * Назначение: Самостоятельная работа. Расчёт сумм столбцов и поиск первой строки с минимальной суммой
 */

#include <stdio.h>
#define LIMIT 5

int main(void)
{
    int a[LIMIT][LIMIT];
    int rows, cols;

    printf("Enter rows and cols (1..5): ");
    if (scanf("%d %d", &rows, &cols) != 2) {
        printf("Input error\n");
        return 1;
    }
    if (rows < 1 || rows > LIMIT || cols < 1 || cols > LIMIT) {
        printf("Size error\n");
        return 1;
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (scanf("%d", &a[row][col]) != 1) {
                printf("Input error\n");
                return 1;
            }
            if (a[row][col] < -1000 || a[row][col] > 1000) {
                printf("Value error\n");
                return 1;
            }
        }
    }

    printf("Matrix:\n");
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            printf("%6d", a[row][col]);
        }
        printf("\n");
    }

    printf("Column sums:");
    for (int col = 0; col < cols; col++) {
        long long colSum = 0;
        for (int row = 0; row < rows; row++) {
            colSum += a[row][col];
        }
        printf(" %lld", colSum);
    }
    printf("\n");

    int minRow = 0;
    long long minRowSum = 0;
    for (int col = 0; col < cols; col++) {
        minRowSum += a[0][col];
    }

    for (int row = 1; row < rows; row++) {
        long long currentSum = 0;
        for (int col = 0; col < cols; col++) {
            currentSum += a[row][col];
        }
        if (currentSum < minRowSum) {
            minRowSum = currentSum;
            minRow = row;
        }
    }

    printf("Min row index = %d\n", minRow);
    printf("Min row sum = %lld\n", minRowSum);

    return 0;
}
