//
//  ClockLayer.cpp
//  coco_clock-mobile
//
//  Created by Jin Liu on 2018/12/10.
//

#include "ClockLayer.h"
bool ClockLayer::init(){
    Size winSize = Director::getInstance()->getWinSize();
    MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithSystemFont("返回", "", 30), CC_CALLBACK_1(ClockLayer::menuCallback, this));
    
    menuItem->setPosition(Vec2(winSize.width*0.8, winSize.height*0.8));
    auto menu = Menu::create(menuItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    // 精灵初始化
    _background = Sprite::create("res/background.jpg");
    _background->setPosition(Vec2(winSize.width/2, winSize.height/2));
    _background->setScale(1);
    this->addChild(_background);
    
    _hour = Sprite::create("res/shi.png");
    _hour->setPosition(Vec2(winSize.width/2, winSize.height/2));
    _hour->setScale(0.5);
    _hour->setAnchorPoint(Vec2(0.5, 0)); // 锚点
    this->addChild(_hour, 1);
    
    _minute = Sprite::create("res/fen.png");
    _minute->setPosition(Vec2(winSize.width/2, winSize.height/2));
    _minute->setScale(0.5);
    _minute->setAnchorPoint(Vec2(0.5, 0)); // 锚点
    this->addChild(_minute, 2);
    
    _second = Sprite::create("res/miao.png");
    _second->setPosition(Vec2(winSize.width/2, winSize.height/2));
    _second->setScale(0.5);
    _second->setAnchorPoint(Vec2(0.5, 0)); // 锚点
    this->addChild(_second, 3);
    
    struct timeval nowTimeVal;
    gettimeofday(&nowTimeVal, NULL);
    struct tm * tm;
    time_t time_sec;
    time_sec = nowTimeVal.tv_sec;
    tm = localtime(&time_sec);
    
    mRotation = tm->tm_min * 6;
    sRotation = tm->tm_sec * 6;
    if (tm->tm_hour > 12) {
        hRotation = (tm->tm_hour-12) * 5 * 6 + mRotation/72 * 6;
    }else{
        hRotation = (tm->tm_hour) * 5 * 6 + mRotation/72 * 6;
    }
    
    _hour->setRotation(hRotation);
    _minute->setRotation(mRotation);
    _second->setRotation(sRotation);
    
    schedule(CC_SCHEDULE_SELECTOR(ClockLayer::timeUpdate), 1.0);
    
    return true;
}


void ClockLayer::menuCallback(Ref * pSender){
    tsm->goOpenScene();
}

void ClockLayer::timeUpdate(float dt){
    _second->setRotation(_second->getRotation() + 6);
    
    if (_second->getRotation() == 360) {
        _minute->setRotation(_minute->getRotation() + 6);
        _second->setRotation(0);
        if ((int)_minute->getRotation() % 72 == 0) {
            _hour->setRotation(_hour->getRotation() + 6);
            if (_minute->getRotation() == 360) {
                _minute->setRotation(0);
            }
        }
    }
}
