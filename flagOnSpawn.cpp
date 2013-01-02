// flagOnSpawn.cpp : Defines the entry point for the DLL application.
//

#include "bzfsAPI.h"
#include "plugin_utils.h"

BZ_GET_PLUGIN_VERSION

class flagOnSpawn_events : public bz_EventHandler
{
  virtual void process ( bz_EventData *eventData )
  {
    if(eventData->eventType==bz_ePlayerSpawnEvent)
    {
      //Here we read the _flagonspawn variable
      std::string flaggive=(bz_getBZDBString("_flagonspawn")).c_str();
      if(flaggive!="AA")
      {
﻿   //Here we give a flag to the player
﻿   bz_PlayerSpawnEventData* data = (bz_PlayerSpawnEventData*)eventData;
﻿   bz_givePlayerFlag(data->playerID,flaggive.c_str(),1);
﻿   bz_debugMessage(4,"gave flag");
      }
    }
  }
};

flagOnSpawn_events flagOnSpawn_events;
BZF_PLUGIN_CALL int bz_Load ( const char* /*commandLine*/ )
{
  bz_debugMessage(4,"flagOnSpawn plugin loaded");
      if (bz_setBZDBString ( "_flagonspawn", "AA", 0 , 0 ))
 ﻿  {  
﻿    bz_debugMessage(4,"flagOnSpawn plugin set");
﻿  }
      else
﻿  {
﻿    bz_debugMessage(3,"flagOnSpawn plugin failed");
﻿  }

  bz_registerEvent(bz_ePlayerSpawnEvent,&flagOnSpawn_events);
  return 0;


}

BZF_PLUGIN_CALL int bz_Unload ( void )
{
  bz_debugMessage(4,"flagOnSpawn plugin unloaded");
  bz_removeEvent(bz_ePlayerSpawnEvent,&flagOnSpawn_events);
  return 0;
}

//plugin by alezakos

// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8


