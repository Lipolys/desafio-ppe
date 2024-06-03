#include <stdio.h>

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

int main() {
    // Pontos dados
    double x0 = 1, x1 = 3;
    double x2 = 2, x3 = 8;
    double x4 = 3, x5 = 15;

    // system de equações na forma aumentada [A|B]
    double system[3][4] = {
        {x0 * x0, x0, 1, x1},
        {x2 * x2, x2, 1, x3},
        {x4 * x4, x4, 1, x5}
    };

    // Array para armazenar os valores de a, b, c
    double x[3];

    // Resolver o system de equações
    gaussElimination(system, x);

    double a_coef = x[0];
    double b_coef = x[1];
    double c_coef = x[2];

    // Exibir os coeficientes
    printf("A equação da parábola é: y = %fx^2 + %fx + %f\n", a_coef, b_coef, c_coef);

    return 0;
}
