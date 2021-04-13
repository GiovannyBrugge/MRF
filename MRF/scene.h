#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <MRF/camera.h>
#include <MRF/sprite.h>
#include <MRF/ui.h>
class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void update(float deltaTime);
	void addSprite(Sprite* sprite);
	void addUI(UI* ui);

	Camera* camera() { return _camera; };
	std::vector<Sprite*>& sprites() { return _sprites; };
	std::vector<UI*>& uis() { return _uis; };
private:
	Camera* _camera;
	std::vector<Sprite*> _sprites;
	std::vector<UI*> _uis;
};

#endif /* SCENE_H */
