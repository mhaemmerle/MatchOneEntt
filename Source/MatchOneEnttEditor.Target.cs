using UnrealBuildTool;
using System.Collections.Generic;

public class MatchOneEnttEditorTarget : TargetRules
{
    public MatchOneEnttEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;

        ExtraModuleNames.AddRange(new string[] { "MatchOneEntt" });
    }
}
