#pragma once

#include <vector>
#include "Charge.h"

//Forward declarations
namespace Bengine {
	class Camera2D;
}

class Field
{
public:
	Field();
	~Field();

	void addCharge(Charge charge);

	void draw(Bengine::SpriteBatch& spriteBatch, Bengine::DebugRenderer& debugRenderer, Bengine::Camera2D& camera);

	float m_gridCellSize; //Grid cell size in pixels
	std::vector<Charge> m_charges;
	real forceConstant = 1; // Don't worry about this
};

