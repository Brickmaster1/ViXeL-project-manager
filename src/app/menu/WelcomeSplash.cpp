#include "WelcomeSplash.h"
#include "ui/ui.hpp"

int WelcomeSplash::onClose() {
    ui::AppQuit();
    return 1;
}

void WelcomeSplash::onSizeChange() {

}

void WelcomeSplash::onFocusChange() {
    
}