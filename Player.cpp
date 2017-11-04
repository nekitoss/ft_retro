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
    std::cout << "Player is ready" << std::endl;
}

Player::Player(const Player &enemy) : AItem(enemy) {
    std::cout << "Player is reade" << std::endl;
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



