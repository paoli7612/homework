import socket.SocketClient;
import state.*;

public class Boss implements Runnable{
  SocketClient client;
  Media media;

  public Boss(SocketClient client){
    this.client = client;
  }

  private void loop(Current current) throws Exception {
    while (current.getRunning())
      switch (current.getState()){
        case 0:
          AState a = new AState(current, this.client, this.media);
          a.run();
          break;
        case 1:
          BState b = new BState(current, this.client, this.media);
          b.run();
        break;
        case 2:
          CState c = new CState(current, this.client, this.media);
          c.run();
        break;
        case 3:
          DState d = new DState(current, this.client, this.media);
          d.run();
        break;
      }
  }

  @Override
  public void run(){
    try {
      media = new Media();
      Current current = new Current(0);
      this.loop(current);
    } catch (Exception e){

    }
  }
}
