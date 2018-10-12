import cv2
import numpy as np 
img=cv2.imread('/home/pi/Desktop/eye.jpg&f=1', 0) 
j=cv2.medianBlur(img, 3) 
clahe=cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8,8)) 
k=clahe.apply(j) 
cv2.imwrite('clahe.jpg', k) 
kernel=np.ones((5,5), np.uint8) 
closing=cv2.morphologyEx(k, cv2.MORPH_CLOSE, kernel) 
h,w=img.shape[:2] 
mask=np.zeros((h+2, w+2), np.uint8) 
seed_pt=None flooded=k.copy() 
cv2.floodFill(flooded, mask, seed_pt, 220, 0, 3) 
z=cv2.absdiff(closing,flooded) 
ret, th1=cv2.threshold(z, 10, 255, cv2.THRESH_BINARY) 
cv2.imwrite('threshold.jpg', th1) 
cv2.imshow('image', th1) cv2.waitKey(0)