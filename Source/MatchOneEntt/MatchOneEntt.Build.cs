using UnrealBuildTool;
using System;
using System.IO;

public class MatchOneEntt : ModuleRules
{
    public MatchOneEntt(ReadOnlyTargetRules Target) : base(Target)
    {
        //PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Paper2D" });
        PrivateDependencyModuleNames.AddRange(new string[] { });

        CppStandard = CppStandardVersion.Cpp17;

        PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "entt", "src", "entt"));
    }

    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/")); }
    }
}
