#include "GraphicsRenderer.h"

const char* RENDERER_NAME = "Vulkan renderer";
const char* ENGINE_NAME = "No engine";
const uint32_t VK_MAKE_VERSION = VK_MAKE_VERSION(1, 0, 0);
const uint32_t VK_API_VERSION = VK_API_VERSION_1_0;

GraphicsRenderer::GraphicsRenderer()
{
}


GraphicsRenderer::~GraphicsRenderer()
{
}

void GraphicsRenderer::run()
{
  initWindow();
  mainLoop();
}

void GraphicsRenderer::initVulkan()
{
}

void GraphicsRenderer::createInstance()
{
  // TODO: split function to createInstance, extentions and validation layers

  VkApplicationInfo appInfo = getApplicationInfo();

  VkInstanceCreateInfo createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;

  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions;

  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  createInfo.enabledExtensionCount = glfwExtensionCount;
  createInfo.ppEnabledExtensionNames = glfwExtensions;

  createInfo.enabledLayerCount = 0;

  VkResult result = vkCreateInstance(&createInfo, nullptr, &mInstance);

  if (vkCreateInstance(&createInfo, nullptr, &mInstance) != VK_SUCCESS) {
    throw std::runtime_error("failed to create instance!");
  }
}

void GraphicsRenderer::initWindow()
{
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  mWindow = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
}

VkApplicationInfo GraphicsRenderer::getApplicationInfo()
{
  VkApplicationInfo appInfo = {};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = RENDERER_NAME;
  appInfo.applicationVersion = VK_MAKE_VERSION;
  appInfo.pEngineName = ENGINE_NAME;
  appInfo.engineVersion = VK_MAKE_VERSION;
  appInfo.apiVersion = VK_API_VERSION;

  return appInfo;
}

void GraphicsRenderer::mainLoop()
{
  while (!glfwWindowShouldClose(mWindow)) {
    glfwPollEvents();
  }
}

void GraphicsRenderer::cleanup()
{
  vkDestroyInstance(mInstance, nullptr);
  glfwDestroyWindow(mWindow);
  glfwTerminate();
}
