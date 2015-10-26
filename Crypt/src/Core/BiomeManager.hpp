
#pragma once

#include "Singleton.hpp"
#include "Generics.h"
#include "ResourcePath.hpp"

class BiomeManager : public Singleton<BiomeManager> {
public:

    BiomeManager() : Singleton<BiomeManager>()
    {
        loadBiomesFromFile(resourcePath() + "biomes.json");
    }

    void loadBiomesFromFile(std::string filename);

    // singletons don't have descrustots
    void free();

    GDict *getBiomeFromTemp(int temp);

    GArray *biomes;

    int getMaxTemp();

};