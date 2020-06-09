#include <cstdio>
#include <cctype>
#include <cstring>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int i, j, people, songRepeat = 16, order = 0;
	char str[100][100] = { '\0' };
	char song[16][10] = { "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
	scanf("%d", &people);
	getchar();
	for (i = 0; i < people; i++) {
		fgets(str[i], sizeof(str[i]), stdin);
		str[i][strlen(str[i]) - 1] = '\0';
	}
	if (people > 16) {
		if (people % 16 == 0)
			songRepeat = people;
		else songRepeat = ((people / 16) + 1) * 16;
	}
	for (i = 0; i < songRepeat; i++) {
		if (order == people)
			order = 0;
		printf("%s: %s\n", str[order++], song[i % 16]);
	}
	return 0;
}
