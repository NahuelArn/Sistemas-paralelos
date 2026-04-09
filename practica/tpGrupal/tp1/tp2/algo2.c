#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 256

// ----------- DWALLTIME -----------
double dwalltime(){
    double sec;
    struct timeval tv;

    gettimeofday(&tv,NULL);
    sec = tv.tv_sec + tv.tv_usec/1000000.0;
    return sec;
}

// ----------- FUNCIONES -----------

double max(double inMatrix[N][N]){
    double out = inMatrix[0][0];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if(inMatrix[i][j] > out)
                out = inMatrix[i][j];
    return out;
}

double min(double inMatrix[N][N]){
    double out = inMatrix[0][0];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if(inMatrix[i][j] < out)
                out = inMatrix[i][j];
    return out;
}

double prom(double inMatrix[N][N]){
    double suma = 0;
    int cant = 0;

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++){
            suma += inMatrix[i][j];
            cant++;
        }

    return suma / cant;
}

void transponer(double original[N][N], double traspuesta[N][N]){
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            traspuesta[j][i] = original[i][j];
}

void multiplicar(double A[N][N], double B[N][N], double R[N][N]) {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) {
            R[i][j] = 0;
            for(int k=0;k<N;k++)
                R[i][j] += A[i][k] * B[k][j];
        }
}

void escalar(double M[N][N], double k) {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            M[i][j] *= k;
}

// ----------- MAIN -----------

int main(){

    static double A[N][N], B[N][N], BT[N][N];
    static double C[N][N], R[N][N];

    // llenar matrices
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }

    double tick = dwalltime();

    double maxA = max(A);
    double minA = min(A);
    double promA = prom(A);

    double maxB = max(B);
    double minB = min(B);
    double promB = prom(B);

    double factor = (maxA*maxB - minA*minB) / (promA * promB);

    transponer(B, BT);

    multiplicar(A, B, C);
    multiplicar(C, BT, R);

    escalar(R, factor);

    double tiempo = dwalltime() - tick;

    printf("Tiempo total: %f segundos\n", tiempo);

    return 0;
}