#include <DataTables.hpp>

std::vector<EnemyProfileData> initializeEnemyProfileData()
{
    std::vector<EnemyProfileData> data(NUMBER_OF_ENEMY_PROFILES);

    data[0].name        =   "Enemy 1";
    data[0].description =   "Basic ground troop, fires at player, \n"
                            "and damages player upon touch.\n";

    data[1].name        =   "Enemy 2";
    data[1].description =   "Another description of some enemy...";

    data[2].name        =   "Enemy 3";
    data[2].description =   "Another description of some enemy...";

    data[3].name        =   "Enemy 4";
    data[3].description =   "Another description of some enemy...";

    return data;
}
