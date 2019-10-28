# Arduino-Smartphone device as a physical phenomena measurer


*The Arduino code file (**arduino-code.ino**) and the RoboRemo app interface file (**roboremo-interface.interface**) are provided 
for educational purpose only.* 


*The authors of this two files are not the owners of the licenses of RoboRemo app and Arduino or have any professional relation 
with them.*


*Please, contact to mail@mail.com if you have any doubts or comments.*

## Arduino-code.ino

The Arduino-code.ino must be compiled and uploaded to an Arduino/Genuino UNO Board using the Arduino IDE.
(https://www.arduino.cc/en/main/howto)

Once the code is compiled and uploaded, the board will get the function of measuring analog signals between
**-1V and +1V** (it is important to not overpass this boundaries) which will be provided by the **analog pin A0**. 

Also, the code allows to communicate the board with the application RoboRemo app installed on a Smartphone
which will be recieving via OTG USB the digital signal converted by te board.


## roboremo-interface.interface

The RoboRemo app interface allows the Smartphone to read, visualize and save the data from the digital signal provided by the
Arduino/Genuino board.  

The steps to import the interface into the Smartphone are:
1. Copy the interface file to the RoboRemo app folder on the Smartphone
2. Open RoboRemo app in the Smartphone
3. Select menu -> interface -> import
4. Choose the file


The full manual of the RoboRemo app can be found in http://www.roboremo.com/uploads/2/4/5/7/24571986/manual_v212.pdf
