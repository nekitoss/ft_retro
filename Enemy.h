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
    Enemy(const Enemy &enemy);
    Enemy &operator=(Enemy const &enemy);
    ~Enemy();

};


#endif //RUSH00_ENEMY_H
