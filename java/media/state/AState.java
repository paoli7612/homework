package state;
import socket.SocketClient;

public class AState implements State {
  Current current;
  SocketClient client;
  Media media;

  public AState(Current current, SocketClient client, Media media){
    this.current = current;
    this.client = client;
    this.media = media;
  }

  private Integer toInt(String message){
    try {
      return Integer.parseInt(message);
    } catch (Exception e) {
      return null;
    }
  }

  public void run() throws Exception {
    client.send("richiesta numero");
    String message = client.recv();
    Integer n = this.toInt(message);
    if (n == null){
      current.setState(1);
    } else {
      this.media.add(n);
    }
  }
}
