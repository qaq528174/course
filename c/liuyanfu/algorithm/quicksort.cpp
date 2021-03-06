#include <iostream>
using namespace std;

void parti(int *arr,size_t left,size_t right)
{
	size_t mid  = (left+right)/2;
	if(arr[left]>arr[right])
	{
		swap(arr[left],arr[right]);
	}
	if(arr[mid]>arr[right])
	{
		swap(arr[mid],arr[right]);
	}
	if(arr[left]<arr[mid])
	{
		swap(arr[left],arr[mid]);
	}
}

void qsort(int *arr, size_t left, size_t right)
{
	if (left >= right)
		return;
	parti(arr,left,right);
	size_t i = left;
	size_t j = right;
	int temp = arr[left];
	int t    = 0;
	while(i!=j)
	{
		while(i<j && arr[j]>temp)
			--j;
		while(arr[i]<=temp && i<j)
			++i;
		if(i < j)
		{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	arr[left] = arr[i];
	arr[i]   = temp;

	int pval = i;
	int k1=0,k2=i-1;
	while(k1!=k2)
	{
		while(k1<k2 && arr[k2]==temp)
			--k2;
		while(k1<k2 && arr[k1]!=temp)
			++k1;
		if(k1<k2)
		{
			swap(arr[k1],arr[k2]);
		}
	}
	if(k2!=0)
	{
		if(arr[k2]==temp)
			qsort(arr,left,k2-1);
		else
			qsort(arr,left,k2);
	}
	qsort(arr,i+1,right);
	return;

}

void quicksort(int *arr, size_t dsize)
{
	size_t left = 0;
	size_t right= dsize-1;
	qsort(arr,left,right);
}

