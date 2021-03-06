#include <OgreException.h>

#include "Application.hpp"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
	int main(int argc, char *argv[])
#endif
	{
		// Create application object
		Application app;

		try {
			app.Run();
		} catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
			MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
			std::cerr << "################### OGRE EXCEPTION ###################" << std::endl;
			std::cerr << e.getFullDescription().c_str() << std::endl;
			std::cerr << "################### EXCEPTION END ####################" << std::endl;
#endif
		}

		return 0;
	}

#ifdef __cplusplus
}
#endif
