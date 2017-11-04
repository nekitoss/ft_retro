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

