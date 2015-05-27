#pragma once
#include "pile.h"
class squaredPile : virtual public pile
{
public:
	squaredPile(sf::Vector2i = sf::Vector2i(0,0));
	~squaredPile(void);
	void draw(sf::RenderWindow&);
	void resetCardPositions();
	unsigned int getWidth() const;
	unsigned int getHeight() const;
	int getCardAt(sf::Vector2i);
	sf::Vector2i getCardPosition(unsigned int);
	virtual bool canSplit(unsigned int) = 0;
	virtual bool canAppend(const pile&) = 0;
};

