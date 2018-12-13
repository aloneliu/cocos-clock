//
//  SceneManager.h
//  coco_clock-mobile
//
//  Created by Jin Liu on 2018/12/10.
//

#ifndef SceneManager_h
#define SceneManager_h

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class SceneManager{
public:
    Scene * loadScene;
    Scene * openScene;
    Scene * clockScene;
    
    void createLoadScene();
    void goOpenScene();
    void goClockScene();
};

#endif /* SceneManager_h */
