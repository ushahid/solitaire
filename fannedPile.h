#pragma once
#include "pile.h"

class fannedPile : virtual public pile
{
public:
	enum fanDirection{RIGHT, DOWN};
	fannedPile(sf::Vector2i = sf::Vector2i(0, 0), fanDirection = RIGHT, sf::Vector2f = sf::Vector2f(30.0, 15.0));
	~fannedPile(void);
	void draw(sf::RenderWindow&);
	unsigned int getWidth() const;
	unsigned int getHeight() const;
	int getCardAt(sf::Vector2i);
	sf::Vector2i getCardPosition(unsigned int);
	virtual bool canSplit(unsigned int) = 0;
	virtual bool canAppend(const pile&) = 0;
protected:
	sf::Vector2f percentageVisibility;
private:
	fanDirection fanDir;
	sf::Vector2i getCardOffset() const;
	void resetCardPositions();
};

