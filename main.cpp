#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.hpp"

using namespace std;

int main()
{
    int confirm;
    string player1, player2;

    cout << "Jogador 1: ";
    cin >> player1;
    cout << "Jogador 2: ";
    cin >> player2;
    do
    {
        jogo();
        system("cls");
        cout << player1 << " " << contJogador1 << endl
             << player2 << " " << contJogador2 << endl
             << "Empate: " << empate << endl;
        desenhar();
        cout << "\n Outra partida?" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Jogar de novo" << endl;
        cin >> confirm;
        if (confirm > 1 || confirm < 0)
        {
            do
            {
                cout << "Intervalo incorreto!" << endl;
                cout << "0. Sair" << endl;
                cout << "1. Jogar de novo" << endl;
                cin >> confirm;
            } while (confirm > 1 || confirm < 0);
        }
    } while (confirm == 1);
    system("cls");
    cout << "Obrigado por jogar!" << endl;
    cout << player1 << " " << contJogador1 << endl
         << player2 << " " << contJogador2 << endl
         << "Empate: " << empate << endl;
    if (contJogador1 > contJogador2 && contJogador1 > empate)
    {
        cout << "Parabens: " << player1;
    }
    else if (contJogador2 > contJogador1 && contJogador2 > empate)
    {
        cout << "Parabens: " << player2;
    }
    else if (contJogador1 == contJogador2 && empate != contJogador1)
    {
        cout << "Empate entre os Jogadores: " << player1 << " e " << player2;
    }
    else if (empate > contJogador1 && empate > contJogador2)
    {
        cout << "Teve mais empate que vitorias";
    }
    return 0;
}