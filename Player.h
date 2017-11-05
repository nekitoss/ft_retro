/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kstorozh <kstorozh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:17:00 by kstorozh          #+#    #+#             */
/*   Updated: 2017/11/04 19:17:00 by kstorozh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RUSH00_PLAYER_H
#define RUSH00_PLAYER_H

#include "AItem.h"
#include "Bullet.h"


class Player : public AItem{

public:
    Player(int x, int y);
    Player(const Player &enemy);
    Player &operator=(Player const &enemy);

    virtual void move(int x, int y);

    Bullet *bullet;

    virtual ~Player();
};


#endif //RUSH00_PLAYER_H
