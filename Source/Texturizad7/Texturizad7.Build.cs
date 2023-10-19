// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Texturizad7 : ModuleRules
{
	public Texturizad7(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
