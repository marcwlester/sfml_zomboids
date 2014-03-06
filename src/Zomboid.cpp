#include "Zomboid.h"


Zomboid::Zomboid() :
    _position(0,0),
    _size(32.0,32.0),
    _destination(0,0),
    _destinationEnabled(false),
    _roamSpeed(20.0),
    _chaseSpeed(40.0),
    _state(Roaming),
    _shape(_size)
{
    //ctor
}

Zomboid::~Zomboid()
{
    //dtor
}

void Zomboid::setPosition(const sf::Vector2f& position)
{
    _position = position;
}

const sf::Vector2f& Zomboid::getPosition() const
{
    return _position;
}

const sf::Vector2f& Zomboid::getSize() const
{
    return _size;
}

void Zomboid::setDestination(const sf::Vector2f& dest)
{
    _destination = dest;
    _destinationEnabled = true;
}

const sf::Vector2f& Zomboid::getDestination() const
{
    return _destination;
}

void Zomboid::setState(const ZomboidState s)
{
    _state = s;
}
const ZomboidState& Zomboid::getState() const
{
    return _state;
}

void Zomboid::draw()
{

}

const sf::RectangleShape& Zomboid::getShape()
{
    _shape.setFillColor(sf::Color::Red);
    _shape.setPosition(_position);
    return _shape;
}

void Zomboid::process(float delta)
{
    sf::Vector2f velocity(10,0);

    _position += velocity * delta;
    //std::cout << delta << std::endl;
}
