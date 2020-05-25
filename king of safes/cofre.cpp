#include <iostream>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;
///48 a 57 ('0' a '9')
string senha;
bool wingame (string &);
void intro();
bool valido(string &);
void dica (string &);
void gerasenha(string &);

int main(){
    string chute="",op="";
    int tentativa=0;
    gerasenha(senha);
    ///cout<<senha<<endl;
    while(op!="z"){
        int mFlag = 0;
        cout<<"### INVASOR DE COFRE ###\n";
        cout<<"1- Comecar jogo\n"
        <<"2- Instrucoes\n"
        <<"3- Sobre\n"
        <<"z- Sair\n>>";
        getline(cin,op);
        if (op=="3"){
            cout<<"Criado por Pedro Canedo, \nestudante de Engenharia de Controle e Automacao,"
            <<"pela Universidade Federal de Itajuba, campus avancado de Itabira.\n"
            <<"Criado entre os dias 13 e 14 de Novembro de 2019\n\n";
            system("PAUSE");
            system("cls");

        }
        if (op=="2") intro();
        if (op=="1"){
            while(!wingame(chute)){
                cout<<"Entre com uma senha valida: ";
                getline(cin,chute);
                ///if (chute=="m")
                if (!valido(chute)){
                    cout<<"Formato de senha invalido, senha deve ter 3 numeros diferentes entre si, indo de 0 a 9 cada um.\n\n";
                }
                else {
                    cout<<"\nsenha valida;\n";

                    /// analisa e da as dicas
                    dica(chute);
                    tentativa++;

                }
            }
            cout<<"\nVoce acertou a senha, parabens. \n"<<"Voce acertou na tentativa "<<tentativa<<endl;
            tentativa=0;
            chute="";
            gerasenha(senha);
        }
        if (op=="z") return 0;
        else op="";
    }



}

void gerasenha(string &senha){
    senha="";
    int a,b,c;
    b = c = 0;
    srand(time(NULL));
    a = rand()%10 + 48; /// 0 a 9;
    b = rand()%10 + 48;
    while (a==b) b = rand()%10 + 48;
    c = rand()%10 + 48;
    while (c==b or c==a) c = rand()%10 + 48;

    senha+=(char)a;
    senha+=(char)b;
    senha+=(char)c;

}

void dica(string &chute){
    /// testa otimo, regular e pessimo
    int oti,reg,pes;
    char a,b,c;
    oti = reg = pes = 0;
    a = chute[0];
    b = chute[1];
    c = chute[2];
    ///valida otimo e pessimo.
    for(int i=0;i<=2;i++) {
        if (chute[i] == senha[i]) oti++;
    }
    /// valida regular
    for (int i=0;i<=2;i++){
        for (int j=0;j<=2;j++){
            if (i != j) {
                if (chute[i]==senha[j]) reg++;
            }
        }
    }
    pes = 3 - oti - reg;
    cout<<endl;
    cout<<oti<<" otimo(s)"<<endl;
    cout<<reg<<" regular(es)"<<endl;
    cout<<pes<<" pessimo(s)"<<endl;
}

bool valido(string &chute){ /// Valida a integridade da string
    char a,b,c;
    if (chute.size() != 3) return false;
    else {
        a = chute[0];
        b = chute[1];
        c = chute[2];

        for(int i=0;i<=2;i++) if ((int)chute[i]<48 or (int)chute[i]>57) return false;
        if ((a == b or a==c) or c == b ) return false;

    return true;
    }
}

void intro(){
    system("cls");
    cout<<"Voce precisa adivinhar a senha do cofre !"<<endl
    <<"A senha eh composta por 3 digitos que nao se repetem"<<endl
    <<"e que vao de 0 a 9 cada um"<<endl<<endl
    <<"Escolha os tres digitos e o cofre ira revela-lo algumas dicas..."<<endl
    <<"AS dicas sao:\n"
    <<"- Otimo: quando um digito estah na posicao correta.\n"
    <<"- Regular: quando um digito correto estah na posicao errada.\n"
    <<"- Pessimo: quando um digito nao corresponde a nenhum da senha.\n\n";
    system("PAUSE");
    cout<<endl;
    cout<<"Exemplo: A senha eh 123\n"
    <<"Voce chuta 152. \n"
    <<"O cofre lhe informara:\n"
    <<"- 1 bom\n- 1 regular\n- 1 pessimo.\n"
    <<"\n\n"<<"Se voce entendeu, prossiga para limpar a tela. BOA SORTE.\n";
    system("PAUSE");
    system("cls");
}

bool wingame(string &chute){
    if (chute == senha ) return true;
    else return false;
}
