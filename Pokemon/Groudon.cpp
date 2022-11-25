#include "Groudon.h"
#include "Config.h"

Groudon::Groudon(const sf::Texture& texture) :
    AnimatedEntity(texture, std::vector<sf::IntRect>(GROUDON_ANIM_RECT))
{
    this->_sprite.scale(10, 10);
}