// Copyright 2017 Chris "AngryGod" Buckingham M.A.G. Studios Canada. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TheDaysAfterMenuServerTarget : TargetRules
{
    public TheDaysAfterMenuServerTarget(TargetInfo Target) : base (Target)
    {
        Type = TargetType.Server;
        ExtraModuleNames.Add("TDA_Menu");
    }

    //
    // TargetRules interface.
    //
    //Modified for UE4.16
    //public override void SetupBinaries(
    //   TargetInfo Target,
    //   ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
    //    ref List<string> OutExtraModuleNames
    //    )
    //{
    //    base.SetupBinaries(Target, ref OutBuildBinaryConfigurations, ref OutExtraModuleNames);
    //    OutExtraModuleNames.Add("TDAMenu");
    //}
    
    
}