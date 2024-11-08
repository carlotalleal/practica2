//ctrl S guarda
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
//declarem i definim les variables
for( i = from; i < (numel+ from); i++ ){
    printf("%.2f ", vect[i]);
//printear el vector amb 2 decimals de precissió
}
}

//exercici 2
void PrintRow( float mat[N][N], int row, int from, int numel ) {
int i;
//declarem i definim les variables
for (i=from;i<numel+from ;i++){
    printf("%f ",mat[row][i]);
//printeem la fila i amb 2 decimals de precissió
}
}

//exercici 3:
void MultEscalar( float vect[N], float vectres[N], float alfa ){
    int i;
//declarem i definim les variables
    for( i = 0; i < N; i++ ){
        vectres[i]= vect[i]*alfa;
//mulpiplicar cada element del vector per alfa(un número)
    } 
}

//exercici 4:
float Scalar( float vect1[N], float vect2[N] ){
    int i;
    float pe;
    pe= 0;
//declarem i definim les variables
    for( i = 0; i < N; i++ ){
        pe= pe + (vect1[i] * vect2[i]);
//sumem els elements de v1 i v2 mamb el mateix índex multiplicats
    }
    return(pe);
//es retorna la suma acumulada
}

//exercici 5
float Magnitude( float vect[N] ){
    int i;
    float res, sum=0;
//declarem i definim les variables
    sum = Scalar(vect, vect);
//elevem al quadrat el vector índex amb la funció scalar
    res =sqrt(sum);
//fem l'arrel quadrada
    return (res);
}

//exercici 6:
int Ortogonal( float vect1[N], float vect2[N] ){
    int ort;
    float pe;
//declarem i definim les variables
    pe= Scalar( vect1,vect2);
//s'utiliza la funció anterior per fer el rpoducto escalar
    if (pe==0){
        ort=1;
    }else {
        ort=0;
    }
//mirem si es ortogonal o no
    return(ort);
}

//exercici 7
void Projection(float vect1[N],float vect2[N],float vectres[N]){
int pe, mod, temp;
//declarem i definim les variables
pe= Scalar (vect1,vect2); 
mod= Magnitude (vect2);
//fem el producte escalar de v1 i v2 i el módul de v2
temp= pe/(mod*mod);
//dividim els resultats de les ordres anteriors
MultEscalar(vect2,vectres,temp);
//i fem el multiescalar amb el temp i el vector 2 (vecttres es a resposta)
}

//exercici 8
float Infininorm( float M[N][N] ){
     int i, ii;
     float comp, acum, m;
     comp = 0;
//declarem i definim les variables
     for( i = 0; i < N; i++ ){
        acum = 0;
//declaram y reiniciem el acumulador a 0 cada vegada que cambia la fila
        for (ii = 0; ii < N; ii++){
            m= fabs(M[i][ii]);
            acum = m + acum;
//acumulem la suma de la linea completa
        }
        if (acum > comp){
            comp = acum;
//mirem si es més gran que el comparador(la fila més gran fins el moment)
        }
     }
     return(comp);
}

//exercici 9
float Onenorm( float M[N][N] ){
    int i, ii;
    float comp, acum, m;
    comp = 0;
//declarem i definim les variables
    for( i = 0; i < N; i++ ){
       acum = 0;
//declaram y reiniciem el acumulador a 0 cada vegada que cambia la colunma
       for (ii = 0; ii < N; ii++){
           m= fabs(M[ii][i]);
           acum = m + acum;
//acumulem la suma de la columna completa
       }
       if (acum > comp){
           comp = acum;
//mirem si es més gran que el comparador(la calumna més gran fins el moment)
       }
    }
    return(comp);
}


