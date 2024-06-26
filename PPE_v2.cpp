#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 500

typedef char string[MAX_LEN];


/* function: iterateOverString 
parameters: array of strings, array of doubles, an index
return: void


Iterates over the string vector in the index passed as a parameter, sending the points found to the array of double
*/

void iterateOverString(string *line, double *values, int index) {
	int j = 0;
    for(int i = 0; i < strlen(line[index]); i++) {
    	if (line[index][i] != '-' && !isalnum(line[index][i])) {
    		if (values[j] != NULL) {
    			j++;
			}
		} else {
			if (line[index][i] != '-') {
    			if (values[j] == NULL) {
    				values[j] = line[index][i];
    				values[j] = values[j] - 48;
				} else {
					values[j] = values [j] * 10;
					values [j] = values[j] + (line[index][i] - 48);
				}
			} else {
				i++;
				if (values[j] == NULL) {
    				values[j] = line[index][i];
    				values[j] = values[j] - 48;
				} else {
					values[j] = values [j] * 10;
					values [j] = values[j] + (line[index][i] - 48);
				}
				values[j] = values[j] * -1;
			}
		}
	}
}

/* function: gaussElimination 
parameters: multidimensional array of doubles, array of doubles
return: void


Finds the coefficients A, B and C of the quadratic function through Gaussian elimination and stores them in the array of doubles
*/
void gaussElimination(double system[3][4], double x[3]) {
    int i, j, k;
    double factor;
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            factor = system[j][i] / system[i][i];
            for (k = 0; k < 4; k++) {
                system[j][k] -= factor * system[i][k];
            }
        }
    }
    for (i = 2; i >= 0; i--) {
        x[i] = system[i][3];
        for (j = i + 1; j < 3; j++) {
            x[i] -= system[i][j] * x[j];
        }
        x[i] = x[i] / system[i][i];
    }
}

/* function: clearVector 
parameters: array of doubles
return: void


Clears the vector received as a parameter 
*/
void clearVector(double *values){
	for (int j = 0; j < 6; j++) {
		values[j] = NULL; 
	}
}

int main () {
    FILE *pointer = fopen("points.txt", "r");
    string line[MAX_LEN];
    double values[6] = {NULL};
    double coefficients[3] = {0};
    int i = 0;
    if (pointer == NULL) {
        printf ("Unable to open file");
    } else {
        printf ("File opened successfully\n");
        while (fgets(line[i], MAX_LEN - 1, pointer) != NULL){
        	printf ("\n%s", line[i]);
        	iterateOverString(line, values, i);
        	double system[3][4] = {
				{values[0] * values[0], values[0], 1, values[1]},
				{values[2] * values[2], values[2], 1, values[3]},
				{values[4] * values[4], values[4], 1, values[5]}
			};
			
			
			gaussElimination(system, coefficients);
			for (int j = 0; j < 3; j++) {
				printf ("%.6f ", coefficients[j]);
			}
			printf ("\n");
			clearVector(values);
			i++;
		}
        fclose (pointer);
    }
    return 0;
}
