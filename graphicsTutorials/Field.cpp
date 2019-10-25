#include "Field.h"

Field::Field()
{
}

Field::~Field()
{
}

void Field::addCharge(Charge charge)
{
	m_charges.push_back(charge);
}

void Field::draw(Bengine::SpriteBatch & spriteBatch, Bengine::DebugRenderer & debugRenderer)
{
	for (size_t i = 0; i < m_charges.size(); i++) {
		m_charges[i].draw(spriteBatch, debugRenderer);
	}
}
