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

Game::Game() {
    player = new Player(0, 0); // add player with position
    setup(); // generate enamy

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
