#include <iostream>
#include <ctime>
#include <Windows.h>

struct Tree
{
	int* arr;
	int size;
	int length = 0;
};

inline int leftChild(int idx)
{
	return idx * 2;
}

inline int rightChild(int idx)
{
	return idx * 2 + 1;
}

void swap(Tree* tree, int idx1, int idx2)
{
	int tmp = tree->arr[idx1];
	tree->arr[idx1] = tree->arr[idx2];
	tree->arr[idx2] = tmp;
}

void insertV(Tree* tree, int value)
{
	if (tree->length < tree->size)
	{
		tree->arr[++tree->length] = value;
	}
}

void minHeap(Tree* tree, int start, bool isSub)
{
	int curPos = start;
	int minChildIdx;
	int left, right;

	while (curPos >= 1)
	{
		left = leftChild(curPos);
		right = rightChild(curPos);
		if (left <= tree->length)
		{
			if (right <= tree->length)
			{
				if (tree->arr[left] < tree->arr[right])
					minChildIdx = left;
				else
					minChildIdx = right;
			}
			else
				minChildIdx = left;

			if (tree->arr[curPos] > tree->arr[minChildIdx])
			{
				swap(tree, curPos, minChildIdx);
				minHeap(tree, minChildIdx, true);
			}
		}

		curPos--;

		if (isSub)
			break;
	}
}

int deleteV(Tree* tree)
{
	if (tree->length >= 0)
	{
		int value = tree->arr[1];
		tree->arr[1] = tree->arr[tree->length--];
		minHeap(tree, 1, false);
		return value;
	}
	return -1;
}

void heapSort(Tree* tree, int* sortedArr)
{
	for (int i = 0; i < tree->size; i++)
		sortedArr[i] = deleteV(tree);
}

void printArr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d\n", arr[i]);
	}
}


int main(void)
{
	Tree tree;
	int lines;
	scanf("%d", &lines);

	tree.arr = new int[lines + 1];
	tree.size = lines;

	int* sortedArr = new int[tree.size + 1];
	int input;
	for (int i = 1; i <= lines; i++)
	{
		scanf("%d", &input);
		insertV(&tree, input);
	}

	minHeap(&tree, lines / 2, false); 
	heapSort(&tree, sortedArr); 
	printArr(sortedArr, lines);

	delete[] sortedArr;
	delete[] tree.arr;
	return 0;
}