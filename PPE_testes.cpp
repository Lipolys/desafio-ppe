#include <stdio.h>

void gaussElimination(double sistema[3][4], double x[3]) {
    int i, j, k;
    double factor;
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            factor = sistema[j][i] / sistema[i][i];
            for (k = 0; k < 4; k++) {
                sistema[j][k] -= factor * sistema[i][k];
            }
        }
    }
    for (i = 2; i >= 0; i--) {
        x[i] = sistema[i][3];
        for (j = i + 1; j < 3; j++) {
            x[i] -= sistema[i][j] * x[j];
        }
        x[i] = x[i] / sistema[i][i];
    }
}

int main() {
    // Pontos dados
    double x1 = 4, y1 = 5;
    double x2 = 10, y2 = 5;
    double x3 = 22, y3 = 4;

    // Sistema de equações na forma aumentada [A|B]
    double sistema[3][4] = {
        {x1 * x1, x1, 1, y1},
        {x2 * x2, x2, 1, y2},
        {x3 * x3, x3, 1, y3}
    };

    // Array para armazenar os valores de a, b, c
    double x[3];

    // Resolver o sistema de equações
    gaussElimination(sistema, x);

    double a_coef = x[0];
    double b_coef = x[1];
    double c_coef = x[2];

    // Exibir os coeficientes
    printf("A equação da parábola é: y = %fx^2 + %fx + %f\n", a_coef, b_coef, c_coef);

    return 0;
}
