# Viewer
This repository provides an Unreal Engine based Ifc-Viewer. It was created with modularity in mind and should be easily extendable with additional plugins. The project is still at an early stage; therefore, major changes to the structure and the tools used are to be expected.

# Dependencies
## Unreal Engine Plugins
The following Unreal Engine plugins are required for this project and need to be put into the projects "Plugins" folder. If no Plugins folder is provided, simply create a new one.

EasyFileDialog: https://www.unrealengine.com/marketplace/en-US/product/easy-file-dialog/

EasyXMLParser: https://github.com/ayumax/EasyXMLParser

LowEntryExtStdLib: https://code.lowentry.com/Applications/Plugins/UE4/ExtendedStandardLibrary

glTFRuntime: https://github.com/rdeioris/glTFRuntime / https://www.unrealengine.com/marketplace/en-US/product/gltfruntime

VaRestPlugin: https://github.com/ufna/VaRest

Victory: https://github.com/EverNewJoy/VictoryPlugin


## IfcConvert
The Plugins depends on the IfcConvert.exe from [IfcOpenShell](https://github.com/IfcOpenShell/IfcOpenShell). It is used for converting the selected IFC File into a glTF file for geometry, and an XML file for the properties. You can browse to the GitHub Repository of IfcOpenShell and compile the code from source, or download the IfcConvert.exe directly from the [projects website](http://ifcopenshell.org/ifcconvert). For the current version of the viewer we used version 0.6.0. Once the IfcConvert.exe is generated or downloaded, place it in the Unreal Engine projects Content folder under `Content/IfcConvert/IfcConvert.exe`.
