//
//  OpenLayer.h
//  coco_clock-mobile
//
//  Created by Jin Liu on 2018/12/10.
//

#ifndef OpenLayer_h
#define OpenLayer_h

#include <stdio.h>
#include "cocos2d.h"
#include "SceneManager.h"
USING_NS_CC;
class OpenLayer:public Layer{
public:
    CREATE_FUNC(OpenLayer);
    virtual bool init();
    void ccMenuCallback(Ref * pSender);
public:
    SceneManager * tsm;
};

#endif /* OpenLayer_h */
