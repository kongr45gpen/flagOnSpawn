// flagOnSpawn.cpp : Defines the entry point for the DLL application.
//

#include "bzfsAPI.h"
#include "plugin_utils.h"
#include <stdlib.h>

class bzspawnflagvar : public bz_Plugin
{
  virtual const char* Name (){return "Flag on Spawn";}
  virtual void Init ( const char* config);

  virtual void Event ( bz_EventData * eventData );
};

BZ_PLUGIN(bzspawnflagvar)

void bzspawnflagvar::Init ( const char* /*commandLine*/ )
{
  bz_debugMessage(4,"flagOnSpawn plugin loaded");
  if (!bz_BZDBItemExists("_flagonspawn") && bz_setBZDBString ( "_flagonspawn", "none", 0 , 0 ))
  {
	bz_debugMessage(4,"flagOnSpawn plugin set");
  } else  {
	bz_debugMessage(4,"flagOnSpawn plugin failed or already set");
  }
  Register(bz_ePlayerSpawnEvent);
}

void bzspawnflagvar::Event ( bz_EventData *eventData )
{
    if(eventData->eventType==bz_ePlayerSpawnEvent) {
      //Here we read the _flagonspawn variable
      std::string flaggive=(bz_getBZDBString("_flagonspawn")).c_str();
      const int maxrounds = 20;
      if(flaggive == "random") {
        for(int i=0; i<maxrounds; i++) {
          int flagid = rand() % bz_getNumFlags();
          if(bz_flagPlayer(flagid) != -1 && i != maxrounds-1) continue;

          //There is an unused flag. Give a similar one to the player.
          bz_PlayerSpawnEventData_V1* data = (bz_PlayerSpawnEventData_V1*)eventData;
          bz_givePlayerFlag(data->playerID,bz_getFlagName(flagid).c_str(),1);
          bz_debugMessage(4,"gave random flag");
          break;
        }

      } else if(flaggive != "none") {
         //Here we give a flag to the player
         bz_PlayerSpawnEventData_V1* data = (bz_PlayerSpawnEventData_V1*)eventData;
         bz_givePlayerFlag(data->playerID,flaggive.c_str(),1);
         bz_debugMessage(4,"gave flag");
      }
    }
}

// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8
