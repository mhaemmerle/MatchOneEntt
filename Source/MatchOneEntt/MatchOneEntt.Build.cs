using UnrealBuildTool;
using System;
using System.IO;

public class MatchOneEntt : ModuleRules
{
    public MatchOneEntt(ReadOnlyTargetRules Target) : base(Target)
    {
        //PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        bUseRTTI = true;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Paper2D" });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        var p = Path.Combine(ThirdPartyPath, "entt", "src", "entt");

        Console.WriteLine("p " + p);

        PublicIncludePaths.Add(p);

        PublicIncludePaths.AddRange(new string[] { "../../ThirdParty/entt/src/entt" });
    }

    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/")); }
    }
}
