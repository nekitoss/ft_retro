/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kstorozh <kstorozh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:50:00 by kstorozh          #+#    #+#             */
/*   Updated: 2017/11/05 19:50:00 by kstorozh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bullet.h"
#include <ncurses.h>

void Bullet::makeFire(int x, int ye, int yp) {
    for (int i = ye; i < yp ; i++) {
        mvaddch(i, x, '*' | A_BOLD | A_REVERSE);
    }
}

void Bullet::cleanFire(int x, int ye, int yp) {
    for (int i = ye; i < yp ; i++) {
        mvaddch(i, x, '_' | A_BOLD | A_REVERSE);
    }
}

Bullet::Bullet(int X, int Y0, int Y) : X(X), Yp(Y0), Ye(Y) {
    isFire = false;
}

Bullet::~Bullet() {

}

void Bullet::setX(int X) {
    this->X = X;
}

void Bullet::setY0(int Y0) {
   this->Yp = Y0;
}

void Bullet::setY(int Y) {
    this->Ye = Y;
}

void Bullet::makeFire() {
    for (int i = getYe(); i < getYp() ; i++) {
        mvaddch(i, getX(), '*' | A_BOLD | A_REVERSE);
    }
}

void Bullet::cleanFire() {

    for (int i = getYe(); i < getYp() ; i++) {

        mvaddch(i, getX(), ' ');
    }
}

bool Bullet::isIsFire() const {
    return isFire;
}

void Bullet::setIsFire(bool isFire) {
    Bullet::isFire = isFire;
}

int Bullet::getX() const {
    return X;
}

int Bullet::getYp() const {
    return Yp;
}

int Bullet::getYe() const {
    return Ye;
}
