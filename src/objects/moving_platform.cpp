#include "moving_platform.hpp"

using biv::MovingPlatform;

MovingPlatform::MovingPlatform(const Coord& top_left, const int width, const int height, float speed, float max_distance) 
    : RectMapMovableAdapter(top_left, width, height) {
    this->start_x = top_left.x;
    this->max_distance = max_distance;
    this->vspeed = 0;
    this->hspeed = speed; 
}

biv::Rect MovingPlatform::get_rect() const noexcept {
    return {top_left, width, height};
}

biv::Speed MovingPlatform::get_speed() const noexcept {
    return {vspeed, hspeed};
}

void MovingPlatform::set_mario(Mario* m) noexcept {
    this->mario = m;
}

void MovingPlatform::process_horizontal_static_collision(Rect* obj) noexcept {
    hspeed = -hspeed;
    top_left.x += hspeed;
}

void MovingPlatform::process_mario_collision(Collisionable* m) noexcept {}

void MovingPlatform::process_vertical_static_collision(Rect* obj) noexcept {}

void MovingPlatform::move_vertically() noexcept {}

void MovingPlatform::move_horizontally() noexcept {
    top_left.x += hspeed;

    if (top_left.x >= start_x + max_distance || top_left.x <= start_x - max_distance) {
        hspeed = -hspeed;
    }

    if (mario != nullptr) {
        Rect m_rect = mario->get_rect();
        Rect p_rect = get_rect();
        
        bool is_mario_on_top = (m_rect.get_bottom() >= p_rect.get_top() && 
                                m_rect.get_bottom() <= p_rect.get_top() + 1) &&
                               (m_rect.get_right() > p_rect.get_left()) &&
                               (m_rect.get_left() < p_rect.get_right());

        if (is_mario_on_top) {
            mario->move_horizontal_offset(hspeed);
        }
    }
}

void MovingPlatform::move_map_left() noexcept {
    RectMapMovableAdapter::move_map_left();
    start_x -= biv::MapMovable::MAP_STEP;
}

void MovingPlatform::move_map_right() noexcept {
    RectMapMovableAdapter::move_map_right();
    start_x += biv::MapMovable::MAP_STEP;
}