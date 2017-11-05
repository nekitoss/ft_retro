/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kstorozh <kstorozh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:17:00 by kstorozh          #+#    #+#             */
/*   Updated: 2017/11/04 19:17:00 by kstorozh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Game.h"
#include <cstdlib>
#include <iostream>
int Game::H = 0;
int Game::W = 0;
Game::Game() {
    initscr();
    curs_set(0);
    //getmaxyx()



    int h = getmaxy(stdscr);
    int w = getmaxx(stdscr);
    game_window  = newwin(h, w, 1, 1);
    Game::H = getmaxy(game_window);
    Game::W = getmaxx(game_window);


    // useful color pairs
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);

    // enable function keys
    keypad(game_window, true);

    // disable input blocking
    nodelay(game_window, true);

    player = new Player(0, 0); // add player with position
    setup(); // generate enamy
    //printw(" w  %d,  h %d \n", Game::W, Game::H);
   // printw(" w wind %d, %d %d \n", w, h, 1);
    wrefresh(game_window);
    //std::cout << "Constructor Game::H = " << h << "Game::W = " << w << std::endl;


}

Game::~Game() {

}

void Game::setup() {
    for (int i = 0; i < COUNT_ENEMYS; ++i) {
        enemys_array[i] = new Enemy();
        for (int j = 0; j < i; ++j) {
            if (enemys_array[i] == enemys_array[j]) {
                delete enemys_array[j];
                enemys_array[j] = new Enemy();
                //std::cout << "Colizia !!!"  << std::endl;
            }
        }
    }
}

void Game::gameOver() {
    delete player;
    for (int i = 0; i < COUNT_ENEMYS ; ++i) {
        delete enemys_array[i];
    }

    exit(0);
}

Player *Game::getPlayer() const {
    return player;
}

Enemy *const *Game::getEnemys_array() const {
    return enemys_array;
}

int Game::getW() const {
    return W;
}

int Game::getH() const {
    return H;
}

WINDOW *Game::getGame_window() const {
    return game_window;
}

void Game::setGame_window(WINDOW *game_window) {
    this->game_window = game_window;
}

void Game::run() {
    //int tick;

    // initialize player as before

    // constrain object fields to game area
    //asteroids.setBounds(game_window);
    //stars.setBounds(game_area);

    Player *player = getPlayer();
    mvaddch(player->get_Y(), player->get_Y(), player->getCh());
    refresh();

}

void Game::print_enemus() {


    for (int i = 0; i < COUNT_ENEMYS ; ++i) {
        AItem *en = getEnemys_array()[i];
        //printw(" x %d, y %d ch %d \n", en->get_X(), en->get_Y(), en->getCh());

        en->print();
    }

}

void Game::move_enemys_per_time() {
    for (int i = 0; i < COUNT_ENEMYS; ++i) {

        AItem *enemys = getEnemys_array()[i];
        enemys->move(0, 1);
        if (player->checkCollision(enemys) == 1)
        {
            printw("Colizia !!!\n");
            wrefresh(getGame_window());
            wtimeout(getGame_window(), -1);
            getch();
            endwin();
            gameOver();
        }
    }

}

void Game::fire() {


    bool locat_is_fire = false;
    for (int i = 0; i < COUNT_ENEMYS; ++i) {
        Enemy *enemys = getEnemys_array()[i];
        if(getPlayer()->get_X() == enemys->get_X() && getPlayer()->get_Y() > enemys->get_Y())
        {
            getPlayer()->bullet->setY(enemys->get_Y());
            getPlayer()->bullet->setY0(getPlayer()->get_Y());
            getPlayer()->bullet->setX(getPlayer()->get_X());

            getPlayer()->bullet->makeFire();

            enemys->die();
            locat_is_fire = true;

        }
    }
    if (!locat_is_fire)
    {

        getPlayer()->bullet->setY(0);
        getPlayer()->bullet->setY0(getPlayer()->get_Y());
        getPlayer()->bullet->setX(getPlayer()->get_X());
        getPlayer()->bullet->makeFire();

    }
}







//void Game::print_enemus() {
//    AItem *enemys = getEnemys_array();
//}
