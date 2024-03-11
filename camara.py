import cv2
import numpy as np
import matplotlib.pylab as plt
cap = cv2.VideoCapture(1)

winName = 'IP_CAM'
cv2.namedWindow(winName, cv2.WINDOW_AUTOSIZE)

def escribir_coordenadas(x, y):
    with open("Coordenadas.txt", "a") as file:  # Modo 'a' para añadir al archivo
        file.write(f"Posicion x: {x}, y: {y}\n") 

while True:
    ret, frame = cap.read()

    if ret:

        imgray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        imgrgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)        

    
        imgrgb=cv2.flip(frame,1)     
        img_dist=cv2.medianBlur(imgrgb,9)
        bordes=cv2.Canny(imgrgb,threshold1=0,threshold2=120)
        bordes_1=cv2.Canny(img_dist,threshold1=70,threshold2=50)
        med_valor=np.median(imgrgb)
        lower=int(max(0,0.7*med_valor))
        upper=int(max(255,1.3*med_valor))
        bordes_2=cv2.Canny(img_dist,threshold1=lower,threshold2=upper)
        bordes_3=cv2.Canny(imgrgb,threshold1=lower,threshold2=upper)
        countours_b,jerarqui_b=cv2.findContours(bordes_2,cv2.RETR_LIST,cv2.CHAIN_APPROX_NONE)
        #print(countours_b)
        cv2.drawContours(imgrgb,countours_b,-1,(0,255,0),3)
    
        #frame=cv2.rotate(frame,cv2.ROTATE_90_CLOCKWISE)
        cv2.line(imgrgb,pt1=(320,0),pt2=(320,640),color=(20,250,250),thickness=1)
        cv2.line(imgrgb,pt1=(0,240),pt2=(640,240),color=(20,250,250),thickness=1)        
        cv2.line(imgrgb,pt1=(0,150),pt2=(640,150),color=(20,250,250),thickness=1)
        
    for contour in  countours_b:
    # Get the bounding box of the contour
        x, y, w, h = cv2.boundingRect(contour)
    
    if y==0:
        if x>=250 and x<=300:    
            print('CENTRO' f" x: {x}, y: {y}")
    if y>=0:
        if x>=100 and x<=250 and y<=100: 
            print('IZQUIERDA' f" x: {x}, y: {y}")
    if x<=100  and y>=0 and y<=200 :
        print('DERECHA' f" x: {x}, y: {y}")    
    #print(f"x: {x}, y: {y}")
    
    # Print the xy positions of the bounding box
     ##Origen X=320 Y=240
   
    escribir_coordenadas(x, y)
    cv2.imshow(winName,frame)
    #count_txt = np.savetxt('count.txt', countours_b, delimiter =', '
  
    cv2.imshow("RGB", imgrgb)
    
    
    tecla = cv2.waitKey(1) & 0xFF
    if tecla == 27:
        break
cap.release()
cv2.destroyAllWindows()