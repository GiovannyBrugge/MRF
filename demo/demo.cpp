// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <MRF/config.h>
#include <MRF/renderer.h>
#include <MRF/camera.h>
#include <MRF/scene.h>
#include <MRF/sprite.h>

int main( void )
{
	Renderer renderer;

	Scene* scene = new Scene();
	
	Sprite* c_note = new Sprite("assets/white_key_note.tga");
	c_note->position = glm::vec3(100.0f, 400.0f, 0.0f);
	Sprite* c_sharp_note = new Sprite("assets/black_key_note.tga");
	c_sharp_note->position = glm::vec3(200.0f, 350.0f, 0.0f);
	Sprite* d_note = new Sprite("assets/white_key_note.tga");
	d_note->position = glm::vec3(250.0f, 400.0f, 0.0f);
	Sprite* d_sharp_note = new Sprite("assets/black_key_note.tga");
	d_sharp_note->position = glm::vec3(350.0f, 350.0f, 0.0f);
	Sprite* e_note = new Sprite("assets/white_key_note.tga");
	e_note->position = glm::vec3(400, 400.0f, 0.0f);
	Sprite* f_note = new Sprite("assets/white_key_note.tga");
	f_note->position = glm::vec3(550, 400.0f, 0.0f);
	Sprite* f_sharp_note = new Sprite("assets/black_key_note.tga");
	f_sharp_note->position = glm::vec3(650.0f, 350.0f, 0.0f);
	Sprite* g_note = new Sprite("assets/white_key_note.tga");
	g_note->position = glm::vec3(700, 400.0f, 0.0f);
	Sprite* g_sharp_note = new Sprite("assets/black_key_note.tga");
	g_sharp_note->position = glm::vec3(800.0f, 350.0f, 0.0f);
	Sprite* a_note = new Sprite("assets/white_key_note.tga");
	a_note->position = glm::vec3(850, 400.0f, 0.0f);
	Sprite* a_sharp_note = new Sprite("assets/black_key_note.tga");
	a_sharp_note->position = glm::vec3(950.0f, 350.0f, 0.0f);
	Sprite* b_note = new Sprite("assets/white_key_note.tga");
	b_note->position = glm::vec3(1000, 400.0f, 0.0f);

	scene->addSprite(c_note);
	scene->addSprite(d_note);
	scene->addSprite(e_note);
	scene->addSprite(f_note);
	scene->addSprite(g_note);
	scene->addSprite(a_note);
	scene->addSprite(b_note);
	scene->addSprite(c_sharp_note);
	scene->addSprite(d_sharp_note);
	scene->addSprite(f_sharp_note);
	scene->addSprite(g_sharp_note);
	scene->addSprite(a_sharp_note);

	do {
		// get deltaTime and update camera
		float dt = renderer.updateDeltaTime();
		scene->camera()->computeViewMatrixFromInput(renderer.window(), dt);

		// Update the scene
		scene->update(dt); // TODO make subclass for Scene (and make Scene abstract?)
		

		// Render the scene
		renderer.renderScene(scene);
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(renderer.window()) == 0 );

	delete scene;

	return 0;
}
