/*

Sorting Algorithms

 */


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

//QuickSort
void swap(int l, int u, int x[])
{
  if (l == u) {
    return;
  }
  
  int tmp = x[l];
  x[l] = x[u];
  x[u] = tmp;
}

int randint(int l, int u)
{
  return rand() % (u - l) + l;
}

void quicksort(int l, int u, int x[])
{
  if (l >= u) {
    return;
  }
  
  swap(l, randint(l, u), x);
  
  int m = l;
  
  for (int i = l + 1; i <= u; i ++) {
    if (x[i] < x[l]) {
      swap(++m, i, x);
    }
  }
  
  swap(l, m, x);
  
  quicksort(l, m - 1, x);
  quicksort(m + 1, u, x);
}


//MergeSort
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int k = 0;
	
	while (i <= mid && j <= last)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	while (i <= mid)
		temp[k++] = a[i++];
	
	while (j <= last)
		temp[k++] = a[j++];
	
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}

void mergesort(int a[], int first, int last, int temp[])
{
	if (first >= last) {
    return;
  }
	
  int mid = (first + last) / 2;
  mergesort(a, first, mid, temp);   
  mergesort(a, mid + 1, last, temp);
  mergearray(a, first, mid, last, temp); 
}

bool MergeSort(int a[], int n)
{
	int *p = new int[n];
	if (p == NULL)
		return false;
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return true;
}

//BubbleSort
void bubbleSort(int x[], int length)
{
  for (int i = 0; i < length - 1; i ++) {
    for (int j = 0; j < length - i - 1; j ++) {
      if (x[j] > x[j + 1]) {
        swap(j, j + 1, x);
      }
    }
  }
}

void selectSort(int x[], int length)
{
  for (int i = 0; i < length; i ++) {
    int min = x[i];
    int position = i;
    
    for (int j = i + 1; j < length; j ++) {
      if (x[j] < min) {
        min = x[j];
        position = j;
      }
    }
    
    swap(i, position, x);
  }
}

void insertSort(int x[], int length)
{
  for (int i = 1; i < length; i ++) {
    int j;
    for (j = i - 1; j >= 0; j --) {
      if (x[i] < x[j]) {
        x[j + 1] = x[j];
      }
    }
    x[j + 1] = x[i];
  }
}
