// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class TDA_Menu : ModuleRules
{
	public TDA_Menu(ReadOnlyTargetRules Target) : base (Target)
    {
        // added as after thought may not be needed
        PrivateIncludePaths.AddRange(new string[]
            {
                "TheDaysAfter/TDA_Menu",
            }
        );	
        PublicDependencyModuleNames.AddRange(new string[] 
			{ 
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"AdvancedSessions",
				"OnlineSubsystem",
				"OnlineSubsystemUtils",
				"Networking",
				"Sockets",
				"OnlineSubsystemSteam",
				"OnlineSubsystemNull",
				"MoviePlayer" 
			}
		);

        PrivateDependencyModuleNames.AddRange(new string[] 
			{ 
				"OnlineSubsystem",
				"Sockets",
				"Networking",
				"OnlineSubsystemSteam",
				"OnlineSubsystemNull" 
			}
		);

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        //PrivateDependencyModuleNames.Add("OnlineSubsystem");
        //if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
        //{
        //		if (UEBuildConfiguration.bCompileSteamOSS == true)
        //		{
        //			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
        //		}
        // }
    }
}
