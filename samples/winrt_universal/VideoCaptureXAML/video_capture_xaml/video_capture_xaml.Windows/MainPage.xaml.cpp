//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "highgui.xaml.h"

#include <ppl.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui_winrt.hpp>
#include <opencv2/videoio/cap_winrt.hpp>

#include <fstream>
using namespace video_capture_xaml;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

using namespace ::Windows::Foundation;
using namespace Windows::UI::Xaml::Media::Imaging;

namespace video_capture_xaml
{
    inline Platform::String^ LoadTxtFile(Platform::String^ filename);
    // nb. implemented in main.cpp
    void cvMain();

    MainPage::MainPage()
    {
        InitializeComponent();

#if 1
        Button^ b = ref new Button();
        b->Content = "Show";
        b->Width = 110;
        b->Height = 80;
        b->Click += ref new Windows::UI::Xaml::RoutedEventHandler(this, &video_capture_xaml::MainPage::Button_Click);

        auto content = this->Grid;
        content->Children->Append(b);
#endif
        Window::Current->VisibilityChanged += ref new Windows::UI::Xaml::WindowVisibilityChangedEventHandler(this, &video_capture_xaml::MainPage::OnVisibilityChanged);

        // attach XAML elements
        cv::winrt_setFrameContainer(cvImage);

        // start (1) frame-grabbing loop and (2) message loop
        //
        // 1. Function passed as an argument must implement common OCV reading frames
        //    pattern (see cv::VideoCapture documentation) AND call cv::winrt_imgshow().
        // 2. Message processing loop required to overcome WinRT container and type
        //    conversion restrictions. OCV provides default implementation
        cv::winrt_startMessageLoop(cvMain);
    }

    void video_capture_xaml::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
    {
        static cv::String windowName("sample");
        cv::winrt_initContainer(this->cvContainer);
        cv::namedWindow(windowName); // not required

        cv::Mat image = cv::imread("Assets/sample.jpg");
        cv::Mat converted = cv::Mat(image.rows, image.cols, CV_8UC4);
        cvtColor(image, converted, CV_BGR2BGRA);
        cv::imshow(windowName, converted); // this will create window if it hasn't been created before

        int state = 50;
        cv::TrackbarCallback callback = [](int pos, void* userdata)
        {
            if (pos == 0) {
                cv::destroyWindow(windowName);
            }
        };
        cv::TrackbarCallback callbackTwin = [](int pos, void* userdata)
        {
            if (pos >= 70) {
                cv::destroyAllWindows();
            }
        };
        cv::createTrackbar("Sample trackbar", windowName, &state, 100, callback);
        cv::createTrackbar("Twin brother", windowName, &state, 100, callbackTwin);
    }

    void video_capture_xaml::MainPage::OnVisibilityChanged(Platform::Object ^sender,
        Windows::UI::Core::VisibilityChangedEventArgs ^e)
    {
        cv::winrt_onVisibilityChanged(e->Visible);
    }

    inline Platform::String^ LoadTxtFile(Platform::String^ filename)
    {
        using namespace Windows::Storage;
        auto folder = Windows::ApplicationModel::Package::Current->InstalledLocation;

        Platform::Array<byte>^ data = nullptr;
        std::wstring dir = folder->Path->ToString()->Data();
        auto fullpath = dir.append(L"/").append(filename->Data());

        std::ifstream file(fullpath, std::ios::in | std::ios::ate);
        // if opened read it in
        if (file.is_open())
        {
            int length = (int)file.tellg();
            data = ref new Array<byte>(length);
            file.seekg(0, std::ios::beg);
            file.read(reinterpret_cast<char*>(data->Data), length);
            file.close();
        }

        std::wstring output;
        if (data != nullptr)
        {
            for (int i = 0; i < data->Length; i++)
                output += data[i];
        }

        return ref new Platform::String(output.c_str());
    }
}