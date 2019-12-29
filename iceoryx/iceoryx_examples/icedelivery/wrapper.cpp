/*
 * wrapper.cpp
 *
 *  Created on: Dec 21, 2019
 *      Author: ADMIN
 */

#include "iceoryx_posh/popo/publisher.hpp"
#include "iceoryx_posh/runtime/posh_runtime.hpp"
#include "wrapper.h"

extern "C" {    
    void PoshRuntime_getInstance(PoshRuntime* v) {
        return (void) v->getInstance("/publisher-bare-metal");
    }

    iox::popo::Publisher* newPublisher() {
        return new Publisher({"Radar", "FrontLeft", "Counter"});
    }
    void Publisher_offer(Publisher* v) {
        return v->offer();
    }
    void* Publisher_allocateChunk(Publisher* v, YoloData payloadSize) {
        return v->allocateChunk(sizeof(payloadSize));
    }
    void Publisher_sendChunk(Publisher* v, YoloData* payload) {
        return v->sendChunk(payload);
    }
    void Publisher_stopOffer(Publisher* v) {
        return v->stopOffer();
    }
}
