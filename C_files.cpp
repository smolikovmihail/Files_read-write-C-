// C_files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int numberCount(FILE* );
void read_numbers(FILE*,FILE*, int s,int s1, int*);
void print_array(int*, int);
void bubbleSorting(int* numbers,int totalSize);
int main()
{
	FILE* input = fopen("num1.txt", "r");// открываем первый файл
	FILE* input1= fopen("num2.txt", "r");//открываем второй файл (режим чтения)
	if (input == 0||input1==0) 
	{
		printf("can`t open files!!!\n");
		return 1;
	}
	int size = numberCount(input);
	int size1 = numberCount(input1);
	int totalSize = size + size1;
	int* numbers = (int*)malloc(sizeof(int) * totalSize);
	read_numbers(input,input1, size,size1, numbers);
	bubbleSorting(numbers,totalSize);
	print_array(numbers, totalSize);
}

int numberCount(FILE* input)
{
	fseek(input, 0, SEEK_SET);
	int counter = 0;
	while (true) {
		int value;
		if (fscanf(input, "%d", &value) == 1)
			counter++;
		if (feof(input))
			break;
	}
	return counter;
}

void read_numbers(FILE* input,FILE* input1, int size,int size1, int* numbers) 
{
	fseek(input, 0, SEEK_SET);
	for (int i = 0; i < size; ++i) {
		fscanf(input, "%d", &numbers[i]);
	}
	fseek(input1, 0, SEEK_SET);
	for (int j = size; j < size+size1; ++j) {
		fscanf(input1, "%d", &numbers[j]);
	}
}

void bubbleSorting(int* numbers,int totalSize)
{
	int tmp;
	bool noSwap;

	for (int i = totalSize - 1; i >= 0; i--)
	{
		noSwap = 1;
		for (int j = 0; j < i; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				tmp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = tmp;
				noSwap = 0;
			}
		}
		if (noSwap == 1)
			break;
	}
	/*printf("Sorted array:\n");
	for (int i = 0; i < N; i++)
		printf("%d ", numbers[i]);
	printf("\n");*/
	//free(numbers);
}

void print_array(int* numbers, int size) {
	/*for (int i = 0; i < size; ++i) {  //пишем в консоль чтобы проверить правильность работы
		printf("%d ; ", numbers[i]);
	}*/
	FILE* output = fopen("num3.txt", "w");  //третий файл создаётся на запись
	fseek(output, 0, SEEK_SET);
	for (int i = 0; i < size; ++i) {
		fprintf(output,"%d \n", numbers[i]);
	}

	free(numbers);
	printf("\n");
}

