Purpose of this branch is to keep minimal set of updates that make WinRT tests run from console w/o APPCONTAINER. Can be used as reference branch for required updates. [Code snippets](https://microsoft.sharepoint.com/teams/OpenCV/_layouts/OneNote.aspx?id=%2fteams%2fOpenCV%2fSiteAssets%2fOpenCV%20Notebook&wd=target%28OpenCV.one%7cDA83EB3E-D510-43F1-A8FD-75F405545514%2fCMake%20Code%20Snippets%7c837DAEAC-2CE9-424D-A4DE-449A472AC702%2f%29
onenote:https://microsoft.sharepoint.com/teams/OpenCV/SiteAssets/OpenCV%20Notebook/OpenCV.one#CMake%20Code%20Snippets&section-id={DA83EB3E-D510-43F1-A8FD-75F405545514}&page-id={837DAEAC-2CE9-424D-A4DE-449A472AC702}&end) are based on this branch (Link to OneNote notebook, need to get permissions to access)

### OpenCV: Open Source Computer Vision Library

[![Gittip](http://img.shields.io/gittip/OpenCV.png)](https://www.gittip.com/OpenCV/)

#### Build notes

1. You might need to install this if you haven't already: http://www.microsoft.com/en-US/download/details.aspx?id=40784
2. Set ```OPENCV_TEST_DATA_PATH``` environment variable to location of ```opencv_extra/testdata``` (cloning of [opencv_extra](https://github.com/Itseez/opencv_extra) repo required) to get tests work correctly. Also, set ```OPENCV_PERF_VALIDATION_DIR``` environment variable in case you are planning to run performance tests.
3. *In case you'd like to adjust some flags that are defaulted by script, go to "Manual build" section.* Otherwise go to ```platforms/winrt``` and execute ```>> setup_winrt.bat "WS" "8.1" "x64"```.
This will generate all of the files needed to build open_cv projects for selected platform in ```opencv\bin\...```. Open the ```opencv\bin\WS\8.1\x64``` directory and open the ```OpenCV.sln```.
4. Set OCV solution to Release mode and build all of the projects. They should build without errors and generate executables in "bin\WS\8.1\x64\bin\Release\"
5. Running tests:
 
 - **Accuracy:** Run opencv_test_{module}.exe via console or as usual by double clicking it. You should see output in the console window
 - **Performance:** Run opencv_perf_{module}.exe via console or as usual by double clicking it. You should see output in the console window. In case you'd like to write test results to file use --perf_write_validation_results=<filename> parameter; To compare current results to previous use --perf_read_validation_results=<filename>. This should read/write files from/to ```OPENCV_PERF_VALIDATION_DIR```

##### Manual build
- CMake interface
 - Set ```CMAKE_SYSTEM_NAME``` to WindowsStore or WindowsPhone and ```CMAKE_SYSTEM_VERSION``` to 8.0 or 8.1
 - Set ```CMAKE_INSTALL_PREFIX``` using format ```<install dir>\WS\8.1\x64``` (this structure is required by samples)
 - Click "Configure" and choose required generator
 - Click "Generate"
- Command line:
 - ```md bin```
 - ```cd bin```
 - Add any required parameters to this command and execute it: ```cmake -G "Visual Studio 12 2013 Win64" -DCMAKE_SYSTEM_NAME:String=WindowsStore -DCMAKE_SYSTEM_VERSION:String=8.1 -DCMAKE_VS_EFFECTIVE_PLATFORMS:String=x64 -DCMAKE_INSTALL_PREFIX:PATH=.\install\WS\8.1\x64\ ..```
- Build solution for the required configuration and separately build INSTALL project 
- You need to set ```OPENCV_WINRT_INSTALL_DIR``` to use installed OCV with WinRT samples

#### Resources

* Homepage: <http://opencv.org>
* Docs: <http://docs.opencv.org>
* Q&A forum: <http://answers.opencv.org>
* Issue tracking: <http://code.opencv.org>

#### Contributing

Please read before starting work on a pull request: <http://code.opencv.org/projects/opencv/wiki/How_to_contribute>

Summary of guidelines:

* One pull request per issue;
* Choose the right base branch;
* Include tests and documentation;
* Clean up "oops" commits before submitting;
* Follow the coding style guide.
