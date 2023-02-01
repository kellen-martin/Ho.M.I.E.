// #include "header.hpp"
#include "defs.cpp"
#include "dtypes.cpp"

#ifndef FUNCTION_HEADERS
#define FUNCTION_HEADERS
#include "CalculateTemplate.cpp"
#include "AverageImage.cpp"
#include "DifferenceStack.cpp"
#include "ImportImages.cpp"
#include "linspace.cpp"
#include "PlotFrame.cpp"
#include "Reconstructor.cpp"
#include "dtypes.cpp"
#endif

using namespace std;
using namespace cv;

// Region of interest values:
// float ROI_x[2];
// float ROI_y[2];
// int ROI_x_pix[2];
// int ROI_y_pix[2];
string output_folder = "../Output Images";

int main()
{       
    // float ROI_x[2] = {-0.5*1e-3, 0.5*1e-3};
    // float ROI_y[2] = {-0.5*1e-3, 0.5*1e-3};
    // int ROI_x_pix[2] = {(int)n_pixels/2 + (int)(ROI_x[0]/pixel_p), (int)n_pixels/2 + (int)(ROI_x[1]/pixel_p)};
    // int ROI_y_pix[2] = {(int)n_pixels/2 + (int)(ROI_y[0]/pixel_p), (int)n_pixels/2 + (int)(ROI_y[1]/pixel_p)};

    string commandFilename = "Commands.txt";
    string outputFilename = "MicroscopeOutput.txt";

    vector<image_set> MEMORY; // just a variable called memory for now, basically represents bulk storage
    vector<Mat> images;
    
    // can just use MATLAB to generate data if we need, then use the images here
    string input_folder = "../generatedData3b"; // path to folder from program location

    if(verbose) cout << endl;

    ImportImages(images, input_folder);
    
    // PlotFrame(images[0], "TEST - NO ROI 1", "test1.png", false);
    // PlotFrame(images[1], "TEST - NO ROI 2", "test2.png", false);

    if(verbose) cout << endl << "Returned to Main" << endl << endl;

    if(verbose) cout << "Image size: " << images[0].rows << " x " << images[0].cols << " x " << images[0].channels() << endl << endl;

    // Average images
    Mat avgImg = AverageImage(images);
    // if using first and last arguments to select a range, make indexes zero based
    
    if(verbose) cout << endl << "Returned to Main" << endl << endl;

    // PlotFrame(avgImg, "Average Image", "avgImg-test.png", false);

    // put a call to plotframe here to mirror matlab code
    // plot "Raw Frame 1"

    Mat diffStack = DifferenceStack(images);
    // another call to plotFrame
    // plot "Raw Difference Stack"

    if(verbose) cout << endl << "Returned to Main" << endl << endl;

    Mat recon = Reconstructor(diffStack, 1);
    // call plotFrame here
    // plot "Reconstructed Image"
    
    if(verbose) cout << endl << "Returned to Main" << endl << endl;

    if(verbose) cout << "Plotting frame: --------------" << endl;
    PlotFrame(recon, "Reconstructed 4-frame difference stack", "test-diff.png", true);
    if(verbose) cout << "------------------------------" << endl;



    // vector<string> commands;

    // readCommands(&commands, commandFilename);
    // loop through commands and do desired calculations

    return 0;
}


