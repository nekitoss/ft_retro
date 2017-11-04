// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vizu.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mpochuka <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 18:14:57 by mpochuka          #+#    #+#             //
//   Updated: 2017/11/04 18:14:58 by mpochuka         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VIZU_HPP
# define VIZU_HPP

# include <ncurses.h>
// # include <../Enemy.h>

class Vizu
{
public:
	Vizu();
	Vizu(Vizu& src);
	~Vizu();
	Vizu& operator=(Vizu& src);

	int		start_vizu();
	void	setScore(int val);

	const int	minX;
	const int	minY;
private:
	
	int			_score;
	// Player	p1;
	// Enemy 	en[10];
	
};

#endif
