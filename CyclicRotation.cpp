#include <stdio.h>
#include <stdlib.h>

struct Results
{
	int *A;
	int N;
};

void swap(int *A, int start, int end)
{
	while (start < end)
	{
		int temp = A[start];
		A[start] = A[end];
		A[end] = temp;
		start++;
		end--;
	}
}

void cyclic_rotation_1(int *A, int N, int K)
{
	if (N == 0)
		return;

	K = K % N;

	swap(A, 0, N - 1); // 1. Balik semua array
	swap(A, 0, K - 1); // 2. Balik K elemen pertama
	swap(A, K, N - 1); // 3. Balik Sisanya
}

void cyclic_rotation_2(int *A, int N, int K)
{
	if (N == 0)
	{
		return;
	}

	K = K % N;

	int *rotated = (int *)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++)
	{
		rotated[(i + K) % N] = A[i];
	}

	for (int i = 0; i < N; i++)
	{
		A[i] = rotated[i];
	}
	free(rotated);
}

struct Results solution(int *A, int N, int K)
{
	struct Results result;
	result.A = (int *)malloc(N * sizeof(int));
	result.N = N;

	if (N == 0)
	{
		result.A = NULL;
		return result;
	}

	if (result.A == NULL)
	{
		result.N = 0;
		return result;
	}

	for (int i = 0; i < N; i++)
	{
		result.A[(i + K) % N] = A[i];
	}

	return result;
}

int main()
{
	int A[] = {
		3,
		8,
		9,
		7,
		6};
	int K = 3;
	int N = sizeof(A) / sizeof(A[0]);

	// cyclic_rotation_1(A, N, K);
	// for (int i = 0; i < N; i++)
	// {
	// 	printf("%d", A[i]);
	// }
	// puts("");

	// cyclic_rotation_2(A, N, K);
	// for (int i = 0; i < N; i++)
	// {
	// 	printf("%d ", A[i]);
	// }

	struct Results rotated = solution(A, N, K);

	for (int i = 0; i < N; i++)
	{
		printf("%d", rotated.A[i]);
	}

	return 0;
}