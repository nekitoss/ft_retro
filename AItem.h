/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kstorozh <kstorozh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:15:00 by kstorozh          #+#    #+#             */
/*   Updated: 2017/11/04 19:15:00 by kstorozh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RUSH00_ITEM_H
#define RUSH00_ITEM_H


class AItem {
private:
    int _X;
    int _Y;
    int _X0;
    int _Y0;
public:
    AItem(int x, int y);
    AItem(AItem const &item);
    AItem &operator=(AItem const &item);
    virtual ~AItem();
    void move(int x, int y);
    virtual void takeDamage(int i);
};


#endif //RUSH00_ITEM_H