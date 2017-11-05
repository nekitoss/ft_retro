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
#include "Game.h"
#include <ctime>
#include <ncurses.h>
WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int			main()
{
	Game game;



    Player *player = game.getPlayer();
    //printw(" x %d, y %d ch %d \n", player->get_X(), player->get_Y(), player->getCh());

    for (int i = 0; i < game.COUNT_ENEMYS; ++i) {

        AItem *enemys = game.getEnemys_array()[i];
        if (player->checkCollision(enemys) == 1) ///// dont work coorect
        {
            std::cout << "Colizia !!!"  << std::endl;
            // game.gameOver(); seackfoult
        }



        //game.getEnemys_array()[i] )
    }

    player->move(Game::W / 2, Game::H / 2);







    int ch;
    nodelay(stdscr, TRUE);
    noecho();
    wtimeout(game.getGame_window(), 0);
    curs_set(0);
    bool exit_requested = false;

    time_t timer;
    time(&timer);
    time_t bullet;
    time(&bullet);

    while(!exit_requested) {

        ch = wgetch(game.getGame_window());

        if(static_cast<int>(difftime(time(0), timer)) >= 1)

        {
            time(&timer);
            game.move_enemys_per_time();

            for (int i = 0; i < game.COUNT_ENEMYS; ++i) {
                AItem *enemys = game.getEnemys_array()[i];
                if (player->checkCollision(enemys) == 1)
                {
                    printw("Colizia !!!\n"); //  << std::endl;
                    game.gameOver();
                    exit_requested = true;
                }
                if (exit_requested)
                    break;
            }
        }
        if (exit_requested)
            break ;

        switch (ch) {
            case 'q':
                exit_requested = true;

                break;
            case KEY_UP:
            case 'w':
            case 'i':
                    player->bullet->cleanFire();
                    player->move(0, -1);
                break;
            case KEY_DOWN:
            case 's':
            case 'k':
                player->bullet->cleanFire();
                    player->move(0, 1);
                break;
            case KEY_LEFT:
            case 'a':
            case 'j':
                    player->bullet->cleanFire();
                    player->move(-1, 0);
                break;
            case KEY_RIGHT:
            case 'd':
            case 'l':
                player->bullet->cleanFire();
                player->move(1, 0);
                break;
            case ' ':


                if (!player->bullet->isIsFire())
                {time(&bullet);player->bullet->setIsFire(true);
                game.fire();
                    //mvprintw(0, 0," AFTER fire gX() %d, Yp() %d, Ye() %d", player->bullet->getX(), player->bullet->getYp(), player->bullet->getYe());
                }
                break;
            default:
                break;
        }

        attron(COLOR_PAIR(2));
            player->print();
        attroff(COLOR_PAIR(2));
        game.print_enemus();
        if (player->bullet->isIsFire() && (difftime(time(0), bullet)) >= 0.2)

        {
            time(&bullet);
            //printw("player->bullet->getX() %d, player->bullet->getYp() %d, player->bullet->getYe() %d", player->bullet->getX(), player->bullet->getYp(), player->bullet->getYe());
            player->bullet->cleanFire();
            player->bullet->setIsFire(false);
            //mvprintw(1, 0," AFTER clean gX() %d, Yp() %d, Ye() %d\n", player->bullet->getX(), player->bullet->getYp(), player->bullet->getYe());


        }
            for (int i = 0; i < game.COUNT_ENEMYS; ++i) {
                AItem *enemys = game.getEnemys_array()[i];
                if (player->checkCollision(enemys) == 1)
                {
                    printw("Colizia !!!\n");
                    wrefresh(game.getGame_window());
                    wtimeout(game.getGame_window(), -1);
                    wgetch(game.getGame_window());
                    endwin();
                    game.gameOver();
                }
            }
        refresh();

    }

    timeout(-1);
wgetch(game.getGame_window());
    delwin(game.getGame_window());
    endwin(); /* End curses mode */

    return 0;
}







