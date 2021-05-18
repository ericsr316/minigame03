#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <iostream>
#include "Bonus.h"


Player player;
Map mapGame;
Bonus bonus;
bool isWin = false;

int findPlayer(int rc);
void directions();
void spwanBonus();
void getBonus();
void win();

void singIn()
{
    bool ok = false;
    char c,op;
    std::string u;

    do
    {
        std::cout<<"Hello choose an user for you\n";
        std::cin>>u;
        std::cout<<"Write your letter\n";
        std::cin>>c;

        std::cout<<"Are you sure about your name: "<<u<<" and character as "<<c<<"\nPress Y/N\n";
        std::cin>>op;
        if(op == 'Y' || op== 'y')
        {
            ok = true;
            player.setUser(u);
            player.setAvatar(c);
        }
    }
    while(ok!=true);
}

void spawnPlayer(char a, int r, int c)
{
    for(int i = 0; i < mapGame.row; i++)
    {
        for(int j = 0; j < mapGame.column; j++)
        {
            if(i==r && j ==c)
            {
                mapGame.mapGame[i][j] = player.getAvatar();
            }
        }
    }
}



void game()
{
    singIn();
    directions();

}

int findPlayer(int rc)
{
    for(int i = 0; i < mapGame.row; i++)
    {
        for(int j = 0; j < mapGame.column; j++)
        {
            if(mapGame.mapGame[i][j]==player.getAvatar())
            {
                if(rc == 1)
                {
                    return i;
                }

                else
                {
                    return j;
                }
            }
        }
    }
}

void directions()
{
    spawnPlayer(player.getAvatar(),4,4);
    for(int i = 0; i < 50; i++)
    {
        spwanBonus();
    }
    char op;
    bool status = false;
    int pr, pc;
    do
    {
        system("cls");
        std::cout<<"Player: "<<player.getUser()<<"    score: "<<player.getScore()<<"\n";
        mapGame.printMap();
        std::cout<<"\n";
        pr = findPlayer(1);
        pc = findPlayer(2);
//std::cout<<pr<<" "<<pc<<"\n";
        std::cout<<"w - UP\ns- DOWN\na - LEFT\nd - RIGHT\nq - exit\n";
        std::cin>>op;
        switch(op)
        {

        case 'w':
            if(pr!=0)
            {
                mapGame.mapGame[pr][pc] = '*';
                mapGame.mapGame[pr-1][pc] = player.getAvatar();

            }
            break;

        case 's':
            if(pr!=9)
            {
                mapGame.mapGame[pr][pc] = '*';
                mapGame.mapGame[pr+1][pc] = player.getAvatar();

            }
            break;

        case 'a':
            if(pc!=0)
            {
                mapGame.mapGame[pr][pc] = '*';
                mapGame.mapGame[pr][pc-1] = player.getAvatar();

            }
            break;

        case 'd':
            if(pc!=9)
            {
                mapGame.mapGame[pr][pc] = '*';
                mapGame.mapGame[pr][pc+1] = player.getAvatar();

            }
            break;

        case 'q':
            status = true;
            break;
        }
        getBonus();
        win();
    }
    while(status==false && isWin == false);
}

void spwanBonus()
{
    int br = 0, bc = 0;
    bonus.setIcon('O');
    bonus.setBonus(100);
    bool status = false;
    do
    {
        br = rand() % 9;
        bc = rand() % 9;
        if(br != findPlayer(1) && bc != findPlayer(2))
        {
            mapGame.mapGame[br][bc] = bonus.getIcon();
            status = true;
        }
    }
    while(status = false);
}

void getBonus()
{
    int pc,pr;
    bool getBonus = false;
    pr = findPlayer(1);
    pc = findPlayer(2);

    for(int i = 0; i < mapGame.row; i++)
    {
        for(int j = 0; j < mapGame.column; j++)
        {
            if(mapGame.mapGame[pr-1][pc] == bonus.getIcon())
            {
                getBonus = true;

            }

            else if(mapGame.mapGame[pr+1][pc] == bonus.getIcon())
            {
                getBonus = true;
            }

            else if(mapGame.mapGame[pr][pc+1] == bonus.getIcon())
            {
                getBonus = true;
            }

            else if(mapGame.mapGame[pr][pc-1] == bonus.getIcon())
            {
                getBonus = true;
            }


        }
    }
    if(getBonus==true)
            {
                player.setScore(player.getScore()+bonus.getBonus());
            }
}
void win()
{
    int col = 0;
    for(int i = 0; i < mapGame.row; i++)
    {
        for(int j = 0; j < mapGame.column; j++)
        {
            if(mapGame.mapGame[i][j]!=bonus.getIcon())
            {
                col++;
            }
        }
        if(col==100)
        {
            isWin = true;
            std::cout<<"You have won!\n";
            system("pause");

        }
    }
}


#endif // GAME_H_INCLUDED
