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

int	size_x;
int	size_y;

	Vizu::Vizu() : minX(13), minY(22), _score(0)
{

}

	Vizu::Vizu(Vizu& src) : minX(13), minY(22)
{
	// this->_size_y = src._size_y;
	// this->_size_x = src._size_x;
	this->_score = src._score;
}

	Vizu::~Vizu()
{

}

	Vizu& Vizu::operator=(Vizu& src)
{
	// this->_size_y = src._size_y;
	// this->_size_x = src._size_x;
	this->_score = src._score;
	return (*this);
}

void	Vizu::setScore(int val)
{
	this->_score += val;
}

int		Vizu::start_vizu()
{//75r*281c 98/282 52*154 50*150
	char ch = 0;
	// int x = 10;
	// int y = 10;

	initscr();
	getmaxyx(stdscr, size_y, size_x);
	if (size_y < 30 && size_x < 100)
	{
		endwin();
		return (0);
	}
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
 	return (1);

}

