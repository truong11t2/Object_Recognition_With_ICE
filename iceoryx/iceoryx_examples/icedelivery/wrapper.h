/*
 * wrapper.h
 *
 *  Created on: Dec 21, 2019
 *      Author: ADMIN
 */



#ifndef _WRAPPER_H_
#define _WRAPPER_H_

//Common Data structure between ice and yolo
typedef struct YoloData
{
    char name[30];
    float prob;
} YoloData;

#ifdef __cplusplus      //For g++ compilation
extern "C" {
typedef struct iox::runtime::PoshRuntime PoshRuntime;
void PoshRuntime_getInstance(PoshRuntime* v);

typedef struct iox::popo::Publisher Publisher;
Publisher* newPublisher();
void Publisher_offer(Publisher* v);
void* Publisher_allocateChunk(Publisher* v, YoloData payloadSize);
void Publisher_sendChunk(Publisher* v, YoloData* payload);
void Publisher_stopOffer(Publisher* v);
}

#else                       //For gcc compilation
typedef struct PoshRuntime PoshRuntime;
void PoshRuntime_getInstance(PoshRuntime* v);

typedef struct Publisher Publisher;
Publisher* newPublisher();
void Publisher_offer(Publisher* v);
void* Publisher_allocateChunk(Publisher* v, YoloData payloadSize);
void Publisher_sendChunk(Publisher* v, YoloData* payload);
void Publisher_stopOffer(Publisher* v);
#endif /* __cplusplus */

#endif /* _WRAPPER_H_ */
