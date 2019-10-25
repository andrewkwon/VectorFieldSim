#include "Field.h"
#include <Bengine/Camera2D.h>
#include <Bengine/DebugRenderer.h>
#include <glm/gtx/rotate_vector.hpp>

Field::Field() :
	m_gridCellSize(10)
{
}

Field::~Field()
{
}

void Field::addCharge(Charge charge)
{
	m_charges.push_back(charge);
}

void Field::draw(Bengine::SpriteBatch & spriteBatch, Bengine::DebugRenderer & debugRenderer, Bengine::Camera2D& camera)
{
	//Draw charges
	for (size_t i = 0; i < m_charges.size(); i++) {
		m_charges[i].draw(spriteBatch, debugRenderer);
	}

	//Draw grid
	glm::vec2 startingCellPos = glm::floor((camera.getPosition() - camera.getScaledScreenSize() / 2.0f) / m_gridCellSize) * m_gridCellSize;
	glm::vec2 endingCellPos = glm::ceil((camera.getPosition() + camera.getScaledScreenSize() / 2.0f) / m_gridCellSize) * m_gridCellSize;
	for (glm::vec2 pos = startingCellPos; pos.x < endingCellPos.x; pos.x += m_gridCellSize) {
		for (pos.y = startingCellPos.y; pos.y < endingCellPos.y; pos.y += m_gridCellSize) {
			static const GLubyte GRAYSCALE_VALUE = 100;
			static const Bengine::ColorRGBA8 GRAY(GRAYSCALE_VALUE, GRAYSCALE_VALUE, GRAYSCALE_VALUE, GRAYSCALE_VALUE);
			debugRenderer.drawBox(glm::vec4(pos.x, pos.y, m_gridCellSize, m_gridCellSize), GRAY, 0.0);

			glm::vec2 fieldStrength;
			for (size_t i = 0; i < m_charges.size(); i++) {
				Charge& charge = m_charges[i];
				glm::vec2 displacement = pos.xy - charge.m_posAndSize.xy;
				fieldStrength += forceConstant * charge.m_strength * displacement / (pow(glm::length(displacement), 3));
			}

			static const Bengine::ColorRGBA8 WHITE(255, 255, 255, 255);
			drawArrow(debugRenderer, pos, pos + fieldStrength, WHITE, camera);
		}
	}
}

void Field::drawArrow(Bengine::DebugRenderer & debugRenderer, const glm::vec2 & a, const glm::vec2 & b, const Bengine::ColorRGBA8 & color, Bengine::Camera2D& camera)
{
	debugRenderer.drawLine(a, b, color);
	glm::vec2 arrowVec = glm::normalize(b - a) * 5.0f * camera.getScale();
	debugRenderer.drawLine(b, b + glm::rotate(arrowVec, 120.0f), color);
	debugRenderer.drawLine(b, b + glm::rotate(arrowVec, -120.0f), color);
}
