/*
 * ice_send.c
 *
 *  Created on: Dec 21, 2019
 *      Author: ADMIN
 */
#include "wrapper.h"
#include "ice_send.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

Publisher* myPublisher;

void ice_init_send()
{
    struct PoshRuntime* v = 0;
    // Create the runtime for registering with the RouDi daemon
    PoshRuntime_getInstance(v);
    printf("Created a transmitter to send data to RouDi daemon\n");
    
    // Create a publisher
    myPublisher = newPublisher();
    
    // With offer() the publisher gets visible to potential subscribers
    Publisher_offer(myPublisher);
    printf("Receivers can see transmitter now\n");
}

void ice_send(YoloData data)
 {
    
    // Allocate a memory chunk for the sample to be sent
    YoloData* sample = (YoloData*)Publisher_allocateChunk(myPublisher, data);
    
    sample->tsend = data.tsend;
    strcpy(sample->name, data.name);
    sample->prob = data.prob;
    
    // Send the sample
    printf("At time %.6f sending: %s: %f\n", data.tsend, sample->name, sample->prob);
    Publisher_sendChunk(myPublisher, sample);
    //sleep(1);
}

void ice_end_send()
{
    // With stopOffer we disconnect all subscribers and the publisher is no more visible
    Publisher_stopOffer(myPublisher);
    printf("Disconnect to all receivers\n");
}