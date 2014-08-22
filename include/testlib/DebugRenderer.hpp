#pragma once
#include <testlib/Config.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class TESTLIB_API DebugRenderer : public sf::Drawable, public b2Draw
{
public:
	DebugRenderer(int width, int height);
	/// Draw a closed polygon provided in CCW order.
	virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;
	/// Draw a solid closed polygon provided in CCW order.
	virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;
	/// Draw a circle.
	virtual void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) override;
	/// Draw a solid circle.
	virtual void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) override;
	/// Draw a line segment.
	virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) override;
	
	/// Draw a transform. Choose your own length scale.
	/// @param xf a transform.
	virtual void DrawTransform(const b2Transform& xf) override;
	
	void clear();

	void update();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::RenderTexture renderTexture;
	sf::Sprite sprite;
};