/*
 * Supermarket.h
 *
 *  Created on: 10 de out de 2016
 *      Author: macelai
 */

#ifndef SUPERMARKET_H_
#define SUPERMARKET_H_
#include <vector>
#include "Client.h"
#include "circularlist.h"
#include "Cashier.h"

class Supermarket {
 public:
 	CircularList<Cashier> circList{};
 	int relogio, clientesDesistentes, valorComprasDesistentes, tempoSimulacao, tempoChegada, totalDeCaixas;
 	std::vector<Cashier> caixas;
 	char nome[];
 	Supermarket(int tempoSimulacao_, int tempoChegada, std::vector<Cashier> caixas_, int totalDeCaixas, char nome[]);
 	void comecaCaixas();
 	Client geraCliente();
};

#endif
