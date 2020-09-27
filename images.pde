import processing.serial.*;

Serial myPort;

String status;
PImage backg, but1;

String[] butts = {"STOP", "Casual Mode", "Popo mode", "Party mode"};

void setup()
{
  size(450, 500, JAVA2D);
  myPort = new Serial(this, "COM5", 38400); // Starts the serial communication
  myPort.bufferUntil('\n'); // Defines up to which character the data from the serial port will be read. The character '\n' or 'New Line'
  backg = loadImage("djrone2.png");
  but1 = loadImage("shSTOP.png");
}

void draw()
{
  background(backg);
  fill(0); // Green Color
  
  //text(status, 155, 240); // Prints the string comming from the Arduino
  
  // If the button "Turn ON" is pressed
  if(mousePressed && mouseX>200 && mouseX<250 && mouseY>0 && mouseY<200){
    myPort.write('1'); // Sends the character '1' and that will turn on the LED
    // Highlighs the buttons in red color when pressed
  }
  // If the button "Turn OFF" is pressed
  if(mousePressed && mouseX>200 && mouseX<250 && mouseY>200 && mouseY<400){
    myPort.write('2'); // Sends the character '0' and that will turn on the LED
  }
  
  if(mousePressed && mouseX>200 && mouseX<250 && mouseY>400 && mouseY<500){
    myPort.write('3'); // Sends the character '0' and that will turn on the LED
  }
}
