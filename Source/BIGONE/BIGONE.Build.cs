// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BIGONE : ModuleRules
{
	public BIGONE(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