//exercici 10
float NormFrobenius( float M[N][N] ){
    int i, ii;
    float acum, m;
    acum = 0;
//declarem i definim les variables
    for( i = 0; i < N; i++ ){
        for (ii = 0; ii < N; ii++){
//fem un doble for, un per files i un altre per colunmes
            m= pow(M[i][ii], 2);
//elevem al quadrat
            acum = m + acum;
//li sumem al acumulat
        }
    }
    return(sqrt(acum));
//li fem la arrel i retornem el valor
}

//exercici 11
int DiagonalDom( float M[N][N] ){
    int i, ii, DD;
    float acum, m;
    ii=0;
    acum=0;
    DD= 1;
//declarem i definim les variables
    for( i = 0; i < N; i++ ){
        acum = 0;
//declaram y reiniciem el acumulador a 0 cada vegada que cambia la fila
        for (ii = 0; ii < N; ii++ ){
            if (ii!=i){
//es mira si el numero de filas es igual al numero de columnas 
                m = fabs(M[ii][i]);
                acum = acum + m;
//s'acumula la línea sense la ordre anterior
            }
        }
        if (acum >= M[i][i])
            DD= 0;
//es mira si es de diagonal dominant o no
    }
    return(DD);
}

//exercici 12
void Matriu_x_Vector (float M[N][N], float vect1[N], float vectres[N]){
    int i, ii;
    float acum, m;
    acum=0;
//declarem i definim les variables
    for( i = 0; i < N; i++ ){
        for (ii = 0; ii < N; ii++){
//fem un doble for, un per files i un altre per columnes
            m= M[i][ii]*vect1[ii];
//multipliquem cada element de la matriu per el índex del vecrtor corresponent
            acum = acum + m;
//sumem al acumulat
        }
        vectres[i]=acum;
    }
}

//exercici 13
int Jacobi( float M[N][N] , float vect[N], float vectres[N], unsigned iter ){
    int DD,Jb;
    float xN[N], s;
    iter = 0;
    DD= DiagonalDom(M);
//declarem i definim les variables i mirem si es DD o no
    if (DD==1){
//mirem si es diagonal dominant
        vectres[0]= 0;
//definim el primer item com a zero
        Jb= 1;
        for (int v = 0; v < iter; v++){
//repetim tot iter vegades
            for (int i = 0; i < N; i++) {
                s = 0;
//reiniciem la variable s
                for (int ii = 0; ii < N; ii++) {
                    if (i != ii) {
//mirem si el element forma part de la diagonal
                        s += M[i][ii] * vectres[ii-1];
//si no ho fa li multipliquem vect -1 al índex de la matriu
                    }
                }
                xN[i] = (vect[i] - s) / M[i][i];
//ho acumulem a un vector auxiliar, la resta del vector i la multiplicació anterior dividir per l'index de la matriu
            }
            for (int i = 0; i < N; i++){
                vectres[i]= xN[i];
//aixó ho acumulen a un vector resultat
            }
        }
    }
    else{
        Jb= 0;
    } 
    return(Jb);
}

