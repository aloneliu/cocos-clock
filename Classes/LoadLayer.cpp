//
//  LoadLayer.cpp
//  coco_clock-mobile
//
//  Created by Jin Liu on 2018/12/10.
//

#include "LoadLayer.h"
bool LoadLayer::init(){
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Label * label = Label::createWithTTF("loading...", "fonts/Marker Felt.ttf", 32);
    label->setPosition(visibleSize.width/2, visibleSize.height/2);
    
    this->addChild(label);
    
    scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce), 2.0);
    
    return true;
}

void LoadLayer::onScheduleOnce(float dt){
    tsm->goOpenScene();
};
