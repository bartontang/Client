/*
 * pbc-lua.h
 *
 *  Created on: 2014年3月26日
 *      Author: root
 */

#ifndef PBC_LUA_H_
#define PBC_LUA_H_

//#include "Gcc.h"

extern "C"
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
	#include "pbc.h"
}

int luaopen_protobuf_c(lua_State *L);


#endif /* PBC_LUA_H_ */
