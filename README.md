# Media-Pipe
A UNSW research project that uses OpenCV and a body detection model to determine ...

## Credits
[OpenPose Body Detection Model](https://github.com/CMU-Perceptual-Computing-Lab/openpose/tree/master)

## Prerequisites
* OpenCV 4.x, with extra modules. You need to build OpenCV to include these extra modules. You can find the method [here.](https://github.com/opencv/opencv_contrib)
    <details>
    <summary>Installation Steps</summary>

    1. Download OpenCV and the extra modules.
    ```
        git clone https://github.com/opencv/opencv.git
        git clone https://github.com/opencv/opencv_contrib.git
    ```
    2. Make the build directory, and configure OpenCV. Note:
    * The `-D CUDA_ARCH_BIN` tag; you need to set this value according to your GPU's architecture, which you can find [here.](https://developer.nvidia.com/cuda-gpus) For example, a RTX 3000 series GPU has value 8.6.
    * The `-DOPENCV_EXTRA_MODULES_PATH` tag; this should be set to the path where you cloned `opencv_contrib`. Represent this path as `[path]`.
    ```
    cmake -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=/usr/local \
        -DWITH_CUDA=ON \
        -DWITH_CUDNN=OFF \
        -DCUDA_ARCH_BIN=8.6 \
        -DWITH_TBB=ON \
        -DWITH_V4L=ON \
        -DWITH_QT=ON \
        -DWITH_OPENGL=ON \
        -DBUILD_EXAMPLES=ON \
        -DOPENCV_GENERATE_PKGCONFIG=ON \
        -DOPENCV_EXTRA_MODULES_PATH=[path]/modules \
        ..
    ```
    3. Compile OpenCV with the terminal commands `make -j$(nproc)` and then `sudo make install`.
    </details>

* OpenPose. You can find the prerequisties required for OpenPose [here.](https://github.com/CMU-Perceptual-Computing-Lab/openpose/blob/master/doc/installation/1_prerequisites.md)
* CMake

## Installation
1. Clone this repository.
For Ubuntu or WSL:
```
git clone git@github.com:emmettmitsuki/media-pipe.git
cd media-pipe
```
2. Create a build directory, and run cmake.
```
cd {media-pipe_folder}
mkdir build
cd build
cmake ..
```
3. Run `make` to build the program.

You can run the program using the terminal command `./OpenCVWebcamApp`.