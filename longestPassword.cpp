/*
	it has to contain only alphanumerical characters (a−z, A−Z, 0−9);
	there should be an even number of letters;
	there should be an odd number of digits.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int password_validation(char *S)
{
	int letters = 0;
	int digits = 0;

	if (S == NULL)
	{
		return 0;
	}

	for (int i = 0; S[i] != '\0'; i++)
	{
		if (isalpha(S[i]))
		{
			letters++;
		}
		else if (isalnum(S[i]))
		{
			digits++;
		}
		else
		{
			return 0;
		}
	}
	return (letters % 2 == 0) && (digits % 2 == 1);
}

int solution(char *S, int len)
{
	if (S == NULL || S[0] == '\0')
	{
		return 0;
	}
	int max = -1;
	char *temp;
	char *token = strtok_r(S, " ", &temp);

	while (token != NULL)
	{
		if (password_validation(token))
		{
			int lenWord = strlen(token);
			if (lenWord > max)
			{
				max = lenWord;
			}
		}
		token = strtok_r(NULL, " ", &temp);
	}
	return max;
}

int solution_2(const char *S)
{
	int maxLength = -1;
	int len = strlen(S);
	char word[201]; // Max size according to constraint (N <= 200)
	int idx = 0;

	for (int i = 0; i <= len; i++)
	{
		if (S[i] == ' ' || S[i] == '\0')
		{
			if (idx > 0)
			{
				word[idx] = '\0'; // End current word
				if (password_validation(word))
				{
					int wordLen = strlen(word);
					if (wordLen > maxLength)
					{
						maxLength = wordLen;
					}
				}
				idx = 0; // Reset word index
			}
		}
		else
		{
			word[idx++] = S[i];
		}
	}

	return maxLength;
}

int main()
{
	char S[] = "test 5 a0A pass007 ?xy1";
	int len = strlen(S);

	int result = solution(S, len);
	printf("%d", result);
	return 0;
}