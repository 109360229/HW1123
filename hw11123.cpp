/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a;
	int *aPtr;
	a = 7;
	aPtr = &a;
	printf("The address of a is %p\nThe value of aPtr is %p", &a, aPtr);
	printf("\n\nThe value of a is %d\nThe value of *aPtr is %d", a, *aPtr);
	printf("\n\nShowing that * and & are complements of " "each other\n&*aPtr = %p" "\n*&aPtr = %p\n", &*aPtr, *&aPtr);
	system("pause");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
int cubeByValue(int n);
int main(void)
{
	int number = 5;
	printf("The original value of number is %d", number);
	number = cubeByValue(number);
	printf("\nThe new value of number is %d\n", number);
	system("pause");
	return 0;
}
int cubeByValue(int n)
{
	return n * n * n;
}

#include <stdio.h>
#include <stdlib.h>
void cubeByReference(int *nPtr);
int main(void)
{
	int number = 5;
	printf("The original value of number is %d", number);
	cubeByReference(&number);
	printf("\nThe new value of number is %d\n", number);
	system("pause");
	return 0;
}
void cubeByReference(int *nPtr)
{
	*nPtr = *nPtr * *nPtr * *nPtr;
}

#include <stdio.h>
#include <stdlib.h>
void cubeByReference(int &nPtr);
int main(void)
{
	int number = 5;
	printf("The original value of number is %d", number);
	cubeByReference( number );
	printf("\nThe new value of number is %d\n", number);
	system("pause");
	return 0;
}
void cubeByReference(int &nPtr)
{
	nPtr = nPtr * nPtr * nPtr;
}

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void bubbleSort(int * const array, const int size);
int main(void)
{
	int a[SIZE]{ 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
	int i;
	printf("Data items in original order\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%4d", a[i]);
	}
	bubbleSort(a, SIZE);
	printf("\nData items in ascending order\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
void bubbleSort(int * const array, const int size)
{
	void swap(int *elementlPtr, int *element2Ptr);
	int pass;
	int j;
	for (pass = 0; pass < size - 1; pass++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}
void swap(int *element1Ptr, int *element2Ptr)
{
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int b[] = { 10, 20, 30, 40 };
	int *bPtr = b;
	int i;
	int offset;
	printf("Array b printed with: \nArray subscript notation\n");
	for (i = 0; i < 4; i++)
	{
		printf("b[%d] = %d\n", i, b[i]);
	}
	printf("\nPointer/offset notation where\n" "the pointer is the array name\n");
	for (offset = 0; offset < 4; offset++)
	{
		printf("*(b + %d) = %d\n", offset, *(b + offset));
	}
	printf("\nPointer subscript notation\n");
	for (i = 0; i < 4; i++)
	{
		printf("bPtr[%d] = %d\n", i, bPtr[i]);
	}
	printf("\nPointer/offset notation\n");
	for (offset = 0; offset < 4; offset++)
	{
		printf("*(bPtr + %d) = %d\n", offset, *(bPtr + offset));
	}
	system("pause");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[]);
int main(void)
{
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	int deck[4][13] = {0};
	srand(time(0));
	shuffle(deck);
	deal(deck, face, suit);
	system("pause");
	return 0;
}
void shuffle(int wDeck[][13])
{
	int row;
	int column;
	int card;
	for (card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);
		wDeck[row][column] = card;
	}
}
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[])
{
	int card;
	int row;
	int column;
	for (card = 1; card <= 52; card++)
	{
		for (row = 0; row <= 3; row++)
		{
			for (column = 0; column <= 12; column++)
			{
				if (wDeck[row][column] == card)
				{
					printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t' );
				}
			}
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	srand(time(0));
	int totals[11] = { 0 };

	int i;
	for (i = 0; i < 36000; ++i) {
		int dice1 = rand() % 6 + 1;
		int dice2 = rand() % 6 + 1;

		int total = dice1 + dice2;
		totals[total - 2]++;

		printf("擲骰子結果：第一顆骰子：%d，第二顆骰子：%d，總和：%d\n", dice1, dice2, total);
	}

	printf("\n各種總和出現的次數：\n");
	printf("-----------------\n");
	printf("| 總和 | 出現次數 |\n");
	printf("-----------------\n");
	for (i = 2; i <= 12; ++i) {
		printf("|  %2d  |    %5d   |\n", i, totals[i - 2]);
	}
	printf("-----------------\n");

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
int binarySearch(int arr[], int left, int right, int key) {
	if (right >= left) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] > key)
			return binarySearch(arr, left, mid - 1, key);
		return binarySearch(arr, mid + 1, right, key);
	}
	return -1;
}
int main() {
	int arr[] = { 2, 3, 4, 10, 40, 50, 60, 70, 80 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 10;
	int result = binarySearch(arr, 0, n - 1, key);
	if (result == -1)
		printf("未找到 %d\n", key);
	else
		printf("%d 在陣列中的索引為 %d\n", key, result);
	return 0;
}

#include <stdio.h>
#pragma warning (disable:4996)
void stringReverse(const char *str) {
	if (*str) {
		stringReverse(str + 1);
		putchar(*str);
	}
}
int main() {
	char inputString[100];
	printf("請輸入一個字串: ");
	scanf("%s", inputString);
	printf("反向列印字串: ");
	stringReverse(inputString);
	printf("\n");
	return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)
int recursiveMaximum(int arr[], int size) {
	if (size == 1) {
		return arr[0];
	}
	else {
		int subMax = recursiveMaximum(arr, size - 1);
		return (subMax > arr[size - 1]) ? subMax : arr[size - 1];
	}
}

int main() {
	int size;
	printf("請輸入數組大小: ");
	scanf("%d", &size);

	int *array = (int *)malloc(size * sizeof(int)); // 使用動態記憶體分配

	if (array == NULL) {
		printf("記憶體分配失敗\n");
		return 1;
	}

	printf("請輸入 %d 個整數: ", size);
	for (int i = 0; i < size; ++i) {
		scanf("%d", &array[i]);
	}

	int max = recursiveMaximum(array, size);
	printf("數組中的最大值為：%d\n", max);

	free(array); // 釋放動態分配的記憶體

	return 0;
}