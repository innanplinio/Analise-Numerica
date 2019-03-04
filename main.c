#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void trapezio ()
{
    int i,part;
    float h,inf,sup,f[50], integral = 0;
    printf("Limite inferior = ");
    scanf("%f", &inf);
    printf("Limite superior = ");
    scanf("%f", &sup);
    printf("Particoes do intervalo = ");
    scanf("%d", &part);
    for (i = 0; i <=part; i++){
        printf("Valor de y(%d):\n",i);
        scanf("%f",&f[i]);
    }
    h = (sup-inf)/part;
    for (i = 0; i <=part; i++){
        if(i==0||i==part)
            integral=integral+f[i];
        else
            integral=integral+(2*f[i]);
    }
    integral = integral * h / 2;
    printf("Integral= %.4f\n", integral);
}

void primeiraSimpson ()
{
    int i,part;
    float h,inf,sup,f[50], integral = 0;
    printf("Limite inferior = ");
    scanf("%f", &inf);
    printf("Limite superior = ");
    scanf("%f", &sup);
    printf("Particoes do intervalo= ");
    scanf("%d", &part);
    for (i = 0; i <=part; i++){
        printf("Valor de y(%d):\n",i);
        scanf("%f",&f[i]);
    }
    h = (sup-inf)/part;
    for (i = 0; i <=part; i++){
        if(i==0||i==part)
            integral=integral+f[i];
        else if(i%2==0)
            integral=integral+(2*f[i]);
        else
            integral=integral+(4*f[i]);
    }
    integral = integral * h / 3;
    printf("Integral=  %.4f\n", integral);
}

void segundaSimpson ()
{
    int i,part;
    float h,inf,sup,f[50], integral = 0;
    printf("Limite inferior = ");
    scanf("%f", &inf);
    printf("Limite superior = ");
    scanf("%f", &sup);
    printf("Particoes do intervalo = ");
    scanf("%d", &part);
    for (i = 0; i <=part; i++){
        printf("Valor de y(%d):\n",i);
        scanf("%f",&f[i]);
    }
    h = (sup-inf)/part;
    for (i = 0; i <=part; i++){
        if(i==0||i==part)
            integral=integral+f[i];
        else if(i%3==0)
            integral=integral+(2*f[i]);
        else
            integral=integral+(3*f[i]);
    }
    integral = integral * 3*h / 8;
    printf("Integral=  %.4f\n", integral);
}

void Newton()
{
    float vet1[50], vet2[50], p[50], xp, f;
    int j=1;
    float f1=1,f2=0;
    int n,i;
    printf("\n qtd numeros na tabela? \n");
    scanf("%d", &n);
    printf("Dados: \n");
    for (i=1; i<=n; i++){
        printf("Valor de x%d: ",i);
        scanf("%f", &vet1[i]);
        printf("Valor de y%d: ",i);
        scanf("%f", &vet2[i]);
    }

    f=vet2[1];
    printf("\n Digite o valor de P(x): \n");
    scanf("%f", &xp);

    do{
        for (i=1; i<=n-1; i++){
            p[i] = ((vet2[i+1]-vet2[i])/(vet1[i+j]-vet1[i]));
            vet2[i]=p[i];
        }
        f1=1;
        for(i=1; i<=j; i++){
            f1*=(xp-vet1[i]);
        }
        f2+=(vet2[1]*f1);
        n--;
        j++;
    }

    while(n!=1);
    f+=f2;
    printf("Resultado:\n");
    printf("\nf(%f) = %f", xp, f);
}

void Lagrange()
{
    int n,i,j ;
	rfloat vet1[50],vet2[50],lf,f,xp ;
    printf("Quantos numeros tem na tabela?\n ");
    scanf("%d",&n);
    printf("Entrada de dados: \n");
    for(i=1; i<=n; i++){
        printf("x%d= \n",i);
        scanf("%f",&vet1[i]);
        printf("f(x%d)= \n",i);
        scanf("%f",&vet2[i]);
    }
    printf("Digite o valor de P(x): \n");
    scanf("%f",&xp);
    f=0.0;
    for(i=1; i<=n; i++){
        lf=1.0;
        for(j=1; j<=n; j++){
            if(i!=j)
                lf=lf*(xp-vet1[j])/(vet1[i]-vet1[j]);
        }
        f=f+lf*vet2[i];
    }
    printf("n f(%f) = %f\n",xp,f);
}

void interQuadratica()
{
    float xp,f;
    int i,j,k,n=3;
    float vet[10][10],c,vet1[10],sum=0.0;
    for(i=1; i<=n; i++){
        for(j=1; j<=(n+1); j++){
            printf("A[%d][%d] : ", i,j);
            scanf("%f",&vet[i][j]);
        }
    }
    for(j=1; j<=n; j++){
        for(i=1; i<=n; i++){
            if(i>j){
                c=vet[i][j]/vet[j][j];
                for(k=1; k<=n+1; k++){
                    vet[i][k]=vet[i][k]-c*vet[j][k];
                }
            }
        }
    }
    vet1[n]=vet[n][n+1]/vet[n][n];
    for(i=n-1; i>=1; i--){
        sum=0;
        for(j=i+1; j<=n; j++){
            sum=sum+vet[i][j]*vet1[j];
        }
        vet1[i]=(vet[i][n+1]-sum)/vet[i][i];
    }

    printf("Digite o valor de P(x): \n");
    scanf("%f",&xp);
    f=vet1[3]+xp*vet1[2]+((xp*xp)*vet1[1]);
    printf("f(%f)=%f",xp,f);
}

int main()
{
    int menu;
    printf("1- Interpolacao Quadratica\n");
    printf("2- Interpolacao de Lagrange\n");
    printf("3- Interpolacao de Newton\n");
    printf("4- Integracao Trapezio \n");
    printf("5- Integracao primeira regra de simpson\n");
    printf("6- Integracao segunda regra de simpson\n");
    scanf("%d", &menu);
	
	
	if( menu == 1 ){
		printf("Selecionado: Interpolacao Quadratica\n");
		interQuadratica();
	}else if (menu == 2 ){
		printf("Selecionado: Interpolacao de Lagrange\n");
		Lagrange();
	}else if (menu == 3 ){
		printf("Selecionado: Interpolacao de Newton\n");
		Newton();
	}else if (menu == 4 ){
		printf("Selecionado: Integracao Trapezio \n");
		trapezio();
	}else if (menu == 5 ){
		printf("Selecionado: Integracao primeira regra de simpson\n");
		primeiraSimpson();
	}else if (menu == 6 ){
		 printf("Selecionado: Integracao segunda regra de simpson\n");
		segundaSimpson();
	}
    return 0;
}

