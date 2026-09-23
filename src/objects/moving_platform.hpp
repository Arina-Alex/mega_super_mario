#pragma once

#include "collisionable.hpp"
#include "movable.hpp"
#include "rect.hpp"
#include "rect_map_movable_adapter.hpp"
#include "speed.hpp"
#include "mario.hpp"

namespace biv {
    class MovingPlatform : public RectMapMovableAdapter, public Movable, public Collisionable {
        private:
            float start_x;       
            float max_distance;  
            Mario* mario = nullptr; 

        public:
            MovingPlatform(const Coord& top_left, const int width, const int height, float speed, float max_distance);

            Rect get_rect() const noexcept override;
            Speed get_speed() const noexcept override;

            void process_horizontal_static_collision(Rect*) noexcept override;
            void process_mario_collision(Collisionable*) noexcept override;
            void process_vertical_static_collision(Rect*) noexcept override;
        
            void move_horizontally() noexcept override;
            void move_vertically() noexcept override;
            
            void set_mario(Mario* m) noexcept;

            void move_map_left() noexcept override;
            void move_map_right() noexcept override;
    };
}