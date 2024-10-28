//ctrl S guarda
#include <stdio.h>
#include <stdlib.h>

#define N 512

void InitData(){
int i,j;
srand(334411);

float Mat[i][j], MatDD[i][j], V1[N], V2[N], V3[N];

for( i = 0; i < N; i++ ){
    for( j = 0; j < N; j++ ){
        Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
    if ( (abs(i - j) <= 3) && (i != j))
        MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
    else if ( i == j )
        MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
    else MatDD[i][j] = 0.0;
 }
}
for( i = 0; i < N; i++ ){
    V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
    V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
    V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
}
}

//ex1:
void PrintVect( float vect[N], int from, int numel ){
int i;
for( i = from; i < numel; i++ ){
    printf("%.2f ", vect[i]);
}
}

//exercici 2
void PrintRow( float mat[N][N], int row, int from, int numel ) {
int i;
for (i=from;i<numel;i++){
    printf("%f ",mat[row][i]);
}
}

//ex3:
void MultEscalar( float vect[N], float vectres[N], float alfa ){
    int i;
    for( i = 0; i < N; i++ ){
        vectres[i]= vect[i]*alfa;
    } 
}

//ex4:
float Scalar( float vect1[N], float vect2[N] ){
    int i;
    float pe;
    pe= 0;
    for( i = 0; i < N; i++ ){
        pe= pe + (vect1[i] * vect2[i]);
    }
    return(pe);
}

//exercici 5
float Magnitude( float vect[N] ){
    int i;
    float sum=0;
    for (i =0 ;i < N;i++){
        sum=sum+(vect[i]*vect[i]);
    }
    float res=sqrt(sum);
    return (res);
}

//ex6:
int Ortogonal( float vect1[N], float vect2[N] ){
    int ort;
    float pe;
    pe= Scalar( vect1,vect2);
    if (pe){
        ort=1;
    }else {
        ort=0;
    }
    return(ort);
}

//ex8
float Infininorm( float M[N][N] ){
     int i, ii;
     float comp, acum, m;
     comp = 0;
     for( i = 0; i < N; i++ ){
        acum = 0;
        for (ii = 0; ii < N; ii++){
            m= fabs(M[i][ii]);
            acum = m + acum;
        }
        if (acum > comp){
            comp = acum;
        }
     }
     return(comp);
}

//ex9
float Onenorm( float M[N][N] ){
    int i, ii;
    float comp, acum, m;
    comp = 0;
    for( i = 0; i < N; i++ ){
       acum = 0;
       for (ii = 0; ii < N; ii++){
           m= fabs(M[ii][i]);
           acum = m + acum;
       }
       if (acum > comp){
           comp = acum;
       }
    }
    return(comp);
}


//ex10
float NormFrobenius( float M[N][N] ){
    int i, ii;
    float acum, m;
    for( i = 0; i < N; i++ ){
        for (ii = 0; ii < N; ii++){
            m= pow(M[i][ii], 2);
            acum = m + acum;
        }
    }
    return(acum);
}


//ex11
int DiagonalDom( float M[N][N] ){
    int i, ii, DD;
    float acum, m;
    ii=0;
    acum =0;
    for( i = 0; i < N; i++ ){
        if (ii!=i){
            m = fabs(M[ii][i]);
            acum = acum + m;
        }
        ii= ii+1;
    }
}
