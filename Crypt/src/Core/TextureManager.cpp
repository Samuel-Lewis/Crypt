//
//  TextureManager.cpp
//  Crypt
//
//  Created by Jacob Gonzalez on 6/10/2015.
//  Copyright © 2015 Jacob Gonzalez. All rights reserved.
//

#include "TextureManager.hpp"
#include "ResourcePath.hpp"
#include "GConfig.h"
#include "lbLog.h"

sf::Texture *TextureManager::getTexture(std::string key)
{
	// Hacky work around for empty entities
	if (key == "")
	{
		return nullptr;
	}
	
	if (textures.find(key) != textures.end())
    {
        return textures[key];
    }
    
    ERROR("Could not find texture '" << key << "'");
	
    return nullptr;
}

void TextureManager::loadTileTexturesFromFile(std::string filename)
{
	GConfig texturesDef = GConfig::read(resourcePath() + filename);
	
	if (texturesDef.good)
	{
		for (auto &&pair : texturesDef.getDict()->value)
		{
			std::string name = pair.first;
			
			sf::IntRect rect(0,0,TILE_SIZE,TILE_SIZE);

			sf::Texture *t = new sf::Texture();
			if (!t->loadFromFile(resourcePath() + name + ".png", rect))
			{
				FATAL("Missing texture " << name << ".png");
			}
			
			INFO("Loaded tile: "<< name);
			
			textures[name] = t;
		}
	}
	else
	{
		ERROR("Texture manager failed to load '" << filename <<"'");
	}

}

void TextureManager::loadTexturesFromFile(std::string filename)
{
    // with Generics fill up the map with textures

    GConfig texturesDef = GConfig::read(resourcePath() + filename);

    if (texturesDef.good)
    {
        for (auto &&pair : texturesDef.getDict()->value)
        {
            std::string name = pair.first;
            GDict *tileInfo = GDictFromDict(texturesDef.getDict(), name);

            std::string tileset = GStringFromDict(tileInfo, "tileset")->value;
            GArray *array = GArrayFromDict(tileInfo, "rect");

            sf::IntRect rect(0,0,TILE_SIZE,TILE_SIZE);

            if (array->count() > 0)
            {
                rect = sf::IntRect(GNumberFromArray(array, 0)->asInt(),
                                   GNumberFromArray(array, 1)->asInt(),
                                   GNumberFromArray(array, 2)->asInt(),
                                   GNumberFromArray(array, 3)->asInt());
            }

            sf::Texture *t = new sf::Texture();
            if (!t->loadFromFile(resourcePath() + tileset, rect))
            {
                FATAL("missing texture " << tileset << " for asset" << name);
            }
            textures[name] = t;
        }
    }
    else
    {
        ERROR("Texture manager failed to load '" << filename << "'");
    }
}

void TextureManager::free()
{
    for (auto it = textures.begin(); it != textures.end(); ++it)
    {
        delete it->second;
    }
    textures.clear();
}
