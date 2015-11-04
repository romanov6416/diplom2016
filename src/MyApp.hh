//
// Created by andrey on 04.11.15.
//

#ifndef RUNOS_MYAPP_HH
#define RUNOS_MYAPP_HH

#include "Application.hh"
#include "Loader.hh"
#include "Common.hh"
#include "OFMessageHandler.hh"
#include "../build/prefix/include/fluid/OFConnection.hh"
#include "../build/prefix/include/fluid/of13msg.hh"

class MyApp : public Application {
SIMPLE_APPLICATION(MyApp, "myapp")
public:
	void init(Loader* loader, const Config& config) override;
	
public slots:
	void onSwitchUp(OFConnection* ofconn, of13::FeaturesReply fr);
};


#endif //RUNOS_MYAPP_HH
