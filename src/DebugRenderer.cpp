#include "testlib/DebugRenderer.hpp"

DebugRenderer::DebugRenderer(int width, int height)
{
	renderTexture.create(width, height);
}

/// Draw a closed polygon provided in CCW order.
void DebugRenderer::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	sf::ConvexShape polygon(vertexCount);
	for (int32 i = 0; i < vertexCount; ++i) {
		polygon.setPoint(i, sf::Vector2f(vertices[i].x * TO_SFML, vertices[i].y * TO_SFML));
	}
	sf::Color fillColor(255 * color.r, 255 * color.g, 255 * color.b, 128 * color.a);
	polygon.setFillColor(fillColor);
	polygon.setOutlineColor(sf::Color(255 * color.r, 255 * color.g, 255 * color.b, 255 * color.a));
	polygon.setOutlineThickness(1.0f);
	renderTexture.draw(polygon);
}

/// Draw a solid closed polygon provided in CCW order.
void DebugRenderer::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	sf::ConvexShape polygon(vertexCount);
	for (int32 i = 0; i < vertexCount; ++i) {
		polygon.setPoint(i, sf::Vector2f(vertices[i].x * TO_SFML, vertices[i].y * TO_SFML));
	}
	polygon.setFillColor(sf::Color(255 * color.r, 255 * color.g, 255 * color.b, 128 * color.a));
	polygon.setOutlineColor(sf::Color(255 * color.r, 255 * color.g, 255 * color.b, 255 * color.a));
	polygon.setOutlineThickness(1.0f);
	renderTexture.draw(polygon);
}

/// Draw a circle.
void DebugRenderer::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
	sf::CircleShape circle(radius * TO_SFML);
	circle.setOrigin(radius * TO_SFML, radius * TO_SFML);

	circle.setFillColor(sf::Color(255 * color.r, 255 * color.g, 255 * color.b, 128 * color.a));
	circle.setOutlineColor(sf::Color(255 * color.r, 255 * color.g, 255 * color.b, 255 * color.a));
	circle.setOutlineThickness(1.0f);

	circle.setPosition(center.x * TO_SFML, center.y * TO_SFML);
	renderTexture.draw(circle);
}

/// Draw a solid circle.
void DebugRenderer::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
	sf::CircleShape circle(radius * TO_SFML);
	circle.setOrigin(radius * TO_SFML, radius * TO_SFML);
	sf::Color fillColor(255 * color.r, 255 * color.g, 255 * color.b, 128 * color.a);
	sf::Color outlineColor(255 * color.r, 255 * color.g, 255 * color.b, 255 * color.a);

	circle.setFillColor(fillColor);
	circle.setOutlineColor(outlineColor);
	circle.setOutlineThickness(1.0f);

	circle.setPosition(center.x * TO_SFML, center.y * TO_SFML);
	renderTexture.draw(circle);

	sf::VertexArray lineAngle(sf::Lines, 2);
	lineAngle[0].position.x = center.x * TO_SFML;
	lineAngle[0].position.y = center.y * TO_SFML;

	b2Vec2 p2 = center + radius * axis;
	lineAngle[1].position.x = p2.x * TO_SFML;
	lineAngle[1].position.y = p2.y * TO_SFML;

	lineAngle[0].color = fillColor;
	lineAngle[1].color = fillColor;

	renderTexture.draw(lineAngle);
}

/// Draw a line segment.
void DebugRenderer::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	sf::VertexArray line(sf::Lines, 2);
	line[0].position.x = p1.x * TO_SFML;
	line[0].position.y = p1.y * TO_SFML;
	line[1].position.x = p2.x * TO_SFML;
	line[1].position.y = p2.y * TO_SFML;

	line[0].color = sf::Color(255 * color.r, 255 * color.g, 255 * color.b, 255 * color.a);
	line[1].color = sf::Color(255 * color.r, 255 * color.g, 255 * color.b, 255 * color.a);

	renderTexture.draw(line);
}

/// Draw a transform. Choose your own length scale.
/// @param xf a transform.
void DebugRenderer::DrawTransform(const b2Transform& xf)
{
	sf::VertexArray lineX(sf::Lines, 2);
	sf::VertexArray lineY(sf::Lines, 2);

	// X-Axis
	lineX[0].position.x = xf.p.x * TO_SFML;
	lineX[0].position.y = xf.p.y * TO_SFML;

	b2Vec2 p2 = xf.p + 0.5f * xf.q.GetXAxis();
	lineX[1].position.x = p2.x * TO_SFML;
	lineX[1].position.y = p2.y * TO_SFML;

	lineX[0].color = sf::Color::Red;
	lineX[1].color = sf::Color::Red;

	// Y-Axis
	lineY[0].position.x = xf.p.x * TO_SFML;
	lineY[0].position.y = xf.p.y * TO_SFML;

	p2 = xf.p - 0.5f * xf.q.GetYAxis();
	lineY[1].position.x = p2.x * TO_SFML;
	lineY[1].position.y = (p2.y * TO_SFML);

	lineY[0].color = sf::Color::Green;
	lineY[1].color = sf::Color::Green;

	renderTexture.draw(lineX);
	renderTexture.draw(lineY);
}

void DebugRenderer::clear()
{
	renderTexture.clear(sf::Color::Transparent);
}

void DebugRenderer::update()
{
	renderTexture.display();
	sprite.setTexture(renderTexture.getTexture());
}

void DebugRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
