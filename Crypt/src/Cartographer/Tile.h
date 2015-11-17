
#ifndef TILE_H
#define TILE_H

#include <string>
#include <vector>

#include "Config.h"

#include "Entity.h"

class Tile
{
public:
	Tile();
	Tile(std::string);
	Tile(std::string, std::string);
	virtual ~Tile();
	
	bool use();
	bool canUse();
	
	// Setters
	void setRegionName(std::string);
	void setSpecial(int);
	
	void setGround(Entity*);
	void setProp(Entity*);
	
	// Getters
	Entity* getGround();
	Entity* getProp();
	
	int getSpecial();
	bool isSolid();
	std::string getRegionName();
	
	
private:
	
	Entity* _ground;
	Entity* _prop;

	int _special;
	std::string _regionName;
	
};

typedef std::vector< std::vector<Tile*> > TILEGRID;

#endif // TILE_H
