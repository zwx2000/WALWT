# 《*用python做计算器，做数学问题*》实验报告
---
## 高数问题


* **实现方程求解**

*解方程的基本思想是*：

*aa = solve([f],[x])*

    1.f是方程，x是变量，第一个代码解的是关于x的方程f=0。

    2.第二块代码：
    解二次方程：
    aa = solve([x**2+a**2],[x])

    3.第三块代码：
    三次方程的解公式也能求出来：
    aa = solve([x**3+a**3],[x])

![](http://a4.qpic.cn/psb?/V10WsyPe3UzLA1/.bK666MgQY5WsPY5SVuwnTWexx4uPLWlVgV*PQ1pD6Q!/b/dFMBAAAAAAAA&ek=1&kp=1&pt=0&bo=owKeAqMCngIBACc!&tl=1&tm=1542513600&sce=0-12-12&rf=viewer_311)

* **实现三角函数的公式化简**

化简 g = cos(x)**2-sin(x)**2

![](http://a1.qpic.cn/psb?/V10WsyPe3UzLA1/eFNuNiGWzHQyEl*Ra5qiS7O4mrRh*aAx5apiBOXDlwQ!/b/dAgBAAAAAAAA&ek=1&kp=1&pt=0&bo=4gEwAeIBMAEBACc!&tl=1&tm=1542513600&sce=0-12-12&rf=viewer_311)

---
## 线性代数问题

* **矩阵求逆**

      1.先来求一下矩阵的逆，先引入numpy
      2.然后创建一个方阵A
      3.使用linalg.det求得方阵的行列式
      4.使用linalg.inv求得方阵A的逆矩阵



![](http://a2.qpic.cn/psb?/V10WsyPe3UzLA1/JXB7AuuYu*OhAeRjEw3y*C*wF.FRpVw.7ia0Mcw35EI!/b/dDUBAAAAAAAA&ek=1&kp=1&pt=0&bo=DAIxAgwCMQIBACc!&tl=1&tm=1542513600&sce=0-12-12&rf=viewer_311)

* **求解简单的线性方程组**

    求解线性方程组比较简单，只需要用到一个函数(scipy.linalg.solve)就可以了。比如我们要求以下方程的解，这是一个非齐次线性方程组：

    3x_1 + x_2 - 2x_3 = 5
    
    x_1 - x_2 + 4x_3 = -2
    
    2x_1 + 3x_3 = 2.5

![](http://a4.qpic.cn/psb?/V10WsyPe3UzLA1/0LnRw4R9bKUae6zfUUw9S6Ds9g.NNcbkgKknUxfg8EQ!/b/dFMBAAAAAAAA&ek=1&kp=1&pt=0&bo=6wFoAesBaAEBACc!&tl=1&tm=1542513600&sce=0-12-12&rf=viewer_311)
