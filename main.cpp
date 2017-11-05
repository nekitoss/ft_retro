// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mpochuka <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 18:09:28 by mpochuka          #+#    #+#             //
//   Updated: 2017/11/04 18:09:31 by mpochuka         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "vizu/Vizu.hpp"
#include "Game.h"
#include <ncurses.h>
WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int			main()
{
	Vizu viz;

	//viz.start_vizu();


    Game game;



    AItem *player = game.getPlayer();


    for (int i = 0; i < game.COUNT_ENEMYS; ++i) {

        AItem *enemys = game.getEnemys_array()[i];
        if (player->checkCollision(enemys) == 1) ///// dont work coorect
        {
            std::cout << "Colizia !!!"  << std::endl;
           // game.gameOver(); seackfoult
        }

        //game.getEnemys_array()[i] )
    }


    //printw(" x %d, y %d dx %d dy %d lines %d cpls %d \n", player->get_X(), player->get_Y(),  Game::H / 2, Game::W / 2, LINES, COLS);
    player->move(Game::W / 2, Game::H / 2);

    //printw(" x %d, y %d dx %d dy %d lines %d cpls %d \n", player->get_X(), player->get_Y(), (LINES - Game::H) / 2, (COLS - Game::W) / 2, LINES, COLS);
    mvaddch(player->get_Y(), player->get_X(), player->getCh() | A_REVERSE);
    refresh();



   int ch;

    while((ch = wgetch(game.getGame_window())) != 'q') {


        switch (ch) {
            case 'q':

                break;
            case KEY_UP:
            case 'w':
            case 'i':
                    player->move(0, -1);
                break;
            case KEY_DOWN:
            case 's':
            case 'k':
                    player->move(0, 1);
                break;
            case KEY_LEFT:
            case 'a':
            case 'j':
                    player->move(-1, 0);
                break;
            case KEY_RIGHT:
            case 'd':
            case 'l':
                player->move(1, 0);
                break;
            default:
                break;
        }

        player->print();

//        mvaddch(player->get_Y0(), player->get_X0(), ' ');
//        mvaddch(player->get_Y(), player->get_X(), player->getCh()| A_REVERSE);
        refresh();
    }






    /*while((ch = getch()) != KEY_F(1))
    { switch(ch)
        { case KEY_LEFT:

                break;
            case KEY_RIGHT:

                break;
            case KEY_UP:

                break;
            case KEY_DOWN:

                break;
        }
    }*/
    game.gameOver();
    endwin(); /* End curses mode */
    return 0;
}







