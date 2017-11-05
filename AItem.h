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
protected:
    int _X;
    int _Y;
    int _X0;
    int _Y0;
    int ch;
public:
    AItem(int x, int y);
    AItem();
    AItem(AItem const &item);
    AItem &operator=(AItem const &item);
    virtual ~AItem();
    void move(int x, int y);
   // virtual void takeDamage(int i);



    bool operator==(const AItem &rhs) const;

    bool operator!=(const AItem &rhs) const;


    int get_X() const;

    int get_Y() const;

    int get_X0() const;

    int get_Y0() const;

    //int checkCollision(Enemy *const *pEnemy); ///// ohh
    int checkCollision(AItem *pItem);

    int getCh() const;
};


#endif //RUSH00_ITEM_H
