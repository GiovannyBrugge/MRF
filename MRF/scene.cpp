#include <iostream>
#include <MRF/scene.h>
#include <MRF/config.h>

Scene::Scene()
{
	_camera = new Camera();
}

Scene::~Scene()
{
	// Delete all the sprites
	for (size_t i = 0; i < _sprites.size(); i++)
	{
		delete _sprites[i];
		_sprites[i] = nullptr;
	}
	
	for (size_t i = 0; i < _uis.size(); i++)
	{
		delete _uis[i];
		_uis[i] = nullptr;
	}

	_sprites.clear();
	_uis.clear();
	// Delete camera
	delete _camera;
}

void Scene::update(float deltaTime)
{
	
}

void Scene::addSprite(Sprite* sprite)
{
	_sprites.push_back(sprite);
}

void Scene::addUI(UI* ui)
{
	_uis.push_back(ui);
}
