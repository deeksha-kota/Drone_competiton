#include "opencv2/opencv.hpp"
#include "opencv2/aruco.hpp"
#include <iostream>

#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define MATLAB_PORT    11112 
#define MAXLINE        1024 

int main(int argc, char** argv) {

    int sockfd; 
    char buffer[MAXLINE]; 
    char hello[] = "x:123400000000;y:5678000000;";
    struct sockaddr_in cliaddr; 

    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    memset(&cliaddr, 0, sizeof(cliaddr)); 

    // Filling cliaddr information 
    cliaddr.sin_family    = AF_INET; // IPv4 
    cliaddr.sin_addr.s_addr = INADDR_ANY; 
    cliaddr.sin_port = htons(MATLAB_PORT);

    cv::Mat frame;

    cv::VideoCapture cap("udp://0.0.0.0:11111",    cv::CAP_FFMPEG);

    cap >> frame; // get a first frame!

    std::vector<int> markerIds;
    std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
    cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_100);

    for(;;) {

        cap >> frame; // get a first frame!

        cv::aruco::detectMarkers(frame, dictionary, markerCorners, markerIds, parameters, rejectedCandidates);
        cv::aruco::drawDetectedMarkers(frame, markerCorners, markerIds);

        cv::imshow("tello vision", frame);

        int minElementIndex = std::min_element(markerIds.begin(),markerIds.end()) - markerIds.begin();

        if (markerIds.size()>0) {
            sprintf(hello, "x:%d;y:%d;\n", static_cast<int>(markerCorners[minElementIndex][0].x), static_cast<int>(markerCorners[minElementIndex][0].y));
        } else {
            sprintf(hello, "x:%d;y:%d;\n", 0, 0);
        }

        sendto(sockfd, (const char *)hello, strlen(hello),  
            0, (const struct sockaddr *) &cliaddr, 
            sizeof(cliaddr)); 

        if ( frame.empty() ) break; // end of video stream

        if( cv::waitKey(10) == 27 ) break; // stop capturing by pressing ESC

    }

    // the camera will be closed automatically upon exit
    cap.release();

    return 0;

}
