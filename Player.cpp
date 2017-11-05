/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kstorozh <kstorozh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:17:00 by kstorozh          #+#    #+#             */
/*   Updated: 2017/11/04 19:17:00 by kstorozh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Player.h"
#include <iostream>

Player::Player(int x, int y) : AItem(x, y) {
    ch = 'Y';
    std::cout << "Player is ready _X = " << _X <<"_Y = " << _Y << std::endl;
}

Player::Player(const Player &player) : AItem(player) {
    std::cout << "Player is reade" << std::endl;
    ch = player.ch;
}

Player &Player::operator=(Player const &player) {
    if (this != &player) {
        AItem::operator=(player);
        // add diff
    }
    return *this;
}

Player::~Player() {
    std::cout << "Player is die =(" << std::endl;
}



