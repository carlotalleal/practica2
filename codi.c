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

//exercici 1:
void PrintVect( float vect[N], int from, int numel ){
int i;
//se declaran i definen las variables
for( i = from; i < (numel+ from); i++ ){
    printf("%.2f ", vect[i]);
//printear el vector con 2 decimales de precisión
}
}

//exercici 2
void PrintRow( float mat[N][N], int row, int from, int numel ) {
int i;
for (i=from;i<numel;i++){
    printf("%f ",mat[row][i]);
}
}

//exercici 3:
void MultEscalar( float vect[N], float vectres[N], float alfa ){
    int i;
//se declaran i definen las variables
    for( i = 0; i < N; i++ ){
        vectres[i]= vect[i]*alfa;
//mulpiplicar cada elemonto del vector por alfa(un número)
    } 
}

//exercici 4:
float Scalar( float vect1[N], float vect2[N] ){
    int i;
    float pe;
    pe= 0;
//se declaran i definen las variables
    for( i = 0; i < N; i++ ){
        pe= pe + (vect1[i] * vect2[i]);
//se suman los elementos de v1 y v2 con el mismo incice
    }
    return(pe);
//se devuelve toda la suma acumulada
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

//exercici 6:
int Ortogonal( float vect1[N], float vect2[N] ){
    int ort;
    float pe;
//se declaran i definen las variables
    pe= Scalar( vect1,vect2);
//se utiliza la función anterior para hacer el rpoducto escalar
    if (pe){
        ort=1;
    }else {
        ort=0;
    }
//se mira si es ortogonal o no
    return(ort);
}

//exercici 7
void Projection(float vect1[N],float vect2[N],float vectres[N]){
int pe;
pe= Scalar (vect1,vect2);
int mod;  
mod= Magnitude (vect2);
int temp;
temp: pe/mod;
MultEscalar(vect2,vectres,temp);
}

//exercici 8
float Infininorm( float M[N][N] ){
     int i, ii;
     float comp, acum, m;
     comp = 0;
//se declaran i definen las variables
     for( i = 0; i < N; i++ ){
        acum = 0;
//declaramos y reiniciamos el acumulador a 0 cada que cambia la fila
        for (ii = 0; ii < N; ii++){
            m= fabs(M[i][ii]);
            acum = m + acum;
//se acumula la suma de la linea completa
        }
        if (acum > comp){
            comp = acum;
//se mira si es mayor que el comparador(la fila mayor hasta ese momento)
        }
     }
     return(comp);
}

//exercici 9
float Onenorm( float M[N][N] ){
    int i, ii;
    float comp, acum, m;
    comp = 0;
//se declaran i definen las variables
    for( i = 0; i < N; i++ ){
       acum = 0;
//declaramos y reiniciamos el acumulador a 0 cada que cambia la columna
       for (ii = 0; ii < N; ii++){
           m= fabs(M[ii][i]);
           acum = m + acum;
//se acumula la suma de la columna completa
       }
       if (acum > comp){
           comp = acum;
//se mira si es mayor que el comparador(la fila mayor hasta ese momento)
       }
    }
    return(comp);
}


//exercici 10
float NormFrobenius( float M[N][N] ){
    int i, ii;
    float acum, m;
//se declaran i definen las variables
    for( i = 0; i < N; i++ ){
        for (ii = 0; ii < N; ii++){
            m= pow(M[i][ii], 2);
            acum = m + acum;
        }
    }
    return(acum);
}

//exercici 11
int DiagonalDom( float M[N][N] ){
    int i, ii, DD;
    float acum, m;
    ii=0;
    acum=0;
    DD= 1;
//se declaran i definen las variables
    for( i = 0; i < N; i++ ){
        acum = 0;
//declaramos y reiniciamos el acumulador a 0 cada que cambia la fila
        for (ii = 0; ii < N; ii++ ){
            if (ii!=i){
//se mira si el numero de filas es igual al numero de columnas 
                m = fabs(M[ii][i]);
                acum = acum + m;
//se acumula la linea exclyendo la orden anterior
            }
        }
        if (acum < M[i][i]);
            DD= 0;
//se mira si es de diagonal dominante o no
    }
    return(DD);
}

//exercici 13
int Jacobi( float M[N][N] , float vect[N], float vectres[N], unsigned iter ){
    int DD,Jb;
    float xN[N], s;
    iter = 0;
    DD= DiagonalDom(M);
    if (DD==1){
        vectres[0]= 0;
        for (int v = 0; v < iter; v++){
            for (int i = 0; i < N; i++) {
                s = 0;
                for (int ii = 0; ii < N; ii++) {
                    if (i != ii) {
                        s += M[i][ii] * vectres[ii-1];
                    }
                }
                xN[i] = (vect[i] - s) / M[i][i];
            }
            for (int i = 0; i < N; i++){
                vectres[i]= xN[i];
            }
        }
    }
    else{
        Jb= 0;
    } 
}
