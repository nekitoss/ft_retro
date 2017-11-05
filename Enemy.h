/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kstorozh <kstorozh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:17:00 by kstorozh          #+#    #+#             */
/*   Updated: 2017/11/04 19:17:00 by kstorozh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RUSH00_ENEMY_H
#define RUSH00_ENEMY_H

#include "AItem.h"


class Enemy : public AItem {
public:
    Enemy(int x, int y);
    Enemy();
    Enemy(const Enemy &enemy);
    Enemy &operator=(Enemy const &enemy);
    virtual ~Enemy();
    static unsigned int random_interval(unsigned int min, unsigned int max);
    void die();

    virtual void move(int x, int y);

    void set_X(int X) ;

    void set_y(int Y) ;
};


#endif //RUSH00_ENEMY_H
