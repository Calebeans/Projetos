#include <iostream>
#include <windows.h>
//autor: Calebe
 
using namespace std;

int contJogador1, contJogador2,  empate;

void zerar(char m[3][3]){ //função para zerar as posições da matriz
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            m[i][j]=' ';      
        }
    }    
}

void desenhar(char m[][3]){ //função para desenhar o jogo da velha
    cout<<endl;
    for(int i=0; i<3; i++){
        cout<<" "<< (m[i][0]) <<" |";
        cout<<" "<< (m[i][1]) <<" |";
        cout<<" "<< (m[i][2]) <<endl;
        
        if(i!=2){
            cout<<"___ ___ ___\n"<<endl;
        }
    }
}

void checar(char m[3][3],int linha, int coluna, bool jogador1=true, bool jogador2=false, bool ganhar = true){ //função para decidir quem vai jogar, também para cada jogada e para verificar a vitória e empate
    int check;  
    zerar(m);

    do{        
        //if para jogada do primeiro jogador
        if(jogador1){
            system("cls");
            desenhar(m);
            do{    
                cout<<"Jogador 1:"<<endl;
                cout<<"Linha: ";
                cin>>linha;
                cout<<"Coluna: ";
                cin>>coluna;
                linha--;
                coluna--;        
                check = linha<0 || linha>3 || coluna<0 || coluna>3;//check para checar as posições que pode digitar, sendo que a linha e coluna não pode ser menor que 0 e maior que 3
                if(check)
                    cout<<"Essa casa nao esta vazia ou fora do intervalo 3x3"<<endl;
            }while(check);
            while (m[linha][coluna] != ' '){//while para verificar se a posição está disponivel/livre
                cout<<"Posicao preenchida"<<endl<<"Digite Novamente:"<<endl;
                cout<<"Linha: ";
                cin>>linha;
                cout<<"Coluna: ";
                cin>>coluna;  
                linha--;
                coluna--;     
            }
            m[linha][coluna]='X';
            jogador1 = false;
            jogador2 = true;
        }

        //if para jogada do segundo jogador
        else if(jogador2){
            do{
                system("cls");
                desenhar(m);
                cout<<"Jogador 2:"<<endl;
                cout<<"Linha: ";
                cin>>linha;
                cout<<"Coluna: ";
                cin>>coluna;
                linha--;
                coluna--;
                check = linha<0 || linha>3 || coluna<0 || coluna>3;//check para checar as posições que pode digitar, sendo que a linha e coluna não pode ser menor que 0 e maior que 3
                if(check)
                    cout<<"Essa casa nao esta vazia ou fora do intervalo 3x3"<<endl;
            }while(check);
            while (m[linha][coluna] != ' '){//while para verificar se a posição está disponivel/livre
                cout<<"Posicao preenchida"<<endl<<"Digite Novamente:"<<endl;
                cout<<"Linha: ";
                cin>>linha;
                cout<<"Coluna: ";
                cin>>coluna;  
                linha--;
                coluna--;     
            }
            m[linha][coluna]='O';
            jogador1 = true;
            jogador2 = false;
        }       
        
        //ifs para verificar os vencedores
        if(m[0][0] == 'X' && m[0][1] == 'X' && m[0][2] == 'X' || m[1][0] == 'X' && m[1][1] == 'X' && m[1][2] == 'X' 
                    || m[2][0] == 'X' && m[2][1] == 'X' && m[2][2] == 'X' || m[0][1]=='X' && m[1][1]=='X' && m[2][1]=='X' 
                    || m[0][2]=='X' && m[1][2]=='X' && m[2][2]=='X' || m[0][0]=='X' && m[1][1]=='X' && m[2][2]=='X' 
                    || m[0][2]=='X' && m[1][1]=='X' && m[2][0]=='X' || m[0][0]=='X' && m[1][0]=='X' && m[2][0]=='X'){
            contJogador1 ++;
            ganhar = true;
        }
        if(m[0][1] == 'O' && m[0][2] == 'O' && m[0][0] == 'O' || m[1][0] == 'O' && m[1][1] == 'O' && m[1][2] == 'O' 
                    || m[2][1] == 'O' && m[2][2] == 'O' && m[2][0] == 'O' || m[0][1]=='O' && m[1][1]=='O' && m[2][1]=='O' 
                    || m[0][2]=='O' && m[1][2]=='O' && m[2][2]=='O' || m[0][0]=='O' && m[1][1]=='O' && m[2][2]=='O' 
                    || m[0][2]=='O' && m[1][1]=='O' && m[2][0]=='O' || m[0][0]=='O' && m[1][0]=='O' && m[2][0]=='O'){
            contJogador2 ++;
            ganhar = true;
        }

        //if para verificar o empate
        else if(m[0][0] != ' ' && m[0][1] != ' ' && m[0][2] != ' ' && m[1][0] != ' ' && m[1][1] != ' ' && m[1][2] != ' ' &&
                    m[2][0] != ' ' && m[2][1] != ' ' && m[2][2] != ' '){
            empate ++;
            ganhar = true;
        }
        
        
    }while (ganhar == false);
}

int main() { 
    char m[3][3];    
    bool jogador1=true, jogador2=false, ganhar=false;
    int linha, coluna, confirm;
 
        do
        {        
            checar(m, linha, coluna, jogador1, jogador2, ganhar); 
            system("cls");
            cout<<"Jogador 1: "<<contJogador1<<endl<<"Jogador 2: "<<contJogador2<<endl<<"Empate: "<< empate<<endl;
            desenhar(m);
            cout<<"\n Outra partida?"<<endl;
            cout<<"0. Sair"<<endl;
            cout<<"1. Jogar de novo"<<endl;
            cin >> confirm;
        } while (confirm == 1);
        return 0;
}