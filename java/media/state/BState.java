package state;

import socket.SocketClient;

public class BState implements State {
  Current current;
  SocketClient client;
  Media media;

  public BState(Current current, SocketClient client, Media media){
    this.current = current;
    this.client = client;
    this.media = media;
  }

  public void run() throws Exception {
    Integer n = media.getLen();
    client.send("Calcolare la media degli " + n + " numeri inseriti fin ora? [s/n]");
    String message = client.recv();
    if (message.equals("s")){
      current.setState(2);
    } else if (message.equals("n")){
      current.setState(0);
    }
  }
}
