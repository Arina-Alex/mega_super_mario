#include "console_moving_platform.hpp"

using biv::ConsoleMovingPlatform;

ConsoleMovingPlatform::ConsoleMovingPlatform(const Coord& top_left, const int width, const int height, float speed, float max_distance) 
    : MovingPlatform(top_left, width, height, speed, max_distance) {}

char ConsoleMovingPlatform::get_brush() const noexcept {
    return '='; 
}