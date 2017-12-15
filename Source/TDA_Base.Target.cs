/*CopyRight 2017 Chris "AngryGod" Buckingham M.A.G.Studios Canada*/

using UnrealBuildTool;
using System.Collections.Generic;

public class TDA_BaseTarget : TargetRules
{
	public TDA_BaseTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("TDA_Base");
	}
}
