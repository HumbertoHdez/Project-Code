import cv2
import numpy as np

cap = cv2.VideoCapture(0)

winName = 'IP_CAM'
cv2.namedWindow(winName, cv2.WINDOW_AUTOSIZE)

while True:
    ret, frame1 = cap.read()

    if ret:
        frame=cv2.flip(frame1,1)
        # Convertir la imagen a escala de grises
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # Aplicar filtro Canny para detectar bordes
        edges = cv2.Canny(gray, 50, 100)

        # Detección de líneas rectas
        lines = cv2.HoughLinesP(edges, 1, np.pi/180, 50, minLineLength=100, maxLineGap=10)

        if lines is not None:
            for line in lines:
                x1, y1, x2, y2 = line[0]

                # Calculate the center of the line
                center_x = int((x1 + x2) / 2)
                center_y = int((y1 + y2) / 2)

                # Get the frame dimensions
                frame_width = frame.shape[1]
                frame_height = frame.shape[0]

                # Determine the line's position
                if center_x < frame_width // 3:
                    position = "Left"
                elif center_x > frame_width * 2 // 3:
                    position = "Right"
                else:
                    position = "Center"

                # Print the position
                print("Line is in the", position)

                # Draw the line on the frame
                cv2.line(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
        else:

            # Detección de líneas curvas (círculos)
            circles = cv2.HoughCircles(edges, cv2.HOUGH_GRADIENT, 1, 100, param1=50, param2=30, minRadius=10, maxRadius=50)

            if circles is not None:
                for circle in circles[0]:
                    x, y, r = circle
                    cv2.circle(frame, (int(x), int(y)), int(r), (0, 255, 0), 2)  # Ensure r is an integer


        # Mostrar la imagen original con las líneas y círculos
        cv2.imshow(winName, frame)

    tecla = cv2.waitKey(1) & 0xFF
    if tecla == 27:
        break

cap.release()
cv2.destroyAllWindows()
