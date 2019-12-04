#pragma once
#include "subSystem.h"
#include "GameEngine.h"

#include "BoxEntity.h"
extern "C" {
#include <include/lua.h>
#include <include/lauxlib.h>
#include <include/lualib.h>
}

#include <LuaBridge\LuaBridge.h>

using namespace luabridge;

class LUAData : public subSystem
{
public:
	LUAData();
	~LUAData();
	static std::vector<std::string> getElements(const std::string& table, lua_State* L);
	void init();
	void update();
	void(*functions[6])(int);
	
	static lua_State* state;
	static std::string dir;
	static std::vector<std::string> elementList;


};

