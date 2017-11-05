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
    AItem *player = game.getPlayer();
    player->move(0, 6);




    for (int i = 0; i < game.COUNT_ENEMYS; ++i) {

        AItem *enemy = game.getEnemys_array()[i];
        if (player->checkCollision(enemy) == 1) ///// dont work coorect
        {
            std::cout << "Colizia !!!"  << std::endl;
            game.gameOver();
        }

        //game.getEnemys_array()[i] )
    }
    game.gameOver();
    //std::cout << game.H << std::endl;
	return (0);
}
