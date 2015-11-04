//
// Created by andrey on 04.11.15.
//

#include <glog/logging.h>
#include <iomanip>
#include "MyApp.hh"
#include "Controller.hh"

REGISTER_APPLICATION(MyApp, {"controller", ""})

void MyApp::init(Loader *loader, const Config& config)
{
    Controller* ctrl = Controller::get(loader);
    ctrl = ctrl;
    LOG(INFO) << "Hello, world!";
    QObject::connect(ctrl, &Controller::switchUp, this, &MyApp::onSwitchUp);
}

void MyApp::onSwitchUp(OFConnection *ofconn, of13::FeaturesReply fr) {
    LOG(INFO) << "Look! This is a switch " << FORMAT_DPID << fr.auxiliary_id();
}