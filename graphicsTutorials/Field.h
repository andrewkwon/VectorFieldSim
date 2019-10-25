#pragma once

#include <vector>
#include "Charge.h"

class Field
{
public:
	Field();
	~Field();

	void addCharge(Charge charge);

	void draw(Bengine::SpriteBatch& spriteBatch, Bengine::DebugRenderer& debugRenderer);

	int m_gridCellSize;
	std::vector<Charge> m_charges;
};

