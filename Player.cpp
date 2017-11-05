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
#include <ncurses.h>

Player::Player(int x, int y) : AItem(x, y) {
    ch = 'Y';
    bullet = new Bullet(0, 0, 0);

}

Player::Player(const Player &player) : AItem(player) {
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
    delete bullet;
    //std::cout << "Player is die =(" << std::endl;
}

void Player::move(int x, int y) {
    AItem::move(x, y);
    bullet->setX(get_X());
}













