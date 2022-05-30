#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int contJogador1 = 0, contJogador2 = 0, empate = 0, linha = 0, coluna = 0, check = 0, confirm;
bool fim = false, jogador1 = true, jogador2 = false, ganhar = false;
char m[3][3];

void zerar();
void desenhar();
int verificar_inteiro();
bool verifica_Vitoria();
void checar();

int main()
{
    do
    {
        checar();
        system("cls");
        cout << "Jogador 1: " << contJogador1 << endl
             << "Jogador 2: " << contJogador2 << endl
             << "Empate: " << empate << endl;
        desenhar();
        cout << "\n Outra partida?" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Jogar de novo" << endl;
        cin >> confirm;
    } while (confirm == 1);
    system("cls");
    cout << "Obrigado por jogar!" << endl;
    cout << "Jogador 1: " << contJogador1 << endl
         << "Jogador 2: " << contJogador2 << endl
         << "Empate: " << empate << endl;
    return 0;
}

void zerar()
{ // função para zerar as posições da matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m[i][j] = ' ';
        }
    }
}

void desenhar()
{ // função para desenhar o jogo da velha
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << " " << (m[i][0]) << " |";
        cout << " " << (m[i][1]) << " |";
        cout << " " << (m[i][2]) << endl;

        if (i != 2)
        {
            cout << "___ ___ ___\n"
                 << endl;
        }
    }
}

// Verificar se o que o usuario digitou foi um numero inteiro
int verificar_inteiro()
{
    int num;
    // Enquanto 'num' não for um inteiro, ele pede para digitar novamente
    while (scanf("%d", &num) != 1)
    {
        // Passando um vetor estatico de tamanho 256
        static char temp[256];
        // fgets-Lendo a string
        // sizeof-Fornece o tamanho do vetor temp
        // stdin-Dispositivo de entrada padrão
        fgets(temp, sizeof(temp), stdin);
        cout << "Digite um numero " << endl;
    }
    return num;
}

bool verifica_Vitoria()
{

    if (m[0][0] == 'X' && m[0][1] == 'X' && m[0][2] == 'X' ||
        m[1][0] == 'X' && m[1][1] == 'X' && m[1][2] == 'X' ||
        m[2][0] == 'X' && m[2][1] == 'X' && m[2][2] == 'X' ||
        m[0][1] == 'X' && m[1][1] == 'X' && m[2][1] == 'X' ||
        m[0][2] == 'X' && m[1][2] == 'X' && m[2][2] == 'X' ||
        m[0][0] == 'X' && m[1][1] == 'X' && m[2][2] == 'X' ||
        m[0][2] == 'X' && m[1][1] == 'X' && m[2][0] == 'X' ||
        m[0][0] == 'X' && m[1][0] == 'X' && m[2][0] == 'X')
    {
        contJogador1++;
        ganhar = true;
        return true;
    }
    if (m[0][1] == 'O' && m[0][2] == 'O' && m[0][0] == 'O' ||
        m[1][0] == 'O' && m[1][1] == 'O' && m[1][2] == 'O' ||
        m[2][1] == 'O' && m[2][2] == 'O' && m[2][0] == 'O' ||
        m[0][1] == 'O' && m[1][1] == 'O' && m[2][1] == 'O' ||
        m[0][2] == 'O' && m[1][2] == 'O' && m[2][2] == 'O' ||
        m[0][0] == 'O' && m[1][1] == 'O' && m[2][2] == 'O' ||
        m[0][2] == 'O' && m[1][1] == 'O' && m[2][0] == 'O' ||
        m[0][0] == 'O' && m[1][0] == 'O' && m[2][0] == 'O')
    {
        contJogador2++;
        ganhar = true;
        return true;
    }
    // if para verificar o empate
    else if (m[0][0] != ' ' && m[0][1] != ' ' && m[0][2] != ' ' && m[1][0] != ' ' && m[1][1] != ' ' && m[1][2] != ' ' &&
             m[2][0] != ' ' && m[2][1] != ' ' && m[2][2] != ' ')
    {
        empate++;
        ganhar = true;
        return true;
    }
}

// função para decidir quem vai jogar, também para cada jogada e para verificar a vitória e empate
void checar()
{
    zerar();
    jogador1 = true, jogador2 = false, ganhar = false;
    do
    {
        // if para jogada do primeiro jogador
        if (jogador1)
        {
            do
            {
                system("cls");
                desenhar();
                cout << "Jogador 1:" << endl;
                cout << "Linha:" << endl;
                linha = verificar_inteiro();

                cout << "Coluna:" << endl;
                coluna = verificar_inteiro();

                linha--;
                coluna--;

                check = m[linha][coluna] != ' ' || linha < 0 || linha > 2 || coluna < 0 || coluna > 2; // check para checar as posições que pode digitar, sendo que a linha e coluna não pode ser menor que 0 e maior que 3
                if (check)
                    cout << "Essa casa nao esta vazia ou fora do intervalo 3x3" << endl;
            } while (check);

            m[linha][coluna] = 'X';
            jogador1 = false;
            jogador2 = true;
            verifica_Vitoria();
        }

        // if para jogada do segundo jogador
        else if (jogador2)
        {
            do
            {
                system("cls");
                desenhar();
                cout << "Jogador 2:" << endl;
                cout << "Linha:";
                linha = verificar_inteiro();

                cout << "Coluna:" << endl;
                coluna = verificar_inteiro();

                linha--;
                coluna--;

                check = m[linha][coluna] != ' ' || linha < 0 || linha > 2 || coluna < 0 || coluna > 2; // check para checar as posições que pode digitar, sendo que a linha e coluna não pode ser menor que 0 e maior que 3
                if (check)
                    cout << "Essa casa nao esta vazia ou fora do intervalo 3x3" << endl;
            } while (check);
            m[linha][coluna] = 'O';
            jogador1 = true;
            jogador2 = false;
            verifica_Vitoria();
        }
    } while (ganhar == false);
}