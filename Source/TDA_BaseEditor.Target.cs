/*CopyRight 2017 Chris "AngryGod" Buckingham M.A.G.Studios Canada*/

using UnrealBuildTool;
using System.Collections.Generic;

public class TDA_BaseEditorTarget : TargetRules
{
	public TDA_BaseEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("TDA_Base");
	}
}
