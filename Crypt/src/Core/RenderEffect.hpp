#pragma once


#include <SFML/Graphics.hpp>
#include "lbRNG.h"

class RenderEffect
{
public:
    virtual ~RenderEffect(){}
    virtual void begin(sf::Sprite &s, float x, float y) = 0;
    virtual void end(sf::Sprite &s) = 0;
    virtual std::string name() const = 0;
};

class LightEffect : public RenderEffect
{
public:
    int flickerSeed;

    void begin(sf::Sprite &s, float x, float y)
    {
        float dist = sqrtf(powf(std::abs(s.getPosition().x - x), 2) + powf(std::abs(s.getPosition().y - y), 2));
        const int maxRadius = 6;
        const int lowestLight = 20;
        const int gradient = 200/maxRadius;

        for (int i = 1; i < maxRadius; i++)
        {
            int flicker = flickerSeed - TILESIZE*i;
            if (dist > i*TILESIZE && dist < (i+2)*TILESIZE)
            {
                int gray = abs((255-i*gradient)+flicker);
                gray = gray < lowestLight ? lowestLight : gray;
                s.setColor(sf::Color(gray,gray,gray,255));
            }
        }

        if (dist > maxRadius*TILESIZE)
        {
            s.setColor(sf::Color(lowestLight,lowestLight,lowestLight,255));
        }
    }
    void end(sf::Sprite &s)
    {
        s.setColor(sf::Color::White);
    }

    std::string name() const
    {
        return "light";
    }
};