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
#include <ctime>
#include <ncurses.h>
WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int			main()
{
	Vizu viz;

	//viz.start_vizu();


    Game game;



    Player *player = game.getPlayer();
    printw(" x %d, y %d ch %d \n", player->get_X(), player->get_Y(), player->getCh());

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
    /*mvaddch(player->get_Y(), player->get_X(), player->getCh() | A_REVERSE);
    refresh();
*/





    int ch;

    noecho();
    wtimeout(game.getGame_window(), 0);
    curs_set(0);
    bool exit_requested = false;

    time_t timer;
    time(&timer);

    time_t bullet;
    time(&bullet);

    while(!exit_requested) {
        nodelay(stdscr, TRUE);
        ch = wgetch(game.getGame_window());

        if(static_cast<int>(difftime(time(0), timer)) >= 1)

        {
            time(&timer);
            game.move_enemys_per_time();

        }
        switch (ch) {
            case 'q':
                exit_requested = true;

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
            case ' ':

                time(&bullet);
                player->bullet->setIsFire(true);
                game.fire();
                break;
            default:
                break;
        }
        player->print();
        game.print_enemus();
        if (player->bullet->isIsFire() && (difftime(time(0), bullet)) >= 0.5)

        {
            player->bullet->setIsFire(false);
            player->bullet->cleanFire();
        }
            for (int i = 0; i < game.COUNT_ENEMYS; ++i) {
                AItem *enemys = game.getEnemys_array()[i];
                if (player->checkCollision(enemys) == 1)
                {
                    printw("Colizia !!!\n");
                    wrefresh(game.getGame_window());
                    wtimeout(game.getGame_window(), -1);
                    getch();
                    endwin();
                    game.gameOver();
                }
            }
        refresh();
    }
    wrefresh(game.getGame_window());
    wtimeout(game.getGame_window(), -1);
    getch();
    game.gameOver();
    endwin();

    return 0;
}







