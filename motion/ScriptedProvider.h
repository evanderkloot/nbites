#ifndef _ScriptedProvider_h_DEFINED
#define _ScriptedProvider_h_DEFINED

#include <vector>
#include "MotionProvider.h"
#include "ChainQueue.h"
#include "Sensors.h"
#include "ChopShop.h"
using namespace std;

class ScriptedProvider : public MotionProvider {
public:
    ScriptedProvider(float motionFrameLength,
					 Sensors *s);
    virtual ~ScriptedProvider();

    void requestStop();
    void calculateNextJoints();


	void enqueue(const BodyJointCommand *command);
	void enqueueSequence(std::vector<BodyJointCommand*> &seq);

private:
	float FRAME_LENGTH_S;
	ChopShop chopper;
	vector<vector<float> > nextJoints;
};

#endif
