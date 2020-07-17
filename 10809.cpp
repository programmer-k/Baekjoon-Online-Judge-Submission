#include <stdio.h>

int main(void)
{
	int i;
	char str[100];
	int alphabet[26];

	for (i = 0; i < 26; i++)
		alphabet[i] = -1;

	scanf("%s", str);

	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] == 'a')
		{
			if (alphabet[0] == -1)
				alphabet[0] = i;
		}
		else if (str[i] == 'b')
		{
			if (alphabet[1] == -1)
				alphabet[1] = i;
		}
		else if (str[i] == 'c')
		{
			if (alphabet[2] == -1)
				alphabet[2] = i;
		}
		else if (str[i] == 'd')
		{
			if (alphabet[3] == -1)
				alphabet[3] = i;
		}
		else if (str[i] == 'e')
		{
			if (alphabet[4] == -1)
				alphabet[4] = i;
		}
		else if (str[i] == 'f')
		{
			if (alphabet[5] == -1)
				alphabet[5] = i;
		}
		else if (str[i] == 'g')
		{
			if (alphabet[6] == -1)
				alphabet[6] = i;
		}
		else if (str[i] == 'h')
		{
			if (alphabet[7] == -1)
				alphabet[7] = i;
		}
		else if (str[i] == 'i')
		{
			if (alphabet[8] == -1)
				alphabet[8] = i;
		}
		else if (str[i] == 'j')
		{
			if (alphabet[9] == -1)
				alphabet[9] = i;
		}
		else if (str[i] == 'k')
		{
			if (alphabet[10] == -1)
				alphabet[10] = i;
		}
		else if (str[i] == 'l')
		{
			if (alphabet[11] == -1)
				alphabet[11] = i;
		}
		else if (str[i] == 'm')
		{
			if (alphabet[12] == -1)
				alphabet[12] = i;
		}
		else if (str[i] == 'n')
		{
			if (alphabet[13] == -1)
				alphabet[13] = i;
		}
		else if (str[i] == 'o')
		{
			if (alphabet[14] == -1)
				alphabet[14] = i;
		}
		else if (str[i] == 'p')
		{
			if (alphabet[15] == -1)
				alphabet[15] = i;
		}
		else if (str[i] == 'q')
		{
			if (alphabet[16] == -1)
				alphabet[16] = i;
		}
		else if (str[i] == 'r')
		{
			if (alphabet[17] == -1)
				alphabet[17] = i;
		}
		else if (str[i] == 's')
		{
			if (alphabet[18] == -1)
				alphabet[18] = i;
		}
		else if (str[i] == 't')
		{
			if (alphabet[19] == -1)
				alphabet[19] = i;
		}
		else if (str[i] == 'u')
		{
			if (alphabet[20] == -1)
				alphabet[20] = i;
		}
		else if (str[i] == 'v')
		{
			if (alphabet[21] == -1)
				alphabet[21] = i;
		}
		else if (str[i] == 'w')
		{
			if (alphabet[22] == -1)
				alphabet[22] = i;
		}
		else if (str[i] == 'x')
		{
			if (alphabet[23] == -1)
				alphabet[23] = i;
		}
		else if (str[i] == 'y')
		{
			if (alphabet[24] == -1)
				alphabet[24] = i;
		}
		else if (str[i] == 'z')
		{
			if (alphabet[25] == -1)
				alphabet[25] = i;
		}
	}

	for (i = 0; i < 26; i++)
		printf("%d ", alphabet[i]);

	return 0;
}