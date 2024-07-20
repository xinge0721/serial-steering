# Untitled - By: j - Sat Jul 20 2024

import sensor, image, time

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False)          #颜色追踪关闭自动增益
sensor.set_auto_whitebal(False)      #颜色追踪关闭自动白平衡

#Threshold_black = (20, 0, -128, 127, -128, 127) #边界阈值
Threshold_red   = (74, 100, -128, 127, -128, 127)
Threshold_red_a   = (67, 100, -128, 127, -128, 127)
#Threshold_green =

clock = time.clock()

while True:
    clock.tick()  # 更新时钟

    img = sensor.snapshot()  # 捕获图像

    # 寻找符合颜色阈值的色块

    blobs = img.find_blobs([Threshold_red], pixels_threshold=200, area_threshold=200)

    if blobs:
        for blob in blobs:
            # 为找到的色块绘制矩形边界框
            img.draw_rectangle(blob.rect() , color=(255,0, 0), thickness=2)

            # 输出色块的像素点
            print("Blob Center:", blob.pixels())

