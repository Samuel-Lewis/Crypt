#include <string>
#include <vector>
#include <map>

#include "lbCSV.h"
#include "lbLog.h"

#include "Tile.h"

//#include "ResourcePath.hpp"
#include "TileManager.hpp"


// Static var declarations
TABLE Tile::_tileList;
std::vector<std::string> Tile::unFoundTiles;

Tile::Tile(std::string tileCall, bool spec, std::string newRegionName)
{
    // Tile manager
    TileManager *tm = &TileManager::getInstance();

    if (tm->tileDict->get(tileCall) != nullptr)
    {
        // Tile does exist in the map
        _name = tileCall;
        _icon = tm->getString(_name, "icon");
        _solid = (bool)tm->getInt(_name, "solid");
        _special = spec;
        _regionName = newRegionName;

        return;
    }

	// Will only get here if tile wasn't found

	// Tile unnamed parameters
	_name = "UNDEFINED";
	_icon = " ";
	_solid = false;
	_special = false;

	// Check if we've thrown an error for this tile before. Don't want to spam a billion "can't find this tile message"
	for (unsigned i = 0; i < unFoundTiles.size(); i++)
	{
		if (unFoundTiles[i] == tileCall)
		{
			return;
		}
	}

	WARN("Tile '" << tileCall << "' could not be found. Ensure the tile library is loaded, and that you spelt the name correctly. Default to 'UNDEFINED'");
	unFoundTiles.push_back(tileCall);
}

Tile::Tile(std::string tileCall): Tile(tileCall, false, "") {}
Tile::Tile(): Tile("UNDEFINED", false, "") {}

Tile::~Tile() {}

// Setters and getters
std::string Tile::getName()
{
	return _name;
}

std::string Tile::getIcon()
{
	return _icon;
}

bool Tile::isSolid()
{
	return _solid;
}

bool Tile::isSpecial()
{
	return _special;
}

void Tile::setSpecial(bool val)
{
	_special = val;
}