int main(){
    int i, j;
    float Mat[N][N], MatDD[N][N], V1[N], V2[N], V3[N];
    
    //a
    InitData();
    PrintVect(V1,0,10);
    PrintVect(V1,256,9);
    PrintVect(V2,0,10);
    PrintVect(V2,256,9);
    PrintVect(V3,0,10);
    PrintVect(V3,256,9);


    //b
    PrintRow(Mat,1,0,10);
    PrintRow(Mat,100,0,10);


    //c
    PrintRow(MatDD,0,0,10);
    PrintRow(MatDD,100,90,10);


    //d
    float INM, ONM, DDM;
    INM=Infininorm(Mat);
    printf("Infininorma de Mat %f",INM);
    ONM=Onenorm(Mat);
    printf("Norma ú de Mat %f",ONM);
    if (DiagonalDom(Mat)==1){
        printf("La matriu Mat és diagonal dominant");
    }
    else{
        printf("La matriu Mat no és diagonal principal");
    }


    float INMD, ONMD, DDMD;
    INMD=Infininorm(MatDD);
    printf("Infininorma de MatDD %f",INMD);
    ONMD=Onenorm(MatDD);
    printf("Norma ú de MatDD %f",ONMD);
    if (DiagonalDom(MatDD)==1){
        printf("La matriu MatDD és diagonal dominant");
    }
    else{
        printf("La matriu MatDD no és dagonal principal");
    }
   
    //e
    float res1, res2, res3;
    res1=Scalar(V1,V2);
    printf("Escalar<V1,V2>=%f",res1);
    res2=Scalar(V1,V3);
    printf("Escalar<V1,V3>=%f",res2);
    res3=Scalar(V2,V3);
    printf("Escalar<V2,V3>=%f",res3);


    //f
    float mag1, mag2, mag3;
    mag1=Magnitude(V1);
    mag2=Magnitude(V2);
    mag3=Magnitude(V3);
    printf ("Magnitud V1, V2, V3= %f %f %f",mag1,mag2,mag3);


    //g
   int ort1, ort2, ort3;
   ort1= Ortogonal(V1, V2);
   ort2= Ortogonal(V1, V3);
   ort3= Ortogonal(V3, V2);
    if (ort1==1)
        printf("V1 i V2 són ortogonals");
    if (ort2==1)
        printf("V1 i V3 són ortogonals");
    if (ort3==1)
        printf("V3 i V2 són ortogonals");

//h
    float r[N];
    MultEscalar(V3, r, 2); 
    printf("Els elements 0 al 9 i 256 al 265 del resultat de multiplicar V3x2.0 són:");
    printf( "%f %f %f %f %f %f %f %f %f %f\n", 
           V3[1], V3[2], V3[3], V3[4], V3[5], V3[6], V3[7], V3[8], V3[9], V3[10]);
    printf( "%f %f %f %f %f %f %f %f %f %f\n", 
           V3[256], V3[257], V3[258], V3[259], V3[260], V3[261], V3[262], V3[263], V3[264], V3[265]);

//i
    float proj[N], proj2[N];
    Projection(V2,V3, proj);
    Projection(V1,V2, proj2);
    printf("Els elements 0 a 9 del resultat de la projecció de V2 sobre V3 són:");
    printf( "%f %f %f %f %f %f %f %f %f %f\n", 
           proj[1], proj[2], proj[3], proj[4], proj[5], proj[6], proj[7], proj[8], proj[9], proj[10]);
    printf("Els elements 0 a 9 del resultat de la projecció de V1 sobre V2 són:");
    printf( "%f %f %f %f %f %f %f %f %f %f\n", 
           proj2[1], proj2[2], proj2[3], proj2[4], proj2[5], proj2[6], proj2[7], proj2[8], proj2[9], proj2[10]);

//j
    float vect3[N];
    Matriu_x_Vector (Mat, V2,vect3);
    printf("Els elements 0 a 9 del resultat de la multiplicació de Mat per v2 són:");
    printf( "%f %f %f %f %f %f %f %f %f %f\n", 
           vect3[1], vect3[2], vect3[3], vect3[4], vect3[5], vect3[6], vect3[7], vect3[8], vect3[9], vect3[10]);

//k
    float vr1[N], vr2[N];
    Jacobi( MatDD, V3, vr1, 1);
    Jacobi( MatDD, V3, vr2, 1000);
    printf("Els elements 0 a 9 de la solució (1 iter) del sistema d'equacions són:");
    printf( "%f %f %f %f %f %f %f %f %f %f\n", 
           vr1[1], vr1[2], vr1[3], vr1[4], vr1[5], vr1[6], vr1[7], vr1[8], vr1[9], vr1[10]);
    printf("Els elements 0 a 9 de la solució (1000 iters) del sistema d'equacions són:");
    printf( "%f %f %f %f %f %f %f %f %f %f\n", 
           vr2[1], vr2[2], vr2[3], vr2[4], vr2[5], vr2[6], vr2[7], vr2[8], vr2[9], vr2[10]);


}