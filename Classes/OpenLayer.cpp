//
//  OpenLayer.cpp
//  coco_clock-mobile
//
//  Created by Jin Liu on 2018/12/10.
//

#include "OpenLayer.h"
bool OpenLayer::init(){
    Size winSize = Director::getInstance()->getWinSize();
    
    Label * label = Label::createWithSystemFont("时钟程序", "", 48);
    label->setPosition(Vec2(winSize.width/2, winSize.height*3/4));
    this->addChild(label);
    
    // item 按钮的回调函数
    MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithSystemFont("开始", "", 32), CC_CALLBACK_1(OpenLayer::ccMenuCallback, this));
    menuItem->setTag(101);
    label->setColor(Color3B(255, 0 , 0));
    menuItem->setPosition(Vec2(winSize.width/2, winSize.height*0.5));
    
    MenuItemLabel * menuItem_2 = MenuItemLabel::create(Label::createWithSystemFont("退出", "", 32), CC_CALLBACK_1(OpenLayer::ccMenuCallback, this));
    menuItem_2->setTag(102);
    menuItem_2->setPosition(Vec2(winSize.width/2, winSize.height*0.25));
    
    auto menu = Menu::create(menuItem, menuItem_2, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    return true;
}

void OpenLayer::ccMenuCallback(Ref * pSender){
    switch (((MenuItem *)pSender)->getTag()) {
        case 101:
        {
            // 调用
            tsm->goClockScene();
        }
            
            break;
        case 102:
        {
            // 退出
            Director::getInstance()->end();
            exit(0);
        }
            break;
        default:
            break;
    }
    
    
}
