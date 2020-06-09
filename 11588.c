#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int Case, i, j, r, c, m, n, test = 1;
	scanf("%d", &Case);
	while (Case--)
	{
		scanf("%d %d %d %d", &r, &c, &m, &n);
		int num[26] = { 0 }, max = 0, sum = 0;
		char  RC[20][20] = {'\0'};
		for (i = 0; i < r; i++) {
			getchar();
			for (j = 0; j < c; j++)
				scanf("%c", &RC[i][j]);
		}
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				num[RC[i][j] - 'A']++;
				if (num[RC[i][j] - 'A'] > num[max])
					max = RC[i][j] - 'A';
			}
		}
		for (i = 0; i < 26; i++) {
			if (num[i] == num[max])
				sum += num[i] * m;
			else sum += num[i] * n;
		}
		printf("Case %d: %d\n", test++, sum);
	}
	return 0;
}
