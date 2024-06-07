#include <stdio.h>

int main () {
	int x = 0, y = 0;
	FILE *fp = NULL;
	FILE *gnupipe = NULL;
	char *gnuCommands[] = {"set title \"Demo\"", "plot'orderedPairs.txt'"};
	
	fp = fopen ("orderedPairs.txt", "w");
	gnupipe = _popen("gnuplot -persitent", "w");
	
	for (int i = 0; i < 11; i++) {
		fprintf (fp, "%d %d\n", x, y);
		
		x++;
		y++;
	}
	
	for (int i = 0; i < 2; i++) {
		fprintf (gnupipe, "%s\n", gnuCommands[i]);
	}
    return 0;
}
