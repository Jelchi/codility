#include <stdio.h>

void convert_to_binary(int num, char *convert_result, int *size)
{
	int idx = 0;
	char binary[32];

	if (num == 0)
	{
		convert_result[0] = '0';
		convert_result[1] = '\0';

		*size = 1;
		return;
	}

	do
	{
		binary[idx] = num % 2 + '0';
		num = num / 2;
		idx++;
	} while (num > 0);

	int k = 0;
	for (int i = idx - 1; i >= 0; i--)
	{
		convert_result[k] = binary[i];
		k++;
	}
	*size = k;
	convert_result[k] = '\0';
}

int binary_gap_1(char *convert_result, int size)
{
	int max_gap = 0;
	int current_gap = -1;

	for (int i = 0; i < size; i++)
	{
		if (convert_result[i] == '1')
		{
			if (current_gap > max_gap)
			{
				max_gap = current_gap;
			}
			current_gap = 0;
		}
		else if (current_gap != -1)
		{
			current_gap++;
		}
	}
	return max_gap;
}

int binary_gap_2(int num)
{
	int max_gap = 0;
	int current_gap = -1;

	while (num > 0)
	{
		if (num & 1)
		{
			if (current_gap > max_gap)
			{
				max_gap = current_gap;
			}
			current_gap = 0;
		}
		else if (current_gap != -1)
		{
			current_gap++;
		}
		num >>= 1;
	}
	return max_gap;
}

int main()
{
	int num = 523;
	char convert_result[33];
	int size = 0;
	convert_to_binary(num, convert_result, &size);

	for (int i = 0; i < size; i++)
	{
		printf("%c", convert_result[i]);
	}
	puts("");

	int gap_1 = binary_gap_1(convert_result, size);
	printf("%d\n", gap_1);

	int gap_2 = binary_gap_2(num);
	printf("%d\n", gap_2);
	return 0;
}