#include<stdio.h>
#include<stdlib.h>

float juros_comp_rec(float valor, int meses, float juros){
    float resultado;
    if (meses==0)
        return 0;
    resultado=valor+(juros*(valor/100));
    return resultado+juros_comp_rec(valor,meses-1,juros);
}


int main(){
	float v,j,r;
	int m;
	printf("Digite o valor a ser cobrado (em reais): ");
	scanf("%f",&v);
	printf("\nDigite o numero de meses a serem cobrados os juros: ");
	scanf("%d",&m);
	printf("\nDigite o o valor dos juros (em porcentagem): ");
	scanf("%f",&j);
    r=juros_comp_rec(v,m,j);
    printf("\nO valor a ser pago depois do juros composto calculado e: %.2f\n\n",r);
    system("pause");
    return 0;
}
