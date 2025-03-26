// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TheEchoEscape : ModuleRules {
    public TheEchoEscape(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        string[] publicModules = new string[] {
            "Core", 
            "CoreUObject", 
            "Engine", 
            "InputCore", 
            "EnhancedInput", 
            "UMG"
        };
        PublicDependencyModuleNames.AddRange(publicModules);

        string[] privateModules = new string[] {

        };
        PrivateDependencyModuleNames.AddRange(privateModules);

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
