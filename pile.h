#pragma once
#include <vector>
#include "cloud.h"
#include "constants.h"
#include "pileCard.h"

class stickyPile;

class pile
{
public:
	pile(sf::Vector2i = sf::Vector2i(0, 0));
	~pile(void);
	unsigned int getSize() const;
	sf::Vector2i pile::getOffset() const;
	void appendPile(const pile&);
	bool containsPoint(const sf::Vector2i&);
	bool isOverlapping(const pile&);
	void setPosition(sf::Vector2i);
	card getCard(unsigned int) const;

	virtual stickyPile * splitPile(const sf::Vector2i&);
	virtual void draw(sf::RenderWindow&) = 0;
	virtual void resetCardPositions() = 0;
	virtual unsigned int getWidth() const = 0;
	virtual unsigned int getHeight() const = 0;
	virtual int getCardAt(sf::Vector2i) = 0;
	virtual sf::Vector2i getCardPosition(unsigned int) = 0;
	virtual bool canSplit(unsigned int) = 0;
	virtual bool canAppend(const pile&) = 0;
	friend class borrowPile;
	friend class stockPile;
	friend class stickyPile;
	friend class deck;
protected:
	std::vector<pileCard> cards;
	sf::Vector2i offset;
	void drawEmpty(sf::RenderWindow&);
	void appendCard(pileCard);
	bool commonSplitTest(unsigned int);
	bool commonAppendTest(const pile&) const;

private:
	sf::Sprite emptyCard;
	sf::Texture emptyCardTexture;
};

