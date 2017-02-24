// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
using System;
using UnrealBuildTool;
using System.IO;
using System.Collections.Generic;

public class LiMoBlueprintLib : ModuleRules
{

    public LiMoBlueprintLib(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "CoreUObject",
                "Engine",
                "Slate",
                "InputCore",
                "InputDevice",
                //"UnrealEd",
				// ... add other public dependencies that you statically link with here ...
			}
			);

        //LoadKiWiLib(Target);
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            CopyToBinaries(ModuleDirectory + "/lib/LiMoInterfaceDLL.dll", Target);
            CopyToBinaries(ModuleDirectory + "/lib/MotionHouseSDK.dll", Target);
        }
    }

    public bool LoadLib(TargetInfo Target, string LibName)
    {
        bool isLibrarySupported = false;


        if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
        {
            isLibrarySupported = true;

            string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "Win64" : "Win32";

            PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, PlatformString, LibName));

        }

        return isLibrarySupported;
    }

    private void CopyToBinaries(string Filepath, TargetInfo Target)
    {
        string ModuleBinaryPath = ModuleDirectory+"..\\..\\..\\";
        string binariesDir = Path.Combine(ModuleBinaryPath, "Binaries", Target.Platform.ToString());
        string filename = Path.GetFileName(Filepath);

        if (!Directory.Exists(binariesDir))
            Directory.CreateDirectory(binariesDir);

        if (!File.Exists(Path.Combine(binariesDir, filename)))
        {
            File.Copy(Filepath, Path.Combine(binariesDir, filename), true);
            
        }
        RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(binariesDir, filename)));

    }

    public string GetUProjectPath()
    {
        //Change this according to your module's relative location to your project file. If there is any better way to do this I'm interested!
        //Assuming Source/ThirdParty/YourLib/
        return Directory.GetParent(ModuleDirectory).Parent.Parent.ToString();
    }
    public string ModulePath
    {
        get { return ModuleDirectory; }
    }
    public string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "../ThirdParty/")); }
    }

    public string LibraryPath
    {
        get { return Path.GetFullPath(Path.Combine(ThirdPartyPath, "KiWiHIDLib", "Lib")); }
    }


}
