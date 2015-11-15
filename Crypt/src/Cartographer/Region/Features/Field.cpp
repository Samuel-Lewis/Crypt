#include <vector>
#include <string>

#include "Config.h"

#include "lbLog.h"
#include "lbRNG.h"

#include "Tile.h"

#include "Feature.h"
#include "Field.h"

Field::Field(int width, int height) : Feature(width,height) {}
Field::~Field() {}

void Field::generate()
{
	INFO("Generating field");
	
	// OPTIONS
	int cropWidth = 2;
	std::string fieldType = "field-light";
	std::vector<std::string> cropTypes = {"crop-cabbage","crop-onion","crop-tomato"};
	
	
	setAllGround(fieldType);
	for (int x = 0; x < _width; x += cropWidth)
	{
		// Random crop type (from set list above)
		std::string cropName = cropTypes[lbRNG::linear(0,(int)cropTypes.size())];
		// Spans a few columns
		for (int w = 0; w < cropWidth; w++)
		{
			for (int y = 0; y < _height; y++)
			{
				// Relying on correct tile naming
				if (lbRNG::linear(0.0,1.0) < 0.075)
				{
					setProp(x+w,y,cropName + "-grown");
				} else {
					setProp(x+w,y,cropName + "-sown");
				}
			}
		}
	}
	
	
}