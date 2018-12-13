//
//  LoadLayer.h
//  coco_clock-mobile
//
//  Created by Jin Liu on 2018/12/10.
//

#ifndef LoadLayer_h
#define LoadLayer_h

#include <stdio.h>
#include "cocos2d.h"
#include "SceneManager.h"
USING_NS_CC;

class LoadLayer:public Layer{
public:
    CREATE_FUNC(LoadLayer);
    virtual bool init();
    void onScheduleOnce(float dt);
public:
    SceneManager * tsm;
};
#endif /* LoadLayer_h */
