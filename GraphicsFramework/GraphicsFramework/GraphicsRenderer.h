#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>

class GraphicsRenderer
{
public:
  GraphicsRenderer();
  ~GraphicsRenderer();

  void run();
private:
  GLFWwindow* mWindow;
  VkInstance mInstance;
  const int WIDTH = 800;
  const int HEIGHT = 600;

  void initVulkan();
  void createInstance();
  void initWindow();
  VkApplicationInfo getApplicationInfo();
  void mainLoop();
  void cleanup();
};

