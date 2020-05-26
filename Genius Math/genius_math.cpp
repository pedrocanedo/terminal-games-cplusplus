#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

bool initial ();
int algen(int iMax);
int algen(int iMin, int iMax);
bool algen();

///FUNÇÃO PRINCIPAL
int main(){
    while(initial()){
        int nc,acerto=0;
        float dg,iMax;
        cout<<"Digite o numero de calculos: ";
        cin>>nc;
        cout<<"Digite o numero de digito max dos numeros: ";
        cin>>dg;
        iMax = pow(10.0,dg) - 1;
        cout<<endl;
        cout<<"Responda se puder: \n\n\n";
        for (int i=0;i<nc;i++){
            int a,b,res,op;
            a = algen(iMax);
            b = algen(iMax);
            res = a+b;
            cout<<i+1<<") "<<a<<"+"<<b<<" = ";
            cin>>op;
            if (op == res) {
                cout<<" [!Correto!]"<<endl<<endl;
                acerto++;
            }
            else cout<<" [-Errado-]"<<endl<<endl;

        }
        cout<<" Fim de jogo "<<endl;
        cout<<"Voce obteve "<<acerto<<"/"<<nc<<" de pontuacao.";
        cout<<endl<<endl<<endl;
    }

}
/// FIM - FUNÇÃO PRINCIPAL

bool initial (){
    srand(time(NULL));
    return true;
}

int algen(int iMax) {return (rand()%iMax + 1);}
int algen(int iMin, int iMax) {return (rand()%iMax + iMin);}
bool algen() {return rand()%2;}
