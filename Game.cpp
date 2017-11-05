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
    //getmaxyx()



    int h = getmaxy(stdscr);
    int w = getmaxx(stdscr);
    game_window  = newwin(h, w, 1, 1);
    Game::H = getmaxy(game_window);
    Game::W = getmaxx(game_window);

    start_color();
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
    erase();
    // clear();
    // werase(this->getGame_window());
    // wclear(this->getGame_window());
    refresh();
    // wrefresh(this->getGame_window());
    attron(A_BOLD | A_REVERSE | COLOR_PAIR(4));
    mvprintw(LINES/2, COLS/2, "GAME OVER!");
    attroff(A_BOLD | A_REVERSE | COLOR_PAIR(4));
    refresh();
    // wrefresh(this->getGame_window());
    // while(1);

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
    mvaddch(player->get_Y(), player->get_Y(), player->getCh() | COLOR_PAIR(2));
    refresh();

}

void Game::print_enemus() {

    attron(COLOR_PAIR(4));
    for (int i = 0; i < COUNT_ENEMYS ; ++i) {
        AItem *en = getEnemys_array()[i];
        //printw(" x %d, y %d ch %d \n", en->get_X(), en->get_Y(), en->getCh());
        en->print();
    }
    attron(COLOR_PAIR(4));
}

//void Game::print_enemus() {
//    AItem *enemys = getEnemys_array();
//}
