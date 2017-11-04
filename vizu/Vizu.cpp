// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vizu.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mpochuka <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 18:15:04 by mpochuka          #+#    #+#             //
//   Updated: 2017/11/04 18:15:04 by mpochuka         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Vizu.hpp"

	Vizu::Vizu(int x, int y) : _size_x(x), _size_y(y), _score(0)
{

}

	Vizu::Vizu(Vizu& src)
{
	this->_size_y = src._size_y;
	this->_size_x = src._size_x;
	this->_score = src._score;
}

	Vizu::~Vizu()
{

}

	Vizu& Vizu::operator=(Vizu& src)
{
	this->_size_y = src._size_y;
	this->_size_x = src._size_x;
	this->_score = src._score;
	return (*this);
}

void	Vizu::setScore(int val)
{
	this->_score += val;
}

void	Vizu::start_vizu()
{//75r*281c 98/282 52*154
	char ch = 0;
	// int x = 10;
	// int y = 10;

	initscr();
	noecho();
 	// printw("Hello World !!!");
 	// refresh();
 	ch = getch();
 	addch(ch | A_REVERSE);
 	// addch(ACS_LRCORNER);
 	// printw("Presed %d", ch);
 	// if (ch == 27)
 	// 	endwin();
 	refresh();
 	getch();
 	endwin();


}

