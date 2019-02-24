package socket;

import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;

public class Server{
    private Integer port;
    private ServerSocket sock;

    public Server(Integer port) throws Exception{
        this.port = port;
        sock = new ServerSocket(port);
    }

    public SocketClient accept() throws Exception{
      Socket client = this.sock.accept();
      SocketClient socket = new SocketClient(client);
      return socket;
    }

}
