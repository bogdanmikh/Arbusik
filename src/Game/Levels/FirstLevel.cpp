#include "FirstLevel.hpp"

#include "Game/Scripts/Player.hpp"
#include "Game/Scripts/Ground.hpp"
#include "Game/Scripts/Enemy.hpp"
#include "Game/Scripts/Money.hpp"
#include "Game/Scripts/Door.hpp"   

FirstLevel::~FirstLevel() {
    delete shader;
}

void FirstLevel::start(World* world, Camera* camera) {
    shader = new Shader("../resources/shaders/vst.glsl", "../resources/shaders/fst.glsl");
    camera->setShader(shader);

    auto player = new Player(shader, camera);
    player->setSize(0.5f,0.5f);
    player->setPosition(3.f, 0.f, 0.f);
    world->addActor(player);

    auto enemy_1 = new Enemy(shader, player);
    enemy_1->setSize(0.5f,0.5f);
    enemy_1->setPosition(-4.f, 1.f, 0.f);
    world->addActor(enemy_1);

    auto enemy_2 = new Enemy(shader, player);
    enemy_2->setSize(0.5f,0.5f);
    enemy_2->setPosition(-5.f, 1.f, 0.f);
    world->addActor(enemy_2);

    auto place1 = new Ground(shader);
    place1->setPosition(-5.f, -7.5f, 0.f);
    place1->setSize(10.f, 6.f);
    world->addActor(place1);
    
    auto place2 = new Ground(shader);
    place2->setPosition(1.f, -7.5f, 0.f);
    place2->setSize(10.f, 6.f);
    world->addActor(place2);

    auto place3 = new Ground(shader);
    place3->setPosition(-15.f, -7.5f, 0.f);
    place3->setSize(10.f, 6.f);
    world->addActor(place3);
    
    auto ground2 = new Ground(shader);
    ground2->setPosition(-4.f, 0.f, 0.f);
    ground2->setSize(1.f, 1.f);
    world->addActor(ground2);

    auto ground3 = new Ground(shader);
    ground3->setPosition(-2.f, -1.3f, 0.f);
    ground3->setSize(1.f, 1.f);
    world->addActor(ground3);

    auto ground4 = new Ground(shader);
    ground4->setPosition(0.f, 0.5f, 0.f);
    ground4->setSize(1.f, 0.1f);
    world->addActor(ground4);

    auto ground6 = new Ground(shader);
    ground6->setPosition(1.5f, 1.0f, 0.f);
    ground6->setSize(1.f, 1.f);
    world->addActor(ground6);

    auto money_1 = new Money(shader, player);
    money_1->setSize(0.5f, 0.5f);
    money_1->setPosition(5.f, -1.3f, 0.f);
    world->addActor(money_1);
    
    auto door = new Door(shader);
    door->setSize(0.5f, 1.f);
    door->setPosition(6.f, -1.3f, 0.f);
    world->addActor(door);
}