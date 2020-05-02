import cv2
import numpy as np

img = cv2.imread('image4.png')

lower = np.array([215, 215, 215])
upper = np.array([255, 255, 255])
shapeMask = cv2.inRange(img, lower, upper)

contours,h = cv2.findContours(shapeMask.copy(), cv2.RETR_EXTERNAL,
	cv2.CHAIN_APPROX_SIMPLE)

count = 0

for cnt in contours:
	approx = cv2.approxPolyDP(cnt,0.01*cv2.arcLength(cnt,True),True)
	cv2.drawContours(img,[cnt],-1,(0,0,255),1)
	count += 1

print(count)
cv2.imshow('img',img)
cv2.waitKey(0)

