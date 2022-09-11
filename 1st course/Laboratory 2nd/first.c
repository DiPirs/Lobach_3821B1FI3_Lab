#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <time.h>

const double RAND_MAX_F = RAND_MAX;

int main() {
	int			x = 0, i = 0, case_1 = 0, j, o;
	int			size_gener, len_inter_keyboard;
	double		min_gener, max_gener;
	double		inter_keyboard;

	int n;

	double* mas = 0;

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	FILE* file = fopen("file.txt", "w");

	do
	{
		system("cls");
		printf("Вас приветствует меню \"Сортировка\". Что бы Вы хотели сделать?\n");
		printf("1. Сгенерировать числа\n2. Ввести с клавиатуры\n3. Считать данные с другого файла\n");
		scanf_s("%d", &x);
		switch (x)
		{
		case 1:
			do
			{
				system("cls");
				printf("Вы выбрали \"Генирацию чисел\"\n");
				printf("Введите кол-во элементов массива: ");
				scanf_s("%d", &size_gener);
				printf("Введите минимальное число: ");
				scanf_s("%lf", &min_gener);
				printf("Введите максимальное число: ");
				scanf_s("%lf", &max_gener);
				printf("\nОжидайте проверки данных...\n\n");
				Sleep(1500);
				if ((min_gener > max_gener) || (size_gener <= 0))
				{
					printf("Вы ввели не правильные данные. Пожалуйста, повторите попытку.\n");
					Sleep(1000);
				}
				else
				{
					system("cls");
					printf("Данные коректны.\nСейчас произойдет магия генерации...\n\n");
					Sleep(1000);
					case_1++;
				}
			} while (case_1 != 1);

			printf("Ожидайте...\n\n");
			Sleep(1000);

			for (j = 0; j < size_gener; j++)
			{
				fprintf(file, "%lf\n", (rand() / RAND_MAX_F) * ((double)max_gener - (double)min_gener) + min_gener);
			}

			printf("Поздравляю, Вы только что сгенерировали числа\nМожете убедиться, заглянув в текстовой файл.\n");
			i++;
			break;
		case 2:
			system("cls");
			printf("Вы выбрали \"Ввести с клавиатуры\"\n");
			printf("Пожалуйста, введите кол-во элементов массива: ");
			scanf_s("%d", &len_inter_keyboard);
			printf("Пожалуйста, введите все нужные Вам числа (числа вводить с запятой, а не с точкой. К примеру: 1,25):\n");
			for (j = 0; j < len_inter_keyboard; j++)
			{
				scanf_s("%lf", &inter_keyboard);
				fprintf(file, "%f\n", inter_keyboard);
			}
			printf("\nОжидайте...\n\n");
			Sleep(1000);

			printf("Поздравляю, Вы только что записали числа в текстовый файл\nМожете убедиться, заглянув в него.\n");
			i++;
			break;
		case 3:
			system("cls");
			printf("Вы выбрали \"Чтение с другого файла\"\n");

			FILE* file_2 = 0;

			fopen_s(&file_2, "file_2.txt", "r");
			printf("Сколько элементов содержит файл?\n");
			scanf_s("%d", &n);

			mas = malloc(n * sizeof(double));

			for (o = 0; o < n; o++)
			{
				mas[o] = 0;
			}

			for (o = 0; o < n; o++)
			{
				fscanf_s(file_2, "%lf\n", &(mas[o]));
				fprintf(file, "%lf\n", mas[o]);
			}

			fclose(file_2);
			fclose(file);

			i++;
			break;
		default:
			printf("Вы ввели не правильное число, повторите попытку\n");
			Sleep(1000);
			break;
		}
	} while (i != 1);

	return 0;
}
