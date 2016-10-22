#include "Cashier.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>

Cashier::Cashier(int eficiencia_, int salario_, char id_[]) {
	clientesAtendidos = 0;
	faturamentoTotal = 0;
	eficiencia = eficiencia_;
	salario = salario_;
	strcpy(id_,id);
	tempoMedioFila = 0;
}

Cashier::Cashier() {
	char a[] = "a";
	id[0] = a[0];
	clientesAtendidos = 0;
	faturamentoTotal = 0;
	eficiencia = 0;
	salario = 0;
	tempoMedioFila = 0;
}

void Cashier::verificaSeSai(int relogio) {
	if(queue.empty()){
		return;
	} else	
	if(relogio == queue.front().tempoDeSaida){
		faturamentoTotal = faturamentoTotal + queue.front().valorTotalDeCompras;
		if (clientesAtendidos == 0) ++clientesAtendidos;
		tempoMedioFila = (queue.front().tempoDeSaida - queue.front().tempoDeChegada + tempoMedioFila) / clientesAtendidos;
		++clientesAtendidos;
		queue.dequeue();
	}
}

int Cashier::calculaPessoas() {
	return queue.size();
}

int Cashier::calculaCompras() {
	int total = 0;
	if(queue.empty()) {
		return total;
	} else {
		for(int i = 0; i < queue.size(); ++i){
			total = total + queue.at(i).totalDeCompras;
		}
	}
	return total;
}