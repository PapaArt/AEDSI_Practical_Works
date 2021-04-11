#include "sat.h"

void semPreconceito()
{
	#ifdef _WIN32
		system("cls");
	#elif __linux__
		system("clear");
	#endif
}

void print_binary(int n, int leng)
{
    long long  int bit = 1 << leng - 1;
    while (bit)
    {
        printf("%d", n & bit ? 1 : 0);
        bit >>= 1;
    }
    printf("\n");
}

void geraclauses(int (*mat)[40], int C, int N)
{
	int randomic1, randomic2, randomic3, test1, test2, test3;
	int i, j;

	for (i = 0; i < C; i++)
	{
		for (j = 0; j < N; j++)
			mat[i][j] = 0;
	}

	srand(time(0));
	for (i = 0; i < C; i++)
	{
		int test1 = 0;
		int test2 = 0;
		int test3 = 0;

		randomic1 = rand() % N;
		test1 = rand() % 3;
		if (test1 == 0)
		{
			test1++;
		}
		mat[i][randomic1] = test1;

		randomic2 = rand() % N;

		test2 = rand() % 3;

		if (test2 == 0)
		{
			test2++;
		}
		while (randomic2 == randomic1)
		{
			randomic2 = rand() % N;
		}

		mat[i][randomic2] = test2;

		randomic3 = rand() % N;

		test3 = rand() % 3;
		if (test3 == 0)
		{
			test3++;
		}

		while (randomic3 == randomic2 || randomic3 == randomic1)
		{
			randomic3 = rand() % N;
		}
		mat[i][randomic3] = test3;
		printf("Escolhas: %d %d %d\n", randomic1, randomic2, randomic3);
		printf("Negacao: %d %d %d\n", test1, test2, test3);
	}
}
