#include <stdio.h>
#include <stdlib.h>

int solution_1(int *A, int N)
{
	int max = A[0];
	for (int i = 0; i < N; i++)
	{
		if (max < A[i + 1])
		{
			max = A[i];
		}
	}

	int *counts = (int *)calloc(max + 1, sizeof(int));
	if (counts == NULL)
	{
		return -1;
	}

	for (int i = 0; i < N; i++)
	{
		counts[A[i]]++;
	}

	int result = -1;

	for (int i = 0; i < max + 1; i++)
	{
		if (counts[i] % 2 != 0)
		{
			result = i;
			break;
		}
	}

	free(counts);
	return result;
}

int solution_2(int *A, int N)
{
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		result ^= A[i];
		// result = result ^ A[i];
	}

	return result;
}

int main()
{
	int A[] = {9, 3, 9, 3, 9, 7, 9};
	int N = sizeof(A) / sizeof(A[0]);

	int solution_result_1 = solution_1(A, N);
	printf("%d\n", solution_result_1);

	int solution_result_2 = solution_2(A, N);
	printf("%d\n", solution_result_2);

	return 0;
}