#ifndef DATATABLES_HPP
#define DATATABLES_HPP

#include <string>
#include <vector>

const unsigned int NUMBER_OF_ENEMY_PROFILES = 4;

struct EnemyProfileData
{
    std::string name;
    std::string description;
};

std::vector<EnemyProfileData> initializeEnemyProfileData();

#endif // DATATABLES_HPP
