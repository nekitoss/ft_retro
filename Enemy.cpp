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
#include <cstdlib>

Enemy::Enemy(int x, int y):AItem(x, y) {

}

Enemy::Enemy(const Enemy &item) : AItem(item) {
    //add diff
}

Enemy &Enemy::operator=(Enemy const &enemy) {
    if (this != &enemy) {
        AItem::operator=(enemy);
        // add diff
    }
}

Enemy::Enemy():AItem() {
    _X = random_interval(0, 150);
    _Y = random_interval(0, 150);
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

