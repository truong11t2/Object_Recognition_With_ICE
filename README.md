The purpose of this is to transfer real time data with zero-delay on embedded systems based on Linux.
It performs an Inter process communication (IPC) between Object Recognition software to another.
This project is based on darknet and iceoryx source code.
More information can be found at: https://pjreddie.com/darknet/ and https://github.com/eclipse/iceoryx
 
~~~~~~~~~~BUILD SOURCE CODE AND SET UP ENVIRONMENT~~~~~~~~~~

1. Get the source code:
git clone https://github.com/truong11t2/Object_Recognition_With_ICE.git

2. Go to folder: iceoryx/tools, run script by command:
$ ./iceoryx_build_test.sh

3. Link library on darknet
Go to folder iceoryx/build/install/prefix/lib, copy the following libraries:
libiceoryx_posh.a, libiceoryx_posh_roudi.a, libiceoryx_utils.a. Then paste in folder: darknet
Go to folder iceoryx/build/iceoryx_examples/icedelivery, copy the following library:
libwrapper.a. Then paste in folder: darknet

4. Make sure OpenCV is installed (if the object detection run on jpg picture only)
OpenCV and Cuda are installed (if the object detection run on video picture or a camera)

5. Go to folder darknet, build darknet source code by command:
$ make

6. For Object Recognition, a set of trained data need to be included in darket by run command:
wget https://pjreddie.com/media/files/yolov3.weights

~~~~~~~~~~RUN PROGRAM~~~~~~~~~~

1. Go to: iceoryx/build/install/prefix/bin, initialize IPC communication with RouDi daemon by command:
$ ./RouDi

2. Go to: iceoryx_examples/icedelivery/icedelivery, run receiver program by command:
$ ./ice-subscriber-bare-metal

3. Go to: darknet, run YoLov3 (an object recognition sw) by command:
With picture example: ./darknet detect cfg/yolov3.cfg yolov3.weights data/dog.jpg
With video: ./darknet detector demo cfg/coco.data cfg/yolov3.cfg yolov3.weights
More details at: https://pjreddie.com/darknet/yolo/

4. Check the data which transfer from darknet to ice-subscriber-bare-metal
