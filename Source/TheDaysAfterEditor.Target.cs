// Copyright 2017 Chris "AngryGod" Buckingham M.A.G. Studios Canada. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TheDaysAfterEditorTarget : TargetRules
{
   	public TheDaysAfterEditorTarget(TargetInfo Target) : base(Target)
		{
			Type = TargetType.Editor;
			ExtraModuleNames.Add("TheDaysAfter");
			
		}
}

/*
public class TDA_MenuEditorTarget : TargetRules
{
    public TDA_MenuEditorTarget(TargetInfo Target) : base(Target)
		{
			Type = TargetType.Editor;
			ExtraModuleNames.Add("TDA_Menu");

		}
}

public class SurvivalGameEditorTarget : TargetRules
{
	public SurvivalGameEditorTarget(TargetInfo Target) : base(Target)
    {
		Type = TargetType.Editor;
        ExtraModuleNames.AddRange(new string[] { "SurvivalGame" });
    }
}
*/