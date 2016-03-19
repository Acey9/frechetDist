#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#include "frechet.h"

void print(double **ca, int m, int n) {
        int i, j;
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++){
                printf("\t%f", ca[i][j]);
                }
            printf("\n");
            }
        }


double euc_dist(point  pt1, point  pt2) {
        double ua, ub;
        ua = pt2.x - pt1.x;
        ub = pt2.y - pt1.y;
        return sqrt(ua*ua + ub*ub);
        }

double max(double a, double b) {
        return a > b?a:b;
        }

double min(double a, double b, double c) {
        double m;
        m = a < b?a:b;
        return m < c?m:c;
        }
double _c(double **ca, int i, int j, point *p, point *q) {
        if (ca[i][j] > -1) {
            return ca[i][j];
            }
        else if (i == 0 && j == 0) {
            ca[i][j] = euc_dist(p[0],q[0]);
            }
        else if (i > 0 && j == 0) {
            ca[i][j] = max(_c(ca,i-1,0,p,q),euc_dist(p[i],q[0]));
            }
        else if (i == 0 && j > 0) {
            ca[i][j] = max(_c(ca,0,j-1,p,q),euc_dist(p[0],q[j]));
            }
        else if (i > 0 && j > 0) {
            ca[i][j] = max(
                min(
                    _c(ca,i-1,j,p,q),
                    _c(ca,i-1,j-1,p,q),
                    _c(ca,i,j-1,p,q)
                    ),
                euc_dist(p[i],q[j])
                );
            }
        else {
            //TODO
            //inf
            ca[i][j] = DBL_MAX;
            }
        return ca[i][j];
        }

double frechetDist(int m, int n, point *p, point *q) {
        int i,j;
        double dist;
        double **ca = NULL;
        ca = (double**)malloc(m*sizeof(double));
        for(i=0; i<m; i++) {
            ca[i] = (double *)malloc(n *sizeof(double));
            }
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++){
                ca[i][j] = -1.0;
                }
            }

        dist = _c(ca, m-1, n-1, p, q);
        //print(ca, m, n);
        for(i=0; i<m; i++) {
            free(ca[i]);
            }
        free(ca);
        ca = NULL;

        //printf("frechetDist:%f\n", dist);
        return dist;
        }
        
  void main(int argc, char** argv) {
        double dist;
        point p[2] = {{0,0}, {0,0}};
        p[0].x = 0;
        p[0].y = 1;
        p[1].x = 1;
        p[1].y = 2;

        point q[2] = {{0,0}, {0,0}};
        q[0].x = 0;
        q[0].y = 1;
        q[1].x = 1;
        q[1].y = 20;

        dist = frechetDist(2, 2, p, q);
        }
