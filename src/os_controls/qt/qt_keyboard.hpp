#pragma once
#include <atomic>
#include "keyboard.hpp"

namespace biv {
    class QtKeyboard : public KeyBoard {
    private:
        std::atomic<UserInput> current_input;
        bool is_active;

    public:
        QtKeyboard() : current_input(UserInput::NO_INPUT), is_active(false) {}

        UserInput get_user_input() override {
            if (!is_active) return UserInput::NO_INPUT;
            UserInput input = current_input.load();
            current_input.store(UserInput::NO_INPUT);
            return input;
        }

        void off() override { is_active = false; }
        void on() override { is_active = true; current_input = UserInput::NO_INPUT; }

        void set_input(UserInput input) {
            if (is_active) {
                current_input.store(input);
            }
        }
    };
}