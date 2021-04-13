// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <MRF/config.h>
#include <MRF/renderer.h>
#include <MRF/camera.h>
#include <MRF/scene.h>
#include <MRF/sprite.h>
#include <MRF/ui.h>

int main( void )
{
	Renderer renderer;

	Scene* scene = new Scene();
	
	//Giving UI's values
	UI* c_noteUI = new UI("assets/UI_A.tga");
	c_noteUI->position = glm::vec3(100.0f, 600.0f, 0.0f);
	UI* c_sharp_noteUI = new UI("assets/UI_W.tga");
	c_sharp_noteUI->position = glm::vec3(175.0f,400.0f, 0.0f);
	UI* d_noteUI = new UI("assets/UI_S.tga");
	d_noteUI->position = glm::vec3(250.0f, 600.0f, 0.0f);
	UI* d_sharp_noteUI = new UI("assets/UI_E.tga");
	d_sharp_noteUI->position = glm::vec3(325.0f, 400.0f, 0.0f);
	UI* e_noteUI = new UI("assets/UI_D.tga");
	e_noteUI->position = glm::vec3(400, 600.0f, 0.0f);
	UI* f_noteUI = new UI("assets/UI_F.tga");
	f_noteUI->position = glm::vec3(550, 600.0f, 0.0f);
	UI* f_sharp_noteUI = new UI("assets/UI_T.tga");
	f_sharp_noteUI->position = glm::vec3(625.0f, 400.0f, 0.0f);
	UI* g_noteUI = new UI("assets/UI_G.tga");
	g_noteUI->position = glm::vec3(700, 600.0f, 0.0f);
	UI* g_sharp_noteUI = new UI("assets/UI_Y.tga");
	g_sharp_noteUI->position = glm::vec3(775.0f, 400.0f, 0.0f);
	UI* a_noteUI = new UI("assets/UI_H.tga");
	a_noteUI->position = glm::vec3(850, 600.0f, 0.0f);
	UI* a_sharp_noteUI = new UI("assets/UI_U.tga");
	a_sharp_noteUI->position = glm::vec3(925.0f, 400.0f, 0.0f);
	UI* b_noteUI = new UI("assets/UI_J.tga");
	b_noteUI->position = glm::vec3(1000, 600.0f, 0.0f);
	
	//Giving sprites values
	Sprite* c_note = new Sprite("assets/white_key_note.tga");
	c_note->position = glm::vec3(100.0f, 400.0f, 0.0f);
	Sprite* c_sharp_note = new Sprite("assets/black_key_note.tga");
	c_sharp_note->position = glm::vec3(175.0f, 350.0f, 0.0f);
	Sprite* d_note = new Sprite("assets/white_key_note.tga");
	d_note->position = glm::vec3(250.0f, 400.0f, 0.0f);
	Sprite* d_sharp_note = new Sprite("assets/black_key_note.tga");
	d_sharp_note->position = glm::vec3(325.0f, 350.0f, 0.0f);
	Sprite* e_note = new Sprite("assets/white_key_note.tga");
	e_note->position = glm::vec3(400, 400.0f, 0.0f);
	Sprite* f_note = new Sprite("assets/white_key_note.tga");
	f_note->position = glm::vec3(550, 400.0f, 0.0f);
	Sprite* f_sharp_note = new Sprite("assets/black_key_note.tga");
	f_sharp_note->position = glm::vec3(625.0f, 350.0f, 0.0f);
	Sprite* g_note = new Sprite("assets/white_key_note.tga");
	g_note->position = glm::vec3(700, 400.0f, 0.0f);
	Sprite* g_sharp_note = new Sprite("assets/black_key_note.tga");
	g_sharp_note->position = glm::vec3(775.0f, 350.0f, 0.0f);
	Sprite* a_note = new Sprite("assets/white_key_note.tga");
	a_note->position = glm::vec3(850, 400.0f, 0.0f);
	Sprite* a_sharp_note = new Sprite("assets/black_key_note.tga");
	a_sharp_note->position = glm::vec3(925.0f, 350.0f, 0.0f);
	Sprite* b_note = new Sprite("assets/white_key_note.tga");
	b_note->position = glm::vec3(1000, 400.0f, 0.0f);

	
	//Adding UI's to the scene
	scene->addUI(c_noteUI);
	scene->addUI(d_noteUI);
	scene->addUI(e_noteUI);
	scene->addUI(f_noteUI);
	scene->addUI(g_noteUI);
	scene->addUI(a_noteUI);
	scene->addUI(b_noteUI);
	scene->addUI(c_sharp_noteUI);
	scene->addUI(d_sharp_noteUI);
	scene->addUI(f_sharp_noteUI);
	scene->addUI(g_sharp_noteUI);
	scene->addUI(a_sharp_noteUI);
	//Adding sprites to the scene
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
