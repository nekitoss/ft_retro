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

class Vizu
{
public:
	Vizu(int x = 50, int y = 50);
	Vizu(Vizu& src);
	~Vizu();
	Vizu& operator=(Vizu& src);

	void start_vizu();
private:
	int		_size_x;
	int		_size_y;
	
};

#endif
