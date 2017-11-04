/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kstorozh <kstorozh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:15:00 by kstorozh          #+#    #+#             */
/*   Updated: 2017/11/04 19:15:00 by kstorozh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "AItem.h"
#include "Game.h"
AItem::AItem(int x, int y): _X(x), _Y(y), _X0(x), _Y0(y){}

AItem::AItem(AItem const &item) {
    *this = item;
}

AItem::AItem() {
    _X0 = 0;
    _Y0 = 0;
    _X = 0;
    _Y = 0;
}

AItem::~AItem() {

}

AItem &AItem::operator=(AItem const &item) {
    if (this != &item)
    {
        this->_X = item._X;
        this->_Y = item._Y;
        this->_X0 = item._X0;
        this->_Y0 = item._Y0;
    }
    return *this;
}

void AItem::move(int x, int y) {
    if (_X + x < Game::W || _Y + y < Game::H || _X + x > 0 || _Y + y > 0)
    {
        _X0 = _X;
        _Y0 = _Y;
        _X += x;
        _Y += y;
    }
    else
        std::cout << "cant move" << std::endl;
}

bool AItem::operator==(const AItem &rhs) const {
    return _X == rhs._X &&
           _Y == rhs._Y &&
           _X0 == rhs._X0 &&
           _Y0 == rhs._Y0;
}

bool AItem::operator!=(const AItem &rhs) const {
    return !(rhs == *this);
}

int AItem::get_X() const {
    return _X;
}

int AItem::get_Y() const {
    return _Y;
}

int AItem::get_X0() const {
    return _X0;
}

int AItem::get_Y0() const {
    return _Y0;
}
