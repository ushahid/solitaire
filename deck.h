#pragma once
#include <vector>
#include "pile.h"
#include "card.h"
#include "borrowPile.h"
#include "stockPile.h"
#include "foundationPile.h"
#include "tableauPile.h"

class deck
{
public:
	deck();
	void reset();
	void shuffle();
	std::vector<pile*> getPiles();
	~deck();
private:
	std::vector<card> cards;
};

