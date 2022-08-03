#include "FirstLevel.hpp"

#include "Game/Scripts/Player.hpp"
#include "Game/Scripts/Ground.hpp"
#include "Game/Scripts/Enemy.hpp"
#include "Game/Scripts/Money.hpp"
#include "Game/Scripts/Door.hpp"   
#include "Game/Scripts/Spring.hpp"   
#include "Game/Scripts/Tree.hpp"   

FirstLevel::~FirstLevel() {
    delete shader;
}

void FirstLevel::start(World* world, Camera* camera) {
    shader = new Shader("../resources/shaders/vst.glsl", "../resources/shaders/fst.glsl");
    camera->setShader(shader);


    auto player = new Player(shader, camera);
    player->setSize(0.5f,0.5f);
    player->setPosition(3.f, 0.f, 0.f);
    player->time = 30.f;
    world->addActor(player);

    auto tree = new Tree(shader);
    tree->setSize(0.5f,1.f);
    tree->setPosition(3.f, -1.5f, 0.f);
    world->addActor(tree);

    auto enemy_1 = new Enemy(shader, player);
    enemy_1->setSize(0.5f, 0.5f);
    enemy_1->setPosition(11.f, 0.f, 0.f);
    world->addActor(enemy_1);

    auto enemy_2 = new Enemy(shader, player);
    enemy_2->setSize(0.5f, 0.5f);
    enemy_2->setPosition(-3.f, 5.f, 0.f);
    world->addActor(enemy_2);
    
    auto enemy_3 = new Enemy(shader, player);
    enemy_3->setSize(0.5f, 0.5f);
    enemy_3->setPosition(-7.8f, 3.f, 0.f);
    world->addActor(enemy_3);

    auto place1 = new Ground(shader);
    place1->setPosition(-5.f, -7.5f, 0.f);
    place1->setSize(10.f, 6.f);
    world->addActor(place1);
    
    auto place2 = new Ground(shader);
    place2->setPosition(5.f, -7.5f, 0.f);
    place2->setSize(10.f, 6.f);
    world->addActor(place2);

    auto place3 = new Ground(shader);
    place3->setPosition(-20.f, -8.5f, 0.f);
    place3->setSize(10.f, 6.f);
    world->addActor(place3);

    auto place4 = new Ground(shader);
    place4->setPosition(-15.f, -7.5f, 0.f);
    place4->setSize(10.f, 6.f);
    world->addActor(place4);
    
    auto place5 = new Ground(shader);
    place5->setPosition(-32.f, -5.f, 0.f);
    place5->setSize(12.f, 8.f);
    world->addActor(place5);
    
    auto ground1 = new Ground(shader);
    ground1->setPosition(1.9f, -1.4f, 0.f);
    ground1->setSize(1.f, 1.f);
    world->addActor(ground1);
    
    auto ground2 = new Ground(shader);
    ground2->setPosition(3.7f, 0.2f, 0.f);
    ground2->setSize(1.f, 1.f);
    world->addActor(ground2);
    
    auto ground3 = new Ground(shader);
    ground3->setPosition(1.5f, 1.8f, 0.f);
    ground3->setSize(1.f, 1.f);
    world->addActor(ground3);
   
    auto ground4 = new Ground(shader);
    ground4->setPosition(-6.f, 4.f, 0.f);
    ground4->setSize(6.f, 0.2f);
    world->addActor(ground4);
    
    auto ground5 = new Ground(shader);
    ground5->setPosition(-8.f, 2.f, 0.f);
    ground5->setSize(1.f, 1.f);
    world->addActor(ground5);

    auto ground6 = new Ground(shader);
    ground6->setPosition(-15.f, 1.5f, 0.f);
    ground6->setSize(5.f, 0.2f);
    world->addActor(ground6);

    auto money_1 = new Money(shader, player);
    money_1->setSize(0.5f, 0.5f);
    money_1->setPosition(5.f, -1.3f, 0.f);
    world->addActor(money_1);
    
    auto money_2 = new Money(shader, player);
    money_2->setSize(0.5f, 0.5f);
    money_2->setPosition(-4.f, 4.4f, 0.f);
    world->addActor(money_2);
   
    auto money_3 = new Money(shader, player);
    money_3->setSize(0.5f, 0.5f);
    money_3->setPosition(-12.f, 2.2f, 0.f);
    world->addActor(money_3);
    
    auto money_4 = new Money(shader, player);
    money_4->setSize(0.5f, 0.5f);
    money_4->setPosition(-18.f, -2.2f, 0.f);
    world->addActor(money_4);
    
    auto door = new Door(shader, player);
    door->setSize(0.5f, 1.f);
    door->setPosition(13.5f, -1.5f, 0.f);
    world->addActor(door);
}
