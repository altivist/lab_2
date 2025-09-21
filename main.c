// main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void write_random_numbers(FILE *f, int count, int MIN_VAL, int MAX_VAL)
{
    for (int i = 0; i < count; i++)
    {
        int num = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
        fprintf(f, "%d%c", num, (i == count - 1) ? '\n' : ' ');
    }
}

int main(void)
{
    enum
    {
        MIN_VAL = 1,
        MAX_VAL = 10,
        COUNT = 10,
        FILES = 3
    };

    const char *filenames[FILES] = {"file1.txt", "file2.txt", "file3.txt"};
    FILE *files[FILES];

    srand(time(NULL));

    for (int i = 0; i < FILES; i++)
    {
        files[i] = fopen(filenames[i], "w");
        if (!files[i])
        {
            printf("Ошибка открытия файла file%d.txt\n", i + 1);
            while (i--)
                fclose(files[i]);
            return 1;
        }
    }

    for (int i = 0; i < FILES; i++)
    {
        write_random_numbers(files[i], COUNT, MIN_VAL, MAX_VAL);
    }

    for (int i = 0; i < FILES; i++)
    {
        fclose(files[i]);
    }

    return 0;
}
