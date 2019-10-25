#include "Charge.h"

#include <Bengine/SpriteBatch.h>
#include <Bengine/GLTexture.h>
#include <Bengine/ResourceManager.h>
#include <Bengine/DebugRenderer.h>

Charge::Charge(real strength, glm::vec2 pos) :
	m_strength(strength),
	m_posAndSize(pos.x, pos.y, 0, 0)
{
	setStrength(strength);
}

Charge::~Charge()
{
}

void Charge::draw(Bengine::SpriteBatch& spriteBatch, Bengine::DebugRenderer& debugRenderer) {
	static const Bengine::ColorRGBA8 RED(255, 50, 50, 255); //+
	static const Bengine::ColorRGBA8 BLUE(30, 40, 255, 255); //-
	debugRenderer.drawCircle(glm::vec2(m_posAndSize.x, m_posAndSize.y), m_strength >= 0 ? RED : BLUE, getRadius());
}

void Charge::setStrength(real strength)
{
	real radius = log(abs(strength) + 1);
	m_posAndSize.z = m_posAndSize.w = radius;
}

real Charge::getRadius()
{
	return m_posAndSize.z / 2.0;
}
