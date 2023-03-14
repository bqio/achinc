#if defined _achinc_included
	#endinput
#endif

#define _achinc_included

#if !defined MAX_ACHIEVEMENTS
	#define MAX_ACHIEVEMENTS 100
#endif

#if !defined MAX_ACHIEVEMENTS_NAME
	#define MAX_ACHIEVEMENTS_NAME 256
#endif

#if !defined MAX_ACHIEVEMENTS_DESCRIPTION
	#define MAX_ACHIEVEMENTS_DESCRIPTION 1024
#endif

#if !defined ACHIEVEMENTS_DIALOG_ID
	#define ACHIEVEMENTS_DIALOG_ID 55055
#endif

new gAchievements[MAX_PLAYERS][MAX_ACHIEVEMENTS];
new gAchievementsName[MAX_ACHIEVEMENTS][MAX_ACHIEVEMENTS_NAME];
new gAchievementsDesc[MAX_ACHIEVEMENTS][MAX_ACHIEVEMENTS_DESCRIPTION];


stock Achievements_Create(achid, const name[], const description[])
{
  strcat(gAchievementsName[achid], name, MAX_ACHIEVEMENTS_NAME);
  strcat(gAchievementsDesc[achid], description, MAX_ACHIEVEMENTS_DESCRIPTION);
}

stock Achievements_Unlock(playerid, achid)
{
  gAchievements[playerid][achid] = 1;
}

stock Achievements_Lock(playerid, achid)
{
  gAchievements[playerid][achid] = 0;
}

stock Achievements_IsDone(playerid, achid)
{
  return gAchievements[playerid][achid];
}

stock Achievements_ShowDialog(playerid)
{
  ShowPlayerDialog(playerid, ACHIEVEMENTS_DIALOG_ID, DIALOG_STYLE_TABLIST,
  "Achievements", "Data", "Choose", "Close");
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
  if (dialogid == ACHIEVEMENTS_DIALOG_ID)
  {
    if (response)
    {
      return 1;
    }
  }

  return 0;
}