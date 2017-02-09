//Example 2-10. The same object can load videos from a camera or a file

#include <opencv2/opencv.hpp>
#include <iostream>

int main( int argc, char** argv )
{
    cv::namedWindow( "Example2-10", cv::WINDOW_AUTOSIZE );
    cv::VideoCapture cap;
    if (argc==1)
    {
        cap.open(0);
    }
    else
    {
        cap.open(argv[1]);
    }
    if( !cap.isOpened() )   // check if we succeeded
    {
        std::cerr << "Couldn't open capture." << std::endl;
        return -1;
    }

    cv::Mat frame;
    for(;;)
    {
        cap >> frame;
        if(frame.empty()){
                break; // ran out of film
        }
        cv::imshow("Example2-10",frame);
        char ch = cv::waitKey(33);
        if (ch > 0) {
                break;
        }
    }
    return 0;
}
