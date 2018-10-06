# html5的入门游戏开发
## 关于html5
*  考虑到一部分同学像我一样对这方面是零基础，所以首先给大家科普一下什么是html5
 >   HTML5 (formerly spelled HTML5[a]) is a markup language used for structuring and presenting content on the World Wide Web. 
     
 >   万维网的核心语言、标准通用标记语言下的一个应用超文本标记语言（HTML）的第五次重大修改
 
 ## 制作步骤
 * 1 安装 Construct 2
 
   [点击这里](https://www.scirra.com/construct2/releases/r262)下载安装Construct 2
   
  * 2 新建工程
  
  打开Construct 2，可以看到一个类似Microsoft Office 2010的界面。点击左上角File（文件）按钮打开“文件”菜单，选择New（新建）建立工程。
  
  ![](https://www.scirra.com/images/articles/filenew.png)
  
  * 3 插入对象
  
 让我们在布局中平铺背景图像。双击布局中的一个空白位置，这时候将出现一个“插入对象”对话框，双击“背景图层”对象以插入对象。 这时候鼠标将变成一个十字光标。不管你最初将鼠标置于何处，这时候的你只要左击布局中的任何位置便可。随后图像编辑器便会打开，然后你便能够选择图像进行平铺。
 
 ![](https://www.scirra.com/images/articles/insertobject.png)
 
 * 4 加入游戏角色
 
 ![Monster](https://www.scirra.com/images/articles/monster.png)
 ![Player](https://www.scirra.com/images/articles/player.png)
 ![Bullet](https://www.scirra.com/images/articles/bullet.png)
 ![Explode](https://www.scirra.com/images/articles/bullet.png)
 
 1双击插入新对象

2双击“Sprite”对象。

3当鼠标转向十字准线时，单击布局中的某个位置。工具提示应该是“Main”。（记住这是主动布局。）

4弹出纹理编辑器。单击打开的图标，并加载四个纹理之一。

5关闭纹理编辑器，保存更改。现在你应该看到布局中的对象了！

* 5 添加动作

让我们向玩家添加8方向的移动行为。点击播放器选择它。在属性栏中，注意行为类别。单击“添加/编辑”。玩家的行为对话框将打开。

![](https://www.scirra.com/images/articles/openbehaviors.png)

![](https://www.scirra.com/images/articles/add8dir.png)

![](https://www.scirra.com/images/articles/playerbehaviors_2.png)

* 6 事件

添加事件
![](https://www.scirra.com/images/articles/newevent_2.png)

![](https://www.scirra.com/images/articles/alwayslookatmouse.png)

* 7 添加动作

![](https://www.scirra.com/images/articles/addactiondlg.png)

![](https://www.scirra.com/images/articles/everytickcnd.png)

仿照如上操作，最终事件如下图

![](http://a1.qpic.cn/psb?/V10WsyPe3UzLA1/jYyxRM0mIYdCDReFcuCrrrWvtDUqPnXVBUpCLoQv5x8!/b/dDQBAAAAAAAA&ek=1&kp=1&pt=0&bo=QAUCA0AFAgMBACc!&tl=3&vuin=2148174380&tm=1538816400&sce=60-2-2&rf=viewer_311)

* 8 加入积分制

![](https://www.scirra.com/images/articles/addglobal.png)

![](https://www.scirra.com/images/articles/addglobalscore.png)

## 游戏成果展示

![](http://wx4.sinaimg.cn/large/005TGGHgly1fvxavnckvvg30gp0atx6p.gif)
