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

        AItem *enemy = game.getEnemys_array()[i];
        if (player->checkCollision(enemy) == 1) ///// dont work coorect
        {
            std::cout << "Colizia !!!"  << std::endl;
           // game.gameOver(); seackfoult
        }

        //game.getEnemys_array()[i] )
    }





    //WINDOW *my_win;
    //int startx, starty;
//    int width, height;

    printw(" x %d, y %d dx %d dy %d lines %d cpls %d \n", player->get_X(), player->get_Y(),  Game::H / 2, Game::W / 2, LINES, COLS);

    //player->move(Game::H / 2, Game::W / 2);
    player->move(Game::H / 2, Game::W / 2);

    printw(" x %d, y %d dx %d dy %d lines %d cpls %d \n", player->get_X(), player->get_Y(), (LINES - Game::H) / 2, (COLS - Game::W) / 2, LINES, COLS);
    //mvaddch(player->get_Y(), player->get_X(), player->getCh() | A_REVERSE);

    mvaddch(31, 123, player->getCh() | A_REVERSE);

    refresh();


    //my_win = create_newwin(height, width, starty, startx);

//    int top = 0;
//    int bot = Game::H;
//    int left = 0;
//    int right = Game::W;
   int ch;

    while((ch = getch()) != 'q') {
        switch (ch) {
            case 'q':
                //exit_requested = true;
                break;
//            case KEY_UP:
//            case 'w':
//            case 'i':
//                //if (player->get_Y() > top)
//                    player->move(0, -1);
//                //destroy_win(my_win);
//                //my_win = create_newwin(height, width, --starty,startx);
//                    //player.pos.y -= 1;
//                break;
//            case KEY_DOWN:
//            case 's':
//            case 'k':
//                //if (player->get_Y() > bot + 1)
//                    player->move(0, 1);
//                //destroy_win(my_win);
//                //my_win = create_newwin(height, width, ++starty,startx);
//                break;
//            case KEY_LEFT:
//            case 'a':
//            case 'j':
//                //if (player->get_X() > left + 1)
//                    player->move(-1, 0);
//                //destroy_win(my_win);
//                //my_win = create_newwin(height, width, starty, --startx);
//                break;
//            case KEY_RIGHT:
//            case 'd':
//            case 'l':
//                //if (player->get_X() < right - 2)
//                    player->move(1, 0);
//                //destroy_win(my_win);
//                //my_win = create_newwin(height, width, starty, ++startx);
//                break;
//            default:
//                break;
        }
        //mvaddch(player->get_X0(), player->get_Y0(), ' ');
        //mvaddch(player->get_Y(), player->get_Y(), player->getCh());
        //refresh();
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







