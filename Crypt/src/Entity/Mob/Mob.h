
#ifndef ENTITY_MOB_H
#define ENTITY_MOB_H

#include <string>

#include "Config.h"

class Tile;
#include "Path.h"
#include "Entity.h"

class Mob: public Entity {
public:

	Mob(std::string, Tile*);
	virtual ~Mob();
	
	virtual bool think() = 0;
	virtual bool move(DIRECTION);
	
	void setParentTile(Tile*);
	
protected:
	
	Path* _path;
	Mob* _target;
	
	int _speed;
	
	bool _thinkCoolDown();
	int _coolDown;
	
private:
	
	Tile* _parentTile;
	
	//TODO: Level of aggression


	
};

#endif // ENTITY_MOB_H