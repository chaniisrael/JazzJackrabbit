#pragma once
#include "GiftType.h"
#include "Factory.h"

class GiftTime : public GiftType
{
public:
	GiftTime(const sf::Vector2f& location, float height, float width);
	GiftTime() = default;
	~GiftTime() = default;

protected:

	static bool m_registerit;
};
inline bool GiftTime::m_registerit = Factory::registeritGift(
[](const sf::Vector2f& location, float height, float width) -> std::unique_ptr<GiftType> { return std::make_unique<GiftTime>(location, height, width); });
