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


#ifndef MMGGA_SCENE_H
#define MMGGA_SCENE_H


#include <list>

#include <engine/engine.h>

namespace mmgga
{

	class GameObject;
	class Scene;

	/**
	* \brief The Scene Manager do the transition between two scenes, read from the Engine Configuration the scenes build list
	*/
	class SceneManager : public Module<SceneManager>
	{
	public:
		/**
		* \brief Initialize the SceneManager, get the Configuration from Engine and save the Scene lists from it
		*/
		void Init() override;
		/**
		* \brief Update the SceneManager, mostly updating the GameObjects of the current Scene and doing the transition when needed
		* \param dt Delta time since last frame
		*/
		void Update(sf::Time dt) override;
		/**
		* \brief Finalize and delete everything created in the SceneManager
		*/
		void Destroy() override;

		/**
		* \brief Load a Scene and create all its GameObject
		* \param sceneName the scene path given by the configuration
		* \return the heap Scene that will need to be destroyed
		*/
		Scene* LoadScene(std::string sceneName);

		/**
		* \brief Save a Scene on a JSon file
		* \param scene which must be save
		*/
		void SaveScene(Scene* scene);
	private:

		Scene* currentScene = nullptr;
	};

	/**
	* \brief The Scene includes GameObjects that are loaded from a JSON file
	*
	*/
	class Scene
	{
	public:
		/**
		* \brief Update the Scene, mostly updating the GameObjects and doing the transition when needed
		* \param dt Delta time since last frame
		*/
		void Update(sf::Time dt);
		/**
		* \brief Destroy all the GameObjects of the scene
		*/
		~Scene();
	protected:
		std::string name;
		std::list<GameObject*> m_GameObjects;
		friend class SceneManager;
	};
}
#endif
