#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 50 

typedef char string[LEN];

int main () {
    FILE *pointer = fopen("points.txt", "r");
    string line[LEN];
    char lineString[50];
    int values[6] = {NULL};
    if (pointer == NULL) {
        printf ("Impossível abrir o arquivo");
    } else {
        printf ("Arquivo aberto com sucesso");
        
        fgets(line[0], LEN - 1, pointer);
        fgets(lineString, LEN - 1, pointer);
        printf ("%s", line[0]);
        
        fclose (pointer);
    }
    int j = 0;
    for(int i = 0; i < strlen(line[0]); i++) {
    	if (line[0][i] != '-' && !isalnum(line[0][i])) {
    		if (values[j] != NULL) {
    			j++;
			}
		} else {
			if (line[0][i] != '-') {
    			if (values[j] == NULL) {
    				values[j] = line[0][i];
    				values[j] = values[j] - 48;
				} else {
					values[j] = values [j] * 10;
					values [j] = values[j] + (line[0][i] - 48);
				}
			} else {
				i++;
				if (values[j] == NULL) {
    				values[j] = line[0][i];
    				values[j] = values[j] - 48;
				} else {
					values[j] = values [j] * 10;
					values [j] = values[j] + (line[0][i] - 48);
				}
				values[j] = values[j] * -1;
			}
		}
	}
	for (int i = 0; i < 6; i++) {
		printf ("%i ", values[i]);
	}
	
	int b = atoi(lineString);
	printf ("\n\n\n%i", b);
    return 0;
}
