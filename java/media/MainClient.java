import socket.Client;

import java.util.Scanner;

class MainClient {
  public static void main(String[] args) throws Exception{
    Client client = new Client("localhost", 25000);
    Scanner keyboard = new Scanner(System.in);
    Boolean running = true;
    while (running){
      String input = client.recv();
      if (input.equals("close")){
        running = false;
      } else if (input.startsWith("Media")){
        System.out.println(input);
      } else {
        System.out.println(input);
        System.out.print(">>> ");
        String output = keyboard.nextLine();
        if (output.equals("q")){
          running = false;
        }
        client.send(output);
      }
    }
  }
}
