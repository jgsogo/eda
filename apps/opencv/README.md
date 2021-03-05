Camera demo: face recognition
=============================

OpenCV provides a really powerful library and easy to use set of features
related to image processing. In this example we'll take a look at how
to do **face recognition** with less than one hundred lines of code.

In this example we are using `opencv/3.4.5` and CMake to create the
project we are going to build:


#### **`CMakeLists.txt`**
```cmake
cmake_minimum_required(VERSION 3.1)

project(CameraApp CXX)
find_package(opencv)

add_executable(camera main.cpp)
target_link_libraries(camera opencv::opencv)
set_target_properties(camera PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

```

The main file is quite straighforward too:

#### **`main.cpp`**
```cpp
#include <opencv2/opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;

/** Global variables */
string window_name = "BCN C++ Meetup";
String face_cascade_name = "haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;

/** Function Headers */
void detectAndDisplay(Mat frame);

int main(int argc, char* argv[]) {
      //-- 1. Load the cascades
    if(!face_cascade.load(face_cascade_name)) { printf("--(!)Error loading\n"); return -1; };

    //Open the default video camera
    VideoCapture cap(1);

    // if not success, exit program
    if (cap.isOpened() == false)  {
        cout << "Cannot open the video camera" << endl;
        cin.get(); //wait for any key press
        return -1;
    } 

    namedWindow(window_name); //create a window called "My Camera Feed"
    moveWindow(window_name, 20,20);
    while (true){
        Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video 

        //Breaking the while loop if the frames cannot be captured
        if (bSuccess == false)  {
            cout << "Video camera is disconnected" << endl;
            cin.get(); //Wait for any key press
            break;
        }

        detectAndDisplay(frame);
        //show the frame in the created window
        imshow(window_name, frame);

        //wait for for 10 ms until any key is pressed.  
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop 
        //If any key is not pressed withing 10 ms, continue the loop 
        if (waitKey(10) == 27) {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

    return 0;
}

void detectAndDisplay(Mat frame) {
    std::vector<Rect> faces;
    Mat frame_gray;

    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

    for(size_t i = 0; i < faces.size(); i++) {
        Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
        ellipse(frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
    }
    //-- Show what you got
    imshow(window_name, frame);
}
```

Compile as usual.

**Note.-** You will need [*haarcascade* face file](https://raw.githubusercontent.com/anaustinbeing/haar-cascade-files/master/haarcascade_frontalface_alt.xml) in the folder with the
executable in order to work.

---

```
mkdir build && cd build
conan install .. --build missing
cmake .. -DCMAKE_MODULE_PATH=$(pwd)
cmake --build .
conan imports .. -if=.

cd bin
./camera
```
