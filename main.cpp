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
#include "Game.h"

int			main()
{
	Vizu viz;

	viz.start_vizu();

	Game game;
    for (int i = 0; i < game.COUNT_ENEMYS; ++i) {
        AItem *player = game.getPlayer();

//        if (player->checkCollision(&(game.getEnemys_array()[i])) == 1) ///// dont work coorect
//        {
//
//        }

        //game.getEnemys_array()[i] )
    }
    game.gameOver();
    std::cout << game.H << std::endl;
	return (0);
}
