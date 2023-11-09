/*
Sketch that checks all the sensors avaialble, requesting 100 samples of each
With Putty, log the Serial output as a .txt
@author: Pablo Marquínez
*/

#include "Arduino_BHY2.h"

/*
Sensor
SensorXYZ 
SensorQuaternion
SensorOrientation
SensorBSEC
SensorActivity
*/
int sensors[] = { 48, 50, 52, 53, 55, 57, 59, 61, 67, 70, 75, 77, 94, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 140, 141, 142, 143 };
Sensor* ptrSensor;

int sensorsXYZ[] = { 1, 3, 4, 5, 6, 7, 10, 12, 13, 14, 15, 16, 19, 22, 23, 24, 25, 28, 29, 31, 32, 91, 92, 93 };
SensorXYZ* ptrSensorXYZ;

int sensorsQuaternion[] = { 34, 35, 37, 38, 40, 41 };
SensorQuaternion* ptrSensorQuaternion;

int sensorsOrientation[] = { 43, 44, 69 };
SensorOrientation* ptrSensorOrientation;

int sensorsBSEC[] = { 115 };
SensorBSEC* ptrSensorBSEC;

int sensorsACtivity[] = { 63 };
SensorActivity* ptrSensorActivity;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial)
    ;

  delay(10000);
  BHY2.begin();

  delay(1000);

  checkSensors();
  //checkSensorsXYZ();
  //checkSensorsQuaternion();
  //checkSensorsOrientation();
  //checkSensorsBSEC();

  Serial.println("--------");
  Serial.println("END");
}

void loop() {
  // put your main code here, to run repeatedly:
}

void checkSensors() {
  Serial.println("-------");
  Serial.println("Checking type Sensor");
  int listLength = sizeof(sensors) / sizeof(sensors[0]);
  for (int checkID = 0; checkID < listLength; checkID++) {
    ptrSensor = new Sensor(sensors[checkID]);
    ptrSensor->begin();

    Serial.print("\tChecking ");
    Serial.println(sensors[checkID]);
    for (int i = 0; i < 100; i++) {
      BHY2.update();
      Serial.println(String("\t\tSample n") + String(i) + String(" ") + ptrSensor->toString());
      delay(20);
    }

    ptrSensor->end();
  }
}

void checkSensorsXYZ() {
  Serial.println("-------");
  Serial.println("Checking type SensorXYZ");
  int listLength = sizeof(sensorsXYZ) / sizeof(sensorsXYZ[0]);
  for (int checkID = 0; checkID < listLength; checkID++) {
    ptrSensorXYZ = new SensorXYZ(sensorsXYZ[checkID]);
    ptrSensorXYZ->begin();

    Serial.print("\tChecking ");
    Serial.println(sensorsXYZ[checkID]);
    for (int i = 0; i < 100; i++) {
      BHY2.update();
      Serial.println(String("\t\tSample n") + String(i) + String(" ") + ptrSensorXYZ->toString());
      delay(20);
    }

    ptrSensorXYZ->end();
  }
}

void checkSensorsQuaternion() {
  Serial.println("-------");
  Serial.println("Checking type SensorQuaternion");
  int listLength = sizeof(sensorsQuaternion) / sizeof(sensorsQuaternion[0]);
  for (int checkID = 0; checkID < listLength; checkID++) {
    ptrSensorQuaternion = new SensorQuaternion(sensorsQuaternion[checkID]);
    ptrSensorQuaternion->begin();

    Serial.print("\tChecking ");
    Serial.println(sensorsQuaternion[checkID]);
    for (int i = 0; i < 100; i++) {
      BHY2.update();
      Serial.println(String("\t\tSample n") + String(i) + String(" ") + ptrSensorQuaternion->toString());
      delay(20);
    }

    ptrSensorQuaternion->end();
  }
}

void checkSensorsOrientation() {
  Serial.println("-------");
  Serial.println("Checking type SensorOrientation");
  int listLength = sizeof(sensorsOrientation) / sizeof(sensorsOrientation[0]);
  for (int checkID = 0; checkID < listLength; checkID++) {
    ptrSensorOrientation = new SensorOrientation(sensorsOrientation[checkID]);
    ptrSensorOrientation->begin();

    Serial.print("\tChecking ");
    Serial.println(sensorsOrientation[checkID]);
    for (int i = 0; i < 100; i++) {
      BHY2.update();
      Serial.println(String("\t\tSample n") + String(i) + String(" ") + ptrSensorOrientation->toString());
      delay(20);
    }

    ptrSensorOrientation->end();
  }
}

void checkSensorsBSEC() {
  Serial.println("-------");
  Serial.println("Checking type SensorBSEC");
  int listLength = sizeof(sensorsBSEC) / sizeof(sensorsBSEC[0]);
  for (int checkID = 0; checkID < listLength; checkID++) {
    ptrSensorBSEC = new SensorBSEC(sensorsBSEC[checkID]);
    ptrSensorBSEC->begin();

    Serial.print("\tChecking ");
    Serial.println(sensorsBSEC[checkID]);
    for (int i = 0; i < 100; i++) {
      BHY2.update();
      Serial.println(String("\t\tSample n") + String(i) + String(" ") + ptrSensorBSEC->toString());
      delay(20);
    }

    ptrSensorBSEC->end();
  }
}