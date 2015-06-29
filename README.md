Purpose of this branch is to add ARM WinRT devices support (as you cannot run *.exe w/o APPCONTAINER on WinRT device. Such exe should be signed in a specific way)

Most common WinRT way is used to access resources: attach files as content. So you need to clone [opencv_extra](https://github.com/Itseez/opencv_extra) and set `OPENCV_TEST_DATA_PATH` environment variable to `opencv_extra\testdata` before CMake run.

Also added basic support for comparing of performance test results. The last result is stored inside of LocalFolder of the application so you may compare current run with the previous one.

**Currently supported for build:** WindowsStore 8.0, 8.1; WindowsPhone 8.0, 8.1

**Currently supported for test run:** WindowsStore 8.0, 8.1; WindowsPhone 8.1

Logs are written to Documents folder (OneDrive or local, check both) and to Visual Studio Output window.


### OpenCV: Open Source Computer Vision Library

[![Gittip](http://img.shields.io/gittip/OpenCV.png)](https://www.gittip.com/OpenCV/)

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
