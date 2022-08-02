#include "SecondLevel.hpp"

#include "Game/Scripts/Player.hpp"
#include "Game/Scripts/Ground.hpp"
#include "Game/Scripts/Enemy.hpp"
#include "Game/Scripts/Money.hpp"
#include "Game/Scripts/Door.hpp"   

SecondLevel::~SecondLevel() {
    delete shader;
}

void SecondLevel::start(World* world, Camera* camera) {
    shader = new Shader("../resources/shaders/vst.glsl", "../resources/shaders/fst.glsl");
    camera->setShader(shader);

    auto player = new Player(shader, camera);
    player->setSize(0.5f,0.5f);
    player->setPosition(-1.f, 0.f, 0.f);
    player->time = 30.f;
    world->addActor(player);

    auto place1 = new Ground(shader);
    place1->setPosition(-5.f, -7.5f, 0.f);
    place1->setSize(10.f, 6.f);
    world->addActor(place1);
   
    auto ground1 = new Ground(shader);
    ground1->setPosition(0.5f, -1.4f, 0.f);
    ground1->setSize(1.f, 1.f);
    world->addActor(ground1);
 
    auto money_1 = new Money(shader, player);
    money_1->setSize(0.5f, 0.5f);
    money_1->setPosition(2.f, -1.3f, 0.f);
    world->addActor(money_1);

    auto door = new Door(shader, player);
    door->setSize(0.5f, 1.f);
    door->setPosition(4.5f, -1.5f, 0.f);
    world->addActor(door);
}
