from SetupPython import PythonConfiguration as PythonRequirements
# Make sure everything we need for the setup is installed
PythonRequirements.Validate()

from SetupBuildTools import BuildToolsConfiguration as BuildRequirements
# Make sure CMake and Ninja are insalled correctly
BuildRequirements.Validate()

from SetupClang import ClangConfiguration as ClangRequirements
# Make sure Clang is installed correctly
ClangRequirements.Validate()