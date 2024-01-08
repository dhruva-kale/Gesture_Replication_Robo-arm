from cvzone.HandTrackingModule import HandDetector
from cvzone.SerialModule import SerialObject
import cv2

cap = cv2.VideoCapture(0)
detector = HandDetector(detectionCon=0.8, maxHands=1)
myserial = SerialObject("COM6",9600, 1)

while True:
    
    success, img = cap.read()
    hands, img = detector.findHands(img) 

    if hands:
        hand1 = hands[0]
        lmList1 = hand1["lmList"]  
        bbox1 = hand1["bbox"]
        centerPoint1 = hand1['center']  

        fingers1 = detector.fingersUp(hand1)
        fingers = fingers1[::-1]
        myserial.sendData(fingers)

    cv2.imshow("Image", img)
    cv2.waitKey(1)