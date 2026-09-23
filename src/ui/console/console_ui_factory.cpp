#include "console_ui_factory.hpp"

using biv::ConsoleUIFactory;

ConsoleUIFactory::ConsoleUIFactory(Game* game) : UIFactory(game) {}

void ConsoleUIFactory::clear_data() {
	game->remove_objs();
	game_map->remove_objs();
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

void ConsoleUIFactory::create_box(
	const Coord& top_left, const int width, const int height
) {
	ConsoleBox* box = new ConsoleBox(top_left, width, height);
	boxes.push_back(box);
	game->add_map_movable(box);
	game->add_static_obj(box);
	game_map->add_obj(box);
}

void ConsoleUIFactory::create_enemy(
	const Coord& top_left, const int width, const int height, float speed
) {
	ConsoleEnemy* enemy = new ConsoleEnemy(top_left, width, height, speed);
	enemies.push_back(enemy);
	game->add_map_movable(enemy);
	game->add_movable(enemy);
	game->add_collisionable(enemy);
	game_map->add_obj(enemy);
}

void ConsoleUIFactory::create_flying_enemy(
	const Coord& top_left, const int width, const int height, float speed, float max_dist
) {
	ConsoleFlyingEnemy* f_enemy = new ConsoleFlyingEnemy(top_left, width, height, speed, max_dist);
	flying_enemies.push_back(f_enemy);
	game->add_map_movable(f_enemy);
	game->add_movable(f_enemy);
	game->add_collisionable(f_enemy);
	game_map->add_obj(f_enemy);
}

void ConsoleUIFactory::create_jumping_enemy(
	const Coord& top_left, const int width, const int height
) {
	ConsoleJumpingEnemy* j_enemy = new ConsoleJumpingEnemy(top_left, width, height);
	jumping_enemies.push_back(j_enemy);
	game->add_map_movable(j_enemy);
	game->add_movable(j_enemy);
	game->add_collisionable(j_enemy);
	game_map->add_obj(j_enemy);
}

void ConsoleUIFactory::create_full_box(
	const Coord& top_left, const int width, const int height
) {
	ConsoleFullBox* full_box = new ConsoleFullBox(top_left, width, height, this);
	full_boxes.push_back(full_box);
	game->add_collisionable(full_box);
	game->add_map_movable(full_box);
	game->add_static_obj(full_box);
	game_map->add_obj(full_box);
}

void ConsoleUIFactory::create_mario(
	const Coord& top_left, const int width, const int height
) {
	game->remove_collisionable(mario);
	game->remove_movable(mario);
	game->remove_mario();
	game_map->remove_obj(mario);
	delete mario;
	mario = nullptr;
	
	mario = new ConsoleMario(top_left, width, height);
	game->add_collisionable(mario);
	game->add_movable(mario);
	game->add_mario(mario);
	game_map->add_obj(mario);
}

void ConsoleUIFactory::create_money(
	const Coord& top_left, const int width, const int height
) {
	ConsoleMoney* money = new ConsoleMoney(top_left, width, height);
	moneys.push_back(money);
	game->add_map_movable(money);
	game->add_movable(money);
	game->add_collisionable(money);
	game_map->add_obj(money);
}

void ConsoleUIFactory::create_mushroom(
	const Coord& top_left, const int width, const int height
) {
	ConsoleMushroom* mushroom = new ConsoleMushroom(top_left, width, height);
	mushrooms.push_back(mushroom);
	game->add_map_movable(mushroom);
	game->add_movable(mushroom);
	game->add_collisionable(mushroom);
	game_map->add_obj(mushroom);
}

void ConsoleUIFactory::create_mushroom_box(
	const Coord& top_left, const int width, const int height
) {
	ConsoleMushroomBox* mushroom_box = new ConsoleMushroomBox(top_left, width, height, this);
	mushroom_boxes.push_back(mushroom_box);
	game->add_collisionable(mushroom_box);
	game->add_map_movable(mushroom_box);
	game->add_static_obj(mushroom_box);
	game_map->add_obj(mushroom_box);
}

void ConsoleUIFactory::create_moving_platform(
    const Coord& top_left, const int width, const int height, float speed, float max_dist
) {
    ConsoleMovingPlatform* platform = new ConsoleMovingPlatform(top_left, width, height, speed, max_dist);
    platform->set_mario(mario); 
    
    moving_platforms.push_back(platform);
    
    game->add_map_movable(platform);
    game->add_movable(platform);
    game->add_static_obj(platform); 
    game_map->add_obj(platform);
}

void ConsoleUIFactory::create_ship(
	const Coord& top_left, const int width, const int height
) {
	ConsoleShip* ship = new ConsoleShip(top_left, width, height);
	ships.push_back(ship);
	game->add_map_movable(ship);
	game->add_static_obj(ship);
	game_map->add_obj(ship);
}

biv::GameMap* ConsoleUIFactory::get_game_map(const int height, const int width) {
	if (game_map == nullptr) {
		game_map = new ConsoleGameMap(height, width);
	}
	return game_map;
}

biv::Mario* ConsoleUIFactory::get_mario() {
	return mario;
}
