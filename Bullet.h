/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kstorozh <kstorozh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:50:00 by kstorozh          #+#    #+#             */
/*   Updated: 2017/11/05 19:50:00 by kstorozh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RUSH00_BULLET_H
#define RUSH00_BULLET_H


class Bullet {
private:
    int X;
    int Yp;
    int Ye;
    bool isFire;
public:
    bool isIsFire() const;

    void setIsFire(bool isFire);

public:
    Bullet(int X, int Y0, int Y);


    void setX(int X);

    void setYp(int Y0);

    void setY(int Y);

    virtual ~Bullet();

    void makeFire(int x, int yp, int ye);
    void makeFire();
    void cleanFire(int x, int yp, int ye);

    int getX() const;

    int getYp() const;

    int getYe() const;

    void cleanFire();
};


#endif //RUSH00_BULLET_H
