#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 500

typedef char string[MAX_LEN];



void iterarSobreString(string *line, int *values, int indice) {
	int j = 0;
    for(int i = 0; i < strlen(line[indice]); i++) {
    	if (line[indice][i] != '-' && !isalnum(line[indice][i])) {
    		if (values[j] != NULL) {
    			j++;
			}
		} else {
			if (line[indice][i] != '-') {
    			if (values[j] == NULL) {
    				values[j] = line[indice][i];
    				values[j] = values[j] - 48;
				} else {
					values[j] = values [j] * 10;
					values [j] = values[j] + (line[indice][i] - 48);
				}
			} else {
				i++;
				if (values[j] == NULL) {
    				values[j] = line[indice][i];
    				values[j] = values[j] - 48;
				} else {
					values[j] = values [j] * 10;
					values [j] = values[j] + (line[indice][i] - 48);
				}
				values[j] = values[j] * -1;
			}
		}
	}
}

int main () {
    FILE *pointer = fopen("points.txt", "r");
    string line[MAX_LEN];
    int values[6] = {NULL};
    int i = 0;
    if (pointer == NULL) {
        printf ("Impossível abrir o arquivo");
    } else {
        printf ("Arquivo aberto com sucesso\n");
        while (fgets(line[i], MAX_LEN - 1, pointer) != NULL){
        	printf ("%s\n", line[i]);
        	iterarSobreString(line, values, i);
        	int system[3][4] = {
			{values[0] * values[0], values[0], 1, values[1]},
			{values[2] * values[2], values[2], 1, values[3]},
			{values[4] * values[4], values[4], 1, values[5]}
			};
        	for (int j = 0; j < 6; j++) {
				printf ("%i ", values[j]);
				values[j] = NULL; //Needed to clear the vector.
			}
			printf ("\n");
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 4; k++) {
					printf ("%i |", system[j][k]);
				}
				printf ("\n");
			}
			i++;
		}
        fclose (pointer);
    }
    
	
    return 0;
}
