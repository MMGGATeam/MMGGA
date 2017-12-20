/*
MIT License

Copyright (c) 2017 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef MMGGA_ENGINE_H
#define MMGGA_ENGINE_H

//Engine
#include <engine/utility.h>
#include <engine/config.h>

//Dependancies
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

namespace mmgga
{
	//class prototype
	class PythonManager;

	//class prototype
	class SceneManager;

	//class prototype
	class InputManager;

	//class prototype
	class GraphicsManager;
/**
* \brief The main Engine class to centralise the frame process and the references
*/
class Engine
{
public:
	/**
	* \brief Constructor of the Engine
	*/
	Engine();
	/**
	* \brief Initialize all the modules of the Game Engine, reading the config file too
	*/
	void Init();
	/**
	* \brief Starting the Game Engine after the Init()
	*/
	void Start();
	/**
	* \brief Update the Game Engine after the Start()
	*/
	void Update(sf::Time dt);

	~Engine();
	/**
	* \brief A getter of the Configuration
	* \return The Configuration struct got by the Engine
	*/
	Configuration* GetConfig();
	/**
	* \brief sf::window reference
	*/
	sf::RenderWindow* GetWindow();

	bool running = false;
	bool editor = false;
protected:
	Configuration* m_Config = nullptr;
	sf::RenderWindow* m_Window = nullptr;
	std::shared_ptr<PythonManager> m_PythonManager;
	std::shared_ptr<SceneManager> m_SceneManager;
	std::shared_ptr<InputManager> m_InputManager;
	std::shared_ptr<GraphicsManager> m_GraphicsManager;
};

/**
* \brief Module are Singleton used by the Engine to init and update features
*/
class Module 
{
public:
	/**
	* \brief constructor of Module taking Engine references in argument
	*/
	Module(Engine& engine);
	/**
	* \brief Called to initialize the module
	*/
	virtual void Init() = 0;
	/**
	* \brief Called every frame to update the module
	* \param dt The delta time since last frame
	*/
	virtual void Update(sf::Time dt) = 0;
	/**
	* \brief Used instead of the destructor to delete all heap created structure and finalize
	*/
	virtual void Destroy() = 0;
protected:
	virtual ~Module() {};
	Engine& engine;
};

}

#endif // !SFGE_ENGINE_H
