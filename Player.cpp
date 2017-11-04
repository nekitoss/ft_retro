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

Player::Player(int x, int y) : AItem(x, y) {

}

Player::Player(const Player &enemy) : AItem(enemy) {

}

Player &Player::operator=(Player const &player) {
    if (this != &player) {
        AItem::operator=(player);
        // add diff
    }
}

Player::~Player() {

}
