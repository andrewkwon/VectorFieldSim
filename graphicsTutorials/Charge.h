#pragma once

#include "Typedefs.h"
#include <glm/glm.hpp>

//Forward declarations
namespace Bengine {
	class SpriteBatch;
	class DebugRenderer;
}

class Charge
{
public:
	Charge(real strength, glm::vec2 pos);
	~Charge();

	void draw(Bengine::SpriteBatch& spriteBatch, Bengine::DebugRenderer& debugRenderer);
	
	void setStrength(real strength);

	real getRadius();

	real m_strength;
	glm::vec4 m_posAndSize;

	//Computed properties
};

