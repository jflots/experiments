// Logger.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

#include "Include/Message.h"

#include <iostream>

using Logger::Message;

int main()
{
	Message msg;

	msg.setDetails("un premier message de log à écrire.");

	std::cout << msg.getDetails() << std::endl;


    return 0;
}

