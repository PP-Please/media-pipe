#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*
To compile, enter the build directory and run make. 
*/
int main() {
    cerr << "Attempting to open webcam." << endl;
    
    // Used the V4L2 Linux driver for my webcam to detect. 
    VideoCapture cap(0, cv::CAP_V4L2);

    /*
    OpenCV defaults to a resolution of 640x480, but for me increasing resolution
    to 1080p makes the fps go to like 3-5 instead of 30
    */ 
    
    // cap.set(CAP_PROP_FRAME_WIDTH, 1920); 
    // cap.set(CAP_PROP_FRAME_HEIGHT, 1080);
    // cap.set(CAP_PROP_FPS, 30);
    // cap.set(CAP_PROP_AUTO_EXPOSURE, 0.01);

    /*
    Default camera output format is YUYV, which requires more bandwidth. Changing it to 
    MJPG can increase performance and in my case, gets it to actually work
    */
    cap.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M', 'J', 'P', 'G'));

    if (!cap.isOpened()) {
        cerr << "Error: Failed to open webcam." << endl;
        return -1;
    }

    cerr << "Webcam opened successfully!" << endl;

    Mat img, imgCanny;

    while (true) {
        cap.read(img);

        // Using the Canny edge detection algorithm. 
        Canny(img, imgCanny, 50, 150);
        imshow("Image", imgCanny);
        waitKey(1);
    }

    cap.release();

    return 0;
}


// g++ -o main main.cpp `pkg-config --cflags --libs opencv4`
// sudo chmod 666 /dev/video0
