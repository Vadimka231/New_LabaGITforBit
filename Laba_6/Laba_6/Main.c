#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;

void printElements() {
	printf("< ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf(">\n");

}
void keyboardInput() {
	printf("n = ");
	scanf_s("%d", &n);

	printf("input %d values: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}
void oddsX10() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			arr[i] = arr[i] * 10;
		}
	}
}
int findMin() {
	int min = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

//Задача 6.1.2 
int moreThan10() {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 10) {
			counter++;
		}
	}
	return counter;
}

//Задача 6.1.3
int findLastEven() {
	int even = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] % 2 == 0) {
			even = i;
			break;
		}
	}
	return even;
}

//Задача 6.1.4
int findIndexMin() {
	int min = arr[0];
	int even = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
			even = i;
		}
	}
	return even;
}

//Задача 6.1.7
void minus() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			arr[i] = arr[i] * -1;
		}
	}
}

//Задача 6.1.8
void onlyfour() {
	for (int i = 0; i < n; i++) {
		if (arr[i] < 4) {
			arr[i] = 4;
		}
	}
}

//Задача 6.1.9 вариант 2
void onlyOne() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) {
			arr[i] = 1;
		}
	}
}

//Задача 6.2.1
void deleteElement(int delIndex) {
	for (int i = delIndex; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
}

//Задача 6.2.2
void insertElement(int insertIndex, int insertElem) {
	for (int i = n; i > insertIndex - 1; i--) {
		arr[i] = arr[i - 1];
	}
	n++;
	arr[insertIndex] = insertElem;
}

//Задача 6.2.2
//Используется функции deleteElement() и findIndexMin()

//Задача 6.2.2

//Задача 8.1.3
int inFiles() {
	FILE* fin = fopen("arr.txt", "w");
	if (!fin) {
		printf("Не удалось создать файл");
		return 1;
	}
	fprintf(fin, "%d\n", n);
	for (int i = 0; i < n; ++i) {
		fprintf(fin, "%d ", arr[i]);
	}

	fclose(fin);

	printf("Файл готов!");
	return 0;
}

int outFiles() {
	FILE* fout = fopen("arr.txt", "r");
	if (!fout) {
		printf("Не удалось найти файл");
		return 1;
	}

	int k;
	fscanf(fout, "%d", &k);

	for (int i = 0; i < k; ++i) {
		fscanf(fout, "%d", &arr[i]);
	}
	fclose(fout);
	n = k;
	printf("Данные загружены!");
	return 0;
}

void main() {
	int item;
	do {
		printf("\n");
		printf("------------------------------\n");
		printf("Содержимое массива:");
		printf("Изменение 11\n");
		printf("Изменение 21\n");
		printf("Изменение 21\n");
		printElements();
		printf("Выберите нужную вам операцию:\n");
		printf("1: Ввести с клавиатуры массив\n");
		printf("2: x10 для всех нечетных элементов\n");
		printf("3: Найти минимальный элемент\n");
		printf("4: Сколько элементов > 10\n");
		printf("5: X2 для последнего чётного\n");
		printf("6: Сколько чётных левее минимального\n");
		printf("7: Все четные элементы массива умножить на -1\n");
		printf("8: Все элементы массива имеющие значения меньше 4 заменить на 4\n");
		printf("9: Все нечетные элементы заменить на 1\n");
		printf("11: Удалить заданный элемент\n");
		printf("12: Вставить новый элемент в заданное место\n");
		printf("13: Удалить минимальный элемент\n");
		printf("14: Перед минимальным элементом вставить 0\n");
		printf("15: Загрузить массив в файл\n");
		printf("16: Выгрузить массив из файла\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 1:
			keyboardInput();
			break;
		case 2:
			oddsX10();
			break;
		case 3:
		{
			int min = findMin();
			printf("min  = %d\n", min);
		}
		break;
		case 4:
			printf("%d элементов больше чем 10", moreThan10());
			break;
		case 5:
		{
			int index = findLastEven();
			if (index >= 0) {
				arr[index] *= 2;
			}
		}
		break;
		case 6:
		{
			int index = findIndexMin();
			printf("Индекс минимального элемента = %d\n", index);

			int cnt = 0;
			for (int i = 0; i < index; i++) {
				if (arr[i] % 2 == 0) {
					cnt++;
				}
			}
			printf("Левее минимального %d четных элементов \n", cnt);
		}
		break;
		case 7:
			minus();
			break;
		case 8:
			onlyfour();
			break;
		case 9:
			onlyOne();
			break;
		//Лаба 6.2
		case 11:
		{
			printf("Индекс удаляемого элемента = ");
			int index;
			scanf_s("%d", &index);
			deleteElement(index);
		}
			break;
		case 12:
		{
			printf("Перед каким элементом нужно всатвить новый? Индекс = ");
			int index;
			scanf_s("%d", &index);

			printf("Значение, которое нужно вставить = ");
			int value;
			scanf_s("%d", &value);

			insertElement(index, value);
		}
		break;
		case 13:
		{
			int min = findIndexMin();
			printf("Индекс минимального элемента = %d", min);
			deleteElement(min);
		}
			break;
		case 14:
		{
			int min = findIndexMin();
			printf("Индекс минимального элемента = %d", min);
			insertElement(min, 0);
		}
			break;
		case 15:
			inFiles();
			break;
		case 16:
			outFiles();
			break;
		}


	} while (item != 0);
}
