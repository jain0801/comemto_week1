#include <stdio.h>
#include <time.h>

int	len(int *arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	*insert(int *arr)
{
	int i;
	int j;
	int k;
	int tmp;

	i = 0;
	while (arr[i] != 0)
	{
	    k = i;
		j = i - 1;
		while (j >= 0 && arr[k] < arr[j])
		{
			tmp = arr[k];
			arr[k] = arr[j];
			arr[j] = tmp;
			k--;
			j = k - 1;
		}
		i++;
	}
	return (arr);
}

int	len(int *arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	*merge(int *arr, int low, int mid, int high)
{
	int tmp[high - low + 1];
	int i;
	int j;
	int k;

	k = low;
	i = low;
	j = mid + 1;
	while (k <= high)
	{
		if (i > mid)
		{
			tmp[k - low] = arr[j];
			j += 1;
		}
		else if (j > high)
		{
			tmp[k - low] = arr[i];
			i += 1;
		}
		else if (arr[j] < arr[i])
		{
			tmp[k - low] = arr[j];
			j += 1;
		}
		else
		{
			tmp[k - low] = arr[i];
			i += 1;
		}
		k++;
	}
	k = low;
	while (k <= high)
	{
		arr[k] = tmp[k - low];
		k++;
	}
}

void	merge_sort(int *arr, int low, int high)
{
	int	mid;

	if (high <= low)
		return ;
	mid = (low + high) / 2;
	merge_sort(arr, low, mid);
	merge_sort(arr, mid + 1, high);
	merge(arr, low, mid, high);
}

int	*s_merge(int *arr)
{
	int l;

	l = len(arr);
	merge_sort(arr, 0, l);
	return (arr);
}

int	sub_sort(int *arr, int pivot, int high)
{
	int i;
	int j;
	int tmp;

	i = pivot + 1;
	j = high;
	while (1)
	{
		while (i < high && arr[i] < arr[pivot])
			i += 1;
		while (j > pivot && arr[j] > arr[pivot])
			j -= 1;
		if (j <= i)
			break;
		tmp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = tmp;
	}
	return (j);
}

void	quick_sort(int *arr, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = sub_sort(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

int	*quick(int *arr)
{
	quick_sort(arr, 0, len(arr));
	return (arr);
}

int main()
{
	time_t start, end;
	int arr[10] = {1,3,2,4,5,6,9,8,7};
	int *result;
	int i = 0;
	start = time(NULL);
	result = quick(arr);
	end = time(NULL);
	
	while (i < 10)
	{
		printf("%d, ",result[i]);
		i++;
	}	

	printf("\n%ld", end - start);
}
