//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Demomstrates how a ClassTable might be populated.
//
//=============================================================================

#include <iostream>
#include <vector>
#include <string>

//#define DECLARE_GAME_OBJECT(ClassName)   To populate the class table. This is
//          more generic and should be called with each system and component
//          registration.

//#define DECLARE_CUSTOM_ENTITY(EntityName)  To create a custom entity with
//          specific components associated with it.


#define DECLARE_SYSTEM(ClassName)  \
    GameSystemRegistration g_##ClassName##_ClassReg(#ClassName, g_SystemManager)

//#define DECLARE_COMPONENT(ComponentName)  \
//    ComponentRegistration g_##ClassName##_ComponentReg(#ClassName, g_ComponentManager);\

// Could be templated to allocate arrays for the components.







class SystemManager {
public:
    int totalSystems = 0;
    std::vector<std::string> classNames;

    SystemManager() = default;
    int registerSystem(std::string sName) {
        classNames.push_back(sName);
        return totalSystems++;
    }
    std::vector<std::string> getSystems() {
        return this->classNames;
    }
};


class GameSystemRegistration {
public:
    int classID;
    GameSystemRegistration(std::string className, SystemManager &sManager) {
        classID = sManager.registerSystem(className);  // Maybe give pointer to self
    }
};


// Define global system manager
SystemManager g_SystemManager;






// Custom systems with registration
class CustomSystem1;
DECLARE_SYSTEM(CustomSystem1);

class CustomSystem2;
DECLARE_SYSTEM(CustomSystem2);


//GameSystemRegistration g_Sys1("Sys1", g_SystemManager);
//GameSystemRegistration g_Sys2("Sys2", g_SystemManager);

int main() {
    std::vector<std::string> classNames = g_SystemManager.getSystems();

    // Print all systems in global system manager
    for (std::string str : classNames) {
        std::cout << str << ' ';
    }

    return 0;
}
