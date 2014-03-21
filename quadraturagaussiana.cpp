#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {

    //Variáveis:
    int n; //número de pontos
    int f; //função escolhida
    double a; //início do intervalo
    double b; //fim do intervalo
    double soma = 0; //somatório

    //Xi's
    double x [5] = {0,0,0,0,0};

    //Ti's
    double t [5] = {0,0,0,0,0};

    //Ai's
    double A [5] = {0,0,0,0,0};

    //LER AQUIVO AQUI, ESSA PARTE SERÁ ADICIONADA DEPOIS

    //setando os Ti's e Ai's
    if(n == 2) {
        t[0] = -0.57735;
        t[1] = 0.57735;
        A[0] = 1;
        A[1] = 1;
    }
    if(n == 3) {
        t[0] = -0.77459;
        t[2] = 0.77459;
        A[0] = 0.55556;
        A[1] = 0.88889;
        A[2] = 0.55556;
    }
    if(n == 4) {
        t[0] = -0.86113;
        t[1] = -0.33998;
        t[2] = 0.33998;
        t[3] = 0.86113;
        A[0] = 0.34785;
        A[1] = 0.65214;
        A[2] = 0.65214;
        A[3] = 0.34785;
    }
    if(n == 5) {
        t[0] = -0,90617;
        t[1] = -0,53846;
        t[3] = 0,53846;
        t[4] = 0,90617;
        A[0] = 0.23692;
        A[1] = 0.47862;
        A[2] = 0.56889;
        A[3] = 0.47862;
        A[4] = 0.23692;
    }

    //setando os Xi's
    for(int i = 0; i < n ; i++ ) {
        x[i] = t[i]*(b - a)/2 + (a + b)/2;
    }


    if(f == 1) {
        //Somatório Ai*F(xi)
        for(int i = 0; i < n; i++) {
            soma = soma + A[i]*(1/sqrt(x[i]));
        }
        return (b - a)*soma/2;
    }

    if(f == 2) {
        //Somatório Ai*F(xi)
        for(int i = 0; i < n; i++) {
            soma = soma + A[i]*(1/sqrt(1 - x[i]*x[i]));
        }
        return (b - a)*soma/2;
    }

    if(f == 3) {
        //Somatório Ai*F(xi)
        for(int i = 0; i < n; i++) {
            soma = soma + A[i]*(2*x[i]*x[i]*x[i] + 3*x[i]*x[i] + 6*x[i] + 1);
        }
        return (b - a)*soma/2;
    }

    if(f == 4) {
        //Somatório Ai*F(xi)
        for(int i = 0; i < n; i++) {
            soma = soma + A[i]*(1 - x[i] - 4*x[i]*x[i]*x[i] + 2*x[i]*x[i]*x[i]*x[i]*x[i]);
        }
        return (b - a)*soma/2;
    }

    if(f == 5) {
        //Somatório Ai*F(xi)
        for(int i = 0; i < n; i++) {
            soma = soma + A[i]*(4/(1 + x[i]*x[i]));
        }
        return (b - a)*soma/2;
    }
}
