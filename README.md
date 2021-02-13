# Vinegar
 My 2D/3D rendering engine. Requires C++ 14 and [CMake](https://cmake.org/download/). It ***attempts*** to follow the code it yourself philosophy.  

# Libraries
 Uses GLFW, GLM, OpenVR, and Bullet Physics.
 Planning to use these libraries in the future:  
-	Networking:		enet
-	Audio:			OpenAL or opus (depending on platform)
-	Scripting:		Python embedding in C++

# Building
   The build system uses CMake. Should be compatible with Windows and Linux at least.  
   Build by running these commands:
   ```
   git clone https://github.com/PyroFlareX/Vinegar.git
   cd Vinegar
   cmake .
   ```
   **IGNORE BELOW!!!**  

## Windows
 Works.  
 To build, first clone this repo (recursively so the submodules are clone). Then   
 Run 
 ```
 cmake .
 ```
 
## Linux
 *Should* work. 

## Cmake
If you don't have cmake installed, [go to their website](https://cmake.org/download/) and download it since unlike gradle which doesnt need to be downloaded, CMake needs to be installed seperately.