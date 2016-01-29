#include "panelboard.h"

PanelBoard::PanelBoard(const HardwareController *pCtrl)
{
    LayoutNode* dummyOuter = new LayoutNode();

    LayoutNode* outerRight = new LayoutNode();
    LayoutNode* outerLeft = new LayoutNode();
    LayoutNode* outerCenter = new LayoutNode();

    LayoutNode* outerToInnerLeft = new LayoutNode();
    LayoutNode* outerToInnerRight = new LayoutNode();

    LayoutNode* dummyInner = new LayoutNode();

    LayoutNode* innerBetweenPoints = new LayoutNode();
    LayoutNode* innerRight = new LayoutNode();
    LayoutNode* innerLeft = new LayoutNode();
    LayoutNode* innerCenter = new LayoutNode();

    LayoutNode* innerToStation = new LayoutNode();

    LayoutNode* dummyStationOuter = new LayoutNode();
    LayoutNode* stationOuterBetweenPoints = new LayoutNode();
    LayoutNode* stationOuterRight = new LayoutNode();
    LayoutNode* stationOuterLeft = new LayoutNode();
    LayoutNode* stationOuterCenter = new LayoutNode();

    LayoutNode* stationSidingRight1 = new LayoutNode();
    LayoutNode* dummyRightBetweenSidings = new LayoutNode();
    LayoutNode* stationSidingRight2 = new LayoutNode();
    LayoutNode* stationSidingRight3 = new LayoutNode();

    LayoutNode* stationOuterToInnerLeft = new LayoutNode();
    LayoutNode* stationOuterToInnerRight = new LayoutNode();

    LayoutNode* dummyStationInner = new LayoutNode();
    LayoutNode* stationInnerRight = new LayoutNode();
    LayoutNode* stationInnerCenter = new LayoutNode();

    LayoutNode* dummyLeftBetweenPoints = new LayoutNode();
    LayoutNode* stationSidingLeft1 = new LayoutNode();
    LayoutNode* dummyLeftBetweenSidings = new LayoutNode();
    LayoutNode* stationSidingLeft2 = new LayoutNode();
    LayoutNode* stationSidingLeft3 = new LayoutNode();


    dummyOuter->setNext(pCtrl->getPoint("outerSwitchRight"), outerRight, 0);

    outerRight->setPrev(pCtrl->getPoint("outerSwitchRight"), dummyOuter, outerToInnerRight);
    outerRight->setNext(outerLeft);

    outerLeft->setPrev(outerRight);
    outerLeft->setNext(pCtrl->getPoint("outerSwitchLeft"), outerToInnerLeft, outerCenter);

    outerCenter->setPrev(pCtrl->getPoint("outerSwitchLeft"), 0, outerLeft);

    outerToInnerLeft->setPrev(pCtrl->getPoint("outerSwitchLeft"), outerLeft, 0);
    outerToInnerLeft->setNext(pCtrl->getPoint("innerSwitchLeft"), innerCenter, 0);

    outerToInnerRight->setPrev(pCtrl->getPoint("outerSwitchRight"), 0, outerRight);
    outerToInnerRight->setNext(pCtrl->getPoint("innerSwitchRight"), 0, innerBetweenPoints);

    //////

    dummyInner->setNext(pCtrl->getPoint("innerStationSwitch"), innerBetweenPoints, 0);

    innerBetweenPoints->setPrev(pCtrl->getPoint("innerStationSwitch"), dummyInner, innerToStation);
    innerBetweenPoints->setNext(pCtrl->getPoint("innerSwitchRight"), innerRight, outerToInnerRight);

    innerRight->setPrev(pCtrl->getPoint("innerSwitchRight"), innerBetweenPoints, 0);
    innerRight->setNext(innerLeft);

    innerLeft->setPrev(innerRight);
    innerLeft->setNext(pCtrl->getPoint("innerSwitchLeft"), 0, innerCenter);

    innerCenter->setPrev(pCtrl->getPoint("innerSwitchLeft"), outerToInnerLeft, innerLeft);

    innerToStation->setPrev(pCtrl->getPoint("innerStationSwitch"), 0, innerBetweenPoints);
    innerToStation->setNext(pCtrl->getPoint("stationOuterEntrance"), 0, stationOuterBetweenPoints);

    ///////
    dummyStationOuter->setNext(pCtrl->getPoint("stationOuterLoopSwitchRight"), stationOuterBetweenPoints, 0);

    stationOuterBetweenPoints->setPrev(pCtrl->getPoint("stationOuterLoopSwitchRight"), dummyStationOuter, stationOuterToInnerRight);
    stationOuterBetweenPoints->setNext(pCtrl->getPoint("stationOuterEntrance"), stationOuterRight, innerToStation);

    stationOuterRight->setPrev(pCtrl->getPoint("stationOuterEntrance"), stationOuterBetweenPoints, 0);
    stationOuterRight->setNext(pCtrl->getPoint("stationOuterRightSiding1"), dummyRightBetweenSidings, stationSidingRight1);

    dummyRightBetweenSidings->setPrev(pCtrl->getPoint("stationOuterRightSiding1"), stationOuterRight, 0);
    dummyRightBetweenSidings->setNext(pCtrl->getPoint("rightSidingSwitch2"), stationSidingRight3, stationSidingRight2);

    stationSidingRight1->setPrev(pCtrl->getPoint("stationOuterRightSiding1"), 0, stationOuterRight);
    stationSidingRight2->setPrev(pCtrl->getPoint("rightSidingSwitch2"), 0, dummyRightBetweenSidings);
    stationSidingRight3->setPrev(pCtrl->getPoint("rightSidingSwitch2"), dummyRightBetweenSidings, 0);

    stationOuterLeft->setNext(pCtrl->getPoint("stationOuterLoopSwitchLeft"), stationOuterToInnerLeft, stationOuterCenter);

    stationOuterLeft->setPrev(pCtrl->getPoint("stationOuterLoopSwitchLeft"), 0, stationOuterLeft);

    stationOuterToInnerLeft->setPrev(pCtrl->getPoint("stationOuterLoopSwitchLeft"), stationOuterLeft, 0);
    stationOuterToInnerLeft->setNext(pCtrl->getPoint("stationInnerLoopSwitchLeft"), stationInnerCenter, 0);

    stationOuterToInnerRight->setPrev(pCtrl->getPoint("stationOuterLoopSwitchRight"), 0, stationOuterBetweenPoints);
    stationOuterToInnerRight->setNext(pCtrl->getPoint("stationInnerLoopSwitchRight"), 0, dummyStationInner);

    //////

    dummyStationInner->setNext(pCtrl->getPoint("stationInnerLoopSwitchRight"), stationInnerRight, stationOuterToInnerRight);

    stationInnerRight->setPrev(pCtrl->getPoint("stationInnerLoopSwitchRight"), dummyStationInner, 0);

    stationInnerCenter->setPrev(pCtrl->getPoint("stationInnerLoopSwitchLeft"), stationOuterToInnerLeft, dummyLeftBetweenPoints);

    dummyLeftBetweenPoints->setPrev(pCtrl->getPoint("leftSidingSwitch"), stationSidingLeft1, dummyLeftBetweenSidings);
    dummyLeftBetweenPoints->setNext(pCtrl->getPoint("stationInnerLoopSwitchLeft"), 0, stationInnerCenter);

    dummyLeftBetweenSidings->setPrev(pCtrl->getPoint("outerSwitchLeft"), stationSidingLeft2, stationSidingLeft3);
    dummyLeftBetweenSidings->setNext(pCtrl->getPoint("leftSidingSwitch"), 0, dummyLeftBetweenPoints);

    stationSidingLeft1->setNext(pCtrl->getPoint("leftSidingSwitch"), dummyLeftBetweenPoints, 0);
    stationSidingLeft2->setNext(pCtrl->getPoint("outerSwitchLeft"), dummyLeftBetweenPoints, 0);
    stationSidingLeft3->setNext(pCtrl->getPoint("outerSwitchLeft"), 0, dummyLeftBetweenPoints);

    //LayoutNode* pOuterController = new LayoutCon;
    //m_ControlNodes.insert()
}

void PanelBoard::refresh()
{

}

int PanelBoard::getLightState(const QByteArray &lightName) const
{

}
