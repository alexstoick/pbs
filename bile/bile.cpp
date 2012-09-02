//Mugurel Andreica 100 puncte
#include <stdio.h>

#define NMAX 15001

#define min(a, b) ((a) < (b) ? (a) : (b))

short int P[NMAX], S[NMAX], Pgot[2], Sleft[2];
long int i, j, k, N, x, xmax, sumx, y1, y2, x1, x2, d1, d2, yx1, yx2, T;

long int f(int x)
{
	Pgot[0] = x;
	Sleft[0] = S[0] - x;
	sumx = x;

	for (i = 0; i < N; i++)
	{
		if (i > 0)
		{
			Sleft[i % 2] = S[i];
			k = min(Sleft[i % 2], P[i] - Pgot[i % 2]);
			Sleft[i % 2] = S[i] - k;
			Pgot[i % 2] += k;
			sumx += k;
		}

		if (i < N - 1)
			k = min(Sleft[i % 2], P[(i + 1) % N]);
		else
			k = min(Sleft[i % 2], P[(i + 1) % N] - x);

		Sleft[i % 2] -= k;
		Pgot[((i + 1) % N) % 2] = k;
		sumx += k;
	}

	return sumx;
}

int main()
{
	freopen("bile.in", "r", stdin);
	freopen("bile.out", "w", stdout);

	scanf("%ld", &T);

	while (T--)
	{
		scanf("%ld", &N);

		for (i = 0; i < N; i++)
			scanf("%d %d", &S[i], &P[i]);

		xmax = min(P[0], S[0]);

		y1 = f(0);
		y2 = f(xmax);
		x1 = (y2 - y1+ xmax) / 2;
		yx1 = f(x1);

		if ((y2 - y1 + xmax) % 2 == 1)
		{
			x2 = x1 + 1;
			yx2 = f(x2);
		}
		else
		{
			x2 = x1;
			yx2 = yx1;
		}

		d1 = y1 + x1 - yx1;
		d2 = y2 + (xmax - x2) - yx2;

		fprintf(stderr, "0 (y=%ld) => +1 ; platou: %d - %d (y=%ld); -1 => xmax=%d (y=%ld); %d\n", y1, x1 - d1, x2 + d2, yx1, xmax, y2, (y2 > y1));

		for (x = 0; x <= x1 - d1; x++)
			printf("%ld\n", y1 + x);

		for (x = x1 - d1 + 1; x <= x2 + d2; x++)
			printf("%ld\n", yx1);

		for (x = x2 + d2 + 1; x <= xmax; x++)
			printf("%ld\n", y2 + (xmax - x));
	}

	return 0;
}
