#pragma once
#include "ui_factory.hpp"
#include "qt_game_map.hpp"
#include "qt_objects.hpp"

namespace biv {
    class QtUIFactory : public UIFactory {
    private:
        QtGameMap* game_map = nullptr;
        QtKeyboard* keyboard = nullptr;

        std::vector<QtBox*> boxes;
        std::vector<QtFullBox*> full_boxes;
        std::vector<QtShip*> ships;
        QtMario* mario = nullptr;
        std::vector<QtEnemy*> enemies;
        std::vector<QtFlyingEnemy*> flying_enemies;
        std::vector<QtJumpingEnemy*> jumping_enemies;
        std::vector<QtMoney*> moneys;
        std::vector<QtMushroom*> mushrooms;
        std::vector<QtMushroomBox*> mushroom_boxes;
        std::vector<QtMovingPlatform*> moving_platforms;

    public:
        QtUIFactory(Game* game, QtKeyboard* kb) : UIFactory(game), keyboard(kb) {}

        void clear_data() override {
            game->remove_objs();
            if (game_map) game_map->remove_objs();
            delete mario;
            mario = nullptr;
            boxes.clear();
            full_boxes.clear();
            ships.clear();
            enemies.clear();
            flying_enemies.clear();
            jumping_enemies.clear();
            moneys.clear();
            mushrooms.clear();
            mushroom_boxes.clear();
            moving_platforms.clear();
        }

        void create_box(const Coord& top_left, const int width, const int height) override {
            auto* box = new QtBox(top_left, width, height);
            boxes.push_back(box);
            game->add_map_movable(box);
            game->add_static_obj(box);
            if (game_map) game_map->add_obj(box);
        }

        void create_enemy(const Coord& top_left, const int width, const int height, float speed) override {
            auto* enemy = new QtEnemy(top_left, width, height, speed);
            enemies.push_back(enemy);
            game->add_map_movable(enemy);
            game->add_movable(enemy);
            game->add_collisionable(enemy);
            if (game_map) game_map->add_obj(enemy);
        }

        void create_flying_enemy(const Coord& top_left, const int width, const int height, float speed, float max_dist) override {
            auto* f_enemy = new QtFlyingEnemy(top_left, width, height, speed, max_dist);
            flying_enemies.push_back(f_enemy);
            game->add_map_movable(f_enemy);
            game->add_movable(f_enemy);
            game->add_collisionable(f_enemy);
            if (game_map) game_map->add_obj(f_enemy);
        }

        void create_jumping_enemy(const Coord& top_left, const int width, const int height) override {
            auto* j_enemy = new QtJumpingEnemy(top_left, width, height);
            jumping_enemies.push_back(j_enemy);
            game->add_map_movable(j_enemy);
            game->add_movable(j_enemy);
            game->add_collisionable(j_enemy);
            if (game_map) game_map->add_obj(j_enemy);
        }

        void create_full_box(const Coord& top_left, const int width, const int height) override {
            auto* full_box = new QtFullBox(top_left, width, height, this);
            full_boxes.push_back(full_box);
            game->add_collisionable(full_box);
            game->add_map_movable(full_box);
            game->add_static_obj(full_box);
            if (game_map) game_map->add_obj(full_box);
        }

        void create_mario(const Coord& top_left, const int width, const int height) override {
            if (mario) {
                game->remove_collisionable(mario);
                game->remove_movable(mario);
                game->remove_mario();
                if (game_map) game_map->remove_obj(mario);
                delete mario;
            }
            mario = new QtMario(top_left, width, height);
            game->add_collisionable(mario);
            game->add_movable(mario);
            game->add_mario(mario);
            if (game_map) game_map->add_obj(mario);
        }

        void create_money(const Coord& top_left, const int width, const int height) override {
            auto* money = new QtMoney(top_left, width, height);
            moneys.push_back(money);
            game->add_map_movable(money);
            game->add_movable(money);
            game->add_collisionable(money);
            if (game_map) game_map->add_obj(money);
        }

        void create_mushroom(const Coord& top_left, const int width, const int height) override {
            auto* mushroom = new QtMushroom(top_left, width, height);
            mushrooms.push_back(mushroom);
            game->add_map_movable(mushroom);
            game->add_movable(mushroom);
            game->add_collisionable(mushroom);
            if (game_map) game_map->add_obj(mushroom);
        }

        void create_mushroom_box(const Coord& top_left, const int width, const int height) override {
            auto* m_box = new QtMushroomBox(top_left, width, height, this);
            mushroom_boxes.push_back(m_box);
            game->add_collisionable(m_box);
            game->add_map_movable(m_box);
            game->add_static_obj(m_box);
            if (game_map) game_map->add_obj(m_box);
        }

        void create_moving_platform(const Coord& top_left, const int width, const int height, float speed, float max_dist) override {
            auto* platform = new QtMovingPlatform(top_left, width, height, speed, max_dist);
            platform->set_mario(mario);
            moving_platforms.push_back(platform);
            game->add_map_movable(platform);
            game->add_movable(platform);
            game->add_static_obj(platform);
            if (game_map) game_map->add_obj(platform);
        }

        void create_ship(const Coord& top_left, const int width, const int height) override {
            auto* ship = new QtShip(top_left, width, height);
            ships.push_back(ship);
            game->add_map_movable(ship);
            game->add_static_obj(ship);
            if (game_map) game_map->add_obj(ship);
        }

        GameMap* get_game_map(const int height, const int width) override {
            if (game_map == nullptr) {
                game_map = new QtGameMap(height, width, keyboard);
            }
            return game_map;
        }

        Mario* get_mario() override {
            return mario;
        }
    };
}