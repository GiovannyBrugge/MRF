#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <MRF/scene.h>
#include <MRF/camera.h>
#include <MRF/sprite.h>
#include <MRF/ui.h>
class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

	void renderScene(Scene* scene);
	void renderSprite(Sprite* sprite);
	void renderUI(UI* ui);
	GLFWwindow* window() { return _window; };

	float updateDeltaTime();

private:
	int init();

	GLFWwindow* _window;

	GLuint loadShaders(
		const std::string& vertex_file_path,
		const std::string& fragment_file_path
	);

	GLuint _programID;

	Camera* _camera; // reference to scene->camera
};

#endif /* RENDERER_H */
