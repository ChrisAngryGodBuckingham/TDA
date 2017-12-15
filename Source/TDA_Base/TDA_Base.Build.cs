/*CopyRight 2017 Chris "AngryGod" Buckingham M.A.G.Studios Canada*/

using UnrealBuildTool;

public class TDA_Base : ModuleRules
{
	public TDA_Base(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
