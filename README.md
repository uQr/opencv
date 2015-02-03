### OpenCV: Open Source Computer Vision Library

[![Gittip](http://img.shields.io/gittip/OpenCV.png)](https://www.gittip.com/OpenCV/)

#### Build notes

1. Go to ```platforms/winrt``` and execute ```>> setup_winrt.bat "WS" "8.1" "x86"```. 
This will generate all of the files needed to build open_cv projects for selected platform in ```opencv\bin\...```. Open the ```opencv\bin\WS\8.1\x86``` directory and open the ```OpenCV.sln```. Build all of the projects. They should build without errors and *resources.pri* files should be generated in the root directory of every project (```\CMake Build Path\modules\Module Name\```).
2. In VS add ```resources.pri``` file to corresponding test project using "Add Existing Item" on the ```opencv_test_core``` project and change ```Content``` property to ```True```.
3. To run the tests right-click on the ```opencv_test_core``` project and choose ```Debug -> Start New Instance```.

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
