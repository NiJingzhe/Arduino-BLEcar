# Arduino-BLEcar
# 基于Arduino的蓝牙小车
   made by Lil-Dinosaur
# 1.程序结构 
    Robot__
           |_Motor
           |_Controler
                     |_BlinkerSlider x 2,BlinkerButton x 1
                    
# 2.操作
  采用BlinkerAPP，创建两个滑动条分别控制左右马达速度，一个stop按钮控制强制制动，蓝牙连接小车的JDY-08实现控制。
  
# 3.硬件
   Arduino Uno 3做主控
   采用JDY-08蓝牙模块
   用L289N直流步进模块控制直流电机
   机身打算时硬纸板先凑合用用，后期可能换木板或钢板

