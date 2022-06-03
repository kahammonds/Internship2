#include "SerialPort.hpp"

using namespace mn::CppLinuxSerial;

int main(){

    SerialPort serialPort("/dev/ttyUSB0", BaudRate::B_57600, NumDataBits::EIGHT, Parity::NONE, NumStopBits::ONE); //pre-initialized baud rates
    //SerialPort serialPort("/dev/ttyACMO", 13000); //custom baud rate
    serialPort.SetTimeout(-1); //wait until data is received
    serialPort.Open();

    serialPort.Write("Hi Paul");

    std::string readData; //will only start reading after 1 byte is received due to SetTime call above
    serialPort.Read(readData);

    serialPort.Close();
}


