#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min_steps(int x, int y)
{
    if (x == y)
        return 0;
    if (x > y)
        return -1;

    int steps = 0;
    int current = x;
    int length = 1;

    while (current < y)
    {
        current += length;
        steps++;
        if (current == y)
            break;
        if (current + (length + 1) <= y)
        {
            length++;
        }
        else if (current + length <= y)
        {
        }
        else
        {
            length--;
        }
    }

    return steps;
}

int main()
{
    int x, y;

    printf("Введіть початкову точку x: ");
    scanf("%d", &x);

    printf("Введіть кінцеву точку y: ");
    scanf("%d", &y);

    if (x < 0 || y < 0 || y > INT_MAX || x > INT_MAX)
    {
        printf("Некоректний ввід\n");
        return 1;
    }

    int result = min_steps(x, y);

    if (result == -1)
    {
        printf("Неможливо дістатися від %d до %d шляхом збільшення x\n", x, y);
    }
    else
    {
        printf("Мінімальна кількість кроків від %d до %d: %d\n", x, y, result);
    }

    return 0;
}
