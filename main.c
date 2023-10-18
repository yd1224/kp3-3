#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int calculateCubicRoot(double p, double q, double d);
int complex calculateExpression(double u, double v);
double x2, x3, y2, y3;
double x1, yFirst, a;
double complex xComplex2, xComplex3, yComplex2, yComplex3;
double getInput(const char *prompt);
bool isScientificNotation(const char *input);
int main(void) {
    double b, c, p, q, d;
    printf("The program finds all solutions including imaginary of cubic equations\n");
    printf("\n");
    printf("x3 + ax2 + bx + c = 0\n");
    printf("\n");
    a = getInput("\tEnter a: ");
    b = getInput("\tEnter b: ");
    c = getInput("\tEnter c: ");
    printf("\n");
    if (a == 0 && b == 0 && c == 0){
        printf("x1 = x2 = x3 = 0\n");
        return 0;
        
    }
    p = b - (a*a)/3;

    
    q = (2*a*a*a)/27 - (a*b)/3 + (c);
    d = (p*p*p/27) + (q*q/4);


    calculateCubicRoot( p,  q,  d);

    return 0;
}





int calculateCubicRoot(double p, double q, double d){
    if(d>0){
        double u, v, rootBase;
        rootBase = q / (-2) + sqrt(d);
        u = (rootBase>0)? (pow(rootBase, 1/3.)):(pow(fabs(rootBase), 1/3.)*(-1));
        v = (-1) * p / (3*u);
        yFirst = u + v;
        calculateExpression( u,  v);
        x1 = yFirst- (a/3);
        xComplex2 = yComplex2 - (a/3);
        xComplex3 = yComplex3 - (a/3);
        printf("x1 = %f\n", x1);
        printf("x2 = %f + %fi\n", creal(xComplex2), cimag(xComplex2));
        printf("x3 = %f + %fi\n", creal(xComplex3), cimag(xComplex3));

    }
    else if (d == 0) {
        yFirst = 3 * q / p;
        y2 = (-1)*3*q/(2*p);
        y3 = y2;
        x1 = yFirst - (a/3);
        x2 = y2 - (a/3);
        x3 = y3 - (a/3);
        printf("x1 = %f\n", x1);
        printf("x2 = %f\n", x2);
        printf("x3 = %f\n", x3);

    }
    else
        if(d<0 && (((-1)*pow(p, 3)/27)>=0)){
        double r;
        r = sqrt(((-1)*pow(p, 3))/27);
        double f = acos((-1)*q/(2*r));
        yFirst = 2 * fabs(pow(r, 1/3.))*cos(f/3);
        y2 = 2 * fabs(pow(r, 1/3.))*cos((f + 2 * M_PI)/3);
        y3 = 2 * fabs(pow(r, 1/3.))*cos((f + 4 * M_PI)/3);
        x1 = yFirst - (a/3);
        x2 = y2 - (a/3);
        x3 = y3 - (a/3);
        printf("x1 = %f\n", x1);
        printf("x2 = %f\n", x2);
        printf("x3 = %f\n", x3);
    }


    return 0;
}


int complex calculateExpression(double u, double v) {
    yComplex2 = (u + v) / (-2) + I * (sqrt(3) * (u - v)) / 2;
    yComplex3 = (u + v) / (-2) - I * (sqrt(3) * (u - v)) / 2;


    return 0;
}

double getInput(const char *prompt) {
    char input[15];
    double number;

    do {
        printf("%s", prompt);
        scanf("%s", input);

        int invalidInput = 0;
        for (int i = 0; input[i] != '\0'; i++) {
            if (isdigit(input[i]) == 0 && input[i] != '.' && input[i] != '-' && !isScientificNotation(input)) {
                printf("\nYour input is invalid\n");
                invalidInput = 1;
                break;
            }
        }

        if (!invalidInput) {
            number = atof(input);
            break;
        }
    } while (1);

    return number;
}
bool isScientificNotation(const char *input) {
    int len = strlen(input);
    int eCount = 0;
    int digitsBeforeE = 0;
    int digitsAfterE = 0;

    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (c == 'e' || c == 'E') {
            eCount++;
        } else if (isdigit(c) && eCount == 0) {
            digitsBeforeE++;
        } else if (isdigit(c) && eCount == 1) {
            digitsAfterE++;
        }
    }


    return (eCount == 1) && (digitsBeforeE > 0) && (digitsAfterE > 0);
}

























