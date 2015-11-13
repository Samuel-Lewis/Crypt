
#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
	
public:
	Entity();
	Entity(std::string);
	virtual ~Entity();
	
	// Getters
	bool isSolid();
	std::string getDisplayName();
	std::string getTileName();
	

private:
	
	enum contType {
		NONE,
		SELF,
		SOLID,
	};
	
	

	contType _connected;
	
	bool _solid;
	// Used to show tile type to user
	std::string _displayName;
	
	// Used to call tile texture, or actually differentiate between tile types
	std::string _tileName;
	
};

#endif // ENTITY_H