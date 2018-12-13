//
//  ClockLayer.h
//  coco_clock-mobile
//
//  Created by Jin Liu on 2018/12/10.
//

#ifndef ClockLayer_h
#define ClockLayer_h

#include <stdio.h>
#include "cocos2d.h"
#include "SceneManager.h"
USING_NS_CC;
class ClockLayer:public Layer{
public:
    CREATE_FUNC(ClockLayer);
    virtual bool init();
    
    void menuCallback(Ref * pSender);
    void timeUpdate(float dt);
public:
    SceneManager * tsm;
    
    Sprite * _hour;
    Sprite * _minute;
    Sprite * _second;
    Sprite * _background;
    
    // 时分秒的偏转角度
    int hRotation = 0;
    int mRotation = 0;
    int sRotation = 0;
};

#endif /* ClockLayer_h */

