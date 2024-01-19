//
// Created by ianpo on 19/01/2024.
//

#include <iostream>
#include <string>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE 1
#include <GLFW/glfw3.h>

int main(int argc, char** argv)
{/* Initialize the library */
//	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
		throw std::runtime_error("Couldn't initialize GLFW.");

	// Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
	// GL ES 2.0 + GLSL 100
        glsl_version = "#version 100";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
        glfwWindowHint(GLFW_RESIZABLE, allowResize ? GL_TRUE : GL_FALSE);
#elif defined(__APPLE__)
	// GL 3.2 + GLSL 150
        glsl_version = "#version 150";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
        glfwWindowHint(GLFW_RESIZABLE, allowResize ? GL_TRUE : GL_FALSE);
#else
	// GL 4.6 + GLSL 330
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
#endif

	/* Create a windowed mode window and its OpenGL context */
	auto m_Window = glfwCreateWindow(1600, 900, "Renderer", nullptr, nullptr);
	if (m_Window == nullptr) {
		glfwTerminate();
		throw std::runtime_error("Couldn't create the GLFW window.");
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(m_Window);
	glfwSwapInterval(1);

	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	std::cout << "OpenGL Info:" << std::endl;
	std::cout << "  Vendor: " << (const char*)glGetString(GL_VENDOR)  << std::endl;
	std::cout << "  Renderer: " << (const char*)glGetString(GL_RENDERER) << std::endl;
	std::cout << "  Version: " << (const char*)glGetString(GL_VERSION)  << std::endl;
	std::cout << "  Shading Version: " << (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION)  << std::endl;
	std::cout << "  Extensions: " << (const char*)glGetString(GL_EXTENSIONS)  << std::endl;

	while (!glfwWindowShouldClose(m_Window))
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}
	return 0;
}
