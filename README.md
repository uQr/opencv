#####Changes in this branch:

1. Update UNIX binaries to use relative RPATH to libraries 
2. Update run.py to copy bin and lib folders to the same dir when performing --tests_move

OSX support is not  implemented because of technical difficulties. It looks like the most common for OSX is post build updating of the absolute paths on binaries.

Something like this should work (Checked manual way from [there](https://blogs.oracle.com/dipol/entry/dynamic_libraries_rpath_and_mac)):
```
otool -l binary | grep -oE "[^ ]libopencv[^ ]*" | xargs -I % install_name_tool -change % @loader_path/../lib/<substitution of library name>
```

However it is difficult to get and substitute **```<substitution of library name>```** part in this command using OSX terminal utilities.

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
