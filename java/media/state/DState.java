package state;

import socket.SocketClient;

public class DState implements State {
  Current current;
  SocketClient client;
  Media media;

  public DState(Current current, SocketClient client, Media media){
    this.current = current;
    this.client = client;
    this.media = media;
  }

  public void run() throws Exception {
    client.send("Vuoi calcolare ancora la media?[s/n]");
    String message = client.recv();
    if (message.equals("s")){
      current.setState(0);
    } else if (message.equals("n")){
      client.send("close");
      current.stop();
    }
  }
}
