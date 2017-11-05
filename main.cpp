// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mpochuka <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 18:09:28 by mpochuka          #+#    #+#             //
//   Updated: 2017/11/04 18:09:31 by mpochuka         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "vizu/Vizu.hpp"

extern int	size_x;
extern int	size_y;

int			main()
{
	Vizu viz;

	if (viz.start_vizu())
	{
		
	}
	else
		std::cout << "Window size is too small!"
		<< std::endl
		<< "Plz make window bigger and/or make font smaller."
		<< std::endl
		<< "Then try again... (Minimum size is " 
		<< viz.minX << 'x' << viz.minY << ')' << std::endl;

	return (0);
}
