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
	int tmp;

	i = 0;
	while (arr[i] != 0)
	{
		j = i - 1;
		while (arr[i] > arr[j])
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			j--;
		}
		i++;
	}
}

void	*merge(int *arr, int low, int mid, int high)
{
	int tmp[high - low];
	int i;
	int j;
	int l;

	l = 0;
	i = low;
	j = high;
	while (l <= high - low)
	{
		if (i > mid)
		{
			tmp[l] = arr[j];
			j += 1;
		}
		else if (j > high)
		{
			tmp[l] = arr[i];
			i += 1;
		}
		else if (arr[j] < arr[i])
		{
			tmp[l] = arr[j];
			j += 1;
		}
		else
		{
			tmp[l] = arr[i];
			i += 1;
		}
		l++;
	}
	l = 0;
	while (l <= high)
	{
		arr[l + low] = tmp[l];
		l++;
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
	while (i < 10)
	{
		printf("%d, ",result[i]);
		i++;
	}

	end = time(NULL);
	printf("\n%ld", end - start);

	start = time(NULL);
	result = insert(arr);
	end = time(NULL);
	while (i < 10)
	{
		printf("%d", result[i]);
		i++;
	}
	printf("\n%ld", end - start);
}
