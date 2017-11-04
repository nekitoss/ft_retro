/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kstorozh <kstorozh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:17:00 by kstorozh          #+#    #+#             */
/*   Updated: 2017/11/04 19:17:00 by kstorozh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RUSH00_GAME_H
#define RUSH00_GAME_H


#include "Player.h"
#include "Enemy.h"

class Game {

public:
    int static const W = 50;
    int static const H = 50;
    int static const COUNT_ENEMYS  = 20;
    Game();

    virtual ~Game();

private:
    Player *player;
    Enemy *enemys_array[COUNT_ENEMYS];
};


#endif //RUSH00_GAME_H
