// Copyright 2017 AngryGod MAG Studios. All Rights Reserved.

using UnrealBuildTool;

public class TheDaysAfter : ModuleRules
{
   	public TheDaysAfter(ReadOnlyTargetRules Target) : base(Target)
	{
        PrivateIncludePaths.AddRange(new string[]
            {
                "TheDaysAfter/Private",
                "TheDaysAfter/Public",
           //     "TheDaysAfter/TDA_Menu/Menu/Public",  //these are removed until ready for the main menu to fire in editor each time we test.
           //     "TheDaysAfter/TDA_Menu/Menu/Private"  //May only need to point to TheDaysAfter/TDA_Menu and not the public/private folders
            }
        );

		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
            {
		"AIModule",
		"AdvancedSessions",
                "Core",
                "CoreUObject",
                "Engine",
		"GameplayTasks",
                "HeadMountedDisplay",
                "InputCore",
                "MoviePlayer",
		"Networking",
                "OnlineSubsystem",
                "OnlineSubsystemUtils",     
                "OnlineSubsystemSteam",
                "OnlineSubsystemNull",
                "Sockets",
            }
        );

        // DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");

        PrivateDependencyModuleNames.AddRange(new string[] 
            {
                "OnlineSubsystem",
                "Sockets",
                "Networking",
                "OnlineSubsystemSteam",
                "OnlineSubsystemNull"
            }
        );
    }
}
	
