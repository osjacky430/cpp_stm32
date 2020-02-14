import processing.serial.*;

int array_1[] = {0xFF, 0xFF, 0x01, 0x04, 0x01, 0x01, 0x80, 0x7A, 0x00};
int array_2[] = {0xFF, 0xFF, 0x01, 0x05, 0x02, 0x11, 0x73, 0x20, 0x7A};
int array_3[] = {0xFF, 0xFF, 0x01, 0x03, 0x02, 0x11, 0x73, 0x00, 0x00};

int array_actual_len[] = { 8, 9, 7 };
int two_d_array[][] = { array_1, array_2, array_3 };

Serial my_port = new Serial(this, Serial.list()[0], 115200);

void setup() {
}

void draw() {
  int idx = int(random(3));
  
  for (int i = 0; i < array_actual_len[idx]; ++i) {
    my_port.write(two_d_array[idx][i]);
  }
  
  while(my_port.available() > 0) {
    int in_byte = my_port.read();
    
    if (in_byte == '\t' || in_byte == '\n') {
    } else {
      print(hex(in_byte, 2), " ");
    }
    
    if (in_byte == '\t') {
      println();
    }
  }
  
  delay(1000);
}
