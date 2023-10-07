# Code Explaination

### Importing Libraries
numpy (np): A library for numerical operations in Python.
cv2: OpenCV library for computer vision tasks.
imutils: A collection of convenience functions for OpenCV, simplifying common tasks.
sys: A module that provides access to some variables used or maintained by the Python interpreter and to functions that interact strongly with the interpreter.
pytesseract: A Python wrapper for Google's Tesseract-OCR Engine.
pandas (pd): A library for data manipulation and analysis.
time: A module providing time-related functions.

### Image Loading
cv2.imread('car.jpeg'): Reads an image from a file. The image is loaded in BGR format.
if image is None: Checks if the image loading was successful.
print("Error: Image not found."): Prints an error message if the image is not found.
sys.exit(): Exits the script if there's an error in loading the image.

### Image Operations
imutils.resize(image, width=500): Resizes the image to have a width of 500 pixels. imutils.resize maintains the aspect ratio.
cv2.imshow("Original Image", image): Displays the original image in a window with the title "Original Image."
cv2.cvtColor(image, cv2.COLOR_BGR2GRAY): Converts the image from BGR (color) to grayscale

### Filtering | Masking
cv2.bilateralFilter: Applies a bilateral filter to the grayscale image. This filter smoothens the image while preserving edges.
cv2.Canny: Applies the Canny edge detector to detect edges in the image.
cv2.findContours: Finds contours in the edged image.
sorted(cnts, key=cv2.contourArea, reverse=True)[:30]: Sorts contours by area in descending order and selects the top 30.
NumberPlateCnt = None: Initializes a variable to store the contour of the number plate.

Iterates through the sorted contours:
    cv2.arcLength(c, True): Calculates the perimeter of the contour.
    cv2.approxPolyDP: Approximates the polygonal curve of the contour with a specified precision.
    if len(approx) == 4: Checks if the contour is a quadrilateral (assumed to be the number plate).

cv2.drawContours: Draws contours on a mask.
cv2.bitwise_and: Applies a bitwise AND operation to retain the region of interest (number plate) in the original image.

### Tesseract OCR
Tesseract OCR Configuration:
    -l eng: Specifies the language (English).
    --oem 1: Uses the LSTM OCR Engine.
    --psm 3: Assumes that the image has a single block of text.

pytesseract.image_to_string: Extracts text from the image using Tesseract OCR.

### Data Storage
Data Storage:
    Creates a dictionary (raw_data) with the date and recognized vehicle number.
    Converts the dictionary to a Pandas DataFrame.
    Writes the DataFrame to a CSV file named 'data.csv.'

### Window
cv2.waitKey(0): Waits indefinitely until a key is pressed.
cv2.destroyAllWindows(): Closes all OpenCV windows.