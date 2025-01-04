#pragma once

#include "ui/container/Window.h"

#include <rocket.hpp>

class WelcomeSplash : public Window {
public:
    WelcomeSplash() = default;
    ~WelcomeSplash() = default;

    int onClose() override;
    void onSizeChange() override;
    void onFocusChange() override;

private:

};