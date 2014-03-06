#ifndef ZOMBOID_H
#define ZOMBOID_H

#include <SFML/Graphics.hpp>

enum ZomboidState { Roaming, Chasing, Eating, Resurecting };

class Zomboid
{
    public:
        /** Default constructor */
        Zomboid();
        /** Default destructor */
        virtual ~Zomboid();
        void setPosition(const sf::Vector2f& position);
        const sf::Vector2f& getPosition() const;
        const sf::Vector2f& getSize() const;
        void setDestination(const sf::Vector2f& dest);
        const sf::Vector2f& getDestination() const;
        void setState(const ZomboidState s);
        const ZomboidState& getState() const;
        void draw();
        const sf::RectangleShape& getShape();
        void process(float delta);
    protected:
        sf::Vector2f _position;
        sf::Vector2f _size;
        sf::Vector2f _destination;
        bool _destinationEnabled;
        float _roamSpeed;
        float _chaseSpeed;
        ZomboidState _state;
        sf::RectangleShape _shape;
    private:
};

#endif // ZOMBOID_H
