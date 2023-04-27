#pragma once
#include "GiftType.h"
#include "Factory.h"
class GiftCoins : public GiftType
{
public:
	GiftCoins(const sf::Vector2f& location,  float height,  float width);
	GiftCoins() = default;
	~GiftCoins() = default;

protected:
	static bool m_registerit;
};
inline bool GiftCoins::m_registerit = Factory::registeritGift(
	[](const sf::Vector2f& location, float height, float width) -> std::unique_ptr<GiftType> { return std::make_unique<GiftCoins>(location, height, width); });

