import socket.Server;
import socket.SocketClient;

class MainServer {
  public static void main(String[] args) throws Exception{
    Server s = new Server(25000);
    System.out.println("Server avviato");
    System.out.println("Server in ascolto...");
    Boolean running = true;
    while (running){
      SocketClient c = s.accept();
      Boss m = new Boss(c);
      Thread t = new Thread(m);
      t.start();
    }
  }
}
