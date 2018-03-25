using UnrealBuildTool;
using System.Collections.Generic;

public class MatchOneEnttTarget : TargetRules
{
    public MatchOneEnttTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;

        ExtraModuleNames.AddRange(new string[] { "MatchOneEntt" });
    }
}
