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


#include <ncurses.h>
#include "Player.h"
#include "Enemy.h"

class Game {

public:

    int static const COUNT_ENEMYS  = 20;
    Game();
    void setup();
    void gameOver();
    virtual ~Game();
private:
    Player *player;
    Enemy *enemys_array[COUNT_ENEMYS];
public:
    static int W;
    static int H;
    WINDOW *game_window;




public:
    int getW() const;
    int getH() const;

    WINDOW *getGame_window() const;
    void setGame_window(WINDOW *game_window);
    void run();
    Player *getPlayer() const;
    Enemy *const *getEnemys_array() const;

};


#endif //RUSH00_GAME_H
