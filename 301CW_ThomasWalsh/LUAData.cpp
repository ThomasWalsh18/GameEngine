#include "LUAData.h"
lua_State* LUAData::state;
std::vector<std::string> LUAData::elementList;

LUAData::LUAData()
{
	/*
	Load the window creation stuff first from the lua window
	This is done on contrution so that the windows window knows how big to be
	*/
	state = luaL_newstate();
	luaL_dofile(state, "Window.lua");
	luaL_openlibs(state);
	lua_pcall(state, 0, 0, 0);

	LuaRef t = getGlobal(state, "Window");
	LuaRef title = t["title"];
	LuaRef w = t["width"];
	LuaRef h = t["height"];

	GameEngine::title = title.cast<std::string>();
	GameEngine::width = w.cast<int>();
	GameEngine::height = h.cast<int>();
}

LUAData::~LUAData()
{
}

void loadLevel(int level)
{	
	/*
	Clear all the entites that currently exist as well as their bounding boxes
	*/
	for (int i = GameEngine::entities.size()-1;  i >= 0; i--) {
		if (int(GameEngine::entities[i]->type) != 1) {

			if (GameEngine::entities[i]->GetSceneNode() != nullptr) {
				GameEngine::entities[i]->GetSceneNode()->remove();

			}
			else if (GameEngine::entities[i]->GetSimpleSceneNode() != nullptr) {
				GameEngine::entities[i]->GetSimpleSceneNode()->remove();
			}
			btCollisionObject* obj = Physics::world->getCollisionObjectArray()[i];
			Physics::world->removeCollisionObject(obj);
			delete obj;
		}
		GameEngine::entities[i]->destroy();
	}
	GameEngine::entities.erase(GameEngine::entities.begin(), GameEngine::entities.end());


	LUAData::state = luaL_newstate();
	/*
	The starting level that can also be changed on runtime
	*/
	if (level == 1) {
		luaL_dofile(LUAData::state, "elements.lua");
	}
	else {
		luaL_dofile(LUAData::state, "elements2.lua");
	}

	luaL_openlibs(LUAData::state);
	lua_pcall(LUAData::state, 0, 0, 0);

	LUAData::elementList = LUAData::getElements("elementList", LUAData::state);

	LuaRef elementsRef = getGlobal(LUAData::state, "elementList");
	int checker;

	for (int i = 0; i < LUAData::elementList.size(); i++)
	{
		LuaRef entityCheck = elementsRef[LUAData::elementList.at(i)];
		checker = entityCheck["e_type"].cast<int>();
		/*
		If the Checker is the correct value get comman varaibles between the different entites
		Then check the entites to see which one is which, then depending on the entity
		Get the correct data
		*/
		if (checker >= 0)
		{
			float x = entityCheck["positionx"].cast<float>();
			float y = entityCheck["positiony"].cast<float>();
			float z = entityCheck["positionz"].cast<float>();

			float mass = entityCheck["mass"].cast<float>();

			std::string texture = entityCheck["Texture"].cast<std::string>();

			if (checker == 4) {
				float rx = entityCheck["rotationx"].cast<float>();
				float ry = entityCheck["rotationy"].cast<float>();
				float rz = entityCheck["rotationz"].cast<float>();

				float sx = entityCheck["scalex"].cast<float>();
				float sy = entityCheck["scaley"].cast<float>();
				float sz = entityCheck["scalez"].cast<float>();

				float size = entityCheck["size"].cast<float>();

				std::string texture2 = entityCheck["Texture2"].cast<std::string>();

				Entity* temp = new BoxEntity(
					glm::vec3(x, y, z),
					mass,
					size,
					glm::vec3(rx, ry, rz),
					glm::vec3(sx, sy, sz),
					EntityEnum(checker),
					texture);
				GameEngine::entities.push_back(temp);

			}
			else {
				std::string model = entityCheck["Model"].cast <std::string>();
				std::string file = entityCheck["file"].cast <std::string>();
				Entity* temp = new moveEntity(
					glm::vec3(x, y, z),
					mass,
					model,
					file, 
					EntityEnum(checker),
					texture);
				GameEngine::entities.push_back(temp);
			}
		}
	}
}

std::vector<std::string> LUAData::getElements(const std::string& table, lua_State* L) {
	std::string source =
		"function getElements(table) "
		"s = \"\""
		"for k, v in pairs(_G[table]) do "
		"    s = s..k..\"|\" "
		"    end "
		"return s "
		"end";

	luaL_loadstring(L, source.c_str());
	lua_pcall(L, 0, 0, 0);
	lua_getglobal(L, "getElements");
	lua_pushstring(L, table.c_str());
	lua_pcall(L, 1, 1, 0);

	std::string ans = lua_tostring(L, -1);
	std::vector<std::string> elements;
	std::string temp = "";
	for (unsigned int i = 0; i < ans.size(); i++) {
		if (ans.at(i) != '|') {
			temp += ans.at(i);
		}
		else {
			elements.push_back(temp);
			temp = "";
		}
	}

	int n = lua_gettop(L);
	lua_pop(L, 1);

	return elements;
}

void LUAData::init()
{
	void(*level)(int) = loadLevel;
	functions[5] = loadLevel;
	
	
	loadLevel(1);
	
}

void LUAData::update()
{
	if (GameEngine::eventQueue.size() != 0) { // if event Q is populated
		for (int i = 0; i < GameEngine::eventQueue.size(); i++) {	// for each event, then for each sub system in each event
			for (int j = 0; j < GameEngine::eventQueue[i]->mySubs.size(); j++) {
				if (GameEngine::eventQueue[i]->mySubs[j] == SubSystemEnum(6)) { // check to see if it need the current subsystem
					functions[int(GameEngine::eventQueue[i]->functPoint)](GameEngine::eventQueue[i]->eventInfo.level);
					GameEngine::eventQueue[i]->mySubs.erase(GameEngine::eventQueue[i]->mySubs.begin() + j);
				}
			}
		}
	}
}
