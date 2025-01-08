# 在Vscode上学习OpenGL

**一些必备的网站：**

* [我自己的Github链接](https://github.com/Sky101223/LearnOpenGL.git)
* [GLFW](https://www.glfw.org/)
* [glad](https://glad.dav1d.de/)
* [Vscode](https://code.visualstudio.com/)

基本目录样子：

``` None
项目: LearnOpenGL

-CMakeLists.txt
|
+--include
|  |
|  +--GLFW
|  |  \--...
|  |
|  +--glad
|  |  \--...
|  +--KHR
|  |  \--...
|  \--...
+--lib
|  \--glad.c
|  \--...
+--src
   \--CMakeLists.txt
   \--Main.cpp
```

## 配置Vscode

1. GLFW  
下载 [GLFW](https://www.glfw.org/) （~~如果你是34位的，请下载34位的；如果你是64位的，请下载64位的~~）  
下载后请将给它解压了，然后在解压后的文件中找到include文件。
将include文件下的GLFW文件拷贝到vscode的include文件里（~~先在自己的文件夹中创建好，再用vscode打开~~）
再将该文件下的lib-mingw64-w64里的.dll文件的路径记录下来（一会要用）
*建议你在一个固定的文件夹里，这样方便你链接.dll文件*

2. glad  
下载 [glad](https://glad.dav1d.de/)，选择核心模式（core）然后下载，将下载后文件解压，在里面找到include的文件，将里面的glad文件拷贝到vscode里的include文件。将里面src里的glad.c文件拷贝到vscode里的src目录下

3. 编写CMakeLists.txt  
*前提时你要有一个Cmake编译器*  
在根目录下创建一个名为CMakeLists.txt，在文件里编写项目的一些配置项目的Cmake代码（[CMake教程](https://www.runoob.com/cmake/cmake-tutorial.html)）
