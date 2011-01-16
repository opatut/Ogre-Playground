#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <OgreRoot.h>
#include <OgreConfigFile.h>
#include <OgreCamera.h>
#include <OgreViewport.h>
#include <OgreEntity.h>
#include <OgreWindowEventUtilities.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include "Root.hpp"


class Application : public Ogre::WindowEventListener, public Ogre::FrameListener {
public:
    Application();
	virtual ~Application();

	bool Run();
	void SetupScene();


	// Ogre::WindowEventListener
	virtual void windowResized(Ogre::RenderWindow* rw);
	virtual void windowClosed(Ogre::RenderWindow* rw);

	// Ogre::FrameListener
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

private:
	// Ogre basic elements
	Ogre::Root* mOgreRoot;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager* mSceneMgr;
	Ogre::Camera* mCamera;

	// Ogre Configuration File Locations
	Ogre::String mPluginsCfg;
	Ogre::String mResourcesCfg;

	// OIS Input devices
	OIS::InputManager* mInputManager;
	OIS::Mouse*    mMouse;
	OIS::Keyboard* mKeyboard;

	// Root object
	Root mRoot;

};

#endif // APPLICATION_HPP
