
#ifndef ENTITY_H
#define ENTITY_H

#include <string>

#include "Config.h"

class Entity {
	
public:
	Entity();
	Entity(std::string);
	virtual ~Entity();
	
	enum contType {
		NONE,
		SELF,
		SOLID,
	};
	
	virtual bool use();
	virtual bool canUse();
	
	// Getters
	bool isSolid();
	std::string getDisplayName();
	std::string getEntityName();
	std::string getTextureName();
	std::string getTextureSuffix();
	contType getContType();
	
	// Setters
	void setTextureName(std::string);
	void setTextureSuffix(std::string);
	
protected:
		
	contType _connected;
	
	bool _solid;
	// Aesthetic naming of this entity
	std::string _displayName;
	
	// The actual name of the entity, used for referencing. (Not to be confused with texture name)
	std::string _entityName;
	
	std::string _textureName;
	std::string _textureSuffix;
	
	bool _canUse;
	
};

#endif // ENTITY_H