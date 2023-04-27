#pragma once
#include "GiftType.h"
#include "Factory.h"
class GiftDisqualifications : public GiftType
{
public:
	GiftDisqualifications(const sf::Vector2f& location, float height, float width);
	GiftDisqualifications() = default;
	~GiftDisqualifications() = default;

protected:

	static bool m_registerit;
};
inline bool GiftDisqualifications::m_registerit = Factory::registeritGift(
	[](const sf::Vector2f& location, float height, float width) -> std::unique_ptr<GiftType> { return std::make_unique<GiftDisqualifications>(location, height, width); });


