/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kstorozh <kstorozh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:17:00 by kstorozh          #+#    #+#             */
/*   Updated: 2017/11/04 19:17:00 by kstorozh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Enemy.h"
#include "Game.h"
#include <cstdlib>
#include <iostream>

Enemy::Enemy(int x, int y): AItem(x, y) {
    this->ch = 'E';
}

Enemy::Enemy(const Enemy &item) : AItem(item) {
    this->ch = item.ch;
    //add diff
}

Enemy &Enemy::operator=(Enemy const &enemy) {
    if (this != &enemy) {
        AItem::operator=(enemy);
        // add diff
    }
    return *this;
}

Enemy::Enemy():AItem() {

    this->ch = 'E';
    _X0 = 0;
    _Y0 = 0;
    _X = random_interval(0, (unsigned int)Game::W); /// change to constant
    _Y = random_interval(0, (unsigned int)Game::H/2); /// change to constant

   // std::cout << "Enemy born!! _X = " << _X << " _Y = " << _Y << std::endl;

}

unsigned int Enemy::random_interval(unsigned int min, unsigned int max) {

    int r;
    unsigned int range;
    unsigned int buckets;
    unsigned int limit;

    range = 1 + max - min;
    buckets = RAND_MAX / range;
    limit = buckets * range;
    r = rand();
    while (r >= (int) limit)
        r = rand();
    return (min + (r / buckets));
}

Enemy::~Enemy() {
    //std::cout << "Enemy die!!! UHHHHU" << std::endl;
}

void Enemy::die() {
    int x = random_interval(0, (unsigned int)Game::W);
    int y = random_interval(0, (unsigned int)Game::H/2);
    this->set_X(x);
    this->set_y(y);
    //printw("player->bullet->getX() %d, player->bullet->getYp() %d, player->bullet->getYe() %d", get_X(), get_Y(), get_Y());

    this->move(0 , 0);
    //printw("player->bullet->getX() %d, player->bullet->getYp() %d, player->bullet->getYe() %d", get_X(), get_Y(), get_Y());
}

void Enemy::move(int x, int y) {
    AItem::move(x, y);

    if (_Y == Game::H -2)
    {
        _Y = 0;
    }

}

void Enemy::set_X(int X) {

    AItem::set_X(X);
}

void Enemy::set_y(int Y) {

    AItem::set_y(Y);
}

