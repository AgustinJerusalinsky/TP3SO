#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define FALSE 0
#define TRUE 1

double generateGaussian(double mean, double stdDev);

double generateGaussian(double mean, double stdDev) {
    static double spare;
    static char hasSpare = FALSE;

    if (hasSpare) {
        hasSpare = FALSE;
        return spare * stdDev + mean;
    } else {
        double u, v, s;
        do {
            u = (rand() / ((double)RAND_MAX)) * 2.0 - 1.0;
            v = (rand() / ((double)RAND_MAX)) * 2.0 - 1.0;
            s = u * u + v * v;
        } while (s >= 1.0 || s == 0.0);
        s = sqrt(-2.0 * log(s) / s);
        spare = v * s;
        hasSpare = TRUE;
        return mean + stdDev * u * s;
    }
}