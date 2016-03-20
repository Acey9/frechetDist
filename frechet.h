#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

typedef struct {
    double x;
    double y;
}__point;

void print(double **ca, int m, int n);
double euc_dist(__point  pt1, __point  pt2);
double min(double a, double b, double c);
double _c(double **ca, int i, int j, __point *p, __point *q);
double distance(int m, int n, __point *p, __point *q);
