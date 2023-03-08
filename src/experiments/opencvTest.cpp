#include <iostream>
#include <opencv2/opencv.hpp>
#include <dlib/opencv.h>
#include <dlib/image_processing.h>
#include <dlib/image_processing/frontal_face_detector.h>

using namespace cv;
using namespace dlib;
using namespace std;

int main()
{
    // Initialize face detector and landmark detector
    frontal_face_detector face_detector = get_frontal_face_detector();
    shape_predictor landmark_detector;
    deserialize("shape_predictor_68_face_landmarks.dat") >> landmark_detector;

    // Open default camera
    VideoCapture cap(0);

    if (!cap.isOpened()) {
        cerr << "Unable to open camera." << endl;
        return 1;
    }

    while (true) {
        // Capture frame from camera
        Mat frame;
        cap >> frame;

        // Convert OpenCV image to dlib format
        cv_image<bgr_pixel> dlib_img(frame);

        // Detect faces in the image
        std::vector<rectangle> faces = face_detector(dlib_img);

        // Draw landmarks on each detected face
        for (rectangle face : faces) {
            full_object_detection landmarks = landmark_detector(dlib_img, face);
            for (int i = 0; i < landmarks.num_parts(); i++) {
                circle(frame, Point(landmarks.part(i).x(), landmarks.part(i).y()), 2, Scalar(0, 255, 0), -1);
            }
        }

        // Display image with facial landmarks
        imshow("Facial Landmarks", frame);

        // Exit if 'q' key is pressed
        if (waitKey(1) == 'q') {
            break;
        }
    }

    return 0;
}
