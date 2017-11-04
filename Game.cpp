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
    player = new Player(0, 0);
    for (int i = 0; i < COUNT_ENEMYS; ++i) {
        enemys_array[i] = new Enemy();
        for (int j = 0; j < i; ++j) {
            if (enemys_array[i] == enemys_array[j]) {
                delete enemys_array[j];
                enemys_array[j] = new Enemy();
            std::cout << "Colizia !!!"  << std::endl;
            }
        }
        std::cout << "Enemy pos x = " << enemys_array[i]->get_X() << " y = " << enemys_array[i]->get_Y() << " x0 " << enemys_array[i]->get_X0() << " y0 " << enemys_array[i]->get_Y0() << std::endl;
    }


}

Game::~Game() {

}
