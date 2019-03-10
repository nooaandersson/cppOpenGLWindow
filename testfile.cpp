#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;
int width = 800; 
int height = 800;
int main() {
	glfwInit(); 

	void framebuffer_size_callback(GLFWwindow* widnow, int width, int height);

	GLFWwindow* window = glfwCreateWindow(width, height, "hello window", NULL, NULL); 
	//för att se så window fungerare om inte kommer vi bara stänga programet.
	if (window == NULL) {
		cout << "det funka inte att starta fönstere" << endl; 
		glfwTerminate(); 
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
	// nästa är att se om glad funkar det gör vi med funktionen "gladloader"

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "gick inte att få in glad, kanske du inte har länkat det rätt" << endl;
		return -1;
	}

	while (!glfwWindowShouldClose) {


		glClearColor(0.0f, 0.2f, 0.4f, 0.0f); 
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents(); 
		glfwSwapBuffers(window);


	}


	return 0;
}

void framebuffer_size_callback(GLFWwindow* widnow, int width, int height) {

	glViewport(0, 0, width, height);


}