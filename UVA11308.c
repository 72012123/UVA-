#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
int main()
{
	int Case, i, j, k, b, m, n, test;
	scanf("%d", &Case);
	while (Case--)
	{
		char name[100] = { '\0' }, ingredient[100][50] = { '\0' };
		char way[100][50] = { '\0' }, temp[100][50] = { '\0' }, swapstr[100];
		int price[100] = { 0 }, count, num[100] = { 0 }, swap;
		bool expensive = true;
		getchar();
		fgets(name, sizeof(name), stdin);
		scanf("%d %d %d", &m, &n, &b);
		for (i = 0; i < m; i++) {
			getchar();
			for (j = 0; ; j++) {
				scanf("%c", &ingredient[i][j]);
				if (ingredient[i][j] == ' ') {
					ingredient[i][j] = '\0';
					scanf("%d", &num[i]);
					break;
				}
			}
		}
		for (i = 0; i < n; i++) {
			getchar();
			fgets(way[i], sizeof(way[i]), stdin);
			scanf("%d", &test);
			for (j = 0; j < test; j++) {
				getchar();
				for (k = 0; ; k++) {
					scanf("%c", &temp[j][k]);
					if (temp[j][k] == ' ') {
						temp[j][k] = '\0';
						scanf("%d", &count);
						break;
					}
				}
				for (k = 0; k < m; k++) {
					if (strcmp(ingredient[k], temp[j]) == 0)
						price[i] += num[k] * count;
				}
			}
		}
		for (i = 0; i < sizeof(name); i++) {
			if (name[i] == '\n')
				break;
			printf("%c", toupper(name[i]));
		}
		printf("\n");
		if (n > 1) {
			for (i = 0; i < n; i++) {
				for (j = i + 1; j < n; j++) {
					if (price[j] < price[i]) {
						strcpy(swapstr, way[i]);
						strcpy(way[i], way[j]);
						strcpy(way[j], swapstr);
						swap = price[i];
						price[i] = price[j];
						price[j] = swap;
					}
					else if (price[j] == price[i]) {
						if (strcmp(way[i], way[j]) > 0) {
							strcpy(swapstr, way[i]);
							strcpy(way[i], way[j]);
							strcpy(way[j], swapstr);
						}
					}
				}
			}
		}
		for (i = 0; i < n; i++) {
			if (price[i] <= b) {
				printf("%s", way[i]);
				expensive = false;
			}
		}
		if (expensive == true)
			printf("Too expensive!\n");
		printf("\n");
	}
	return 0;
}
