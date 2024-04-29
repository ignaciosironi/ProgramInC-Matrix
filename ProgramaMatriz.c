#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargar(int matriz[3][3], int dim);
void mostrar(int matriz[3][3], int dim);
void conversionMatrizDiagonal(int matriz[3][3], int dim);
void reconocerMatrizAntisimetrica(int matriz[3][3],int dim);

int main()
{
    
    int matriz[3][3], dim=3;
    
    cargar(matriz, dim);
    mostrar(matriz, dim);
    conversionMatrizDiagonal(matriz, dim);
    printf("cargar una nueva matriz para saber si es antisimétrica, ya que la anterior matriz ya no sirve: \n");
    cargar(matriz, dim);
    printf("la nueva matriz es: \n");
    mostrar(matriz, dim);
    reconocerMatrizAntisimetrica(matriz,dim);

    return 0;
}

void cargar(int matriz[3][3], int dim){
    int i, j;
    
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            printf("Ingrese valor para la fila %d y la columna %d: \n", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrar(int matriz[3][3], int dim){
    int i,j;
    
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }
}

void conversionMatrizDiagonal(int matriz[3][3], int dim){
    int i,j;
    
    printf("La matriz diagonal es: \n");
    
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            
            if(i==j){
                printf("%d\t",matriz[i][j]);    
            }
            else {
                matriz[i][j]=0;
                printf("%d\t",matriz[i][j]);
            }
            
        }
        printf("\n");
    }
}

void reconocerMatrizAntisimetrica(int matriz[3][3],int dim){
    int i,j, cont=0;
    
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            if((i!=j)&&(matriz[i][j]==(matriz[j][i]*-1))){
                cont++; 
            }
        }
    }
    printf("Hay %d valores por encima o debajo de la diagonal principal que son iguales pero opuestos.\n",cont);
    
    if((cont/2)==((dim*dim)-dim)/2){
       printf("la matriz es antisimétrica"); 
    }
    else{
        printf("la matriz no es antisimétrica");
    }
}