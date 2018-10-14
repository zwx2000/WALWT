# 图像与图形的压缩处理
* 日常生活中，我们时常会注意到一些有关图像的专有名词，图片格式相信很多人都见过，刷微博，朋友圈时的图片保存时就会出现jpg,gif等字样，本文就为大家介绍以下不同图片格式的压缩特点及作用，在叙述图片格式之前，了解一下部分专有名词的定义也是很有必要的。
## 名词解释
1.像素（Pixel）:

In digital imaging, a pixel, pel,dots, or picture element is a physical point in a raster image, or the smallest addressable element in an all points addressable display device; so it is the smallest controllable element of a picture represented on the screen.

在数字成像中，像素，像素点或图像元素是光栅图像中的物理点，或者是全点可寻址 显示设备中的最小可寻址元素; 所以它是屏幕上显示的图片的最小可控元素。

2.图像分辨率（Image resolution）：

Image resolution is the detail an image holds. The term applies to raster digital images, film images, and other types of images. Higher resolution means more image detail.

图像分辨率是图像所具有的细节。该术语适用于光栅数字图像，胶片图像和其他类型的图像。分辨率越高意味着图像细节越多。

3.位图（Bitmap）：

A bitmap is a type of memory organization or image file format used to store digital images. 

位图是一种用于存储数字图像的存储器组织或图像文件格式。

![](https://upload.wikimedia.org/wikipedia/commons/2/2b/Pixel-example.png)

## 图片格式
### jpeg/jpg

JPEG文件的扩展名为Joint Photographic Experts Group,其压缩技术十分先进，它用去除冗余的图像和彩色数据，获取得极高的压缩率的同时能展现十分丰富生动的图像，换句话说，就是可以**用最少的磁盘空间得到较好的图像质量**。

由于JPEG格式文件尺寸较小，下载速度快，所以是互联网上最广泛使用的格式，在使用数码相机拍摄时，我们通常采用这样一个原则：**景物色彩丰富，明暗过渡阶调多，选择低压缩比，使用高分辨率拍摄时，选择高压缩比**

### bmp

BMP（全称Bitmap）是Windows操作系统中的标准图像文件格式，可以分成两类：设备相关位图（DDB）和设备无关位图（DIB），使用非常广。它采用位映射存储格式，**除了图像深度可选以外，不采用其他任何压缩，因此，BMP文件所占用的空间很大**。



### tiff
标签图像文件格式（Tag Image File Format，简写为TIFF）是一种灵活的位图格式，主要用来存储包括照片和艺术图在内的图像。

它具有**拓展性、方便性、可改性。TIFF采用无损压缩，支持多种色彩图像模式**，由于它储存的图像信息非常多，图像质量高，有利于原稿的复制，很多地方都将此格式用于印刷。

但是这种格式**兼容性较差，且体积较大，一般适用于Mac系统用户以及摄影爱好者，做无损扫描或者印刷出版**

* 欧洲野猫的照片，压缩率从左到右递减，从而质量增加
![](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e9/Felis_silvestris_silvestris_small_gradual_decrease_of_quality.png/300px-Felis_silvestris_silvestris_small_gradual_decrease_of_quality.png)

### gif

GIF(Graphics Interchange Format)的原义是“图像互换格式”，是CompuServe公司在 1987年开发的图像文件格式。GIF文件的数据，是一种基于LZW算法的连续色调的无损压缩格式。其压缩率一般在50%左右，它不属于任何应用程序。GIF格式可以存多幅彩色图像，如果把存于一个文件中的多幅图像数据逐幅读出并显示到屏幕上，就可构成一种最简单的动画。通常情况下它只支持256种颜色，**色域较窄，文件压缩比不高**。

它的优势是**支持多帧动画，支持透明背景图像，并且文件小，下载速度快**，可用许多具有同样大小的图像文件组成动画，一般用于做动图演示。

![](https://goss1.vcg.com/creative/vcg/800/new/VCG211151553549.gif)

读者想自己亲身实践一下的话，不妨在自己的电脑上下载一个BMP格式的图片，再将这个BMP格式的图片另存为jpg,tiff等格式，比较各自的文件大小与放大之后的图形显示效果，相信会给你一个更为直观的感受。

上文提到的四种格式是较为常见的，当然还有诸如PSD，EXIF等格式，有兴趣的读者可以自己查阅网上的相关资料加深对图片压缩处理的印象。
