// Copyright 2017 Chris "AngryGod" Buckingham M.A.G. Studios Canada. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TheDaysAfterTarget : TargetRules
{
       public TheDaysAfterTarget(TargetInfo Target) : base(Target)
		{
			Type = TargetType.Game;
			ExtraModuleNames.Add("TheDaysAfter");
			bUsesSteam = true;
		}
}
/*public class TDA_MenuTarget : TargetRules
{
    public TDA_MenuTarget(TargetInfo Target) : base(Target)
		{
			Type = TargetType.Game;
			ExtraModuleNames.Add("TDA_Menu");
			
		}
}

public class SurvivalGameTarget : TargetRules
{
	public SurvivalGameTarget(TargetInfo Target) : base(Target)
    {
		Type = TargetType.Game;
        ExtraModuleNames.AddRange(new string[] { "SurvivalGame" });
    }
}*/