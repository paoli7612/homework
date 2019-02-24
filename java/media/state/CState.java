package state;

import socket.SocketClient;

public class CState implements State {
  Current current;
  SocketClient client;
  Media media;

  public CState(Current current, SocketClient client, Media media){
    this.current = current;
    this.client = client;
    this.media = media;
  }

  public void run() throws Exception {
    Float n = media.calculate();
    client.send("Media: " + n);
    current.setState(3);
  }
}
