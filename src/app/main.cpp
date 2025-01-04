#include "ui/container/Window.h"
#include "menu/WelcomeSplash.h"
#include "DataUtil.h"
#include "ui/ui.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

int main() {
    glfwInit();
    
    Rect2d screenSize;
    glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), NULL, NULL, &screenSize.x, &screenSize.y);

    ui::AppInit();

    WelcomeSplash* startupSplash = new WelcomeSplash();
    startupSplash
        ->setTitle("Welcome")
        //->setMargined(true)
        //->setBorderless(true)
        ->setResizable(false)
        ->setSize({screenSize.x / 4, screenSize.y / 4})
        ->createAndShow();
    
    ui::AppMain();
    ui::AppUninit();
}