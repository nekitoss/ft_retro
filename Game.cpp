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
    Game::H = getmaxy(game_window);
    Game::W = getmaxx(game_window);


    game_window  = newwin(Game::W, Game::H, 1, 1);
    //int h = getmaxy(game_window);
    //int w = getmaxx(game_window);

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
    printw(" w wind %d, %d %d \n", Game::W, Game::H, 1);
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
                std::cout << "Colizia !!!"  << std::endl;
            }
        }
    }
}

void Game::gameOver() {
    delete player;
    for (int i = 0; i < COUNT_ENEMYS ; ++i) {
        delete enemys_array[i];
    }
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
