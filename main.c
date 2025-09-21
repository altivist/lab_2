#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const char *file1 = "file1.txt", *file2 = "file2.txt", *file3 = "file3.txt";
    FILE *f1 = fopen(file1, "w"), *f2 = fopen(file2, "w"), *f3 = fopen(file3, "w");

    if (f1 == NULL || f2 == NULL || f3 == NULL)
    {
        printf("Не удалось создать файлы\n");
        if (f1)
            fclose(f1);
        if (f2)
            fclose(f2);
        if (f3)
            fclose(f3);
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        int num1 = (rand() % 10) + 1;
        int num2 = (rand() % 10) + 1;
        int num3 = (rand() % 10) + 1;

        fprintf(f1, "%d ", num1, i == 9 ? '\n' : ' ');
        fprintf(f2, "%d ", num2, i == 9 ? '\n' : ' ');
        fprintf(f3, "%d ", num3, i == 9 ? '\n' : ' ');
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}